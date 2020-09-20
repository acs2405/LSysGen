
// Generated from LSysDLexer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  LSysDLexer : public antlr4::Lexer {
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

  LSysDLexer(antlr4::CharStream *input);
  ~LSysDLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

