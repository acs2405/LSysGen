
#include "lsysgen.h"

#include <streambuf>
#include <sstream>



lsysgen::LSystem<char> * lsystem_create(lsysgen::Settings const& settings) {
    lsysgen::LSystem<char> * lsystem = parseLSystem(settings);

    if (lsystem == nullptr)
        return nullptr;

    lsystem->prepare();

    if (lsystem->messages()->failed()) {
        lsystem->messages()->dump();
        return nullptr;
    }

    return lsystem;
}

lsysgen::LSystem<char> * lsystem_create_from_file(char const* file) {
    Settings settings;
    settings.inputFile.set(file);
    return lsystem_create(settings);
}

void lsystem_generate(lsysgen::LSystem<char> * lsystem) {
    lsystem->iterate();
}

void lsystem_iterate(lsysgen::LSystem<char> * lsystem, int iterations) {
    lsystem->iterate(iterations);
}

int lsystem_get_iteration_number(lsysgen::LSystem<char> * lsystem) {
    return lsystem->iteration();
}

int lsystem_get_number_of_errors(lsysgen::LSystem<char> * lsystem) {
    return lsystem->messages()->failed();
}

char const* lsystem_get_result_string(lsysgen::LSystem<char> * lsystem) {
    if (lsystem->messages()->errors().size() == 0) {
        std::string sret = lsystem->current()->toString();
        char const* ret1 = sret.c_str();
        char * ret = new char[sret.size()+1];
        strcpy(ret, ret1);

        return ret;
    } else
        return nullptr;
}

char const* lsystem_to_svg(lsysgen::LSystem<char> * lsystem) {
    if (lsystem->messages()->errors().size() == 0) {
        std::string sret = node2svg(lsystem->current(), lsystem);
        char const* ret1 = sret.c_str();
        char * ret = new char[sret.size()+1];
        strcpy(ret, ret1);

        return ret;
    } else
        return nullptr;
}



lsysgen::LSystem<char> * parseLSystem(lsysgen::Settings const& settings) {
    std::string fileContents;
    if (settings.inputFile.isset()) {
        std::string const& file = settings.inputFile.get();
        if (file == "-") {
            return parseLSystemFromStream(std::cin, settings); //"<stdin>");
        } else {
            std::fstream fstream(file.c_str(), std::ios::in);
            if (fstream.fail()) {
                std::cerr << "File '" << file << "' does not exist." << std::endl;
                exit(1);
            }
            lsysgen::LSystem<char> * ret = parseLSystemFromStream(fstream, settings);
            fstream.close();
            return ret;
        }
    } else {
        if (settings.axiom.isset()) {
            return parseLSystemFromAxiom(settings.axiom.get(), settings);
        } else {
            std::cerr << "You must either specify an input file or an axiom (-a AXIOM)" << std::endl;
                exit(1);
        }
    }
}

lsysgen::LSystem<char> * parseLSystemFromStream(std::istream & stream, lsysgen::Settings const& settings) {
        std::string fileContents((std::istreambuf_iterator<char>(stream)),
                     std::istreambuf_iterator<char>());
        switch (settings.inputMode.get()) {
            case Settings::InputMode::LSD:
                return parseLSystemFromString(fileContents, settings);
            case Settings::InputMode::AXIOM:
                return parseLSystemFromAxiom(fileContents, settings);
            default:
                return nullptr;
        }
}

// lsysgen::LSystem<char>* parseLSystemFromFile(std::string const& file) {
//     if (file == "-") {
//         return parseLSystemFromStream(std::cin, file); //"<stdin>");
//     } else {
//         std::fstream fstream;
//         fstream.open(file);
//         if (fstream.fail()) {
//             std::cerr << "File '" << file << "' does not exist." << std::endl;
//             exit(1);
//         }
//         // fstream.close();
//         return parseLSystemFromStream(fstream, file);
//     }
//     // std::cout << file << std::endl;
// }

