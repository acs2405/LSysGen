
#pragma once


#include "Settings.h"

#include <string>
#include <string_view>
#include <regex>
#include <iostream>


// using namespace std::literals;


void parseCLIArgs(int argc, char** argv, lsysgen::Settings & settings);

int strict_stoi(std::string const& arg, std::string const& s, int base=10);
double strict_stod(std::string const& arg, std::string const& s);

void printUsage();
void printHelp();
