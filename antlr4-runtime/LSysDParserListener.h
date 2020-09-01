
// Generated from LSysDParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LSysDParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LSysDParser.
 */
class  LSysDParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(LSysDParser::MainContext *ctx) = 0;
  virtual void exitMain(LSysDParser::MainContext *ctx) = 0;

  virtual void enterSep(LSysDParser::SepContext *ctx) = 0;
  virtual void exitSep(LSysDParser::SepContext *ctx) = 0;

  virtual void enterNl(LSysDParser::NlContext *ctx) = 0;
  virtual void exitNl(LSysDParser::NlContext *ctx) = 0;

  virtual void enterName(LSysDParser::NameContext *ctx) = 0;
  virtual void exitName(LSysDParser::NameContext *ctx) = 0;

  virtual void enterDefinitions(LSysDParser::DefinitionsContext *ctx) = 0;
  virtual void exitDefinitions(LSysDParser::DefinitionsContext *ctx) = 0;

  virtual void enterDefinition(LSysDParser::DefinitionContext *ctx) = 0;
  virtual void exitDefinition(LSysDParser::DefinitionContext *ctx) = 0;

  virtual void enterPropDef(LSysDParser::PropDefContext *ctx) = 0;
  virtual void exitPropDef(LSysDParser::PropDefContext *ctx) = 0;

  virtual void enterFuncDef(LSysDParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(LSysDParser::FuncDefContext *ctx) = 0;

  virtual void enterConstDef(LSysDParser::ConstDefContext *ctx) = 0;
  virtual void exitConstDef(LSysDParser::ConstDefContext *ctx) = 0;

  virtual void enterTableBlock(LSysDParser::TableBlockContext *ctx) = 0;
  virtual void exitTableBlock(LSysDParser::TableBlockContext *ctx) = 0;

  virtual void enterRulesBlock(LSysDParser::RulesBlockContext *ctx) = 0;
  virtual void exitRulesBlock(LSysDParser::RulesBlockContext *ctx) = 0;

  virtual void enterProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) = 0;
  virtual void exitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) = 0;

  virtual void enterCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) = 0;
  virtual void exitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) = 0;

  virtual void enterRules(LSysDParser::RulesContext *ctx) = 0;
  virtual void exitRules(LSysDParser::RulesContext *ctx) = 0;

  virtual void enterRuleDefs(LSysDParser::RuleDefsContext *ctx) = 0;
  virtual void exitRuleDefs(LSysDParser::RuleDefsContext *ctx) = 0;

  virtual void enterProductionRuleDefs(LSysDParser::ProductionRuleDefsContext *ctx) = 0;
  virtual void exitProductionRuleDefs(LSysDParser::ProductionRuleDefsContext *ctx) = 0;

  virtual void enterCodingRuleDefs(LSysDParser::CodingRuleDefsContext *ctx) = 0;
  virtual void exitCodingRuleDefs(LSysDParser::CodingRuleDefsContext *ctx) = 0;

  virtual void enterAnyRule(LSysDParser::AnyRuleContext *ctx) = 0;
  virtual void exitAnyRule(LSysDParser::AnyRuleContext *ctx) = 0;

  virtual void enterProductionRule(LSysDParser::ProductionRuleContext *ctx) = 0;
  virtual void exitProductionRule(LSysDParser::ProductionRuleContext *ctx) = 0;

  virtual void enterCodingRule(LSysDParser::CodingRuleContext *ctx) = 0;
  virtual void exitCodingRule(LSysDParser::CodingRuleContext *ctx) = 0;

  virtual void enterRuleDef(LSysDParser::RuleDefContext *ctx) = 0;
  virtual void exitRuleDef(LSysDParser::RuleDefContext *ctx) = 0;

  virtual void enterProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) = 0;
  virtual void exitProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) = 0;

  virtual void enterCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) = 0;
  virtual void exitCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) = 0;

  virtual void enterTagPrefix(LSysDParser::TagPrefixContext *ctx) = 0;
  virtual void exitTagPrefix(LSysDParser::TagPrefixContext *ctx) = 0;

  virtual void enterTag(LSysDParser::TagContext *ctx) = 0;
  virtual void exitTag(LSysDParser::TagContext *ctx) = 0;

  virtual void enterWeight(LSysDParser::WeightContext *ctx) = 0;
  virtual void exitWeight(LSysDParser::WeightContext *ctx) = 0;

  virtual void enterLside(LSysDParser::LsideContext *ctx) = 0;
  virtual void exitLside(LSysDParser::LsideContext *ctx) = 0;

  virtual void enterLcontext(LSysDParser::LcontextContext *ctx) = 0;
  virtual void exitLcontext(LSysDParser::LcontextContext *ctx) = 0;

  virtual void enterRcontext(LSysDParser::RcontextContext *ctx) = 0;
  virtual void exitRcontext(LSysDParser::RcontextContext *ctx) = 0;

  virtual void enterRside(LSysDParser::RsideContext *ctx) = 0;
  virtual void exitRside(LSysDParser::RsideContext *ctx) = 0;

  virtual void enterWord(LSysDParser::WordContext *ctx) = 0;
  virtual void exitWord(LSysDParser::WordContext *ctx) = 0;

  virtual void enterLChar(LSysDParser::LCharContext *ctx) = 0;
  virtual void exitLChar(LSysDParser::LCharContext *ctx) = 0;

  virtual void enterLItem(LSysDParser::LItemContext *ctx) = 0;
  virtual void exitLItem(LSysDParser::LItemContext *ctx) = 0;

  virtual void enterRItem(LSysDParser::RItemContext *ctx) = 0;
  virtual void exitRItem(LSysDParser::RItemContext *ctx) = 0;

  virtual void enterValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) = 0;
  virtual void exitValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) = 0;

  virtual void enterValidRightChar(LSysDParser::ValidRightCharContext *ctx) = 0;
  virtual void exitValidRightChar(LSysDParser::ValidRightCharContext *ctx) = 0;

  virtual void enterValidChar(LSysDParser::ValidCharContext *ctx) = 0;
  virtual void exitValidChar(LSysDParser::ValidCharContext *ctx) = 0;

  virtual void enterParamsWithCond(LSysDParser::ParamsWithCondContext *ctx) = 0;
  virtual void exitParamsWithCond(LSysDParser::ParamsWithCondContext *ctx) = 0;

  virtual void enterParams(LSysDParser::ParamsContext *ctx) = 0;
  virtual void exitParams(LSysDParser::ParamsContext *ctx) = 0;

  virtual void enterParam(LSysDParser::ParamContext *ctx) = 0;
  virtual void exitParam(LSysDParser::ParamContext *ctx) = 0;

  virtual void enterCond(LSysDParser::CondContext *ctx) = 0;
  virtual void exitCond(LSysDParser::CondContext *ctx) = 0;

  virtual void enterArgs(LSysDParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(LSysDParser::ArgsContext *ctx) = 0;

  virtual void enterArg(LSysDParser::ArgContext *ctx) = 0;
  virtual void exitArg(LSysDParser::ArgContext *ctx) = 0;

  virtual void enterLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *ctx) = 0;
  virtual void exitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *ctx) = 0;

  virtual void enterCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *ctx) = 0;
  virtual void exitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *ctx) = 0;

  virtual void enterConstExpr(LSysDParser::ConstExprContext *ctx) = 0;
  virtual void exitConstExpr(LSysDParser::ConstExprContext *ctx) = 0;

  virtual void enterFunctionCallExpr(LSysDParser::FunctionCallExprContext *ctx) = 0;
  virtual void exitFunctionCallExpr(LSysDParser::FunctionCallExprContext *ctx) = 0;

  virtual void enterIdExpr(LSysDParser::IdExprContext *ctx) = 0;
  virtual void exitIdExpr(LSysDParser::IdExprContext *ctx) = 0;

  virtual void enterBitBinaryExpr(LSysDParser::BitBinaryExprContext *ctx) = 0;
  virtual void exitBitBinaryExpr(LSysDParser::BitBinaryExprContext *ctx) = 0;

  virtual void enterAritUnaryExpr(LSysDParser::AritUnaryExprContext *ctx) = 0;
  virtual void exitAritUnaryExpr(LSysDParser::AritUnaryExprContext *ctx) = 0;

  virtual void enterLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *ctx) = 0;
  virtual void exitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *ctx) = 0;

  virtual void enterParenthesizedExpr(LSysDParser::ParenthesizedExprContext *ctx) = 0;
  virtual void exitParenthesizedExpr(LSysDParser::ParenthesizedExprContext *ctx) = 0;

  virtual void enterAritBinaryExpr(LSysDParser::AritBinaryExprContext *ctx) = 0;
  virtual void exitAritBinaryExpr(LSysDParser::AritBinaryExprContext *ctx) = 0;

  virtual void enterIfElseExpr(LSysDParser::IfElseExprContext *ctx) = 0;
  virtual void exitIfElseExpr(LSysDParser::IfElseExprContext *ctx) = 0;

  virtual void enterArguments(LSysDParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(LSysDParser::ArgumentsContext *ctx) = 0;

  virtual void enterArgument(LSysDParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(LSysDParser::ArgumentContext *ctx) = 0;

  virtual void enterIntConstant(LSysDParser::IntConstantContext *ctx) = 0;
  virtual void exitIntConstant(LSysDParser::IntConstantContext *ctx) = 0;

  virtual void enterFloatConstant(LSysDParser::FloatConstantContext *ctx) = 0;
  virtual void exitFloatConstant(LSysDParser::FloatConstantContext *ctx) = 0;

  virtual void enterStringConstant(LSysDParser::StringConstantContext *ctx) = 0;
  virtual void exitStringConstant(LSysDParser::StringConstantContext *ctx) = 0;

  virtual void enterTrueValue(LSysDParser::TrueValueContext *ctx) = 0;
  virtual void exitTrueValue(LSysDParser::TrueValueContext *ctx) = 0;

  virtual void enterFalseValue(LSysDParser::FalseValueContext *ctx) = 0;
  virtual void exitFalseValue(LSysDParser::FalseValueContext *ctx) = 0;


};

