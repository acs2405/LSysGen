
#pragma once


namespace lsysgen {

template<typename T>
class Derivator;

}

#include "common.h"
#include "TreeNode.h"
#include "NodeContent.h"
#include "Table.h"
#include "Rule.h"
#include "values.h"
#include "ErrorHandler.h"
#include "misc.h"

namespace lsysgen {

template<typename T>
class Derivator {
	ErrorHandler * eh;
    LSysDExpressionEvaluator * evaluator;
    Random * _random;

    bool checkSideContext(TreeNode<LeftSideNodeContent, T> * contextNode, TreeNode<InstanceNodeContent, T> * instanceNode, bool rightSide, std::vector<T> const& ignore, Scope * paramMapping);
    bool checkLeftContext(TreeNode<LeftSideNodeContent, T> * contextNode, TreeNode<InstanceNodeContent, T> * instanceNode, std::vector<T> const& ignore, Scope * paramMapping);
    bool checkRightContext(TreeNode<LeftSideNodeContent, T> * contextNode, TreeNode<InstanceNodeContent, T> * instanceNode, std::vector<T> const& ignore, Scope * paramMapping);
    TreeNode<InstanceNodeContent, T> * evaluateRightNode(TreeNode<RightSideNodeContent, T> const* rightNode, Scope * paramMapping);
    bool mapArgs(std::vector<Value> const* values, std::vector<Parameter *> const* params, Scope * paramMapping);
    Rule<T> const* chooseRule(std::vector<Rule<T> *> const& rules);

public:
	Derivator(ErrorHandler * eh, LSysDExpressionEvaluator * ee, Random * rnd);

	~Derivator();

    TreeBranch<InstanceNodeContent, T> * derive(TreeNode<InstanceNodeContent, T> const* node, Table<T> const& table, std::vector<T> const& ignore, Scope * scope=nullptr);

    Random * random();
    Random const* random() const;
};

}
