
// Generated from LSysDParser.g4 by ANTLR 4.11.1


#include "LSysDParserVisitor.h"

#include "LSysDParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LSysDParserStaticData final {
  LSysDParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LSysDParserStaticData(const LSysDParserStaticData&) = delete;
  LSysDParserStaticData(LSysDParserStaticData&&) = delete;
  LSysDParserStaticData& operator=(const LSysDParserStaticData&) = delete;
  LSysDParserStaticData& operator=(LSysDParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lsysdparserParserOnceFlag;
LSysDParserStaticData *lsysdparserParserStaticData = nullptr;

void lsysdparserParserInitialize() {
  assert(lsysdparserParserStaticData == nullptr);
  auto staticData = std::make_unique<LSysDParserStaticData>(
    std::vector<std::string>{
      "main", "mainWord", "mainRuleDefs", "module", "globalDefs", "globalDef", 
      "declaration", "varDeclaration", "constDeclaration", "lsystem", "sep", 
      "nl", "inLsysDefs", "inLsysDef", "blockOrOneStatement", "block", "oneStatement", 
      "oneStmtNeedsSep", "oneStmtEndsInBlock", "statement", "assignment", 
      "axiomDef", "propDef", "funcDef", "constDef", "tableBlock", "rulesBlock", 
      "productionRulesBlock", "codingRulesBlock", "rules", "ruleDefs", "productionRuleDefs", 
      "codingRuleDefs", "anyRule", "productionRule", "codingRule", "ruleDef", 
      "productionRuleDef", "codingRuleDef", "tagPrefix", "tag", "weight", 
      "lside", "lcontext", "rcontext", "rside", "word", "lChar", "lItem", 
      "rItem", "validLeftChar", "validRightChar", "validChar", "params", 
      "param", "cond", "args", "arg", "expression", "arguments", "argument", 
      "constant"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "'('", "')'", "'{'", "'}'", "'['", "']'", 
      "':'", "';'", "','", "'.'", "'->'", "'='", "'<'", "'>'", "'<='", "'>='", 
      "'=='", "'!='", "'+'", "'-'", "'*'", "'/'", "'%'", "'**'", "'&'", 
      "'|'", "'^'", "'~'", "", "", "", "", "'else'", "", "'false'", "'for'", 
      "", "'if'", "", "'in'", "", "'true'", "'and'", "'axiom'", "'coding'", 
      "'do'", "'function'", "'lsystem'", "'main'", "'not'", "'null'", "'or'", 
      "'production'", "'return'", "'rules'", "'set'", "'table'", "'then'", 
      "'var'", "'while'", "'\\u003F'", "'!'", "'=>'", "'//'"
    },
    std::vector<std::string>{
      "", "EOL", "ACCESSOR", "ID", "INT", "FLOAT", "STRING", "LPAREN", "RPAREN", 
      "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COLON", "SEMI", "COMMA", 
      "DOT", "ARROW", "ASSIGN", "LT", "GT", "LE", "GE", "EQ", "NE", "ADD", 
      "SUB", "MUL", "DIV", "MOD", "POW", "BITAND", "BITOR", "BITXOR", "BITNOT", 
      "AND", "OR", "NOT", "KWAS", "KWELSE", "KWEVENTSPEC", "KWFALSE", "KWFOR", 
      "KWFROM", "KWIF", "KWIMPORT", "KWIN", "KWNONE", "KWTRUE", "KWAND", 
      "KWAXIOM", "KWCODING", "KWDO", "KWFUNCTION", "KWLSYS", "KWMAIN", "KWNOT", 
      "KWNULL", "KWOR", "KWPRODUCTION", "KWRETURN", "KWRULES", "KWSET", 
      "KWTABLE", "KWTHEN", "KWVAR", "KWWHILE", "QM", "XM", "DARROW", "FDIV", 
      "DOLLARID", "RULECHAR", "WS", "COMMENTBLQ", "COMMENTLIN", "LINE_JOINING", 
      "NEW_LINE", "ERRORCHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,78,809,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,1,0,1,0,1,0,1,0,
  	1,0,1,0,3,0,131,8,0,1,1,5,1,134,8,1,10,1,12,1,137,9,1,1,1,1,1,5,1,141,
  	8,1,10,1,12,1,144,9,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,4,3,4,154,8,4,1,4,
  	1,4,1,4,5,4,159,8,4,10,4,12,4,162,9,4,1,4,3,4,165,8,4,1,4,3,4,168,8,4,
  	1,5,1,5,1,5,3,5,173,8,5,1,6,1,6,3,6,177,8,6,1,7,1,7,1,7,1,7,3,7,183,8,
  	7,1,8,1,8,1,8,1,8,1,8,1,9,3,9,191,8,9,1,9,1,9,1,9,3,9,196,8,9,1,9,1,9,
  	1,9,1,9,1,10,4,10,203,8,10,11,10,12,10,204,1,11,4,11,208,8,11,11,11,12,
  	11,209,1,12,3,12,213,8,12,1,12,1,12,1,12,5,12,218,8,12,10,12,12,12,221,
  	9,12,1,12,3,12,224,8,12,1,12,3,12,227,8,12,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,3,13,237,8,13,1,14,1,14,3,14,241,8,14,1,15,1,15,3,15,245,
  	8,15,1,15,1,15,1,16,1,16,3,16,251,8,16,1,17,1,17,1,17,1,17,1,17,3,17,
  	258,8,17,1,17,1,17,3,17,262,8,17,1,17,1,17,3,17,266,8,17,1,17,1,17,3,
  	17,270,8,17,1,17,1,17,3,17,274,8,17,1,17,1,17,1,17,1,17,3,17,280,8,17,
  	1,17,1,17,3,17,284,8,17,1,17,1,17,3,17,288,8,17,1,17,1,17,3,17,292,8,
  	17,1,17,1,17,3,17,296,8,17,1,17,1,17,3,17,300,8,17,1,17,1,17,1,17,1,17,
  	3,17,306,8,17,1,17,1,17,3,17,310,8,17,1,17,1,17,3,17,314,8,17,1,17,1,
  	17,3,17,318,8,17,1,17,1,17,1,17,1,17,3,17,324,8,17,1,17,1,17,3,17,328,
  	8,17,1,17,1,17,3,17,332,8,17,1,17,1,17,3,17,336,8,17,1,17,1,17,3,17,340,
  	8,17,1,17,1,17,3,17,344,8,17,1,18,1,18,3,18,348,8,18,1,18,1,18,3,18,352,
  	8,18,1,18,1,18,3,18,356,8,18,1,18,1,18,3,18,360,8,18,1,18,1,18,1,18,1,
  	18,3,18,366,8,18,1,18,1,18,3,18,370,8,18,1,18,1,18,3,18,374,8,18,1,18,
  	1,18,3,18,378,8,18,1,18,1,18,3,18,382,8,18,1,18,1,18,3,18,386,8,18,1,
  	18,1,18,1,18,1,18,3,18,392,8,18,1,18,1,18,3,18,396,8,18,1,18,1,18,3,18,
  	400,8,18,1,18,1,18,3,18,404,8,18,1,18,1,18,3,18,408,8,18,1,19,3,19,411,
  	8,19,1,19,1,19,1,19,1,19,1,19,3,19,418,8,19,5,19,420,8,19,10,19,12,19,
  	423,9,19,1,19,1,19,3,19,427,8,19,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,
  	22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,449,
  	8,23,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,3,26,
  	463,8,26,1,26,1,26,1,26,1,26,1,27,1,27,3,27,471,8,27,1,27,1,27,3,27,475,
  	8,27,1,27,1,27,1,27,1,27,1,28,1,28,3,28,483,8,28,1,28,1,28,3,28,487,8,
  	28,1,28,1,28,1,28,1,28,1,29,3,29,494,8,29,1,29,1,29,1,29,5,29,499,8,29,
  	10,29,12,29,502,9,29,1,29,3,29,505,8,29,1,29,3,29,508,8,29,1,30,3,30,
  	511,8,30,1,30,1,30,1,30,5,30,516,8,30,10,30,12,30,519,9,30,1,30,3,30,
  	522,8,30,1,30,3,30,525,8,30,1,31,3,31,528,8,31,1,31,1,31,1,31,5,31,533,
  	8,31,10,31,12,31,536,9,31,1,31,3,31,539,8,31,1,31,3,31,542,8,31,1,32,
  	3,32,545,8,32,1,32,1,32,1,32,5,32,550,8,32,10,32,12,32,553,9,32,1,32,
  	3,32,556,8,32,1,32,3,32,559,8,32,1,33,1,33,3,33,563,8,33,1,34,1,34,1,
  	35,1,35,1,36,1,36,3,36,571,8,36,1,37,3,37,574,8,37,1,37,3,37,577,8,37,
  	1,37,1,37,3,37,581,8,37,1,37,3,37,584,8,37,1,37,1,37,3,37,588,8,37,1,
  	37,1,37,1,38,3,38,593,8,38,1,38,3,38,596,8,38,1,38,1,38,3,38,600,8,38,
  	1,38,3,38,603,8,38,1,38,1,38,3,38,607,8,38,1,38,1,38,1,39,1,39,1,39,1,
  	40,1,40,1,41,1,41,1,41,1,42,1,42,1,43,5,43,622,8,43,10,43,12,43,625,9,
  	43,1,43,1,43,1,44,1,44,5,44,631,8,44,10,44,12,44,634,9,44,1,45,5,45,637,
  	8,45,10,45,12,45,640,9,45,1,46,5,46,643,8,46,10,46,12,46,646,9,46,1,47,
  	1,47,1,47,1,47,1,47,3,47,653,8,47,1,48,1,48,1,48,1,48,1,48,3,48,660,8,
  	48,1,48,1,48,5,48,664,8,48,10,48,12,48,667,9,48,1,48,3,48,670,8,48,1,
  	49,1,49,1,49,1,49,1,49,3,49,677,8,49,1,49,1,49,5,49,681,8,49,10,49,12,
  	49,684,9,49,1,49,1,49,3,49,688,8,49,1,50,1,50,1,51,1,51,1,52,1,52,1,53,
  	1,53,1,53,5,53,699,8,53,10,53,12,53,702,9,53,3,53,704,8,53,1,54,1,54,
  	1,55,1,55,1,55,1,56,1,56,1,56,5,56,714,8,56,10,56,12,56,717,9,56,1,56,
  	3,56,720,8,56,3,56,722,8,56,1,57,1,57,1,58,1,58,1,58,1,58,1,58,1,58,1,
  	58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,3,58,744,8,
  	58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,
  	58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,1,
  	58,1,58,1,58,1,58,1,58,1,58,1,58,1,58,5,58,781,8,58,10,58,12,58,784,9,
  	58,1,59,1,59,1,59,5,59,789,8,59,10,59,12,59,792,9,59,1,59,3,59,795,8,
  	59,3,59,797,8,59,1,60,1,60,1,61,1,61,1,61,1,61,1,61,1,61,3,61,807,8,61,
  	1,61,0,1,116,62,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,
  	40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,
  	86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,
  	0,8,2,0,14,14,77,77,2,0,4,5,68,68,3,0,3,4,25,26,72,72,1,0,25,26,2,0,34,
  	34,37,37,1,0,27,29,1,0,19,22,1,0,23,24,898,0,130,1,0,0,0,2,135,1,0,0,
  	0,4,147,1,0,0,0,6,150,1,0,0,0,8,153,1,0,0,0,10,172,1,0,0,0,12,176,1,0,
  	0,0,14,178,1,0,0,0,16,184,1,0,0,0,18,190,1,0,0,0,20,202,1,0,0,0,22,207,
  	1,0,0,0,24,212,1,0,0,0,26,236,1,0,0,0,28,240,1,0,0,0,30,242,1,0,0,0,32,
  	250,1,0,0,0,34,343,1,0,0,0,36,407,1,0,0,0,38,410,1,0,0,0,40,428,1,0,0,
  	0,42,432,1,0,0,0,44,435,1,0,0,0,46,440,1,0,0,0,48,450,1,0,0,0,50,454,
  	1,0,0,0,52,460,1,0,0,0,54,468,1,0,0,0,56,480,1,0,0,0,58,493,1,0,0,0,60,
  	510,1,0,0,0,62,527,1,0,0,0,64,544,1,0,0,0,66,562,1,0,0,0,68,564,1,0,0,
  	0,70,566,1,0,0,0,72,570,1,0,0,0,74,573,1,0,0,0,76,592,1,0,0,0,78,610,
  	1,0,0,0,80,613,1,0,0,0,82,615,1,0,0,0,84,618,1,0,0,0,86,623,1,0,0,0,88,
  	628,1,0,0,0,90,638,1,0,0,0,92,644,1,0,0,0,94,647,1,0,0,0,96,669,1,0,0,
  	0,98,687,1,0,0,0,100,689,1,0,0,0,102,691,1,0,0,0,104,693,1,0,0,0,106,
  	703,1,0,0,0,108,705,1,0,0,0,110,707,1,0,0,0,112,721,1,0,0,0,114,723,1,
  	0,0,0,116,743,1,0,0,0,118,796,1,0,0,0,120,798,1,0,0,0,122,806,1,0,0,0,
  	124,125,3,6,3,0,125,126,5,0,0,1,126,131,1,0,0,0,127,128,3,24,12,0,128,
  	129,5,0,0,1,129,131,1,0,0,0,130,124,1,0,0,0,130,127,1,0,0,0,131,1,1,0,
  	0,0,132,134,5,77,0,0,133,132,1,0,0,0,134,137,1,0,0,0,135,133,1,0,0,0,
  	135,136,1,0,0,0,136,138,1,0,0,0,137,135,1,0,0,0,138,142,3,92,46,0,139,
  	141,5,77,0,0,140,139,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,142,143,
  	1,0,0,0,143,145,1,0,0,0,144,142,1,0,0,0,145,146,5,0,0,1,146,3,1,0,0,0,
  	147,148,3,60,30,0,148,149,5,0,0,1,149,5,1,0,0,0,150,151,3,8,4,0,151,7,
  	1,0,0,0,152,154,3,20,10,0,153,152,1,0,0,0,153,154,1,0,0,0,154,160,1,0,
  	0,0,155,156,3,10,5,0,156,157,3,20,10,0,157,159,1,0,0,0,158,155,1,0,0,
  	0,159,162,1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,164,1,0,0,0,162,
  	160,1,0,0,0,163,165,3,10,5,0,164,163,1,0,0,0,164,165,1,0,0,0,165,167,
  	1,0,0,0,166,168,3,20,10,0,167,166,1,0,0,0,167,168,1,0,0,0,168,9,1,0,0,
  	0,169,173,3,18,9,0,170,173,3,12,6,0,171,173,3,46,23,0,172,169,1,0,0,0,
  	172,170,1,0,0,0,172,171,1,0,0,0,173,11,1,0,0,0,174,177,3,14,7,0,175,177,
  	3,16,8,0,176,174,1,0,0,0,176,175,1,0,0,0,177,13,1,0,0,0,178,179,5,65,
  	0,0,179,182,5,3,0,0,180,181,5,18,0,0,181,183,3,116,58,0,182,180,1,0,0,
  	0,182,183,1,0,0,0,183,15,1,0,0,0,184,185,5,62,0,0,185,186,5,3,0,0,186,
  	187,5,18,0,0,187,188,3,116,58,0,188,17,1,0,0,0,189,191,5,55,0,0,190,189,
  	1,0,0,0,190,191,1,0,0,0,191,192,1,0,0,0,192,193,5,54,0,0,193,195,5,3,
  	0,0,194,196,3,22,11,0,195,194,1,0,0,0,195,196,1,0,0,0,196,197,1,0,0,0,
  	197,198,5,9,0,0,198,199,3,24,12,0,199,200,5,10,0,0,200,19,1,0,0,0,201,
  	203,7,0,0,0,202,201,1,0,0,0,203,204,1,0,0,0,204,202,1,0,0,0,204,205,1,
  	0,0,0,205,21,1,0,0,0,206,208,5,77,0,0,207,206,1,0,0,0,208,209,1,0,0,0,
  	209,207,1,0,0,0,209,210,1,0,0,0,210,23,1,0,0,0,211,213,3,20,10,0,212,
  	211,1,0,0,0,212,213,1,0,0,0,213,219,1,0,0,0,214,215,3,26,13,0,215,216,
  	3,20,10,0,216,218,1,0,0,0,217,214,1,0,0,0,218,221,1,0,0,0,219,217,1,0,
  	0,0,219,220,1,0,0,0,220,223,1,0,0,0,221,219,1,0,0,0,222,224,3,26,13,0,
  	223,222,1,0,0,0,223,224,1,0,0,0,224,226,1,0,0,0,225,227,3,20,10,0,226,
  	225,1,0,0,0,226,227,1,0,0,0,227,25,1,0,0,0,228,237,3,42,21,0,229,237,
  	3,38,19,0,230,237,3,46,23,0,231,237,3,50,25,0,232,237,3,52,26,0,233,237,
  	3,54,27,0,234,237,3,56,28,0,235,237,3,72,36,0,236,228,1,0,0,0,236,229,
  	1,0,0,0,236,230,1,0,0,0,236,231,1,0,0,0,236,232,1,0,0,0,236,233,1,0,0,
  	0,236,234,1,0,0,0,236,235,1,0,0,0,237,27,1,0,0,0,238,241,3,30,15,0,239,
  	241,3,32,16,0,240,238,1,0,0,0,240,239,1,0,0,0,241,29,1,0,0,0,242,244,
  	5,9,0,0,243,245,3,38,19,0,244,243,1,0,0,0,244,245,1,0,0,0,245,246,1,0,
  	0,0,246,247,5,10,0,0,247,31,1,0,0,0,248,251,3,34,17,0,249,251,3,36,18,
  	0,250,248,1,0,0,0,250,249,1,0,0,0,251,33,1,0,0,0,252,344,3,116,58,0,253,
  	344,3,40,20,0,254,344,3,12,6,0,255,257,5,60,0,0,256,258,3,116,58,0,257,
  	256,1,0,0,0,257,258,1,0,0,0,258,344,1,0,0,0,259,261,5,44,0,0,260,262,
  	3,22,11,0,261,260,1,0,0,0,261,262,1,0,0,0,262,263,1,0,0,0,263,265,5,7,
  	0,0,264,266,3,22,11,0,265,264,1,0,0,0,265,266,1,0,0,0,266,267,1,0,0,0,
  	267,269,3,116,58,0,268,270,3,22,11,0,269,268,1,0,0,0,269,270,1,0,0,0,
  	270,271,1,0,0,0,271,273,5,8,0,0,272,274,3,22,11,0,273,272,1,0,0,0,273,
  	274,1,0,0,0,274,275,1,0,0,0,275,276,3,34,17,0,276,344,1,0,0,0,277,279,
  	5,44,0,0,278,280,3,22,11,0,279,278,1,0,0,0,279,280,1,0,0,0,280,281,1,
  	0,0,0,281,283,5,7,0,0,282,284,3,22,11,0,283,282,1,0,0,0,283,284,1,0,0,
  	0,284,285,1,0,0,0,285,287,3,116,58,0,286,288,3,22,11,0,287,286,1,0,0,
  	0,287,288,1,0,0,0,288,289,1,0,0,0,289,291,5,8,0,0,290,292,3,22,11,0,291,
  	290,1,0,0,0,291,292,1,0,0,0,292,293,1,0,0,0,293,295,3,28,14,0,294,296,
  	3,22,11,0,295,294,1,0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,299,5,39,
  	0,0,298,300,3,22,11,0,299,298,1,0,0,0,299,300,1,0,0,0,300,301,1,0,0,0,
  	301,302,3,34,17,0,302,344,1,0,0,0,303,305,5,66,0,0,304,306,3,22,11,0,
  	305,304,1,0,0,0,305,306,1,0,0,0,306,307,1,0,0,0,307,309,5,7,0,0,308,310,
  	3,22,11,0,309,308,1,0,0,0,309,310,1,0,0,0,310,311,1,0,0,0,311,313,3,116,
  	58,0,312,314,3,22,11,0,313,312,1,0,0,0,313,314,1,0,0,0,314,315,1,0,0,
  	0,315,317,5,8,0,0,316,318,3,22,11,0,317,316,1,0,0,0,317,318,1,0,0,0,318,
  	319,1,0,0,0,319,320,3,34,17,0,320,344,1,0,0,0,321,323,5,52,0,0,322,324,
  	3,22,11,0,323,322,1,0,0,0,323,324,1,0,0,0,324,325,1,0,0,0,325,327,3,28,
  	14,0,326,328,3,22,11,0,327,326,1,0,0,0,327,328,1,0,0,0,328,329,1,0,0,
  	0,329,331,5,66,0,0,330,332,3,22,11,0,331,330,1,0,0,0,331,332,1,0,0,0,
  	332,333,1,0,0,0,333,335,5,7,0,0,334,336,3,22,11,0,335,334,1,0,0,0,335,
  	336,1,0,0,0,336,337,1,0,0,0,337,339,3,116,58,0,338,340,3,22,11,0,339,
  	338,1,0,0,0,339,340,1,0,0,0,340,341,1,0,0,0,341,342,5,8,0,0,342,344,1,
  	0,0,0,343,252,1,0,0,0,343,253,1,0,0,0,343,254,1,0,0,0,343,255,1,0,0,0,
  	343,259,1,0,0,0,343,277,1,0,0,0,343,303,1,0,0,0,343,321,1,0,0,0,344,35,
  	1,0,0,0,345,347,5,44,0,0,346,348,3,22,11,0,347,346,1,0,0,0,347,348,1,
  	0,0,0,348,349,1,0,0,0,349,351,5,7,0,0,350,352,3,22,11,0,351,350,1,0,0,
  	0,351,352,1,0,0,0,352,353,1,0,0,0,353,355,3,116,58,0,354,356,3,22,11,
  	0,355,354,1,0,0,0,355,356,1,0,0,0,356,357,1,0,0,0,357,359,5,8,0,0,358,
  	360,3,22,11,0,359,358,1,0,0,0,359,360,1,0,0,0,360,361,1,0,0,0,361,362,
  	3,30,15,0,362,408,1,0,0,0,363,365,5,44,0,0,364,366,3,22,11,0,365,364,
  	1,0,0,0,365,366,1,0,0,0,366,367,1,0,0,0,367,369,5,7,0,0,368,370,3,22,
  	11,0,369,368,1,0,0,0,369,370,1,0,0,0,370,371,1,0,0,0,371,373,3,116,58,
  	0,372,374,3,22,11,0,373,372,1,0,0,0,373,374,1,0,0,0,374,375,1,0,0,0,375,
  	377,5,8,0,0,376,378,3,22,11,0,377,376,1,0,0,0,377,378,1,0,0,0,378,379,
  	1,0,0,0,379,381,3,28,14,0,380,382,3,22,11,0,381,380,1,0,0,0,381,382,1,
  	0,0,0,382,383,1,0,0,0,383,385,5,39,0,0,384,386,3,22,11,0,385,384,1,0,
  	0,0,385,386,1,0,0,0,386,387,1,0,0,0,387,388,3,30,15,0,388,408,1,0,0,0,
  	389,391,5,66,0,0,390,392,3,22,11,0,391,390,1,0,0,0,391,392,1,0,0,0,392,
  	393,1,0,0,0,393,395,5,7,0,0,394,396,3,22,11,0,395,394,1,0,0,0,395,396,
  	1,0,0,0,396,397,1,0,0,0,397,399,3,116,58,0,398,400,3,22,11,0,399,398,
  	1,0,0,0,399,400,1,0,0,0,400,401,1,0,0,0,401,403,5,8,0,0,402,404,3,22,
  	11,0,403,402,1,0,0,0,403,404,1,0,0,0,404,405,1,0,0,0,405,406,3,30,15,
  	0,406,408,1,0,0,0,407,345,1,0,0,0,407,363,1,0,0,0,407,389,1,0,0,0,408,
  	37,1,0,0,0,409,411,3,20,10,0,410,409,1,0,0,0,410,411,1,0,0,0,411,421,
  	1,0,0,0,412,413,3,34,17,0,413,414,3,20,10,0,414,420,1,0,0,0,415,417,3,
  	36,18,0,416,418,3,20,10,0,417,416,1,0,0,0,417,418,1,0,0,0,418,420,1,0,
  	0,0,419,412,1,0,0,0,419,415,1,0,0,0,420,423,1,0,0,0,421,419,1,0,0,0,421,
  	422,1,0,0,0,422,424,1,0,0,0,423,421,1,0,0,0,424,426,3,32,16,0,425,427,
  	3,20,10,0,426,425,1,0,0,0,426,427,1,0,0,0,427,39,1,0,0,0,428,429,5,3,
  	0,0,429,430,5,18,0,0,430,431,3,116,58,0,431,41,1,0,0,0,432,433,5,50,0,
  	0,433,434,3,92,46,0,434,43,1,0,0,0,435,436,5,62,0,0,436,437,5,3,0,0,437,
  	438,5,18,0,0,438,439,3,116,58,0,439,45,1,0,0,0,440,441,5,53,0,0,441,442,
  	5,3,0,0,442,443,5,7,0,0,443,444,3,106,53,0,444,448,5,8,0,0,445,446,5,
  	18,0,0,446,449,3,116,58,0,447,449,3,30,15,0,448,445,1,0,0,0,448,447,1,
  	0,0,0,449,47,1,0,0,0,450,451,5,71,0,0,451,452,5,18,0,0,452,453,3,116,
  	58,0,453,49,1,0,0,0,454,455,5,63,0,0,455,456,5,3,0,0,456,457,5,9,0,0,
  	457,458,3,58,29,0,458,459,5,10,0,0,459,51,1,0,0,0,460,462,5,61,0,0,461,
  	463,3,22,11,0,462,461,1,0,0,0,462,463,1,0,0,0,463,464,1,0,0,0,464,465,
  	5,9,0,0,465,466,3,60,30,0,466,467,5,10,0,0,467,53,1,0,0,0,468,470,5,59,
  	0,0,469,471,3,22,11,0,470,469,1,0,0,0,470,471,1,0,0,0,471,472,1,0,0,0,
  	472,474,5,61,0,0,473,475,3,22,11,0,474,473,1,0,0,0,474,475,1,0,0,0,475,
  	476,1,0,0,0,476,477,5,9,0,0,477,478,3,60,30,0,478,479,5,10,0,0,479,55,
  	1,0,0,0,480,482,5,51,0,0,481,483,3,22,11,0,482,481,1,0,0,0,482,483,1,
  	0,0,0,483,484,1,0,0,0,484,486,5,61,0,0,485,487,3,22,11,0,486,485,1,0,
  	0,0,486,487,1,0,0,0,487,488,1,0,0,0,488,489,5,9,0,0,489,490,3,60,30,0,
  	490,491,5,10,0,0,491,57,1,0,0,0,492,494,3,20,10,0,493,492,1,0,0,0,493,
  	494,1,0,0,0,494,500,1,0,0,0,495,496,3,66,33,0,496,497,3,20,10,0,497,499,
  	1,0,0,0,498,495,1,0,0,0,499,502,1,0,0,0,500,498,1,0,0,0,500,501,1,0,0,
  	0,501,504,1,0,0,0,502,500,1,0,0,0,503,505,3,66,33,0,504,503,1,0,0,0,504,
  	505,1,0,0,0,505,507,1,0,0,0,506,508,3,20,10,0,507,506,1,0,0,0,507,508,
  	1,0,0,0,508,59,1,0,0,0,509,511,3,20,10,0,510,509,1,0,0,0,510,511,1,0,
  	0,0,511,517,1,0,0,0,512,513,3,72,36,0,513,514,3,20,10,0,514,516,1,0,0,
  	0,515,512,1,0,0,0,516,519,1,0,0,0,517,515,1,0,0,0,517,518,1,0,0,0,518,
  	521,1,0,0,0,519,517,1,0,0,0,520,522,3,72,36,0,521,520,1,0,0,0,521,522,
  	1,0,0,0,522,524,1,0,0,0,523,525,3,20,10,0,524,523,1,0,0,0,524,525,1,0,
  	0,0,525,61,1,0,0,0,526,528,3,20,10,0,527,526,1,0,0,0,527,528,1,0,0,0,
  	528,534,1,0,0,0,529,530,3,74,37,0,530,531,3,20,10,0,531,533,1,0,0,0,532,
  	529,1,0,0,0,533,536,1,0,0,0,534,532,1,0,0,0,534,535,1,0,0,0,535,538,1,
  	0,0,0,536,534,1,0,0,0,537,539,3,74,37,0,538,537,1,0,0,0,538,539,1,0,0,
  	0,539,541,1,0,0,0,540,542,3,20,10,0,541,540,1,0,0,0,541,542,1,0,0,0,542,
  	63,1,0,0,0,543,545,3,20,10,0,544,543,1,0,0,0,544,545,1,0,0,0,545,551,
  	1,0,0,0,546,547,3,76,38,0,547,548,3,20,10,0,548,550,1,0,0,0,549,546,1,
  	0,0,0,550,553,1,0,0,0,551,549,1,0,0,0,551,552,1,0,0,0,552,555,1,0,0,0,
  	553,551,1,0,0,0,554,556,3,76,38,0,555,554,1,0,0,0,555,556,1,0,0,0,556,
  	558,1,0,0,0,557,559,3,20,10,0,558,557,1,0,0,0,558,559,1,0,0,0,559,65,
  	1,0,0,0,560,563,3,68,34,0,561,563,3,70,35,0,562,560,1,0,0,0,562,561,1,
  	0,0,0,563,67,1,0,0,0,564,565,3,74,37,0,565,69,1,0,0,0,566,567,3,76,38,
  	0,567,71,1,0,0,0,568,571,3,74,37,0,569,571,3,76,38,0,570,568,1,0,0,0,
  	570,569,1,0,0,0,571,73,1,0,0,0,572,574,3,82,41,0,573,572,1,0,0,0,573,
  	574,1,0,0,0,574,576,1,0,0,0,575,577,3,86,43,0,576,575,1,0,0,0,576,577,
  	1,0,0,0,577,578,1,0,0,0,578,580,3,84,42,0,579,581,3,88,44,0,580,579,1,
  	0,0,0,580,581,1,0,0,0,581,583,1,0,0,0,582,584,3,110,55,0,583,582,1,0,
  	0,0,583,584,1,0,0,0,584,585,1,0,0,0,585,587,5,17,0,0,586,588,3,22,11,
  	0,587,586,1,0,0,0,587,588,1,0,0,0,588,589,1,0,0,0,589,590,3,90,45,0,590,
  	75,1,0,0,0,591,593,3,82,41,0,592,591,1,0,0,0,592,593,1,0,0,0,593,595,
  	1,0,0,0,594,596,3,86,43,0,595,594,1,0,0,0,595,596,1,0,0,0,596,597,1,0,
  	0,0,597,599,3,84,42,0,598,600,3,88,44,0,599,598,1,0,0,0,599,600,1,0,0,
  	0,600,602,1,0,0,0,601,603,3,110,55,0,602,601,1,0,0,0,602,603,1,0,0,0,
  	603,604,1,0,0,0,604,606,5,69,0,0,605,607,3,22,11,0,606,605,1,0,0,0,606,
  	607,1,0,0,0,607,608,1,0,0,0,608,609,3,90,45,0,609,77,1,0,0,0,610,611,
  	3,80,40,0,611,612,5,13,0,0,612,79,1,0,0,0,613,614,5,3,0,0,614,81,1,0,
  	0,0,615,616,7,1,0,0,616,617,5,32,0,0,617,83,1,0,0,0,618,619,3,94,47,0,
  	619,85,1,0,0,0,620,622,3,96,48,0,621,620,1,0,0,0,622,625,1,0,0,0,623,
  	621,1,0,0,0,623,624,1,0,0,0,624,626,1,0,0,0,625,623,1,0,0,0,626,627,5,
  	19,0,0,627,87,1,0,0,0,628,632,5,20,0,0,629,631,3,96,48,0,630,629,1,0,
  	0,0,631,634,1,0,0,0,632,630,1,0,0,0,632,633,1,0,0,0,633,89,1,0,0,0,634,
  	632,1,0,0,0,635,637,3,98,49,0,636,635,1,0,0,0,637,640,1,0,0,0,638,636,
  	1,0,0,0,638,639,1,0,0,0,639,91,1,0,0,0,640,638,1,0,0,0,641,643,3,98,49,
  	0,642,641,1,0,0,0,643,646,1,0,0,0,644,642,1,0,0,0,644,645,1,0,0,0,645,
  	93,1,0,0,0,646,644,1,0,0,0,647,652,3,100,50,0,648,649,5,7,0,0,649,650,
  	3,106,53,0,650,651,5,8,0,0,651,653,1,0,0,0,652,648,1,0,0,0,652,653,1,
  	0,0,0,653,95,1,0,0,0,654,659,3,100,50,0,655,656,5,7,0,0,656,657,3,106,
  	53,0,657,658,5,8,0,0,658,660,1,0,0,0,659,655,1,0,0,0,659,660,1,0,0,0,
  	660,670,1,0,0,0,661,665,5,11,0,0,662,664,3,96,48,0,663,662,1,0,0,0,664,
  	667,1,0,0,0,665,663,1,0,0,0,665,666,1,0,0,0,666,668,1,0,0,0,667,665,1,
  	0,0,0,668,670,5,12,0,0,669,654,1,0,0,0,669,661,1,0,0,0,670,97,1,0,0,0,
  	671,676,3,102,51,0,672,673,5,7,0,0,673,674,3,112,56,0,674,675,5,8,0,0,
  	675,677,1,0,0,0,676,672,1,0,0,0,676,677,1,0,0,0,677,688,1,0,0,0,678,682,
  	5,11,0,0,679,681,3,98,49,0,680,679,1,0,0,0,681,684,1,0,0,0,682,680,1,
  	0,0,0,682,683,1,0,0,0,683,685,1,0,0,0,684,682,1,0,0,0,685,688,5,12,0,
  	0,686,688,3,30,15,0,687,671,1,0,0,0,687,678,1,0,0,0,687,686,1,0,0,0,688,
  	99,1,0,0,0,689,690,3,104,52,0,690,101,1,0,0,0,691,692,3,104,52,0,692,
  	103,1,0,0,0,693,694,7,2,0,0,694,105,1,0,0,0,695,700,3,108,54,0,696,697,
  	5,15,0,0,697,699,3,108,54,0,698,696,1,0,0,0,699,702,1,0,0,0,700,698,1,
  	0,0,0,700,701,1,0,0,0,701,704,1,0,0,0,702,700,1,0,0,0,703,695,1,0,0,0,
  	703,704,1,0,0,0,704,107,1,0,0,0,705,706,5,3,0,0,706,109,1,0,0,0,707,708,
  	5,13,0,0,708,709,3,116,58,0,709,111,1,0,0,0,710,715,3,114,57,0,711,712,
  	5,15,0,0,712,714,3,114,57,0,713,711,1,0,0,0,714,717,1,0,0,0,715,713,1,
  	0,0,0,715,716,1,0,0,0,716,719,1,0,0,0,717,715,1,0,0,0,718,720,5,15,0,
  	0,719,718,1,0,0,0,719,720,1,0,0,0,720,722,1,0,0,0,721,710,1,0,0,0,721,
  	722,1,0,0,0,722,113,1,0,0,0,723,724,3,116,58,0,724,115,1,0,0,0,725,726,
  	6,58,-1,0,726,727,5,7,0,0,727,728,3,116,58,0,728,729,5,8,0,0,729,744,
  	1,0,0,0,730,744,3,122,61,0,731,744,5,3,0,0,732,733,7,3,0,0,733,744,3,
  	116,58,13,734,735,7,4,0,0,735,744,3,116,58,12,736,737,5,44,0,0,737,738,
  	3,116,58,0,738,739,5,64,0,0,739,740,3,116,58,0,740,741,5,39,0,0,741,742,
  	3,116,58,1,742,744,1,0,0,0,743,725,1,0,0,0,743,730,1,0,0,0,743,731,1,
  	0,0,0,743,732,1,0,0,0,743,734,1,0,0,0,743,736,1,0,0,0,744,782,1,0,0,0,
  	745,746,10,11,0,0,746,747,5,30,0,0,747,781,3,116,58,11,748,749,10,10,
  	0,0,749,750,7,5,0,0,750,781,3,116,58,11,751,752,10,9,0,0,752,753,7,3,
  	0,0,753,781,3,116,58,10,754,755,10,8,0,0,755,756,7,6,0,0,756,781,3,116,
  	58,9,757,758,10,7,0,0,758,759,7,7,0,0,759,781,3,116,58,8,760,761,10,6,
  	0,0,761,762,5,31,0,0,762,781,3,116,58,7,763,764,10,5,0,0,764,765,5,33,
  	0,0,765,781,3,116,58,6,766,767,10,4,0,0,767,768,5,32,0,0,768,781,3,116,
  	58,5,769,770,10,3,0,0,770,771,5,35,0,0,771,781,3,116,58,4,772,773,10,
  	2,0,0,773,774,5,36,0,0,774,781,3,116,58,3,775,776,10,14,0,0,776,777,5,
  	7,0,0,777,778,3,118,59,0,778,779,5,8,0,0,779,781,1,0,0,0,780,745,1,0,
  	0,0,780,748,1,0,0,0,780,751,1,0,0,0,780,754,1,0,0,0,780,757,1,0,0,0,780,
  	760,1,0,0,0,780,763,1,0,0,0,780,766,1,0,0,0,780,769,1,0,0,0,780,772,1,
  	0,0,0,780,775,1,0,0,0,781,784,1,0,0,0,782,780,1,0,0,0,782,783,1,0,0,0,
  	783,117,1,0,0,0,784,782,1,0,0,0,785,790,3,120,60,0,786,787,5,15,0,0,787,
  	789,3,120,60,0,788,786,1,0,0,0,789,792,1,0,0,0,790,788,1,0,0,0,790,791,
  	1,0,0,0,791,794,1,0,0,0,792,790,1,0,0,0,793,795,5,15,0,0,794,793,1,0,
  	0,0,794,795,1,0,0,0,795,797,1,0,0,0,796,785,1,0,0,0,796,797,1,0,0,0,797,
  	119,1,0,0,0,798,799,3,116,58,0,799,121,1,0,0,0,800,807,5,4,0,0,801,807,
  	5,5,0,0,802,807,5,6,0,0,803,807,5,48,0,0,804,807,5,41,0,0,805,807,5,57,
  	0,0,806,800,1,0,0,0,806,801,1,0,0,0,806,802,1,0,0,0,806,803,1,0,0,0,806,
  	804,1,0,0,0,806,805,1,0,0,0,807,123,1,0,0,0,120,130,135,142,153,160,164,
  	167,172,176,182,190,195,204,209,212,219,223,226,236,240,244,250,257,261,
  	265,269,273,279,283,287,291,295,299,305,309,313,317,323,327,331,335,339,
  	343,347,351,355,359,365,369,373,377,381,385,391,395,399,403,407,410,417,
  	419,421,426,448,462,470,474,482,486,493,500,504,507,510,517,521,524,527,
  	534,538,541,544,551,555,558,562,570,573,576,580,583,587,592,595,599,602,
  	606,623,632,638,644,652,659,665,669,676,682,687,700,703,715,719,721,743,
  	780,782,790,794,796,806
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lsysdparserParserStaticData = staticData.release();
}

}

LSysDParser::LSysDParser(TokenStream *input) : LSysDParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LSysDParser::LSysDParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LSysDParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *lsysdparserParserStaticData->atn, lsysdparserParserStaticData->decisionToDFA, lsysdparserParserStaticData->sharedContextCache, options);
}

