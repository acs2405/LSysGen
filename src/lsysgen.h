
#pragma once


#include "antlr4-runtime.h"
#include "LSysDLexer.h"
#include "LSysDParser.h"
#include "LSysDVisitor.h"
#include "LSystem.h"
// #include "Drawer2D.h"

#include <string>
#include <iostream>



extern "C" const char* generateLSystem(const char* file, int iterations=-1);

lsysgen::LSystem<char>* parseLSystemFromFile(std::string const& file);

lsysgen::LSystem<char>* parseLSystemFromStream(std::istream& stream, std::string const& file="<default>");

