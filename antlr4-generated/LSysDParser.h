
// Generated from LSysDParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  LSysDParser : public antlr4::Parser {
public:
  enum {
    EOL = 1, ACCESSOR = 2, ID = 3, INT = 4, FLOAT = 5, STRING = 6, LPAREN = 7, 
    RPAREN = 8, LBRACE = 9, RBRACE = 10, LBRACK = 11, RBRACK = 12, COLON = 13, 
    SEMI = 14, COMMA = 15, DOT = 16, ARROW = 17, ASSIGN = 18, LT = 19, GT = 20, 
    LE = 21, GE = 22, EQ = 23, NE = 24, ADD = 25, SUB = 26, MUL = 27, DIV = 28, 
    MOD = 29, POW = 30, BITAND = 31, BITOR = 32, BITXOR = 33, BITNOT = 34, 
    AND = 35, OR = 36, NOT = 37, KWAS = 38, KWELSE = 39, KWEVENTSPEC = 40, 
    KWFALSE = 41, KWFOR = 42, KWFROM = 43, KWIF = 44, KWIMPORT = 45, KWIN = 46, 
    KWNONE = 47, KWTRUE = 48, KWAND = 49, KWAXIOM = 50, KWCODING = 51, KWDO = 52, 
    KWFUNCTION = 53, KWLSYS = 54, KWMAIN = 55, KWNOT = 56, KWNULL = 57, 
    KWOR = 58, KWPRODUCTION = 59, KWRETURN = 60, KWRULES = 61, KWSET = 62, 
    KWTABLE = 63, KWTHEN = 64, KWVAR = 65, KWWHILE = 66, QM = 67, XM = 68, 
    DARROW = 69, FDIV = 70, DOLLARID = 71, RULECHAR = 72, WS = 73, COMMENTBLQ = 74, 
    COMMENTLIN = 75, LINE_JOINING = 76, NEW_LINE = 77, ERRORCHAR = 78
  };

  enum {
    RuleMain = 0, RuleModule = 1, RuleGlobalDefs = 2, RuleGlobalDef = 3, 
    RuleDeclaration = 4, RuleVarDeclaration = 5, RuleConstDeclaration = 6, 
    RuleLsystem = 7, RuleSep = 8, RuleNl = 9, RuleInLsysDefs = 10, RuleInLsysDef = 11, 
    RuleBlockOrOneStatement = 12, RuleBlock = 13, RuleOneStatement = 14, 
    RuleOneStmtNeedsSep = 15, RuleOneStmtEndsInBlock = 16, RuleStatement = 17, 
    RuleAssignment = 18, RuleAxiomDef = 19, RulePropDef = 20, RuleFuncDef = 21, 
    RuleConstDef = 22, RuleTableBlock = 23, RuleRulesBlock = 24, RuleProductionRulesBlock = 25, 
    RuleCodingRulesBlock = 26, RuleRules = 27, RuleRuleDefs = 28, RuleProductionRuleDefs = 29, 
    RuleCodingRuleDefs = 30, RuleAnyRule = 31, RuleProductionRule = 32, 
    RuleCodingRule = 33, RuleRuleDef = 34, RuleProductionRuleDef = 35, RuleCodingRuleDef = 36, 
    RuleTagPrefix = 37, RuleTag = 38, RuleWeight = 39, RuleLside = 40, RuleLcontext = 41, 
    RuleRcontext = 42, RuleRside = 43, RuleWord = 44, RuleLChar = 45, RuleLItem = 46, 
    RuleRItem = 47, RuleValidLeftChar = 48, RuleValidRightChar = 49, RuleValidChar = 50, 
    RuleParams = 51, RuleParam = 52, RuleCond = 53, RuleArgs = 54, RuleArg = 55, 
    RuleExpression = 56, RuleArguments = 57, RuleArgument = 58, RuleConstant = 59
  };

  LSysDParser(antlr4::TokenStream *input);
  ~LSysDParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class MainContext;
  class ModuleContext;
  class GlobalDefsContext;
  class GlobalDefContext;
  class DeclarationContext;
  class VarDeclarationContext;
  class ConstDeclarationContext;
  class LsystemContext;
  class SepContext;
  class NlContext;
  class InLsysDefsContext;
  class InLsysDefContext;
  class BlockOrOneStatementContext;
  class BlockContext;
  class OneStatementContext;
  class OneStmtNeedsSepContext;
  class OneStmtEndsInBlockContext;
  class StatementContext;
  class AssignmentContext;
  class AxiomDefContext;
  class PropDefContext;
  class FuncDefContext;
  class ConstDefContext;
  class TableBlockContext;
  class RulesBlockContext;
  class ProductionRulesBlockContext;
  class CodingRulesBlockContext;
  class RulesContext;
  class RuleDefsContext;
  class ProductionRuleDefsContext;
  class CodingRuleDefsContext;
  class AnyRuleContext;
  class ProductionRuleContext;
  class CodingRuleContext;
  class RuleDefContext;
  class ProductionRuleDefContext;
  class CodingRuleDefContext;
  class TagPrefixContext;
  class TagContext;
  class WeightContext;
  class LsideContext;
  class LcontextContext;
  class RcontextContext;
  class RsideContext;
  class WordContext;
  class LCharContext;
  class LItemContext;
  class RItemContext;
  class ValidLeftCharContext;
  class ValidRightCharContext;
  class ValidCharContext;
  class ParamsContext;
  class ParamContext;
  class CondContext;
  class ArgsContext;
  class ArgContext;
  class ExpressionContext;
  class ArgumentsContext;
  class ArgumentContext;
  class ConstantContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ModuleContext *module();
    antlr4::tree::TerminalNode *EOF();
    InLsysDefsContext *inLsysDefs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

  class  ModuleContext : public antlr4::ParserRuleContext {
  public:
    ModuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlobalDefsContext *globalDefs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleContext* module();

  class  GlobalDefsContext : public antlr4::ParserRuleContext {
  public:
    GlobalDefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);
    std::vector<GlobalDefContext *> globalDef();
    GlobalDefContext* globalDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalDefsContext* globalDefs();

  class  GlobalDefContext : public antlr4::ParserRuleContext {
  public:
    GlobalDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LsystemContext *lsystem();
    DeclarationContext *declaration();
    FuncDefContext *funcDef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalDefContext* globalDef();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDeclarationContext *varDeclaration();
    ConstDeclarationContext *constDeclaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  VarDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWVAR();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclarationContext* varDeclaration();

  class  ConstDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWSET();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclarationContext* constDeclaration();

  class  LsystemContext : public antlr4::ParserRuleContext {
  public:
    LsystemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWLSYS();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LBRACE();
    InLsysDefsContext *inLsysDefs();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *KWMAIN();
    NlContext *nl();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LsystemContext* lsystem();

  class  SepContext : public antlr4::ParserRuleContext {
  public:
    SepContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEW_LINE();
    antlr4::tree::TerminalNode* NEW_LINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SepContext* sep();

  class  NlContext : public antlr4::ParserRuleContext {
  public:
    NlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NEW_LINE();
    antlr4::tree::TerminalNode* NEW_LINE(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NlContext* nl();

  class  InLsysDefsContext : public antlr4::ParserRuleContext {
  public:
    InLsysDefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);
    std::vector<InLsysDefContext *> inLsysDef();
    InLsysDefContext* inLsysDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InLsysDefsContext* inLsysDefs();

  class  InLsysDefContext : public antlr4::ParserRuleContext {
  public:
    InLsysDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AxiomDefContext *axiomDef();
    StatementContext *statement();
    FuncDefContext *funcDef();
    TableBlockContext *tableBlock();
    RulesBlockContext *rulesBlock();
    ProductionRulesBlockContext *productionRulesBlock();
    CodingRulesBlockContext *codingRulesBlock();
    RuleDefContext *ruleDef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InLsysDefContext* inLsysDef();

  class  BlockOrOneStatementContext : public antlr4::ParserRuleContext {
  public:
    BlockOrOneStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    OneStatementContext *oneStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockOrOneStatementContext* blockOrOneStatement();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    StatementContext *statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  OneStatementContext : public antlr4::ParserRuleContext {
  public:
    OneStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OneStmtNeedsSepContext *oneStmtNeedsSep();
    OneStmtEndsInBlockContext *oneStmtEndsInBlock();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneStatementContext* oneStatement();

  class  OneStmtNeedsSepContext : public antlr4::ParserRuleContext {
  public:
    OneStmtNeedsSepContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    AssignmentContext *assignment();
    DeclarationContext *declaration();
    antlr4::tree::TerminalNode *KWRETURN();
    antlr4::tree::TerminalNode *KWIF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    OneStmtNeedsSepContext *oneStmtNeedsSep();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    BlockOrOneStatementContext *blockOrOneStatement();
    antlr4::tree::TerminalNode *KWELSE();
    antlr4::tree::TerminalNode *KWWHILE();
    antlr4::tree::TerminalNode *KWDO();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneStmtNeedsSepContext* oneStmtNeedsSep();

  class  OneStmtEndsInBlockContext : public antlr4::ParserRuleContext {
  public:
    OneStmtEndsInBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWIF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    BlockContext *block();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);
    BlockOrOneStatementContext *blockOrOneStatement();
    antlr4::tree::TerminalNode *KWELSE();
    antlr4::tree::TerminalNode *KWWHILE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OneStmtEndsInBlockContext* oneStmtEndsInBlock();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OneStatementContext *oneStatement();
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);
    std::vector<OneStmtNeedsSepContext *> oneStmtNeedsSep();
    OneStmtNeedsSepContext* oneStmtNeedsSep(size_t i);
    std::vector<OneStmtEndsInBlockContext *> oneStmtEndsInBlock();
    OneStmtEndsInBlockContext* oneStmtEndsInBlock(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  AxiomDefContext : public antlr4::ParserRuleContext {
  public:
    AxiomDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWAXIOM();
    WordContext *word();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AxiomDefContext* axiomDef();

  class  PropDefContext : public antlr4::ParserRuleContext {
  public:
    PropDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWSET();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropDefContext* propDef();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWFUNCTION();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDefContext* funcDef();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOLLARID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDefContext* constDef();

  class  TableBlockContext : public antlr4::ParserRuleContext {
  public:
    TableBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWTABLE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LBRACE();
    RulesContext *rules();
    antlr4::tree::TerminalNode *RBRACE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableBlockContext* tableBlock();

  class  RulesBlockContext : public antlr4::ParserRuleContext {
  public:
    RulesBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWRULES();
    antlr4::tree::TerminalNode *LBRACE();
    RuleDefsContext *ruleDefs();
    antlr4::tree::TerminalNode *RBRACE();
    NlContext *nl();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RulesBlockContext* rulesBlock();

  class  ProductionRulesBlockContext : public antlr4::ParserRuleContext {
  public:
    ProductionRulesBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWPRODUCTION();
    antlr4::tree::TerminalNode *KWRULES();
    antlr4::tree::TerminalNode *LBRACE();
    RuleDefsContext *ruleDefs();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductionRulesBlockContext* productionRulesBlock();

  class  CodingRulesBlockContext : public antlr4::ParserRuleContext {
  public:
    CodingRulesBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWCODING();
    antlr4::tree::TerminalNode *KWRULES();
    antlr4::tree::TerminalNode *LBRACE();
    RuleDefsContext *ruleDefs();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<NlContext *> nl();
    NlContext* nl(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodingRulesBlockContext* codingRulesBlock();

  class  RulesContext : public antlr4::ParserRuleContext {
  public:
    RulesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);
    std::vector<AnyRuleContext *> anyRule();
    AnyRuleContext* anyRule(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RulesContext* rules();

  class  RuleDefsContext : public antlr4::ParserRuleContext {
  public:
    RuleDefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);
    std::vector<RuleDefContext *> ruleDef();
    RuleDefContext* ruleDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleDefsContext* ruleDefs();

  class  ProductionRuleDefsContext : public antlr4::ParserRuleContext {
  public:
    ProductionRuleDefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);
    std::vector<ProductionRuleDefContext *> productionRuleDef();
    ProductionRuleDefContext* productionRuleDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductionRuleDefsContext* productionRuleDefs();

  class  CodingRuleDefsContext : public antlr4::ParserRuleContext {
  public:
    CodingRuleDefsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);
    std::vector<CodingRuleDefContext *> codingRuleDef();
    CodingRuleDefContext* codingRuleDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodingRuleDefsContext* codingRuleDefs();

  class  AnyRuleContext : public antlr4::ParserRuleContext {
  public:
    AnyRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProductionRuleContext *productionRule();
    CodingRuleContext *codingRule();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnyRuleContext* anyRule();

  class  ProductionRuleContext : public antlr4::ParserRuleContext {
  public:
    ProductionRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProductionRuleDefContext *productionRuleDef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductionRuleContext* productionRule();

  class  CodingRuleContext : public antlr4::ParserRuleContext {
  public:
    CodingRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CodingRuleDefContext *codingRuleDef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodingRuleContext* codingRule();

  class  RuleDefContext : public antlr4::ParserRuleContext {
  public:
    RuleDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProductionRuleDefContext *productionRuleDef();
    CodingRuleDefContext *codingRuleDef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleDefContext* ruleDef();

  class  ProductionRuleDefContext : public antlr4::ParserRuleContext {
  public:
    ProductionRuleDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LsideContext *lside();
    antlr4::tree::TerminalNode *ARROW();
    RsideContext *rside();
    WeightContext *weight();
    LcontextContext *lcontext();
    RcontextContext *rcontext();
    CondContext *cond();
    NlContext *nl();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductionRuleDefContext* productionRuleDef();

  class  CodingRuleDefContext : public antlr4::ParserRuleContext {
  public:
    CodingRuleDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LsideContext *lside();
    antlr4::tree::TerminalNode *DARROW();
    RsideContext *rside();
    WeightContext *weight();
    LcontextContext *lcontext();
    RcontextContext *rcontext();
    CondContext *cond();
    NlContext *nl();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodingRuleDefContext* codingRuleDef();

  class  TagPrefixContext : public antlr4::ParserRuleContext {
  public:
    TagPrefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TagContext *tag();
    antlr4::tree::TerminalNode *COLON();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TagPrefixContext* tagPrefix();

  class  TagContext : public antlr4::ParserRuleContext {
  public:
    TagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TagContext* tag();

  class  WeightContext : public antlr4::ParserRuleContext {
  public:
    WeightContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *XM();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WeightContext* weight();

  class  LsideContext : public antlr4::ParserRuleContext {
  public:
    LsideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LCharContext *lChar();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LsideContext* lside();

  class  LcontextContext : public antlr4::ParserRuleContext {
  public:
    LcontextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<LItemContext *> lItem();
    LItemContext* lItem(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LcontextContext* lcontext();

  class  RcontextContext : public antlr4::ParserRuleContext {
  public:
    RcontextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GT();
    std::vector<LItemContext *> lItem();
    LItemContext* lItem(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RcontextContext* rcontext();

  class  RsideContext : public antlr4::ParserRuleContext {
  public:
    RsideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RItemContext *> rItem();
    RItemContext* rItem(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RsideContext* rside();

  class  WordContext : public antlr4::ParserRuleContext {
  public:
    WordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RItemContext *> rItem();
    RItemContext* rItem(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WordContext* word();

  class  LCharContext : public antlr4::ParserRuleContext {
  public:
    LCharContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValidLeftCharContext *validLeftChar();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LCharContext* lChar();

  class  LItemContext : public antlr4::ParserRuleContext {
  public:
    LItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValidLeftCharContext *validLeftChar();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<LItemContext *> lItem();
    LItemContext* lItem(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LItemContext* lItem();

  class  RItemContext : public antlr4::ParserRuleContext {
  public:
    RItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValidRightCharContext *validRightChar();
    antlr4::tree::TerminalNode *LPAREN();
    ArgsContext *args();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();
    std::vector<RItemContext *> rItem();
    RItemContext* rItem(size_t i);
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RItemContext* rItem();

  class  ValidLeftCharContext : public antlr4::ParserRuleContext {
  public:
    ValidLeftCharContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValidCharContext *validChar();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValidLeftCharContext* validLeftChar();

  class  ValidRightCharContext : public antlr4::ParserRuleContext {
  public:
    ValidRightCharContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValidCharContext *validChar();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValidRightCharContext* validRightChar();

  class  ValidCharContext : public antlr4::ParserRuleContext {
  public:
    ValidCharContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *RULECHAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValidCharContext* validChar();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondContext* cond();

  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();

  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgContext* arg();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LogicBinaryExprContext : public ExpressionContext {
  public:
    LogicBinaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CmpBinaryExprContext : public ExpressionContext {
  public:
    CmpBinaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstExprContext : public ExpressionContext {
  public:
    ConstExprContext(ExpressionContext *ctx);

    ConstantContext *constant();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallExprContext : public ExpressionContext {
  public:
    FunctionCallExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LPAREN();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *RPAREN();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExprContext : public ExpressionContext {
  public:
    IdExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitBinaryExprContext : public ExpressionContext {
  public:
    BitBinaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *BITAND();
    antlr4::tree::TerminalNode *BITXOR();
    antlr4::tree::TerminalNode *BITOR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AritUnaryExprContext : public ExpressionContext {
  public:
    AritUnaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicUnaryExprContext : public ExpressionContext {
  public:
    LogicUnaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *BITNOT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedExprContext : public ExpressionContext {
  public:
    ParenthesizedExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AritBinaryExprContext : public ExpressionContext {
  public:
    AritBinaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfElseExprContext : public ExpressionContext {
  public:
    IfElseExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *KWIF();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *KWTHEN();
    antlr4::tree::TerminalNode *KWELSE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentContext* argument();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstantContext() = default;
    void copyFrom(ConstantContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NullValueContext : public ConstantContext {
  public:
    NullValueContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *KWNULL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueValueContext : public ConstantContext {
  public:
    TrueValueContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *KWTRUE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatConstantContext : public ConstantContext {
  public:
    FloatConstantContext(ConstantContext *ctx);

    antlr4::Token *v = nullptr;
    antlr4::tree::TerminalNode *FLOAT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntConstantContext : public ConstantContext {
  public:
    IntConstantContext(ConstantContext *ctx);

    antlr4::Token *v = nullptr;
    antlr4::tree::TerminalNode *INT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringConstantContext : public ConstantContext {
  public:
    StringConstantContext(ConstantContext *ctx);

    antlr4::Token *v = nullptr;
    antlr4::tree::TerminalNode *STRING();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseValueContext : public ConstantContext {
  public:
    FalseValueContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *KWFALSE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConstantContext* constant();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