LSysDParser::~LSysDParser() {
  delete _interpreter;
}

const atn::ATN& LSysDParser::getATN() const {
  return *lsysdparserParserStaticData->atn;
}

std::string LSysDParser::getGrammarFileName() const {
  return "LSysDParser.g4";
}

const std::vector<std::string>& LSysDParser::getRuleNames() const {
  return lsysdparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& LSysDParser::getVocabulary() const {
  return lsysdparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LSysDParser::getSerializedATN() const {
  return lsysdparserParserStaticData->serializedATN;
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


std::any LSysDParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::MainContext* LSysDParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, LSysDParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      module();
      setState(125);
      match(LSysDParser::EOF);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(127);
      inLsysDefs();
      setState(128);
      match(LSysDParser::EOF);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainWordContext ------------------------------------------------------------------

LSysDParser::MainWordContext::MainWordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::WordContext* LSysDParser::MainWordContext::word() {
  return getRuleContext<LSysDParser::WordContext>(0);
}

tree::TerminalNode* LSysDParser::MainWordContext::EOF() {
  return getToken(LSysDParser::EOF, 0);
}

std::vector<tree::TerminalNode *> LSysDParser::MainWordContext::NEW_LINE() {
  return getTokens(LSysDParser::NEW_LINE);
}

tree::TerminalNode* LSysDParser::MainWordContext::NEW_LINE(size_t i) {
  return getToken(LSysDParser::NEW_LINE, i);
}


size_t LSysDParser::MainWordContext::getRuleIndex() const {
  return LSysDParser::RuleMainWord;
}


std::any LSysDParser::MainWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitMainWord(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::MainWordContext* LSysDParser::mainWord() {
  MainWordContext *_localctx = _tracker.createInstance<MainWordContext>(_ctx, getState());
  enterRule(_localctx, 2, LSysDParser::RuleMainWord);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(135);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(132);
        match(LSysDParser::NEW_LINE); 
      }
      setState(137);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(138);
    word();
    setState(142);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LSysDParser::NEW_LINE) {
      setState(139);
      match(LSysDParser::NEW_LINE);
      setState(144);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(145);
    match(LSysDParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainRuleDefsContext ------------------------------------------------------------------

LSysDParser::MainRuleDefsContext::MainRuleDefsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LSysDParser::RuleDefsContext* LSysDParser::MainRuleDefsContext::ruleDefs() {
  return getRuleContext<LSysDParser::RuleDefsContext>(0);
}

tree::TerminalNode* LSysDParser::MainRuleDefsContext::EOF() {
  return getToken(LSysDParser::EOF, 0);
}


size_t LSysDParser::MainRuleDefsContext::getRuleIndex() const {
  return LSysDParser::RuleMainRuleDefs;
}


std::any LSysDParser::MainRuleDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitMainRuleDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::MainRuleDefsContext* LSysDParser::mainRuleDefs() {
  MainRuleDefsContext *_localctx = _tracker.createInstance<MainRuleDefsContext>(_ctx, getState());
  enterRule(_localctx, 4, LSysDParser::RuleMainRuleDefs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    ruleDefs();
    setState(148);
    match(LSysDParser::EOF);
   
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


std::any LSysDParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ModuleContext* LSysDParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 6, LSysDParser::RuleModule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
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


std::any LSysDParser::GlobalDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitGlobalDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::GlobalDefsContext* LSysDParser::globalDefs() {
  GlobalDefsContext *_localctx = _tracker.createInstance<GlobalDefsContext>(_ctx, getState());
  enterRule(_localctx, 8, LSysDParser::RuleGlobalDefs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(153);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(152);
      sep();
      break;
    }

    default:
      break;
    }
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(155);
        globalDef();
        setState(156);
        sep(); 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la - 53) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 53)) & 4615) != 0) {
      setState(163);
      globalDef();
    }
    setState(167);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(166);
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


std::any LSysDParser::GlobalDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitGlobalDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::GlobalDefContext* LSysDParser::globalDef() {
  GlobalDefContext *_localctx = _tracker.createInstance<GlobalDefContext>(_ctx, getState());
  enterRule(_localctx, 10, LSysDParser::RuleGlobalDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::KWLSYS:
      case LSysDParser::KWMAIN: {
        enterOuterAlt(_localctx, 1);
        setState(169);
        lsystem();
        break;
      }

      case LSysDParser::KWSET:
      case LSysDParser::KWVAR: {
        enterOuterAlt(_localctx, 2);
        setState(170);
        declaration();
        break;
      }

      case LSysDParser::KWFUNCTION: {
        enterOuterAlt(_localctx, 3);
        setState(171);
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


std::any LSysDParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::DeclarationContext* LSysDParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, LSysDParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(176);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::KWVAR: {
        enterOuterAlt(_localctx, 1);
        setState(174);
        varDeclaration();
        break;
      }

      case LSysDParser::KWSET: {
        enterOuterAlt(_localctx, 2);
        setState(175);
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


std::any LSysDParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::VarDeclarationContext* LSysDParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, LSysDParser::RuleVarDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(LSysDParser::KWVAR);
    setState(179);
    match(LSysDParser::ID);
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::ASSIGN) {
      setState(180);
      match(LSysDParser::ASSIGN);
      setState(181);
      expression(0);
    }
   
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


std::any LSysDParser::ConstDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitConstDeclaration(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ConstDeclarationContext* LSysDParser::constDeclaration() {
  ConstDeclarationContext *_localctx = _tracker.createInstance<ConstDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 16, LSysDParser::RuleConstDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(LSysDParser::KWSET);
    setState(185);
    match(LSysDParser::ID);
    setState(186);
    match(LSysDParser::ASSIGN);
    setState(187);
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


std::any LSysDParser::LsystemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLsystem(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LsystemContext* LSysDParser::lsystem() {
  LsystemContext *_localctx = _tracker.createInstance<LsystemContext>(_ctx, getState());
  enterRule(_localctx, 18, LSysDParser::RuleLsystem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::KWMAIN) {
      setState(189);
      match(LSysDParser::KWMAIN);
    }
    setState(192);
    match(LSysDParser::KWLSYS);
    setState(193);
    match(LSysDParser::ID);
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(194);
      nl();
    }
    setState(197);
    match(LSysDParser::LBRACE);
    setState(198);
    inLsysDefs();
    setState(199);
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


std::any LSysDParser::SepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitSep(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::SepContext* LSysDParser::sep() {
  SepContext *_localctx = _tracker.createInstance<SepContext>(_ctx, getState());
  enterRule(_localctx, 20, LSysDParser::RuleSep);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(202); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(201);
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
      setState(204); 
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


std::any LSysDParser::NlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitNl(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::NlContext* LSysDParser::nl() {
  NlContext *_localctx = _tracker.createInstance<NlContext>(_ctx, getState());
  enterRule(_localctx, 22, LSysDParser::RuleNl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(207); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(206);
              match(LSysDParser::NEW_LINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(209); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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


std::any LSysDParser::InLsysDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitInLsysDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::InLsysDefsContext* LSysDParser::inLsysDefs() {
  InLsysDefsContext *_localctx = _tracker.createInstance<InLsysDefsContext>(_ctx, getState());
  enterRule(_localctx, 24, LSysDParser::RuleInLsysDefs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(212);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(211);
      sep();
      break;
    }

    default:
      break;
    }
    setState(219);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(214);
        inLsysDef();
        setState(215);
        sep(); 
      }
      setState(221);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(223);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(222);
      inLsysDef();
      break;
    }

    default:
      break;
    }
    setState(226);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(225);
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


std::any LSysDParser::InLsysDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitInLsysDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::InLsysDefContext* LSysDParser::inLsysDef() {
  InLsysDefContext *_localctx = _tracker.createInstance<InLsysDefContext>(_ctx, getState());
  enterRule(_localctx, 26, LSysDParser::RuleInLsysDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      axiomDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(229);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(230);
      funcDef();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(231);
      tableBlock();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(232);
      rulesBlock();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(233);
      productionRulesBlock();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(234);
      codingRulesBlock();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(235);
      ruleDef();
      break;
    }

    default:
      break;
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


std::any LSysDParser::BlockOrOneStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitBlockOrOneStatement(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::BlockOrOneStatementContext* LSysDParser::blockOrOneStatement() {
  BlockOrOneStatementContext *_localctx = _tracker.createInstance<BlockOrOneStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, LSysDParser::RuleBlockOrOneStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(240);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(238);
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
        setState(239);
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


std::any LSysDParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::BlockContext* LSysDParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 30, LSysDParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    match(LSysDParser::LBRACE);
    setState(244);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5913527731642974456) != 0 || (((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 4099) != 0) {
      setState(243);
      statement();
    }
    setState(246);
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


std::any LSysDParser::OneStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitOneStatement(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::OneStatementContext* LSysDParser::oneStatement() {
  OneStatementContext *_localctx = _tracker.createInstance<OneStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, LSysDParser::RuleOneStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(250);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(248);
      oneStmtNeedsSep();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(249);
      oneStmtEndsInBlock();
      break;
    }

    default:
      break;
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


std::any LSysDParser::OneStmtNeedsSepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitOneStmtNeedsSep(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::OneStmtNeedsSepContext* LSysDParser::oneStmtNeedsSep() {
  OneStmtNeedsSepContext *_localctx = _tracker.createInstance<OneStmtNeedsSepContext>(_ctx, getState());
  enterRule(_localctx, 34, LSysDParser::RuleOneStmtNeedsSep);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(343);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(252);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(253);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(254);
      declaration();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(255);
      match(LSysDParser::KWRETURN);
      setState(257);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 144416608981352696) != 0) {
        setState(256);
        expression(0);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(259);
      match(LSysDParser::KWIF);
      setState(261);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(260);
        nl();
      }
      setState(263);
      match(LSysDParser::LPAREN);
      setState(265);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(264);
        nl();
      }
      setState(267);
      expression(0);
      setState(269);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(268);
        nl();
      }
      setState(271);
      match(LSysDParser::RPAREN);
      setState(273);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(272);
        nl();
      }
      setState(275);
      oneStmtNeedsSep();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(277);
      match(LSysDParser::KWIF);
      setState(279);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(278);
        nl();
      }
      setState(281);
      match(LSysDParser::LPAREN);
      setState(283);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(282);
        nl();
      }
      setState(285);
      expression(0);
      setState(287);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(286);
        nl();
      }
      setState(289);
      match(LSysDParser::RPAREN);
      setState(291);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(290);
        nl();
      }
      setState(293);
      blockOrOneStatement();
      setState(295);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(294);
        nl();
      }
      setState(297);
      match(LSysDParser::KWELSE);
      setState(299);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(298);
        nl();
      }
      setState(301);
      oneStmtNeedsSep();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(303);
      match(LSysDParser::KWWHILE);
      setState(305);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(304);
        nl();
      }
      setState(307);
      match(LSysDParser::LPAREN);
      setState(309);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(308);
        nl();
      }
      setState(311);
      expression(0);
      setState(313);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(312);
        nl();
      }
      setState(315);
      match(LSysDParser::RPAREN);
      setState(317);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(316);
        nl();
      }
      setState(319);
      oneStmtNeedsSep();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(321);
      match(LSysDParser::KWDO);
      setState(323);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(322);
        nl();
      }
      setState(325);
      blockOrOneStatement();
      setState(327);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(326);
        nl();
      }
      setState(329);
      match(LSysDParser::KWWHILE);
      setState(331);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(330);
        nl();
      }
      setState(333);
      match(LSysDParser::LPAREN);
      setState(335);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(334);
        nl();
      }
      setState(337);
      expression(0);
      setState(339);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(338);
        nl();
      }
      setState(341);
      match(LSysDParser::RPAREN);
      break;
    }

    default:
      break;
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


