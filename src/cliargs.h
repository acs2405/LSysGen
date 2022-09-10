
#pragma once


#include "Settings.h"

#include <string>
#include <string_view>
#include <regex>
#include <iostream>


// using namespace std::literals;


void parseCLIArgs(int argc, char** argv, lsysgen::Settings & settings);

void printUsage();
void printHelp();
