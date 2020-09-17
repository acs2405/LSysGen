
#pragma once


#include "antlr4-runtime.h"
#include "LSysDLexer.h"
#include "LSysDParser.h"
#include "LSysDVisitor.h"
#include "LSystem.h"
// #include "Drawer2D.h"

#include <string>
#include <iostream>



lsysgen::LSystem<char>* parseLSystemFromFile(std::string const& file);

lsysgen::LSystem<char>* parseLSystemFromStream(std::istream& stream, std::string const& file="<default>");

