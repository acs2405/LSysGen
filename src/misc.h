
#pragma once


// #include "ParseTreeNode.h"
// #include "Rule.h"
// #include "Table.h"
// #include "values.h"

// #include "LSysDParser.h"
// #include "LSysDExpressionEvaluator.h"

#include <string>
#include <string_view>
#include <iostream>
// #include <map>
// #include <list>
// #include <vector>
#include <cstdint>
#include <random>

#ifndef M_PI
#define M_PI = 3.14159265358979323846;
#endif


namespace lsysgen {

class Random {
    std::mt19937 gen;

public:
	Random();
	~Random();
	
    void seed(std::uint_fast32_t seed);
    std::uint_fast32_t rand();
    double randFloat();

    static std::uint_fast32_t randomSeed();
};

// template<typename Base, typename T>
// bool instanceof(T const*) {
//    return std::is_base_of<Base, T>::value;
// }

// Value eval(LSysDParser::ExpressionContext * expr, Scope * scope);

// template<typename T>
// bool checkLeftContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, std::list<T> * ignore, Scope * paramMapping);
// template<typename T>
// bool checkRightContext(ParseTreeNode<LeftSideNodeContent, T> * contextNode, ParseTreeNode<InstanceNodeContent, T> * instanceNode, std::list<T> * ignore, Scope * paramMapping);

// template<typename T>
// ParseTreeNode<InstanceNodeContent, T> * evaluateRightNode(const ParseTreeNode<RightSideNodeContent, T> * node, Scope * paramMapping);

// template<typename T>
// ParseTreeNode<InstanceNodeContent, T> * derive(ParseTreeNode<InstanceNodeContent, T> * node, Table<T> * table, std::list<T> * ignore=nullptr, Scope * scope=nullptr);

// Scope * mapArgs(const std::vector<Value> * values, const std::list<Parameter *> * params, Scope * paramMapping);

// bool checkCondition(LSysDParser::ExpressionContext * cond, Scope * paramMapping);

// template<typename T>
// Rule<T> * chooseRule(std::list<Rule<T> *> * rules);

std::string strEscape(std::string const& s);
std::string strUnescape(std::string const& s);
std::string sanitizeXML(std::string const& s);

std::string getModuleName(std::string const& filename);

bool terminalSupportsColors();

void readFromFile(char const* fileName, std::string & content);
void writeToFile(char const* outputFile, std::string_view output);

// std::string anyToString(Value * v);

// extern template ParseTreeNode<InstanceNodeContent, char> * derive(ParseTreeNode<InstanceNodeContent, char> * node, Table<char> * table, std::list<char> * ignore, Scope * env);

}
