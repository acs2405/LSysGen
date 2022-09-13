
#include "cliargs.h"


#include <set>
#include <list>

#define LSYSGEN_VERSION "0.6"



std::set<std::string> const argNames0 = {
    "--help", "-X", "--axiom-input"
};
std::set<std::string> const argNamesOpt = {
    "--svg", "-S", "--seed"
};
std::set<std::string> const argNames1 = {
    "-a", "--axiom", "-r", "--rules", "-i", "--iterations", "-I", 
    "--ignore", "-H", "--heading", 
    "-R", "--rotation", "-W", "--line-width", "-B", "--background", 
    "-C", "--line-color", "-F", "--fill-color", "-l", "--lsystem", 
    "-w", "--width", "-h", "--height"
};
std::set<std::string> const argNamesN = {
    "-A", "--args"
};
std::regex const argRegex ("([A-Za-z_][A-Za-z_0-9]*):(.+)");



void argumentError(std::string_view message, bool printUsageAfterMessage=false) {
    std::cerr << "Argument error: " << message << std::endl;
    if (printUsageAfterMessage)
        printUsage();
    exit(1);
}


void parseCLIArgs(int argc, char** argv, lsysgen::Settings & settings) {
    if (argc < 2) {
        printUsage();
        exit(1);
    }

    // lsysgen::Settings * settings = new lsysgen::Settings();
    int positionalArgs = 0;

    // Reads Positional arguments first
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.size() == 0)
            continue;

        if (argv[i][0] != '-' || argv[i][1] == '\0') {
            if (positionalArgs == 0) {
                // Found first positional argument
                settings.inputFile.set(arg);
            } else if (positionalArgs == 1) {
                // Found second positional argument
                settings.outputResultFile.set(arg);
            } else {
                // Found third positional argument (not expected)
                argumentError("Error: too many positional arguments", true);
            }
            ++positionalArgs;
        } else {
            // Found a keyword argument
            break;
        }
    }

    // Reads keyword arguments afterwards
    for (int i = positionalArgs + 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.size() == 0)
            continue;

        if (argNames0.find(arg) != argNames0.end()) {
            if (arg == "-X" || arg == "--axiom-input") {
                if (settings.inputMode.isset())
                    argumentError("input mode argument repeated");
                settings.inputMode.set(lsysgen::Settings::InputMode::AXIOM);
            } else if (arg == "--help") {
                printHelp();
                exit(0);
            }
        } else if (argNamesOpt.find(arg) != argNamesOpt.end()) {
            std::string arg2;
            if (argc > i+1) {
                // Excludes options starting with -, but includes "-"
                if (argv[i+1][0] != '-' || argv[i+1][1] == '\0')
                    arg2 = argv[++i];
            }
            if (arg == "--svg") {
                if (settings.renderMode.isset()) {
                    argumentError("render mode argument repeated");
                }
                settings.renderMode.set(lsysgen::Settings::RenderMode::SVG);
                if (arg2.size() > 0)
                    settings.outputRenderFile = arg2;
            } else if (arg == "-S" || arg == "--seed") {
                if (settings.seed.isset())
                    argumentError("seed argument repeated");
                if (arg2.size() > 0) {
                    settings.seed.set(strict_stoi(arg, arg2));
                } else {
                    settings.seed.set();
                }
            }
        } else if (argNames1.find(arg) != argNames1.end()) {
            if (argc == i+1)
                argumentError(arg + " must be followed by a value");
            std::string arg2 = argv[++i];
            if (arg == "-a" || arg == "--axiom") {
                if (settings.axiom.isset())
                    argumentError("axiom argument repeated");
                settings.axiom.set(arg2);
            } else if (arg == "-r" || arg == "--rules") {
                if (settings.rules.isset())
                    settings.rules.set(settings.rules.get() + "\n" + arg2);
                else
                    settings.rules.set(arg2);
            } else if (arg == "-i" || arg == "--iterations") {
                if (settings.iterations.isset())
                    argumentError("iterations argument repeated");
                settings.iterations.set(strict_stoi(arg, arg2));
            } else if (arg == "-l" || arg == "--lsystem") {
                if (settings.lsystem.isset())
                    argumentError("lsystem argument repeated");
                settings.lsystem.set(arg2);
            } else if (arg == "-I" || arg == "--ignore") {
                if (settings.ignore.isset())
                    argumentError("ignore argument repeated");
                settings.ignore.set(arg2);
            } else if (arg == "-H" || arg == "--heading") {
                if (settings.settings2D.heading.isset())
                    argumentError("heading argument repeated");
                settings.settings2D.heading.set(strict_stod(arg, arg2));
            } else if (arg == "-R" || arg == "--rotation") {
                if (settings.settings2D.rotation.isset())
                    argumentError("rotation argument repeated");
                settings.settings2D.rotation.set(strict_stod(arg, arg2));
            } else if (arg == "-W" || arg == "--line_width") {
                if (settings.settings2D.lineWidth.isset())
                    argumentError("line width argument repeated");
                settings.settings2D.lineWidth.set(strict_stod(arg, arg2));
            } else if (arg == "-C" || arg == "--line-color") {
                if (settings.settings2D.lineColor.isset())
                    argumentError("line color argument repeated");
                settings.settings2D.lineColor.set(arg2);
            } else if (arg == "-F" || arg == "--fill-color") {
                if (settings.settings2D.fillColor.isset())
                    argumentError("fill color argument repeated");
                settings.settings2D.fillColor.set(arg2);
            } else if (arg == "-B" || arg == "--background") {
                if (settings.settings2D.background.isset())
                    argumentError("background argument repeated");
                settings.settings2D.background.set(arg2);
            } else if (arg == "-w" || arg == "--width") {
                if (settings.settings2D.width.isset())
                    argumentError("width argument repeated");
                settings.settings2D.width.set(strict_stod(arg, arg2));
            } else if (arg == "-h" || arg == "--height") {
                if (settings.settings2D.height.isset())
                    argumentError("height argument repeated");
                settings.settings2D.height.set(strict_stod(arg, arg2));
            }
        } else if (argNamesN.find(arg) != argNamesN.end()) {
            std::list<char*> values;
            for (++i; i < argc; ++i) {
                // Excludes options starting with -, but includes "-"
                if (argv[i][0] != '-' || argv[i][1] == '\0') {
                    values.push_back(argv[i]);
                } else {
                    // Found an option name. Stop here
                    --i;
                    break;
                }
            }
            if (arg == "-A" || arg == "--args") {
                if (settings.args.isset())
                    argumentError("arguments argument repeated");
                auto & args = settings.args.getRef();
                for (char const* arg2 : values) {
                    std::cmatch m;
                    if (std::regex_match(arg2, m, argRegex)) {
                        if (args.find(m[1]) != args.end())
                            argumentError("lsystem argument \"" + m[1].str() + "\" repeated");
                        args[m[1]] = m[2];
                    } else {
                        argumentError(arg + " arguments must be pairs NAME:VALUE");
                    }
                }
            }
        } else {
            if (argv[i][0] != '-' || argv[i][1] == '\0')
                argumentError("unexpected argument \"" + arg + "\"");
            else
                argumentError("unknown option " + arg);
        }
    }

    // for (auto [name, value] : settings.args.get())
    //     std::cout << name << ": " << value << std::endl;

    // if (svgOptionsSet && settings.renderMode.get() != lsysgen::Settings::RenderMode::SVG)
    //     argumentError("--svg option is required for " + arg + " option");

    // return settings;
}


