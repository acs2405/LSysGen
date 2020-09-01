
#pragma once


namespace lsysgen {

template<typename T>
class LSystem;

}

#include "ParseTreeNode.h"
#include "NodeContent.h"
#include "Table.h"
#include "Rule.h"
#include "misc.h"

#include <string>
#include <iostream>
#include <map>
#include <list>

namespace lsysgen {

template<typename T>
class LSystem {
    int current;

public:
    Environment* env;
    // LSysDExpressionEvaluator* evaluator;

	std::string name;
	std::map<std::string, Table<T>*>* tables;
	// std::list<Table<T>*>* tablesList;
	Table<T>* defaultTable;
	Table<T>* codingRules;
	std::map<std::string, Rule<T>*>* taggedRules;

	Function* tableFunc;
	ParseTreeNode<InstanceNodeContent, T>* axiom;
	int iterations;
	std::list<T>* ignore;
	double initialHeading;
	double rotation;

    std::list<ParseTreeNode<InstanceNodeContent, T>*>* progression;
    std::list<ParseTreeNode<InstanceNodeContent, T>*>* encodedProgression;

public:
	LSystem();

	~LSystem();

	void prepare();
	void iterate(int iterations=-1);
	Table<T>* getTable(int i);
};

}
