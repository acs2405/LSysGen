
#include "lsysgen.h"

#include "antlr4-runtime.h"
#include "LSysDLexer.h"
#include "LSysDParser.h"
#include "LSysDVisitor.h"
#include "interpreter2D.h"

#include <streambuf>
#include <sstream>
#include <filesystem>



/*
 * Ideas:
 * - Documentar con Doxygen (+ Sphinx?)
 * - Optimizar paths SVG de ramas padres e hijas con el mismo formato, uniéndolas en el mismo path
 * - Parámetros por nombre con param, por nombre y posición entre paréntesis?
 * - Números aleatorios en expresiones (rand(), randFloat()) y más funciones para hacer cálculos
 * - Comentario en SVG "Made in LSysGen [VERSION]"
 * - Si se ponen múltiples iteraciones (-i 0:5) y se selecciona una carpeta, crear los archivos *-i#.svg/.txt
 * - Errores HTML? (--html?)
 * - Parámetros por defecto en LSDL
 * 
 * - line_width relative to SVG width? Parece imposible.
 * - Si un archivo no tiene axioma pero se introduce con -a, que no lance error (warning? notice?)
 * - Llamadas a otros LSystem: ¿un settings por llamada? (Mejor solo args)
 * - Acciones {x=3; c=0}
 * - Cada rama ([]) un hilo (thread)? (como garantizar un mismo resultado con una misma semilla? Parece imposible)
 * - Módulo para compilar a código para ejecutar?
 * - Interpretación de símbolos dependiente de contexto? (lc cambie el color de fill?)
 *
 */

lsysgen::LSystem<char> ** lsystem_create_from_settings(lsysgen::Settings const& settings) {
    std::list<lsysgen::LSystem<char> *> * lsystems = createLSystems(settings);

    lsysgen::LSystem<char> ** ret = (lsysgen::LSystem<char> **)malloc(sizeof(lsysgen::LSystem<char> *) * lsystems->size());

    int i = 0;
    for (lsysgen::LSystem<char> * lsystem : *lsystems) {
        ret[i++] = lsystem; // TODO: comprobar si satura el buffer ret, Visual Studio se queja
    }

    delete lsystems;

    return ret;
}

lsysgen::LSystem<char> ** lsystem_create_from_file(char const* file) {
    Settings settings;
    settings.inputFiles.getRef().push_back(file);
    return lsystem_create_from_settings(settings);
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
        // char const* ret1 = sret.c_str();
        // char * ret = new char[sret.size()+1];
        // strcpy(ret, ret1);

        return sret.c_str(); // ERROR: apunta a bytes de la pila
    } else
        return nullptr;
}

char const* lsystem_to_svg(lsysgen::LSystem<char> * lsystem) {
    if (lsystem->messages()->errors().size() == 0) {
        std::string sret = node2svg(lsystem->current(), lsystem);
        // char const* ret1 = sret.c_str();
        // char * ret = new char[sret.size()+1];
        // strcpy(ret, ret1);

        return sret.c_str(); // ERROR: apunta a bytes de la pila
    } else
        return nullptr;
}



std::list<lsysgen::LSystem<char> *> * createLSystems(lsysgen::Settings const& settings) {
    std::list<lsysgen::LSystem<char> *> * lsystems = parseLSystem(settings);

    if (lsystems == nullptr)
        return nullptr;

    std::list<lsysgen::LSystem<char> *> * ret = new std::list<lsysgen::LSystem<char> *>();

    for (lsysgen::LSystem<char> * lsystem : *lsystems) {
        lsystem->prepare();

        if (lsystem->messages()->failed()) {
            lsystem->messages()->dump();
            ret->push_back(nullptr);
        } else {
            ret->push_back(lsystem);
        }
    }

    delete lsystems;

    return ret;
}

