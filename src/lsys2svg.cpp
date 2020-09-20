
#include "lsys2svg.h"

#include <sstream>


int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: lsys2svg FILE.lsd [N_ITERATIONS]" << std::endl;
        exit(1);
    }

    // g2D_prepare(argc, argv);

    // if (std::string(argv[1]) == "-") {
    //     std::string fileContents((std::istreambuf_iterator<char>(std::cin)),
    //                  std::istreambuf_iterator<char>());

    //     std::stringstream ss;

    //     std::vector<std::string>* lines = new std::vector<std::string>();
    //     std::string line;
    //     ss << fileContents;
    //     while (std::getline(ss, line))
    //         lines->push_back(line);

    //     // TreeShapeListener listener;
    //     // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
        
    //     LSysDVisitor* visitor = new LSysDVisitor("<stdin>", lines);
    //     lsysgen::ParseTreeNode<InstanceNodeContent, char>* node = visitor->parseInstanceNode(fileContents);

    //     std::cout << node2svg(node) << std::endl;
    // } else {
    lsysgen::LSystem<char>* lsystem = parseLSystemFromFile(argv[1]);

    if (lsystem == nullptr)
        exit(1);

    if (argc == 3) {
        int n = std::stoi(argv[2]);
        lsystem->iterations = n;
    }

    lsystem->prepare();
    lsystem->iterate();

    std::cout << node2svg(lsystem->encodedProgression->back(), lsystem) << std::endl;
    // }

    return 0;
}

