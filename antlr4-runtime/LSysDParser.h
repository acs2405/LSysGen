
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
    KWNONE = 47, KWTRUE = 48, KWAND = 49, KWCODING = 50, KWLAMBDA = 51, 
    KWLSYS = 52, KWNOT = 53, KWOR = 54, KWPRODUCTION = 55, KWRULES = 56, 
    KWSET = 57, KWTABLE = 58, KWTHEN = 59, QM = 60, XM = 61, DARROW = 62, 
    FDIV = 63, DOLLARID = 64, RULECHAR = 65, WS = 66, COMMENTBLQ = 67, COMMENTLIN = 68, 
    LINE_JOINING = 69, NEW_LINE = 70, ERRORCHAR = 71
  };

  enum {
    RuleMain = 0, RuleSep = 1, RuleNl = 2, RuleName = 3, RuleDefinitions = 4, 
    RuleDefinition = 5, RulePropDef = 6, RuleFuncDef = 7, RuleConstDef = 8, 
    RuleTableBlock = 9, RuleRulesBlock = 10, RuleProductionRulesBlock = 11, 
    RuleCodingRulesBlock = 12, RuleRules = 13, RuleRuleDefs = 14, RuleProductionRuleDefs = 15, 
    RuleCodingRuleDefs = 16, RuleAnyRule = 17, RuleProductionRule = 18, 
    RuleCodingRule = 19, RuleRuleDef = 20, RuleProductionRuleDef = 21, RuleCodingRuleDef = 22, 
    RuleTagPrefix = 23, RuleTag = 24, RuleWeight = 25, RuleLside = 26, RuleLcontext = 27, 
    RuleRcontext = 28, RuleRside = 29, RuleWord = 30, RuleLChar = 31, RuleLItem = 32, 
    RuleRItem = 33, RuleValidLeftChar = 34, RuleValidRightChar = 35, RuleValidChar = 36, 
    RuleParamsWithCond = 37, RuleParams = 38, RuleParam = 39, RuleCond = 40, 
    RuleArgs = 41, RuleArg = 42, RuleExpression = 43, RuleArguments = 44, 
    RuleArgument = 45, RuleConstant = 46
  };

  LSysDParser(antlr4::TokenStream *input);
  ~LSysDParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class MainContext;
  class SepContext;
  class NlContext;
  class NameContext;
  class DefinitionsContext;
  class DefinitionContext;
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
  class ParamsWithCondContext;
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
    antlr4::tree::TerminalNode *EOF();
    DefinitionsContext *definitions();
    NameContext *name();
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

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

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KWLSYS();
    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  DefinitionsContext : public antlr4::ParserRuleContext {
  public:
    DefinitionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DefinitionContext *> definition();
    DefinitionContext* definition(size_t i);
    std::vector<SepContext *> sep();
    SepContext* sep(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionsContext* definitions();

  class  DefinitionContext : public antlr4::ParserRuleContext {
  public:
    DefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropDefContext *propDef();
    FuncDefContext *funcDef();
    TableBlockContext *tableBlock();
    RulesBlockContext *rulesBlock();
    ProductionRulesBlockContext *productionRulesBlock();
    CodingRulesBlockContext *codingRulesBlock();
    RuleDefContext *ruleDef();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefinitionContext* definition();

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
    antlr4::tree::TerminalNode *KWSET();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    ParamsContext *params();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

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
    ProductionRuleDefsContext *productionRuleDefs();
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
    CodingRuleDefsContext *codingRuleDefs();
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
    TagContext *tag();

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
    TagPrefixContext *tagPrefix();
    WeightContext *weight();
    LcontextContext *lcontext();
    RcontextContext *rcontext();
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
    TagPrefixContext *tagPrefix();
    WeightContext *weight();
    LcontextContext *lcontext();
    RcontextContext *rcontext();
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
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *RPAREN();
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
    ParamsWithCondContext *paramsWithCond();
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
    ParamsWithCondContext *paramsWithCond();
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

  class  ParamsWithCondContext : public antlr4::ParserRuleContext {
  public:
    ParamsWithCondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamsContext *params();
    antlr4::tree::TerminalNode *BITOR();
    CondContext *cond();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsWithCondContext* paramsWithCond();

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

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CmpBinaryExprContext : public ExpressionContext {
  public:
    CmpBinaryExprContext(ExpressionContext *ctx);

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

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicUnaryExprContext : public ExpressionContext {
  public:
    LogicUnaryExprContext(ExpressionContext *ctx);

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

