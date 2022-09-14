
// Generated from LSysDParser.g4 by ANTLR 4.11.1

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
    virtual std::any visitMain(LSysDParser::MainContext *context) = 0;

    virtual std::any visitMainWord(LSysDParser::MainWordContext *context) = 0;

    virtual std::any visitMainRuleDefs(LSysDParser::MainRuleDefsContext *context) = 0;

    virtual std::any visitModule(LSysDParser::ModuleContext *context) = 0;

    virtual std::any visitGlobalDefs(LSysDParser::GlobalDefsContext *context) = 0;

    virtual std::any visitGlobalDef(LSysDParser::GlobalDefContext *context) = 0;

    virtual std::any visitDeclaration(LSysDParser::DeclarationContext *context) = 0;

    virtual std::any visitVarDeclaration(LSysDParser::VarDeclarationContext *context) = 0;

    virtual std::any visitConstDeclaration(LSysDParser::ConstDeclarationContext *context) = 0;

    virtual std::any visitLsystem(LSysDParser::LsystemContext *context) = 0;

    virtual std::any visitSep(LSysDParser::SepContext *context) = 0;

    virtual std::any visitNl(LSysDParser::NlContext *context) = 0;

    virtual std::any visitInLsysDefs(LSysDParser::InLsysDefsContext *context) = 0;

    virtual std::any visitInLsysDef(LSysDParser::InLsysDefContext *context) = 0;

    virtual std::any visitBlockOrOneStatement(LSysDParser::BlockOrOneStatementContext *context) = 0;

    virtual std::any visitBlock(LSysDParser::BlockContext *context) = 0;

    virtual std::any visitOneStatement(LSysDParser::OneStatementContext *context) = 0;

    virtual std::any visitOneStmtNeedsSep(LSysDParser::OneStmtNeedsSepContext *context) = 0;

    virtual std::any visitOneStmtEndsInBlock(LSysDParser::OneStmtEndsInBlockContext *context) = 0;

    virtual std::any visitStatement(LSysDParser::StatementContext *context) = 0;

    virtual std::any visitAssignment(LSysDParser::AssignmentContext *context) = 0;

    virtual std::any visitAxiomDef(LSysDParser::AxiomDefContext *context) = 0;

    virtual std::any visitPropDef(LSysDParser::PropDefContext *context) = 0;

    virtual std::any visitFuncDef(LSysDParser::FuncDefContext *context) = 0;

    virtual std::any visitConstDef(LSysDParser::ConstDefContext *context) = 0;

    virtual std::any visitTableBlock(LSysDParser::TableBlockContext *context) = 0;

    virtual std::any visitRulesBlock(LSysDParser::RulesBlockContext *context) = 0;

    virtual std::any visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *context) = 0;

    virtual std::any visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *context) = 0;

    virtual std::any visitRules(LSysDParser::RulesContext *context) = 0;

    virtual std::any visitRuleDefs(LSysDParser::RuleDefsContext *context) = 0;

    virtual std::any visitProductionRuleDefs(LSysDParser::ProductionRuleDefsContext *context) = 0;

    virtual std::any visitCodingRuleDefs(LSysDParser::CodingRuleDefsContext *context) = 0;

    virtual std::any visitAnyRule(LSysDParser::AnyRuleContext *context) = 0;

    virtual std::any visitProductionRule(LSysDParser::ProductionRuleContext *context) = 0;

    virtual std::any visitCodingRule(LSysDParser::CodingRuleContext *context) = 0;

    virtual std::any visitRuleDef(LSysDParser::RuleDefContext *context) = 0;

    virtual std::any visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *context) = 0;

    virtual std::any visitCodingRuleDef(LSysDParser::CodingRuleDefContext *context) = 0;

    virtual std::any visitTagPrefix(LSysDParser::TagPrefixContext *context) = 0;

    virtual std::any visitTag(LSysDParser::TagContext *context) = 0;

    virtual std::any visitWeight(LSysDParser::WeightContext *context) = 0;

    virtual std::any visitLside(LSysDParser::LsideContext *context) = 0;

    virtual std::any visitLcontext(LSysDParser::LcontextContext *context) = 0;

    virtual std::any visitRcontext(LSysDParser::RcontextContext *context) = 0;

    virtual std::any visitRside(LSysDParser::RsideContext *context) = 0;

    virtual std::any visitWord(LSysDParser::WordContext *context) = 0;

    virtual std::any visitLChar(LSysDParser::LCharContext *context) = 0;

    virtual std::any visitLItem(LSysDParser::LItemContext *context) = 0;

    virtual std::any visitRItem(LSysDParser::RItemContext *context) = 0;

    virtual std::any visitValidLeftChar(LSysDParser::ValidLeftCharContext *context) = 0;

    virtual std::any visitValidRightChar(LSysDParser::ValidRightCharContext *context) = 0;

    virtual std::any visitValidChar(LSysDParser::ValidCharContext *context) = 0;

    virtual std::any visitParams(LSysDParser::ParamsContext *context) = 0;

    virtual std::any visitParam(LSysDParser::ParamContext *context) = 0;

    virtual std::any visitCond(LSysDParser::CondContext *context) = 0;

    virtual std::any visitArgs(LSysDParser::ArgsContext *context) = 0;

    virtual std::any visitArg(LSysDParser::ArgContext *context) = 0;

    virtual std::any visitLogicBinaryExpr(LSysDParser::LogicBinaryExprContext *context) = 0;

    virtual std::any visitCmpBinaryExpr(LSysDParser::CmpBinaryExprContext *context) = 0;

    virtual std::any visitConstExpr(LSysDParser::ConstExprContext *context) = 0;

    virtual std::any visitFunctionCallExpr(LSysDParser::FunctionCallExprContext *context) = 0;

    virtual std::any visitIdExpr(LSysDParser::IdExprContext *context) = 0;

    virtual std::any visitBitBinaryExpr(LSysDParser::BitBinaryExprContext *context) = 0;

    virtual std::any visitAritUnaryExpr(LSysDParser::AritUnaryExprContext *context) = 0;

    virtual std::any visitLogicUnaryExpr(LSysDParser::LogicUnaryExprContext *context) = 0;

    virtual std::any visitParenthesizedExpr(LSysDParser::ParenthesizedExprContext *context) = 0;

    virtual std::any visitAritBinaryExpr(LSysDParser::AritBinaryExprContext *context) = 0;

    virtual std::any visitIfElseExpr(LSysDParser::IfElseExprContext *context) = 0;

    virtual std::any visitArguments(LSysDParser::ArgumentsContext *context) = 0;

    virtual std::any visitArgument(LSysDParser::ArgumentContext *context) = 0;

    virtual std::any visitIntConstant(LSysDParser::IntConstantContext *context) = 0;

    virtual std::any visitFloatConstant(LSysDParser::FloatConstantContext *context) = 0;

    virtual std::any visitStringConstant(LSysDParser::StringConstantContext *context) = 0;

    virtual std::any visitTrueValue(LSysDParser::TrueValueContext *context) = 0;

    virtual std::any visitFalseValue(LSysDParser::FalseValueContext *context) = 0;

    virtual std::any visitNullValue(LSysDParser::NullValueContext *context) = 0;


};

