/**
 * Gramática de LSysDParser
 */
parser grammar LSysDParser;

options { tokenVocab=LSysDLexer; language=Cpp; }

//options {LSysDLexer};

main
  : module EOF
  | inLsysDefs EOF
//   | nl? word nl? EOF
  ;

module
  : /*imports*/ globalDefs
  ;

globalDefs
  : sep? (globalDef sep)* globalDef? sep?
  ;

globalDef
  : lsystem
  | declaration
  | funcDef
  ;

declaration
  : varDeclaration
  | constDeclaration
  ;

varDeclaration
  : KWVAR ID (ASSIGN expression)
  ;

constDeclaration
  : KWSET ID ASSIGN expression
  ;

lsystem
  : KWLSYS ID nl? LBRACE inLsysDefs RBRACE
  ;

sep
  : (SEMI | NEW_LINE)+
  ;

nl
  : NEW_LINE+
  ;

inLsysDefs
  : sep? (inLsysDef sep)* inLsysDef? sep?
  ;

inLsysDef
  : axiomDef
  | statement
  | funcDef
  | tableBlock
  | rulesBlock
  | productionRulesBlock
  | codingRulesBlock
  | ruleDef
  ;

blockOrOneStatement
  : block
  | oneStatement
  ;

block
  : LBRACE statement? RBRACE
  ;

oneStatement
  : oneStmtNeedsSep | oneStmtEndsInBlock
  ;

oneStmtNeedsSep
  : expression
  | assignment
  | declaration
  | KWRETURN expression?
  | KWIF nl? LPAREN nl? expression nl? RPAREN nl? oneStmtNeedsSep
  | KWIF nl? LPAREN nl? expression nl? RPAREN nl? blockOrOneStatement nl? KWELSE nl? oneStmtNeedsSep
  | KWWHILE nl? LPAREN nl? expression nl? RPAREN nl? oneStmtNeedsSep
  | KWDO nl? blockOrOneStatement nl? KWWHILE nl? LPAREN nl? expression nl? RPAREN
  ;

oneStmtEndsInBlock
  : KWIF nl? LPAREN nl? expression nl? RPAREN nl? block
  | KWIF nl? LPAREN nl? expression nl? RPAREN nl? blockOrOneStatement nl? KWELSE nl? block
  | KWWHILE nl? LPAREN nl? expression nl? RPAREN nl? block
  ;

statement
  : sep? (oneStmtNeedsSep sep | oneStmtEndsInBlock sep?)* oneStatement sep?
  ;

assignment
  : ID ASSIGN expression
  ;

axiomDef
  : KWAXIOM word
  ;

propDef
  : KWSET ID ASSIGN expression
  ;

funcDef
  : KWFUNCTION ID LPAREN params RPAREN (ASSIGN expression | block)
  ;

constDef
  : DOLLARID ASSIGN expression
  ;

tableBlock
  : KWTABLE ID LBRACE rules RBRACE
  ;

rulesBlock
  : KWRULES nl? LBRACE ruleDefs RBRACE
  ;

productionRulesBlock
  : KWPRODUCTION nl? KWRULES nl? LBRACE ruleDefs RBRACE
  ;

codingRulesBlock
  : KWCODING nl? KWRULES nl? LBRACE ruleDefs RBRACE
  ;

rules
  : sep? (anyRule sep)* anyRule? sep?
  ;

ruleDefs
  : sep? (ruleDef sep)* ruleDef? sep?
  ;

productionRuleDefs
  : sep? (productionRuleDef sep)* productionRuleDef? sep?
  ;

codingRuleDefs
  : sep? (codingRuleDef sep)* codingRuleDef? sep?
  ;

anyRule
  : productionRule
  | codingRule
  ;

productionRule
  : productionRuleDef // | tag
  ;

codingRule
  : codingRuleDef
  ;

ruleDef
  : productionRuleDef | codingRuleDef
  ;

productionRuleDef
  : weight? lcontext? lside rcontext? cond? ARROW nl? rside //weight?
  ;

codingRuleDef
  : weight? lcontext? lside rcontext? cond? DARROW nl? rside //weight?
  ;

tagPrefix
  : tag COLON
  ;

tag
  : ID
  ;

weight
  : (INT | FLOAT | XM) COLON
  ;

lside
  : lChar
  ;

lcontext
  : lItem* LT
  ;

rcontext
  : GT lItem*
  ;

rside
  : rItem*
  ;