std::any LSysDParser::OneStmtEndsInBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitOneStmtEndsInBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::OneStmtEndsInBlockContext* LSysDParser::oneStmtEndsInBlock() {
  OneStmtEndsInBlockContext *_localctx = _tracker.createInstance<OneStmtEndsInBlockContext>(_ctx, getState());
  enterRule(_localctx, 36, LSysDParser::RuleOneStmtEndsInBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(407);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(345);
      match(LSysDParser::KWIF);
      setState(347);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(346);
        nl();
      }
      setState(349);
      match(LSysDParser::LPAREN);
      setState(351);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(350);
        nl();
      }
      setState(353);
      expression(0);
      setState(355);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(354);
        nl();
      }
      setState(357);
      match(LSysDParser::RPAREN);
      setState(359);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(358);
        nl();
      }
      setState(361);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(363);
      match(LSysDParser::KWIF);
      setState(365);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(364);
        nl();
      }
      setState(367);
      match(LSysDParser::LPAREN);
      setState(369);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(368);
        nl();
      }
      setState(371);
      expression(0);
      setState(373);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(372);
        nl();
      }
      setState(375);
      match(LSysDParser::RPAREN);
      setState(377);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(376);
        nl();
      }
      setState(379);
      blockOrOneStatement();
      setState(381);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(380);
        nl();
      }
      setState(383);
      match(LSysDParser::KWELSE);
      setState(385);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(384);
        nl();
      }
      setState(387);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(389);
      match(LSysDParser::KWWHILE);
      setState(391);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(390);
        nl();
      }
      setState(393);
      match(LSysDParser::LPAREN);
      setState(395);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(394);
        nl();
      }
      setState(397);
      expression(0);
      setState(399);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(398);
        nl();
      }
      setState(401);
      match(LSysDParser::RPAREN);
      setState(403);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::NEW_LINE) {
        setState(402);
        nl();
      }
      setState(405);
      block();
      break;
    }

    default:
      break;
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


