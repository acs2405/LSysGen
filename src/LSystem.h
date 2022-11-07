
#pragma once


namespace lsysgen {

template<typename T>
class LSystem;

}

#include "common.h"
#include "Module.h"
#include "ParseTreeNode.h"
#include "NodeContent.h"
#include "Table.h"
#include "Rule.h"
#include "values.h"
#include "ErrorHandler.h"
#include "LSysDVisitor.h"
#include "Derivator.h"
#include "Settings.h"
// #include "misc.h"

#include <string>
#include <map>
#include <list>
#include <vector>

namespace lsysgen {

/**
 * The LSystem class
 */
template<typename T>
class LSystem {
    friend LSysDVisitor;
    
    int _current;

    Module<T> * _module;
    Scope * _scope;
    // LSysDExpressionEvaluator * _evaluator;

    std::string _name;
    std::map<std::string, Table<T> *> _tables;
    // std::list<Table<T> *> * _tablesList;
    Table<T> * _defaultTable;
    Table<T> * _codingRules;
    std::map<std::string, Rule<T> *> _taggedRules;

    ParseTreeNode<InstanceNodeContent, T> * _axiom;
    int _iterations;
    Settings2D _settings2D;
    std::list<T> * _ignore;
    Function * _tableFunc;

    // bool _main;

    ParseTreeNode<InstanceNodeContent, T> * _lastWord;
    std::vector<ParseTreeNode<InstanceNodeContent, T> *> _encodedProgression;

    ErrorHandler * eh;
    Derivator<T> derivator;

    void populateProperties(Settings const& settings);

// public:
//     double initialHeading;
//     double rotation;
//     // double lineLength;
//     double lineWidth;
//     std::string background;

public:
    LSystem(Module<T> * module);

    ~LSystem();

    void setAxiom(ParseTreeNode<InstanceNodeContent, T> * axiom);

    ErrorHandler * messages();
    ErrorHandler const* messages() const;
    // Settings const* settings() const;
    Settings2D const& settings2D() const;
    int iterations() const;

    void prepare();
    void iterate();
    void iterate(int iterations);
    Table<T> * getTable(int i);

    ParseTreeNode<InstanceNodeContent, T> * current();
    int iteration() const;
    std::uint_fast32_t seed() const;
    std::string const& name() const;
    Module<T> * module();

    // bool isMain() const;
};

}
