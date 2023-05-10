
#pragma once


#include "common.h"
#include "Settings.h"


// using namespace std::literals;


void parseCLIArgs(int argc, char** argv, lsysgen::Settings & settings);

int strict_stoi(std::string const& arg, std::string const& s, int base=10);
float strict_stof(std::string const& arg, std::string const& s);

void printUsage();
void printVersion();
void printHelp();
