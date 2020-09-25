
#include "lsys2svg.h"

#include <sstream>


int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: lsys2svg FILE.lsd [N_ITERATIONS]" << std::endl;
        exit(1);
    }

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

    if (lsystem->messages()->failed()) {
        lsystem->messages()->dump();
        return 1;
    }

    std::cout << node2svg(lsystem->current(), lsystem) << std::endl;
    // }

    return 0;
}

