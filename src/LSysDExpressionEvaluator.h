
#pragma once


class LSysDExpressionEvaluator;


#include "common.h"
#include "LSysDParserBaseVisitor.h"
// #include "antlr4-runtime.h"
#include "values.h"
#include "operations.h"
#include "ErrorHandler.h"

using namespace lsysgen;

class LSysDExpressionEvaluator: public LSysDParserBaseVisitor {
    friend Operations;
    
    ErrorHandler* eh;
    Operations* ops;
    Scope * scope;

public:
    // LSysDExpressionEvaluator(std::string const& filename, std::vector<std::string> const* sourceLines);
    LSysDExpressionEvaluator(ErrorHandler * eh);
    LSysDExpressionEvaluator(LSysDExpressionEvaluator const& ev);

    ~LSysDExpressionEvaluator();

    ErrorHandler * messages();

    Value eval(LSysDParser::ExpressionContext* expr, Scope * scope);

private:
    std::any visitConstExpr(LSysDParser::ConstExprContext *ctx) override;

    std::any visitIdExpr(LSysDParser::IdExprContext *ctx) override;

    std::any visitAritBinaryExpr(LSysDParser::AritBinaryExprContext *ctx) override;

    // std::any visitFunctionDefExpr(LSysDParser::FunctionDefExprContext *ctx) override;

    // std::any visitIndexExpr(LSysDParser::IndexExprContext *ctx) override;

    // std::any visitSetDefExpr(LSysDParser::SetDefExprContext *ctx) override;

    std::any visitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *ctx) override;

    std::any visitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *ctx) override;

    std::any visitFunctionCallExpr(LSysDParser::FunctionCallExprContext *ctx) override;

    // std::any visitTupleDefExpr(LSysDParser::TupleDefExprContext *ctx) override;

    std::any visitBitBinaryExpr(LSysDParser::BitBinaryExprContext *ctx) override;

    // std::any visitListDefExpr(LSysDParser::ListDefExprContext *ctx) override;

    // std::any visitMapDefExpr(LSysDParser::MapDefExprContext *ctx) override;

    std::any visitAritUnaryExpr(LSysDParser::AritUnaryExprContext *ctx) override;

    std::any visitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *ctx) override;

    std::any visitParenthesizedExpr(LSysDParser::ParenthesizedExprContext *ctx) override;

    // std::any visitPropertyAccessorExpr(LSysDParser::PropertyAccessorExprContext *ctx) override;

    // std::any visitInExpr(LSysDParser::InExprContext *ctx) override;

    std::any visitIfElseExpr(LSysDParser::IfElseExprContext *ctx) override;

    std::any visitArguments(LSysDParser::ArgumentsContext *ctx) override;

    std::any visitArgument(LSysDParser::ArgumentContext *ctx) override;

    // std::any visitIndexes(LSysDParser::IndexesContext *ctx) override;

    // std::any visitIndex(LSysDParser::IndexContext *ctx) override;

    // std::any visitFormalParameters(LSysDParser::FormalParametersContext *ctx) override;

    // std::any visitFormalParameter(LSysDParser::FormalParameterContext *ctx) override;

    // std::any visitIteratordef(LSysDParser::IteratordefContext *ctx) override;

    // std::any visitListdef(LSysDParser::ListdefContext *ctx) override;

    // std::any visitTupledef(LSysDParser::TupledefContext *ctx) override;

    // std::any visitSetdef(LSysDParser::SetdefContext *ctx) override;

    // std::any visitMapdef(LSysDParser::MapdefContext *ctx) override;

    // std::any visitMapiteratordef(LSysDParser::MapiteratordefContext *ctx) override;

    // std::any visitMapitem(LSysDParser::MapitemContext *ctx) override;

    // std::any visitFunctiondef(LSysDParser::FunctiondefContext *ctx) override;

    // std::any visitSource(LSysDParser::SourceContext *ctx) override;

    std::any visitIntConstant(LSysDParser::IntConstantContext *ctx) override;

    std::any visitFloatConstant(LSysDParser::FloatConstantContext *ctx) override;

    std::any visitStringConstant(LSysDParser::StringConstantContext *ctx) override;

    std::any visitTrueValue(LSysDParser::TrueValueContext *ctx) override;

    std::any visitFalseValue(LSysDParser::FalseValueContext *ctx) override;

    std::any visitNullValue(LSysDParser::NullValueContext *ctx) override;
};
