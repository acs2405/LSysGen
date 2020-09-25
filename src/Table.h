
#pragma once


namespace lsysgen {

template<typename>
class Table;

}

#include "Rule.h"

#include <string>
#include <iostream>
#include <map>
#include <list>


namespace lsysgen {

template<typename T>
class Table {
    std::map<T, std::list<Rule<T> *> *> _rules;

public:
    const std::string name;

    Table(std::string const& name);

    ~Table();

    int size() const;

    void addRule(Rule<T> * r);

    std::list<Rule<T> *> const* rulesFor(T c) const;

    std::string toString() const;
};

template<typename T>
std::ostream & operator<<(std::ostream & os, Table<T> const& t);

}
