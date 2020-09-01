
#pragma once


namespace lsys {

template<typename>
class Rule;
template<typename>
class ProductionRule;
template<typename>
class codingRule;

}

#include "ParseTreeNode.h"

#include <string>
#include <iostream>

namespace lsys {

typedef double weight_t;

template<typename T>
class Rule {
public:
	static const weight_t WEIGHT_ALWAYS;
	static const weight_t WEIGHT_UNSET;

	const std::string tag;
	const weight_t weight;
	const ParseTreeNode<LeftSideNodeContent, T>* lctx;
	const ParseTreeNode<LeftSideNodeContent, T>* lside;
	const ParseTreeNode<LeftSideNodeContent, T>* rctx;
	const ParseTreeNode<RightSideNodeContent, T>* rside;

protected:
	Rule(std::string const& tag, 
		weight_t const weight, 
		ParseTreeNode<LeftSideNodeContent, T>* const lctx, 
		ParseTreeNode<LeftSideNodeContent, T>* const lside, 
		ParseTreeNode<LeftSideNodeContent, T>* const rctx, 
		ParseTreeNode<RightSideNodeContent, T>* const rside);

	std::string toStringBase(std::string arrow);

public:
	~Rule();

	char leftChar() const;
	std::list<Parameter*>* params();
	LSysDParser::ExpressionContext* cond();

	virtual bool isProductionRule() const;

	virtual std::string toString();

};

template<typename T>
class ProductionRule : Rule<T> {
public:
	ProductionRule(std::string const& tag, 
		weight_t const weight, 
		ParseTreeNode<LeftSideNodeContent, T>* const lctx, 
		ParseTreeNode<LeftSideNodeContent, T>* const lside, 
		ParseTreeNode<LeftSideNodeContent, T>* const rctx, 
		ParseTreeNode<RightSideNodeContent, T>* const rside);

	bool isProductionRule() const;

	std::string toString() override;
};

template<typename T>
class CodingRule : Rule<T> {
public:
	CodingRule(std::string const& tag, 
		weight_t const weight, 
		ParseTreeNode<LeftSideNodeContent, T>* const lctx, 
		ParseTreeNode<LeftSideNodeContent, T>* const lside, 
		ParseTreeNode<LeftSideNodeContent, T>* const rctx, 
		ParseTreeNode<RightSideNodeContent, T>* const rside);

	bool isProductionRule() const;

	std::string toString() override;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Rule<T>& r);

}
