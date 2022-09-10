
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

    if (settings.outputResultFile.isset())
        writeToFile(settings.outputResultFile.get().c_str(), lsystem->current()->toString());
    if (settings.renderMode.get() == Settings::RenderMode::NONE) {
        if (!settings.outputResultFile.isset())
            std::cout << lsystem->current()->toString() << std::endl;
    } else if (settings.renderMode.get() == Settings::RenderMode::SVG) {
        if (settings.outputRenderFile.isset()) {
            writeToFile(settings.outputRenderFile.get().c_str(), node2svg(lsystem->current(), lsystem));
        } else {
            std::cout << node2svg(lsystem->current(), lsystem) << std::endl;
        }
    }

    return 0;
}

