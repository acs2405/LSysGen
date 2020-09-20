
#pragma once


#include "LSysDParserBaseVisitor.h"
#include "LSysDParser.h"
#include "LSysDLexer.h"
#include "antlr4-runtime.h"
#include "LSystem.h"
#include "ErrorHandler.h"

#include <string>
#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace lsysgen;

class LSysDVisitor: public LSysDParserBaseVisitor {
    Environment* env;
    ParseTreeNode<InstanceNodeContent, char>* axiom;
    std::map<std::string, Rule<char>*>* taggedRules;
    Table<char>* codingRules;
    Table<char>* defaultTable;
    std::map<std::string, Table<char>*>* tables;
    std::list<Table<char>*>* tablesList;

    Table<char>* currentTable;
    ParseTreeNode<NodeContent, char>* parentNode;

    std::vector<std::string>* sourceLines;
    std::string filename;
    StackTrace* parentTrace;
    ErrorHandler eh;

    // Environment* getEnvironment();
    // Value eval(LSysDParser::ExpressionContext* ctx);
    void error(std::string const& msg, StackTrace* st=nullptr);
    void error(std::string const& msg, antlr4::ParserRuleContext* ctx);
    void error(std::string const& msg, antlr4::tree::TerminalNode* terminal);
    StackTrace* trace(antlr4::Token* tokInit, antlr4::Token* tokEnd=nullptr, StackTrace* parent=nullptr);
    StackTrace* trace(antlr4::ParserRuleContext* token, StackTrace* parent=nullptr);

    template<class R> R* defineRule(LSysDParser::TagPrefixContext* tagCtx, 
                            LSysDParser::WeightContext* weightCtx, 
                            LSysDParser::LcontextContext* lctxCtx, 
                            LSysDParser::LsideContext* lsideCtx, 
                            LSysDParser::RcontextContext* rctxCtx, 
                            LSysDParser::RsideContext* rsideCtx);
public:
    LSysDVisitor(std::string filename, std::vector<std::string>* sourceLines, Environment* env=nullptr);

    ~LSysDVisitor();

    ParseTreeNode<InstanceNodeContent, char>* parseInstanceNode(std::string s);

    const std::list<Error*>* errors() const;

    void dumpErrors() const;
    
    antlrcpp::Any visitMain(LSysDParser::MainContext *ctx) override;

    // antlrcpp::Any visitSep(LSysDParser::SepContext *ctx) override;

    // antlrcpp::Any visitNl(LSysDParser::NlContext *ctx) override;

    antlrcpp::Any visitName(LSysDParser::NameContext *ctx) override;

    antlrcpp::Any visitDefinitions(LSysDParser::DefinitionsContext *ctx) override;

    antlrcpp::Any visitDefinition(LSysDParser::DefinitionContext *ctx) override;

    antlrcpp::Any visitAxiomDef(LSysDParser::AxiomDefContext *ctx) override;

    antlrcpp::Any visitPropDef(LSysDParser::PropDefContext *ctx) override;

    antlrcpp::Any visitFuncDef(LSysDParser::FuncDefContext *ctx) override;

    // antlrcpp::Any visitConstDef(LSysDParser::ConstDefContext *ctx) override;

    antlrcpp::Any visitTableBlock(LSysDParser::TableBlockContext *ctx) override;

    antlrcpp::Any visitRulesBlock(LSysDParser::RulesBlockContext *ctx) override;

    antlrcpp::Any visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) override;

    antlrcpp::Any visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) override;

    antlrcpp::Any visitRules(LSysDParser::RulesContext *ctx) override;

    antlrcpp::Any visitRuleDefs(LSysDParser::RuleDefsContext *ctx) override;

    antlrcpp::Any visitProductionRuleDefs(LSysDParser::ProductionRuleDefsContext *ctx) override;

    antlrcpp::Any visitCodingRuleDefs(LSysDParser::CodingRuleDefsContext *ctx) override;

    antlrcpp::Any visitAnyRule(LSysDParser::AnyRuleContext *ctx) override;

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

    antlrcpp::Any visitParamsWithCond(LSysDParser::ParamsWithCondContext *ctx) override;

    antlrcpp::Any visitParams(LSysDParser::ParamsContext *ctx) override;

    antlrcpp::Any visitParam(LSysDParser::ParamContext *ctx) override;

    antlrcpp::Any visitCond(LSysDParser::CondContext *ctx) override;

    antlrcpp::Any visitArgs(LSysDParser::ArgsContext *ctx) override;

    antlrcpp::Any visitArg(LSysDParser::ArgContext *ctx) override;
};
