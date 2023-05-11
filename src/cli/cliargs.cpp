
#include "cliargs.h"


#include <set>
#include <list>
#include <regex>



std::set<std::string> const argNames0 = {
    "--help", "--version", "-X", "--axiom-input", "--all"
};
std::set<std::string> const argNamesOpt = {
    "-S", "--seed"
};
std::set<std::string> const argNames1 = {
    "-a", "--axiom", "-r", "--rules", "-i", "--iterations", "-I", 
    "--ignore", "-H", "--heading", //"-p", "--plugin", 
    "-R", "--rotation", "-W", "--line-width", "-B", "--background", 
    "-C", "--line-color", "-F", "--fill-color", 
    "-w", "--width", "-h", "--height"
};
std::set<std::string> const argNamesN = {
    "-o", "--output", "-l", "--lsystems", //"-A", "--args"
};
std::set<std::string> const outputFormats = {
    "raw", "svg"
};
std::regex const argRegex ("([A-Za-z_][A-Za-z_0-9]*):(.+)");



void argumentError(std::string_view message, bool printUsageAfterMessage=false) {
    std::cerr << "Argument error: " << message << std::endl;
    if (printUsageAfterMessage)
        printUsage();
    exit(1);
}

template<typename N>
bool betweenInclusive(N n, N min, N max) {return n >= min && n <= max;}

// Excludes options starting with -, but includes "-" and negative numbers
bool isValue(char * arg) {
    return arg[0] != '-' || arg[1] == '\0' || betweenInclusive(arg[1], '0', '9');
}

bool isOption(char * arg) {return !isValue(arg);}


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

        if (isValue(argv[i])) {
            // Found a value (positional argument)
            settings.inputFiles.getRef().push_back(arg);
            ++positionalArgs;
        } else {
            // Found the first option name
            break;
        }
    }

    // Reads options afterwards
    for (int i = positionalArgs + 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.size() == 0)
            continue;

        if (argNames0.find(arg) != argNames0.end()) {
            // Options with no arguments
            if (arg == "-X" || arg == "--axiom-input") {
                if (settings.inputMode.isset())
                    argumentError("input mode argument repeated");
                settings.inputMode.set(lsysgen::Settings::InputMode::AXIOM);
            } else if (arg == "--all") {
                if (settings.lsystems.isset())
                    argumentError("lsystems argument repeated (" + arg + ")");
                settings.lsystems.set(); // empty
            } else if (arg == "--help") {
                printHelp();
                exit(0);
            } else if (arg == "--version") {
                printVersion();
                exit(0);
            }
        } else if (argNamesOpt.find(arg) != argNamesOpt.end()) {
            // Options with 0 or 1 argument
            std::string arg2;
            if (argc > i+1) {
                // Excludes options starting with - (except numbers), but includes "-"
                if (isValue(argv[i+1]))
                    arg2 = argv[++i];
            }
            if (arg == "-S" || arg == "--seed") {
                if (settings.seed.isset())
                    argumentError("seed argument repeated");
                if (arg2.size() > 0) {
                    settings.seed.set(strict_stoi(arg, arg2));
                } else {
                    settings.seed.set();
                }
            }
        } else if (argNames1.find(arg) != argNames1.end()) {
            // Options with 1 argument
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
            } else if (arg == "-I" || arg == "--ignore") {
                if (settings.ignore.isset())
                    argumentError("ignore argument repeated");
                settings.ignore.set(arg2);
            // } else if (arg == "-p" || arg == "--plugin") {
                /* TODO: import module/plugin shared library (arg + ".so/dll/dylib")
                 * call a initializer (or allocator + deleter) function in the library (dlopen, dlsym, dlclose, dlerror in <dlfcn.h>)
                 * Create C structs or c++ interfaces for exchanging information with that function (plugin.h)
                 * Also create extern "C" functions to retrieve data from TreeNodes and LSystems (plugin.h)
                 * initializer(char *opts, int *minArgs, int *maxArgs, void *formatNames, void *formatExts, void *formatFuncs) 
                 * will return supported options (-?/--??, with argument numbers), format names with 
                 * their functions and file extensions, etc.
                 * see https://theo-penavaire.medium.com/loading-of-a-c-class-from-a-shared-library-modern-c-722d6a830a2b
                 */
            } else if (arg == "-H" || arg == "--heading") {
                if (settings.settings2D.heading.isset())
                    argumentError("heading argument repeated");
                settings.settings2D.heading.set(strict_stof(arg, arg2));
            } else if (arg == "-R" || arg == "--rotation") {
                if (settings.settings2D.rotation.isset())
                    argumentError("rotation argument repeated");
                settings.settings2D.rotation.set(strict_stof(arg, arg2));
            } else if (arg == "-W" || arg == "--line_width") {
                if (settings.settings2D.lineWidth.isset())
                    argumentError("line width argument repeated");
                settings.settings2D.lineWidth.set(strict_stof(arg, arg2));
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
                settings.settings2D.width.set(strict_stof(arg, arg2));
            } else if (arg == "-h" || arg == "--height") {
                if (settings.settings2D.height.isset())
                    argumentError("height argument repeated");
                settings.settings2D.height.set(strict_stof(arg, arg2));
            }
        } else if (argNamesN.find(arg) != argNamesN.end()) {
            // Options with any number of arguments
            std::vector<char*> values;
            values.reserve(5);
            for (++i; i < argc; ++i) {
                if (isValue(argv[i])) {
                    // Found a value
                    values.push_back(argv[i]);
                } else {
                    // Found an option name. Stop here
                    --i;
                    break;
                }
            }
            if (arg == "-o" || arg == "--output") {
                if (values.size() == 0)
                    argumentError(arg + " must be followed at least by a format (raw or svg)");
                if (values.size() > 2)
                    argumentError("Too many arguments for " + arg);
                std::string format, dest;
                if (values.size() == 2) {
                    format = values[0]; // toLowerCase()
                    dest = values[1];
                } else {
                    if (values.size() == 1) {
                        format = values[0];
                    }
                }
                if (outputFormats.find(format) == outputFormats.end())
                    argumentError(format + " is not a supported format (must be raw or svg)");
                auto & outputs = settings.outputs.getRef();
                if (std::any_of(outputs.cbegin(), outputs.cend(), [format](auto const& p){return format==p.first;}))
                    argumentError(format + " output format argument repeated");
                if (dest.size() > 0)
                    outputs.push_back(std::make_pair(format, dest));
                else
                    outputs.push_back(std::make_pair(format, "-"));
            } else if (arg == "-l" || arg == "--lsystems") {
                if (settings.lsystems.isset())
                    argumentError("lsystems argument repeated (" + arg + ")");
                if (values.size() == 0)
                    argumentError(arg + " must be followed by one or more L System names");
                for (char const* arg2 : values)
                    settings.lsystems.getRef().push_back(arg2);
            } else if (arg == "-A" || arg == "--args") {
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
            if (argv[i][0] != '-' || argv[i][1] == '\0' || betweenInclusive(argv[i][1], '0', '9'))
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
    } catch ([[maybe_unused]] std::invalid_argument const& ex) {}
    argumentError(arg + " value must be an integer");
    return 0;
}

