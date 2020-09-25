
#pragma once


namespace lsysgen {

template<typename T>
class LSystem;

}

#include "Module.h"
#include "ParseTreeNode.h"
#include "NodeContent.h"
#include "Table.h"
#include "Rule.h"
#include "values.h"
#include "ErrorHandler.h"
#include "LSysDVisitor.h"
#include "Derivator.h"

#include <string>
#include <map>
#include <list>
#include <vector>

namespace lsysgen {

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
    std::list<T> * _ignore;
    Function * _tableFunc;

    ParseTreeNode<InstanceNodeContent, T> * _lastWord;
    std::vector<ParseTreeNode<InstanceNodeContent, T> *> _encodedProgression;

    ErrorHandler * eh;
    Derivator<T> derivator;

    void populateProperties();

public:
    double initialHeading;
    double rotation;
    // double lineLength;
    double lineWidth;
    std::string background;

public:
    LSystem(Module<T> * module);

    ~LSystem();

    ErrorHandler * messages();

    void prepare();
    void iterate();
    void iterate(int iterations);
    ParseTreeNode<InstanceNodeContent, T> * current();
    int iteration() const;
    std::string const& name() const;
    Table<T> * getTable(int i);
};

}
