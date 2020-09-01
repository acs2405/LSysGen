
#pragma once


namespace lsys {

class Parameter;
class Function;
class ValueType;
class Value;
class Environment;

}

#include "ParseTreeNode.h"
#include "Rule.h"
#include "Table.h"

#include "LSysDParser.h"
#include "LSysDExpressionEvaluator.h"

#include <boost/any.hpp>

#include <string>
#include <iostream>
#include <map>
#include <list>
#include <regex>
#include <utility>
#include <sstream>


namespace lsys {

// typedef antlrcpp::Any Any;

class Parameter {
public:
	const std::string name;
	Parameter(std::string const& name);
	// std::string name() {return _name;}
};

bool operator==(Parameter const& p1, Parameter const& p2);


class Function {
	std::list<Parameter*>* params;
	LSysDParser::ExpressionContext* expr;
	antlr4::tree::ParseTree* ctx;

public:
	Function(std::list<Parameter*>* params, LSysDParser::ExpressionContext* expr, antlr4::tree::ParseTree* ctx);
	std::string toString();
	Value call(std::list<Value>* args);
};


class ValueType {
private:
	std::string _name;

	ValueType(std::string const& name);

public:
	std::string const& name() const;

	static const ValueType INT_TYPE;
	static const ValueType FLOAT_TYPE;
	static const ValueType BOOL_TYPE;
	static const ValueType STRING_TYPE;
	static const ValueType FUNCTION_TYPE;
	static const ValueType ERROR_TYPE;

	friend bool operator==(ValueType const& p1, ValueType const& p2);
};

bool operator==(ValueType const& p1, ValueType const& p2);


class Value { // : antlrcpp::Any {
public:
	static Value const& error();

private:
	static const Value ERROR;
	ValueType _type;
	boost::any _value;

public:
	// Value(antlrcpp::Any val);
	Value(ValueType const& type, boost::any value);
	Value();
	Value(int value);
	Value(double value);
	Value(bool value);
	Value(std::string value);
	Value(Function* value);

	ValueType const& type() const;
	bool is (ValueType const& t) const;
	bool isInt () const;
	bool isFloat () const;
	bool isBool () const;
	bool isString () const;
	bool isFunction () const;
	bool isError () const;

	// bool isTrue () const;

	int asInt () const;
	double asFloat () const;
	bool asBool () const;
	std::string asString () const;
	Function* asFunction ();
	Function* asFunction () const;

	template<typename T>
	T as ();
	template<typename T>
	const T as () const;

	std::string toString() const;

	Value& operator=(Value const& p2);
};


// class Error {
// public:
// 	Error();
// };


class Environment {
	std::map<std::string, Value>* mapping;
public:
	Environment();
	Environment(Environment* env);
	~Environment();

	void set(std::string const& var, Value const& val);
	Value get(std::string const& var);
	bool has(std::string const& var) const;

	// Environment* copy();
	void merge(Environment* env);
};

template<typename Base, typename T>
bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}

Value eval(LSysDParser::ExpressionContext* expr, Environment* env);

template<typename T>
bool checkLeftContext(ParseTreeNode<LeftSideNodeContent, T>* contextNode, ParseTreeNode<InstanceNodeContent, T>* instanceNode, std::list<T>* ignore, Environment* paramMapping);
template<typename T>
bool checkRightContext(ParseTreeNode<LeftSideNodeContent, T>* contextNode, ParseTreeNode<InstanceNodeContent, T>* instanceNode, std::list<T>* ignore, Environment* paramMapping);

template<typename T>
ParseTreeNode<InstanceNodeContent, T>* evaluateRightNode(const ParseTreeNode<RightSideNodeContent, T>* node, Environment* paramMapping);

template<typename T>
ParseTreeNode<InstanceNodeContent, T>* derive(ParseTreeNode<InstanceNodeContent, T>* node, Table<T>* table, std::list<T>* ignore=nullptr, Environment* env=nullptr);

bool checkCondition(LSysDParser::ExpressionContext* cond, Environment* paramMapping);

template<typename T>
Rule<T>* chooseRule(std::list<Rule<T>*>* rules);

std::string strEscape(std::string const& s);
std::string strUnescape(std::string const& s);

void err(std::string const& msg, std::string const& source="", antlr4::tree::ParseTree* token=nullptr, int len=-1, int pos=-1);
void warning(std::string const& msg, std::string const& source="", antlr4::tree::ParseTree* token=nullptr, int len=-1, int pos=-1);

// std::string anyToString(Value* v);

extern template ParseTreeNode<InstanceNodeContent, char>* derive(ParseTreeNode<InstanceNodeContent, char>* node, Table<char>* table, std::list<char>* ignore, Environment* env);

}
