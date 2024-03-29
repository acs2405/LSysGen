
#pragma once


class LSysDVisitor;

#include "common.h"
#include "LSysDParserBaseVisitor.h"
#include "LSysDParser.h"
// #include "LSysDLexer.h"
#include "antlr4-runtime.h"
#include "LSystem.h"
#include "ErrorHandler.h"
#include "Table.h"
#include "values.h"
#include "Settings.h"


using namespace lsysgen;

class LSysDVisitor: public LSysDParserBaseVisitor {
    Module<char> * module;

    LSystem<char> * currentLSystem;
    std::list<LSystem<char> *> * selectedLSystems;
    Table<char> * currentTable;
    TreeNode<NodeContent, char> * parentNode;
    Scope * currentScope;
    Scope * baseScope;

    std::string const inputFile;
    Settings const settings;
    ErrorHandler * eh;

    template<class R> 
    R * defineRule(// LSysDParser::TagPrefixContext* tagCtx, 
                            LSysDParser::WeightContext * weightCtx, 
                            LSysDParser::LcontextContext * lctxCtx, 
                            LSysDParser::LsideContext * lsideCtx, 
                            LSysDParser::RcontextContext * rctxCtx, 
                            LSysDParser::CondContext * condCtx, 
                            LSysDParser::RsideContext * rsideCtx);

    void parseArgs();

    void setAxiom();
    void addRules();

    Module<char> * createModule() const;
    LSystem<char> * createLSystem(std::string const& name) const;

public:
    LSysDVisitor(std::string_view inputFile, Settings const& settings, Scope * scope=nullptr, StackTrace const* trace=nullptr);

    ~LSysDVisitor();

    // TreeNode<InstanceNodeContent, char>* parseInstanceNode(std::string s);

    ErrorHandler* messages();

    // LSystem<char> * createLSystem(std::string_view name);
    // void finishLSystem();
    // void setAxiom(lsysgen::TreeNode<lsysgen::InstanceNodeContent, char> * axiom);
    
    std::any visitMain(LSysDParser::MainContext *ctx) override;
    
    std::any visitMainWord(LSysDParser::MainWordContext *ctx) override;
    
    std::any visitGlobalDefs(LSysDParser::GlobalDefsContext *ctx) override;
    
    std::any visitLsystem(LSysDParser::LsystemContext *ctx) override;

    std::any visitAxiomDef(LSysDParser::AxiomDefContext *ctx) override;

    std::any visitConstDeclaration(LSysDParser::ConstDeclarationContext *ctx) override;

    std::any visitVarDeclaration(LSysDParser::VarDeclarationContext *ctx) override;

    std::any visitAssignment(LSysDParser::AssignmentContext *ctx) override;

    std::any visitFuncDef(LSysDParser::FuncDefContext *ctx) override;

    std::any visitTableBlock(LSysDParser::TableBlockContext *ctx) override;

    std::any visitRulesBlock(LSysDParser::RulesBlockContext *ctx) override;

    std::any visitProductionRulesBlock(LSysDParser::ProductionRulesBlockContext *ctx) override;

    std::any visitCodingRulesBlock(LSysDParser::CodingRulesBlockContext *ctx) override;

    std::any visitProductionRule(LSysDParser::ProductionRuleContext *ctx) override;

    std::any visitCodingRule(LSysDParser::CodingRuleContext *ctx) override;

    std::any visitRuleDef(LSysDParser::RuleDefContext *ctx) override;

    std::any visitProductionRuleDef(LSysDParser::ProductionRuleDefContext *ctx) override;

    std::any visitCodingRuleDef(LSysDParser::CodingRuleDefContext *ctx) override;

    std::any visitTagPrefix(LSysDParser::TagPrefixContext *ctx) override;

    std::any visitTag(LSysDParser::TagContext *ctx) override;

    std::any visitWeight(LSysDParser::WeightContext *ctx) override;

    std::any visitLside(LSysDParser::LsideContext *ctx) override;

    std::any visitLcontext(LSysDParser::LcontextContext *ctx) override;

    std::any visitRcontext(LSysDParser::RcontextContext *ctx) override;

    std::any visitRside(LSysDParser::RsideContext *ctx) override;

    std::any visitWord(LSysDParser::WordContext *ctx) override;

    std::any visitLChar(LSysDParser::LCharContext *ctx) override;

    std::any visitLItem(LSysDParser::LItemContext *ctx) override;

    std::any visitRItem(LSysDParser::RItemContext *ctx) override;

    std::any visitValidLeftChar(LSysDParser::ValidLeftCharContext *ctx) override;

    std::any visitValidRightChar(LSysDParser::ValidRightCharContext *ctx) override;

    std::any visitValidChar(LSysDParser::ValidCharContext *ctx) override;

    std::any visitParams(LSysDParser::ParamsContext *ctx) override;

    std::any visitParam(LSysDParser::ParamContext *ctx) override;

    std::any visitCond(LSysDParser::CondContext *ctx) override;

    std::any visitArgs(LSysDParser::ArgsContext *ctx) override;

    std::any visitArg(LSysDParser::ArgContext *ctx) override;
};
