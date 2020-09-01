
#pragma once


namespace lsys {

template<typename>
class Table;

}

#include "Rule.h"

#include <string>
#include <iostream>
#include <map>
#include <list>


namespace lsys {

template<typename T>
class Table {
	std::map<T, std::list<Rule<T>*>*>* rules;

public:
	const std::string name;

	Table(std::string const& name);

	~Table();

	void addRule(Rule<T>* r);

	const std::list<Rule<T>*>* rulesFor(T c);

	std::string toString();
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Table<T>& t);

}
