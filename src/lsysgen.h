
#pragma once


#include "antlr4-runtime.h"
#include "LSysDLexer.h"
#include "LSysDParser.h"
#include "LSysDVisitor.h"
#include "LSystem.h"
#include "interpreter2D.h"
// #include "Drawer2D.h"

#include <string>
#include <iostream>



// extern "C" const char* generateLSystemSVG(const char* file, int iterations=-1);

// extern "C" const char* generateLSystem(const char* file, int iterations=-1);

extern "C" lsysgen::LSystem<char>* lsystem_create(const char* file, int iterations=-1);
extern "C" void lsystem_generate(LSystem<char>* lsystem);
extern "C" void lsystem_iterate(LSystem<char>* lsystem, int iterations=1);
extern "C" int lsystem_get_iteration_number(LSystem<char>* lsystem);
extern "C" const char* lsystem_get_result_string(LSystem<char>* lsystem);
extern "C" const char* lsystem_to_svg(LSystem<char>* lsystem);

lsysgen::LSystem<char>* parseLSystemFromFile(const char* file);

lsysgen::LSystem<char>* parseLSystemFromStream(std::istream& stream, std::string const& file="<default>");

