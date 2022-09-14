
// Generated from LSysDLexer.g4 by ANTLR 4.11.1

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
    KWNONE = 47, KWTRUE = 48, KWAND = 49, KWAXIOM = 50, KWCODING = 51, KWDO = 52, 
    KWFUNCTION = 53, KWLSYS = 54, KWMAIN = 55, KWNOT = 56, KWNULL = 57, 
    KWOR = 58, KWPRODUCTION = 59, KWRETURN = 60, KWRULES = 61, KWSET = 62, 
    KWTABLE = 63, KWTHEN = 64, KWVAR = 65, KWWHILE = 66, QM = 67, XM = 68, 
    DARROW = 69, FDIV = 70, DOLLARID = 71, RULECHAR = 72, WS = 73, COMMENTBLQ = 74, 
    COMMENTLIN = 75, LINE_JOINING = 76, NEW_LINE = 77, ERRORCHAR = 78
  };

  explicit LSysDLexer(antlr4::CharStream *input);

  ~LSysDLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

