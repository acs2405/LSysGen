
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

LSysDParser::ModuleContext* LSysDParser::MainContext::module() {
  return getRuleContext<LSysDParser::ModuleContext>(0);
}

tree::TerminalNode* LSysDParser::MainContext::EOF() {
  return getToken(LSysDParser::EOF, 0);
}

LSysDParser::InLsysDefsContext* LSysDParser::MainContext::inLsysDefs() {
  return getRuleContext<LSysDParser::InLsysDefsContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(120);
      module();
      setState(121);
      match(LSysDParser::EOF);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(123);
      inLsysDefs();
      setState(124);
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

//----------------- ModuleContext ------------------------------------------------------------------

LSysDParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::GlobalDefsContext* LSysDParser::ModuleContext::globalDefs() {
  return getRuleContext<LSysDParser::GlobalDefsContext>(0);
}


size_t LSysDParser::ModuleContext::getRuleIndex() const {
  return LSysDParser::RuleModule;
}

antlrcpp::Any LSysDParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ModuleContext* LSysDParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 2, LSysDParser::RuleModule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    globalDefs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalDefsContext ------------------------------------------------------------------

LSysDParser::GlobalDefsContext::GlobalDefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::SepContext *> LSysDParser::GlobalDefsContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::GlobalDefsContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

std::vector<LSysDParser::GlobalDefContext *> LSysDParser::GlobalDefsContext::globalDef() {
  return getRuleContexts<LSysDParser::GlobalDefContext>();
}

LSysDParser::GlobalDefContext* LSysDParser::GlobalDefsContext::globalDef(size_t i) {
  return getRuleContext<LSysDParser::GlobalDefContext>(i);
}


size_t LSysDParser::GlobalDefsContext::getRuleIndex() const {
  return LSysDParser::RuleGlobalDefs;
}

antlrcpp::Any LSysDParser::GlobalDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitGlobalDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::GlobalDefsContext* LSysDParser::globalDefs() {
  GlobalDefsContext *_localctx = _tracker.createInstance<GlobalDefsContext>(_ctx, getState());
  enterRule(_localctx, 4, LSysDParser::RuleGlobalDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(131);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(130);
      sep();
      break;
    }

    }
    setState(138);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(133);
        globalDef();
        setState(134);
        sep(); 
      }
      setState(140);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 53) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 53)) & ((1ULL << (LSysDParser::KWFUNCTION - 53))
      | (1ULL << (LSysDParser::KWLSYS - 53))
      | (1ULL << (LSysDParser::KWMAIN - 53))
      | (1ULL << (LSysDParser::KWSET - 53))
      | (1ULL << (LSysDParser::KWVAR - 53)))) != 0)) {
      setState(141);
      globalDef();
    }
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(144);
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

//----------------- GlobalDefContext ------------------------------------------------------------------

LSysDParser::GlobalDefContext::GlobalDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::LsystemContext* LSysDParser::GlobalDefContext::lsystem() {
  return getRuleContext<LSysDParser::LsystemContext>(0);
}

LSysDParser::DeclarationContext* LSysDParser::GlobalDefContext::declaration() {
  return getRuleContext<LSysDParser::DeclarationContext>(0);
}

LSysDParser::FuncDefContext* LSysDParser::GlobalDefContext::funcDef() {
  return getRuleContext<LSysDParser::FuncDefContext>(0);
}


size_t LSysDParser::GlobalDefContext::getRuleIndex() const {
  return LSysDParser::RuleGlobalDef;
}

