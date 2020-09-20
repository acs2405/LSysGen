/**
 * Gramática de LSysDParser
 */
parser grammar LSysDParser;

options { tokenVocab=LSysDLexer; language=Cpp; }

//options {LSysDLexer};

main
  : sep? ((name nl? LBRACE sep? definitions sep? RBRACE sep?)?) EOF
  | sep? (definitions sep?) EOF
  | nl? word nl? EOF
  ;

sep
  : (SEMI | NEW_LINE)+
  ;

nl
  : NEW_LINE+
  ;

name
  : KWLSYS ID
  ;

definitions
  : (definition sep)* definition?
  ;

definition
  : axiomDef
  | propDef
  | funcDef
  | tableBlock
  | rulesBlock
  | productionRulesBlock
  | codingRulesBlock
  | ruleDef
  ;

axiomDef
  : KWAXIOM word
  ;

propDef
  : KWSET ID ASSIGN expression
  ;

funcDef
  : KWSET ID LPAREN params RPAREN ASSIGN expression
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
  : productionRuleDef | tag
  ;

codingRule
  : codingRuleDef
  ;

ruleDef
  : productionRuleDef | codingRuleDef
  ;

productionRuleDef
  : tagPrefix? weight? lcontext? lside rcontext? ARROW nl? rside
  ;

codingRuleDef
  : tagPrefix? weight? lcontext? lside rcontext? DARROW nl? rside
  ;

tagPrefix
  : tag COLON
  ;

tag
  : ID
  ;

weight
  : LPAREN INT RPAREN
  | LPAREN XM RPAREN
  | XM
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
  : validLeftChar (LPAREN paramsWithCond RPAREN)?
  ;

lItem
  : validLeftChar (LPAREN paramsWithCond RPAREN)?
  | LBRACK lItem* RBRACK
  ;

rItem
  : validRightChar (LPAREN args RPAREN)?
  | LBRACK rItem* RBRACK
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

paramsWithCond
  : params ( BITOR cond )?
  ;

params
  : ( param (COMMA param)* )?
  ;

param
  : ID
  ;

cond
  : expression
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
  | (ADD | SUB) expression                                                  # AritUnaryExpr
  | (NOT | BITNOT) expression                                               # LogicUnaryExpr
  |<assoc=right> expression (POW) expression                                # AritBinaryExpr
  | expression (MUL | DIV | MOD) expression                                 # AritBinaryExpr
  | expression (ADD | SUB) expression                                       # AritBinaryExpr
  | expression (LT | GT | LE | GE) expression                               # CmpBinaryExpr
  | expression (EQ | NE) expression                                         # CmpBinaryExpr
  | expression (BITAND) expression                                          # BitBinaryExpr
  | expression (BITXOR) expression                                          # BitBinaryExpr
  | expression (BITOR) expression                                           # BitBinaryExpr
  | expression (AND) expression                                             # LogicBinaryExpr
  | expression (OR) expression                                              # LogicBinaryExpr
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
//   | KWNONE                # NullValue
  ;