word
  : rItem*
  ;

lChar
  : validLeftChar (LPAREN params RPAREN)?
  ;

lItem
  : validLeftChar (LPAREN params RPAREN)?
  | LBRACK lItem* RBRACK
  ;

rItem
  : validRightChar (LPAREN args RPAREN)?
  | LBRACK rItem* RBRACK
  | block
  ;

validLeftChar
  : validChar
  ;

validRightChar
  : validChar
  ;

validChar
  : (ID|INT|ADD|SUB|RULECHAR)
  ;

params
  : ( param (COMMA param)* )?
  ;

param
  : ID
  ;

cond
  : COLON expression
  ;

args
  : ( arg (COMMA arg)* COMMA? )?
  ;

arg
  : expression
  ;

expression
  : LPAREN expression RPAREN                                                # ParenthesizedExpr
  | constant                                                                # ConstExpr
//   | listdef                                                                 # ListDefExpr
//   | tupledef                                                                # TupleDefExpr
//   | mapdef                                                                  # MapDefExpr
//   | setdef                                                                  # SetDefExpr
  | ID                                                                      # IdExpr
//   | expression ACCESSOR                                                     # PropertyAccessorExpr
  | expression LPAREN arguments RPAREN                                      # FunctionCallExpr
//   | expression LBRACK index RBRACK                                          # IndexExpr
  | op=(ADD | SUB) expression                                               # AritUnaryExpr
  | op=(NOT | BITNOT) expression                                            # LogicUnaryExpr
  |<assoc=right> expression op=POW expression                               # AritBinaryExpr
  | expression op=(MUL | DIV | MOD) expression                              # AritBinaryExpr
  | expression op=(ADD | SUB) expression                                    # AritBinaryExpr
  | expression op=(LT | GT | LE | GE) expression                            # CmpBinaryExpr
  | expression op=(EQ | NE) expression                                      # CmpBinaryExpr
  | expression op=BITAND expression                                         # BitBinaryExpr
  | expression op=BITXOR expression                                         # BitBinaryExpr
  | expression op=BITOR expression                                          # BitBinaryExpr
  | expression op=AND expression                                            # LogicBinaryExpr
  | expression op=OR expression                                             # LogicBinaryExpr
  |<assoc=right> KWIF expression KWTHEN expression KWELSE expression        # IfElseExpr
//   | expression neg=NOT? op=KWIN expression                                  # InExpr
//   | functiondef                                                             # FunctionDefExpr
  ;

arguments
  : (argument (COMMA argument)* COMMA?)?
  ;

argument
  : expression
//  | ID ASSIGN expression
  ;

// indexes
//   : (index (COMMA index)* COMMA?)?
//   ;

// index
//   : expression
//   | expression? COLON expression? (COLON expression?)?
//   ;

// formalParameters
//   : (formalParameter (COMMA formalParameter)*)?
//   ;

// formalParameter
//   : ID (ASSIGN expression)?
//   ;

// iteratordef
//   : (expression KWFOR)? source (KWIF expression)? (COMMA source (KWIF expression)?)*
//   ;

// listdef
//   : LBRACK iteratordef RBRACK
//   | LBRACK (expression (COMMA expression)*)? COMMA? RBRACK
//   ;

// tupledef
//   : LPAREN expression (COMMA | (COMMA expression)+ COMMA?) RPAREN
//   ;

// setdef
//   : LBRACE iteratordef RBRACE
//   | LBRACE (expression (COMMA expression)*)? COMMA? RBRACE
//   ;

// mapdef
//   : LBRACE mapiteratordef RBRACE
//   | LBRACE (mapitem (COMMA mapitem)*)? COMMA? RBRACE
//   ;

// mapiteratordef
//   : mapitem KWFOR source (KWIF expression)? (COMMA source (KWIF expression)?)*
//   ;

// mapitem
//   : expression COLON expression
//   ;

// functiondef
//   : fp=formalParameters ARROW body=expression
//   ;

// source
//   : ID KWIN expression
//   ;

// Literals
///////////////////////////////////////////////////////////////////////////////////////////////////

//$ctx.getParent()

constant
  : v=INT                 # IntConstant
  | v=FLOAT               # FloatConstant
  | v=STRING              # StringConstant
//   | KWNAN                 # NanValue
//   | KWINF                 # InfValue
  | KWTRUE                # TrueValue
  | KWFALSE               # FalseValue
  | KWNULL                # NullValue
  ;