float strict_stof(std::string const& arg, std::string const& s) {
    try {
        size_t pos;
        float f = std::stof(s, &pos);
        if (pos == s.size())
            return f;
    } catch ([[maybe_unused]] std::invalid_argument const& ex) {}
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

void printVersion() {
    std::cout << "lsys " << LSYSGEN_VERSION << std::endl;
}

void printHelp() {
    // printVersion();
    std::cout << "lsys " << LSYSGEN_VERSION << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "       lsys INPUT_FILE... [OUTPUT_FILE] [OPTIONS]" << std::endl;
    std::cout << "       lsys -a AXIOM [OPTIONS]" << std::endl;
    std::cout << std::endl;
    std::cout << "This project implements in C++ an L System generator and renderer and a LSDL (L System Defining Language) \
interpreter. LSDL is a custom specific purpose language that has been created ad-hoc for this project as a way of describing L \
Systems to the generator. The program reads LSDL *.lsd files, that define one or more L Systems with an easy and compact \
syntax. You can not only print the results of the L System but also create a SVG image from it (see -o formats).\
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
    std::cout << "  $ lsys examples/PenroseTiling.lsd --output svg PenroseTiling4Red.svg -i 4 -C \"#f00\"" << std::endl;
    std::cout << "  $ lsys examples/DragonCurve.lsd -o svg RareCurve1.svg -R 60 -L 1" << std::endl;
    
    std::cout << std::endl;

    std::cout << "Arguments:" << std::endl;
    std::cout << "     INPUT_FILE: the program will read the contents of this .lsd file and will build its main L System (if \
there is more than one L System defined in the file, the one marked with main is selected, unless another(s) are selected with \
-l). There can be multiple input files. If -X option is set, this file will be expected to only contain a word that will act \
as an axiom. If INPUT_FILE is set to \"-\" then the program will read from the standard input. Either -a or INPUT_FILE are \
required." << std::endl;
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
    std::cout << "     -l NAME ..., --lsystems NAME ...: this option selects the L System(s) in the source file that will be \
executed (in source files with multiple L Systems). If one of the NAMEs is not found declared with that name, an error will \
occur." << std::endl;
    std::cout << "     --all: this option selects all the L Systems in the source file." << std::endl;
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
    std::cout << "     -o FORMAT [DEST], --output FORMAT [DEST]: the output format/backend FORMAT will be used as an output that \
will be generated in DEST if set, or in the standard output otherwise (or if set to '-'). If DEST is set to a directory, \
a FILE.EXT file will be created inside that directory for each selected L System, where FILE will be the name of the L System \
and EXT will vary depending on the selected format. More than one format may be specified for several output formats. If this \
option is not set then the result string will be printed to the standard output." << std::endl;
    std::cout << std::endl;
    std::cout << "Currently supported output formats:" << std::endl;
    std::cout << "     * raw: this format creates a plain TXT file after the raw L System result. The program just prints the result \
of the iterated L System." << std::endl;
    std::cout << "     * svg: this format creates an SVG image after the L System result. The program interprets the result of the \
iterated L System to build a SVG image. The procedure of the creation of the image is: a \"turtle\" head with a pen is heading left \
(by default) and the result string symbols (only the special characters) will draw lines, move or change the state of the turtle, \
e.g. F moves forward while drawing a line, f moves forward without drawing, + will turn the turtle to its left and - to its right." << std::endl;
    std::cout << std::endl;
    std::cout << "Options for SVG output format:" << std::endl;
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