int strict_stoi(std::string const& arg, std::string const& s, int base) {
    try {
        size_t pos;
        int i = std::stoi(s, &pos, base);
        if (pos == s.size())
            return i;
    } catch (std::invalid_argument const& ex) {}
    argumentError(arg + " value must be an integer");
    return 0;
}

double strict_stod(std::string const& arg, std::string const& s) {
    try {
        size_t pos;
        double d = std::stod(s, &pos);
        if (pos == s.size())
            return d;
    } catch (std::invalid_argument const& ex) {}
    argumentError(arg + " value must be a number");
    return 0.0;
}

void printUsage() {
    std::cerr << "Usage:" << std::endl;
    std::cerr << "       lsys INPUT_FILE [OUTPUT_FILE] [OPTIONS]" << std::endl;
    std::cerr << "       lsys -a AXIOM [OPTIONS]" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Run lsys --help for more information" << std::endl;
}

void printHelp() {
    std::cout << "lsys " << LSYSGEN_VERSION << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "       lsys INPUT_FILE [OUTPUT_FILE] [OPTIONS]" << std::endl;
    std::cout << "       lsys -a AXIOM [OPTIONS]" << std::endl;
    std::cout << std::endl;
    std::cout << "This project implements in C++ an L System generator and renderer and a LSDL (L System Defining Language) \
interpreter. LSDL is a custom specific purpose language that has been created ad-hoc for this project as a way of describing L \
Systems to the generator. The program reads LSDL *.lsd files, that define one or more L Systems with an easy and compact \
syntax. You can not only print the results of the L System but also create a SVG image from it (see --svg).\
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
    std::cout << "     INPUT_FILE: the program will read the contents of this .lsd file and will build its main L System (if \
there is more than one L System defined in the file, the one marked with main is selected). If -X option is set, this file will \
be expected to only contain a word that will act as an axiom. If INPUT_FILE is set to \"-\" then the program will read from the \
standard input. Either -a or INPUT_FILE are required." << std::endl;
    std::cout << "     OUTPUT_FILE: this file is optional and will be used to write the result word of the L System derivations \
(even if --svg option is set). If OUTPUT_FILE is set to \"-\" then the result will be printed to the standard output. When \
neither OUTPUT_FILE nor --svg are set then the result will be printed to the standard output." << std::endl;
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
    std::cout << "     -l NAME, --lsystem NAME: this option selects the L System that will be executed (INPUT_FILE required), as \
LSD files may contain multiple L Systems. If no one is found declared with that name, an error will occur." << std::endl;
    std::cout << "     -I CHARS, --ignore CHARS: sets or overrides the characters the L System will ignore when looking for left \
and right context of a character when checking a rule. Too many iterations may take too much time. Defaults to empty." << std::endl;
    std::cout << "     -S [N], --seed [N]: sets or overrides a seed for a non-deterministic L System. If N is present, N will be \
used as seed, otherwise, a random seed will be used (based in the system's current milliseconds). If this option is present, the \
chosen seed will be printed to the standard error. When two or more rules can be applied to the same character, some randomness is \
introduced. Setting a seed (> 0) will produce some seemingly \"random\" result, but it will always produce the same result when \
executed with the same seed. Default value is -1 (chooses a random seed)." << std::endl;
    std::cout << "     -A ARG:VALUE ..., --args ARG:VALUE ...: sets arguments for the L System." << std::endl;
    std::cout << std::endl;

    std::cout << "     -X, --axiom-input: when this option is set, the program will read the input file as an axiom rather than as \
a LSD file." << std::endl;
    std::cout << std::endl;
    std::cout << "     --svg [SVG_OUTPUT_FILE]: this option activates SVG image creation after iterating the L System. The program \
interprets the result of the iterations to build a SVG file and printing it to the standard output, or optionally in the file \
SVG_OUTPUT_FILE. The procedure of the creation of the image is: a \"turtle\" head with a pen is heading left (by default) and the \
result string symbols (only the special characters) will draw lines, move or change the state of the turtle, e.g. F moves forward \
while drawing a line, f moves forward without drawing, + will turn the turtle to its left and - to its right." << std::endl;
    std::cout << std::endl;
    std::cout << "Options for SVG output:" << std::endl;
    std::cout << "     -H DEGREES, --heading DEGREES: sets or overrides the initial heading of the turtle." << std::endl;
    std::cout << "     -R DEGREES, --rotation DEGREES: sets or overrides the angle that + and - rotate the turtle. (+ and - can \
be parametrized to rotate a custom angle)" << std::endl;
    std::cout << "     -W NUMBER, --line-width NUMBER: sets or overrides the width of the lines drawn by the turtle." << std::endl;
    std::cout << "     -C COLOR, --line-color COLOR: sets or overrides the color of the line drawn by the turtle." << std::endl;
    std::cout << "     -F COLOR, --fill-color COLOR: sets or overrides the fill color when filling a shape between P and p characters." << std::endl;
    std::cout << "     -B COLOR, --background COLOR: sets or overrides the background color of the image." << std::endl;
    std::cout << "     -w NUMBER, --width NUMBER: sets the width of the SVG element." << std::endl;
    std::cout << "     -h NUMBER, --height NUMBER: sets the height of the SVG element." << std::endl;
}

