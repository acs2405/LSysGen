
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

    std::filesystem::path outputResultPath;
    if (settings.outputResultFile.isset())
        outputResultPath = settings.outputResultFile.get();
    else if (settings.renderMode.get() == Settings::RenderMode::NONE)
        outputResultPath = "-";
    // else if (lsystems->size() > 1)
    //     outputResultPath = std::filesystem::current_path();

    std::filesystem::path outputRenderPath;
    if (settings.outputRenderFile.isset())
        outputRenderPath = settings.outputRenderFile.get();
    else // if (lsystems->size() == 1) // && outputResultPath.string() != "-")
        outputRenderPath = "-";
    // else if (lsystems->size() > 1)
    //     outputRenderPath = std::filesystem::current_path();

    if (settings.inputFiles.get().size() > 1 || (settings.lsystems.isset() && settings.lsystems.get().size() != 1)) {
        if ((settings.outputResultFile.isset() && 
                !std::filesystem::is_directory(outputResultPath) && 
                outputResultPath != "-") || 
                (settings.outputRenderFile.isset() && 
                !std::filesystem::is_directory(outputRenderPath) && 
                outputRenderPath != "-")) {
            std::cerr << "When more than one L System or input file is selected, output must be a directory." << std::endl;
            exit(1);
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

        if (outputResultPath != "") {
            std::filesystem::path outputResultFile = outputResultPath;
            if (std::filesystem::is_directory(outputResultFile))
                outputResultFile /= lsystem->name() + ".txt";
            if (!writeToFile(outputResultFile.string(), lsystem->current()->toString())) {
                std::cerr << "File " << outputResultFile << " is not writable." << std::endl;
                exit(1);
            }
        }

        if (settings.renderMode.get() == Settings::RenderMode::SVG) {
            std::filesystem::path outputRenderFile = outputRenderPath;
            if (std::filesystem::is_directory(outputRenderFile))
                outputRenderFile /= lsystem->name() + ".svg";
            if (!writeToFile(outputRenderFile.string(), node2svg(lsystem->current(), lsystem))) {
                std::cerr << "File " << outputRenderFile << " is not writable." << std::endl;
                exit(1);
            }
        }

    }

    return 0;
}

