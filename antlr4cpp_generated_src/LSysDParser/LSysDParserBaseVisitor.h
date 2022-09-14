
// Generated from LSysDParser.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "LSysDParserVisitor.h"


/**
 * This class provides an empty implementation of LSysDParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LSysDParserBaseVisitor : public LSysDParserVisitor {
public:

  virtual std::any visitMain(LSysDParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMainWord(LSysDParser::MainWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMainRuleDefs(LSysDParser::MainRuleDefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModule(LSysDParser::ModuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalDefs(LSysDParser::GlobalDefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalDef(LSysDParser::GlobalDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(LSysDParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDeclaration(LSysDParser::VarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDeclaration(LSysDParser::ConstDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLsystem(LSysDParser::LsystemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSep(LSysDParser::SepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNl(LSysDParser::NlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInLsysDefs(LSysDParser::InLsysDefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInLsysDef(LSysDParser::InLsysDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockOrOneStatement(LSysDParser::BlockOrOneStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(LSysDParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOneStatement(LSysDParser::OneStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOneStmtNeedsSep(LSysDParser::OneStmtNeedsSepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOneStmtEndsInBlock(LSysDParser::OneStmtEndsInBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(LSysDParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(LSysDParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAxiomDef(LSysDParser::AxiomDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropDef(LSysDParser::PropDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(LSysDParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(LSysDParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTableBlock(LSysDParser::TableBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRulesBlock(LSysDParser::RulesBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRules(LSysDParser::RulesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRuleDefs(LSysDParser::RuleDefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductionRuleDefs(LSysDParser::ProductionRuleDefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodingRuleDefs(LSysDParser::CodingRuleDefsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnyRule(LSysDParser::AnyRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductionRule(LSysDParser::ProductionRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodingRule(LSysDParser::CodingRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRuleDef(LSysDParser::RuleDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTagPrefix(LSysDParser::TagPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTag(LSysDParser::TagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWeight(LSysDParser::WeightContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLside(LSysDParser::LsideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLcontext(LSysDParser::LcontextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRcontext(LSysDParser::RcontextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRside(LSysDParser::RsideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWord(LSysDParser::WordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLChar(LSysDParser::LCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLItem(LSysDParser::LItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRItem(LSysDParser::RItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValidRightChar(LSysDParser::ValidRightCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValidChar(LSysDParser::ValidCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(LSysDParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(LSysDParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(LSysDParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(LSysDParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg(LSysDParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExpr(LSysDParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallExpr(LSysDParser::FunctionCallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdExpr(LSysDParser::IdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitBinaryExpr(LSysDParser::BitBinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAritUnaryExpr(LSysDParser::AritUnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedExpr(LSysDParser::ParenthesizedExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAritBinaryExpr(LSysDParser::AritBinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfElseExpr(LSysDParser::IfElseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(LSysDParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument(LSysDParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntConstant(LSysDParser::IntConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatConstant(LSysDParser::FloatConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringConstant(LSysDParser::StringConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrueValue(LSysDParser::TrueValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFalseValue(LSysDParser::FalseValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullValue(LSysDParser::NullValueContext *ctx) override {
    return visitChildren(ctx);
  }


};