antlrcpp::Any LSysDParser::GlobalDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitGlobalDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::GlobalDefContext* LSysDParser::globalDef() {
  GlobalDefContext *_localctx = _tracker.createInstance<GlobalDefContext>(_ctx, getState());
  enterRule(_localctx, 6, LSysDParser::RuleGlobalDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::KWLSYS:
      case LSysDParser::KWMAIN: {
        enterOuterAlt(_localctx, 1);
        setState(147);
        lsystem();
        break;
      }

      case LSysDParser::KWSET:
      case LSysDParser::KWVAR: {
        enterOuterAlt(_localctx, 2);
        setState(148);
        declaration();
        break;
      }

      case LSysDParser::KWFUNCTION: {
        enterOuterAlt(_localctx, 3);
        setState(149);
        funcDef();
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

//----------------- DeclarationContext ------------------------------------------------------------------

LSysDParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::VarDeclarationContext* LSysDParser::DeclarationContext::varDeclaration() {
  return getRuleContext<LSysDParser::VarDeclarationContext>(0);
}

LSysDParser::ConstDeclarationContext* LSysDParser::DeclarationContext::constDeclaration() {
  return getRuleContext<LSysDParser::ConstDeclarationContext>(0);
}


size_t LSysDParser::DeclarationContext::getRuleIndex() const {
  return LSysDParser::RuleDeclaration;
}

antlrcpp::Any LSysDParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::DeclarationContext* LSysDParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, LSysDParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::KWVAR: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        varDeclaration();
        break;
      }

      case LSysDParser::KWSET: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        constDeclaration();
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

//----------------- VarDeclarationContext ------------------------------------------------------------------

LSysDParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::VarDeclarationContext::KWVAR() {
  return getToken(LSysDParser::KWVAR, 0);
}

tree::TerminalNode* LSysDParser::VarDeclarationContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::VarDeclarationContext::ASSIGN() {
  return getToken(LSysDParser::ASSIGN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::VarDeclarationContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::VarDeclarationContext::getRuleIndex() const {
  return LSysDParser::RuleVarDeclaration;
}

antlrcpp::Any LSysDParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::VarDeclarationContext* LSysDParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, LSysDParser::RuleVarDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(LSysDParser::KWVAR);
    setState(157);
    match(LSysDParser::ID);

    setState(158);
    match(LSysDParser::ASSIGN);
    setState(159);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclarationContext ------------------------------------------------------------------

LSysDParser::ConstDeclarationContext::ConstDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::ConstDeclarationContext::KWSET() {
  return getToken(LSysDParser::KWSET, 0);
}

tree::TerminalNode* LSysDParser::ConstDeclarationContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::ConstDeclarationContext::ASSIGN() {
  return getToken(LSysDParser::ASSIGN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::ConstDeclarationContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::ConstDeclarationContext::getRuleIndex() const {
  return LSysDParser::RuleConstDeclaration;
}

antlrcpp::Any LSysDParser::ConstDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitConstDeclaration(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ConstDeclarationContext* LSysDParser::constDeclaration() {
  ConstDeclarationContext *_localctx = _tracker.createInstance<ConstDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, LSysDParser::RuleConstDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(LSysDParser::KWSET);
    setState(162);
    match(LSysDParser::ID);
    setState(163);
    match(LSysDParser::ASSIGN);
    setState(164);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LsystemContext ------------------------------------------------------------------

LSysDParser::LsystemContext::LsystemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::LsystemContext::KWLSYS() {
  return getToken(LSysDParser::KWLSYS, 0);
}

tree::TerminalNode* LSysDParser::LsystemContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::LsystemContext::LBRACE() {
  return getToken(LSysDParser::LBRACE, 0);
}

LSysDParser::InLsysDefsContext* LSysDParser::LsystemContext::inLsysDefs() {
  return getRuleContext<LSysDParser::InLsysDefsContext>(0);
}

tree::TerminalNode* LSysDParser::LsystemContext::RBRACE() {
  return getToken(LSysDParser::RBRACE, 0);
}

tree::TerminalNode* LSysDParser::LsystemContext::KWMAIN() {
  return getToken(LSysDParser::KWMAIN, 0);
}

LSysDParser::NlContext* LSysDParser::LsystemContext::nl() {
  return getRuleContext<LSysDParser::NlContext>(0);
}


size_t LSysDParser::LsystemContext::getRuleIndex() const {
  return LSysDParser::RuleLsystem;
}

antlrcpp::Any LSysDParser::LsystemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLsystem(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LsystemContext* LSysDParser::lsystem() {
  LsystemContext *_localctx = _tracker.createInstance<LsystemContext>(_ctx, getState());
  enterRule(_localctx, 14, LSysDParser::RuleLsystem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::KWMAIN) {
      setState(166);
      match(LSysDParser::KWMAIN);
    }
    setState(169);
    match(LSysDParser::KWLSYS);
    setState(170);
    match(LSysDParser::ID);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(171);
      nl();
    }
    setState(174);
    match(LSysDParser::LBRACE);
    setState(175);
    inLsysDefs();
    setState(176);
    match(LSysDParser::RBRACE);
   
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
  enterRule(_localctx, 16, LSysDParser::RuleSep);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(179); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(178);
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
      setState(181); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
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
  enterRule(_localctx, 18, LSysDParser::RuleNl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(184); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(183);
              match(LSysDParser::NEW_LINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(186); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InLsysDefsContext ------------------------------------------------------------------

LSysDParser::InLsysDefsContext::InLsysDefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LSysDParser::SepContext *> LSysDParser::InLsysDefsContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::InLsysDefsContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

std::vector<LSysDParser::InLsysDefContext *> LSysDParser::InLsysDefsContext::inLsysDef() {
  return getRuleContexts<LSysDParser::InLsysDefContext>();
}

LSysDParser::InLsysDefContext* LSysDParser::InLsysDefsContext::inLsysDef(size_t i) {
  return getRuleContext<LSysDParser::InLsysDefContext>(i);
}


size_t LSysDParser::InLsysDefsContext::getRuleIndex() const {
  return LSysDParser::RuleInLsysDefs;
}

antlrcpp::Any LSysDParser::InLsysDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitInLsysDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::InLsysDefsContext* LSysDParser::inLsysDefs() {
  InLsysDefsContext *_localctx = _tracker.createInstance<InLsysDefsContext>(_ctx, getState());
  enterRule(_localctx, 20, LSysDParser::RuleInLsysDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(188);
      sep();
      break;
    }

    }
    setState(196);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(191);
        inLsysDef();
        setState(192);
        sep(); 
      }
      setState(198);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(200);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(199);
      inLsysDef();
      break;
    }

    }
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(202);
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

//----------------- InLsysDefContext ------------------------------------------------------------------

LSysDParser::InLsysDefContext::InLsysDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::AxiomDefContext* LSysDParser::InLsysDefContext::axiomDef() {
  return getRuleContext<LSysDParser::AxiomDefContext>(0);
}

LSysDParser::StatementContext* LSysDParser::InLsysDefContext::statement() {
  return getRuleContext<LSysDParser::StatementContext>(0);
}

LSysDParser::FuncDefContext* LSysDParser::InLsysDefContext::funcDef() {
  return getRuleContext<LSysDParser::FuncDefContext>(0);
}

LSysDParser::TableBlockContext* LSysDParser::InLsysDefContext::tableBlock() {
  return getRuleContext<LSysDParser::TableBlockContext>(0);
}

LSysDParser::RulesBlockContext* LSysDParser::InLsysDefContext::rulesBlock() {
  return getRuleContext<LSysDParser::RulesBlockContext>(0);
}

LSysDParser::ProductionRulesBlockContext* LSysDParser::InLsysDefContext::productionRulesBlock() {
  return getRuleContext<LSysDParser::ProductionRulesBlockContext>(0);
}

LSysDParser::CodingRulesBlockContext* LSysDParser::InLsysDefContext::codingRulesBlock() {
  return getRuleContext<LSysDParser::CodingRulesBlockContext>(0);
}

LSysDParser::RuleDefContext* LSysDParser::InLsysDefContext::ruleDef() {
  return getRuleContext<LSysDParser::RuleDefContext>(0);
}


size_t LSysDParser::InLsysDefContext::getRuleIndex() const {
  return LSysDParser::RuleInLsysDef;
}

antlrcpp::Any LSysDParser::InLsysDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitInLsysDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::InLsysDefContext* LSysDParser::inLsysDef() {
  InLsysDefContext *_localctx = _tracker.createInstance<InLsysDefContext>(_ctx, getState());
  enterRule(_localctx, 22, LSysDParser::RuleInLsysDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(205);
      axiomDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(206);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(207);
      funcDef();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(208);
      tableBlock();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(209);
      rulesBlock();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(210);
      productionRulesBlock();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(211);
      codingRulesBlock();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(212);
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

//----------------- BlockOrOneStatementContext ------------------------------------------------------------------

LSysDParser::BlockOrOneStatementContext::BlockOrOneStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::BlockContext* LSysDParser::BlockOrOneStatementContext::block() {
  return getRuleContext<LSysDParser::BlockContext>(0);
}

LSysDParser::OneStatementContext* LSysDParser::BlockOrOneStatementContext::oneStatement() {
  return getRuleContext<LSysDParser::OneStatementContext>(0);
}


size_t LSysDParser::BlockOrOneStatementContext::getRuleIndex() const {
  return LSysDParser::RuleBlockOrOneStatement;
}

antlrcpp::Any LSysDParser::BlockOrOneStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitBlockOrOneStatement(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::BlockOrOneStatementContext* LSysDParser::blockOrOneStatement() {
  BlockOrOneStatementContext *_localctx = _tracker.createInstance<BlockOrOneStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, LSysDParser::RuleBlockOrOneStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(215);
        block();
        break;
      }

      case LSysDParser::ID:
      case LSysDParser::INT:
      case LSysDParser::FLOAT:
      case LSysDParser::STRING:
      case LSysDParser::LPAREN:
      case LSysDParser::ADD:
      case LSysDParser::SUB:
      case LSysDParser::BITNOT:
      case LSysDParser::NOT:
      case LSysDParser::KWFALSE:
      case LSysDParser::KWIF:
      case LSysDParser::KWTRUE:
      case LSysDParser::KWDO:
      case LSysDParser::KWNULL:
      case LSysDParser::KWRETURN:
      case LSysDParser::KWSET:
      case LSysDParser::KWVAR:
      case LSysDParser::KWWHILE: {
        enterOuterAlt(_localctx, 2);
        setState(216);
        oneStatement();
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

//----------------- BlockContext ------------------------------------------------------------------

LSysDParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::BlockContext::LBRACE() {
  return getToken(LSysDParser::LBRACE, 0);
}

tree::TerminalNode* LSysDParser::BlockContext::RBRACE() {
  return getToken(LSysDParser::RBRACE, 0);
}

LSysDParser::StatementContext* LSysDParser::BlockContext::statement() {
  return getRuleContext<LSysDParser::StatementContext>(0);
}


size_t LSysDParser::BlockContext::getRuleIndex() const {
  return LSysDParser::RuleBlock;
}

antlrcpp::Any LSysDParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::BlockContext* LSysDParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, LSysDParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(LSysDParser::LBRACE);
    setState(221);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::FLOAT)
      | (1ULL << LSysDParser::STRING)
      | (1ULL << LSysDParser::LPAREN)
      | (1ULL << LSysDParser::SEMI)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB)
      | (1ULL << LSysDParser::BITNOT)
      | (1ULL << LSysDParser::NOT)
      | (1ULL << LSysDParser::KWFALSE)
      | (1ULL << LSysDParser::KWIF)
      | (1ULL << LSysDParser::KWTRUE)
      | (1ULL << LSysDParser::KWDO)
      | (1ULL << LSysDParser::KWNULL)
      | (1ULL << LSysDParser::KWRETURN)
      | (1ULL << LSysDParser::KWSET))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (LSysDParser::KWVAR - 65))
      | (1ULL << (LSysDParser::KWWHILE - 65))
      | (1ULL << (LSysDParser::NEW_LINE - 65)))) != 0)) {
      setState(220);
      statement();
    }
    setState(223);
    match(LSysDParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OneStatementContext ------------------------------------------------------------------

LSysDParser::OneStatementContext::OneStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::OneStmtNeedsSepContext* LSysDParser::OneStatementContext::oneStmtNeedsSep() {
  return getRuleContext<LSysDParser::OneStmtNeedsSepContext>(0);
}

LSysDParser::OneStmtEndsInBlockContext* LSysDParser::OneStatementContext::oneStmtEndsInBlock() {
  return getRuleContext<LSysDParser::OneStmtEndsInBlockContext>(0);
}


size_t LSysDParser::OneStatementContext::getRuleIndex() const {
  return LSysDParser::RuleOneStatement;
}

antlrcpp::Any LSysDParser::OneStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitOneStatement(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::OneStatementContext* LSysDParser::oneStatement() {
  OneStatementContext *_localctx = _tracker.createInstance<OneStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, LSysDParser::RuleOneStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(225);
      oneStmtNeedsSep();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(226);
      oneStmtEndsInBlock();
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

//----------------- OneStmtNeedsSepContext ------------------------------------------------------------------

LSysDParser::OneStmtNeedsSepContext::OneStmtNeedsSepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::ExpressionContext* LSysDParser::OneStmtNeedsSepContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}

LSysDParser::AssignmentContext* LSysDParser::OneStmtNeedsSepContext::assignment() {
  return getRuleContext<LSysDParser::AssignmentContext>(0);
}

LSysDParser::DeclarationContext* LSysDParser::OneStmtNeedsSepContext::declaration() {
  return getRuleContext<LSysDParser::DeclarationContext>(0);
}

tree::TerminalNode* LSysDParser::OneStmtNeedsSepContext::KWRETURN() {
  return getToken(LSysDParser::KWRETURN, 0);
}

tree::TerminalNode* LSysDParser::OneStmtNeedsSepContext::KWIF() {
  return getToken(LSysDParser::KWIF, 0);
}

tree::TerminalNode* LSysDParser::OneStmtNeedsSepContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

tree::TerminalNode* LSysDParser::OneStmtNeedsSepContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

LSysDParser::OneStmtNeedsSepContext* LSysDParser::OneStmtNeedsSepContext::oneStmtNeedsSep() {
  return getRuleContext<LSysDParser::OneStmtNeedsSepContext>(0);
}

std::vector<LSysDParser::NlContext *> LSysDParser::OneStmtNeedsSepContext::nl() {
  return getRuleContexts<LSysDParser::NlContext>();
}

LSysDParser::NlContext* LSysDParser::OneStmtNeedsSepContext::nl(size_t i) {
  return getRuleContext<LSysDParser::NlContext>(i);
}

LSysDParser::BlockOrOneStatementContext* LSysDParser::OneStmtNeedsSepContext::blockOrOneStatement() {
  return getRuleContext<LSysDParser::BlockOrOneStatementContext>(0);
}

tree::TerminalNode* LSysDParser::OneStmtNeedsSepContext::KWELSE() {
  return getToken(LSysDParser::KWELSE, 0);
}

tree::TerminalNode* LSysDParser::OneStmtNeedsSepContext::KWWHILE() {
  return getToken(LSysDParser::KWWHILE, 0);
}

tree::TerminalNode* LSysDParser::OneStmtNeedsSepContext::KWDO() {
  return getToken(LSysDParser::KWDO, 0);
}


size_t LSysDParser::OneStmtNeedsSepContext::getRuleIndex() const {
  return LSysDParser::RuleOneStmtNeedsSep;
}

antlrcpp::Any LSysDParser::OneStmtNeedsSepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitOneStmtNeedsSep(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::OneStmtNeedsSepContext* LSysDParser::oneStmtNeedsSep() {
  OneStmtNeedsSepContext *_localctx = _tracker.createInstance<OneStmtNeedsSepContext>(_ctx, getState());
  enterRule(_localctx, 30, LSysDParser::RuleOneStmtNeedsSep);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(229);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(230);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(231);
      declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(232);
      match(LSysDParser::KWRETURN);
      setState(234);
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
        | (1ULL << LSysDParser::KWTRUE)
        | (1ULL << LSysDParser::KWNULL))) != 0)) {
        setState(233);
        expression(0);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(236);
      match(LSysDParser::KWIF);
      setState(238);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(237);
        nl();
      }
      setState(240);
      match(LSysDParser::LPAREN);
      setState(242);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(241);
        nl();
      }
      setState(244);
      expression(0);
      setState(246);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(245);
        nl();
      }
      setState(248);
      match(LSysDParser::RPAREN);
      setState(250);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(249);
        nl();
      }
      setState(252);
      oneStmtNeedsSep();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(254);
      match(LSysDParser::KWIF);
      setState(256);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(255);
        nl();
      }
      setState(258);
      match(LSysDParser::LPAREN);
      setState(260);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(259);
        nl();
      }
      setState(262);
      expression(0);
      setState(264);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(263);
        nl();
      }
      setState(266);
      match(LSysDParser::RPAREN);
      setState(268);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(267);
        nl();
      }
      setState(270);
      blockOrOneStatement();
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(271);
        nl();
      }
      setState(274);
      match(LSysDParser::KWELSE);
      setState(276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(275);
        nl();
      }
      setState(278);
      oneStmtNeedsSep();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(280);
      match(LSysDParser::KWWHILE);
      setState(282);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(281);
        nl();
      }
      setState(284);
      match(LSysDParser::LPAREN);
      setState(286);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(285);
        nl();
      }
      setState(288);
      expression(0);
      setState(290);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(289);
        nl();
      }
      setState(292);
      match(LSysDParser::RPAREN);
      setState(294);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(293);
        nl();
      }
      setState(296);
      oneStmtNeedsSep();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(298);
      match(LSysDParser::KWDO);
      setState(300);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(299);
        nl();
      }
      setState(302);
      blockOrOneStatement();
      setState(304);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(303);
        nl();
      }
      setState(306);
      match(LSysDParser::KWWHILE);
      setState(308);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(307);
        nl();
      }
      setState(310);
      match(LSysDParser::LPAREN);
      setState(312);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(311);
        nl();
      }
      setState(314);
      expression(0);
      setState(316);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(315);
        nl();
      }
      setState(318);
      match(LSysDParser::RPAREN);
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

//----------------- OneStmtEndsInBlockContext ------------------------------------------------------------------

LSysDParser::OneStmtEndsInBlockContext::OneStmtEndsInBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::OneStmtEndsInBlockContext::KWIF() {
  return getToken(LSysDParser::KWIF, 0);
}

