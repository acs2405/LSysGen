lexer grammar LSysDLexer;

tokens {EOL, ACCESSOR, ID, INT, FLOAT, STRING, LPAREN, RPAREN, LBRACE, RBRACE, LBRACK, RBRACK, COLON, SEMI, COMMA, DOT, ARROW, ASSIGN, LT, GT, LE, GE, EQ, NE, ADD, SUB, MUL, DIV, MOD, POW, BITAND, BITOR, BITXOR, BITNOT, AND, OR, NOT, KWAS, KWELSE, KWEVENTSPEC, KWFALSE, KWFOR, KWFROM, KWIF, KWIMPORT, KWIN, KWNONE, KWTRUE}

// @header {
// inRuleMode = False
// def ruleMode(val):
//     global inRuleMode
//     inRuleMode = val
//     print("Miau a ", val)
// }

// Compound tokens
///////////////////////////////////////////////////////////////////////////////////////////////////

ACCESSOR
  : DOT ID
  ;

//DECORATOR
//  : AT ID //{$dec = new Decorator($ID.text);}
//  ;

INT
  : DECINT
  | HEXINT
  ;

fragment DECINT
  : DIG+
  ;

fragment HEXINT
  : '0x' [0-9a-fA-F]+
  ;

fragment FL
  : DIG+ DOT DIG*
  | DOT DIG+
  ;

FLOAT
  : FL
  | FL [eE] [-+]? DIG+
  ;

STRING
  : ESCSTR
  | RAWSTR
  ;

fragment ESCSTR
  : DQUOT (ESCSTRCONT*) DQUOT
  | SQUOT (ESCSTRCONT*) SQUOT
  ;

fragment RAWSTR
  : 'r' DQUOT (RAWSTRCONT*?) DQUOT
  | 'r' SQUOT (RAWSTRCONT*?) SQUOT
  ;

fragment ESCSTRCONT
  : ~[\\\r\n'"]
  | BSLASH ESCSTRESC
  ;

fragment RAWSTRCONT
  : ~[\\\r\n'"]
  | BSLASH RAWSTRESC
  ;

fragment ESCSTRESC
  : 'n'
  | 'r'
  | 't'
  | 'f'
  | 'v'
  | '0'
  | BSLASH
  | QUOT
  ;

fragment RAWSTRESC
  : QUOT
  ;

fragment QUOT
  : DQUOT
  | SQUOT
  ;

// Keywords
///////////////////////////////////////////////////////////////////////////////////////////////////

KWAND: 'and';
KWCODING: 'coding';
KWELSE: 'else';
KWFALSE: 'False';
KWFOR: 'for';
//KWFROM: 'from';
KWIF: 'if';
//KWIMPORT: 'import';
KWIN: 'in';
//KWINF: 'Inf';
KWLAMBDA: 'lambda';
KWLSYS: 'lsystem';
//KWNAN: 'Nan';
KWNOT: 'not';
KWNONE: 'None';
KWOR: 'or';
KWPRODUCTION: 'production';
KWRULES: 'rules';
KWSET: 'set';
KWTABLE: 'table';
KWTHEN: 'then';
KWTRUE: 'True';

// Separators
///////////////////////////////////////////////////////////////////////////////////////////////////

LPAREN : '(';
RPAREN : ')';
LBRACE : '{';
RBRACE : '}';
LBRACK : '[';
RBRACK : ']';
COLON  : ':';
SEMI   : ';';
COMMA  : ',';
DOT    : '.';
QM     : '?';
XM     : '!';

// Operators
///////////////////////////////////////////////////////////////////////////////////////////////////

fragment DIG: [0-9];
fragment LET: [a-zA-Z];

fragment DQUOT: '"';
fragment SQUOT: '\'';
fragment BSLASH: '\\';
//fragment AT: '@';

ARROW : '->';
DARROW : '=>';

ASSIGN : '=';

GT : '>';
LT : '<';
EQ : '==';
LE : '<=';
GE : '>=';
NE : '!=';

ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
FDIV : '//';
MOD : '%';
POW : '**';

BITAND : '&';
BITOR : '|';
BITXOR : '^';
BITNOT : '~';

AND: KWAND;
OR: KWOR;
NOT: KWNOT;

// Identifiers
///////////////////////////////////////////////////////////////////////////////////////////////////

ID : [_a-zA-Z][_a-zA-Z0-9]*;
DOLLARID : '$' [_a-zA-Z][_a-zA-Z0-9]*;

//UNDERSCORE : '_';

RULECHAR : ~[ \t\r\n\f()[\]{}$<>#_];

// Whitespace and comments
///////////////////////////////////////////////////////////////////////////////////////////////////

//SKIP_ : (WS | COMMENTBLQ | COMMENTLIN | LINE_JOINING) -> channel(HIDDEN);

WS : [ \t]+ -> channel(1);                              // Ignoramos espacios en blanco
COMMENTBLQ : '#*' .*? '*#' -> channel(2);               // Comentarios multilínea
COMMENTLIN : '#' ~[\r\n\f]* -> channel(2);              // Comentarios en línea
//JDCOMMENTBLQ : '/**' .*? '*/' -> channel(HIDDEN);     // Comentarios estilo JavaDoc
LINE_JOINING : BSLASH WS? NEW_LINE -> skip;

NEW_LINE    : ( '\r'? '\n' | '\r' | '\f');

// Catch-all error for better error messages
///////////////////////////////////////////////////////////////////////////////////////////////////

ERRORCHAR : . ;