std::any LSysDParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::StatementContext* LSysDParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 38, LSysDParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(410);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(409);
      sep();
    }
    setState(421);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(419);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
        case 1: {
          setState(412);
          oneStmtNeedsSep();
          setState(413);
          sep();
          break;
        }

        case 2: {
          setState(415);
          oneStmtEndsInBlock();
          setState(417);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == LSysDParser::SEMI

          || _la == LSysDParser::NEW_LINE) {
            setState(416);
            sep();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(423);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
    setState(424);
    oneStatement();
    setState(426);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      setState(425);
      sep();
      break;
    }

    default:
      break;
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


std::any LSysDParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::AssignmentContext* LSysDParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 40, LSysDParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(LSysDParser::ID);
    setState(429);
    match(LSysDParser::ASSIGN);
    setState(430);
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


std::any LSysDParser::AxiomDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAxiomDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::AxiomDefContext* LSysDParser::axiomDef() {
  AxiomDefContext *_localctx = _tracker.createInstance<AxiomDefContext>(_ctx, getState());
  enterRule(_localctx, 42, LSysDParser::RuleAxiomDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(LSysDParser::KWAXIOM);
    setState(433);
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


std::any LSysDParser::PropDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitPropDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::PropDefContext* LSysDParser::propDef() {
  PropDefContext *_localctx = _tracker.createInstance<PropDefContext>(_ctx, getState());
  enterRule(_localctx, 44, LSysDParser::RulePropDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    match(LSysDParser::KWSET);
    setState(436);
    match(LSysDParser::ID);
    setState(437);
    match(LSysDParser::ASSIGN);
    setState(438);
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


std::any LSysDParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::FuncDefContext* LSysDParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 46, LSysDParser::RuleFuncDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    match(LSysDParser::KWFUNCTION);
    setState(441);
    match(LSysDParser::ID);
    setState(442);
    match(LSysDParser::LPAREN);
    setState(443);
    params();
    setState(444);
    match(LSysDParser::RPAREN);
    setState(448);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ASSIGN: {
        setState(445);
        match(LSysDParser::ASSIGN);
        setState(446);
        expression(0);
        break;
      }

      case LSysDParser::LBRACE: {
        setState(447);
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


std::any LSysDParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ConstDefContext* LSysDParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 48, LSysDParser::RuleConstDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(450);
    match(LSysDParser::DOLLARID);
    setState(451);
    match(LSysDParser::ASSIGN);
    setState(452);
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


std::any LSysDParser::TableBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitTableBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::TableBlockContext* LSysDParser::tableBlock() {
  TableBlockContext *_localctx = _tracker.createInstance<TableBlockContext>(_ctx, getState());
  enterRule(_localctx, 50, LSysDParser::RuleTableBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    match(LSysDParser::KWTABLE);
    setState(455);
    match(LSysDParser::ID);
    setState(456);
    match(LSysDParser::LBRACE);
    setState(457);
    rules();
    setState(458);
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


std::any LSysDParser::RulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RulesBlockContext* LSysDParser::rulesBlock() {
  RulesBlockContext *_localctx = _tracker.createInstance<RulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 52, LSysDParser::RuleRulesBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    match(LSysDParser::KWRULES);
    setState(462);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(461);
      nl();
    }
    setState(464);
    match(LSysDParser::LBRACE);
    setState(465);
    ruleDefs();
    setState(466);
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


std::any LSysDParser::ProductionRulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRulesBlockContext* LSysDParser::productionRulesBlock() {
  ProductionRulesBlockContext *_localctx = _tracker.createInstance<ProductionRulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 54, LSysDParser::RuleProductionRulesBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    match(LSysDParser::KWPRODUCTION);
    setState(470);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(469);
      nl();
    }
    setState(472);
    match(LSysDParser::KWRULES);
    setState(474);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(473);
      nl();
    }
    setState(476);
    match(LSysDParser::LBRACE);
    setState(477);
    ruleDefs();
    setState(478);
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


std::any LSysDParser::CodingRulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRulesBlockContext* LSysDParser::codingRulesBlock() {
  CodingRulesBlockContext *_localctx = _tracker.createInstance<CodingRulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 56, LSysDParser::RuleCodingRulesBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    match(LSysDParser::KWCODING);
    setState(482);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(481);
      nl();
    }
    setState(484);
    match(LSysDParser::KWRULES);
    setState(486);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::NEW_LINE) {
      setState(485);
      nl();
    }
    setState(488);
    match(LSysDParser::LBRACE);
    setState(489);
    ruleDefs();
    setState(490);
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


std::any LSysDParser::RulesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRules(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RulesContext* LSysDParser::rules() {
  RulesContext *_localctx = _tracker.createInstance<RulesContext>(_ctx, getState());
  enterRule(_localctx, 58, LSysDParser::RuleRules);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(493);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      setState(492);
      sep();
      break;
    }

    default:
      break;
    }
    setState(500);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(495);
        anyRule();
        setState(496);
        sep(); 
      }
      setState(502);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    }
    setState(504);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 101189688) != 0 || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(503);
      anyRule();
    }
    setState(507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(506);
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


std::any LSysDParser::RuleDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRuleDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RuleDefsContext* LSysDParser::ruleDefs() {
  RuleDefsContext *_localctx = _tracker.createInstance<RuleDefsContext>(_ctx, getState());
  enterRule(_localctx, 60, LSysDParser::RuleRuleDefs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(510);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      setState(509);
      sep();
      break;
    }

    default:
      break;
    }
    setState(517);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(512);
        ruleDef();
        setState(513);
        sep(); 
      }
      setState(519);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    }
    setState(521);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 101189688) != 0 || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(520);
      ruleDef();
    }
    setState(524);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(523);
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


