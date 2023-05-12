
#pragma once


namespace lsysgen {

template<typename>
class Table;

}

#include "common.h"
#include "Rule.h"


namespace lsysgen {

template<typename T>
class Table {
public:
    const std::string name;

private:
    std::map<std::pair<T,int>, std::list<Rule<T> *>> _rules;
    mutable std::map<std::pair<T,int>, std::list<Rule<T> *>> _cachedRules;

    void addRule(Rule<T> * r, T c, int arity);

public:
    Table(std::string const& name);

    ~Table();

    size_t size() const;

    void addRule(Rule<T> * r);

    std::list<Rule<T> *> const* rulesFor(T c, int arity) const;

    std::string toString() const;
};

template<typename T>
std::ostream & operator<<(std::ostream & os, Table<T> const& t);

}
