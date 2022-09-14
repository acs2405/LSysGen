
#pragma once


#include "antlr4-runtime.h"
#include "LSysDLexer.h"
#include "LSysDParser.h"
#include "LSysDVisitor.h"
#include "LSystem.h"
#include "interpreter2D.h"
#include "Settings.h"
// #include "Drawer2D.h"

#include <string>
#include <string_view>
#include <iostream>



// extern "C" const char* generateLSystemSVG(const char* file, int iterations=-1);

// extern "C" const char* generateLSystem(const char* file, int iterations=-1);

extern "C" lsysgen::LSystem<char> ** lsystem_create_from_settings(lsysgen::Settings const& settings);
extern "C" lsysgen::LSystem<char> ** lsystem_create_from_file(char const* file);
extern "C" void lsystem_generate(lsysgen::LSystem<char> * lsystem);
extern "C" void lsystem_iterate(lsysgen::LSystem<char> * lsystem, int iterations=1);
extern "C" int lsystem_get_iteration_number(lsysgen::LSystem<char> * lsystem);
extern "C" int lsystem_get_number_of_errors(lsysgen::LSystem<char> * lsystem);
extern "C" char const* lsystem_get_result_string(lsysgen::LSystem<char> * lsystem);
extern "C" char const* lsystem_to_svg(lsysgen::LSystem<char> * lsystem);

std::list<lsysgen::LSystem<char> *> * createLSystems(lsysgen::Settings const& settings);

std::list<lsysgen::LSystem<char> *> * parseLSystem(lsysgen::Settings const& settings);

std::list<lsysgen::LSystem<char> *> * parseLSystemFromString(std::string_view inputFile, std::string_view lsdContents, lsysgen::Settings const& settings);

std::list<lsysgen::LSystem<char> *> * parseLSystemFromAxiom(std::string_view inputFile, std::string_view s_axiom, lsysgen::Settings const& settings);