std::any LSysDParser::ProductionRuleDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRuleDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRuleDefsContext* LSysDParser::productionRuleDefs() {
  ProductionRuleDefsContext *_localctx = _tracker.createInstance<ProductionRuleDefsContext>(_ctx, getState());
  enterRule(_localctx, 62, LSysDParser::RuleProductionRuleDefs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(527);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      setState(526);
      sep();
      break;
    }

    default:
      break;
    }
    setState(534);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(529);
        productionRuleDef();
        setState(530);
        sep(); 
      }
      setState(536);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    }
    setState(538);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 101189688) != 0 || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(537);
      productionRuleDef();
    }
    setState(541);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(540);
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


std::any LSysDParser::CodingRuleDefsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRuleDefs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRuleDefsContext* LSysDParser::codingRuleDefs() {
  CodingRuleDefsContext *_localctx = _tracker.createInstance<CodingRuleDefsContext>(_ctx, getState());
  enterRule(_localctx, 64, LSysDParser::RuleCodingRuleDefs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(544);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      setState(543);
      sep();
      break;
    }

    default:
      break;
    }
    setState(551);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(546);
        codingRuleDef();
        setState(547);
        sep(); 
      }
      setState(553);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
    }
    setState(555);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 101189688) != 0 || _la == LSysDParser::XM

    || _la == LSysDParser::RULECHAR) {
      setState(554);
      codingRuleDef();
    }
    setState(558);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::SEMI

    || _la == LSysDParser::NEW_LINE) {
      setState(557);
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


std::any LSysDParser::AnyRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitAnyRule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::AnyRuleContext* LSysDParser::anyRule() {
  AnyRuleContext *_localctx = _tracker.createInstance<AnyRuleContext>(_ctx, getState());
  enterRule(_localctx, 66, LSysDParser::RuleAnyRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(562);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(560);
      productionRule();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(561);
      codingRule();
      break;
    }

    default:
      break;
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


std::any LSysDParser::ProductionRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRuleContext* LSysDParser::productionRule() {
  ProductionRuleContext *_localctx = _tracker.createInstance<ProductionRuleContext>(_ctx, getState());
  enterRule(_localctx, 68, LSysDParser::RuleProductionRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
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


std::any LSysDParser::CodingRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRule(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRuleContext* LSysDParser::codingRule() {
  CodingRuleContext *_localctx = _tracker.createInstance<CodingRuleContext>(_ctx, getState());
  enterRule(_localctx, 70, LSysDParser::RuleCodingRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(566);
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


std::any LSysDParser::RuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRuleDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RuleDefContext* LSysDParser::ruleDef() {
  RuleDefContext *_localctx = _tracker.createInstance<RuleDefContext>(_ctx, getState());
  enterRule(_localctx, 72, LSysDParser::RuleRuleDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(570);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(568);
      productionRuleDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(569);
      codingRuleDef();
      break;
    }

    default:
      break;
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


std::any LSysDParser::ProductionRuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitProductionRuleDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ProductionRuleDefContext* LSysDParser::productionRuleDef() {
  ProductionRuleDefContext *_localctx = _tracker.createInstance<ProductionRuleDefContext>(_ctx, getState());
  enterRule(_localctx, 74, LSysDParser::RuleProductionRuleDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(572);
      weight();
      break;
    }

    default:
      break;
    }
    setState(576);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      setState(575);
      lcontext();
      break;
    }

    default:
      break;
    }
    setState(578);
    lside();
    setState(580);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::GT) {
      setState(579);
      rcontext();
    }
    setState(583);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::COLON) {
      setState(582);
      cond();
    }
    setState(585);
    match(LSysDParser::ARROW);
    setState(587);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
    case 1: {
      setState(586);
      nl();
      break;
    }

    default:
      break;
    }
    setState(589);
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


std::any LSysDParser::CodingRuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCodingRuleDef(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CodingRuleDefContext* LSysDParser::codingRuleDef() {
  CodingRuleDefContext *_localctx = _tracker.createInstance<CodingRuleDefContext>(_ctx, getState());
  enterRule(_localctx, 76, LSysDParser::RuleCodingRuleDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(592);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
    case 1: {
      setState(591);
      weight();
      break;
    }

    default:
      break;
    }
    setState(595);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      setState(594);
      lcontext();
      break;
    }

    default:
      break;
    }
    setState(597);
    lside();
    setState(599);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::GT) {
      setState(598);
      rcontext();
    }
    setState(602);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::COLON) {
      setState(601);
      cond();
    }
    setState(604);
    match(LSysDParser::DARROW);
    setState(606);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      setState(605);
      nl();
      break;
    }

    default:
      break;
    }
    setState(608);
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