tree::TerminalNode* LSysDParser::OneStmtEndsInBlockContext::LPAREN() {
  return getToken(LSysDParser::LPAREN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::OneStmtEndsInBlockContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}

tree::TerminalNode* LSysDParser::OneStmtEndsInBlockContext::RPAREN() {
  return getToken(LSysDParser::RPAREN, 0);
}

LSysDParser::BlockContext* LSysDParser::OneStmtEndsInBlockContext::block() {
  return getRuleContext<LSysDParser::BlockContext>(0);
}

std::vector<LSysDParser::NlContext *> LSysDParser::OneStmtEndsInBlockContext::nl() {
  return getRuleContexts<LSysDParser::NlContext>();
}

LSysDParser::NlContext* LSysDParser::OneStmtEndsInBlockContext::nl(size_t i) {
  return getRuleContext<LSysDParser::NlContext>(i);
}

LSysDParser::BlockOrOneStatementContext* LSysDParser::OneStmtEndsInBlockContext::blockOrOneStatement() {
  return getRuleContext<LSysDParser::BlockOrOneStatementContext>(0);
}

tree::TerminalNode* LSysDParser::OneStmtEndsInBlockContext::KWELSE() {
  return getToken(LSysDParser::KWELSE, 0);
}

tree::TerminalNode* LSysDParser::OneStmtEndsInBlockContext::KWWHILE() {
  return getToken(LSysDParser::KWWHILE, 0);
}


size_t LSysDParser::OneStmtEndsInBlockContext::getRuleIndex() const {
  return LSysDParser::RuleOneStmtEndsInBlock;
}

antlrcpp::Any LSysDParser::OneStmtEndsInBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitOneStmtEndsInBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::OneStmtEndsInBlockContext* LSysDParser::oneStmtEndsInBlock() {
  OneStmtEndsInBlockContext *_localctx = _tracker.createInstance<OneStmtEndsInBlockContext>(_ctx, getState());
  enterRule(_localctx, 32, LSysDParser::RuleOneStmtEndsInBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(322);
      match(LSysDParser::KWIF);
      setState(324);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(323);
        nl();
      }
      setState(326);
      match(LSysDParser::LPAREN);
      setState(328);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(327);
        nl();
      }
      setState(330);
      expression(0);
      setState(332);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(331);
        nl();
      }
      setState(334);
      match(LSysDParser::RPAREN);
      setState(336);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(335);
        nl();
      }
      setState(338);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(340);
      match(LSysDParser::KWIF);
      setState(342);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(341);
        nl();
      }
      setState(344);
      match(LSysDParser::LPAREN);
      setState(346);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(345);
        nl();
      }
      setState(348);
      expression(0);
      setState(350);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(349);
        nl();
      }
      setState(352);
      match(LSysDParser::RPAREN);
      setState(354);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(353);
        nl();
      }
      setState(356);
      blockOrOneStatement();
      setState(358);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(357);
        nl();
      }
      setState(360);
      match(LSysDParser::KWELSE);
      setState(362);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(361);
        nl();
      }
      setState(364);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(366);
      match(LSysDParser::KWWHILE);
      setState(368);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(367);
        nl();
      }
      setState(370);
      match(LSysDParser::LPAREN);
      setState(372);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(371);
        nl();
      }
      setState(374);
      expression(0);
      setState(376);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(375);
        nl();
      }
      setState(378);
      match(LSysDParser::RPAREN);
      setState(380);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(379);
        nl();
      }
      setState(382);
      block();
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

//----------------- StatementContext ------------------------------------------------------------------

LSysDParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::OneStatementContext* LSysDParser::StatementContext::oneStatement() {
  return getRuleContext<LSysDParser::OneStatementContext>(0);
}

std::vector<LSysDParser::SepContext *> LSysDParser::StatementContext::sep() {
  return getRuleContexts<LSysDParser::SepContext>();
}

LSysDParser::SepContext* LSysDParser::StatementContext::sep(size_t i) {
  return getRuleContext<LSysDParser::SepContext>(i);
}

std::vector<LSysDParser::OneStmtNeedsSepContext *> LSysDParser::StatementContext::oneStmtNeedsSep() {
  return getRuleContexts<LSysDParser::OneStmtNeedsSepContext>();
}

LSysDParser::OneStmtNeedsSepContext* LSysDParser::StatementContext::oneStmtNeedsSep(size_t i) {
  return getRuleContext<LSysDParser::OneStmtNeedsSepContext>(i);
}

std::vector<LSysDParser::OneStmtEndsInBlockContext *> LSysDParser::StatementContext::oneStmtEndsInBlock() {
  return getRuleContexts<LSysDParser::OneStmtEndsInBlockContext>();
}

LSysDParser::OneStmtEndsInBlockContext* LSysDParser::StatementContext::oneStmtEndsInBlock(size_t i) {
  return getRuleContext<LSysDParser::OneStmtEndsInBlockContext>(i);
}


size_t LSysDParser::StatementContext::getRuleIndex() const {
  return LSysDParser::RuleStatement;
}

antlrcpp::Any LSysDParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::StatementContext* LSysDParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 34, LSysDParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(387);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(386);
      sep();
    }
    setState(398);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(396);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
        case 1: {
          setState(389);
          oneStmtNeedsSep();
          setState(390);
          sep();
          break;
        }

        case 2: {
          setState(392);
          oneStmtEndsInBlock();
          setState(394);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == LSysDParser::SEMI

          || _la == LSysDParser::NEW_LINE) {
            setState(393);
            sep();
          }
          break;
        }

        } 
      }
      setState(400);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    }
    setState(401);
    oneStatement();
    setState(403);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      setState(402);
      sep();
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

//----------------- AssignmentContext ------------------------------------------------------------------

LSysDParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LSysDParser::AssignmentContext::ID() {
  return getToken(LSysDParser::ID, 0);
}

tree::TerminalNode* LSysDParser::AssignmentContext::ASSIGN() {
  return getToken(LSysDParser::ASSIGN, 0);
}

LSysDParser::ExpressionContext* LSysDParser::AssignmentContext::expression() {
  return getRuleContext<LSysDParser::ExpressionContext>(0);
}


size_t LSysDParser::AssignmentContext::getRuleIndex() const {
  return LSysDParser::RuleAssignment;
}

antlrcpp::Any LSysDParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::AssignmentContext* LSysDParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 36, LSysDParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    match(LSysDParser::ID);
    setState(406);
    match(LSysDParser::ASSIGN);
    setState(407);
    expression(0);
   
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
  enterRule(_localctx, 38, LSysDParser::RuleAxiomDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(LSysDParser::KWAXIOM);
    setState(410);
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
  enterRule(_localctx, 40, LSysDParser::RulePropDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(LSysDParser::KWSET);
    setState(413);
    match(LSysDParser::ID);
    setState(414);
    match(LSysDParser::ASSIGN);
    setState(415);
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

tree::TerminalNode* LSysDParser::FuncDefContext::KWFUNCTION() {
  return getToken(LSysDParser::KWFUNCTION, 0);
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

LSysDParser::BlockContext* LSysDParser::FuncDefContext::block() {
  return getRuleContext<LSysDParser::BlockContext>(0);
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
  enterRule(_localctx, 42, LSysDParser::RuleFuncDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(417);
    match(LSysDParser::KWFUNCTION);
    setState(418);
    match(LSysDParser::ID);
    setState(419);
    match(LSysDParser::LPAREN);
    setState(420);
    params();
    setState(421);
    match(LSysDParser::RPAREN);
    setState(425);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ASSIGN: {
        setState(422);
        match(LSysDParser::ASSIGN);
        setState(423);
        expression(0);
        break;
      }

      case LSysDParser::LBRACE: {
        setState(424);
        block();
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
  enterRule(_localctx, 44, LSysDParser::RuleConstDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    match(LSysDParser::DOLLARID);
    setState(428);
    match(LSysDParser::ASSIGN);
    setState(429);
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
  enterRule(_localctx, 46, LSysDParser::RuleTableBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    match(LSysDParser::KWTABLE);
    setState(432);
    match(LSysDParser::ID);
    setState(433);
    match(LSysDParser::LBRACE);
    setState(434);
    rules();
    setState(435);
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
  enterRule(_localctx, 48, LSysDParser::RuleRulesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(LSysDParser::KWRULES);
    setState(439);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(438);
      nl();
    }
    setState(441);
    match(LSysDParser::LBRACE);
    setState(442);
    ruleDefs();
    setState(443);
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
  enterRule(_localctx, 50, LSysDParser::RuleProductionRulesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    match(LSysDParser::KWPRODUCTION);
    setState(447);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(446);
      nl();
    }
    setState(449);
    match(LSysDParser::KWRULES);
    setState(451);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(450);
      nl();
    }
    setState(453);
    match(LSysDParser::LBRACE);
    setState(454);
    ruleDefs();
    setState(455);
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
  enterRule(_localctx, 52, LSysDParser::RuleCodingRulesBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    match(LSysDParser::KWCODING);
    setState(459);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(458);
      nl();
    }
    setState(461);
    match(LSysDParser::KWRULES);
    setState(463);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(462);
      nl();
    }
    setState(465);
    match(LSysDParser::LBRACE);
    setState(466);
    ruleDefs();
    setState(467);
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
  enterRule(_localctx, 54, LSysDParser::RuleRules);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(470);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(469);
      sep();
      break;
    }

    }
    setState(477);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(472);
        anyRule();
        setState(473);
        sep(); 
      }
      setState(479);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
    }
    setState(481);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::FLOAT)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::LT)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(480);
      anyRule();
    }
    setState(484);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(483);
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
  enterRule(_localctx, 56, LSysDParser::RuleRuleDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(487);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      setState(486);
      sep();
      break;
    }

    }
    setState(494);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(489);
        ruleDef();
        setState(490);
        sep(); 
      }
      setState(496);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    }
    setState(498);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::FLOAT)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::LT)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(497);
      ruleDef();
    }
    setState(501);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(500);
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
  enterRule(_localctx, 58, LSysDParser::RuleProductionRuleDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(504);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      setState(503);
      sep();
      break;
    }

    }
    setState(511);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(506);
        productionRuleDef();
        setState(507);
        sep(); 
      }
      setState(513);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    }
    setState(515);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::FLOAT)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::LT)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(514);
      productionRuleDef();
    }
    setState(518);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(517);
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
  enterRule(_localctx, 60, LSysDParser::RuleCodingRuleDefs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(521);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      setState(520);
      sep();
      break;
    }

    }
    setState(528);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(523);
        codingRuleDef();
        setState(524);
        sep(); 
      }
      setState(530);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    }
    setState(532);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::FLOAT)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::LT)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(531);
      codingRuleDef();
    }
    setState(535);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(534);
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
  enterRule(_localctx, 62, LSysDParser::RuleAnyRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(539);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(537);
      productionRule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(538);
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
  enterRule(_localctx, 64, LSysDParser::RuleProductionRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(541);
    productionRuleDef();
   
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
  enterRule(_localctx, 66, LSysDParser::RuleCodingRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(543);
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
  enterRule(_localctx, 68, LSysDParser::RuleRuleDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(547);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(545);
      productionRuleDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(546);
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

LSysDParser::WeightContext* LSysDParser::ProductionRuleDefContext::weight() {
  return getRuleContext<LSysDParser::WeightContext>(0);
}

LSysDParser::LcontextContext* LSysDParser::ProductionRuleDefContext::lcontext() {
  return getRuleContext<LSysDParser::LcontextContext>(0);
}

LSysDParser::RcontextContext* LSysDParser::ProductionRuleDefContext::rcontext() {
  return getRuleContext<LSysDParser::RcontextContext>(0);
}

LSysDParser::CondContext* LSysDParser::ProductionRuleDefContext::cond() {
  return getRuleContext<LSysDParser::CondContext>(0);
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
  enterRule(_localctx, 70, LSysDParser::RuleProductionRuleDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(550);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx)) {
    case 1: {
      setState(549);
      weight();
      break;
    }

    }
    setState(553);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      setState(552);
      lcontext();
      break;
    }

    }
    setState(555);
    lside();
    setState(557);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::GT) {
      setState(556);
      rcontext();
    }
    setState(560);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::COLON) {
      setState(559);
      cond();
    }
    setState(562);
    match(LSysDParser::ARROW);
    setState(564);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      setState(563);
      nl();
      break;
    }

    }
    setState(566);
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

LSysDParser::WeightContext* LSysDParser::CodingRuleDefContext::weight() {
  return getRuleContext<LSysDParser::WeightContext>(0);
}

LSysDParser::LcontextContext* LSysDParser::CodingRuleDefContext::lcontext() {
  return getRuleContext<LSysDParser::LcontextContext>(0);
}

LSysDParser::RcontextContext* LSysDParser::CodingRuleDefContext::rcontext() {
  return getRuleContext<LSysDParser::RcontextContext>(0);
}

