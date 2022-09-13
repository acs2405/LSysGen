
#include "cli.h"


#include <filesystem>



int main(int argc, char** argv) {

    Settings settings;

    parseCLIArgs(argc, argv, settings);

    lsysgen::LSystem<char>* lsystem = lsystem_create(settings);

    if (lsystem == nullptr)
        return 1;

    lsystem->iterate();

    if (lsystem->messages()->failed()) {
        lsystem->messages()->dump();
        return 1;
    }

    if (settings.outputResultFile.isset()) {
        std::filesystem::path outputResultFile = settings.outputResultFile.get();
        if (std::filesystem::is_directory(outputResultFile))
            outputResultFile /= lsystem->name() + ".txt";
        if (!writeToFile(outputResultFile.c_str(), lsystem->current()->toString())) {
            std::cerr << "File " << outputResultFile << " is not writable." << std::endl;
            exit(1);
        }
    }
    if (settings.renderMode.get() == Settings::RenderMode::NONE) {
        if (!settings.outputResultFile.isset())
            std::cout << lsystem->current()->toString() << std::endl;
    } else if (settings.renderMode.get() == Settings::RenderMode::SVG) {
        if (settings.outputRenderFile.isset()) {
            std::filesystem::path outputRenderFile = settings.outputRenderFile.get();
            if (std::filesystem::is_directory(outputRenderFile))
                outputRenderFile /= lsystem->name() + ".svg";
            if (!writeToFile(outputRenderFile.c_str(), node2svg(lsystem->current(), lsystem))) {
                std::cerr << "File " << outputRenderFile << " is not writable." << std::endl;
                exit(1);
            }
        } else {
            std::cout << node2svg(lsystem->current(), lsystem) << std::endl;
        }
    }

    return 0;
}

