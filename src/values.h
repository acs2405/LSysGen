
#pragma once


namespace lsysgen {

class Parameter;
class Function;
class ValueType;
class Value;
class Scope;

}

#include <boost/any.hpp>

#include <string>
#include <iostream>
#include <map>
#include <list>

#include "LSysDParser.h"
#include "LSysDExpressionEvaluator.h"


namespace lsysgen {

// typedef antlrcpp::Any Any;

class Parameter {
public:
    std::string const name;

    Parameter(std::string const& name);
    // std::string name() {return _name;}
};

bool operator==(Parameter const& p1, Parameter const& p2);


class Function {
    std::list<Parameter *> * _params;
    LSysDParser::ExpressionContext * expr;
    antlr4::tree::ParseTree * ctx;

public:
    Function(std::list<Parameter *> * params, LSysDParser::ExpressionContext * expr, antlr4::tree::ParseTree * ctx);
    std::string toString();
    std::list<Parameter *> const* params() const;
    Value call(std::list<Value> * args, Scope * scope, LSysDExpressionEvaluator * ee);
};


class ValueType {
private:
    std::string const _name;

    ValueType(std::string const& name);

public:
    std::string const& name() const;

    static ValueType const INT_TYPE;
    static ValueType const FLOAT_TYPE;
    static ValueType const BOOL_TYPE;
    static ValueType const STRING_TYPE;
    static ValueType const FUNCTION_TYPE;
    static ValueType const NULL_TYPE;
    static ValueType const ERROR_TYPE;

    friend bool operator==(ValueType const& p1, ValueType const& p2);
};


class Value { // : antlrcpp::Any {
public:
    static Value const& error();
    static Value const& null();

private:
    static Value const ERROR;
    static Value const NIL;

    ValueType const* _type;
    boost::any _value;

public:
    // Value(antlrcpp::Any val);
    Value(ValueType const* type, boost::any const& value);
    Value();
    Value(int value);
    Value(double value);
    Value(bool value);
    Value(std::string const& value);
    Value(Function* value);
    Value(std::nullptr_t value);

    ValueType const* type() const;
    bool is (ValueType const* t) const;
    bool isInt () const;
    bool isFloat () const;
    bool isBool () const;
    bool isString () const;
    bool isFunction () const;
    bool isNull () const;
    bool isError () const;

    // bool isTrue () const;

    int asInt () const;
    double asFloat () const;
    bool asBool () const;
    std::string asString () const;
    Function* asFunction ();
    Function* asFunction () const;
    std::nullptr_t asNull () const;

    template<typename T>
    T as ();
    template<typename T>
    const T as () const;

    std::string toString() const;

    Value& operator=(Value const& p2);
};


// class Error {
// public:
//  Error();
// };


class Scope {
    std::map<std::string, Value> mapping;
    Scope * _parent;
public:
    Scope();
    Scope(Scope * parent);
    // Scope(Scope const& parent);
    ~Scope();

    Scope * parent();

    void set(std::string const& var, Value const& val);
    Value const& get(std::string const& var);
    bool has(std::string const& var) const;

    void merge(Scope const* env);
};

}