lsysgen::LSystem<char> * parseLSystemFromString(std::string_view fileContents, lsysgen::Settings const& settings) {

    // std::string fileContents((std::istreambuf_iterator<char>(stream)),
    //              std::istreambuf_iterator<char>());

    // std::stringstream ss;
    // ss << fileContents;

    antlr4::ANTLRInputStream * input = new antlr4::ANTLRInputStream(fileContents);
    LSysDLexer * lexer = new LSysDLexer(input);

    if (lexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * tokens = new antlr4::CommonTokenStream(lexer);
    LSysDParser * parser = new LSysDParser(tokens);

    antlr4::tree::ParseTree * tree = parser->main();

    if (parser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    LSysDVisitor visitor(settings, splitInLines(fileContents));
    lsysgen::Module<char> * module = std::any_cast<lsysgen::Module<char> *>(visitor.visit(tree));

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        return nullptr;
    }
    
    lsysgen::LSystem<char> * lsystem = module->mainLSystem();

    if (settings.axiom.isset()) {
        lsystem->setAxiom(parseAxiom(settings.axiom.get(), visitor));
    }

    return lsystem;
}

/*
 * Ideas:
 * - Solucionar tema del formato en los errores (--html)
 * - Si un archivo no tiene axioma pero se introduce con -a, que no lance error (warning? notice?)
 * - Llamadas a otros LSystem: ¿un settings por llamada? (Mejor solo args)
 * - Parámetros por nombre con param, por nombre y posición entre paréntesis
 * - Acciones
 * - Cada rama ([]) un hilo (thread)? (como garantizar un mismo resultado con una misma semilla?)
 * - Módulo para compilar a código para ejecutar?
 * - Interpretación de símbolos dependiente de contexto? (lc cambie el color de fill?)
 *
 */

lsysgen::ParseTreeNode<lsysgen::InstanceNodeContent, char> * parseAxiom(std::string_view s_axiom, LSysDVisitor & visitor) {
    antlr4::ANTLRInputStream * axiomInput = new antlr4::ANTLRInputStream(s_axiom);
    LSysDLexer * axiomLexer = new LSysDLexer(axiomInput);

    if (axiomLexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * axiomTokens = new antlr4::CommonTokenStream(axiomLexer);
    LSysDParser * axiomParser = new LSysDParser(axiomTokens);

    antlr4::tree::ParseTree * axiomTree = axiomParser->mainWord();
    // for (auto n : static_cast<LSysDParser::WordContext*>(axiomTree)->rItem())
    //     std::cout << n->getText() << std::endl;

    if (axiomParser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    lsysgen::ParseTreeNode<lsysgen::InstanceNodeContent, char> * axiom = 
            std::any_cast<lsysgen::ParseTreeNode<lsysgen::InstanceNodeContent, char> *>
            (visitor.visit(axiomTree, splitInLines(s_axiom)));

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        exit(1);
    }

    return axiom;
}

void parseRules(std::string_view s_rules, LSysDVisitor & visitor) {
    antlr4::ANTLRInputStream * rulesInput = new antlr4::ANTLRInputStream(s_rules);
    LSysDLexer * rulesLexer = new LSysDLexer(rulesInput);

    if (rulesLexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * rulesTokens = new antlr4::CommonTokenStream(rulesLexer);
    LSysDParser * rulesParser = new LSysDParser(rulesTokens);

    antlr4::tree::ParseTree * rulesTree = rulesParser->mainRuleDefs();

    if (rulesParser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    // This adds the rules to the current LSystem
    visitor.visit(rulesTree, splitInLines(s_rules));

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        exit(1);
    }
}

lsysgen::LSystem<char> * parseLSystemFromAxiom(std::string_view s_axiom, lsysgen::Settings const& settings) {
    LSysDVisitor visitor(settings);
    lsysgen::LSystem<char> * lsystem = visitor.createLSystem("<inline>");

    lsystem->setAxiom(parseAxiom(s_axiom, visitor));

    if (settings.rules.isset()) {
        // TODO: hacer los visits de rules que no cambien el estado sino que devuelvan las reglas
        parseRules(settings.rules.get(), visitor);
    }

    visitor.finishLSystem();

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        return nullptr;
    }

    return lsystem;
}

std::vector<std::string> * splitInLines(std::string_view s) {
    std::vector<std::string> * lines = new std::vector<std::string>();
    std::stringstream ss;
    ss << s;
    std::string line;
    while (std::getline(ss, line))
        lines->push_back(line);
    return lines;
}
