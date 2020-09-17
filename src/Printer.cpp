
#include "Printer.h"



int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: lsysgen FILE.lsd [N_ITERATIONS]" << std::endl;
        exit(1);
    }

    // g2D_prepare(argc, argv);

    lsysgen::LSystem<char>* lsystem = parseLSystemFromFile(argv[1]);

    if (lsystem == nullptr)
        exit(1);

    if (argc == 3) {
        int n = std::stoi(argv[2]);
        lsystem->iterations = n;
    }

    lsystem->prepare();
    lsystem->iterate();

    // int i = 0;
    // for (lsysgen::ParseTreeNode<lsysgen::InstanceNodeContent, char>* iteration : *lsystem->encodedProgression) {
    //     std::cout << i++ << ": " << iteration->toString() << std::endl;
    // }
    std::cout << lsystem->encodedProgression->back()->toString() << std::endl;

    return 0;
}

