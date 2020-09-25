
#pragma once


class LSysDExpressionEvaluator;


#include "LSysDParserBaseVisitor.h"
#include "antlr4-runtime.h"
#include "values.h"
#include "operations.h"
#include "ErrorHandler.h"

#include <string>
#include <iostream>

using namespace lsysgen;

class LSysDExpressionEvaluator: public LSysDParserBaseVisitor {
    friend Operations;
    
    ErrorHandler* eh;
    Operations* ops;
    Scope* scope;

public:
    LSysDExpressionEvaluator(std::string const& filename, const std::vector<std::string>* sourceLines);
    LSysDExpressionEvaluator(const ErrorHandler* eh);
    LSysDExpressionEvaluator(const LSysDExpressionEvaluator* ev);

    ~LSysDExpressionEvaluator();

    Value eval(LSysDParser::ExpressionContext* expr, Scope* scope);

private:
    antlrcpp::Any visitConstExpr(LSysDParser::ConstExprContext *ctx) override;

    antlrcpp::Any visitIdExpr(LSysDParser::IdExprContext *ctx) override;

    antlrcpp::Any visitAritBinaryExpr(LSysDParser::AritBinaryExprContext *ctx) override;

    // antlrcpp::Any visitFunctionDefExpr(LSysDParser::FunctionDefExprContext *ctx) override;

    // antlrcpp::Any visitIndexExpr(LSysDParser::IndexExprContext *ctx) override;

    // antlrcpp::Any visitSetDefExpr(LSysDParser::SetDefExprContext *ctx) override;

    antlrcpp::Any visitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *ctx) override;

    antlrcpp::Any visitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *ctx) override;

    antlrcpp::Any visitFunctionCallExpr(LSysDParser::FunctionCallExprContext *ctx) override;

    // antlrcpp::Any visitTupleDefExpr(LSysDParser::TupleDefExprContext *ctx) override;

    antlrcpp::Any visitBitBinaryExpr(LSysDParser::BitBinaryExprContext *ctx) override;

    // antlrcpp::Any visitListDefExpr(LSysDParser::ListDefExprContext *ctx) override;

    // antlrcpp::Any visitMapDefExpr(LSysDParser::MapDefExprContext *ctx) override;

    antlrcpp::Any visitAritUnaryExpr(LSysDParser::AritUnaryExprContext *ctx) override;

    antlrcpp::Any visitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *ctx) override;

    antlrcpp::Any visitParenthesizedExpr(LSysDParser::ParenthesizedExprContext *ctx) override;

    // antlrcpp::Any visitPropertyAccessorExpr(LSysDParser::PropertyAccessorExprContext *ctx) override;

    // antlrcpp::Any visitInExpr(LSysDParser::InExprContext *ctx) override;

    antlrcpp::Any visitIfElseExpr(LSysDParser::IfElseExprContext *ctx) override;

    antlrcpp::Any visitArguments(LSysDParser::ArgumentsContext *ctx) override;

    antlrcpp::Any visitArgument(LSysDParser::ArgumentContext *ctx) override;

    // antlrcpp::Any visitIndexes(LSysDParser::IndexesContext *ctx) override;

    // antlrcpp::Any visitIndex(LSysDParser::IndexContext *ctx) override;

    // antlrcpp::Any visitFormalParameters(LSysDParser::FormalParametersContext *ctx) override;

    // antlrcpp::Any visitFormalParameter(LSysDParser::FormalParameterContext *ctx) override;

    // antlrcpp::Any visitIteratordef(LSysDParser::IteratordefContext *ctx) override;

    // antlrcpp::Any visitListdef(LSysDParser::ListdefContext *ctx) override;

    // antlrcpp::Any visitTupledef(LSysDParser::TupledefContext *ctx) override;

    // antlrcpp::Any visitSetdef(LSysDParser::SetdefContext *ctx) override;

    // antlrcpp::Any visitMapdef(LSysDParser::MapdefContext *ctx) override;

    // antlrcpp::Any visitMapiteratordef(LSysDParser::MapiteratordefContext *ctx) override;

    // antlrcpp::Any visitMapitem(LSysDParser::MapitemContext *ctx) override;

    // antlrcpp::Any visitFunctiondef(LSysDParser::FunctiondefContext *ctx) override;

    // antlrcpp::Any visitSource(LSysDParser::SourceContext *ctx) override;

    antlrcpp::Any visitIntConstant(LSysDParser::IntConstantContext *ctx) override;

    antlrcpp::Any visitFloatConstant(LSysDParser::FloatConstantContext *ctx) override;

    antlrcpp::Any visitStringConstant(LSysDParser::StringConstantContext *ctx) override;

    antlrcpp::Any visitTrueValue(LSysDParser::TrueValueContext *ctx) override;

    antlrcpp::Any visitFalseValue(LSysDParser::FalseValueContext *ctx) override;

    antlrcpp::Any visitNullValue(LSysDParser::NullValueContext *ctx) override;
};
