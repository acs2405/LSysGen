
#include "Table.h"


namespace lsys {

char wildcard() {return '_';}

template<typename T>
Table<T>::Table(std::string const& name): name(name) {
	this->rules = new std::map<T, std::list<Rule<T>*>*>();
}

template<typename T>
Table<T>::~Table() {
	for (auto e : *this->rules)
		e.second->clear();
	this->rules->clear();
}

template<typename T>
void Table<T>::addRule(Rule<T>* r) {
	auto l = this->rules->find(r->leftChar());
	if (l != this->rules->end()) {
		(*l).second->push_back(r);
	} else {
		this->rules->emplace(r->leftChar(), new std::list<Rule<T>*> {r});
	}
}

template<typename T>
const std::list<Rule<T>*>* Table<T>::rulesFor(T c) {
	std::list<Rule<T>*>* ret = new std::list<Rule<T>*>();	
	auto it1 = this->rules->find(c);
	if (it1 != this->rules->end())
		ret->insert(ret->end(), (*it1).second->begin(), (*it1).second->end());
		// return it->second;
	// else
	// 	return nullptr;
	auto it2 = this->rules->find(wildcard());
	if (it2 != this->rules->end())
		ret->insert(ret->end(), (*it2).second->begin(), (*it2).second->end());
	return ret;
}

template<typename T>
std::string Table<T>::toString() {
	std::string ret = "table " + this->name + " {\n";
	for (auto const& e : *this->rules) {
		for (Rule<T>* r : *e.second)
			ret += "    " + r->toString() + "\n";
	}
	ret += "}\n";
	return ret;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Table<T>& t) {
	return os << t.toString() << std::endl;
}



template class Table<char>;

}
