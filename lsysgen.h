
#pragma once


#include "antlr4-runtime.h"
#include "LSysDLexer.h"
#include "LSysDParser.h"
#include "LSysDVisitor.h"
#include "LSystem.h"
#include "Drawer2D.h"

#include <string>
#include <iostream>


int main(int argc, char** argv);

lsysgen::LSystem<char>* parseLSystem(std::string file);

lsysgen::LSystem<char>* parseLSystem(std::string file, std::istream& stream);