std::list<lsysgen::LSystem<char> *> * parseLSystem(lsysgen::Settings const& settings) {
    if (settings.inputFiles.isset()) {
        std::list<lsysgen::LSystem<char> *> * lsystems = new std::list<lsysgen::LSystem<char> *>();
        for (std::string const& inputFile : settings.inputFiles.get()) {
            if (std::filesystem::is_directory(inputFile)) {
                std::cerr << inputFile << " input file is a directory, not a source file" << std::endl;
                continue;
            }
            std::string content;
            if (!readFromFile(inputFile, content)) {
                std::cerr << "Input file '" << inputFile << "' does not exist." << std::endl;
                exit(1);
            }
            std::list<lsysgen::LSystem<char> *> * lsystems2;
            switch (settings.inputMode.get()) {
                case Settings::InputMode::LSD:
                    if (getModuleName(inputFile, "lsd") == "") {
                        std::cerr << inputFile << " is not a valid LSD file name (must be a valid module name + .lsd)" << std::endl;
                        continue;
                    }
                    lsystems2 = parseLSystemFromString(inputFile, content, settings);
                    if (lsystems2 != nullptr) {
                        lsystems->splice(lsystems->end(), *lsystems2);
                        delete lsystems2;
                    }
                    break;
                case Settings::InputMode::AXIOM:
                    if (getModuleName(inputFile, "lsd") == "") {
                        std::cerr << inputFile << " is not a valid LSD file name (must be a valid module name + optional extension)" << std::endl;
                        continue;
                    }
                    if (settings.axiom.isset())
                        content = settings.axiom.get();
                    lsystems2 = parseLSystemFromAxiom(inputFile, content, settings);
                    if (lsystems2 != nullptr) {
                        lsystems->splice(lsystems->end(), *lsystems2);
                        delete lsystems2;
                    }
                    break;
            }
        }
        return lsystems;
    } else {
        if (settings.axiom.isset()) {
            return parseLSystemFromAxiom("", settings.axiom.get(), settings);
        } else {
            std::cerr << "You must either specify an input file or an axiom (-a AXIOM)" << std::endl;
            exit(1);
        }
    }
}

std::list<lsysgen::LSystem<char> *> * parseLSystemFromString(std::string_view inputFile, std::string_view lsdContents, lsysgen::Settings const& settings) {

    antlr4::ANTLRInputStream * input = new antlr4::ANTLRInputStream(lsdContents);
    LSysDLexer * lexer = new LSysDLexer(input);

    if (lexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * tokens = new antlr4::CommonTokenStream(lexer);
    LSysDParser * parser = new LSysDParser(tokens);

    antlr4::tree::ParseTree * tree = parser->main();

    if (parser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    LSysDVisitor visitor(inputFile, settings);
    std::list<lsysgen::LSystem<char> *> * lsystems = 
            std::any_cast<std::list<lsysgen::LSystem<char> *> *>(visitor.visit(tree));

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        return nullptr;
    }

    return lsystems;
}

std::list<lsysgen::LSystem<char> *> * parseLSystemFromAxiom(std::string_view inputFile, std::string_view s_axiom, lsysgen::Settings const& settings) {
    antlr4::ANTLRInputStream * axiomInput = new antlr4::ANTLRInputStream(s_axiom);
    LSysDLexer * axiomLexer = new LSysDLexer(axiomInput);

    if (axiomLexer->getNumberOfSyntaxErrors() != 0)
        exit(1);

    antlr4::CommonTokenStream * axiomTokens = new antlr4::CommonTokenStream(axiomLexer);
    LSysDParser * axiomParser = new LSysDParser(axiomTokens);

    antlr4::tree::ParseTree * axiomTree = axiomParser->mainWord();

    if (axiomParser->getNumberOfSyntaxErrors() != 0)
        exit(1);

    LSysDVisitor visitor(inputFile, settings);
    std::list<lsysgen::LSystem<char> *> * lsystems = 
            std::any_cast<std::list<lsysgen::LSystem<char> *> *>(visitor.visit(axiomTree));

    if (visitor.messages()->failed()) {
        visitor.messages()->dump();
        return nullptr;
    }

    return lsystems;
}
