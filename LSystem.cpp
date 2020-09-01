
#include "LSystem.h"

namespace lsys {

template<typename T>
LSystem<T>::LSystem(): env(nullptr), name(""), tables(nullptr), defaultTable(nullptr), 
        codingRules(nullptr), taggedRules(nullptr), tableFunc(nullptr), axiom(nullptr), 
        iterations(0), initialHeading(0.0), rotation(0.0), current(-1) {
    this->progression = new std::list<ParseTreeNode<InstanceNodeContent, T>*>();
    this->encodedProgression = new std::list<ParseTreeNode<InstanceNodeContent, T>*>();
    this->ignore = new std::list<T>();
}

template<typename T>
LSystem<T>::~LSystem() {}

template<typename T>
void LSystem<T>::prepare() {
    if (this->current < 0) {
        this->current = 0;
        // this->axiom = this->parser.parseWord(this->axiom, this->environment());
        this->progression->push_back(this->axiom);  // seed
        // this->encodedProgression->push_back(this->progression->back());
        this->encodedProgression->push_back(derive(this->axiom, this->codingRules, this->ignore, this->env));
    }
}

template<typename T>
void LSystem<T>::iterate(int iterations) {
    iterations = iterations >= 0 ? iterations : this->iterations - this->current;
    for (int i = this->progression->size(); i < this->current + iterations + 1; ++i) {
        Table<T>* table = this->getTable(i);
        // std::cout << "ROUND " << i << std::endl;
        this->progression->push_back(derive(this->progression->back(), table, this->ignore, this->env));
        // this->encodedProgression->push_back(this->progression->back());
        this->encodedProgression->push_back(derive(this->progression->back(), this->codingRules, this->ignore, this->env));
    }
    this->current += iterations;
}

template<typename T>
Table<T>* LSystem<T>::getTable(int i) {
    if (this->tableFunc == nullptr)
        return this->defaultTable;
    // std::cout << this->tableFunc->toString() << std::endl;
    Value val = this->tableFunc->call(new std::list<Value> {Value(i)});
    if (!val.isString()) {
        err("Table function must return a string");
        return nullptr;
    }
    std::string tableIndex = val.asString();
    if (this->tables->find(tableIndex) != this->tables->end())
        return this->tables->at(tableIndex);
    // if type(tableIndex) == int and tableIndex < len(this->tablesList):
    //     return this->tablesList[tableIndex];
    err("Error in table function: no table '" + tableIndex + "' found");
    return nullptr;
}



template class LSystem<char>;

}
