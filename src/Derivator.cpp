
#include "Derivator.h"

#include <cmath>
#include <cstdlib>
#include <chrono>
#include <iostream>


namespace lsysgen {

template<typename T>
Derivator<T>::Derivator(ErrorHandler * eh, LSysDExpressionEvaluator * ee): 
		eh(eh), evaluator(ee) {}

template<typename T>
Derivator<T>::~Derivator() {}

template<typename T>
ParseTreeNode<InstanceNodeContent, T> * Derivator<T>::derive(ParseTreeNode<InstanceNodeContent, T> const* node, Table<T> const* table, std::list<T> const* ignore, Scope * scope) {
    // std::cerr << "Deriving " << node->toStringWithContext() << std::endl;
    if (node->isLeaf()) {
        std::list<Rule<T> *> const* candidateRules = table->rulesFor(node->element());
        std::list<Rule<T> *> applicableRules;
        Scope paramMapping(scope);
        Value v = paramMapping.get("i");
        for (Rule<T> * r : *candidateRules) {
            // std::cerr << "RULE CANDIDATE: " << r->toString() << std::endl;
            // Check arguments:
            if (this->mapArgs(node->content().values, r->params(), &paramMapping) == nullptr)
                continue;
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
                if (v.isError())
                    return nullptr;
                else if (v.isBool()) {
                    if (!v.asBool())
                        continue;
                } else {
                    eh->fatalError("The condition expression (of type " + v.type()->name() + ") must be a boolean");
                    return nullptr;
                }
            }
            applicableRules.push_back(r);
        }
        ParseTreeNode<InstanceNodeContent, T> * ret;
        if (applicableRules.size() > 0) {
            Rule<T> const* chosenRule = this->chooseRule(applicableRules);
            if (chosenRule == nullptr)
                return nullptr;
            // std::cerr << "RULE APPLIED: " << chosenRule->toString() << std::endl;
            ret = this->evaluateRightNode(chosenRule->rside, &paramMapping);
            if (ret == nullptr)
                return nullptr;
        } else {
            ret = new ParseTreeNode<InstanceNodeContent, T>(*node);
            ret = ret->encapsulate();
        }
        return ret;
    } else {
        ParseTreeNode<InstanceNodeContent, T> * replacement = new ParseTreeNode<InstanceNodeContent, T>();
        for (ParseTreeNode<InstanceNodeContent, T> * child = node->leftmostChild(); 
                child != nullptr; 
                child = child->right()) {
            ParseTreeNode<InstanceNodeContent, T> * encapsulatedChildReplacement = derive(child, table, ignore, scope);
            if (encapsulatedChildReplacement == nullptr)
                return nullptr;
            for (ParseTreeNode<InstanceNodeContent, T> * child2 = encapsulatedChildReplacement->leftmostChild(); 
                    child2 != nullptr; 
                    child2 = child2->right())
                replacement->addChild(child2);
            encapsulatedChildReplacement->prune();
            delete encapsulatedChildReplacement;
        }
        return node->isRoot() ? replacement : replacement->encapsulate();
    }
}

template<typename T>
bool Derivator<T>::checkSideContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, bool rightSide, std::list<T> const* ignore, Scope * paramMapping) {
    if (contextNode == nullptr)
        return true;
    if (instanceNode == nullptr)
        return false;
    ParseTreeNode<LeftSideNodeContent, T> * ctxNode;
    ParseTreeNode<InstanceNodeContent, T> * insNode;
    for (ctxNode = contextNode, insNode = instanceNode; 
             ctxNode != nullptr; 
             ctxNode = rightSide ? contextNode->right() : contextNode->left(),
             insNode = rightSide ? instanceNode->right() : instanceNode->nextLeft()) {
        if (insNode == nullptr)
            return false;
        if (ctxNode->isLeaf()) {
            ignore->end();
            while (insNode->isBranch() || 
                    std::find(ignore->begin(), ignore->end(), insNode->element()) != ignore->end()) {
                insNode = rightSide ? insNode->right() : insNode->nextLeft();
                if (insNode == nullptr)
                    return false;
            }
            if (ctxNode->element() != insNode->element() || ctxNode->element() == '_')
                return false;
        } else if (ctxNode->isBranch()) {
            if (!insNode->isBranch())
                return false;
            if (!this->checkRightContext(ctxNode->leftmostChild(), insNode->leftmostChild(), ignore, paramMapping))
                return false;
        }
    }
    if (this->mapArgs(instanceNode->content().values, contextNode->content().params, paramMapping) == nullptr)
        return false;
    return true;
}

template<typename T>
bool Derivator<T>::checkLeftContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, std::list<T> const* ignore, Scope * paramMapping) {
    return this->checkSideContext(contextNode, instanceNode, false, ignore, paramMapping);
}

template<typename T>
bool Derivator<T>::checkRightContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, std::list<T> const* ignore, Scope * paramMapping) {
    return this->checkSideContext(contextNode, instanceNode, true, ignore, paramMapping);
}

template<typename T>
ParseTreeNode<InstanceNodeContent, T> * Derivator<T>::evaluateRightNode(ParseTreeNode<RightSideNodeContent, T> const* node, Scope * paramMapping) {
    ParseTreeNode<InstanceNodeContent, T> * instanceNode = new ParseTreeNode<InstanceNodeContent, T>(node->element(), node->type());
    if (node->isLeaf()) {
        if (node->content().args != nullptr) {
            std::vector<Value> * values = new std::vector<Value>();
            for (LSysDParser::ExpressionContext * arg : *node->content().args) {
                Value ret = evaluator->eval(arg, paramMapping);
                // if (evaluator->messages()->failed())
                if (ret.isError())
                    return nullptr;
                values->push_back(ret);
            }
            instanceNode->content().values = values;
        }
    } else {
        for (ParseTreeNode<RightSideNodeContent, T> * child = node->leftmostChild();
                child != nullptr;
                child = child->right()) {
            ParseTreeNode<InstanceNodeContent, T> * childInstanceNode = this->evaluateRightNode(child, paramMapping);
            if (childInstanceNode == nullptr)
                return nullptr;
            instanceNode->addChild(childInstanceNode);
        }
    }
    return instanceNode;
}

template<typename T>
Scope * Derivator<T>::mapArgs(std::vector<Value> const* values, std::list<Parameter *> const* params, Scope * paramMapping) {
    if (params != nullptr) {
        if (values == nullptr || params->size() != values->size())
            return nullptr;
        std::list<Parameter *>::const_iterator param;
        std::vector<Value>::const_iterator value;
        for (param = params->begin(), value = values->begin();
                param != params->end() && value != values->end();
                ++param, ++value) {
            paramMapping->set(( *param)->name, *value);
        }
    }
    return paramMapping;
}

template<typename T>
Rule<T> const* Derivator<T>::chooseRule(std::list<Rule<T> *> const& rules) {
    if (rules.size() == 1)
        return rules.front();
    double total = 0.0;
    for (Rule<T> const* r : rules) {
        total += r->weight;
        if (r->weight < 0)
            return r;
    }
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    double rnd = (double)rand() / RAND_MAX;
    srand(rand() + millis);
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



template class Derivator<char>;

}
