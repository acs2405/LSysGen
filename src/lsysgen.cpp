
#include "lsysgen.h"

#include <streambuf>
#include <sstream>



lsysgen::LSystem<char>* parseLSystemFromFile(std::string const& file) {
    if (file == "-") {
        return parseLSystemFromStream(std::cin, "<stdin>");
    } else {
        std::fstream fstream;
        fstream.open(file);
        if (fstream.fail()) {
            std::cerr << "File '" << file << "' does not exist." << std::endl;
            exit(1);
        }
        return parseLSystemFromStream(fstream, file);
    }
    // std::cout << file << std::endl;
}

lsysgen::LSystem<char>* parseLSystemFromStream(std::istream& stream, std::string const& file) {

    std::string fileContents((std::istreambuf_iterator<char>(stream)),
                 std::istreambuf_iterator<char>());

    std::stringstream ss;
    ss << fileContents;

    antlr4::ANTLRInputStream* input = new antlr4::ANTLRInputStream(ss);
    LSysDLexer* lexer = new LSysDLexer(input);

    if (lexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream* tokens = new antlr4::CommonTokenStream(lexer);
    LSysDParser* parser = new LSysDParser(tokens);

    antlr4::tree::ParseTree *tree = parser->main();

    if (parser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    std::vector<std::string>* lines = new std::vector<std::string>();
    std::string line;
    ss << fileContents;
    while (std::getline(ss, line))
        lines->push_back(line);

    // TreeShapeListener listener;
    // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    
    LSysDVisitor* visitor = new LSysDVisitor(file, lines);
    lsysgen::LSystem<char>* lsystem = visitor->visit(tree);

    // std::list<Error*> *errs = visitor->getErrors();
    // std::cerr << errs->size() << " errors" << std::endl;
    // for (Error *e : errs)
    //     std::cerr << e.getMessage() << std::endl;

    // std::cout << tree->getText() << std::endl;

    return lsystem;
}
