
#include "lsys.h"

#include <streambuf>
#include <sstream>


/*
 * 
 * java -jar antlr-4.8-complete.jar -Dlanguage=Cpp -o antlr4-runtime/ LSysDParser.g4 LSysDLexer.g4 -visitor
 * 
 * 
 * - cd <antlr4-dir>/runtime/Cpp
 * - mkdir build && mkdir run && cd build
 * - cmake ..
 * - make
 * - DESTDIR=<antlr4-dir>/runtime/Cpp/run make install
 * 
 * 
 * - mkdir build; cd build
 * - cmake ..
 * - make
 * - ./lsysgen b2.lsd
 * 
 */


// class TreeShapeListener : public LSysDParserBaseListener {
// public:
//     void enterMain(LSysDParser::MainContext *ctx) override {
//     // Do something when entering the key rule.
//     }
// };


int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: lsysgen FILE.lsd [N_ITERATIONS]" << std::endl;
        exit(1);
    }

    // g2D_prepare(argc, argv);

    lsys::LSystem<char>* lsystem = parseLSystem(argv[1]);

    if (lsystem == nullptr)
        exit(1);

    if (argc == 3) {
        int n = stoi(argv[2]);
        lsystem->iterations = n;
    }

    lsystem->prepare();
    lsystem->iterate();

    // int i = 0;
    // for (lsys::ParseTreeNode<lsys::InstanceNodeContent, char>* iteration : *lsystem->encodedProgression) {
    //     std::cout << i++ << ": " << iteration->toString() << std::endl;
    // }
    std::cout << lsystem->encodedProgression->back()->toString() << std::endl;

    Drawer2D drawer(lsystem);
    drawer.prepare(argc, argv);
    drawer.draw();

    return 0;
}

lsys::LSystem<char>* parseLSystem(std::string file) {
    if (file == "-") {
        return parseLSystem(file, std::cin);
    } else {
        std::fstream fstream;
        fstream.open(file);
        if (fstream.fail()) {
            std::cerr << "File '" << file << "' does not exist." << std::endl;
            exit(1);
        }
        return parseLSystem(file, fstream);
    }
    // std::cout << file << std::endl;
}

lsys::LSystem<char>* parseLSystem(std::string file, std::istream& stream) {

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
    lsys::LSystem<char>* lsystem = visitor->visit(tree);

    // std::list<Error*> *errs = visitor->getErrors();
    // std::cerr << errs->size() << " errors" << std::endl;
    // for (Error *e : errs)
    //     std::cerr << e.getMessage() << std::endl;

    // std::cout << tree->getText() << std::endl;

    return lsystem;
}