
// Generated from LSysDParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LSysDParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LSysDParser.
 */
class  LSysDParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LSysDParser.
   */
    virtual antlrcpp::Any visitMain(LSysDParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitSep(LSysDParser::SepContext *context) = 0;

    virtual antlrcpp::Any visitNl(LSysDParser::NlContext *context) = 0;

    virtual antlrcpp::Any visitName(LSysDParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitDefinitions(LSysDParser::DefinitionsContext *context) = 0;

    virtual antlrcpp::Any visitDefinition(LSysDParser::DefinitionContext *context) = 0;

    virtual antlrcpp::Any visitAxiomDef(LSysDParser::AxiomDefContext *context) = 0;

    virtual antlrcpp::Any visitPropDef(LSysDParser::PropDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(LSysDParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitConstDef(LSysDParser::ConstDefContext *context) = 0;

    virtual antlrcpp::Any visitTableBlock(LSysDParser::TableBlockContext *context) = 0;

    virtual antlrcpp::Any visitRulesBlock(LSysDParser::RulesBlockContext *context) = 0;

    virtual antlrcpp::Any visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *context) = 0;

    virtual antlrcpp::Any visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *context) = 0;

    virtual antlrcpp::Any visitRules(LSysDParser::RulesContext *context) = 0;

    virtual antlrcpp::Any visitRuleDefs(LSysDParser::RuleDefsContext *context) = 0;

    virtual antlrcpp::Any visitProductionRuleDefs(LSysDParser::ProductionRuleDefsContext *context) = 0;

    virtual antlrcpp::Any visitCodingRuleDefs(LSysDParser::CodingRuleDefsContext *context) = 0;

    virtual antlrcpp::Any visitAnyRule(LSysDParser::AnyRuleContext *context) = 0;

    virtual antlrcpp::Any visitProductionRule(LSysDParser::ProductionRuleContext *context) = 0;

    virtual antlrcpp::Any visitCodingRule(LSysDParser::CodingRuleContext *context) = 0;

    virtual antlrcpp::Any visitRuleDef(LSysDParser::RuleDefContext *context) = 0;

    virtual antlrcpp::Any visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *context) = 0;

    virtual antlrcpp::Any visitCodingRuleDef(LSysDParser::CodingRuleDefContext *context) = 0;

    virtual antlrcpp::Any visitTagPrefix(LSysDParser::TagPrefixContext *context) = 0;

    virtual antlrcpp::Any visitTag(LSysDParser::TagContext *context) = 0;

    virtual antlrcpp::Any visitWeight(LSysDParser::WeightContext *context) = 0;

    virtual antlrcpp::Any visitLside(LSysDParser::LsideContext *context) = 0;

    virtual antlrcpp::Any visitLcontext(LSysDParser::LcontextContext *context) = 0;

    virtual antlrcpp::Any visitRcontext(LSysDParser::RcontextContext *context) = 0;

    virtual antlrcpp::Any visitRside(LSysDParser::RsideContext *context) = 0;

    virtual antlrcpp::Any visitWord(LSysDParser::WordContext *context) = 0;

    virtual antlrcpp::Any visitLChar(LSysDParser::LCharContext *context) = 0;

    virtual antlrcpp::Any visitLItem(LSysDParser::LItemContext *context) = 0;

    virtual antlrcpp::Any visitRItem(LSysDParser::RItemContext *context) = 0;

    virtual antlrcpp::Any visitValidLeftChar(LSysDParser::ValidLeftCharContext *context) = 0;

    virtual antlrcpp::Any visitValidRightChar(LSysDParser::ValidRightCharContext *context) = 0;

    virtual antlrcpp::Any visitValidChar(LSysDParser::ValidCharContext *context) = 0;

    virtual antlrcpp::Any visitParamsWithCond(LSysDParser::ParamsWithCondContext *context) = 0;

    virtual antlrcpp::Any visitParams(LSysDParser::ParamsContext *context) = 0;

    virtual antlrcpp::Any visitParam(LSysDParser::ParamContext *context) = 0;

    virtual antlrcpp::Any visitCond(LSysDParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitArgs(LSysDParser::ArgsContext *context) = 0;

    virtual antlrcpp::Any visitArg(LSysDParser::ArgContext *context) = 0;

    virtual antlrcpp::Any visitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *context) = 0;

    virtual antlrcpp::Any visitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *context) = 0;

    virtual antlrcpp::Any visitConstExpr(LSysDParser::ConstExprContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallExpr(LSysDParser::FunctionCallExprContext *context) = 0;

    virtual antlrcpp::Any visitIdExpr(LSysDParser::IdExprContext *context) = 0;

    virtual antlrcpp::Any visitBitBinaryExpr(LSysDParser::BitBinaryExprContext *context) = 0;

    virtual antlrcpp::Any visitAritUnaryExpr(LSysDParser::AritUnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedExpr(LSysDParser::ParenthesizedExprContext *context) = 0;

    virtual antlrcpp::Any visitAritBinaryExpr(LSysDParser::AritBinaryExprContext *context) = 0;

    virtual antlrcpp::Any visitIfElseExpr(LSysDParser::IfElseExprContext *context) = 0;

    virtual antlrcpp::Any visitArguments(LSysDParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitArgument(LSysDParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitIntConstant(LSysDParser::IntConstantContext *context) = 0;

    virtual antlrcpp::Any visitFloatConstant(LSysDParser::FloatConstantContext *context) = 0;

    virtual antlrcpp::Any visitStringConstant(LSysDParser::StringConstantContext *context) = 0;

    virtual antlrcpp::Any visitTrueValue(LSysDParser::TrueValueContext *context) = 0;

    virtual antlrcpp::Any visitFalseValue(LSysDParser::FalseValueContext *context) = 0;


};

