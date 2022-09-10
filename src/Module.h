
#pragma once


namespace lsysgen {

template<typename T>
class Module;

}

#include "LSystem.h"
#include "ErrorHandler.h"
#include "LSysDVisitor.h"
#include "values.h"
// #include "Settings.h"

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
    // Settings const* _settings;

public:
    Module(std::string_view name);
    // Module();

    ~Module();

    ErrorHandler * messages();
    LSysDExpressionEvaluator * evaluator();

    Scope * scope();
    std::string const& name() const;
    // Settings const* settings() const;
    // std::string const& filename() const;

    LSystem<T> * mainLSystem();
};

}
