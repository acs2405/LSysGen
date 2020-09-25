
#pragma once


namespace lsysgen {

template<typename T>
class Module;

}

#include "LSystem.h"
#include "ErrorHandler.h"
#include "LSysDVisitor.h"
#include "values.h"

#include <string>
#include <iostream>
#include <map>
#include <list>

namespace lsysgen {

template<typename T>
class Module {
    friend LSysDVisitor;

    std::string _filename;
    std::string _name;
    Scope * _scope;
    // LSysDExpressionEvaluator * evaluator;
    LSystem<T> * _mainLSystem;
    std::map<std::string, LSystem<T> *> _lsystems;

    ErrorHandler * eh;

    LSysDExpressionEvaluator * _evaluator;

public:
    Module(std::string const& name);
    // Module();

    ~Module();

    ErrorHandler * messages();
    LSysDExpressionEvaluator * evaluator();

    Scope * scope();
    // Scope * scope();
    std::string const& name() const;
    std::string const& filename() const;

    LSystem<T> * mainLSystem();
};

}
