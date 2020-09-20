
// Generated from LSysDParser.g4 by ANTLR 4.7.2


#include "LSysDParserVisitor.h"

#include "LSysDParser.h"


using namespace antlrcpp;
using namespace antlr4;

LSysDParser::LSysDParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LSysDParser::~LSysDParser() {
  delete _interpreter;
}

std::string LSysDParser::getGrammarFileName() const {
  return "LSysDParser.g4";
}

const std::vector<std::string>& LSysDParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LSysDParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainContext ------------------------------------------------------------------

LSysDParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::MainContext::EOF() {
  return getToken(LSysDParser::EOF, 0);
}

std::vector<LSysDParser::SepContext *> LSysDParser::MainContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::MainContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

LSysDParser::NameContext* LSysDParser::MainContext::name() {
  return getRuleContext<LSysDParser::NameContext>(0);
}

tree::TerminalNode* LSysDParser::MainContext::LBRACE() {
  return getToken(LSysDParser::LBRACE, 0);
}

LSysDParser::DefinitionsContext* LSysDParser::MainContext::definitions() {
  return getRuleContext<LSysDParser::DefinitionsContext>(0);
}

tree::TerminalNode* LSysDParser::MainContext::RBRACE() {
  return getToken(LSysDParser::RBRACE, 0);
}

std::vector<LSysDParser::NlContext *> LSysDParser::MainContext::nl() {
  return getRuleContexts<LSysDParser::NlContext>();
}

LSysDParser::NlContext* LSysDParser::MainContext::nl(size_t i) {
  return getRuleContext<LSysDParser::NlContext>(i);
}

LSysDParser::WordContext* LSysDParser::MainContext::word() {
  return getRuleContext<LSysDParser::WordContext>(0);
}


size_t LSysDParser::MainContext::getRuleIndex() const {
  return LSysDParser::RuleMain;
}

