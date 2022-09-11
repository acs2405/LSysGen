
#include "cli.h"



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
        if (!writeToFile(settings.outputResultFile.get(), lsystem->current()->toString())) {
            std::cerr << "File '" << settings.outputResultFile.get() << "' is not writable." << std::endl;
            exit(1);
        }
    }
    if (settings.renderMode.get() == Settings::RenderMode::NONE) {
        if (!settings.outputResultFile.isset())
            std::cout << lsystem->current()->toString() << std::endl;
    } else if (settings.renderMode.get() == Settings::RenderMode::SVG) {
        if (settings.outputRenderFile.isset()) {
            if (!writeToFile(settings.outputRenderFile.get(), node2svg(lsystem->current(), lsystem))) {
                std::cerr << "File '" << settings.outputRenderFile.get() << "' is not writable." << std::endl;
                exit(1);
            }
        } else {
            std::cout << node2svg(lsystem->current(), lsystem) << std::endl;
        }
    }

    return 0;
}

