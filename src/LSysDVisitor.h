
#pragma once


class LSysDVisitor;

#include "LSysDParserBaseVisitor.h"
#include "LSysDParser.h"
#include "LSysDLexer.h"
#include "antlr4-runtime.h"
#include "LSystem.h"
#include "ErrorHandler.h"
#include "Table.h"
#include "values.h"

#include <string>
#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace lsysgen;

class LSysDVisitor: public LSysDParserBaseVisitor {
    Module<char> * module;

    LSystem<char> * currentLSystem;
    Scope * currentScope;
    Scope * baseScope;
    Table<char> * currentTable;
    ParseTreeNode<NodeContent, char> * parentNode;

    ErrorHandler * eh;

    template<class R> 
    R * defineRule(// LSysDParser::TagPrefixContext* tagCtx, 
                            LSysDParser::WeightContext * weightCtx, 
                            LSysDParser::LcontextContext * lctxCtx, 
                            LSysDParser::LsideContext * lsideCtx, 
                            LSysDParser::RcontextContext * rctxCtx, 
                            LSysDParser::CondContext * condCtx, 
                            LSysDParser::RsideContext * rsideCtx);

public:
    LSysDVisitor(std::string const& filename, std::vector<std::string> const* sourceLines, Scope * scope=nullptr, StackTrace const* trace=nullptr);

    ~LSysDVisitor();

    // ParseTreeNode<InstanceNodeContent, char>* parseInstanceNode(std::string s);

    ErrorHandler* messages();
    
    antlrcpp::Any visitMain(LSysDParser::MainContext *ctx) override;
    
    antlrcpp::Any visitLsystem(LSysDParser::LsystemContext *ctx) override;

    antlrcpp::Any visitAxiomDef(LSysDParser::AxiomDefContext *ctx) override;

    antlrcpp::Any visitConstDeclaration(LSysDParser::ConstDeclarationContext *ctx) override;

    antlrcpp::Any visitVarDeclaration(LSysDParser::VarDeclarationContext *ctx) override;

    antlrcpp::Any visitFuncDef(LSysDParser::FuncDefContext *ctx) override;

    antlrcpp::Any visitTableBlock(LSysDParser::TableBlockContext *ctx) override;

    antlrcpp::Any visitRulesBlock(LSysDParser::RulesBlockContext *ctx) override;

    antlrcpp::Any visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) override;

    antlrcpp::Any visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) override;

    antlrcpp::Any visitProductionRule(LSysDParser::ProductionRuleContext *ctx) override;

    antlrcpp::Any visitCodingRule(LSysDParser::CodingRuleContext *ctx) override;

    antlrcpp::Any visitRuleDef(LSysDParser::RuleDefContext *ctx) override;

    antlrcpp::Any visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) override;

    antlrcpp::Any visitCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) override;

    antlrcpp::Any visitTagPrefix(LSysDParser::TagPrefixContext *ctx) override;

    antlrcpp::Any visitTag(LSysDParser::TagContext *ctx) override;

    antlrcpp::Any visitWeight(LSysDParser::WeightContext *ctx) override;

    antlrcpp::Any visitLside(LSysDParser::LsideContext *ctx) override;

    antlrcpp::Any visitLcontext(LSysDParser::LcontextContext *ctx) override;

    antlrcpp::Any visitRcontext(LSysDParser::RcontextContext *ctx) override;

    antlrcpp::Any visitRside(LSysDParser::RsideContext *ctx) override;

    antlrcpp::Any visitWord(LSysDParser::WordContext *ctx) override;

    antlrcpp::Any visitLChar(LSysDParser::LCharContext *ctx) override;

    antlrcpp::Any visitLItem(LSysDParser::LItemContext *ctx) override;

    antlrcpp::Any visitRItem(LSysDParser::RItemContext *ctx) override;

    antlrcpp::Any visitValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) override;

    antlrcpp::Any visitValidRightChar(LSysDParser::ValidRightCharContext *ctx) override;

    antlrcpp::Any visitValidChar(LSysDParser::ValidCharContext *ctx) override;

    antlrcpp::Any visitParams(LSysDParser::ParamsContext *ctx) override;

    antlrcpp::Any visitParam(LSysDParser::ParamContext *ctx) override;

    antlrcpp::Any visitCond(LSysDParser::CondContext *ctx) override;

    antlrcpp::Any visitArgs(LSysDParser::ArgsContext *ctx) override;

    antlrcpp::Any visitArg(LSysDParser::ArgContext *ctx) override;
};