std::any LSysDParser::TagPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitTagPrefix(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::TagPrefixContext* LSysDParser::tagPrefix() {
  TagPrefixContext *_localctx = _tracker.createInstance<TagPrefixContext>(_ctx, getState());
  enterRule(_localctx, 78, LSysDParser::RuleTagPrefix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    tag();
    setState(611);
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


std::any LSysDParser::TagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitTag(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::TagContext* LSysDParser::tag() {
  TagContext *_localctx = _tracker.createInstance<TagContext>(_ctx, getState());
  enterRule(_localctx, 80, LSysDParser::RuleTag);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(613);
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

tree::TerminalNode* LSysDParser::WeightContext::BITOR() {
  return getToken(LSysDParser::BITOR, 0);
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


std::any LSysDParser::WeightContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitWeight(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::WeightContext* LSysDParser::weight() {
  WeightContext *_localctx = _tracker.createInstance<WeightContext>(_ctx, getState());
  enterRule(_localctx, 82, LSysDParser::RuleWeight);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(615);
    _la = _input->LA(1);
    if (!(_la == LSysDParser::INT

    || _la == LSysDParser::FLOAT || _la == LSysDParser::XM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(616);
    match(LSysDParser::BITOR);
   
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


std::any LSysDParser::LsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLside(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LsideContext* LSysDParser::lside() {
  LsideContext *_localctx = _tracker.createInstance<LsideContext>(_ctx, getState());
  enterRule(_localctx, 84, LSysDParser::RuleLside);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(618);
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


std::any LSysDParser::LcontextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLcontext(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LcontextContext* LSysDParser::lcontext() {
  LcontextContext *_localctx = _tracker.createInstance<LcontextContext>(_ctx, getState());
  enterRule(_localctx, 86, LSysDParser::RuleLcontext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(623);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 100665368) != 0 || _la == LSysDParser::RULECHAR) {
      setState(620);
      lItem();
      setState(625);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(626);
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


std::any LSysDParser::RcontextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRcontext(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RcontextContext* LSysDParser::rcontext() {
  RcontextContext *_localctx = _tracker.createInstance<RcontextContext>(_ctx, getState());
  enterRule(_localctx, 88, LSysDParser::RuleRcontext);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    match(LSysDParser::GT);
    setState(632);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 100665368) != 0 || _la == LSysDParser::RULECHAR) {
      setState(629);
      lItem();
      setState(634);
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


std::any LSysDParser::RsideContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRside(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RsideContext* LSysDParser::rside() {
  RsideContext *_localctx = _tracker.createInstance<RsideContext>(_ctx, getState());
  enterRule(_localctx, 90, LSysDParser::RuleRside);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(638);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 100665880) != 0 || _la == LSysDParser::RULECHAR) {
      setState(635);
      rItem();
      setState(640);
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


std::any LSysDParser::WordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitWord(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::WordContext* LSysDParser::word() {
  WordContext *_localctx = _tracker.createInstance<WordContext>(_ctx, getState());
  enterRule(_localctx, 92, LSysDParser::RuleWord);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(644);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 100665880) != 0 || _la == LSysDParser::RULECHAR) {
      setState(641);
      rItem();
      setState(646);
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


std::any LSysDParser::LCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LCharContext* LSysDParser::lChar() {
  LCharContext *_localctx = _tracker.createInstance<LCharContext>(_ctx, getState());
  enterRule(_localctx, 94, LSysDParser::RuleLChar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(647);
    validLeftChar();
    setState(652);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::LPAREN) {
      setState(648);
      match(LSysDParser::LPAREN);
      setState(649);
      params();
      setState(650);
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


std::any LSysDParser::LItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitLItem(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::LItemContext* LSysDParser::lItem() {
  LItemContext *_localctx = _tracker.createInstance<LItemContext>(_ctx, getState());
  enterRule(_localctx, 96, LSysDParser::RuleLItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(669);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ID:
      case LSysDParser::INT:
      case LSysDParser::ADD:
      case LSysDParser::SUB:
      case LSysDParser::RULECHAR: {
        enterOuterAlt(_localctx, 1);
        setState(654);
        validLeftChar();
        setState(659);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::LPAREN) {
          setState(655);
          match(LSysDParser::LPAREN);
          setState(656);
          params();
          setState(657);
          match(LSysDParser::RPAREN);
        }
        break;
      }

      case LSysDParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(661);
        match(LSysDParser::LBRACK);
        setState(665);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 100665368) != 0 || _la == LSysDParser::RULECHAR) {
          setState(662);
          lItem();
          setState(667);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(668);
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


std::any LSysDParser::RItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitRItem(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::RItemContext* LSysDParser::rItem() {
  RItemContext *_localctx = _tracker.createInstance<RItemContext>(_ctx, getState());
  enterRule(_localctx, 98, LSysDParser::RuleRItem);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(687);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::ID:
      case LSysDParser::INT:
      case LSysDParser::ADD:
      case LSysDParser::SUB:
      case LSysDParser::RULECHAR: {
        enterOuterAlt(_localctx, 1);
        setState(671);
        validRightChar();
        setState(676);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LSysDParser::LPAREN) {
          setState(672);
          match(LSysDParser::LPAREN);
          setState(673);
          args();
          setState(674);
          match(LSysDParser::RPAREN);
        }
        break;
      }

      case LSysDParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(678);
        match(LSysDParser::LBRACK);
        setState(682);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 100665880) != 0 || _la == LSysDParser::RULECHAR) {
          setState(679);
          rItem();
          setState(684);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(685);
        match(LSysDParser::RBRACK);
        break;
      }

      case LSysDParser::LBRACE: {
        enterOuterAlt(_localctx, 3);
        setState(686);
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


std::any LSysDParser::ValidLeftCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitValidLeftChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ValidLeftCharContext* LSysDParser::validLeftChar() {
  ValidLeftCharContext *_localctx = _tracker.createInstance<ValidLeftCharContext>(_ctx, getState());
  enterRule(_localctx, 100, LSysDParser::RuleValidLeftChar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(689);
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


std::any LSysDParser::ValidRightCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitValidRightChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ValidRightCharContext* LSysDParser::validRightChar() {
  ValidRightCharContext *_localctx = _tracker.createInstance<ValidRightCharContext>(_ctx, getState());
  enterRule(_localctx, 102, LSysDParser::RuleValidRightChar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(691);
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


std::any LSysDParser::ValidCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitValidChar(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ValidCharContext* LSysDParser::validChar() {
  ValidCharContext *_localctx = _tracker.createInstance<ValidCharContext>(_ctx, getState());
  enterRule(_localctx, 104, LSysDParser::RuleValidChar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(693);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 100663320) != 0 || _la == LSysDParser::RULECHAR)) {
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


std::any LSysDParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ParamsContext* LSysDParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 106, LSysDParser::RuleParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(703);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LSysDParser::ID) {
      setState(695);
      param();
      setState(700);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LSysDParser::COMMA) {
        setState(696);
        match(LSysDParser::COMMA);
        setState(697);
        param();
        setState(702);
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


std::any LSysDParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ParamContext* LSysDParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 108, LSysDParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(705);
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


std::any LSysDParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::CondContext* LSysDParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 110, LSysDParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    match(LSysDParser::COLON);
    setState(708);
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


std::any LSysDParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgsContext* LSysDParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 112, LSysDParser::RuleArgs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(721);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144416608981352696) != 0) {
      setState(710);
      arg();
      setState(715);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(711);
          match(LSysDParser::COMMA);
          setState(712);
          arg(); 
        }
        setState(717);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx);
      }
      setState(719);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::COMMA) {
        setState(718);
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


std::any LSysDParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgContext* LSysDParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 114, LSysDParser::RuleArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(723);
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


std::any LSysDParser::LogicBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::CmpBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::FunctionCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::BitBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::AritUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::LogicUnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::ParenthesizedExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::AritBinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::IfElseExprContext::accept(tree::ParseTreeVisitor *visitor) {
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
  size_t startState = 116;
  enterRecursionRule(_localctx, 116, LSysDParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(743);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::LPAREN: {
        _localctx = _tracker.createInstance<ParenthesizedExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(726);
        match(LSysDParser::LPAREN);
        setState(727);
        expression(0);
        setState(728);
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
        setState(730);
        constant();
        break;
      }

      case LSysDParser::ID: {
        _localctx = _tracker.createInstance<IdExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(731);
        match(LSysDParser::ID);
        break;
      }

      case LSysDParser::ADD:
      case LSysDParser::SUB: {
        _localctx = _tracker.createInstance<AritUnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(732);
        antlrcpp::downCast<AritUnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == LSysDParser::ADD

        || _la == LSysDParser::SUB)) {
          antlrcpp::downCast<AritUnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(733);
        expression(13);
        break;
      }

      case LSysDParser::BITNOT:
      case LSysDParser::NOT: {
        _localctx = _tracker.createInstance<LogicUnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(734);
        antlrcpp::downCast<LogicUnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == LSysDParser::BITNOT

        || _la == LSysDParser::NOT)) {
          antlrcpp::downCast<LogicUnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(735);
        expression(12);
        break;
      }

      case LSysDParser::KWIF: {
        _localctx = _tracker.createInstance<IfElseExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(736);
        match(LSysDParser::KWIF);
        setState(737);
        expression(0);
        setState(738);
        match(LSysDParser::KWTHEN);
        setState(739);
        expression(0);
        setState(740);
        match(LSysDParser::KWELSE);
        setState(741);
        expression(1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(782);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(780);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(745);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(746);
          antlrcpp::downCast<AritBinaryExprContext *>(_localctx)->op = match(LSysDParser::POW);
          setState(747);
          expression(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(748);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(749);
          antlrcpp::downCast<AritBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 939524096) != 0)) {
            antlrcpp::downCast<AritBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(750);
          expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AritBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(751);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(752);
          antlrcpp::downCast<AritBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == LSysDParser::ADD

          || _la == LSysDParser::SUB)) {
            antlrcpp::downCast<AritBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(753);
          expression(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CmpBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(754);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(755);
          antlrcpp::downCast<CmpBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 7864320) != 0)) {
            antlrcpp::downCast<CmpBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(756);
          expression(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CmpBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(757);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(758);
          antlrcpp::downCast<CmpBinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == LSysDParser::EQ

          || _la == LSysDParser::NE)) {
            antlrcpp::downCast<CmpBinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(759);
          expression(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(760);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(761);
          antlrcpp::downCast<BitBinaryExprContext *>(_localctx)->op = match(LSysDParser::BITAND);
          setState(762);
          expression(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(763);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(764);
          antlrcpp::downCast<BitBinaryExprContext *>(_localctx)->op = match(LSysDParser::BITXOR);
          setState(765);
          expression(6);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(766);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(767);
          antlrcpp::downCast<BitBinaryExprContext *>(_localctx)->op = match(LSysDParser::BITOR);
          setState(768);
          expression(5);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(769);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(770);
          antlrcpp::downCast<LogicBinaryExprContext *>(_localctx)->op = match(LSysDParser::AND);
          setState(771);
          expression(4);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicBinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(772);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(773);
          antlrcpp::downCast<LogicBinaryExprContext *>(_localctx)->op = match(LSysDParser::OR);
          setState(774);
          expression(3);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<FunctionCallExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(775);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(776);
          match(LSysDParser::LPAREN);
          setState(777);
          arguments();
          setState(778);
          match(LSysDParser::RPAREN);
          break;
        }

        default:
          break;
        } 
      }
      setState(784);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx);
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


std::any LSysDParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgumentsContext* LSysDParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 118, LSysDParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(796);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144416608981352696) != 0) {
      setState(785);
      argument();
      setState(790);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(786);
          match(LSysDParser::COMMA);
          setState(787);
          argument(); 
        }
        setState(792);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx);
      }
      setState(794);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LSysDParser::COMMA) {
        setState(793);
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


std::any LSysDParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

LSysDParser::ArgumentContext* LSysDParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 120, LSysDParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(798);
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


std::any LSysDParser::NullValueContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::TrueValueContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::FloatConstantContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::IntConstantContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any LSysDParser::FalseValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LSysDParserVisitor*>(visitor))
    return parserVisitor->visitFalseValue(this);
  else
    return visitor->visitChildren(this);
}
LSysDParser::ConstantContext* LSysDParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 122, LSysDParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(806);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LSysDParser::INT: {
        _localctx = _tracker.createInstance<LSysDParser::IntConstantContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(800);
        antlrcpp::downCast<IntConstantContext *>(_localctx)->v = match(LSysDParser::INT);
        break;
      }

      case LSysDParser::FLOAT: {
        _localctx = _tracker.createInstance<LSysDParser::FloatConstantContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(801);
        antlrcpp::downCast<FloatConstantContext *>(_localctx)->v = match(LSysDParser::FLOAT);
        break;
      }

      case LSysDParser::STRING: {
        _localctx = _tracker.createInstance<LSysDParser::StringConstantContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(802);
        antlrcpp::downCast<StringConstantContext *>(_localctx)->v = match(LSysDParser::STRING);
        break;
      }

      case LSysDParser::KWTRUE: {
        _localctx = _tracker.createInstance<LSysDParser::TrueValueContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(803);
        match(LSysDParser::KWTRUE);
        break;
      }

      case LSysDParser::KWFALSE: {
        _localctx = _tracker.createInstance<LSysDParser::FalseValueContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(804);
        match(LSysDParser::KWFALSE);
        break;
      }

      case LSysDParser::KWNULL: {
        _localctx = _tracker.createInstance<LSysDParser::NullValueContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(805);
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
    case 58: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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

void LSysDParser::initialize() {
  ::antlr4::internal::call_once(lsysdparserParserOnceFlag, lsysdparserParserInitialize);
}
