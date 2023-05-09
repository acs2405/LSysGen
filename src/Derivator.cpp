
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
TreeBranch<InstanceNodeContent, T> * Derivator<T>::derive(
        TreeNode<InstanceNodeContent, T> const* node, 
        Table<T> const& table, 
        std::vector<T> const& ignore, 
        Scope * scope) {
    // std::cerr << "Deriving " << node->toStringWithContext() << std::endl;
    if (node->isLeaf()) {
        auto leaf = reinterpret_cast<TreeLeaf<InstanceNodeContent, T> const*>(node);
        std::vector<Rule<T> *> const* candidateRules = table.rulesFor(leaf->element());
        std::vector<Rule<T> *> applicableRules;
        applicableRules.reserve(candidateRules->size());
        Scope paramMapping(scope);
        for (Rule<T> * r : *candidateRules) {
            // std::cerr << "RULE CANDIDATE: " << r->toString() << std::endl;
            // Check arguments:
            if (!this->mapArgs(leaf->content().values(), r->params(), &paramMapping))
                continue;
            // Left context:
            if (r->lctx) {
                if (!this->checkLeftContext(r->lctx->lastChild(), leaf->prev(), ignore, &paramMapping))
                    continue;
            }
            // Right context:
            if (r->rctx) {
                if (!this->checkRightContext(r->rctx->firstChild(), leaf->nextSibling(), ignore, &paramMapping))
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
        TreeBranch<InstanceNodeContent, T> * ret;
        if (applicableRules.size() > 0) {
            Rule<T> const* chosenRule = this->chooseRule(applicableRules);
            if (chosenRule == nullptr)
                return nullptr;
            // std::cerr << "RULE APPLIED: " << chosenRule->toString() << std::endl;
            ret = reinterpret_cast<TreeBranch<InstanceNodeContent, T> *>(this->evaluateRightNode(chosenRule->rside, &paramMapping));
            // std::cerr << "DERIVED: " << ret->toString() << std::endl;
            if (ret == nullptr)
                return nullptr;
        } else {
            ret = new TreeBranch<InstanceNodeContent, T>();
            ret->addChild(new TreeLeaf<InstanceNodeContent, T>(*leaf));
        }
        return ret;
    } else { // node->isBranch()
        auto branch = reinterpret_cast<TreeBranch<InstanceNodeContent, T> const*>(node);
        auto replacement = new TreeBranch<InstanceNodeContent, T>();
        for (auto const child : *branch->children()) {
            TreeBranch<InstanceNodeContent, T> * encapsulatedChildReplacement = derive(child, table, ignore, scope);
            if (encapsulatedChildReplacement == nullptr) {
                delete replacement;
                return nullptr;
            }
            // std::cerr << "DELETED: " << encapsulatedChildReplacement->toString() << std::endl;
            encapsulatedChildReplacement->transferChildrenTo(replacement);
            delete encapsulatedChildReplacement;
        }
        // std::cerr << "ASSEMBLED: " << replacement->toString() << std::endl;
        return branch->isRoot() ? replacement : new TreeBranch<InstanceNodeContent, T>(replacement);
    }
}

// Chechs whether an instance node (and its next/prev siblings) is compatible with a context node (and its next/prev siblings)
template<typename T>
bool Derivator<T>::checkSideContext(TreeNode<LeftSideNodeContent, T> * contextNode, 
        TreeNode<InstanceNodeContent, T> * instanceNode, 
        bool rightSide, 
        std::vector<T> const& ignore, 
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
    // Compare nodes one by one until last ctxNode
    for (ctxNode = contextNode, insNode = instanceNode; 
             ctxNode != nullptr; 
             ctxNode = rightSide ? contextNode->nextSibling() : contextNode->prevSibling(),
             insNode = rightSide ? instanceNode->nextSibling() : instanceNode->prev()) {
        // Return false if insNode ends before ctxNode
        if (insNode == nullptr)
            return false;
        if (ctxNode->isLeaf()) {
            auto ctxLeaf = reinterpret_cast<TreeLeaf<LeftSideNodeContent, T> *>(ctxNode);
            // Jump to next leaf insNode (ignore branches and ignored characters)
            while (insNode->isBranch() || 
                    std::find(ignore.begin(), ignore.end(), insNode->element()) != ignore.end()) {
                insNode = rightSide ? insNode->nextSibling() : insNode->prev();
                if (insNode == nullptr)
                    return false;
            }
            auto insLeaf = reinterpret_cast<TreeLeaf<InstanceNodeContent, T> *>(insNode);
            // Return false if insLeaf char is incompatible with ctxLeaf char
            if (ctxLeaf->element() != insLeaf->element() || ctxLeaf->element() == '_')
                return false;
            // Return false if insLeaf arity doesn't match ctxLeaf arity
            if (!this->mapArgs(insLeaf->content().values(), ctxLeaf->content().params(), paramMapping))
                return false;
        } else { // if (ctxNode->isBranch()) {
            // Return false if insNode is not another branch
            if (!insNode->isBranch())
                return false;
            auto ctxBranch = reinterpret_cast<TreeBranch<LeftSideNodeContent, T> *>(ctxNode);
            auto insBranch = reinterpret_cast<TreeBranch<InstanceNodeContent, T> *>(insNode);
            // Compare both branches from left to right
            if (!this->checkRightContext(ctxBranch->firstChild(), insBranch->firstChild(), ignore, paramMapping))
                return false;
        }
    }
    // If the for loop didn't find incompatibilities, this side context matches
    return true;
}

template<typename T>
bool Derivator<T>::checkLeftContext(TreeNode<LeftSideNodeContent, T> * contextNode, 
    TreeNode<InstanceNodeContent, T> * instanceNode, 
    std::vector<T> const& ignore, 
    Scope * paramMapping) {
    return this->checkSideContext(contextNode, instanceNode, false, ignore, paramMapping);
}

template<typename T>
bool Derivator<T>::checkRightContext(TreeNode<LeftSideNodeContent, T> * contextNode, 
        TreeNode<InstanceNodeContent, T> * instanceNode, 
        std::vector<T> const& ignore, 
        Scope * paramMapping) {
    return this->checkSideContext(contextNode, instanceNode, true, ignore, paramMapping);
}

template<typename T>
TreeNode<InstanceNodeContent, T> * Derivator<T>::evaluateRightNode(
        TreeNode<RightSideNodeContent, T> const* rightNode, 
        Scope * paramMapping) {
    assert(paramMapping != nullptr);
    TreeNode<InstanceNodeContent, T> * instanceNode;
    if (rightNode->isLeaf()) {
        auto rightLeaf = reinterpret_cast<TreeLeaf<RightSideNodeContent, T> const*>(rightNode);
        auto instanceLeaf = new TreeLeaf<InstanceNodeContent, T>(rightLeaf->element());
        // std::cerr << "Evaluating leaf " << rightLeaf->toStringWithContext() << std::endl;
        if (rightLeaf->content().args() != nullptr) {
            instanceLeaf->content().createValues();
            std::vector<Value> * values = instanceLeaf->content().values();
            values->reserve(rightLeaf->content().args()->size());
            for (LSysDParser::ExpressionContext * arg : *rightLeaf->content().args()) {
                Value ret = evaluator->eval(arg, paramMapping);
                if (evaluator->messages()->failed()) {
                    evaluator->messages()->dump();
                    delete instanceLeaf;
                    return nullptr;
                }
                values->push_back(ret);
            }
            // instanceLeaf->content().values() = values;
        }
        // std::cerr << "LEAF EVALUATED: " << instanceLeaf->toString() << std::endl;
        instanceNode = instanceLeaf;
    } else { // rightNode->isBranch()
        auto rightBranch = reinterpret_cast<TreeBranch<RightSideNodeContent, T> const*>(rightNode);
        auto instanceBranch = new TreeBranch<InstanceNodeContent, T>();
        // std::cerr << "Evaluating branch " << rightBranch->toStringWithContext() << std::endl;
        instanceBranch->reserve(rightBranch->children()->size());
        for (auto const childRightNode : *rightBranch->children()) {
            auto childInstanceNode = this->evaluateRightNode(childRightNode, paramMapping);
            if (childInstanceNode == nullptr) {
                delete instanceBranch;
                return nullptr;
            }
            instanceBranch->addChild(childInstanceNode);
        }
        // std::cerr << "BRANCH EVALUATED: " << instanceBranch->toString() << std::endl;
        instanceNode = instanceBranch;
    }
    return instanceNode;
}

template<typename T>
bool Derivator<T>::mapArgs(std::vector<Value> const* values, std::vector<Parameter *> const* params, Scope * paramMapping) {
    assert(paramMapping != nullptr);
    if (params == nullptr)
        return true;
    if (values == nullptr && params->size() == 0)
        return true;
    if (values == nullptr || params->size() != values->size())
        return false;
    std::vector<Parameter *>::const_iterator param;
    std::vector<Value>::const_iterator value;
    for (param = params->begin(), value = values->begin();
            param != params->end() && value != values->end();
            ++param, ++value) {
        paramMapping->set((*param)->name, *value);
    }
    return true;
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
