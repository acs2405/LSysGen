
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
    TreeBranch<LeftSideNodeContent, T> const* const lctx;
    TreeLeaf<LeftSideNodeContent, T> const* const lside;
    TreeBranch<LeftSideNodeContent, T> const* const rctx;
    TreeBranch<RightSideNodeContent, T> const* const rside;

protected:
    Rule(// std::string const& tag, 
        weight_t weight, 
        TreeBranch<LeftSideNodeContent, T> const* lctx, 
        TreeLeaf<LeftSideNodeContent, T> const* lside, 
        TreeBranch<LeftSideNodeContent, T> const* rctx, 
        LSysDParser::ExpressionContext * cond,
        TreeBranch<RightSideNodeContent, T> const* rside);

    std::string toStringBase(std::string arrow) const;

public:
    ~Rule();

    char leftChar() const;
    std::vector<Parameter *> const* params() const;
    LSysDParser::ExpressionContext * cond();

    virtual bool isProductionRule() const;

    virtual std::string toString() const;

};

template<typename T>
class ProductionRule : Rule<T> {
public:
    ProductionRule(// std::string const& tag, 
        weight_t const weight, 
        TreeBranch<LeftSideNodeContent, T> const* lctx, 
        TreeLeaf<LeftSideNodeContent, T> const* lside, 
        TreeBranch<LeftSideNodeContent, T> const* rctx, 
        LSysDParser::ExpressionContext * cond, 
        TreeBranch<RightSideNodeContent, T> const* rside);

    bool isProductionRule() const;

    std::string toString() const override;
};

template<typename T>
class CodingRule : Rule<T> {
public:
    CodingRule(// std::string const& tag, 
        weight_t const weight, 
        TreeBranch<LeftSideNodeContent, T> const* lctx, 
        TreeLeaf<LeftSideNodeContent, T> const* lside, 
        TreeBranch<LeftSideNodeContent, T> const* rctx, 
        LSysDParser::ExpressionContext * cond, 
        TreeBranch<RightSideNodeContent, T> const* rside);

    bool isProductionRule() const;

    std::string toString() const override;
};

template<typename T>
std::ostream & operator<<(std::ostream & os, Rule<T> const& r);

}
