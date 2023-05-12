
#include "Derivator.h"

#include <cmath>
#include <iostream>


namespace lsysgen {

template<typename T>
Derivator<T>::Derivator(ErrorHandler * eh, LSysDExpressionEvaluator * ee, Random * rnd): 
		eh(eh), evaluator(ee), _random(rnd) {}

template<typename T>
Derivator<T>::~Derivator() {}

template<typename T>
TreeNode<InstanceNodeContent, T> * Derivator<T>::derive(
        TreeNode<InstanceNodeContent, T> const* node, 
        Table<T> const* table, 
        std::vector<T> const* ignore, 
        Scope * scope) {
    // std::cerr << "Deriving " << node->toStringWithContext() << std::endl;
    if (node->isLeaf()) {
        std::vector<Value> const* values = node->content().values;
        auto candidateRules = table->rulesFor(node->element(), values != nullptr ? values->size() : -1);
        if (candidateRules != nullptr) {
            // The node signature matches the left char signature
            std::vector<Rule<T> *> applicableRules;
            applicableRules.reserve(candidateRules->size());
            Scope paramMapping(scope);
            for (Rule<T> * r : *candidateRules) {
                // std::cerr << "RULE CANDIDATE: " << r->toString() << std::endl;
                // Map arguments:
                if (r->params() && r->params()->size() > 0)
                    this->mapArgs(values, r->params(), &paramMapping);
                // Left context:
                if (r->lctx) {
                    if (!this->checkLeftContext(r->lctx->rightmostChild(), node->nextLeft(), ignore, &paramMapping))
                        continue;
                }
                // Right context:
                if (r->rctx) {
                    if (!this->checkRightContext(r->rctx->leftmostChild(), node->right(), ignore, &paramMapping))
                        continue;
                }
                // Check condition:
                if (r->cond()) {
                    Value v = evaluator->eval(r->cond(), &paramMapping);
                    if (evaluator->messages()->failed()) {
                        evaluator->messages()->dump();
                        return nullptr;
                    }
                    if (v.isBool()) {
                        if (!v.asBool())
                            continue;
                    } else {
                        eh->error("The condition expression (of type " + v.type()->name() + ") must be a boolean");
                        return nullptr;
                    }
                }
                applicableRules.push_back(r);
            }
            if (applicableRules.size() > 0) {
                Rule<T> const* chosenRule = this->chooseRule(applicableRules);
                if (chosenRule == nullptr)
                    return nullptr;
                // std::cerr << "RULE APPLIED: " << chosenRule->toString() << std::endl;
                return this->evaluateRightNode(chosenRule->rside, &paramMapping);
            }
        }
        auto ret = new TreeNode<InstanceNodeContent, T>(*node); // Copy constructor
        ret = new TreeNode<InstanceNodeContent, T>(ret); // Branch with one element constructor
        return ret;
    } else { // if (node->isBranch()) {
        TreeNode<InstanceNodeContent, T> * replacement = new TreeNode<InstanceNodeContent, T>();
        for (TreeNode<InstanceNodeContent, T> * child = node->leftmostChild(); 
                child != nullptr; 
                child = child->right()) {
            TreeNode<InstanceNodeContent, T> * encapsulatedChildReplacement = derive(child, table, ignore, scope);
            if (encapsulatedChildReplacement == nullptr) {
                delete replacement;
                return nullptr;
            }
            for (TreeNode<InstanceNodeContent, T> * child2 = encapsulatedChildReplacement->leftmostChild(); 
                    child2 != nullptr; 
                    child2 = child2->right())
                replacement->addChild(child2);
            encapsulatedChildReplacement->prune();
            delete encapsulatedChildReplacement;
        }
        return node->isRoot() ? replacement : new TreeNode<InstanceNodeContent, T>(replacement);
    }
}

template<typename T>
bool Derivator<T>::checkSideContext(
        TreeNode<LeftSideNodeContent, T> * contextNode, 
        TreeNode<InstanceNodeContent, T> * instanceNode, 
        bool rightSide, 
        std::vector<T> const* ignore, 
        Scope * paramMapping) {
    assert(paramMapping != nullptr);
    // Always true when there is no context to compare
    if (contextNode == nullptr)
        return true;
    // Always false when there are no instance nodes to compare
    if (instanceNode == nullptr)
        return false;
    TreeNode<LeftSideNodeContent, T> * ctxNode;
    TreeNode<InstanceNodeContent, T> * insNode;
    // Compare nodes one by one searching for any incompatibility until last ctxNode
    for (ctxNode = contextNode, insNode = instanceNode; 
             ctxNode != nullptr; 
             ctxNode = rightSide ? contextNode->right() : contextNode->left(),
             insNode = rightSide ? instanceNode->right() : instanceNode->nextLeft()) {
        // Return false if insNode ends before ctxNode
        if (insNode == nullptr)
            return false;
        if (ctxNode->isLeaf()) {
            // Jump to next leaf insNode (ignore branches and ignored characters)
            while (insNode->isBranch() || 
                    std::find(ignore->begin(), ignore->end(), insNode->element()) != ignore->end()) {
                insNode = rightSide ? insNode->right() : insNode->nextLeft();
                if (insNode == nullptr)
                    return false;
            }
            // Return false if insLeaf char is incompatible with ctxLeaf char
            if (ctxNode->element() != insNode->element() || ctxNode->element() == '_')
                return false;
            // Return false if insLeaf arity doesn't match ctxLeaf arity
            if (!this->checkArgs(insNode->content().values, ctxNode->content().params, paramMapping))
                return false;
        } else { // if (ctxNode->isBranch()) {
            // Return false if insNode is not another branch
            if (!insNode->isBranch())
                return false;
            // Compare both branches from left to right
            if (!this->checkRightContext(ctxNode->leftmostChild(), insNode->leftmostChild(), ignore, paramMapping))
                return false;
        }
    }
    // If the for loop didn't find incompatibilities, this side context matches
    return true;
}

template<typename T>
bool Derivator<T>::checkLeftContext(
        TreeNode<LeftSideNodeContent, T> * contextNode, 
        TreeNode<InstanceNodeContent, T> * instanceNode, 
        std::vector<T> const* ignore, 
        Scope * paramMapping) {
    return this->checkSideContext(contextNode, instanceNode, false, ignore, paramMapping);
}

template<typename T>
bool Derivator<T>::checkRightContext(
        TreeNode<LeftSideNodeContent, T> * contextNode, 
        TreeNode<InstanceNodeContent, T> * instanceNode, 
        std::vector<T> const* ignore, 
        Scope * paramMapping) {
    return this->checkSideContext(contextNode, instanceNode, true, ignore, paramMapping);
}

template<typename T>
TreeNode<InstanceNodeContent, T> * Derivator<T>::evaluateRightNode(TreeNode<RightSideNodeContent, T> const* node, Scope * paramMapping) {
    TreeNode<InstanceNodeContent, T> * instanceNode = new TreeNode<InstanceNodeContent, T>(node->element(), node->type());
    if (node->isLeaf()) {
        if (node->content().args != nullptr) {
            std::vector<Value> * values = new std::vector<Value>();
            for (LSysDParser::ExpressionContext * arg : *node->content().args) {
                Value ret = evaluator->eval(arg, paramMapping);
                if (evaluator->messages()->failed()) {
                    evaluator->messages()->dump();
                    delete values;
                    delete instanceNode;
                    return nullptr;
                }
                values->push_back(ret);
            }
            instanceNode->content().values = values;
        }
    } else { // if (node->isBranch()) {
        for (TreeNode<RightSideNodeContent, T> * child = node->leftmostChild();
                child != nullptr;
                child = child->right()) {
            TreeNode<InstanceNodeContent, T> * childInstanceNode = this->evaluateRightNode(child, paramMapping);
            if (childInstanceNode == nullptr) {
                delete instanceNode;
                return nullptr;
            }
            instanceNode->addChild(childInstanceNode);
        }
    }
    return instanceNode;
}

template<typename T>
bool Derivator<T>::checkArgs(std::vector<Value> const* values, std::list<Parameter *> const* params, Scope * paramMapping) {
    if (params != nullptr) {
        if (values == nullptr && params->size() == 0)
            return true;
        if (values == nullptr || params->size() != values->size())
            return false;
        mapArgs(values, params, paramMapping);
    }
    return true;
}

template<typename T>
void Derivator<T>::mapArgs(std::vector<Value> const* values, std::list<Parameter *> const* params, Scope * paramMapping) {
    // We already know that the character and the arity are correct for this rule, and that values and params are not null
    // if (params != nullptr && params->size() > 0) {
    std::list<Parameter *>::const_iterator param;
    std::vector<Value>::const_iterator value;
    for (param = params->begin(), value = values->begin();
            param != params->end() && value != values->end();
            ++param, ++value) {
        paramMapping->set((*param)->name, *value);
    }
    // }
}

template<typename T>
Rule<T> const* Derivator<T>::chooseRule(std::vector<Rule<T> *> const& rules) {
    if (rules.size() == 1)
        return rules.front();
    double total = 0.0;
    for (Rule<T> const* r : rules) {
        total += r->weight;
        if (r->weight < 0)
            return r;
    }
    double rnd = this->_random->randFloat();
    double choice = total * rnd;
    double current = 0.0;
    for (Rule<T> const* r : rules) {
        current += r->weight;
        if (choice < current)
            return r;
    }
    eh->error("No rule can be chosen in chooseRule()");
    return nullptr;
}

template<typename T>
Random * Derivator<T>::random() {return this->_random;}

template<typename T>
Random const* Derivator<T>::random() const {return this->_random;}



template class Derivator<char>;

}
