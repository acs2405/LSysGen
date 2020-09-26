
#include "LSystem.h"

#include "misc.h"

#include <iostream>
#include <cmath>

namespace lsysgen {

template<typename T>
LSystem<T>::LSystem(Module<T> * module): _module(module), _name(), eh(module->messages()), 
        derivator(eh, module->evaluator()), _tableFunc(nullptr), _axiom(nullptr), 
        _iterations(0), _ignore(), initialHeading(0.0), rotation(NAN), lineWidth(NAN), 
        background(), _current(-1), _lastWord(nullptr), _encodedProgression() {
    this->_scope = new Scope(module->scope());

    this->_defaultTable = new Table<char>("<default>");
    this->_tables[this->_defaultTable->name] = this->_defaultTable;
    this->_codingRules = new Table<char>("<coding>");
}

template<typename T>
LSystem<T>::~LSystem() {
    for (auto t : _tables)
        delete t.second;
    // delete _defaultTable;
    delete _codingRules;
    delete _axiom;
    delete _ignore;
    // delete _tableFunc;
    delete _lastWord;
    _encodedProgression.clear();
    // for (ParseTreeNode<InstanceNodeContent, T> * n : _encodedProgression)
    //     delete n;
    delete _scope;
}

template<typename T>
ErrorHandler * LSystem<T>::messages() {return this->eh;}

template<typename T>
void LSystem<T>::populateProperties() {
    if (_scope->has("table_func")) {
        Value v = _scope->get("table_func");
        if (v.isFunction() && v.asFunction()->params()->size() == 1)
            this->_tableFunc = v.asFunction();
        else if (!v.isError())
            eh->error("table_func property must be a function with one parameter");
    }
    if (_scope->has("iterations")) {
        Value v = _scope->get("iterations");
        if (v.isInt())
            this->_iterations = v.asInt();
        else if (!v.isError())
            eh->error("iterations property must be a integer number");
    }
    if (_scope->has("ignore")) {
        Value v = _scope->get("ignore");
        if (v.isString()) {
            std::string ignore = v.asString();
            this->_ignore = new std::list<char>(ignore.begin(), ignore.end());
        } else if (!v.isError())
            eh->error("ignore property must be a string");
    }
    if (_scope->has("initial_heading")) {
        Value v = _scope->get("initial_heading");
        if (v.isFloat())
            this->initialHeading = v.asFloat();
        else if (v.isInt())
            this->initialHeading = v.asInt();
        else if (!v.isError())
            eh->error("initial_heading property must be a number");
    }
    if (_scope->has("rotation")) {
        Value v = _scope->get("rotation");
        if (v.isFloat())
            this->rotation = v.asFloat();
        else if (v.isInt())
            this->rotation = v.asInt();
        else if (!v.isError())
            eh->error("rotation property must be a number");
    }
    if (_scope->has("line_width")) {
        Value v = _scope->get("line_width");
        if (v.isFloat())
            this->lineWidth = v.asFloat();
        else if (v.isInt())
            this->lineWidth = v.asInt();
        else if (!v.isError())
            eh->error("line_width property must be a number");
    }
    if (_scope->has("background")) {
        Value v = _scope->get("background");
        if (v.isString()) {
            this->background = sanitizeXML(v.asString());
        } else if (!v.isError())
            eh->error("background property must be a string");
    }
}

template<typename T>
void LSystem<T>::prepare() {
    if (eh->failed())
        return;
    if (this->_current < 0) {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        srand(millis);
        if (this->_axiom == nullptr)
            this->_axiom = new ParseTreeNode<InstanceNodeContent, T>();
        if (this->_ignore == nullptr)
            this->_ignore = new std::list<T>();
        this->_current = 0;
        // this->_axiom = this->parser.parseWord(this->_axiom, this->_scope());
        this->_scope->set("i", 0);
        this->_lastWord = this->_axiom;  // seed
        ParseTreeNode<InstanceNodeContent, T> * derived = derivator.derive(_lastWord, _codingRules, _ignore, _scope);
        if (derived == nullptr)
            return;
        this->_encodedProgression.push_back(derived);
    }
}

template<typename T>
void LSystem<T>::iterate() {
    if (eh->failed())
        return;
    this->prepare();
    if (this->_current < this->_iterations) {
        int iterations = this->_iterations - this->_current;
        this->iterate(iterations);
    }
}

template<typename T>
void LSystem<T>::iterate(int iterations) {
    if (eh->failed())
        return;
    this->prepare();
    for (int i = this->_encodedProgression.size(); i < this->_current + iterations + 1; ++i) {
        Table<T> * table = this->getTable(i);
        if (table == nullptr)
            return;
        this->_scope->set("i", i);
        // std::cout << "ROUND " << i << std::endl;
        // std::cout << this->_scope->get("i").asInt() << std::endl;
        ParseTreeNode<InstanceNodeContent, T> * lastWord = this->_lastWord;
        ParseTreeNode<InstanceNodeContent, T> * derived;
        derived = derivator.derive(lastWord, table, _ignore, _scope);
        if (derived == nullptr)
            return;
        this->_lastWord = derived;
        delete lastWord;
        derived = derivator.derive(_lastWord, _codingRules, _ignore, _scope);
        if (derived == nullptr)
            return;
        this->_encodedProgression.push_back(derived);
    }
    this->_current += iterations;
    if (this->_current < 0)
        this->_current = 0;
    this->_scope->set("i", this->_current);
}

template<typename T>
ParseTreeNode<InstanceNodeContent, T> * LSystem<T>::current() {
    if (_encodedProgression.size() > 0)
        return this->_encodedProgression.at(this->_current);
    else
        return nullptr;
}

template<typename T>
int LSystem<T>::iteration() const {
    return this->_current;
}

template<typename T>
std::string const& LSystem<T>::name() const {
    return this->_name;
}

template<typename T>
Table<T> * LSystem<T>::getTable(int i) {
    if (this->_tableFunc == nullptr)
        return this->_defaultTable;
    // std::cout << this->_tableFunc->toString() << std::endl;
    Value val = this->_tableFunc->call(new std::list<Value> {Value(i)}, _scope, _module->evaluator());
    if (val.isError())
        return nullptr;
    if (!val.isString()) {
        eh->fatalError("Table function must return a string");
        return nullptr;
    }
    std::string tableIndex = val.asString();
    if (this->_tables.find(tableIndex) != this->_tables.end())
        return this->_tables.at(tableIndex);
    // if type(tableIndex) == int and tableIndex < len(this->tablesList):
    //     return this->tablesList[tableIndex];
    eh->fatalError("Error in table function: no table '" + tableIndex + "' found");
    return nullptr;
}



template class LSystem<char>;

}
