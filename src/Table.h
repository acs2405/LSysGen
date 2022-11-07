
#pragma once


namespace lsysgen {

template<typename>
class Table;

}

#include "common.h"
#include "Rule.h"

#include <string>
#include <iostream>
#include <map>
#include <list>


namespace lsysgen {

template<typename T>
class Table {
public:
    const std::string name;

private:
    std::map<T, std::list<Rule<T> *> *> _rules;

public:
    Table(std::string const& name);

    ~Table();

    size_t size() const;

    void addRule(Rule<T> * r);

    std::list<Rule<T> *> const* rulesFor(T c) const;

    std::string toString() const;
};

template<typename T>
std::ostream & operator<<(std::ostream & os, Table<T> const& t);

}