
#include "cli.h"


#include "lsysgen.h"
#include "interpreter2D.h"
#include "Settings.h"
#include "cliargs.h"
#include "misc.h"

#include <filesystem>
#include <csignal>

static std::map<int, std::string> signames {
    {SIGTERM, "SIGTERM"},
    {SIGSEGV, "SIGSEGV"},
    {SIGINT, "SIGINT"},
    {SIGILL, "SIGILL"},
    {SIGABRT, "SIGABRT"},
    {SIGFPE, "SIGFPE"}
};

#ifndef NDEBUG
#ifdef __linux__
#include <execinfo.h>
void handler(int sig) {
    size_t const max_size = 64;
    void * array[max_size];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, max_size);

    // print out all the frames to stderr
    fprintf(stderr, "Signal %d (%s):\n", sig, signames[sig].c_str());
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}
#endif
#endif

void handle_signals() {
    #ifndef NDEBUG
    #ifdef __linux__
    signal(SIGTERM, handler);
    signal(SIGSEGV, handler);
    signal(SIGINT, handler);
    signal(SIGILL, handler);
    signal(SIGABRT, handler);
    signal(SIGFPE, handler);
    #endif
    #endif
}


int main(int argc, char** argv) {
    handle_signals();

    Settings settings;

    parseCLIArgs(argc, argv, settings);

    std::map<std::string, std::filesystem::path> outputPaths;

    if (!settings.outputs.isset())
        settings.outputs.getRef()[Settings::DEFAULT_OUTPUT_FORMAT] = "-";

    for (auto const& [format, output] : settings.outputs.getRef()) {
        if (output.size() > 0)
            outputPaths[format] = output;
        else
            outputPaths[format] = "-";
        // else if (lsystems->size() > 1)
        //     outputPaths[format] = std::filesystem::current_path();
    }

    if (settings.inputFiles.get().size() > 1 || (settings.lsystems.isset() && settings.lsystems.get().size() != 1)) {
        for (auto const& [format, outputPath] : outputPaths) {
            if (outputPath != "-" && !std::filesystem::is_directory(outputPath)) {
                std::cerr << "When more than one L System or input file is selected, output destinations must be directories." << std::endl;
                exit(1);
            }
        }
    }

    std::list<lsysgen::LSystem<char> *> * lsystems = createLSystems(settings);

    if (lsystems == nullptr)
        return 1;

    if (lsystems->size() == 0)
        return 1;

    if (settings.seed.isset()) {
        if (settings.seed.get() >= 0)
            std::cerr << "USING SEED " << std::to_string(lsystems->front()->seed()) << std::endl;
        else
            std::cerr << "USING RANDOM SEED" << std::endl;
    }

    for (lsysgen::LSystem<char> * lsystem : *lsystems) {

        if (lsystem == nullptr)
            continue;

        lsystem->iterate();

        if (lsystem->messages()->failed()) {
            lsystem->messages()->dump();
            return 1;
        }

        for (auto const& [format, outputPath] : outputPaths) {
            std::filesystem::path outputFile = outputPath;
            if (std::filesystem::is_directory(outputFile)) {
                if (format == "raw")
                    outputFile /= lsystem->name() + ".txt";
                else // if (format == "svg")
                    outputFile /= lsystem->name() + ".svg";
            }
            bool written;
            if (format == "raw")
                written = writeToFile(outputFile.string(), lsystem->current()->toString());
            else // if (format == "svg")
                written = writeToFile(outputFile.string(), node2svg(lsystem->current(), lsystem));
            if (!written) {
                std::cerr << "File " << outputFile << " is not writable." << std::endl;
                exit(1);
            }
        }

    }

    return 0;
}

