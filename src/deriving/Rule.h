
#pragma once


namespace lsysgen {

template<typename>
class Rule;
template<typename>
class ProductionRule;
template<typename>
class CodingRule;

}

#include "common.h"
#include "TreeNode.h"
// #include "values.h"


namespace lsysgen {

typedef double weight_t;

template<typename T>
class Rule {
    LSysDParser::ExpressionContext * _cond;

public:
    static weight_t const WEIGHT_ALWAYS;
    static weight_t const WEIGHT_UNSET;

    // const std::string tag;
    weight_t const weight;
    TreeNode<LeftSideNodeContent, T> const* lctx;
    TreeNode<LeftSideNodeContent, T> const* lside;
    TreeNode<LeftSideNodeContent, T> const* rctx;
    TreeNode<RightSideNodeContent, T> const* rside;

protected:
    Rule(// std::string const& tag, 
        weight_t weight, 
        TreeNode<LeftSideNodeContent, T> const* lctx, 
        TreeNode<LeftSideNodeContent, T> const* lside, 
        TreeNode<LeftSideNodeContent, T> const* rctx, 
        LSysDParser::ExpressionContext * cond,
        TreeNode<RightSideNodeContent, T> const* rside);

    std::string toStringBase(std::string arrow) const;

public:
    virtual ~Rule();

    char leftChar() const;
    std::list<Parameter *> const* params() const;
    LSysDParser::ExpressionContext * cond();

    virtual bool isProductionRule() const;

    virtual std::string toString() const;

};

template<typename T>
class ProductionRule : Rule<T> {
public:
    ProductionRule(// std::string const& tag, 
        weight_t const weight, 
        TreeNode<LeftSideNodeContent, T> const* lctx, 
        TreeNode<LeftSideNodeContent, T> const* lside, 
        TreeNode<LeftSideNodeContent, T> const* rctx, 
        LSysDParser::ExpressionContext * cond, 
        TreeNode<RightSideNodeContent, T> const* rside);

    bool isProductionRule() const;

    std::string toString() const override;
};

template<typename T>
class CodingRule : Rule<T> {
public:
    CodingRule(// std::string const& tag, 
        weight_t const weight, 
        TreeNode<LeftSideNodeContent, T> const* lctx, 
        TreeNode<LeftSideNodeContent, T> const* lside, 
        TreeNode<LeftSideNodeContent, T> const* rctx, 
        LSysDParser::ExpressionContext * cond, 
        TreeNode<RightSideNodeContent, T> const* rside);

    bool isProductionRule() const;

    std::string toString() const override;
};

template<typename T>
std::ostream & operator<<(std::ostream & os, Rule<T> const& r);

}