LSysDParser::CondContext* LSysDParser::CodingRuleDefContext::cond() {
  return getRuleContext<LSysDParser::CondContext>(0);
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
  enterRule(_localctx, 72, LSysDParser::RuleCodingRuleDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      setState(568);
      weight();
      break;
    }

    }
    setState(572);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      setState(571);
      lcontext();
      break;
    }

    }
    setState(574);
    lside();
    setState(576);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::GT) {
      setState(575);
      rcontext();
    }
    setState(579);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::COLON) {
      setState(578);
      cond();
    }
    setState(581);
    match(LSysDParser::DARROW);
    setState(583);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      setState(582);
      nl();
      break;
    }

    }
    setState(585);
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
  enterRule(_localctx, 74, LSysDParser::RuleTagPrefix);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(587);
    tag();
    setState(588);
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
  enterRule(_localctx, 76, LSysDParser::RuleTag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(590);
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

tree::TerminalNode* LSysDParser::WeightContext::COLON() {
  return getToken(LSysDParser::COLON, 0);
}

tree::TerminalNode* LSysDParser::WeightContext::INT() {
  return getToken(LSysDParser::INT, 0);
}

tree::TerminalNode* LSysDParser::WeightContext::FLOAT() {
  return getToken(LSysDParser::FLOAT, 0);
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
  enterRule(_localctx, 78, LSysDParser::RuleWeight);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(592);
    _la = _input->LA(1);
    if (!(_la == LSysDParser::INT

    || _la == LSysDParser::FLOAT || _la == LSysDParser::XM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(593);
    match(LSysDParser::COLON);
   
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
  enterRule(_localctx, 80, LSysDParser::RuleLside);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
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
  enterRule(_localctx, 82, LSysDParser::RuleLcontext);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(600);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::RULECHAR) {
      setState(597);
      lItem();
      setState(602);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(603);
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
  enterRule(_localctx, 84, LSysDParser::RuleRcontext);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(605);
    match(LSysDParser::GT);
    setState(609);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::RULECHAR) {
      setState(606);
      lItem();
      setState(611);
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
  enterRule(_localctx, 86, LSysDParser::RuleRside);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(615);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::LBRACE)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::RULECHAR) {
      setState(612);
      rItem();
      setState(617);
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
  enterRule(_localctx, 88, LSysDParser::RuleWord);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::LBRACE)
      | (1ULL << LSysDParser::LBRACK)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::RULECHAR) {
      setState(618);
      rItem();
      setState(623);
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

LSysDParser::ParamsContext* LSysDParser::LCharContext::params() {
  return getRuleContext<LSysDParser::ParamsContext>(0);
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
  enterRule(_localctx, 90, LSysDParser::RuleLChar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(624);
    validLeftChar();
    setState(629);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::LPAREN) {
      setState(625);
      match(LSysDParser::LPAREN);
      setState(626);
      params();
      setState(627);
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

LSysDParser::ParamsContext* LSysDParser::LItemContext::params() {
  return getRuleContext<LSysDParser::ParamsContext>(0);
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
  enterRule(_localctx, 92, LSysDParser::RuleLItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(646);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ID:
      case LSysDParser::INT:
      case LSysDParser::ADD:
      case LSysDParser::SUB:
      case LSysDParser::RULECHAR: {
        enterOuterAlt(_localctx, 1);
        setState(631);
        validLeftChar();
        setState(636);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::LPAREN) {
          setState(632);
          match(LSysDParser::LPAREN);
          setState(633);
          params();
          setState(634);
          match(LSysDParser::RPAREN);
        }
        break;
      }

      case LSysDParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(638);
        match(LSysDParser::LBRACK);
        setState(642);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << LSysDParser::ID)
          | (1ULL << LSysDParser::INT)
          | (1ULL << LSysDParser::LBRACK)
          | (1ULL << LSysDParser::ADD)
          | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::RULECHAR) {
          setState(639);
          lItem();
          setState(644);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(645);
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

LSysDParser::BlockContext* LSysDParser::RItemContext::block() {
  return getRuleContext<LSysDParser::BlockContext>(0);
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
  enterRule(_localctx, 94, LSysDParser::RuleRItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(664);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ID:
      case LSysDParser::INT:
      case LSysDParser::ADD:
      case LSysDParser::SUB:
      case LSysDParser::RULECHAR: {
        enterOuterAlt(_localctx, 1);
        setState(648);
        validRightChar();
        setState(653);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::LPAREN) {
          setState(649);
          match(LSysDParser::LPAREN);
          setState(650);
          args();
          setState(651);
          match(LSysDParser::RPAREN);
        }
        break;
      }

      case LSysDParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(655);
        match(LSysDParser::LBRACK);
        setState(659);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << LSysDParser::ID)
          | (1ULL << LSysDParser::INT)
          | (1ULL << LSysDParser::LBRACE)
          | (1ULL << LSysDParser::LBRACK)
          | (1ULL << LSysDParser::ADD)
          | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::RULECHAR) {
          setState(656);
          rItem();
          setState(661);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(662);
        match(LSysDParser::RBRACK);
        break;
      }

      case LSysDParser::LBRACE: {
        enterOuterAlt(_localctx, 3);
        setState(663);
        block();
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
  enterRule(_localctx, 96, LSysDParser::RuleValidLeftChar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(666);
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
  enterRule(_localctx, 98, LSysDParser::RuleValidRightChar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(668);
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
  enterRule(_localctx, 100, LSysDParser::RuleValidChar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(670);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LSysDParser::ID)
      | (1ULL << LSysDParser::INT)
      | (1ULL << LSysDParser::ADD)
      | (1ULL << LSysDParser::SUB))) != 0) || _la == LSysDParser::RULECHAR)) {
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
  enterRule(_localctx, 102, LSysDParser::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(680);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::ID) {
      setState(672);
      param();
      setState(677);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LSysDParser::COMMA) {
        setState(673);
        match(LSysDParser::COMMA);
        setState(674);
        param();
        setState(679);
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
  enterRule(_localctx, 104, LSysDParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(682);
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

tree::TerminalNode* LSysDParser::CondContext::COLON() {
  return getToken(LSysDParser::COLON, 0);
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
  enterRule(_localctx, 106, LSysDParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(684);
    match(LSysDParser::COLON);
    setState(685);
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
  enterRule(_localctx, 108, LSysDParser::RuleArgs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(698);
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
      | (1ULL << LSysDParser::KWTRUE)
      | (1ULL << LSysDParser::KWNULL))) != 0)) {
      setState(687);
      arg();
      setState(692);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(688);
          match(LSysDParser::COMMA);
          setState(689);
          arg(); 
        }
        setState(694);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx);
      }
      setState(696);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::COMMA) {
        setState(695);
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
  enterRule(_localctx, 110, LSysDParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
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
  size_t startState = 112;
  enterRecursionRule(_localctx, 112, LSysDParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(720);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::LPAREN: {
        _localctx = _tracker.createInstance<ParenthesizedExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(703);
        match(LSysDParser::LPAREN);
        setState(704);
        expression(0);
        setState(705);
        match(LSysDParser::RPAREN);
        break;
      }

      case LSysDParser::INT:
      case LSysDParser::FLOAT:
      case LSysDParser::STRING:
      case LSysDParser::KWFALSE:
      case LSysDParser::KWTRUE:
      case LSysDParser::KWNULL: {
        _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(707);
        constant();
        break;
      }

      case LSysDParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(708);
        match(LSysDParser::ID);
        break;
      }

      case LSysDParser::ADD:
      case LSysDParser::SUB: {
        _localctx = _tracker.createInstance<AritUnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(709);
        dynamic_cast<AritUnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == LSysDParser::ADD

        || _la == LSysDParser::SUB)) {
          dynamic_cast<AritUnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(710);
        expression(13);
        break;
      }

      case LSysDParser::BITNOT:
      case LSysDParser::NOT: {
        _localctx = _tracker.createInstance<LogicUnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(711);
        dynamic_cast<LogicUnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == LSysDParser::BITNOT

        || _la == LSysDParser::NOT)) {
          dynamic_cast<LogicUnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(712);
        expression(12);
        break;
      }

      case LSysDParser::KWIF: {
        _localctx = _tracker.createInstance<IfElseExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(713);
        match(LSysDParser::KWIF);
        setState(714);
        expression(0);
        setState(715);
        match(LSysDParser::KWTHEN);
        setState(716);
        expression(0);
        setState(717);
        match(LSysDParser::KWELSE);
        setState(718);
        expression(1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(759);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(757);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(722);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(723);
          dynamic_cast<AritBinaryExprContext *>(_localctx)->op = match(LSysDParser::POW);
          setState(724);
          expression(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(725);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(726);
          dynamic_cast<AritBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << LSysDParser::MUL)
            | (1ULL << LSysDParser::DIV)
            | (1ULL << LSysDParser::MOD))) != 0))) {
            dynamic_cast<AritBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(727);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(728);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(729);
          dynamic_cast<AritBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == LSysDParser::ADD

          || _la == LSysDParser::SUB)) {
            dynamic_cast<AritBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(730);
          expression(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CmpBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(731);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(732);
          dynamic_cast<CmpBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << LSysDParser::LT)
            | (1ULL << LSysDParser::GT)
            | (1ULL << LSysDParser::LE)
            | (1ULL << LSysDParser::GE))) != 0))) {
            dynamic_cast<CmpBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(733);
          expression(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CmpBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(734);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(735);
          dynamic_cast<CmpBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == LSysDParser::EQ

          || _la == LSysDParser::NE)) {
            dynamic_cast<CmpBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(736);
          expression(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(737);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(738);
          dynamic_cast<BitBinaryExprContext *>(_localctx)->op = match(LSysDParser::BITAND);
          setState(739);
          expression(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(740);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(741);
          dynamic_cast<BitBinaryExprContext *>(_localctx)->op = match(LSysDParser::BITXOR);
          setState(742);
          expression(6);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(743);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(744);
          dynamic_cast<BitBinaryExprContext *>(_localctx)->op = match(LSysDParser::BITOR);
          setState(745);
          expression(5);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(746);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(747);
          dynamic_cast<LogicBinaryExprContext *>(_localctx)->op = match(LSysDParser::AND);
          setState(748);
          expression(4);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(749);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(750);
          dynamic_cast<LogicBinaryExprContext *>(_localctx)->op = match(LSysDParser::OR);
          setState(751);
          expression(3);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<FunctionCallExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(752);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(753);
          match(LSysDParser::LPAREN);
          setState(754);
          arguments();
          setState(755);
          match(LSysDParser::RPAREN);
          break;
        }

        } 
      }
      setState(761);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
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
  enterRule(_localctx, 114, LSysDParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(773);
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
      | (1ULL << LSysDParser::KWTRUE)
      | (1ULL << LSysDParser::KWNULL))) != 0)) {
      setState(762);
      argument();
      setState(767);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(763);
          match(LSysDParser::COMMA);
          setState(764);
          argument(); 
        }
        setState(769);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx);
      }
      setState(771);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::COMMA) {
        setState(770);
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
  enterRule(_localctx, 116, LSysDParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(775);
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

//----------------- NullValueContext ------------------------------------------------------------------

tree::TerminalNode* LSysDParser::NullValueContext::KWNULL() {
  return getToken(LSysDParser::KWNULL, 0);
}

LSysDParser::NullValueContext::NullValueContext(ConstantContext *ctx) { copyFrom(ctx); }

antlrcpp::Any LSysDParser::NullValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitNullValue(this);
  else
    return visitor->visitChildren(this);
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
  enterRule(_localctx, 118, LSysDParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(783);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::INT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::IntConstantContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(777);
        dynamic_cast<IntConstantContext *>(_localctx)->v = match(LSysDParser::INT);
        break;
      }

      case LSysDParser::FLOAT: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::FloatConstantContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(778);
        dynamic_cast<FloatConstantContext *>(_localctx)->v = match(LSysDParser::FLOAT);
        break;
      }

      case LSysDParser::STRING: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::StringConstantContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(779);
        dynamic_cast<StringConstantContext *>(_localctx)->v = match(LSysDParser::STRING);
        break;
      }

      case LSysDParser::KWTRUE: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::TrueValueContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(780);
        match(LSysDParser::KWTRUE);
        break;
      }

      case LSysDParser::KWFALSE: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::FalseValueContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(781);
        match(LSysDParser::KWFALSE);
        break;
      }

      case LSysDParser::KWNULL: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<LSysDParser::NullValueContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(782);
        match(LSysDParser::KWNULL);
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
    case 56: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

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
  "main", "module", "globalDefs", "globalDef", "declaration", "varDeclaration", 
  "constDeclaration", "lsystem", "sep", "nl", "inLsysDefs", "inLsysDef", 
  "blockOrOneStatement", "block", "oneStatement", "oneStmtNeedsSep", "oneStmtEndsInBlock", 
  "statement", "assignment", "axiomDef", "propDef", "funcDef", "constDef", 
  "tableBlock", "rulesBlock", "productionRulesBlock", "codingRulesBlock", 
  "rules", "ruleDefs", "productionRuleDefs", "codingRuleDefs", "anyRule", 
  "productionRule", "codingRule", "ruleDef", "productionRuleDef", "codingRuleDef", 
  "tagPrefix", "tag", "weight", "lside", "lcontext", "rcontext", "rside", 
  "word", "lChar", "lItem", "rItem", "validLeftChar", "validRightChar", 
  "validChar", "params", "param", "cond", "args", "arg", "expression", "arguments", 
  "argument", "constant"
};

