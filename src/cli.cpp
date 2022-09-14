
#include "cli.h"


#include <filesystem>



int main(int argc, char** argv) {

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

    if (settings.inputFiles.get().size() > 1 || settings.lsystems.isset() && settings.lsystems.get().size() != 1) {
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
            if (!writeToFile(outputResultFile.c_str(), lsystem->current()->toString())) {
                std::cerr << "File " << outputResultFile << " is not writable." << std::endl;
                exit(1);
            }
        }

        if (settings.renderMode.get() == Settings::RenderMode::SVG) {
            std::filesystem::path outputRenderFile = outputRenderPath;
            if (std::filesystem::is_directory(outputRenderFile))
                outputRenderFile /= lsystem->name() + ".svg";
            if (!writeToFile(outputRenderFile.c_str(), node2svg(lsystem->current(), lsystem))) {
                std::cerr << "File " << outputRenderFile << " is not writable." << std::endl;
                exit(1);
            }
        }

    }

    return 0;
}

