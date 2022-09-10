
#include "cliargs.h"


#include <set>

#define LSYSGEN_VERSION "0.6"



std::set<std::string> const argNames0 = {
    "--help", "-X", "--axiom-input"
};
std::set<std::string> const argNames1 = {
    "-a", "--axiom", "-r", "--rules", "-i", "--iterations", "-I", 
    "--ignore", "-S", "--seed", "-H", "--initial-heading", 
    "-R", "--rotation", "-L", "--line-width", "-B", "--background", 
    "-C", "--line-color", "-F", "--fill-color", "-l", "--lsystem"
};
std::set<std::string> const argNamesOpt = {
    "--svg"
};
std::set<std::string> const argNamesN = {
    "-A", "--args"
};
std::regex const argRegex ("([A-Za-z_][A-Za-z_0-9]*):(.+)");

void parseCLIArgs(int argc, char** argv, lsysgen::Settings & settings) {
    if (argc < 2) {
        printUsage();
    }

    // lsysgen::Settings * settings = new lsysgen::Settings();
    int spatialArgs = 0;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.size() == 0)
            continue;

        if (arg[0] != '-' || arg == "-") {
            if (spatialArgs == 0) {
                settings.inputFile.set(arg);
            } else if (spatialArgs == 1) {
                settings.outputResultFile.set(arg);
            } else {
                std::cerr << "Too many spatial arguments" << std::endl;
                exit(1);
            }
            ++spatialArgs;
        } else {
            if (argNames0.find(arg) != argNames0.end()) {
                if (arg == "-X" || arg == "--axiom-input") {
                    if (settings.inputMode.isset()) {
                        std::cerr << "Input mode argument repeated" << std::endl;
                        exit(1);
                    }
                    settings.inputMode.set(lsysgen::Settings::InputMode::AXIOM);
                } else if (arg == "--help") {
                    printHelp();
                }
            } else if (argNames1.find(arg) != argNames1.end()) {
                if (argc == i+1) {
                    std::cerr << arg << " must be followed by an argument (the axiom)" << std::endl;
                    exit(1);
                }
                std::string arg2 = argv[++i];
                if (arg == "-a" || arg == "--axiom") {
                    if (settings.axiom.isset()) {
                        std::cerr << "Axiom argument repeated" << std::endl;
                        exit(1);
                    }
                    settings.axiom.set(arg2);
                } else if (arg == "-r" || arg == "--rules") {
                    if (settings.rules.isset())
                        settings.rules.set(settings.rules.get() + "\n" + arg2);
                    else
                        settings.rules.set(arg2);
                } else if (arg == "-i" || arg == "--iterations") {
                    if (settings.iterations.isset()) {
                        std::cerr << "Iterations argument repeated" << std::endl;
                        exit(1);
                    }
                    try {
                        settings.iterations.set(std::stoi(arg2));
                    } catch (std::invalid_argument const& ex) {
                        std::cerr << arg << " value must be an integer" << std::endl;
                        exit(1);
                    }
                } else if (arg == "-l" || arg == "--lsystem") {
                    if (settings.lsystem.isset()) {
                        std::cerr << "LSystem argument repeated" << std::endl;
                        exit(1);
                    }
                    settings.lsystem.set(arg2);
                } else if (arg == "-I" || arg == "--ignore") {
                    if (settings.ignore.isset()) {
                        std::cerr << "Ignore argument repeated" << std::endl;
                        exit(1);
                    }
                    settings.ignore.set(arg2);
                } else if (arg == "-S" || arg == "--seed") {
                    if (settings.seed.isset()) {
                        std::cerr << "Seed argument repeated" << std::endl;
                        exit(1);
                    }
                    try {
                        settings.seed.set(std::stoi(arg2));
                    } catch (std::invalid_argument const& ex) {
                        std::cerr << arg << " value must be an integer" << std::endl;
                        exit(1);
                    }
                } else if (arg == "-H" || arg == "--heading") {
                    try {
                        settings.settings2D.heading.set(std::stod(arg2));
                    } catch (std::invalid_argument const& ex) {
                        std::cerr << arg << " value must be a number" << std::endl;
                        exit(1);
                    }
                } else if (arg == "-R" || arg == "--rotation") {
                    try {
                        settings.settings2D.rotation.set(std::stod(arg2));
                    } catch (std::invalid_argument const& ex) {
                        std::cerr << arg << " value must be a number" << std::endl;
                        exit(1);
                    }
                } else if (arg == "-L" || arg == "--line_width") {
                    try {
                        settings.settings2D.lineWidth.set(std::stod(arg2));
                    } catch (std::invalid_argument const& ex) {
                        std::cerr << arg << " value must be a number" << std::endl;
                        exit(1);
                    }
                } else if (arg == "-B" || arg == "--background") {
                    settings.settings2D.background.set(arg2);
                } else if (arg == "-C" || arg == "--line-color") {
                    settings.settings2D.lineColor.set(arg2);
                } else if (arg == "-F" || arg == "--fill-color") {
                    settings.settings2D.fillColor.set(arg2);
                }
            } else if (argNamesOpt.find(arg) != argNamesOpt.end()) {
                std::string arg2;
                if (argc > i+1) {
                    arg2 = argv[++i];
                }
                if (arg == "--svg") {
                    if (settings.renderMode.isset()) {
                        std::cerr << "Render mode argument repeated" << std::endl;
                        exit(1);
                    }
                    settings.renderMode.set(lsysgen::Settings::RenderMode::SVG);
                    if (arg2.size() > 0)
                        settings.outputRenderFile = arg2;
                }
            } else if (argNamesN.find(arg) != argNamesN.end()) {
                // if (settings.args.isset()) {
                //     std::cerr << arg << " argument repeated" << std::endl;
                //     exit(1);
                // }
                if (arg == "-A" || arg == "--args") {
                    settings.args.set();
                }
                auto & args = settings.args.get();
                for (++i; i < argc; ++i) {
                    std::string arg2 = argv[i];
                    if (arg2.size() > 0 && arg2[0] == '-') {
                        break;
                    } else {
                        if (arg == "-A" || arg == "--args") {
                            std::smatch m;
                            if (std::regex_match(arg2, m, argRegex)) {
                                if (args.find(m[1]) != args.end()) {
                                    std::cerr << "Lsystem argument '" << m[1] <<"' repeated" << std::endl;
                                    exit(1);
                                }
                                args[m[1]] = m[2];
                            } else {
                                std::cerr << arg << " arguments must be pairs NAME:VALUE" << std::endl;
                                exit(1);
                            }
                        }
                    }
                }
            } else {
                std::cerr << "Unknown argument '" << arg << "'" << std::endl;
                exit(1);
            }
        }
    }

    // return settings;
}