antlrcpp::Any LSysDParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::MainContext* LSysDParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, LSysDParser::RuleMain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::SEMI

      || _la == LSysDParser::NEW_LINE) {
        setState(96);
        sep();
      }

      setState(115);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::KWLSYS) {
        setState(99);
        name();
        setState(101);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::NEW_LINE) {
          setState(100);
          nl();
        }
        setState(103);
        match(LSysDParser::LBRACE);
        setState(105);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          setState(104);
          sep();
          break;
        }

        }
        setState(107);
        definitions();
        setState(109);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::SEMI

        || _la == LSysDParser::NEW_LINE) {
          setState(108);
          sep();
        }
        setState(111);
        match(LSysDParser::RBRACE);
        setState(113);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::SEMI

        || _la == LSysDParser::NEW_LINE) {
          setState(112);
          sep();
        }
      }
      setState(117);
      match(LSysDParser::EOF);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(119);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(118);
        sep();
        break;
      }

      }

      setState(121);
      definitions();
      setState(123);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::SEMI

      || _la == LSysDParser::NEW_LINE) {
        setState(122);
        sep();
      }
      setState(125);
      match(LSysDParser::EOF);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(128);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(127);
        nl();
        break;
      }

      }
      setState(130);
      word();
      setState(132);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(131);
        nl();
      }
      setState(134);
      match(LSysDParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SepContext ------------------------------------------------------------------

LSysDParser::SepContext::SepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LSysDParser::SepContext::SEMI() {
  return getTokens(LSysDParser::SEMI);
}

tree::TerminalNode* LSysDParser::SepContext::SEMI(size_t i) {
  return getToken(LSysDParser::SEMI, i);
}

std::vector<tree::TerminalNode *> LSysDParser::SepContext::NEW_LINE() {
  return getTokens(LSysDParser::NEW_LINE);
}

tree::TerminalNode* LSysDParser::SepContext::NEW_LINE(size_t i) {
  return getToken(LSysDParser::NEW_LINE, i);
}


size_t LSysDParser::SepContext::getRuleIndex() const {
  return LSysDParser::RuleSep;
}

antlrcpp::Any LSysDParser::SepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitSep(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::SepContext* LSysDParser::sep() {
  SepContext *_localctx = _tracker.createInstance<SepContext>(_ctx, getState());
  enterRule(_localctx, 2, LSysDParser::RuleSep);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(139); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(138);
              _la = _input->LA(1);
              if (!(_la == LSysDParser::SEMI

              || _la == LSysDParser::NEW_LINE)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(141); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NlContext ------------------------------------------------------------------

LSysDParser::NlContext::NlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LSysDParser::NlContext::NEW_LINE() {
  return getTokens(LSysDParser::NEW_LINE);
}

tree::TerminalNode* LSysDParser::NlContext::NEW_LINE(size_t i) {
  return getToken(LSysDParser::NEW_LINE, i);
}


size_t LSysDParser::NlContext::getRuleIndex() const {
  return LSysDParser::RuleNl;
}

antlrcpp::Any LSysDParser::NlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitNl(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::NlContext* LSysDParser::nl() {
  NlContext *_localctx = _tracker.createInstance<NlContext>(_ctx, getState());
  enterRule(_localctx, 4, LSysDParser::RuleNl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(144); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(143);
              match(LSysDParser::NEW_LINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(146); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

LSysDParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::NameContext::KWLSYS() {
  return getToken(LSysDParser::KWLSYS, 0);
}

tree::TerminalNode* LSysDParser::NameContext::ID() {
  return getToken(LSysDParser::ID, 0);
}


size_t LSysDParser::NameContext::getRuleIndex() const {
  return LSysDParser::RuleName;
}

antlrcpp::Any LSysDParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::NameContext* LSysDParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 6, LSysDParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(LSysDParser::KWLSYS);
    setState(149);
    match(LSysDParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionsContext ------------------------------------------------------------------

LSysDParser::DefinitionsContext::DefinitionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::DefinitionContext *> LSysDParser::DefinitionsContext::definition() {
  return getRuleContexts<LSysDParser::DefinitionContext>();
}

LSysDParser::DefinitionContext* LSysDParser::DefinitionsContext::definition(size_t i) {
  return getRuleContext<LSysDParser::DefinitionContext>(i);
}

std::vector<LSysDParser::SepContext *> LSysDParser::DefinitionsContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::DefinitionsContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}


size_t LSysDParser::DefinitionsContext::getRuleIndex() const {
  return LSysDParser::RuleDefinitions;
}

antlrcpp::Any LSysDParser::DefinitionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitDefinitions(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::DefinitionsContext* LSysDParser::definitions() {
  DefinitionsContext *_localctx = _tracker.createInstance<DefinitionsContext>(_ctx, getState());
  enterRule(_localctx, 8, LSysDParser::RuleDefinitions);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(151);
        definition();
        setState(152);
        sep(); 
      }
      setState(158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(160);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LPAREN - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::LT - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::KWAXIOM - 3))
      | (1ULL << (LSysDParser::KWCODING - 3))
      | (1ULL << (LSysDParser::KWPRODUCTION - 3))
      | (1ULL << (LSysDParser::KWRULES - 3))
      | (1ULL << (LSysDParser::KWSET - 3))
      | (1ULL << (LSysDParser::KWTABLE - 3))
      | (1ULL << (LSysDParser::XM - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(159);
      definition();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionContext ------------------------------------------------------------------

LSysDParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::AxiomDefContext* LSysDParser::DefinitionContext::axiomDef() {
  return getRuleContext<LSysDParser::AxiomDefContext>(0);
}

LSysDParser::PropDefContext* LSysDParser::DefinitionContext::propDef() {
  return getRuleContext<LSysDParser::PropDefContext>(0);
}

LSysDParser::FuncDefContext* LSysDParser::DefinitionContext::funcDef() {
  return getRuleContext<LSysDParser::FuncDefContext>(0);
}

LSysDParser::TableBlockContext* LSysDParser::DefinitionContext::tableBlock() {
  return getRuleContext<LSysDParser::TableBlockContext>(0);
}

LSysDParser::RulesBlockContext* LSysDParser::DefinitionContext::rulesBlock() {
  return getRuleContext<LSysDParser::RulesBlockContext>(0);
}

LSysDParser::ProductionRulesBlockContext* LSysDParser::DefinitionContext::productionRulesBlock() {
  return getRuleContext<LSysDParser::ProductionRulesBlockContext>(0);
}

LSysDParser::CodingRulesBlockContext* LSysDParser::DefinitionContext::codingRulesBlock() {
  return getRuleContext<LSysDParser::CodingRulesBlockContext>(0);
}

LSysDParser::RuleDefContext* LSysDParser::DefinitionContext::ruleDef() {
  return getRuleContext<LSysDParser::RuleDefContext>(0);
}


size_t LSysDParser::DefinitionContext::getRuleIndex() const {
  return LSysDParser::RuleDefinition;
}

antlrcpp::Any LSysDParser::DefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitDefinition(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::DefinitionContext* LSysDParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 10, LSysDParser::RuleDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(162);
      axiomDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(163);
      propDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(164);
      funcDef();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(165);
      tableBlock();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(166);
      rulesBlock();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(167);
      productionRulesBlock();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(168);
      codingRulesBlock();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(169);
      ruleDef();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AxiomDefContext ------------------------------------------------------------------

LSysDParser::AxiomDefContext::AxiomDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::AxiomDefContext::KWAXIOM() {
  return getToken(LSysDParser::KWAXIOM, 0);
}

LSysDParser::WordContext* LSysDParser::AxiomDefContext::word() {
  return getRuleContext<LSysDParser::WordContext>(0);
}


size_t LSysDParser::AxiomDefContext::getRuleIndex() const {
  return LSysDParser::RuleAxiomDef;
}

antlrcpp::Any LSysDParser::AxiomDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAxiomDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::AxiomDefContext* LSysDParser::axiomDef() {
  AxiomDefContext *_localctx = _tracker.createInstance<AxiomDefContext>(_ctx, getState());
  enterRule(_localctx, 12, LSysDParser::RuleAxiomDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(LSysDParser::KWAXIOM);
    setState(173);
    word();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropDefContext ------------------------------------------------------------------

LSysDParser::PropDefContext::PropDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::PropDefContext::KWSET() {
  return getToken(LSysDParser::KWSET, 0);
}

tree::TerminalNode* LSysDParser::PropDefContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::PropDefContext::ASSIGN() {
  return getToken(LSysDParser::ASSIGN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::PropDefContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::PropDefContext::getRuleIndex() const {
  return LSysDParser::RulePropDef;
}

antlrcpp::Any LSysDParser::PropDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitPropDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::PropDefContext* LSysDParser::propDef() {
  PropDefContext *_localctx = _tracker.createInstance<PropDefContext>(_ctx, getState());
  enterRule(_localctx, 14, LSysDParser::RulePropDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(LSysDParser::KWSET);
    setState(176);
    match(LSysDParser::ID);
    setState(177);
    match(LSysDParser::ASSIGN);
    setState(178);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

LSysDParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::FuncDefContext::KWSET() {
  return getToken(LSysDParser::KWSET, 0);
}

tree::TerminalNode* LSysDParser::FuncDefContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::FuncDefContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

LSysDParser::ParamsContext* LSysDParser::FuncDefContext::params() {
  return getRuleContext<LSysDParser::ParamsContext>(0);
}

tree::TerminalNode* LSysDParser::FuncDefContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

tree::TerminalNode* LSysDParser::FuncDefContext::ASSIGN() {
  return getToken(LSysDParser::ASSIGN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::FuncDefContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::FuncDefContext::getRuleIndex() const {
  return LSysDParser::RuleFuncDef;
}

antlrcpp::Any LSysDParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::FuncDefContext* LSysDParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 16, LSysDParser::RuleFuncDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(LSysDParser::KWSET);
    setState(181);
    match(LSysDParser::ID);
    setState(182);
    match(LSysDParser::LPAREN);
    setState(183);
    params();
    setState(184);
    match(LSysDParser::RPAREN);
    setState(185);
    match(LSysDParser::ASSIGN);
    setState(186);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

LSysDParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::ConstDefContext::DOLLARID() {
  return getToken(LSysDParser::DOLLARID, 0);
}

tree::TerminalNode* LSysDParser::ConstDefContext::ASSIGN() {
  return getToken(LSysDParser::ASSIGN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::ConstDefContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::ConstDefContext::getRuleIndex() const {
  return LSysDParser::RuleConstDef;
}

antlrcpp::Any LSysDParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ConstDefContext* LSysDParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 18, LSysDParser::RuleConstDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(LSysDParser::DOLLARID);
    setState(189);
    match(LSysDParser::ASSIGN);
    setState(190);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableBlockContext ------------------------------------------------------------------

LSysDParser::TableBlockContext::TableBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::TableBlockContext::KWTABLE() {
  return getToken(LSysDParser::KWTABLE, 0);
}

tree::TerminalNode* LSysDParser::TableBlockContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::TableBlockContext::LBRACE() {
  return getToken(LSysDParser::LBRACE, 0);
}

LSysDParser::RulesContext* LSysDParser::TableBlockContext::rules() {
  return getRuleContext<LSysDParser::RulesContext>(0);
}

tree::TerminalNode* LSysDParser::TableBlockContext::RBRACE() {
  return getToken(LSysDParser::RBRACE, 0);
}


size_t LSysDParser::TableBlockContext::getRuleIndex() const {
  return LSysDParser::RuleTableBlock;
}

antlrcpp::Any LSysDParser::TableBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitTableBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::TableBlockContext* LSysDParser::tableBlock() {
  TableBlockContext *_localctx = _tracker.createInstance<TableBlockContext>(_ctx, getState());
  enterRule(_localctx, 20, LSysDParser::RuleTableBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(LSysDParser::KWTABLE);
    setState(193);
    match(LSysDParser::ID);
    setState(194);
    match(LSysDParser::LBRACE);
    setState(195);
    rules();
    setState(196);
    match(LSysDParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RulesBlockContext ------------------------------------------------------------------

LSysDParser::RulesBlockContext::RulesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::RulesBlockContext::KWRULES() {
  return getToken(LSysDParser::KWRULES, 0);
}

tree::TerminalNode* LSysDParser::RulesBlockContext::LBRACE() {
  return getToken(LSysDParser::LBRACE, 0);
}

LSysDParser::RuleDefsContext* LSysDParser::RulesBlockContext::ruleDefs() {
  return getRuleContext<LSysDParser::RuleDefsContext>(0);
}

tree::TerminalNode* LSysDParser::RulesBlockContext::RBRACE() {
  return getToken(LSysDParser::RBRACE, 0);
}

LSysDParser::NlContext* LSysDParser::RulesBlockContext::nl() {
  return getRuleContext<LSysDParser::NlContext>(0);
}


size_t LSysDParser::RulesBlockContext::getRuleIndex() const {
  return LSysDParser::RuleRulesBlock;
}

antlrcpp::Any LSysDParser::RulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RulesBlockContext* LSysDParser::rulesBlock() {
  RulesBlockContext *_localctx = _tracker.createInstance<RulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 22, LSysDParser::RuleRulesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(LSysDParser::KWRULES);
    setState(200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(199);
      nl();
    }
    setState(202);
    match(LSysDParser::LBRACE);
    setState(203);
    ruleDefs();
    setState(204);
    match(LSysDParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductionRulesBlockContext ------------------------------------------------------------------

LSysDParser::ProductionRulesBlockContext::ProductionRulesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::ProductionRulesBlockContext::KWPRODUCTION() {
  return getToken(LSysDParser::KWPRODUCTION, 0);
}

tree::TerminalNode* LSysDParser::ProductionRulesBlockContext::KWRULES() {
  return getToken(LSysDParser::KWRULES, 0);
}

tree::TerminalNode* LSysDParser::ProductionRulesBlockContext::LBRACE() {
  return getToken(LSysDParser::LBRACE, 0);
}

LSysDParser::RuleDefsContext* LSysDParser::ProductionRulesBlockContext::ruleDefs() {
  return getRuleContext<LSysDParser::RuleDefsContext>(0);
}

tree::TerminalNode* LSysDParser::ProductionRulesBlockContext::RBRACE() {
  return getToken(LSysDParser::RBRACE, 0);
}

std::vector<LSysDParser::NlContext *> LSysDParser::ProductionRulesBlockContext::nl() {
  return getRuleContexts<LSysDParser::NlContext>();
}

LSysDParser::NlContext* LSysDParser::ProductionRulesBlockContext::nl(size_t i) {
  return getRuleContext<LSysDParser::NlContext>(i);
}


size_t LSysDParser::ProductionRulesBlockContext::getRuleIndex() const {
  return LSysDParser::RuleProductionRulesBlock;
}

antlrcpp::Any LSysDParser::ProductionRulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRulesBlockContext* LSysDParser::productionRulesBlock() {
  ProductionRulesBlockContext *_localctx = _tracker.createInstance<ProductionRulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 24, LSysDParser::RuleProductionRulesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(LSysDParser::KWPRODUCTION);
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(207);
      nl();
    }
    setState(210);
    match(LSysDParser::KWRULES);
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(211);
      nl();
    }
    setState(214);
    match(LSysDParser::LBRACE);
    setState(215);
    ruleDefs();
    setState(216);
    match(LSysDParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodingRulesBlockContext ------------------------------------------------------------------

LSysDParser::CodingRulesBlockContext::CodingRulesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::CodingRulesBlockContext::KWCODING() {
  return getToken(LSysDParser::KWCODING, 0);
}

tree::TerminalNode* LSysDParser::CodingRulesBlockContext::KWRULES() {
  return getToken(LSysDParser::KWRULES, 0);
}

tree::TerminalNode* LSysDParser::CodingRulesBlockContext::LBRACE() {
  return getToken(LSysDParser::LBRACE, 0);
}

LSysDParser::RuleDefsContext* LSysDParser::CodingRulesBlockContext::ruleDefs() {
  return getRuleContext<LSysDParser::RuleDefsContext>(0);
}

tree::TerminalNode* LSysDParser::CodingRulesBlockContext::RBRACE() {
  return getToken(LSysDParser::RBRACE, 0);
}

std::vector<LSysDParser::NlContext *> LSysDParser::CodingRulesBlockContext::nl() {
  return getRuleContexts<LSysDParser::NlContext>();
}

LSysDParser::NlContext* LSysDParser::CodingRulesBlockContext::nl(size_t i) {
  return getRuleContext<LSysDParser::NlContext>(i);
}


size_t LSysDParser::CodingRulesBlockContext::getRuleIndex() const {
  return LSysDParser::RuleCodingRulesBlock;
}

antlrcpp::Any LSysDParser::CodingRulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRulesBlockContext* LSysDParser::codingRulesBlock() {
  CodingRulesBlockContext *_localctx = _tracker.createInstance<CodingRulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 26, LSysDParser::RuleCodingRulesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(LSysDParser::KWCODING);
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(219);
      nl();
    }
    setState(222);
    match(LSysDParser::KWRULES);
    setState(224);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(223);
      nl();
    }
    setState(226);
    match(LSysDParser::LBRACE);
    setState(227);
    ruleDefs();
    setState(228);
    match(LSysDParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RulesContext ------------------------------------------------------------------

LSysDParser::RulesContext::RulesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::SepContext *> LSysDParser::RulesContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::RulesContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

std::vector<LSysDParser::AnyRuleContext *> LSysDParser::RulesContext::anyRule() {
  return getRuleContexts<LSysDParser::AnyRuleContext>();
}

LSysDParser::AnyRuleContext* LSysDParser::RulesContext::anyRule(size_t i) {
  return getRuleContext<LSysDParser::AnyRuleContext>(i);
}


size_t LSysDParser::RulesContext::getRuleIndex() const {
  return LSysDParser::RuleRules;
}

antlrcpp::Any LSysDParser::RulesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRules(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RulesContext* LSysDParser::rules() {
  RulesContext *_localctx = _tracker.createInstance<RulesContext>(_ctx, getState());
  enterRule(_localctx, 28, LSysDParser::RuleRules);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(231);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(230);
      sep();
      break;
    }

    }
    setState(238);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(233);
        anyRule();
        setState(234);
        sep(); 
      }
      setState(240);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(242);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LPAREN - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::LT - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::XM - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(241);
      anyRule();
    }
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(244);
      sep();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleDefsContext ------------------------------------------------------------------

LSysDParser::RuleDefsContext::RuleDefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::SepContext *> LSysDParser::RuleDefsContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::RuleDefsContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

std::vector<LSysDParser::RuleDefContext *> LSysDParser::RuleDefsContext::ruleDef() {
  return getRuleContexts<LSysDParser::RuleDefContext>();
}

LSysDParser::RuleDefContext* LSysDParser::RuleDefsContext::ruleDef(size_t i) {
  return getRuleContext<LSysDParser::RuleDefContext>(i);
}


size_t LSysDParser::RuleDefsContext::getRuleIndex() const {
  return LSysDParser::RuleRuleDefs;
}

antlrcpp::Any LSysDParser::RuleDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRuleDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RuleDefsContext* LSysDParser::ruleDefs() {
  RuleDefsContext *_localctx = _tracker.createInstance<RuleDefsContext>(_ctx, getState());
  enterRule(_localctx, 30, LSysDParser::RuleRuleDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(248);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(247);
      sep();
      break;
    }

    }
    setState(255);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(250);
        ruleDef();
        setState(251);
        sep(); 
      }
      setState(257);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LPAREN - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::LT - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::XM - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(258);
      ruleDef();
    }
    setState(262);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(261);
      sep();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductionRuleDefsContext ------------------------------------------------------------------

LSysDParser::ProductionRuleDefsContext::ProductionRuleDefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::SepContext *> LSysDParser::ProductionRuleDefsContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::ProductionRuleDefsContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

std::vector<LSysDParser::ProductionRuleDefContext *> LSysDParser::ProductionRuleDefsContext::productionRuleDef() {
  return getRuleContexts<LSysDParser::ProductionRuleDefContext>();
}

LSysDParser::ProductionRuleDefContext* LSysDParser::ProductionRuleDefsContext::productionRuleDef(size_t i) {
  return getRuleContext<LSysDParser::ProductionRuleDefContext>(i);
}


size_t LSysDParser::ProductionRuleDefsContext::getRuleIndex() const {
  return LSysDParser::RuleProductionRuleDefs;
}

antlrcpp::Any LSysDParser::ProductionRuleDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRuleDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRuleDefsContext* LSysDParser::productionRuleDefs() {
  ProductionRuleDefsContext *_localctx = _tracker.createInstance<ProductionRuleDefsContext>(_ctx, getState());
  enterRule(_localctx, 32, LSysDParser::RuleProductionRuleDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(265);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(264);
      sep();
      break;
    }

    }
    setState(272);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(267);
        productionRuleDef();
        setState(268);
        sep(); 
      }
      setState(274);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LPAREN - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::LT - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::XM - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(275);
      productionRuleDef();
    }
    setState(279);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(278);
      sep();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodingRuleDefsContext ------------------------------------------------------------------

LSysDParser::CodingRuleDefsContext::CodingRuleDefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::SepContext *> LSysDParser::CodingRuleDefsContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::CodingRuleDefsContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

std::vector<LSysDParser::CodingRuleDefContext *> LSysDParser::CodingRuleDefsContext::codingRuleDef() {
  return getRuleContexts<LSysDParser::CodingRuleDefContext>();
}

LSysDParser::CodingRuleDefContext* LSysDParser::CodingRuleDefsContext::codingRuleDef(size_t i) {
  return getRuleContext<LSysDParser::CodingRuleDefContext>(i);
}


size_t LSysDParser::CodingRuleDefsContext::getRuleIndex() const {
  return LSysDParser::RuleCodingRuleDefs;
}

antlrcpp::Any LSysDParser::CodingRuleDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRuleDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRuleDefsContext* LSysDParser::codingRuleDefs() {
  CodingRuleDefsContext *_localctx = _tracker.createInstance<CodingRuleDefsContext>(_ctx, getState());
  enterRule(_localctx, 34, LSysDParser::RuleCodingRuleDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(282);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(281);
      sep();
      break;
    }

    }
    setState(289);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(284);
        codingRuleDef();
        setState(285);
        sep(); 
      }
      setState(291);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LPAREN - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::LT - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::XM - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(292);
      codingRuleDef();
    }
    setState(296);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(295);
      sep();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnyRuleContext ------------------------------------------------------------------

LSysDParser::AnyRuleContext::AnyRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ProductionRuleContext* LSysDParser::AnyRuleContext::productionRule() {
  return getRuleContext<LSysDParser::ProductionRuleContext>(0);
}

LSysDParser::CodingRuleContext* LSysDParser::AnyRuleContext::codingRule() {
  return getRuleContext<LSysDParser::CodingRuleContext>(0);
}


size_t LSysDParser::AnyRuleContext::getRuleIndex() const {
  return LSysDParser::RuleAnyRule;
}

antlrcpp::Any LSysDParser::AnyRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAnyRule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::AnyRuleContext* LSysDParser::anyRule() {
  AnyRuleContext *_localctx = _tracker.createInstance<AnyRuleContext>(_ctx, getState());
  enterRule(_localctx, 36, LSysDParser::RuleAnyRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(298);
      productionRule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(299);
      codingRule();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductionRuleContext ------------------------------------------------------------------

LSysDParser::ProductionRuleContext::ProductionRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ProductionRuleDefContext* LSysDParser::ProductionRuleContext::productionRuleDef() {
  return getRuleContext<LSysDParser::ProductionRuleDefContext>(0);
}

LSysDParser::TagContext* LSysDParser::ProductionRuleContext::tag() {
  return getRuleContext<LSysDParser::TagContext>(0);
}


size_t LSysDParser::ProductionRuleContext::getRuleIndex() const {
  return LSysDParser::RuleProductionRule;
}

antlrcpp::Any LSysDParser::ProductionRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRuleContext* LSysDParser::productionRule() {
  ProductionRuleContext *_localctx = _tracker.createInstance<ProductionRuleContext>(_ctx, getState());
  enterRule(_localctx, 38, LSysDParser::RuleProductionRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(302);
      productionRuleDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(303);
      tag();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodingRuleContext ------------------------------------------------------------------

LSysDParser::CodingRuleContext::CodingRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::CodingRuleDefContext* LSysDParser::CodingRuleContext::codingRuleDef() {
  return getRuleContext<LSysDParser::CodingRuleDefContext>(0);
}


size_t LSysDParser::CodingRuleContext::getRuleIndex() const {
  return LSysDParser::RuleCodingRule;
}

antlrcpp::Any LSysDParser::CodingRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRuleContext* LSysDParser::codingRule() {
  CodingRuleContext *_localctx = _tracker.createInstance<CodingRuleContext>(_ctx, getState());
  enterRule(_localctx, 40, LSysDParser::RuleCodingRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    codingRuleDef();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleDefContext ------------------------------------------------------------------

LSysDParser::RuleDefContext::RuleDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ProductionRuleDefContext* LSysDParser::RuleDefContext::productionRuleDef() {
  return getRuleContext<LSysDParser::ProductionRuleDefContext>(0);
}

LSysDParser::CodingRuleDefContext* LSysDParser::RuleDefContext::codingRuleDef() {
  return getRuleContext<LSysDParser::CodingRuleDefContext>(0);
}


size_t LSysDParser::RuleDefContext::getRuleIndex() const {
  return LSysDParser::RuleRuleDef;
}

antlrcpp::Any LSysDParser::RuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRuleDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RuleDefContext* LSysDParser::ruleDef() {
  RuleDefContext *_localctx = _tracker.createInstance<RuleDefContext>(_ctx, getState());
  enterRule(_localctx, 42, LSysDParser::RuleRuleDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(310);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(308);
      productionRuleDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(309);
      codingRuleDef();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductionRuleDefContext ------------------------------------------------------------------

LSysDParser::ProductionRuleDefContext::ProductionRuleDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::LsideContext* LSysDParser::ProductionRuleDefContext::lside() {
  return getRuleContext<LSysDParser::LsideContext>(0);
}

tree::TerminalNode* LSysDParser::ProductionRuleDefContext::ARROW() {
  return getToken(LSysDParser::ARROW, 0);
}

LSysDParser::RsideContext* LSysDParser::ProductionRuleDefContext::rside() {
  return getRuleContext<LSysDParser::RsideContext>(0);
}

LSysDParser::TagPrefixContext* LSysDParser::ProductionRuleDefContext::tagPrefix() {
  return getRuleContext<LSysDParser::TagPrefixContext>(0);
}

LSysDParser::WeightContext* LSysDParser::ProductionRuleDefContext::weight() {
  return getRuleContext<LSysDParser::WeightContext>(0);
}

LSysDParser::LcontextContext* LSysDParser::ProductionRuleDefContext::lcontext() {
  return getRuleContext<LSysDParser::LcontextContext>(0);
}

LSysDParser::RcontextContext* LSysDParser::ProductionRuleDefContext::rcontext() {
  return getRuleContext<LSysDParser::RcontextContext>(0);
}

LSysDParser::NlContext* LSysDParser::ProductionRuleDefContext::nl() {
  return getRuleContext<LSysDParser::NlContext>(0);
}


size_t LSysDParser::ProductionRuleDefContext::getRuleIndex() const {
  return LSysDParser::RuleProductionRuleDef;
}

antlrcpp::Any LSysDParser::ProductionRuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRuleDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRuleDefContext* LSysDParser::productionRuleDef() {
  ProductionRuleDefContext *_localctx = _tracker.createInstance<ProductionRuleDefContext>(_ctx, getState());
  enterRule(_localctx, 44, LSysDParser::RuleProductionRuleDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(312);
      tagPrefix();
      break;
    }

    }
    setState(316);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::LPAREN

    || _la == LSysDParser::XM) {
      setState(315);
      weight();
    }
    setState(319);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      setState(318);
      lcontext();
      break;
    }

    }
    setState(321);
    lside();
    setState(323);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::GT) {
      setState(322);
      rcontext();
    }
    setState(325);
    match(LSysDParser::ARROW);
    setState(327);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(326);
      nl();
      break;
    }

    }
    setState(329);
    rside();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodingRuleDefContext ------------------------------------------------------------------

LSysDParser::CodingRuleDefContext::CodingRuleDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::LsideContext* LSysDParser::CodingRuleDefContext::lside() {
  return getRuleContext<LSysDParser::LsideContext>(0);
}

tree::TerminalNode* LSysDParser::CodingRuleDefContext::DARROW() {
  return getToken(LSysDParser::DARROW, 0);
}

LSysDParser::RsideContext* LSysDParser::CodingRuleDefContext::rside() {
  return getRuleContext<LSysDParser::RsideContext>(0);
}

LSysDParser::TagPrefixContext* LSysDParser::CodingRuleDefContext::tagPrefix() {
  return getRuleContext<LSysDParser::TagPrefixContext>(0);
}

LSysDParser::WeightContext* LSysDParser::CodingRuleDefContext::weight() {
  return getRuleContext<LSysDParser::WeightContext>(0);
}

LSysDParser::LcontextContext* LSysDParser::CodingRuleDefContext::lcontext() {
  return getRuleContext<LSysDParser::LcontextContext>(0);
}

LSysDParser::RcontextContext* LSysDParser::CodingRuleDefContext::rcontext() {
  return getRuleContext<LSysDParser::RcontextContext>(0);
}

LSysDParser::NlContext* LSysDParser::CodingRuleDefContext::nl() {
  return getRuleContext<LSysDParser::NlContext>(0);
}


size_t LSysDParser::CodingRuleDefContext::getRuleIndex() const {
  return LSysDParser::RuleCodingRuleDef;
}

antlrcpp::Any LSysDParser::CodingRuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRuleDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRuleDefContext* LSysDParser::codingRuleDef() {
  CodingRuleDefContext *_localctx = _tracker.createInstance<CodingRuleDefContext>(_ctx, getState());
  enterRule(_localctx, 46, LSysDParser::RuleCodingRuleDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      setState(331);
      tagPrefix();
      break;
    }

    }
    setState(335);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::LPAREN

    || _la == LSysDParser::XM) {
      setState(334);
      weight();
    }
    setState(338);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(337);
      lcontext();
      break;
    }

    }
    setState(340);
    lside();
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::GT) {
      setState(341);
      rcontext();
    }
    setState(344);
    match(LSysDParser::DARROW);
    setState(346);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(345);
      nl();
      break;
    }

    }
    setState(348);
    rside();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TagPrefixContext ------------------------------------------------------------------

LSysDParser::TagPrefixContext::TagPrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::TagContext* LSysDParser::TagPrefixContext::tag() {
  return getRuleContext<LSysDParser::TagContext>(0);
}

tree::TerminalNode* LSysDParser::TagPrefixContext::COLON() {
  return getToken(LSysDParser::COLON, 0);
}


size_t LSysDParser::TagPrefixContext::getRuleIndex() const {
  return LSysDParser::RuleTagPrefix;
}

antlrcpp::Any LSysDParser::TagPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitTagPrefix(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::TagPrefixContext* LSysDParser::tagPrefix() {
  TagPrefixContext *_localctx = _tracker.createInstance<TagPrefixContext>(_ctx, getState());
  enterRule(_localctx, 48, LSysDParser::RuleTagPrefix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    tag();
    setState(351);
    match(LSysDParser::COLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TagContext ------------------------------------------------------------------

LSysDParser::TagContext::TagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::TagContext::ID() {
  return getToken(LSysDParser::ID, 0);
}


size_t LSysDParser::TagContext::getRuleIndex() const {
  return LSysDParser::RuleTag;
}

antlrcpp::Any LSysDParser::TagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitTag(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::TagContext* LSysDParser::tag() {
  TagContext *_localctx = _tracker.createInstance<TagContext>(_ctx, getState());
  enterRule(_localctx, 50, LSysDParser::RuleTag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(LSysDParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WeightContext ------------------------------------------------------------------

LSysDParser::WeightContext::WeightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::WeightContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

tree::TerminalNode* LSysDParser::WeightContext::INT() {
  return getToken(LSysDParser::INT, 0);
}

tree::TerminalNode* LSysDParser::WeightContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

tree::TerminalNode* LSysDParser::WeightContext::XM() {
  return getToken(LSysDParser::XM, 0);
}


size_t LSysDParser::WeightContext::getRuleIndex() const {
  return LSysDParser::RuleWeight;
}

antlrcpp::Any LSysDParser::WeightContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitWeight(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::WeightContext* LSysDParser::weight() {
  WeightContext *_localctx = _tracker.createInstance<WeightContext>(_ctx, getState());
  enterRule(_localctx, 52, LSysDParser::RuleWeight);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(355);
      match(LSysDParser::LPAREN);
      setState(356);
      match(LSysDParser::INT);
      setState(357);
      match(LSysDParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      match(LSysDParser::LPAREN);
      setState(359);
      match(LSysDParser::XM);
      setState(360);
      match(LSysDParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(361);
      match(LSysDParser::XM);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LsideContext ------------------------------------------------------------------

LSysDParser::LsideContext::LsideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::LCharContext* LSysDParser::LsideContext::lChar() {
  return getRuleContext<LSysDParser::LCharContext>(0);
}


size_t LSysDParser::LsideContext::getRuleIndex() const {
  return LSysDParser::RuleLside;
}

antlrcpp::Any LSysDParser::LsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLside(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LsideContext* LSysDParser::lside() {
  LsideContext *_localctx = _tracker.createInstance<LsideContext>(_ctx, getState());
  enterRule(_localctx, 54, LSysDParser::RuleLside);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    lChar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LcontextContext ------------------------------------------------------------------

LSysDParser::LcontextContext::LcontextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::LcontextContext::LT() {
  return getToken(LSysDParser::LT, 0);
}

std::vector<LSysDParser::LItemContext *> LSysDParser::LcontextContext::lItem() {
  return getRuleContexts<LSysDParser::LItemContext>();
}

LSysDParser::LItemContext* LSysDParser::LcontextContext::lItem(size_t i) {
  return getRuleContext<LSysDParser::LItemContext>(i);
}


size_t LSysDParser::LcontextContext::getRuleIndex() const {
  return LSysDParser::RuleLcontext;
}

antlrcpp::Any LSysDParser::LcontextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLcontext(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LcontextContext* LSysDParser::lcontext() {
  LcontextContext *_localctx = _tracker.createInstance<LcontextContext>(_ctx, getState());
  enterRule(_localctx, 56, LSysDParser::RuleLcontext);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(366);
      lItem();
      setState(371);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(372);
    match(LSysDParser::LT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RcontextContext ------------------------------------------------------------------

LSysDParser::RcontextContext::RcontextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::RcontextContext::GT() {
  return getToken(LSysDParser::GT, 0);
}

std::vector<LSysDParser::LItemContext *> LSysDParser::RcontextContext::lItem() {
  return getRuleContexts<LSysDParser::LItemContext>();
}

LSysDParser::LItemContext* LSysDParser::RcontextContext::lItem(size_t i) {
  return getRuleContext<LSysDParser::LItemContext>(i);
}


size_t LSysDParser::RcontextContext::getRuleIndex() const {
  return LSysDParser::RuleRcontext;
}

antlrcpp::Any LSysDParser::RcontextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRcontext(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RcontextContext* LSysDParser::rcontext() {
  RcontextContext *_localctx = _tracker.createInstance<RcontextContext>(_ctx, getState());
  enterRule(_localctx, 58, LSysDParser::RuleRcontext);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    match(LSysDParser::GT);
    setState(378);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(375);
      lItem();
      setState(380);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RsideContext ------------------------------------------------------------------

LSysDParser::RsideContext::RsideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::RItemContext *> LSysDParser::RsideContext::rItem() {
  return getRuleContexts<LSysDParser::RItemContext>();
}

LSysDParser::RItemContext* LSysDParser::RsideContext::rItem(size_t i) {
  return getRuleContext<LSysDParser::RItemContext>(i);
}


size_t LSysDParser::RsideContext::getRuleIndex() const {
  return LSysDParser::RuleRside;
}

antlrcpp::Any LSysDParser::RsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRside(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RsideContext* LSysDParser::rside() {
  RsideContext *_localctx = _tracker.createInstance<RsideContext>(_ctx, getState());
  enterRule(_localctx, 60, LSysDParser::RuleRside);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(381);
      rItem();
      setState(386);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WordContext ------------------------------------------------------------------

LSysDParser::WordContext::WordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::RItemContext *> LSysDParser::WordContext::rItem() {
  return getRuleContexts<LSysDParser::RItemContext>();
}

LSysDParser::RItemContext* LSysDParser::WordContext::rItem(size_t i) {
  return getRuleContext<LSysDParser::RItemContext>(i);
}


size_t LSysDParser::WordContext::getRuleIndex() const {
  return LSysDParser::RuleWord;
}

antlrcpp::Any LSysDParser::WordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitWord(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::WordContext* LSysDParser::word() {
  WordContext *_localctx = _tracker.createInstance<WordContext>(_ctx, getState());
  enterRule(_localctx, 62, LSysDParser::RuleWord);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::LBRACK - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
      setState(387);
      rItem();
      setState(392);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LCharContext ------------------------------------------------------------------

LSysDParser::LCharContext::LCharContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ValidLeftCharContext* LSysDParser::LCharContext::validLeftChar() {
  return getRuleContext<LSysDParser::ValidLeftCharContext>(0);
}

tree::TerminalNode* LSysDParser::LCharContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

LSysDParser::ParamsWithCondContext* LSysDParser::LCharContext::paramsWithCond() {
  return getRuleContext<LSysDParser::ParamsWithCondContext>(0);
}

tree::TerminalNode* LSysDParser::LCharContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}


size_t LSysDParser::LCharContext::getRuleIndex() const {
  return LSysDParser::RuleLChar;
}

antlrcpp::Any LSysDParser::LCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LCharContext* LSysDParser::lChar() {
  LCharContext *_localctx = _tracker.createInstance<LCharContext>(_ctx, getState());
  enterRule(_localctx, 64, LSysDParser::RuleLChar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    validLeftChar();
    setState(398);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::LPAREN) {
      setState(394);
      match(LSysDParser::LPAREN);
      setState(395);
      paramsWithCond();
      setState(396);
      match(LSysDParser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LItemContext ------------------------------------------------------------------

LSysDParser::LItemContext::LItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ValidLeftCharContext* LSysDParser::LItemContext::validLeftChar() {
  return getRuleContext<LSysDParser::ValidLeftCharContext>(0);
}

tree::TerminalNode* LSysDParser::LItemContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

LSysDParser::ParamsWithCondContext* LSysDParser::LItemContext::paramsWithCond() {
  return getRuleContext<LSysDParser::ParamsWithCondContext>(0);
}

tree::TerminalNode* LSysDParser::LItemContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

tree::TerminalNode* LSysDParser::LItemContext::LBRACK() {
  return getToken(LSysDParser::LBRACK, 0);
}

tree::TerminalNode* LSysDParser::LItemContext::RBRACK() {
  return getToken(LSysDParser::RBRACK, 0);
}

std::vector<LSysDParser::LItemContext *> LSysDParser::LItemContext::lItem() {
  return getRuleContexts<LSysDParser::LItemContext>();
}

LSysDParser::LItemContext* LSysDParser::LItemContext::lItem(size_t i) {
  return getRuleContext<LSysDParser::LItemContext>(i);
}


size_t LSysDParser::LItemContext::getRuleIndex() const {
  return LSysDParser::RuleLItem;
}

antlrcpp::Any LSysDParser::LItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLItem(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LItemContext* LSysDParser::lItem() {
  LItemContext *_localctx = _tracker.createInstance<LItemContext>(_ctx, getState());
  enterRule(_localctx, 66, LSysDParser::RuleLItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(415);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ID:
      case LSysDParser::INT:
      case LSysDParser::ADD:
      case LSysDParser::SUB:
      case LSysDParser::RULECHAR: {
        enterOuterAlt(_localctx, 1);
        setState(400);
        validLeftChar();
        setState(405);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::LPAREN) {
          setState(401);
          match(LSysDParser::LPAREN);
          setState(402);
          paramsWithCond();
          setState(403);
          match(LSysDParser::RPAREN);
        }
        break;
      }

      case LSysDParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(407);
        match(LSysDParser::LBRACK);
        setState(411);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 3) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
          | (1ULL << (LSysDParser::INT - 3))
          | (1ULL << (LSysDParser::LBRACK - 3))
          | (1ULL << (LSysDParser::ADD - 3))
          | (1ULL << (LSysDParser::SUB - 3))
          | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
          setState(408);
          lItem();
          setState(413);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(414);
        match(LSysDParser::RBRACK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RItemContext ------------------------------------------------------------------

LSysDParser::RItemContext::RItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ValidRightCharContext* LSysDParser::RItemContext::validRightChar() {
  return getRuleContext<LSysDParser::ValidRightCharContext>(0);
}

tree::TerminalNode* LSysDParser::RItemContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

LSysDParser::ArgsContext* LSysDParser::RItemContext::args() {
  return getRuleContext<LSysDParser::ArgsContext>(0);
}

tree::TerminalNode* LSysDParser::RItemContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

tree::TerminalNode* LSysDParser::RItemContext::LBRACK() {
  return getToken(LSysDParser::LBRACK, 0);
}

tree::TerminalNode* LSysDParser::RItemContext::RBRACK() {
  return getToken(LSysDParser::RBRACK, 0);
}

std::vector<LSysDParser::RItemContext *> LSysDParser::RItemContext::rItem() {
  return getRuleContexts<LSysDParser::RItemContext>();
}

LSysDParser::RItemContext* LSysDParser::RItemContext::rItem(size_t i) {
  return getRuleContext<LSysDParser::RItemContext>(i);
}


size_t LSysDParser::RItemContext::getRuleIndex() const {
  return LSysDParser::RuleRItem;
}

antlrcpp::Any LSysDParser::RItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRItem(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RItemContext* LSysDParser::rItem() {
  RItemContext *_localctx = _tracker.createInstance<RItemContext>(_ctx, getState());
  enterRule(_localctx, 68, LSysDParser::RuleRItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(432);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ID:
      case LSysDParser::INT:
      case LSysDParser::ADD:
      case LSysDParser::SUB:
      case LSysDParser::RULECHAR: {
        enterOuterAlt(_localctx, 1);
        setState(417);
        validRightChar();
        setState(422);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::LPAREN) {
          setState(418);
          match(LSysDParser::LPAREN);
          setState(419);
          args();
          setState(420);
          match(LSysDParser::RPAREN);
        }
        break;
      }

      case LSysDParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(424);
        match(LSysDParser::LBRACK);
        setState(428);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 3) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
          | (1ULL << (LSysDParser::INT - 3))
          | (1ULL << (LSysDParser::LBRACK - 3))
          | (1ULL << (LSysDParser::ADD - 3))
          | (1ULL << (LSysDParser::SUB - 3))
          | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0)) {
          setState(425);
          rItem();
          setState(430);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(431);
        match(LSysDParser::RBRACK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValidLeftCharContext ------------------------------------------------------------------

LSysDParser::ValidLeftCharContext::ValidLeftCharContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ValidCharContext* LSysDParser::ValidLeftCharContext::validChar() {
  return getRuleContext<LSysDParser::ValidCharContext>(0);
}


size_t LSysDParser::ValidLeftCharContext::getRuleIndex() const {
  return LSysDParser::RuleValidLeftChar;
}

antlrcpp::Any LSysDParser::ValidLeftCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitValidLeftChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ValidLeftCharContext* LSysDParser::validLeftChar() {
  ValidLeftCharContext *_localctx = _tracker.createInstance<ValidLeftCharContext>(_ctx, getState());
  enterRule(_localctx, 70, LSysDParser::RuleValidLeftChar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    validChar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValidRightCharContext ------------------------------------------------------------------

LSysDParser::ValidRightCharContext::ValidRightCharContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ValidCharContext* LSysDParser::ValidRightCharContext::validChar() {
  return getRuleContext<LSysDParser::ValidCharContext>(0);
}


size_t LSysDParser::ValidRightCharContext::getRuleIndex() const {
  return LSysDParser::RuleValidRightChar;
}

antlrcpp::Any LSysDParser::ValidRightCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitValidRightChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ValidRightCharContext* LSysDParser::validRightChar() {
  ValidRightCharContext *_localctx = _tracker.createInstance<ValidRightCharContext>(_ctx, getState());
  enterRule(_localctx, 72, LSysDParser::RuleValidRightChar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    validChar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValidCharContext ------------------------------------------------------------------

LSysDParser::ValidCharContext::ValidCharContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::ValidCharContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::ValidCharContext::INT() {
  return getToken(LSysDParser::INT, 0);
}

tree::TerminalNode* LSysDParser::ValidCharContext::ADD() {
  return getToken(LSysDParser::ADD, 0);
}

tree::TerminalNode* LSysDParser::ValidCharContext::SUB() {
  return getToken(LSysDParser::SUB, 0);
}

tree::TerminalNode* LSysDParser::ValidCharContext::RULECHAR() {
  return getToken(LSysDParser::RULECHAR, 0);
}


size_t LSysDParser::ValidCharContext::getRuleIndex() const {
  return LSysDParser::RuleValidChar;
}

antlrcpp::Any LSysDParser::ValidCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitValidChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ValidCharContext* LSysDParser::validChar() {
  ValidCharContext *_localctx = _tracker.createInstance<ValidCharContext>(_ctx, getState());
  enterRule(_localctx, 74, LSysDParser::RuleValidChar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    _la = _input->LA(1);
    if (!(((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (LSysDParser::ID - 3))
      | (1ULL << (LSysDParser::INT - 3))
      | (1ULL << (LSysDParser::ADD - 3))
      | (1ULL << (LSysDParser::SUB - 3))
      | (1ULL << (LSysDParser::RULECHAR - 3)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsWithCondContext ------------------------------------------------------------------

LSysDParser::ParamsWithCondContext::ParamsWithCondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ParamsContext* LSysDParser::ParamsWithCondContext::params() {
  return getRuleContext<LSysDParser::ParamsContext>(0);
}

tree::TerminalNode* LSysDParser::ParamsWithCondContext::BITOR() {
  return getToken(LSysDParser::BITOR, 0);
}

LSysDParser::CondContext* LSysDParser::ParamsWithCondContext::cond() {
  return getRuleContext<LSysDParser::CondContext>(0);
}


size_t LSysDParser::ParamsWithCondContext::getRuleIndex() const {
  return LSysDParser::RuleParamsWithCond;
}

antlrcpp::Any LSysDParser::ParamsWithCondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitParamsWithCond(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ParamsWithCondContext* LSysDParser::paramsWithCond() {
  ParamsWithCondContext *_localctx = _tracker.createInstance<ParamsWithCondContext>(_ctx, getState());
  enterRule(_localctx, 76, LSysDParser::RuleParamsWithCond);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    params();
    setState(443);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::BITOR) {
      setState(441);
      match(LSysDParser::BITOR);
      setState(442);
      cond();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

LSysDParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::ParamContext *> LSysDParser::ParamsContext::param() {
  return getRuleContexts<LSysDParser::ParamContext>();
}

LSysDParser::ParamContext* LSysDParser::ParamsContext::param(size_t i) {
  return getRuleContext<LSysDParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> LSysDParser::ParamsContext::COMMA() {
  return getTokens(LSysDParser::COMMA);
}

tree::TerminalNode* LSysDParser::ParamsContext::COMMA(size_t i) {
  return getToken(LSysDParser::COMMA, i);
}


size_t LSysDParser::ParamsContext::getRuleIndex() const {
  return LSysDParser::RuleParams;
}

antlrcpp::Any LSysDParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ParamsContext* LSysDParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 78, LSysDParser::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(453);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::ID) {
      setState(445);
      param();
      setState(450);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LSysDParser::COMMA) {
        setState(446);
        match(LSysDParser::COMMA);
        setState(447);
        param();
        setState(452);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

LSysDParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::ParamContext::ID() {
  return getToken(LSysDParser::ID, 0);
}


size_t LSysDParser::ParamContext::getRuleIndex() const {
  return LSysDParser::RuleParam;
}

antlrcpp::Any LSysDParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ParamContext* LSysDParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 80, LSysDParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(455);
    match(LSysDParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

LSysDParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ExpressionContext* LSysDParser::CondContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::CondContext::getRuleIndex() const {
  return LSysDParser::RuleCond;
}

antlrcpp::Any LSysDParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CondContext* LSysDParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 82, LSysDParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

LSysDParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::ArgContext *> LSysDParser::ArgsContext::arg() {
  return getRuleContexts<LSysDParser::ArgContext>();
}

LSysDParser::ArgContext* LSysDParser::ArgsContext::arg(size_t i) {
  return getRuleContext<LSysDParser::ArgContext>(i);
}

std::vector<tree::TerminalNode *> LSysDParser::ArgsContext::COMMA() {
  return getTokens(LSysDParser::COMMA);
}

tree::TerminalNode* LSysDParser::ArgsContext::COMMA(size_t i) {
  return getToken(LSysDParser::COMMA, i);
}


size_t LSysDParser::ArgsContext::getRuleIndex() const {
  return LSysDParser::RuleArgs;
}

antlrcpp::Any LSysDParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgsContext* LSysDParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 84, LSysDParser::RuleArgs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(470);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::FLOAT)
      | (1ULL << LSysDParser::STRING)
      | (1ULL << LSysDParser::LPAREN)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB)
      | (1ULL << LSysDParser::BITNOT)
      | (1ULL << LSysDParser::NOT)
      | (1ULL << LSysDParser::KWFALSE)
      | (1ULL << LSysDParser::KWIF)
      | (1ULL << LSysDParser::KWTRUE))) != 0)) {
      setState(459);
      arg();
      setState(464);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(460);
          match(LSysDParser::COMMA);
          setState(461);
          arg(); 
        }
        setState(466);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }
      setState(468);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::COMMA) {
        setState(467);
        match(LSysDParser::COMMA);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

LSysDParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ExpressionContext* LSysDParser::ArgContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::ArgContext::getRuleIndex() const {
  return LSysDParser::RuleArg;
}

antlrcpp::Any LSysDParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgContext* LSysDParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 86, LSysDParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(472);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

LSysDParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LSysDParser::ExpressionContext::getRuleIndex() const {
  return LSysDParser::RuleExpression;
}

void LSysDParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LogicBinaryExprContext ------------------------------------------------------------------

std::vector<LSysDParser::ExpressionContext *> LSysDParser::LogicBinaryExprContext::expression() {
  return getRuleContexts<LSysDParser::ExpressionContext>();
}

LSysDParser::ExpressionContext* LSysDParser::LogicBinaryExprContext::expression(size_t i) {
  return getRuleContext<LSysDParser::ExpressionContext>(i);
}

tree::TerminalNode* LSysDParser::LogicBinaryExprContext::AND() {
  return getToken(LSysDParser::AND, 0);
}

tree::TerminalNode* LSysDParser::LogicBinaryExprContext::OR() {
  return getToken(LSysDParser::OR, 0);
}

LSysDParser::LogicBinaryExprContext::LogicBinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::LogicBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLogicBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CmpBinaryExprContext ------------------------------------------------------------------

std::vector<LSysDParser::ExpressionContext *> LSysDParser::CmpBinaryExprContext::expression() {
  return getRuleContexts<LSysDParser::ExpressionContext>();
}

LSysDParser::ExpressionContext* LSysDParser::CmpBinaryExprContext::expression(size_t i) {
  return getRuleContext<LSysDParser::ExpressionContext>(i);
}

tree::TerminalNode* LSysDParser::CmpBinaryExprContext::LT() {
  return getToken(LSysDParser::LT, 0);
}

tree::TerminalNode* LSysDParser::CmpBinaryExprContext::GT() {
  return getToken(LSysDParser::GT, 0);
}

tree::TerminalNode* LSysDParser::CmpBinaryExprContext::LE() {
  return getToken(LSysDParser::LE, 0);
}

tree::TerminalNode* LSysDParser::CmpBinaryExprContext::GE() {
  return getToken(LSysDParser::GE, 0);
}

tree::TerminalNode* LSysDParser::CmpBinaryExprContext::EQ() {
  return getToken(LSysDParser::EQ, 0);
}

tree::TerminalNode* LSysDParser::CmpBinaryExprContext::NE() {
  return getToken(LSysDParser::NE, 0);
}

LSysDParser::CmpBinaryExprContext::CmpBinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::CmpBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCmpBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstExprContext ------------------------------------------------------------------

LSysDParser::ConstantContext* LSysDParser::ConstExprContext::constant() {
  return getRuleContext<LSysDParser::ConstantContext>(0);
}

LSysDParser::ConstExprContext::ConstExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitConstExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallExprContext ------------------------------------------------------------------

LSysDParser::ExpressionContext* LSysDParser::FunctionCallExprContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}

tree::TerminalNode* LSysDParser::FunctionCallExprContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

LSysDParser::ArgumentsContext* LSysDParser::FunctionCallExprContext::arguments() {
  return getRuleContext<LSysDParser::ArgumentsContext>(0);
}

tree::TerminalNode* LSysDParser::FunctionCallExprContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

LSysDParser::FunctionCallExprContext::FunctionCallExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::FunctionCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::IdExprContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

LSysDParser::IdExprContext::IdExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitBinaryExprContext ------------------------------------------------------------------

std::vector<LSysDParser::ExpressionContext *> LSysDParser::BitBinaryExprContext::expression() {
  return getRuleContexts<LSysDParser::ExpressionContext>();
}

LSysDParser::ExpressionContext* LSysDParser::BitBinaryExprContext::expression(size_t i) {
  return getRuleContext<LSysDParser::ExpressionContext>(i);
}

tree::TerminalNode* LSysDParser::BitBinaryExprContext::BITAND() {
  return getToken(LSysDParser::BITAND, 0);
}

tree::TerminalNode* LSysDParser::BitBinaryExprContext::BITXOR() {
  return getToken(LSysDParser::BITXOR, 0);
}

tree::TerminalNode* LSysDParser::BitBinaryExprContext::BITOR() {
  return getToken(LSysDParser::BITOR, 0);
}

LSysDParser::BitBinaryExprContext::BitBinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::BitBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitBitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AritUnaryExprContext ------------------------------------------------------------------

LSysDParser::ExpressionContext* LSysDParser::AritUnaryExprContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}

tree::TerminalNode* LSysDParser::AritUnaryExprContext::ADD() {
  return getToken(LSysDParser::ADD, 0);
}

tree::TerminalNode* LSysDParser::AritUnaryExprContext::SUB() {
  return getToken(LSysDParser::SUB, 0);
}

LSysDParser::AritUnaryExprContext::AritUnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::AritUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAritUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicUnaryExprContext ------------------------------------------------------------------

LSysDParser::ExpressionContext* LSysDParser::LogicUnaryExprContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}

tree::TerminalNode* LSysDParser::LogicUnaryExprContext::NOT() {
  return getToken(LSysDParser::NOT, 0);
}

tree::TerminalNode* LSysDParser::LogicUnaryExprContext::BITNOT() {
  return getToken(LSysDParser::BITNOT, 0);
}

LSysDParser::LogicUnaryExprContext::LogicUnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::LogicUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLogicUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExprContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::ParenthesizedExprContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::ParenthesizedExprContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}

tree::TerminalNode* LSysDParser::ParenthesizedExprContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

LSysDParser::ParenthesizedExprContext::ParenthesizedExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::ParenthesizedExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AritBinaryExprContext ------------------------------------------------------------------

std::vector<LSysDParser::ExpressionContext *> LSysDParser::AritBinaryExprContext::expression() {
  return getRuleContexts<LSysDParser::ExpressionContext>();
}

LSysDParser::ExpressionContext* LSysDParser::AritBinaryExprContext::expression(size_t i) {
  return getRuleContext<LSysDParser::ExpressionContext>(i);
}

tree::TerminalNode* LSysDParser::AritBinaryExprContext::POW() {
  return getToken(LSysDParser::POW, 0);
}

tree::TerminalNode* LSysDParser::AritBinaryExprContext::MUL() {
  return getToken(LSysDParser::MUL, 0);
}

tree::TerminalNode* LSysDParser::AritBinaryExprContext::DIV() {
  return getToken(LSysDParser::DIV, 0);
}

tree::TerminalNode* LSysDParser::AritBinaryExprContext::MOD() {
  return getToken(LSysDParser::MOD, 0);
}

tree::TerminalNode* LSysDParser::AritBinaryExprContext::ADD() {
  return getToken(LSysDParser::ADD, 0);
}

tree::TerminalNode* LSysDParser::AritBinaryExprContext::SUB() {
  return getToken(LSysDParser::SUB, 0);
}

LSysDParser::AritBinaryExprContext::AritBinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::AritBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAritBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfElseExprContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::IfElseExprContext::KWIF() {
  return getToken(LSysDParser::KWIF, 0);
}

std::vector<LSysDParser::ExpressionContext *> LSysDParser::IfElseExprContext::expression() {
  return getRuleContexts<LSysDParser::ExpressionContext>();
}

LSysDParser::ExpressionContext* LSysDParser::IfElseExprContext::expression(size_t i) {
  return getRuleContext<LSysDParser::ExpressionContext>(i);
}

tree::TerminalNode* LSysDParser::IfElseExprContext::KWTHEN() {
  return getToken(LSysDParser::KWTHEN, 0);
}

tree::TerminalNode* LSysDParser::IfElseExprContext::KWELSE() {
  return getToken(LSysDParser::KWELSE, 0);
}

LSysDParser::IfElseExprContext::IfElseExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::IfElseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitIfElseExpr(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ExpressionContext* LSysDParser::expression() {
   return expression(0);
}

LSysDParser::ExpressionContext* LSysDParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LSysDParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  LSysDParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 88;
  enterRecursionRule(_localctx, 88, LSysDParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(492);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::LPAREN: {
        _localctx = _tracker.createInstance<ParenthesizedExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(475);
        match(LSysDParser::LPAREN);
        setState(476);
        expression(0);
        setState(477);
        match(LSysDParser::RPAREN);
        break;
      }

      case LSysDParser::INT:
      case LSysDParser::FLOAT:
      case LSysDParser::STRING:
      case LSysDParser::KWFALSE:
      case LSysDParser::KWTRUE: {
        _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(479);
        constant();
        break;
      }

      case LSysDParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(480);
        match(LSysDParser::ID);
        break;
      }

      case LSysDParser::ADD:
      case LSysDParser::SUB: {
        _localctx = _tracker.createInstance<AritUnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(481);
        _la = _input->LA(1);
        if (!(_la == LSysDParser::ADD

        || _la == LSysDParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(482);
        expression(13);
        break;
      }

      case LSysDParser::BITNOT:
      case LSysDParser::NOT: {
        _localctx = _tracker.createInstance<LogicUnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(483);
        _la = _input->LA(1);
        if (!(_la == LSysDParser::BITNOT

        || _la == LSysDParser::NOT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(484);
        expression(12);
        break;
      }

      case LSysDParser::KWIF: {
        _localctx = _tracker.createInstance<IfElseExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(485);
        match(LSysDParser::KWIF);
        setState(486);
        expression(0);
        setState(487);
        match(LSysDParser::KWTHEN);
        setState(488);
        expression(0);
        setState(489);
        match(LSysDParser::KWELSE);
        setState(490);
        expression(1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(531);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(529);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(494);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");

          setState(495);
          match(LSysDParser::POW);
          setState(496);
          expression(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(497);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(498);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << LSysDParser::MUL)
            | (1ULL << LSysDParser::DIV)
            | (1ULL << LSysDParser::MOD))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(499);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(500);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(501);
          _la = _input->LA(1);
          if (!(_la == LSysDParser::ADD

          || _la == LSysDParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(502);
          expression(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CmpBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(503);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(504);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << LSysDParser::LT)
            | (1ULL << LSysDParser::GT)
            | (1ULL << LSysDParser::LE)
            | (1ULL << LSysDParser::GE))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(505);
          expression(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CmpBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(506);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(507);
          _la = _input->LA(1);
          if (!(_la == LSysDParser::EQ

          || _la == LSysDParser::NE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(508);
          expression(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(509);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");

          setState(510);
          match(LSysDParser::BITAND);
          setState(511);
          expression(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(512);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");

          setState(513);
          match(LSysDParser::BITXOR);
          setState(514);
          expression(6);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(515);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");

          setState(516);
          match(LSysDParser::BITOR);
          setState(517);
          expression(5);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(518);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");

          setState(519);
          match(LSysDParser::AND);
          setState(520);
          expression(4);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(521);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");

          setState(522);
          match(LSysDParser::OR);
          setState(523);
          expression(3);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<FunctionCallExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(524);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(525);
          match(LSysDParser::LPAREN);
          setState(526);
          arguments();
          setState(527);
          match(LSysDParser::RPAREN);
          break;
        }

        } 
      }
      setState(533);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

LSysDParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::ArgumentContext *> LSysDParser::ArgumentsContext::argument() {
  return getRuleContexts<LSysDParser::ArgumentContext>();
}

LSysDParser::ArgumentContext* LSysDParser::ArgumentsContext::argument(size_t i) {
  return getRuleContext<LSysDParser::ArgumentContext>(i);
}

std::vector<tree::TerminalNode *> LSysDParser::ArgumentsContext::COMMA() {
  return getTokens(LSysDParser::COMMA);
}

tree::TerminalNode* LSysDParser::ArgumentsContext::COMMA(size_t i) {
  return getToken(LSysDParser::COMMA, i);
}


size_t LSysDParser::ArgumentsContext::getRuleIndex() const {
  return LSysDParser::RuleArguments;
}

antlrcpp::Any LSysDParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgumentsContext* LSysDParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 90, LSysDParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(545);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::FLOAT)
      | (1ULL << LSysDParser::STRING)
      | (1ULL << LSysDParser::LPAREN)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB)
      | (1ULL << LSysDParser::BITNOT)
      | (1ULL << LSysDParser::NOT)
      | (1ULL << LSysDParser::KWFALSE)
      | (1ULL << LSysDParser::KWIF)
      | (1ULL << LSysDParser::KWTRUE))) != 0)) {
      setState(534);
      argument();
      setState(539);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(535);
          match(LSysDParser::COMMA);
          setState(536);
          argument(); 
        }
        setState(541);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      }
      setState(543);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::COMMA) {
        setState(542);
        match(LSysDParser::COMMA);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

LSysDParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ExpressionContext* LSysDParser::ArgumentContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::ArgumentContext::getRuleIndex() const {
  return LSysDParser::RuleArgument;
}

antlrcpp::Any LSysDParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgumentContext* LSysDParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 92, LSysDParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

LSysDParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LSysDParser::ConstantContext::getRuleIndex() const {
  return LSysDParser::RuleConstant;
}

void LSysDParser::ConstantContext::copyFrom(ConstantContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TrueValueContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::TrueValueContext::KWTRUE() {
  return getToken(LSysDParser::KWTRUE, 0);
}

LSysDParser::TrueValueContext::TrueValueContext(ConstantContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::TrueValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitTrueValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatConstantContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::FloatConstantContext::FLOAT() {
  return getToken(LSysDParser::FLOAT, 0);
}

LSysDParser::FloatConstantContext::FloatConstantContext(ConstantContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::FloatConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitFloatConstant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntConstantContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::IntConstantContext::INT() {
  return getToken(LSysDParser::INT, 0);
}

LSysDParser::IntConstantContext::IntConstantContext(ConstantContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::IntConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitIntConstant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringConstantContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::StringConstantContext::STRING() {
  return getToken(LSysDParser::STRING, 0);
}

LSysDParser::StringConstantContext::StringConstantContext(ConstantContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FalseValueContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::FalseValueContext::KWFALSE() {
  return getToken(LSysDParser::KWFALSE, 0);
}

LSysDParser::FalseValueContext::FalseValueContext(ConstantContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::FalseValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitFalseValue(this);
  else
    return visitor->visitChildren(this);
}
LSysDParser::ConstantContext* LSysDParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 94, LSysDParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(554);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::INT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::IntConstantContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(549);
        dynamic_cast<IntConstantContext *>(_localctx)->v = match(LSysDParser::INT);
        break;
      }

      case LSysDParser::FLOAT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::FloatConstantContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(550);
        dynamic_cast<FloatConstantContext *>(_localctx)->v = match(LSysDParser::FLOAT);
        break;
      }

      case LSysDParser::STRING: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::StringConstantContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(551);
        dynamic_cast<StringConstantContext *>(_localctx)->v = match(LSysDParser::STRING);
        break;
      }

      case LSysDParser::KWTRUE: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::TrueValueContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(552);
        match(LSysDParser::KWTRUE);
        break;
      }

      case LSysDParser::KWFALSE: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::FalseValueContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(553);
        match(LSysDParser::KWFALSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool LSysDParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 44: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LSysDParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);
    case 7: return precpred(_ctx, 4);
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 14);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> LSysDParser::_decisionToDFA;
atn::PredictionContextCache LSysDParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LSysDParser::_atn;
std::vector<uint16_t> LSysDParser::_serializedATN;

std::vector<std::string> LSysDParser::_ruleNames = {
  "main", "sep", "nl", "name", "definitions", "definition", "axiomDef", 
  "propDef", "funcDef", "constDef", "tableBlock", "rulesBlock", "productionRulesBlock", 
  "codingRulesBlock", "rules", "ruleDefs", "productionRuleDefs", "codingRuleDefs", 
  "anyRule", "productionRule", "codingRule", "ruleDef", "productionRuleDef", 
  "codingRuleDef", "tagPrefix", "tag", "weight", "lside", "lcontext", "rcontext", 
  "rside", "word", "lChar", "lItem", "rItem", "validLeftChar", "validRightChar", 
  "validChar", "paramsWithCond", "params", "param", "cond", "args", "arg", 
  "expression", "arguments", "argument", "constant"
};

std::vector<std::string> LSysDParser::_literalNames = {
  "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "':'", "';'", "','", "'.'", "'->'", "'='", "'<'", "'>'", "'<='", "'>='", 
  "'=='", "'!='", "'+'", "'-'", "'*'", "'/'", "'%'", "'**'", "'&'", "'|'", 
  "'^'", "'~'", "", "", "", "", "'else'", "", "'False'", "'for'", "", "'if'", 
  "", "'in'", "'None'", "'True'", "'and'", "'axiom'", "'coding'", "'lambda'", 
  "'lsystem'", "'not'", "'or'", "'production'", "'rules'", "'set'", "'table'", 
  "'then'", "'?'", "'!'", "'=>'", "'//'"
};

std::vector<std::string> LSysDParser::_symbolicNames = {
  "", "EOL", "ACCESSOR", "ID", "INT", "FLOAT", "STRING", "LPAREN", "RPAREN", 
  "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COLON", "SEMI", "COMMA", "DOT", 
  "ARROW", "ASSIGN", "LT", "GT", "LE", "GE", "EQ", "NE", "ADD", "SUB", "MUL", 
  "DIV", "MOD", "POW", "BITAND", "BITOR", "BITXOR", "BITNOT", "AND", "OR", 
  "NOT", "KWAS", "KWELSE", "KWEVENTSPEC", "KWFALSE", "KWFOR", "KWFROM", 
  "KWIF", "KWIMPORT", "KWIN", "KWNONE", "KWTRUE", "KWAND", "KWAXIOM", "KWCODING", 
  "KWLAMBDA", "KWLSYS", "KWNOT", "KWOR", "KWPRODUCTION", "KWRULES", "KWSET", 
  "KWTABLE", "KWTHEN", "QM", "XM", "DARROW", "FDIV", "DOLLARID", "RULECHAR", 
  "WS", "COMMENTBLQ", "COMMENTLIN", "LINE_JOINING", "NEW_LINE", "ERRORCHAR"
};

dfa::Vocabulary LSysDParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LSysDParser::_tokenNames;

LSysDParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x4a, 0x22f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x3, 0x2, 0x5, 
    0x2, 0x64, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x68, 0xa, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x6c, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 
    0x70, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x74, 0xa, 0x2, 0x5, 0x2, 
    0x76, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x7a, 0xa, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x5, 0x2, 0x7e, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 
    0x2, 0x83, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x87, 0xa, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x5, 0x2, 0x8b, 0xa, 0x2, 0x3, 0x3, 0x6, 0x3, 0x8e, 0xa, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0x8f, 0x3, 0x4, 0x6, 0x4, 0x93, 0xa, 0x4, 0xd, 
    0x4, 0xe, 0x4, 0x94, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x9d, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xa0, 0xb, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0xa3, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xad, 0xa, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0xcb, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0xd3, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0xd7, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0xdf, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xe3, 0xa, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x5, 0x10, 0xea, 
    0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xef, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0xf2, 0xb, 0x10, 0x3, 0x10, 0x5, 0x10, 0xf5, 0xa, 
    0x10, 0x3, 0x10, 0x5, 0x10, 0xf8, 0xa, 0x10, 0x3, 0x11, 0x5, 0x11, 0xfb, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x100, 0xa, 0x11, 
    0xc, 0x11, 0xe, 0x11, 0x103, 0xb, 0x11, 0x3, 0x11, 0x5, 0x11, 0x106, 
    0xa, 0x11, 0x3, 0x11, 0x5, 0x11, 0x109, 0xa, 0x11, 0x3, 0x12, 0x5, 0x12, 
    0x10c, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x111, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x114, 0xb, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x117, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 0x11a, 0xa, 0x12, 0x3, 0x13, 
    0x5, 0x13, 0x11d, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
    0x122, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x125, 0xb, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0x128, 0xa, 0x13, 0x3, 0x13, 0x5, 0x13, 0x12b, 0xa, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x12f, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0x133, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0x139, 0xa, 0x17, 0x3, 0x18, 0x5, 0x18, 0x13c, 0xa, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0x13f, 0xa, 0x18, 0x3, 0x18, 0x5, 0x18, 0x142, 
    0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x146, 0xa, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0x14a, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
    0x5, 0x19, 0x14f, 0xa, 0x19, 0x3, 0x19, 0x5, 0x19, 0x152, 0xa, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x155, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0x159, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x15d, 0xa, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x16d, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
    0x7, 0x1e, 0x172, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x175, 0xb, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x17b, 0xa, 0x1f, 
    0xc, 0x1f, 0xe, 0x1f, 0x17e, 0xb, 0x1f, 0x3, 0x20, 0x7, 0x20, 0x181, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x184, 0xb, 0x20, 0x3, 0x21, 0x7, 0x21, 
    0x187, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x18a, 0xb, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x191, 0xa, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x198, 
    0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x19c, 0xa, 0x23, 0xc, 0x23, 
    0xe, 0x23, 0x19f, 0xb, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1a2, 0xa, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1a9, 
    0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x1ad, 0xa, 0x24, 0xc, 0x24, 
    0xe, 0x24, 0x1b0, 0xb, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1b3, 0xa, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1be, 0xa, 0x28, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x1c3, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 
    0x1c6, 0xb, 0x29, 0x5, 0x29, 0x1c8, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x1d1, 
    0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x1d4, 0xb, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x1d7, 0xa, 0x2c, 0x5, 0x2c, 0x1d9, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1ef, 
    0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x214, 0xa, 0x2e, 
    0xc, 0x2e, 0xe, 0x2e, 0x217, 0xb, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
    0x7, 0x2f, 0x21c, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x21f, 0xb, 0x2f, 
    0x3, 0x2f, 0x5, 0x2f, 0x222, 0xa, 0x2f, 0x5, 0x2f, 0x224, 0xa, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x5, 0x31, 0x22d, 0xa, 0x31, 0x3, 0x31, 0x2, 0x3, 0x5a, 0x32, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x2, 
    0x9, 0x4, 0x2, 0x10, 0x10, 0x49, 0x49, 0x5, 0x2, 0x5, 0x6, 0x1b, 0x1c, 
    0x44, 0x44, 0x3, 0x2, 0x1b, 0x1c, 0x4, 0x2, 0x24, 0x24, 0x27, 0x27, 
    0x3, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x15, 0x18, 0x3, 0x2, 0x19, 0x1a, 0x2, 
    0x261, 0x2, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x92, 0x3, 0x2, 0x2, 0x2, 0x8, 0x96, 0x3, 0x2, 0x2, 0x2, 0xa, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0xac, 0x3, 0x2, 0x2, 0x2, 0xe, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x12, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x16, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x20, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x24, 0x11c, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x28, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x134, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x138, 0x3, 0x2, 0x2, 
    0x2, 0x2e, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x160, 0x3, 0x2, 0x2, 0x2, 0x34, 0x163, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x16c, 0x3, 0x2, 0x2, 0x2, 0x38, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x173, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x178, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x182, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x188, 0x3, 0x2, 0x2, 0x2, 0x42, 0x18b, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1b2, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1b6, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x1c7, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1cb, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1da, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x223, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x225, 0x3, 0x2, 0x2, 0x2, 0x60, 0x22c, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x64, 0x5, 0x4, 0x3, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x75, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x67, 0x5, 0x8, 0x5, 0x2, 0x66, 0x68, 0x5, 0x6, 0x4, 0x2, 0x67, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x6b, 0x7, 0xb, 0x2, 0x2, 0x6a, 0x6c, 0x5, 0x4, 
    0x3, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x5, 0xa, 0x6, 0x2, 
    0x6e, 0x70, 0x5, 0x4, 0x3, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x73, 
    0x7, 0xc, 0x2, 0x2, 0x72, 0x74, 0x5, 0x4, 0x3, 0x2, 0x73, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x65, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x8b, 0x7, 0x2, 0x2, 0x3, 
    0x78, 0x7a, 0x5, 0x4, 0x3, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 
    0x5, 0xa, 0x6, 0x2, 0x7c, 0x7e, 0x5, 0x4, 0x3, 0x2, 0x7d, 0x7c, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x80, 0x7, 0x2, 0x2, 0x3, 0x80, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x83, 0x5, 0x6, 0x4, 0x2, 0x82, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x86, 0x5, 0x40, 0x21, 0x2, 0x85, 0x87, 0x5, 0x6, 0x4, 0x2, 0x86, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x2, 0x2, 0x3, 0x89, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x63, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x82, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x8e, 0x9, 0x2, 0x2, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x5, 0x3, 0x2, 0x2, 0x2, 0x91, 0x93, 0x7, 
    0x49, 0x2, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x7, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x37, 0x2, 0x2, 
    0x97, 0x98, 0x7, 0x5, 0x2, 0x2, 0x98, 0x9, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x5, 0xc, 0x7, 0x2, 0x9a, 0x9b, 0x5, 0x4, 0x3, 0x2, 0x9b, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa3, 0x5, 0xc, 0x7, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xad, 0x5, 0xe, 0x8, 0x2, 0xa5, 0xad, 0x5, 0x10, 0x9, 0x2, 0xa6, 0xad, 
    0x5, 0x12, 0xa, 0x2, 0xa7, 0xad, 0x5, 0x16, 0xc, 0x2, 0xa8, 0xad, 0x5, 
    0x18, 0xd, 0x2, 0xa9, 0xad, 0x5, 0x1a, 0xe, 0x2, 0xaa, 0xad, 0x5, 0x1c, 
    0xf, 0x2, 0xab, 0xad, 0x5, 0x2c, 0x17, 0x2, 0xac, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xd, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 
    0x34, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x40, 0x21, 0x2, 0xb0, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0xb1, 0xb2, 0x7, 0x3c, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x5, 0x2, 
    0x2, 0xb3, 0xb4, 0x7, 0x14, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x5a, 0x2e, 0x2, 
    0xb5, 0x11, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x3c, 0x2, 0x2, 0xb7, 
    0xb8, 0x7, 0x5, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x9, 0x2, 0x2, 0xb9, 0xba, 
    0x5, 0x50, 0x29, 0x2, 0xba, 0xbb, 0x7, 0xa, 0x2, 0x2, 0xbb, 0xbc, 0x7, 
    0x14, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x5a, 0x2e, 0x2, 0xbd, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0xbf, 0x7, 0x43, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x14, 0x2, 
    0x2, 0xc0, 0xc1, 0x5, 0x5a, 0x2e, 0x2, 0xc1, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xc3, 0x7, 0x3d, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x5, 0x2, 0x2, 0xc4, 
    0xc5, 0x7, 0xb, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x1e, 0x10, 0x2, 0xc6, 0xc7, 
    0x7, 0xc, 0x2, 0x2, 0xc7, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 0x7, 
    0x3b, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0x6, 0x4, 0x2, 0xca, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xcd, 0x7, 0xb, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x20, 0x11, 0x2, 
    0xce, 0xcf, 0x7, 0xc, 0x2, 0x2, 0xcf, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd0, 
    0xd2, 0x7, 0x3a, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x6, 0x4, 0x2, 0xd2, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xd6, 0x7, 0x3b, 0x2, 0x2, 0xd5, 0xd7, 0x5, 0x6, 
    0x4, 0x2, 0xd6, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0xb, 0x2, 0x2, 
    0xd9, 0xda, 0x5, 0x20, 0x11, 0x2, 0xda, 0xdb, 0x7, 0xc, 0x2, 0x2, 0xdb, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xde, 0x7, 0x35, 0x2, 0x2, 0xdd, 0xdf, 
    0x5, 0x6, 0x4, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x7, 0x3b, 
    0x2, 0x2, 0xe1, 0xe3, 0x5, 0x6, 0x4, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe4, 0xe5, 0x7, 0xb, 0x2, 0x2, 0xe5, 0xe6, 0x5, 0x20, 0x11, 0x2, 0xe6, 
    0xe7, 0x7, 0xc, 0x2, 0x2, 0xe7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 
    0x5, 0x4, 0x3, 0x2, 0xe9, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x26, 
    0x14, 0x2, 0xec, 0xed, 0x5, 0x4, 0x3, 0x2, 0xed, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf5, 
    0x5, 0x26, 0x14, 0x2, 0xf4, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x5, 0x4, 
    0x3, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 0x5, 0x4, 0x3, 0x2, 
    0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0x2c, 0x17, 0x2, 0xfd, 0xfe, 
    0x5, 0x4, 0x3, 0x2, 0xfe, 0x100, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 
    0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x104, 0x106, 0x5, 0x2c, 
    0x17, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x108, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x5, 0x4, 
    0x3, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 
    0x2, 0x2, 0x109, 0x21, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x5, 0x4, 0x3, 
    0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x112, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x5, 0x2e, 0x18, 
    0x2, 0x10e, 0x10f, 0x5, 0x4, 0x3, 0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x110, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x116, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 
    0x2, 0x115, 0x117, 0x5, 0x2e, 0x18, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 0x3, 0x2, 0x2, 
    0x2, 0x118, 0x11a, 0x5, 0x4, 0x3, 0x2, 0x119, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x11b, 0x11d, 0x5, 0x4, 0x3, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x123, 0x3, 0x2, 0x2, 0x2, 
    0x11e, 0x11f, 0x5, 0x30, 0x19, 0x2, 0x11f, 0x120, 0x5, 0x4, 0x3, 0x2, 
    0x120, 0x122, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11e, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x125, 0x3, 0x2, 0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x123, 0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x123, 0x3, 0x2, 0x2, 0x2, 0x126, 0x128, 0x5, 0x30, 0x19, 0x2, 
    0x127, 0x126, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12b, 0x5, 0x4, 0x3, 0x2, 
    0x12a, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x25, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 0x5, 0x28, 0x15, 0x2, 
    0x12d, 0x12f, 0x5, 0x2a, 0x16, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x27, 0x3, 0x2, 0x2, 0x2, 0x130, 
    0x133, 0x5, 0x2e, 0x18, 0x2, 0x131, 0x133, 0x5, 0x34, 0x1b, 0x2, 0x132, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x5, 0x30, 0x19, 0x2, 0x135, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x136, 0x139, 0x5, 0x2e, 0x18, 0x2, 0x137, 
    0x139, 0x5, 0x30, 0x19, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13c, 
    0x5, 0x32, 0x1a, 0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13f, 
    0x5, 0x36, 0x1c, 0x2, 0x13e, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 
    0x3, 0x2, 0x2, 0x2, 0x13f, 0x141, 0x3, 0x2, 0x2, 0x2, 0x140, 0x142, 
    0x5, 0x3a, 0x1e, 0x2, 0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 
    0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x145, 
    0x5, 0x38, 0x1d, 0x2, 0x144, 0x146, 0x5, 0x3c, 0x1f, 0x2, 0x145, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x147, 0x149, 0x7, 0x13, 0x2, 0x2, 0x148, 0x14a, 
    0x5, 0x6, 0x4, 0x2, 0x149, 0x148, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 
    0x5, 0x3e, 0x20, 0x2, 0x14c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14f, 
    0x5, 0x32, 0x1a, 0x2, 0x14e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 
    0x3, 0x2, 0x2, 0x2, 0x14f, 0x151, 0x3, 0x2, 0x2, 0x2, 0x150, 0x152, 
    0x5, 0x36, 0x1c, 0x2, 0x151, 0x150, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 
    0x3, 0x2, 0x2, 0x2, 0x152, 0x154, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 
    0x5, 0x3a, 0x1e, 0x2, 0x154, 0x153, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 
    0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x158, 
    0x5, 0x38, 0x1d, 0x2, 0x157, 0x159, 0x5, 0x3c, 0x1f, 0x2, 0x158, 0x157, 
    0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 
    0x3, 0x2, 0x2, 0x2, 0x15a, 0x15c, 0x7, 0x41, 0x2, 0x2, 0x15b, 0x15d, 
    0x5, 0x6, 0x4, 0x2, 0x15c, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 
    0x5, 0x3e, 0x20, 0x2, 0x15f, 0x31, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 
    0x5, 0x34, 0x1b, 0x2, 0x161, 0x162, 0x7, 0xf, 0x2, 0x2, 0x162, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x7, 0x5, 0x2, 0x2, 0x164, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x165, 0x166, 0x7, 0x9, 0x2, 0x2, 0x166, 0x167, 0x7, 
    0x6, 0x2, 0x2, 0x167, 0x16d, 0x7, 0xa, 0x2, 0x2, 0x168, 0x169, 0x7, 
    0x9, 0x2, 0x2, 0x169, 0x16a, 0x7, 0x40, 0x2, 0x2, 0x16a, 0x16d, 0x7, 
    0xa, 0x2, 0x2, 0x16b, 0x16d, 0x7, 0x40, 0x2, 0x2, 0x16c, 0x165, 0x3, 
    0x2, 0x2, 0x2, 0x16c, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16b, 0x3, 
    0x2, 0x2, 0x2, 0x16d, 0x37, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x5, 0x42, 
    0x22, 0x2, 0x16f, 0x39, 0x3, 0x2, 0x2, 0x2, 0x170, 0x172, 0x5, 0x44, 
    0x23, 0x2, 0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 0x175, 0x3, 0x2, 
    0x2, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x3, 0x2, 
    0x2, 0x2, 0x174, 0x176, 0x3, 0x2, 0x2, 0x2, 0x175, 0x173, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x177, 0x7, 0x15, 0x2, 0x2, 0x177, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x178, 0x17c, 0x7, 0x16, 0x2, 0x2, 0x179, 0x17b, 0x5, 0x44, 
    0x23, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x181, 0x5, 0x46, 0x24, 0x2, 0x180, 0x17f, 0x3, 0x2, 0x2, 
    0x2, 0x181, 0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 
    0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x187, 0x5, 0x46, 0x24, 0x2, 
    0x186, 0x185, 0x3, 0x2, 0x2, 0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 0x2, 
    0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 
    0x189, 0x41, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 
    0x190, 0x5, 0x48, 0x25, 0x2, 0x18c, 0x18d, 0x7, 0x9, 0x2, 0x2, 0x18d, 
    0x18e, 0x5, 0x4e, 0x28, 0x2, 0x18e, 0x18f, 0x7, 0xa, 0x2, 0x2, 0x18f, 
    0x191, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x190, 
    0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 0x43, 0x3, 0x2, 0x2, 0x2, 0x192, 0x197, 
    0x5, 0x48, 0x25, 0x2, 0x193, 0x194, 0x7, 0x9, 0x2, 0x2, 0x194, 0x195, 
    0x5, 0x4e, 0x28, 0x2, 0x195, 0x196, 0x7, 0xa, 0x2, 0x2, 0x196, 0x198, 
    0x3, 0x2, 0x2, 0x2, 0x197, 0x193, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 
    0x3, 0x2, 0x2, 0x2, 0x198, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19d, 
    0x7, 0xd, 0x2, 0x2, 0x19a, 0x19c, 0x5, 0x44, 0x23, 0x2, 0x19b, 0x19a, 
    0x3, 0x2, 0x2, 0x2, 0x19c, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 
    0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a0, 
    0x3, 0x2, 0x2, 0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a2, 
    0x7, 0xe, 0x2, 0x2, 0x1a1, 0x192, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x199, 
    0x3, 0x2, 0x2, 0x2, 0x1a2, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a8, 0x5, 
    0x4a, 0x26, 0x2, 0x1a4, 0x1a5, 0x7, 0x9, 0x2, 0x2, 0x1a5, 0x1a6, 0x5, 
    0x56, 0x2c, 0x2, 0x1a6, 0x1a7, 0x7, 0xa, 0x2, 0x2, 0x1a7, 0x1a9, 0x3, 
    0x2, 0x2, 0x2, 0x1a8, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x3, 
    0x2, 0x2, 0x2, 0x1a9, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ae, 0x7, 
    0xd, 0x2, 0x2, 0x1ab, 0x1ad, 0x5, 0x46, 0x24, 0x2, 0x1ac, 0x1ab, 0x3, 
    0x2, 0x2, 0x2, 0x1ad, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1ac, 0x3, 
    0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b1, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b3, 0x7, 
    0xe, 0x2, 0x2, 0x1b2, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1aa, 0x3, 
    0x2, 0x2, 0x2, 0x1b3, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x4c, 
    0x27, 0x2, 0x1b5, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x4c, 
    0x27, 0x2, 0x1b7, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x9, 0x3, 
    0x2, 0x2, 0x1b9, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bd, 0x5, 0x50, 
    0x29, 0x2, 0x1bb, 0x1bc, 0x7, 0x22, 0x2, 0x2, 0x1bc, 0x1be, 0x5, 0x54, 
    0x2b, 0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x3, 0x2, 
    0x2, 0x2, 0x1be, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c4, 0x5, 0x52, 
    0x2a, 0x2, 0x1c0, 0x1c1, 0x7, 0x11, 0x2, 0x2, 0x1c1, 0x1c3, 0x5, 0x52, 
    0x2a, 0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c6, 0x3, 0x2, 
    0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 
    0x2, 0x2, 0x1c5, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c4, 0x3, 0x2, 
    0x2, 0x2, 0x1c7, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 0x2, 
    0x2, 0x2, 0x1c8, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x7, 0x5, 0x2, 
    0x2, 0x1ca, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 0x5, 0x5a, 0x2e, 
    0x2, 0x1cc, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1d2, 0x5, 0x58, 0x2d, 
    0x2, 0x1ce, 0x1cf, 0x7, 0x11, 0x2, 0x2, 0x1cf, 0x1d1, 0x5, 0x58, 0x2d, 
    0x2, 0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d4, 0x3, 0x2, 0x2, 
    0x2, 0x1d2, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x3, 0x2, 0x2, 
    0x2, 0x1d3, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 
    0x2, 0x1d5, 0x1d7, 0x7, 0x11, 0x2, 0x2, 0x1d6, 0x1d5, 0x3, 0x2, 0x2, 
    0x2, 0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d9, 0x3, 0x2, 0x2, 
    0x2, 0x1d8, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 0x2, 0x2, 
    0x2, 0x1d9, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 0x5, 0x5a, 0x2e, 
    0x2, 0x1db, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x8, 0x2e, 0x1, 
    0x2, 0x1dd, 0x1de, 0x7, 0x9, 0x2, 0x2, 0x1de, 0x1df, 0x5, 0x5a, 0x2e, 
    0x2, 0x1df, 0x1e0, 0x7, 0xa, 0x2, 0x2, 0x1e0, 0x1ef, 0x3, 0x2, 0x2, 
    0x2, 0x1e1, 0x1ef, 0x5, 0x60, 0x31, 0x2, 0x1e2, 0x1ef, 0x7, 0x5, 0x2, 
    0x2, 0x1e3, 0x1e4, 0x9, 0x4, 0x2, 0x2, 0x1e4, 0x1ef, 0x5, 0x5a, 0x2e, 
    0xf, 0x1e5, 0x1e6, 0x9, 0x5, 0x2, 0x2, 0x1e6, 0x1ef, 0x5, 0x5a, 0x2e, 
    0xe, 0x1e7, 0x1e8, 0x7, 0x2e, 0x2, 0x2, 0x1e8, 0x1e9, 0x5, 0x5a, 0x2e, 
    0x2, 0x1e9, 0x1ea, 0x7, 0x3e, 0x2, 0x2, 0x1ea, 0x1eb, 0x5, 0x5a, 0x2e, 
    0x2, 0x1eb, 0x1ec, 0x7, 0x29, 0x2, 0x2, 0x1ec, 0x1ed, 0x5, 0x5a, 0x2e, 
    0x3, 0x1ed, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1dc, 0x3, 0x2, 0x2, 
    0x2, 0x1ee, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1e2, 0x3, 0x2, 0x2, 
    0x2, 0x1ee, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1e5, 0x3, 0x2, 0x2, 
    0x2, 0x1ee, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x215, 0x3, 0x2, 0x2, 
    0x2, 0x1f0, 0x1f1, 0xc, 0xd, 0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x20, 0x2, 
    0x2, 0x1f2, 0x214, 0x5, 0x5a, 0x2e, 0xd, 0x1f3, 0x1f4, 0xc, 0xc, 0x2, 
    0x2, 0x1f4, 0x1f5, 0x9, 0x6, 0x2, 0x2, 0x1f5, 0x214, 0x5, 0x5a, 0x2e, 
    0xd, 0x1f6, 0x1f7, 0xc, 0xb, 0x2, 0x2, 0x1f7, 0x1f8, 0x9, 0x4, 0x2, 
    0x2, 0x1f8, 0x214, 0x5, 0x5a, 0x2e, 0xc, 0x1f9, 0x1fa, 0xc, 0xa, 0x2, 
    0x2, 0x1fa, 0x1fb, 0x9, 0x7, 0x2, 0x2, 0x1fb, 0x214, 0x5, 0x5a, 0x2e, 
    0xb, 0x1fc, 0x1fd, 0xc, 0x9, 0x2, 0x2, 0x1fd, 0x1fe, 0x9, 0x8, 0x2, 
    0x2, 0x1fe, 0x214, 0x5, 0x5a, 0x2e, 0xa, 0x1ff, 0x200, 0xc, 0x8, 0x2, 
    0x2, 0x200, 0x201, 0x7, 0x21, 0x2, 0x2, 0x201, 0x214, 0x5, 0x5a, 0x2e, 
    0x9, 0x202, 0x203, 0xc, 0x7, 0x2, 0x2, 0x203, 0x204, 0x7, 0x23, 0x2, 
    0x2, 0x204, 0x214, 0x5, 0x5a, 0x2e, 0x8, 0x205, 0x206, 0xc, 0x6, 0x2, 
    0x2, 0x206, 0x207, 0x7, 0x22, 0x2, 0x2, 0x207, 0x214, 0x5, 0x5a, 0x2e, 
    0x7, 0x208, 0x209, 0xc, 0x5, 0x2, 0x2, 0x209, 0x20a, 0x7, 0x25, 0x2, 
    0x2, 0x20a, 0x214, 0x5, 0x5a, 0x2e, 0x6, 0x20b, 0x20c, 0xc, 0x4, 0x2, 
    0x2, 0x20c, 0x20d, 0x7, 0x26, 0x2, 0x2, 0x20d, 0x214, 0x5, 0x5a, 0x2e, 
    0x5, 0x20e, 0x20f, 0xc, 0x10, 0x2, 0x2, 0x20f, 0x210, 0x7, 0x9, 0x2, 
    0x2, 0x210, 0x211, 0x5, 0x5c, 0x2f, 0x2, 0x211, 0x212, 0x7, 0xa, 0x2, 
    0x2, 0x212, 0x214, 0x3, 0x2, 0x2, 0x2, 0x213, 0x1f0, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x213, 0x1f6, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x213, 0x1fc, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x213, 0x202, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x205, 0x3, 0x2, 0x2, 0x2, 0x213, 0x208, 0x3, 0x2, 0x2, 
    0x2, 0x213, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x213, 0x20e, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x217, 0x3, 0x2, 0x2, 0x2, 0x215, 0x213, 0x3, 0x2, 0x2, 
    0x2, 0x215, 0x216, 0x3, 0x2, 0x2, 0x2, 0x216, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21d, 0x5, 0x5e, 0x30, 0x2, 
    0x219, 0x21a, 0x7, 0x11, 0x2, 0x2, 0x21a, 0x21c, 0x5, 0x5e, 0x30, 0x2, 
    0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21f, 0x3, 0x2, 0x2, 0x2, 
    0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21e, 0x3, 0x2, 0x2, 0x2, 
    0x21e, 0x221, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x21d, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x222, 0x7, 0x11, 0x2, 0x2, 0x221, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x222, 0x3, 0x2, 0x2, 0x2, 0x222, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x218, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x224, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x5, 0x5a, 0x2e, 0x2, 
    0x226, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x227, 0x22d, 0x7, 0x6, 0x2, 0x2, 0x228, 
    0x22d, 0x7, 0x7, 0x2, 0x2, 0x229, 0x22d, 0x7, 0x8, 0x2, 0x2, 0x22a, 
    0x22d, 0x7, 0x32, 0x2, 0x2, 0x22b, 0x22d, 0x7, 0x2b, 0x2, 0x2, 0x22c, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x22b, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x61, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x63, 
    0x67, 0x6b, 0x6f, 0x73, 0x75, 0x79, 0x7d, 0x82, 0x86, 0x8a, 0x8f, 0x94, 
    0x9e, 0xa2, 0xac, 0xca, 0xd2, 0xd6, 0xde, 0xe2, 0xe9, 0xf0, 0xf4, 0xf7, 
    0xfa, 0x101, 0x105, 0x108, 0x10b, 0x112, 0x116, 0x119, 0x11c, 0x123, 
    0x127, 0x12a, 0x12e, 0x132, 0x138, 0x13b, 0x13e, 0x141, 0x145, 0x149, 
    0x14e, 0x151, 0x154, 0x158, 0x15c, 0x16c, 0x173, 0x17c, 0x182, 0x188, 
    0x190, 0x197, 0x19d, 0x1a1, 0x1a8, 0x1ae, 0x1b2, 0x1bd, 0x1c4, 0x1c7, 
    0x1d2, 0x1d6, 0x1d8, 0x1ee, 0x213, 0x215, 0x21d, 0x221, 0x223, 0x22c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LSysDParser::Initializer LSysDParser::_init;
