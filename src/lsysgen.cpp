
#include "lsysgen.h"

#include <streambuf>
#include <sstream>



/*
 * Ideas:
 * - Solucionar tema del formato en los errores (--html?)
 * - Cache grammar outputs for java not to be required?
 * - Parámetros por nombre con param, por nombre y posición entre paréntesis?
 * - Números aleatorios en expresiones (rand(), randFloat())
 * - Comentario en SVG "Made in LSysGen [VERSION]"
 * - Si el archivo de salida introducido es una carpeta, exportar en esa carpeta con el nombre del módulo + .txt/.svg
 * - line_width relative to SVG width? Parece imposible.
 * - Si un archivo no tiene axioma pero se introduce con -a, que no lance error (warning? notice?)
 * - Llamadas a otros LSystem: ¿un settings por llamada? (Mejor solo args)
 * - Acciones
 * - Cada rama ([]) un hilo (thread)? (como garantizar un mismo resultado con una misma semilla?)
 * - Módulo para compilar a código para ejecutar?
 * - Interpretación de símbolos dependiente de contexto? (lc cambie el color de fill?)
 *
 */

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
    if (settings.inputFile.isset()) {
        std::string const& file = settings.inputFile.get();
        std::string content;
        if (!readFromFile(file, content)) {
            std::cerr << "Input file '" << file << "' does not exist." << std::endl;
            exit(1);
        }

        switch (settings.inputMode.get()) {
            case Settings::InputMode::LSD:
                return parseLSystemFromString(content, settings);
            case Settings::InputMode::AXIOM:
                if (settings.axiom.isset())
                    content = settings.axiom.get();
                return parseLSystemFromAxiom(content, settings);
            default:
                return nullptr;
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

lsysgen::LSystem<char> * parseLSystemFromString(std::string_view fileContents, lsysgen::Settings const& settings) {

    antlr4::ANTLRInputStream * input = new antlr4::ANTLRInputStream(fileContents);
    LSysDLexer * lexer = new LSysDLexer(input);

    if (lexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * tokens = new antlr4::CommonTokenStream(lexer);
    LSysDParser * parser = new LSysDParser(tokens);

    antlr4::tree::ParseTree * tree = parser->main();

    if (parser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    LSysDVisitor visitor(settings);
    lsysgen::LSystem<char> * lsystem = std::any_cast<lsysgen::LSystem<char> *>(visitor.visit(tree));

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        return nullptr;
    }

    return lsystem;
}

lsysgen::LSystem<char> * parseLSystemFromAxiom(std::string_view s_axiom, lsysgen::Settings const& settings) {
    antlr4::ANTLRInputStream * axiomInput = new antlr4::ANTLRInputStream(s_axiom);
    LSysDLexer * axiomLexer = new LSysDLexer(axiomInput);

    if (axiomLexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * axiomTokens = new antlr4::CommonTokenStream(axiomLexer);
    LSysDParser * axiomParser = new LSysDParser(axiomTokens);

    antlr4::tree::ParseTree * axiomTree = axiomParser->mainWord();

    if (axiomParser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    LSysDVisitor visitor(settings);
    lsysgen::LSystem<char> * lsystem = std::any_cast<lsysgen::LSystem<char> *>(visitor.visit(axiomTree));

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        return nullptr;
    }

    return lsystem;
}
