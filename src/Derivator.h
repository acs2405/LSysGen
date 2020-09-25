
#pragma once


namespace lsysgen {

template<typename T>
class Derivator;

}

#include "ParseTreeNode.h"
#include "NodeContent.h"
#include "Table.h"
#include "Rule.h"
#include "values.h"
#include "ErrorHandler.h"

#include <string>
#include <list>
#include <vector>

namespace lsysgen {

template<typename T>
class Derivator {
	ErrorHandler * eh;
    LSysDExpressionEvaluator * evaluator;

    bool checkSideContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, bool rightSide, std::list<T> const* ignore, Scope * paramMapping);
    bool checkLeftContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, std::list<T> const* ignore, Scope * paramMapping);
    bool checkRightContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, std::list<T> const* ignore, Scope * paramMapping);
    ParseTreeNode<InstanceNodeContent, T> * evaluateRightNode(ParseTreeNode<RightSideNodeContent, T> const* node, Scope * paramMapping);
    Scope * mapArgs(std::vector<Value> const* values, std::list<Parameter *> const* params, Scope * paramMapping);
    Rule<T> const* chooseRule(std::list<Rule<T> *> const& rules);

public:
	Derivator(ErrorHandler * eh, LSysDExpressionEvaluator * ee);

	~Derivator();

    ParseTreeNode<InstanceNodeContent, T> * derive(ParseTreeNode<InstanceNodeContent, T> const* node, Table<T> const* table, std::list<T> const* ignore=nullptr, Scope * scope=nullptr);
};

}