void printUsage() {
    std::cerr << "Usage:" << std::endl;
    std::cerr << "       lsys INPUT_FILE [OUTPUT_FILE] [OPTIONS]" << std::endl;
    std::cerr << "       lsys -a AXIOM [OPTIONS]" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Run lsys --help for more information" << std::endl;
    exit(1);
}

void printHelp() {
    std::cout << "lsys " << LSYSGEN_VERSION << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "       lsys INPUT_FILE [OUTPUT_FILE] [OPTIONS]" << std::endl;
    std::cout << "       lsys -a AXIOM [OPTIONS]" << std::endl;
    std::cout << std::endl;
    std::cout << "lsys is a L System generator and interpreter. The program is also a compiler of a purpose specific language \
LSD (L System Descriptor), that defines one or more L Systems with an easy and compact syntax. You can just print the results of \
the L System but you can also create a SVG image from it (see --svg option). Enjoy creating plants and fractals with this tool!\
" << std::endl;
    std::cout << "An L system or Lindenmayer system is a parallel rewriting system and a type of formal grammar. An L-system \
consists of an alphabet of symbols that can be used to make strings, a collection of production rules that expand each symbol \
into some larger string of symbols, an initial \"axiom\" string from which to begin construction, and a mechanism for \
translating the generated strings into geometric structures." << std::endl;
    std::cout << "L-systems were introduced and developed in 1968 by Aristid Lindenmayer, a Hungarian theoretical biologist and \
botanist at the University of Utrecht. Lindenmayer used L-systems to describe the behaviour of plant cells and to model the \
growth processes of plant development. L-systems have also been used to model the morphology of a variety of organisms and \
can be used to generate self-similar fractals." << std::endl;
    std::cout << "To create an L System an axiom and a set of rules are needed (you can build an L System with just an axiom too, \
although it wouldn't change over iterations). An axiom is a string of characters such as letters, numbers and some symbols, e.g. \
\"A\", \"F++F++F\", etc. A rule has generally the shape \"left -> right\", where 'left' is the character the rule will select to \
be replaced by the 'right' string, e.g. \"A -> AB\", \"B->A\", etc." << std::endl;
    std::cout << std::endl;

    std::cout << "Examples:" << std::endl;
    std::cout << "  $ lsys -a \"A\" -r \"A->AB; B->A\" -i 5" << std::endl;
    std::cout << "  $ lsys examples/PenroseTiling.lsd --svg PenroseTiling4Red.svg -i 4 -C \"#f00\"" << std::endl;
    std::cout << "  $ lsys examples/DragonCurve.lsd --svg RareCurve1.svg -R 60 -L 1" << std::endl;
    
    std::cout << std::endl;

    std::cout << "Arguments:" << std::endl;
    std::cout << "     INPUT_FILE: the program will read the contents of this .lsd file and will build the L System from it. With \
-X option, this file will be expected to only contain a word that will act as an axiom. If set to - the program will read \
from the standard input. Either -a or INPUT_FILE are required." << std::endl;
    std::cout << "     OUTPUT_FILE: this file is optional and will be used to write the result of the L System derivations (a \
word, even if --svg option is set)." << std::endl;
    std::cout << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "     --help: to show this message." << std::endl;
    std::cout << "     -a AXIOM, --axiom AXIOM: sets or overrides the axiom of the L-System. With this option, INPUT_FILE is \
optional, as the axiom is the most basic L System, though rules can be added with -r and -i for the number of iterations." << std::endl;
    std::cout << "     -r RULES, --r RULES: sets or adds rules to the L System. RULES can be one or more rules separated with \
a semicolon (;), but it must be always quoted since it uses > and/or < characters that will conflict with the shell syntax \
when unquoted." << std::endl;
    std::cout << "     -i N, --iterations N: sets or overrides the number of iterations that the L System will be applying the \
rules. Defaults to 0." << std::endl;
    std::cout << "     -I CHARS, --ignore CHARS: sets or overrides the characters the L System will ignore when looking for left \
and right context of a character when checking a rule. Too many iterations may take too much time. Defaults to empty." << std::endl;
    std::cout << "     -S N, --seed N: sets or overrides a seed for a non-deterministic L System. When two or more rules can be \
applied to the same character, some randomness is introduced. Setting a seed (> 0) will produce some \"random\" result, but \
it will always produce the same result if executed with the same seed. Default is -1 (chooses a random seed)." << std::endl;
    std::cout << "     -A ARG:VALUE ..., --args ARG:VALUE ...: sets arguments for the L System [NOT IMPLEMENTED]." << std::endl;
    std::cout << std::endl;

    std::cout << "     -X, --axiom-input: when this option is set, the program will read the input file as an axiom rather than as \
a LSD file." << std::endl;
    std::cout << std::endl;
    std::cout << "     --svg [SVG_OUTPUT_FILE]: this option activates SVG image creation after iterating the L System. The program \
interprets the result of the iterations to build a SVG file and printing it to the standard output, or optionally in the file \
SVG_OUTPUT_FILE. The procedure of the creation of the image is: a \"turtle\" head with a pen is looking to the left (by default) \
and the characters the result string has (some of them) will move or change the state of the turtle, e.g. F moves forward while \
drawing a line, f moves forward without drawing, + will turn the turtle to its left and - to its right." << std::endl;
    std::cout << std::endl;
    std::cout << "Options for SVG output:" << std::endl;
    std::cout << "     -H DEGREES, --initial-heading DEGREES: sets or overrides the initial heading of the turtle." << std::endl;
    std::cout << "     -R DEGREES, --rotation DEGREES: sets or overrides the angle that + and - rotate the turtle. (+ and - can \
be parametrized to rotate a custom angle)" << std::endl;
    std::cout << "     -L NUMBER, --line-width NUMBER: sets or overrides the width of the lines drawn by the turtle." << std::endl;
    std::cout << "     -B COLOR, --background COLOR: sets or overrides the background color of the image." << std::endl;
    std::cout << "     -C COLOR, --line-color COLOR: sets or overrides the color of the line drawn by the turtle." << std::endl;
    std::cout << "     -F COLOR, --fill-color COLOR: sets or overrides the fill color when filling a shape with P and p." << std::endl;
    std::cout << "     -l NAME, --lsystem NAME: this option chooses the L System that will be executed, as LSD files may \
contain multiple L Systems. If no one is found declared with that name, an error will occur." << std::endl;

    exit(0);
}

