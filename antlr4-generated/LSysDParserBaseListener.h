
// Generated from LSysDParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LSysDParserListener.h"


/**
 * This class provides an empty implementation of LSysDParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LSysDParserBaseListener : public LSysDParserListener {
public:

  virtual void enterMain(LSysDParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(LSysDParser::MainContext * /*ctx*/) override { }

  virtual void enterSep(LSysDParser::SepContext * /*ctx*/) override { }
  virtual void exitSep(LSysDParser::SepContext * /*ctx*/) override { }

  virtual void enterNl(LSysDParser::NlContext * /*ctx*/) override { }
  virtual void exitNl(LSysDParser::NlContext * /*ctx*/) override { }

  virtual void enterName(LSysDParser::NameContext * /*ctx*/) override { }
  virtual void exitName(LSysDParser::NameContext * /*ctx*/) override { }

  virtual void enterDefinitions(LSysDParser::DefinitionsContext * /*ctx*/) override { }
  virtual void exitDefinitions(LSysDParser::DefinitionsContext * /*ctx*/) override { }

  virtual void enterDefinition(LSysDParser::DefinitionContext * /*ctx*/) override { }
  virtual void exitDefinition(LSysDParser::DefinitionContext * /*ctx*/) override { }

  virtual void enterPropDef(LSysDParser::PropDefContext * /*ctx*/) override { }
  virtual void exitPropDef(LSysDParser::PropDefContext * /*ctx*/) override { }

  virtual void enterFuncDef(LSysDParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(LSysDParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterConstDef(LSysDParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(LSysDParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterTableBlock(LSysDParser::TableBlockContext * /*ctx*/) override { }
  virtual void exitTableBlock(LSysDParser::TableBlockContext * /*ctx*/) override { }

  virtual void enterRulesBlock(LSysDParser::RulesBlockContext * /*ctx*/) override { }
  virtual void exitRulesBlock(LSysDParser::RulesBlockContext * /*ctx*/) override { }

  virtual void enterProductionRulesBlock(LSysDParser::ProductionRulesBlockContext * /*ctx*/) override { }
  virtual void exitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext * /*ctx*/) override { }

  virtual void enterCodingRulesBlock(LSysDParser::CodingRulesBlockContext * /*ctx*/) override { }
  virtual void exitCodingRulesBlock(LSysDParser::CodingRulesBlockContext * /*ctx*/) override { }

  virtual void enterRules(LSysDParser::RulesContext * /*ctx*/) override { }
  virtual void exitRules(LSysDParser::RulesContext * /*ctx*/) override { }

  virtual void enterRuleDefs(LSysDParser::RuleDefsContext * /*ctx*/) override { }
  virtual void exitRuleDefs(LSysDParser::RuleDefsContext * /*ctx*/) override { }

  virtual void enterProductionRuleDefs(LSysDParser::ProductionRuleDefsContext * /*ctx*/) override { }
  virtual void exitProductionRuleDefs(LSysDParser::ProductionRuleDefsContext * /*ctx*/) override { }

  virtual void enterCodingRuleDefs(LSysDParser::CodingRuleDefsContext * /*ctx*/) override { }
  virtual void exitCodingRuleDefs(LSysDParser::CodingRuleDefsContext * /*ctx*/) override { }

  virtual void enterAnyRule(LSysDParser::AnyRuleContext * /*ctx*/) override { }
  virtual void exitAnyRule(LSysDParser::AnyRuleContext * /*ctx*/) override { }

  virtual void enterProductionRule(LSysDParser::ProductionRuleContext * /*ctx*/) override { }
  virtual void exitProductionRule(LSysDParser::ProductionRuleContext * /*ctx*/) override { }

  virtual void enterCodingRule(LSysDParser::CodingRuleContext * /*ctx*/) override { }
  virtual void exitCodingRule(LSysDParser::CodingRuleContext * /*ctx*/) override { }

  virtual void enterRuleDef(LSysDParser::RuleDefContext * /*ctx*/) override { }
  virtual void exitRuleDef(LSysDParser::RuleDefContext * /*ctx*/) override { }

  virtual void enterProductionRuleDef(LSysDParser::ProductionRuleDefContext * /*ctx*/) override { }
  virtual void exitProductionRuleDef(LSysDParser::ProductionRuleDefContext * /*ctx*/) override { }

  virtual void enterCodingRuleDef(LSysDParser::CodingRuleDefContext * /*ctx*/) override { }
  virtual void exitCodingRuleDef(LSysDParser::CodingRuleDefContext * /*ctx*/) override { }

  virtual void enterTagPrefix(LSysDParser::TagPrefixContext * /*ctx*/) override { }
  virtual void exitTagPrefix(LSysDParser::TagPrefixContext * /*ctx*/) override { }

  virtual void enterTag(LSysDParser::TagContext * /*ctx*/) override { }
  virtual void exitTag(LSysDParser::TagContext * /*ctx*/) override { }

  virtual void enterWeight(LSysDParser::WeightContext * /*ctx*/) override { }
  virtual void exitWeight(LSysDParser::WeightContext * /*ctx*/) override { }

  virtual void enterLside(LSysDParser::LsideContext * /*ctx*/) override { }
  virtual void exitLside(LSysDParser::LsideContext * /*ctx*/) override { }

  virtual void enterLcontext(LSysDParser::LcontextContext * /*ctx*/) override { }
  virtual void exitLcontext(LSysDParser::LcontextContext * /*ctx*/) override { }

  virtual void enterRcontext(LSysDParser::RcontextContext * /*ctx*/) override { }
  virtual void exitRcontext(LSysDParser::RcontextContext * /*ctx*/) override { }

  virtual void enterRside(LSysDParser::RsideContext * /*ctx*/) override { }
  virtual void exitRside(LSysDParser::RsideContext * /*ctx*/) override { }

  virtual void enterWord(LSysDParser::WordContext * /*ctx*/) override { }
  virtual void exitWord(LSysDParser::WordContext * /*ctx*/) override { }

  virtual void enterLChar(LSysDParser::LCharContext * /*ctx*/) override { }
  virtual void exitLChar(LSysDParser::LCharContext * /*ctx*/) override { }

  virtual void enterLItem(LSysDParser::LItemContext * /*ctx*/) override { }
  virtual void exitLItem(LSysDParser::LItemContext * /*ctx*/) override { }

  virtual void enterRItem(LSysDParser::RItemContext * /*ctx*/) override { }
  virtual void exitRItem(LSysDParser::RItemContext * /*ctx*/) override { }

  virtual void enterValidLeftChar(LSysDParser::ValidLeftCharContext * /*ctx*/) override { }
  virtual void exitValidLeftChar(LSysDParser::ValidLeftCharContext * /*ctx*/) override { }

  virtual void enterValidRightChar(LSysDParser::ValidRightCharContext * /*ctx*/) override { }
  virtual void exitValidRightChar(LSysDParser::ValidRightCharContext * /*ctx*/) override { }

  virtual void enterValidChar(LSysDParser::ValidCharContext * /*ctx*/) override { }
  virtual void exitValidChar(LSysDParser::ValidCharContext * /*ctx*/) override { }

  virtual void enterParamsWithCond(LSysDParser::ParamsWithCondContext * /*ctx*/) override { }
  virtual void exitParamsWithCond(LSysDParser::ParamsWithCondContext * /*ctx*/) override { }

  virtual void enterParams(LSysDParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(LSysDParser::ParamsContext * /*ctx*/) override { }

  virtual void enterParam(LSysDParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(LSysDParser::ParamContext * /*ctx*/) override { }

  virtual void enterCond(LSysDParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(LSysDParser::CondContext * /*ctx*/) override { }

  virtual void enterArgs(LSysDParser::ArgsContext * /*ctx*/) override { }
  virtual void exitArgs(LSysDParser::ArgsContext * /*ctx*/) override { }

  virtual void enterArg(LSysDParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(LSysDParser::ArgContext * /*ctx*/) override { }

  virtual void enterLogicBinaryExpr(LSysDParser::LogicBinaryExprContext * /*ctx*/) override { }
  virtual void exitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext * /*ctx*/) override { }

  virtual void enterCmpBinaryExpr(LSysDParser::CmpBinaryExprContext * /*ctx*/) override { }
  virtual void exitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext * /*ctx*/) override { }

  virtual void enterConstExpr(LSysDParser::ConstExprContext * /*ctx*/) override { }
  virtual void exitConstExpr(LSysDParser::ConstExprContext * /*ctx*/) override { }

  virtual void enterFunctionCallExpr(LSysDParser::FunctionCallExprContext * /*ctx*/) override { }
  virtual void exitFunctionCallExpr(LSysDParser::FunctionCallExprContext * /*ctx*/) override { }

  virtual void enterIdExpr(LSysDParser::IdExprContext * /*ctx*/) override { }
  virtual void exitIdExpr(LSysDParser::IdExprContext * /*ctx*/) override { }

  virtual void enterBitBinaryExpr(LSysDParser::BitBinaryExprContext * /*ctx*/) override { }
  virtual void exitBitBinaryExpr(LSysDParser::BitBinaryExprContext * /*ctx*/) override { }

  virtual void enterAritUnaryExpr(LSysDParser::AritUnaryExprContext * /*ctx*/) override { }
  virtual void exitAritUnaryExpr(LSysDParser::AritUnaryExprContext * /*ctx*/) override { }

  virtual void enterLogicUnaryExpr(LSysDParser::LogicUnaryExprContext * /*ctx*/) override { }
  virtual void exitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext * /*ctx*/) override { }

  virtual void enterParenthesizedExpr(LSysDParser::ParenthesizedExprContext * /*ctx*/) override { }
  virtual void exitParenthesizedExpr(LSysDParser::ParenthesizedExprContext * /*ctx*/) override { }

  virtual void enterAritBinaryExpr(LSysDParser::AritBinaryExprContext * /*ctx*/) override { }
  virtual void exitAritBinaryExpr(LSysDParser::AritBinaryExprContext * /*ctx*/) override { }

  virtual void enterIfElseExpr(LSysDParser::IfElseExprContext * /*ctx*/) override { }
  virtual void exitIfElseExpr(LSysDParser::IfElseExprContext * /*ctx*/) override { }

  virtual void enterArguments(LSysDParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(LSysDParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterArgument(LSysDParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(LSysDParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterIntConstant(LSysDParser::IntConstantContext * /*ctx*/) override { }
  virtual void exitIntConstant(LSysDParser::IntConstantContext * /*ctx*/) override { }

  virtual void enterFloatConstant(LSysDParser::FloatConstantContext * /*ctx*/) override { }
  virtual void exitFloatConstant(LSysDParser::FloatConstantContext * /*ctx*/) override { }

  virtual void enterStringConstant(LSysDParser::StringConstantContext * /*ctx*/) override { }
  virtual void exitStringConstant(LSysDParser::StringConstantContext * /*ctx*/) override { }

  virtual void enterTrueValue(LSysDParser::TrueValueContext * /*ctx*/) override { }
  virtual void exitTrueValue(LSysDParser::TrueValueContext * /*ctx*/) override { }

  virtual void enterFalseValue(LSysDParser::FalseValueContext * /*ctx*/) override { }
  virtual void exitFalseValue(LSysDParser::FalseValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

