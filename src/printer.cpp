
#include "printer.h"



int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: lsys FILE.lsd [N_ITERATIONS]" << std::endl;
        exit(1);
    }

    // g2D_prepare(argc, argv);

    lsysgen::LSystem<char>* lsystem = lsystem_create(argv[1]);

    if (lsystem == nullptr)
        exit(1);

    if (argc == 3) {
        int n = std::stoi(argv[2]);
        // lsystem->iterations = n;
        lsystem->iterate(n);
    } else {
        lsystem->iterate();
    }

    // int i = 0;
    // for (lsysgen::ParseTreeNode<lsysgen::InstanceNodeContent, char>* iteration : *lsystem->encodedProgression) {
    //     std::cout << i++ << ": " << iteration->toString() << std::endl;
    // }
    std::cout << lsystem->current()->toString() << std::endl;

    return 0;
}