std::vector<std::string> LSysDParser::_literalNames = {
  "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", 
  "':'", "';'", "','", "'.'", "'->'", "':='", "'<'", "'>'", "'<='", "'>='", 
  "", "'!='", "'+'", "'-'", "'*'", "'/'", "'%'", "'**'", "'&'", "'|'", "'^'", 
  "'~'", "", "", "", "", "'else'", "", "'false'", "'for'", "", "'if'", "", 
  "'in'", "", "'true'", "'and'", "'axiom'", "'coding'", "'do'", "'function'", 
  "'lsystem'", "'main'", "'not'", "'null'", "'or'", "'production'", "'return'", 
  "'rules'", "'set'", "'table'", "'then'", "'var'", "'while'", "'?'", "'!'", 
  "'=>'", "'//'"
};

std::vector<std::string> LSysDParser::_symbolicNames = {
  "", "EOL", "ACCESSOR", "ID", "INT", "FLOAT", "STRING", "LPAREN", "RPAREN", 
  "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COLON", "SEMI", "COMMA", "DOT", 
  "ARROW", "ASSIGN", "LT", "GT", "LE", "GE", "EQ", "NE", "ADD", "SUB", "MUL", 
  "DIV", "MOD", "POW", "BITAND", "BITOR", "BITXOR", "BITNOT", "AND", "OR", 
  "NOT", "KWAS", "KWELSE", "KWEVENTSPEC", "KWFALSE", "KWFOR", "KWFROM", 
  "KWIF", "KWIMPORT", "KWIN", "KWNONE", "KWTRUE", "KWAND", "KWAXIOM", "KWCODING", 
  "KWDO", "KWFUNCTION", "KWLSYS", "KWMAIN", "KWNOT", "KWNULL", "KWOR", "KWPRODUCTION", 
  "KWRETURN", "KWRULES", "KWSET", "KWTABLE", "KWTHEN", "KWVAR", "KWWHILE", 
  "QM", "XM", "DARROW", "FDIV", "DOLLARID", "RULECHAR", "WS", "COMMENTBLQ", 
  "COMMENTLIN", "LINE_JOINING", "NEW_LINE", "ERRORCHAR"
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
    0x3, 0x50, 0x314, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x81, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x5, 0x4, 0x86, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x8b, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x8e, 0xb, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x91, 0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x94, 0xa, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x99, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0x9d, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x5, 0x9, 0xaa, 
    0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xaf, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x6, 0xa, 0xb6, 0xa, 0xa, 
    0xd, 0xa, 0xe, 0xa, 0xb7, 0x3, 0xb, 0x6, 0xb, 0xbb, 0xa, 0xb, 0xd, 0xb, 
    0xe, 0xb, 0xbc, 0x3, 0xc, 0x5, 0xc, 0xc0, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0xc5, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc8, 0xb, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0xcb, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0xce, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0xd8, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xdc, 
    0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xe0, 0xa, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xe6, 0xa, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xed, 0xa, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0xf1, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
    0x11, 0xf5, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xf9, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xfd, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x103, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x107, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x10b, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x10f, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x113, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x117, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x11d, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x121, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x125, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x129, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x12f, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x133, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x137, 0xa, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x13b, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x13f, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x143, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x147, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0x14b, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x14f, 
    0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x153, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x159, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x5, 0x12, 0x15d, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x161, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x165, 0xa, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x169, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0x16d, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0x173, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x177, 
    0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x17b, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x5, 0x12, 0x17f, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x183, 0xa, 0x12, 0x3, 0x13, 0x5, 0x13, 0x186, 0xa, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x18d, 0xa, 0x13, 
    0x7, 0x13, 0x18f, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x192, 0xb, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x196, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1ac, 
    0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x1ba, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1c2, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x1c6, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1ce, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x5, 0x1c, 0x1d2, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x5, 0x1d, 0x1d9, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x7, 0x1d, 0x1de, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x1e1, 0xb, 0x1d, 
    0x3, 0x1d, 0x5, 0x1d, 0x1e4, 0xa, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1e7, 
    0xa, 0x1d, 0x3, 0x1e, 0x5, 0x1e, 0x1ea, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x7, 0x1e, 0x1ef, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x1f2, 
    0xb, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1f5, 0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
    0x1f8, 0xa, 0x1e, 0x3, 0x1f, 0x5, 0x1f, 0x1fb, 0xa, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x200, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
    0x203, 0xb, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x206, 0xa, 0x1f, 0x3, 0x1f, 
    0x5, 0x1f, 0x209, 0xa, 0x1f, 0x3, 0x20, 0x5, 0x20, 0x20c, 0xa, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x211, 0xa, 0x20, 0xc, 0x20, 
    0xe, 0x20, 0x214, 0xb, 0x20, 0x3, 0x20, 0x5, 0x20, 0x217, 0xa, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x21a, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
    0x21e, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x226, 0xa, 0x24, 0x3, 0x25, 0x5, 0x25, 0x229, 
    0xa, 0x25, 0x3, 0x25, 0x5, 0x25, 0x22c, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x5, 0x25, 0x230, 0xa, 0x25, 0x3, 0x25, 0x5, 0x25, 0x233, 0xa, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x237, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x26, 0x5, 0x26, 0x23c, 0xa, 0x26, 0x3, 0x26, 0x5, 0x26, 0x23f, 
    0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x243, 0xa, 0x26, 0x3, 0x26, 
    0x5, 0x26, 0x246, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x24a, 
    0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2b, 0x7, 0x2b, 0x259, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x25c, 
    0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x262, 
    0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x265, 0xb, 0x2c, 0x3, 0x2d, 0x7, 0x2d, 
    0x268, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x26b, 0xb, 0x2d, 0x3, 0x2e, 
    0x7, 0x2e, 0x26e, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x271, 0xb, 0x2e, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x278, 
    0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 
    0x30, 0x27f, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x283, 0xa, 
    0x30, 0xc, 0x30, 0xe, 0x30, 0x286, 0xb, 0x30, 0x3, 0x30, 0x5, 0x30, 
    0x289, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x5, 0x31, 0x290, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x294, 
    0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x297, 0xb, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x5, 0x31, 0x29b, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x2a6, 
    0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x2a9, 0xb, 0x35, 0x5, 0x35, 0x2ab, 
    0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x2b5, 0xa, 0x38, 0xc, 0x38, 
    0xe, 0x38, 0x2b8, 0xb, 0x38, 0x3, 0x38, 0x5, 0x38, 0x2bb, 0xa, 0x38, 
    0x5, 0x38, 0x2bd, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x2d3, 0xa, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
    0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x2f8, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 
    0x2fb, 0xb, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x300, 
    0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x303, 0xb, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 
    0x306, 0xa, 0x3b, 0x5, 0x3b, 0x308, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 
    0x3d, 0x312, 0xa, 0x3d, 0x3, 0x3d, 0x2, 0x3, 0x72, 0x3e, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 
    0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x2, 0xa, 0x4, 
    0x2, 0x10, 0x10, 0x4f, 0x4f, 0x4, 0x2, 0x6, 0x7, 0x46, 0x46, 0x5, 0x2, 
    0x5, 0x6, 0x1b, 0x1c, 0x4a, 0x4a, 0x3, 0x2, 0x1b, 0x1c, 0x4, 0x2, 0x24, 
    0x24, 0x27, 0x27, 0x3, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x15, 0x18, 0x3, 0x2, 
    0x19, 0x1a, 0x2, 0x36c, 0x2, 0x80, 0x3, 0x2, 0x2, 0x2, 0x4, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0xa3, 0x3, 0x2, 0x2, 0x2, 0x10, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x12, 0xb5, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0xba, 0x3, 0x2, 0x2, 0x2, 0x16, 0xbf, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe5, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x142, 0x3, 0x2, 0x2, 0x2, 0x22, 0x182, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x185, 0x3, 0x2, 0x2, 0x2, 0x26, 0x197, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x19b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1a3, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x30, 0x1b1, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1bf, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1d8, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1fa, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x21f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x221, 0x3, 0x2, 0x2, 0x2, 0x46, 0x225, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x228, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x23b, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x250, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x252, 0x3, 0x2, 0x2, 0x2, 0x52, 0x255, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x56, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x269, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x272, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x288, 0x3, 0x2, 0x2, 0x2, 0x60, 0x29a, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x64, 0x29e, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2aa, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x2ae, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x70, 0x2be, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x74, 0x307, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x309, 0x3, 0x2, 0x2, 0x2, 0x78, 0x311, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
    0x5, 0x4, 0x3, 0x2, 0x7b, 0x7c, 0x7, 0x2, 0x2, 0x3, 0x7c, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x16, 0xc, 0x2, 0x7e, 0x7f, 0x7, 0x2, 
    0x2, 0x3, 0x7f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7a, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x81, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x83, 0x5, 0x6, 0x4, 0x2, 0x83, 0x5, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x86, 0x5, 0x12, 0xa, 0x2, 0x85, 0x84, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x5, 
    0x8, 0x5, 0x2, 0x88, 0x89, 0x5, 0x12, 0xa, 0x2, 0x89, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x91, 0x5, 0x8, 0x5, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x93, 0x3, 0x2, 0x2, 0x2, 0x92, 0x94, 0x5, 
    0x12, 0xa, 0x2, 0x93, 0x92, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x7, 0x3, 0x2, 0x2, 0x2, 0x95, 0x99, 0x5, 0x10, 0x9, 
    0x2, 0x96, 0x99, 0x5, 0xa, 0x6, 0x2, 0x97, 0x99, 0x5, 0x2c, 0x17, 0x2, 
    0x98, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9d, 
    0x5, 0xc, 0x7, 0x2, 0x9b, 0x9d, 0x5, 0xe, 0x8, 0x2, 0x9c, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0x9f, 0x7, 0x43, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x5, 0x2, 
    0x2, 0xa0, 0xa1, 0x7, 0x14, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x72, 0x3a, 0x2, 
    0xa2, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x40, 0x2, 0x2, 0xa4, 
    0xa5, 0x7, 0x5, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x14, 0x2, 0x2, 0xa6, 0xa7, 
    0x5, 0x72, 0x3a, 0x2, 0xa7, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xaa, 0x7, 
    0x39, 0x2, 0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x38, 0x2, 
    0x2, 0xac, 0xae, 0x7, 0x5, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x14, 0xb, 0x2, 
    0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0xb, 0x2, 0x2, 0xb1, 0xb2, 
    0x5, 0x16, 0xc, 0x2, 0xb2, 0xb3, 0x7, 0xc, 0x2, 0x2, 0xb3, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb6, 0x9, 0x2, 0x2, 0x2, 0xb5, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xbb, 0x7, 0x4f, 0x2, 0x2, 0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0x15, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x5, 
    0x12, 0xa, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0x18, 0xd, 
    0x2, 0xc2, 0xc3, 0x5, 0x12, 0xa, 0x2, 0xc3, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc4, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcb, 0x5, 
    0x18, 0xd, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x5, 0x12, 0xa, 
    0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 
    0xce, 0x17, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd8, 0x5, 0x28, 0x15, 0x2, 0xd0, 
    0xd8, 0x5, 0x24, 0x13, 0x2, 0xd1, 0xd8, 0x5, 0x2c, 0x17, 0x2, 0xd2, 
    0xd8, 0x5, 0x30, 0x19, 0x2, 0xd3, 0xd8, 0x5, 0x32, 0x1a, 0x2, 0xd4, 
    0xd8, 0x5, 0x34, 0x1b, 0x2, 0xd5, 0xd8, 0x5, 0x36, 0x1c, 0x2, 0xd6, 
    0xd8, 0x5, 0x46, 0x24, 0x2, 0xd7, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd2, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdc, 0x5, 0x1c, 0xf, 0x2, 
    0xda, 0xdc, 0x5, 0x1e, 0x10, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 
    0x7, 0xb, 0x2, 0x2, 0xde, 0xe0, 0x5, 0x24, 0x13, 0x2, 0xdf, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xe1, 0xe2, 0x7, 0xc, 0x2, 0x2, 0xe2, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xe6, 0x5, 0x20, 0x11, 0x2, 0xe4, 0xe6, 0x5, 0x22, 0x12, 
    0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x143, 0x5, 0x72, 0x3a, 0x2, 0xe8, 
    0x143, 0x5, 0x26, 0x14, 0x2, 0xe9, 0x143, 0x5, 0xa, 0x6, 0x2, 0xea, 
    0xec, 0x7, 0x3e, 0x2, 0x2, 0xeb, 0xed, 0x5, 0x72, 0x3a, 0x2, 0xec, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0xee, 0xf0, 0x7, 0x2e, 0x2, 0x2, 0xef, 0xf1, 0x5, 0x14, 
    0xb, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf4, 0x7, 0x9, 0x2, 0x2, 
    0xf3, 0xf5, 0x5, 0x14, 0xb, 0x2, 0xf4, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 
    0x5, 0x72, 0x3a, 0x2, 0xf7, 0xf9, 0x5, 0x14, 0xb, 0x2, 0xf8, 0xf7, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0xfa, 0xfc, 0x7, 0xa, 0x2, 0x2, 0xfb, 0xfd, 0x5, 0x14, 0xb, 
    0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 
    0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x5, 0x20, 0x11, 0x2, 0xff, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x100, 0x102, 0x7, 0x2e, 0x2, 0x2, 0x101, 
    0x103, 0x5, 0x14, 0xb, 0x2, 0x102, 0x101, 0x3, 0x2, 0x2, 0x2, 0x102, 
    0x103, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x106, 0x7, 0x9, 0x2, 0x2, 0x105, 0x107, 0x5, 0x14, 0xb, 0x2, 0x106, 
    0x105, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 0x10a, 0x5, 0x72, 0x3a, 0x2, 0x109, 
    0x10b, 0x5, 0x14, 0xb, 0x2, 0x10a, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10a, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 
    0x10e, 0x7, 0xa, 0x2, 0x2, 0x10d, 0x10f, 0x5, 0x14, 0xb, 0x2, 0x10e, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x112, 0x5, 0x1a, 0xe, 0x2, 0x111, 
    0x113, 0x5, 0x14, 0xb, 0x2, 0x112, 0x111, 0x3, 0x2, 0x2, 0x2, 0x112, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 
    0x116, 0x7, 0x29, 0x2, 0x2, 0x115, 0x117, 0x5, 0x14, 0xb, 0x2, 0x116, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x5, 0x20, 0x11, 0x2, 0x119, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11c, 0x7, 0x44, 0x2, 0x2, 0x11b, 
    0x11d, 0x5, 0x14, 0xb, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11c, 
    0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 
    0x120, 0x7, 0x9, 0x2, 0x2, 0x11f, 0x121, 0x5, 0x14, 0xb, 0x2, 0x120, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x124, 0x5, 0x72, 0x3a, 0x2, 0x123, 
    0x125, 0x5, 0x14, 0xb, 0x2, 0x124, 0x123, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 
    0x128, 0x7, 0xa, 0x2, 0x2, 0x127, 0x129, 0x5, 0x14, 0xb, 0x2, 0x128, 
    0x127, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 
    0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x5, 0x20, 0x11, 0x2, 0x12b, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x7, 0x36, 0x2, 0x2, 0x12d, 
    0x12f, 0x5, 0x14, 0xb, 0x2, 0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 
    0x132, 0x5, 0x1a, 0xe, 0x2, 0x131, 0x133, 0x5, 0x14, 0xb, 0x2, 0x132, 
    0x131, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x136, 0x7, 0x44, 0x2, 0x2, 0x135, 
    0x137, 0x5, 0x14, 0xb, 0x2, 0x136, 0x135, 0x3, 0x2, 0x2, 0x2, 0x136, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x13a, 0x7, 0x9, 0x2, 0x2, 0x139, 0x13b, 0x5, 0x14, 0xb, 0x2, 0x13a, 
    0x139, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x5, 0x72, 0x3a, 0x2, 0x13d, 
    0x13f, 0x5, 0x14, 0xb, 0x2, 0x13e, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x141, 0x7, 0xa, 0x2, 0x2, 0x141, 0x143, 0x3, 0x2, 0x2, 0x2, 0x142, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0x142, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x142, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0x142, 0xea, 0x3, 0x2, 0x2, 0x2, 0x142, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x100, 0x3, 0x2, 0x2, 0x2, 0x142, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x143, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x146, 0x7, 0x2e, 0x2, 0x2, 0x145, 0x147, 0x5, 0x14, 
    0xb, 0x2, 0x146, 0x145, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14a, 0x7, 0x9, 
    0x2, 0x2, 0x149, 0x14b, 0x5, 0x14, 0xb, 0x2, 0x14a, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14e, 0x5, 0x72, 0x3a, 0x2, 0x14d, 0x14f, 0x5, 0x14, 
    0xb, 0x2, 0x14e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x152, 0x7, 0xa, 
    0x2, 0x2, 0x151, 0x153, 0x5, 0x14, 0xb, 0x2, 0x152, 0x151, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x154, 0x155, 0x5, 0x1c, 0xf, 0x2, 0x155, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x156, 0x158, 0x7, 0x2e, 0x2, 0x2, 0x157, 0x159, 0x5, 0x14, 
    0xb, 0x2, 0x158, 0x157, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15c, 0x7, 0x9, 
    0x2, 0x2, 0x15b, 0x15d, 0x5, 0x14, 0xb, 0x2, 0x15c, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x15c, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 
    0x2, 0x2, 0x15e, 0x160, 0x5, 0x72, 0x3a, 0x2, 0x15f, 0x161, 0x5, 0x14, 
    0xb, 0x2, 0x160, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x162, 0x3, 0x2, 0x2, 0x2, 0x162, 0x164, 0x7, 0xa, 
    0x2, 0x2, 0x163, 0x165, 0x5, 0x14, 0xb, 0x2, 0x164, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x168, 0x5, 0x1a, 0xe, 0x2, 0x167, 0x169, 0x5, 0x14, 
    0xb, 0x2, 0x168, 0x167, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 
    0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16c, 0x7, 0x29, 
    0x2, 0x2, 0x16b, 0x16d, 0x5, 0x14, 0xb, 0x2, 0x16c, 0x16b, 0x3, 0x2, 
    0x2, 0x2, 0x16c, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 
    0x2, 0x2, 0x16e, 0x16f, 0x5, 0x1c, 0xf, 0x2, 0x16f, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x172, 0x7, 0x44, 0x2, 0x2, 0x171, 0x173, 0x5, 0x14, 
    0xb, 0x2, 0x172, 0x171, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x3, 0x2, 
    0x2, 0x2, 0x173, 0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 0x176, 0x7, 0x9, 
    0x2, 0x2, 0x175, 0x177, 0x5, 0x14, 0xb, 0x2, 0x176, 0x175, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x3, 0x2, 
    0x2, 0x2, 0x178, 0x17a, 0x5, 0x72, 0x3a, 0x2, 0x179, 0x17b, 0x5, 0x14, 
    0xb, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17e, 0x7, 0xa, 
    0x2, 0x2, 0x17d, 0x17f, 0x5, 0x14, 0xb, 0x2, 0x17e, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x180, 0x181, 0x5, 0x1c, 0xf, 0x2, 0x181, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x144, 0x3, 0x2, 0x2, 0x2, 0x182, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x170, 0x3, 0x2, 0x2, 0x2, 0x183, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x186, 0x5, 0x12, 0xa, 0x2, 0x185, 0x184, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x186, 0x3, 0x2, 0x2, 0x2, 0x186, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x187, 0x188, 0x5, 0x20, 0x11, 0x2, 0x188, 0x189, 0x5, 0x12, 0xa, 
    0x2, 0x189, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18c, 0x5, 0x22, 0x12, 
    0x2, 0x18b, 0x18d, 0x5, 0x12, 0xa, 0x2, 0x18c, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18f, 0x3, 0x2, 0x2, 
    0x2, 0x18e, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x18f, 0x192, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 
    0x2, 0x190, 0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 0x193, 0x3, 0x2, 0x2, 
    0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x193, 0x195, 0x5, 0x1e, 0x10, 
    0x2, 0x194, 0x196, 0x5, 0x12, 0xa, 0x2, 0x195, 0x194, 0x3, 0x2, 0x2, 
    0x2, 0x195, 0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x197, 0x198, 0x7, 0x5, 0x2, 0x2, 0x198, 0x199, 0x7, 0x14, 0x2, 0x2, 
    0x199, 0x19a, 0x5, 0x72, 0x3a, 0x2, 0x19a, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x19b, 0x19c, 0x7, 0x34, 0x2, 0x2, 0x19c, 0x19d, 0x5, 0x5a, 0x2e, 0x2, 
    0x19d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x40, 0x2, 0x2, 
    0x19f, 0x1a0, 0x7, 0x5, 0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0x14, 0x2, 0x2, 
    0x1a1, 0x1a2, 0x5, 0x72, 0x3a, 0x2, 0x1a2, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x1a3, 0x1a4, 0x7, 0x37, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 0x5, 0x2, 0x2, 
    0x1a5, 0x1a6, 0x7, 0x9, 0x2, 0x2, 0x1a6, 0x1a7, 0x5, 0x68, 0x35, 0x2, 
    0x1a7, 0x1ab, 0x7, 0xa, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x14, 0x2, 0x2, 
    0x1a9, 0x1ac, 0x5, 0x72, 0x3a, 0x2, 0x1aa, 0x1ac, 0x5, 0x1c, 0xf, 0x2, 
    0x1ab, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x1ac, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x49, 0x2, 0x2, 
    0x1ae, 0x1af, 0x7, 0x14, 0x2, 0x2, 0x1af, 0x1b0, 0x5, 0x72, 0x3a, 0x2, 
    0x1b0, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x41, 0x2, 0x2, 
    0x1b2, 0x1b3, 0x7, 0x5, 0x2, 0x2, 0x1b3, 0x1b4, 0x7, 0xb, 0x2, 0x2, 
    0x1b4, 0x1b5, 0x5, 0x38, 0x1d, 0x2, 0x1b5, 0x1b6, 0x7, 0xc, 0x2, 0x2, 
    0x1b6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b9, 0x7, 0x3f, 0x2, 0x2, 
    0x1b8, 0x1ba, 0x5, 0x14, 0xb, 0x2, 0x1b9, 0x1b8, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1bc, 0x7, 0xb, 0x2, 0x2, 0x1bc, 0x1bd, 0x5, 0x3a, 0x1e, 0x2, 
    0x1bd, 0x1be, 0x7, 0xc, 0x2, 0x2, 0x1be, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1bf, 
    0x1c1, 0x7, 0x3d, 0x2, 0x2, 0x1c0, 0x1c2, 0x5, 0x14, 0xb, 0x2, 0x1c1, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 
    0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c5, 0x7, 0x3f, 0x2, 0x2, 0x1c4, 
    0x1c6, 0x5, 0x14, 0xb, 0x2, 0x1c5, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
    0x1c8, 0x7, 0xb, 0x2, 0x2, 0x1c8, 0x1c9, 0x5, 0x3a, 0x1e, 0x2, 0x1c9, 
    0x1ca, 0x7, 0xc, 0x2, 0x2, 0x1ca, 0x35, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cd, 
    0x7, 0x35, 0x2, 0x2, 0x1cc, 0x1ce, 0x5, 0x14, 0xb, 0x2, 0x1cd, 0x1cc, 
    0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 
    0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d1, 0x7, 0x3f, 0x2, 0x2, 0x1d0, 0x1d2, 
    0x5, 0x14, 0xb, 0x2, 0x1d1, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 
    0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 
    0x7, 0xb, 0x2, 0x2, 0x1d4, 0x1d5, 0x5, 0x3a, 0x1e, 0x2, 0x1d5, 0x1d6, 
    0x7, 0xc, 0x2, 0x2, 0x1d6, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d9, 0x5, 
    0x12, 0xa, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x3, 
    0x2, 0x2, 0x2, 0x1d9, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 0x5, 
    0x40, 0x21, 0x2, 0x1db, 0x1dc, 0x5, 0x12, 0xa, 0x2, 0x1dc, 0x1de, 0x3, 
    0x2, 0x2, 0x2, 0x1dd, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x3, 
    0x2, 0x2, 0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 
    0x2, 0x2, 0x2, 0x1e0, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1df, 0x3, 
    0x2, 0x2, 0x2, 0x1e2, 0x1e4, 0x5, 0x40, 0x21, 0x2, 0x1e3, 0x1e2, 0x3, 
    0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e6, 0x3, 
    0x2, 0x2, 0x2, 0x1e5, 0x1e7, 0x5, 0x12, 0xa, 0x2, 0x1e6, 0x1e5, 0x3, 
    0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x1e8, 0x1ea, 0x5, 0x12, 0xa, 0x2, 0x1e9, 0x1e8, 0x3, 0x2, 
    0x2, 0x2, 0x1e9, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1f0, 0x3, 0x2, 
    0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x46, 0x24, 0x2, 0x1ec, 0x1ed, 0x5, 0x12, 
    0xa, 0x2, 0x1ed, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1eb, 0x3, 0x2, 
    0x2, 0x2, 0x1ef, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 
    0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f4, 0x3, 0x2, 
    0x2, 0x2, 0x1f2, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x5, 0x46, 
    0x24, 0x2, 0x1f4, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 
    0x2, 0x2, 0x1f5, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f8, 0x5, 0x12, 
    0xa, 0x2, 0x1f7, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x3, 0x2, 
    0x2, 0x2, 0x1f8, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fb, 0x5, 0x12, 
    0xa, 0x2, 0x1fa, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 0x2, 
    0x2, 0x2, 0x1fb, 0x201, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 0x5, 0x48, 
    0x25, 0x2, 0x1fd, 0x1fe, 0x5, 0x12, 0xa, 0x2, 0x1fe, 0x200, 0x3, 0x2, 
    0x2, 0x2, 0x1ff, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x200, 0x203, 0x3, 0x2, 
    0x2, 0x2, 0x201, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x201, 0x202, 0x3, 0x2, 
    0x2, 0x2, 0x202, 0x205, 0x3, 0x2, 0x2, 0x2, 0x203, 0x201, 0x3, 0x2, 
    0x2, 0x2, 0x204, 0x206, 0x5, 0x48, 0x25, 0x2, 0x205, 0x204, 0x3, 0x2, 
    0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 0x208, 0x3, 0x2, 
    0x2, 0x2, 0x207, 0x209, 0x5, 0x12, 0xa, 0x2, 0x208, 0x207, 0x3, 0x2, 
    0x2, 0x2, 0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x20a, 0x20c, 0x5, 0x12, 0xa, 0x2, 0x20b, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0x20b, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x212, 0x3, 0x2, 0x2, 
    0x2, 0x20d, 0x20e, 0x5, 0x4a, 0x26, 0x2, 0x20e, 0x20f, 0x5, 0x12, 0xa, 
    0x2, 0x20f, 0x211, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20d, 0x3, 0x2, 0x2, 
    0x2, 0x211, 0x214, 0x3, 0x2, 0x2, 0x2, 0x212, 0x210, 0x3, 0x2, 0x2, 
    0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 0x216, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x212, 0x3, 0x2, 0x2, 0x2, 0x215, 0x217, 0x5, 0x4a, 0x26, 
    0x2, 0x216, 0x215, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 0x2, 
    0x2, 0x217, 0x219, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21a, 0x5, 0x12, 0xa, 
    0x2, 0x219, 0x218, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 
    0x2, 0x21a, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21e, 0x5, 0x42, 0x22, 
    0x2, 0x21c, 0x21e, 0x5, 0x44, 0x23, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 
    0x2, 0x21d, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x21f, 0x220, 0x5, 0x48, 0x25, 0x2, 0x220, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x222, 0x5, 0x4a, 0x26, 0x2, 0x222, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x226, 0x5, 0x48, 0x25, 0x2, 0x224, 0x226, 0x5, 0x4a, 0x26, 0x2, 
    0x225, 0x223, 0x3, 0x2, 0x2, 0x2, 0x225, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x226, 0x47, 0x3, 0x2, 0x2, 0x2, 0x227, 0x229, 0x5, 0x50, 0x29, 0x2, 
    0x228, 0x227, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 0x2, 
    0x229, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22c, 0x5, 0x54, 0x2b, 0x2, 
    0x22b, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x3, 0x2, 0x2, 0x2, 
    0x22c, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22f, 0x5, 0x52, 0x2a, 0x2, 
    0x22e, 0x230, 0x5, 0x56, 0x2c, 0x2, 0x22f, 0x22e, 0x3, 0x2, 0x2, 0x2, 
    0x22f, 0x230, 0x3, 0x2, 0x2, 0x2, 0x230, 0x232, 0x3, 0x2, 0x2, 0x2, 
    0x231, 0x233, 0x5, 0x6c, 0x37, 0x2, 0x232, 0x231, 0x3, 0x2, 0x2, 0x2, 
    0x232, 0x233, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 0x2, 
    0x234, 0x236, 0x7, 0x13, 0x2, 0x2, 0x235, 0x237, 0x5, 0x14, 0xb, 0x2, 
    0x236, 0x235, 0x3, 0x2, 0x2, 0x2, 0x236, 0x237, 0x3, 0x2, 0x2, 0x2, 
    0x237, 0x238, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x5, 0x58, 0x2d, 0x2, 
    0x239, 0x49, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23c, 0x5, 0x50, 0x29, 0x2, 
    0x23b, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x3, 0x2, 0x2, 0x2, 
    0x23c, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23f, 0x5, 0x54, 0x2b, 0x2, 
    0x23e, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 0x2, 0x2, 0x2, 
    0x23f, 0x240, 0x3, 0x2, 0x2, 0x2, 0x240, 0x242, 0x5, 0x52, 0x2a, 0x2, 
    0x241, 0x243, 0x5, 0x56, 0x2c, 0x2, 0x242, 0x241, 0x3, 0x2, 0x2, 0x2, 
    0x242, 0x243, 0x3, 0x2, 0x2, 0x2, 0x243, 0x245, 0x3, 0x2, 0x2, 0x2, 
    0x244, 0x246, 0x5, 0x6c, 0x37, 0x2, 0x245, 0x244, 0x3, 0x2, 0x2, 0x2, 
    0x245, 0x246, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 0x3, 0x2, 0x2, 0x2, 
    0x247, 0x249, 0x7, 0x47, 0x2, 0x2, 0x248, 0x24a, 0x5, 0x14, 0xb, 0x2, 
    0x249, 0x248, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x3, 0x2, 0x2, 0x2, 
    0x24a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x5, 0x58, 0x2d, 0x2, 
    0x24c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x5, 0x4e, 0x28, 0x2, 
    0x24e, 0x24f, 0x7, 0xf, 0x2, 0x2, 0x24f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x250, 
    0x251, 0x7, 0x5, 0x2, 0x2, 0x251, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x252, 0x253, 
    0x9, 0x3, 0x2, 0x2, 0x253, 0x254, 0x7, 0xf, 0x2, 0x2, 0x254, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x255, 0x256, 0x5, 0x5c, 0x2f, 0x2, 0x256, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x257, 0x259, 0x5, 0x5e, 0x30, 0x2, 0x258, 0x257, 0x3, 
    0x2, 0x2, 0x2, 0x259, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x258, 0x3, 
    0x2, 0x2, 0x2, 0x25a, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25d, 0x3, 
    0x2, 0x2, 0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x7, 
    0x15, 0x2, 0x2, 0x25e, 0x55, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x263, 0x7, 
    0x16, 0x2, 0x2, 0x260, 0x262, 0x5, 0x5e, 0x30, 0x2, 0x261, 0x260, 0x3, 
    0x2, 0x2, 0x2, 0x262, 0x265, 0x3, 0x2, 0x2, 0x2, 0x263, 0x261, 0x3, 
    0x2, 0x2, 0x2, 0x263, 0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x265, 0x263, 0x3, 0x2, 0x2, 0x2, 0x266, 0x268, 0x5, 0x60, 
    0x31, 0x2, 0x267, 0x266, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26b, 0x3, 0x2, 
    0x2, 0x2, 0x269, 0x267, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x3, 0x2, 
    0x2, 0x2, 0x26a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 
    0x2, 0x26c, 0x26e, 0x5, 0x60, 0x31, 0x2, 0x26d, 0x26c, 0x3, 0x2, 0x2, 
    0x2, 0x26e, 0x271, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x26d, 0x3, 0x2, 0x2, 
    0x2, 0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 0x270, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x271, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x272, 0x277, 0x5, 0x62, 0x32, 0x2, 
    0x273, 0x274, 0x7, 0x9, 0x2, 0x2, 0x274, 0x275, 0x5, 0x68, 0x35, 0x2, 
    0x275, 0x276, 0x7, 0xa, 0x2, 0x2, 0x276, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x273, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27e, 0x5, 0x62, 0x32, 0x2, 
    0x27a, 0x27b, 0x7, 0x9, 0x2, 0x2, 0x27b, 0x27c, 0x5, 0x68, 0x35, 0x2, 
    0x27c, 0x27d, 0x7, 0xa, 0x2, 0x2, 0x27d, 0x27f, 0x3, 0x2, 0x2, 0x2, 
    0x27e, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x3, 0x2, 0x2, 0x2, 
    0x27f, 0x289, 0x3, 0x2, 0x2, 0x2, 0x280, 0x284, 0x7, 0xd, 0x2, 0x2, 
    0x281, 0x283, 0x5, 0x5e, 0x30, 0x2, 0x282, 0x281, 0x3, 0x2, 0x2, 0x2, 
    0x283, 0x286, 0x3, 0x2, 0x2, 0x2, 0x284, 0x282, 0x3, 0x2, 0x2, 0x2, 
    0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 0x287, 0x3, 0x2, 0x2, 0x2, 
    0x286, 0x284, 0x3, 0x2, 0x2, 0x2, 0x287, 0x289, 0x7, 0xe, 0x2, 0x2, 
    0x288, 0x279, 0x3, 0x2, 0x2, 0x2, 0x288, 0x280, 0x3, 0x2, 0x2, 0x2, 
    0x289, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28f, 0x5, 0x64, 0x33, 0x2, 
    0x28b, 0x28c, 0x7, 0x9, 0x2, 0x2, 0x28c, 0x28d, 0x5, 0x6e, 0x38, 0x2, 
    0x28d, 0x28e, 0x7, 0xa, 0x2, 0x2, 0x28e, 0x290, 0x3, 0x2, 0x2, 0x2, 
    0x28f, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x3, 0x2, 0x2, 0x2, 
    0x290, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x291, 0x295, 0x7, 0xd, 0x2, 0x2, 
    0x292, 0x294, 0x5, 0x60, 0x31, 0x2, 0x293, 0x292, 0x3, 0x2, 0x2, 0x2, 
    0x294, 0x297, 0x3, 0x2, 0x2, 0x2, 0x295, 0x293, 0x3, 0x2, 0x2, 0x2, 
    0x295, 0x296, 0x3, 0x2, 0x2, 0x2, 0x296, 0x298, 0x3, 0x2, 0x2, 0x2, 
    0x297, 0x295, 0x3, 0x2, 0x2, 0x2, 0x298, 0x29b, 0x7, 0xe, 0x2, 0x2, 
    0x299, 0x29b, 0x5, 0x1c, 0xf, 0x2, 0x29a, 0x28a, 0x3, 0x2, 0x2, 0x2, 
    0x29a, 0x291, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x299, 0x3, 0x2, 0x2, 0x2, 
    0x29b, 0x61, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x5, 0x66, 0x34, 0x2, 
    0x29d, 0x63, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29f, 0x5, 0x66, 0x34, 0x2, 
    0x29f, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a1, 0x9, 0x4, 0x2, 0x2, 0x2a1, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a7, 0x5, 0x6a, 0x36, 0x2, 0x2a3, 
    0x2a4, 0x7, 0x11, 0x2, 0x2, 0x2a4, 0x2a6, 0x5, 0x6a, 0x36, 0x2, 0x2a5, 
    0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
    0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 
    0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ab, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x7, 0x5, 0x2, 0x2, 0x2ad, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 0x7, 0xf, 0x2, 0x2, 0x2af, 0x2b0, 
    0x5, 0x72, 0x3a, 0x2, 0x2b0, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b6, 
    0x5, 0x70, 0x39, 0x2, 0x2b2, 0x2b3, 0x7, 0x11, 0x2, 0x2, 0x2b3, 0x2b5, 
    0x5, 0x70, 0x39, 0x2, 0x2b4, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b8, 
    0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 
    0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b6, 
    0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2bb, 0x7, 0x11, 0x2, 0x2, 0x2ba, 0x2b9, 
    0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2bd, 
    0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 
    0x3, 0x2, 0x2, 0x2, 0x2bd, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x5, 
    0x72, 0x3a, 0x2, 0x2bf, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0x8, 
    0x3a, 0x1, 0x2, 0x2c1, 0x2c2, 0x7, 0x9, 0x2, 0x2, 0x2c2, 0x2c3, 0x5, 
    0x72, 0x3a, 0x2, 0x2c3, 0x2c4, 0x7, 0xa, 0x2, 0x2, 0x2c4, 0x2d3, 0x3, 
    0x2, 0x2, 0x2, 0x2c5, 0x2d3, 0x5, 0x78, 0x3d, 0x2, 0x2c6, 0x2d3, 0x7, 
    0x5, 0x2, 0x2, 0x2c7, 0x2c8, 0x9, 0x5, 0x2, 0x2, 0x2c8, 0x2d3, 0x5, 
    0x72, 0x3a, 0xf, 0x2c9, 0x2ca, 0x9, 0x6, 0x2, 0x2, 0x2ca, 0x2d3, 0x5, 
    0x72, 0x3a, 0xe, 0x2cb, 0x2cc, 0x7, 0x2e, 0x2, 0x2, 0x2cc, 0x2cd, 0x5, 
    0x72, 0x3a, 0x2, 0x2cd, 0x2ce, 0x7, 0x42, 0x2, 0x2, 0x2ce, 0x2cf, 0x5, 
    0x72, 0x3a, 0x2, 0x2cf, 0x2d0, 0x7, 0x29, 0x2, 0x2, 0x2d0, 0x2d1, 0x5, 
    0x72, 0x3a, 0x3, 0x2d1, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2c0, 0x3, 
    0x2, 0x2, 0x2, 0x2d2, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2c6, 0x3, 
    0x2, 0x2, 0x2, 0x2d2, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2c9, 0x3, 
    0x2, 0x2, 0x2, 0x2d2, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2f9, 0x3, 
    0x2, 0x2, 0x2, 0x2d4, 0x2d5, 0xc, 0xd, 0x2, 0x2, 0x2d5, 0x2d6, 0x7, 
    0x20, 0x2, 0x2, 0x2d6, 0x2f8, 0x5, 0x72, 0x3a, 0xd, 0x2d7, 0x2d8, 0xc, 
    0xc, 0x2, 0x2, 0x2d8, 0x2d9, 0x9, 0x7, 0x2, 0x2, 0x2d9, 0x2f8, 0x5, 
    0x72, 0x3a, 0xd, 0x2da, 0x2db, 0xc, 0xb, 0x2, 0x2, 0x2db, 0x2dc, 0x9, 
    0x5, 0x2, 0x2, 0x2dc, 0x2f8, 0x5, 0x72, 0x3a, 0xc, 0x2dd, 0x2de, 0xc, 
    0xa, 0x2, 0x2, 0x2de, 0x2df, 0x9, 0x8, 0x2, 0x2, 0x2df, 0x2f8, 0x5, 
    0x72, 0x3a, 0xb, 0x2e0, 0x2e1, 0xc, 0x9, 0x2, 0x2, 0x2e1, 0x2e2, 0x9, 
    0x9, 0x2, 0x2, 0x2e2, 0x2f8, 0x5, 0x72, 0x3a, 0xa, 0x2e3, 0x2e4, 0xc, 
    0x8, 0x2, 0x2, 0x2e4, 0x2e5, 0x7, 0x21, 0x2, 0x2, 0x2e5, 0x2f8, 0x5, 
    0x72, 0x3a, 0x9, 0x2e6, 0x2e7, 0xc, 0x7, 0x2, 0x2, 0x2e7, 0x2e8, 0x7, 
    0x23, 0x2, 0x2, 0x2e8, 0x2f8, 0x5, 0x72, 0x3a, 0x8, 0x2e9, 0x2ea, 0xc, 
    0x6, 0x2, 0x2, 0x2ea, 0x2eb, 0x7, 0x22, 0x2, 0x2, 0x2eb, 0x2f8, 0x5, 
    0x72, 0x3a, 0x7, 0x2ec, 0x2ed, 0xc, 0x5, 0x2, 0x2, 0x2ed, 0x2ee, 0x7, 
    0x25, 0x2, 0x2, 0x2ee, 0x2f8, 0x5, 0x72, 0x3a, 0x6, 0x2ef, 0x2f0, 0xc, 
    0x4, 0x2, 0x2, 0x2f0, 0x2f1, 0x7, 0x26, 0x2, 0x2, 0x2f1, 0x2f8, 0x5, 
    0x72, 0x3a, 0x5, 0x2f2, 0x2f3, 0xc, 0x10, 0x2, 0x2, 0x2f3, 0x2f4, 0x7, 
    0x9, 0x2, 0x2, 0x2f4, 0x2f5, 0x5, 0x74, 0x3b, 0x2, 0x2f5, 0x2f6, 0x7, 
    0xa, 0x2, 0x2, 0x2f6, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2d4, 0x3, 
    0x2, 0x2, 0x2, 0x2f7, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2da, 0x3, 
    0x2, 0x2, 0x2, 0x2f7, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2e0, 0x3, 
    0x2, 0x2, 0x2, 0x2f7, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2e6, 0x3, 
    0x2, 0x2, 0x2, 0x2f7, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2ec, 0x3, 
    0x2, 0x2, 0x2, 0x2f7, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f2, 0x3, 
    0x2, 0x2, 0x2, 0x2f8, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2f7, 0x3, 
    0x2, 0x2, 0x2, 0x2f9, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x73, 0x3, 0x2, 
    0x2, 0x2, 0x2fb, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x301, 0x5, 0x76, 
    0x3c, 0x2, 0x2fd, 0x2fe, 0x7, 0x11, 0x2, 0x2, 0x2fe, 0x300, 0x5, 0x76, 
    0x3c, 0x2, 0x2ff, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x300, 0x303, 0x3, 0x2, 
    0x2, 0x2, 0x301, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x301, 0x302, 0x3, 0x2, 
    0x2, 0x2, 0x302, 0x305, 0x3, 0x2, 0x2, 0x2, 0x303, 0x301, 0x3, 0x2, 
    0x2, 0x2, 0x304, 0x306, 0x7, 0x11, 0x2, 0x2, 0x305, 0x304, 0x3, 0x2, 
    0x2, 0x2, 0x305, 0x306, 0x3, 0x2, 0x2, 0x2, 0x306, 0x308, 0x3, 0x2, 
    0x2, 0x2, 0x307, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x3, 0x2, 
    0x2, 0x2, 0x308, 0x75, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30a, 0x5, 0x72, 
    0x3a, 0x2, 0x30a, 0x77, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x312, 0x7, 0x6, 
    0x2, 0x2, 0x30c, 0x312, 0x7, 0x7, 0x2, 0x2, 0x30d, 0x312, 0x7, 0x8, 
    0x2, 0x2, 0x30e, 0x312, 0x7, 0x32, 0x2, 0x2, 0x30f, 0x312, 0x7, 0x2b, 
    0x2, 0x2, 0x310, 0x312, 0x7, 0x3b, 0x2, 0x2, 0x311, 0x30b, 0x3, 0x2, 
    0x2, 0x2, 0x311, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x311, 0x30d, 0x3, 0x2, 
    0x2, 0x2, 0x311, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x311, 0x30f, 0x3, 0x2, 
    0x2, 0x2, 0x311, 0x310, 0x3, 0x2, 0x2, 0x2, 0x312, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x80, 0x85, 0x8c, 0x90, 0x93, 0x98, 0x9c, 0xa9, 0xae, 0xb7, 
    0xbc, 0xbf, 0xc6, 0xca, 0xcd, 0xd7, 0xdb, 0xdf, 0xe5, 0xec, 0xf0, 0xf4, 
    0xf8, 0xfc, 0x102, 0x106, 0x10a, 0x10e, 0x112, 0x116, 0x11c, 0x120, 
    0x124, 0x128, 0x12e, 0x132, 0x136, 0x13a, 0x13e, 0x142, 0x146, 0x14a, 
    0x14e, 0x152, 0x158, 0x15c, 0x160, 0x164, 0x168, 0x16c, 0x172, 0x176, 
    0x17a, 0x17e, 0x182, 0x185, 0x18c, 0x18e, 0x190, 0x195, 0x1ab, 0x1b9, 
    0x1c1, 0x1c5, 0x1cd, 0x1d1, 0x1d8, 0x1df, 0x1e3, 0x1e6, 0x1e9, 0x1f0, 
    0x1f4, 0x1f7, 0x1fa, 0x201, 0x205, 0x208, 0x20b, 0x212, 0x216, 0x219, 
    0x21d, 0x225, 0x228, 0x22b, 0x22f, 0x232, 0x236, 0x23b, 0x23e, 0x242, 
    0x245, 0x249, 0x25a, 0x263, 0x269, 0x26f, 0x277, 0x27e, 0x284, 0x288, 
    0x28f, 0x295, 0x29a, 0x2a7, 0x2aa, 0x2b6, 0x2ba, 0x2bc, 0x2d2, 0x2f7, 
    0x2f9, 0x301, 0x305, 0x307, 0x311, 
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
