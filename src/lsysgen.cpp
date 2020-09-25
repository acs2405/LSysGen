
#include "lsysgen.h"

#include <streambuf>
#include <sstream>



lsysgen::LSystem<char>* lsystem_create(const char* file) {
    lsysgen::LSystem<char>* lsystem = parseLSystemFromFile(file);

    if (lsystem == nullptr)
        return nullptr;

    lsystem->prepare();

    if (lsystem->messages()->failed()) {
        lsystem->messages()->dump();
        return nullptr;
    }

    return lsystem;
}

void lsystem_generate(LSystem<char>* lsystem) {
    lsystem->iterate();
}

void lsystem_iterate(LSystem<char>* lsystem, int iterations) {
    lsystem->iterate(iterations);
}

int lsystem_get_iteration_number(LSystem<char>* lsystem) {
    return lsystem->iteration();
}

int lsystem_get_number_of_errors(LSystem<char>* lsystem) {
    return lsystem->messages()->failed();
}

const char* lsystem_get_result_string(LSystem<char>* lsystem) {
    if (lsystem->messages()->errors().size() == 0) {
        std::string sret = lsystem->current()->toString();
        const char* ret1 = sret.c_str();
        char *ret = new char[sret.size()+1];
        strcpy(ret, ret1);

        return ret;
    } else
        return nullptr;
}

const char* lsystem_to_svg(LSystem<char>* lsystem) {
    if (lsystem->messages()->errors().size() == 0) {
        std::string sret = node2svg(lsystem->current(), lsystem);
        const char* ret1 = sret.c_str();
        char *ret = new char[sret.size()+1];
        strcpy(ret, ret1);

        return ret;
    } else
        return nullptr;
}



lsysgen::LSystem<char>* parseLSystemFromFile(std::string const& file) {
    if (file == "-") {
        return parseLSystemFromStream(std::cin, file); //"<stdin>");
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

    LSysDVisitor visitor(file, lines);
    lsysgen::Module<char>* module = visitor.visit(tree);

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        return nullptr;
    }
    
    lsysgen::LSystem<char>* lsystem = module->mainLSystem();

    return lsystem;
}
