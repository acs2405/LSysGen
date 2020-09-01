
#include "Table.h"


namespace lsysgen {

char wildcard() {return '_';}

template<typename T>
Table<T>::Table(std::string const& name): name(name) {
	this->_rules = new std::map<T, std::list<Rule<T>*>*>();
}

template<typename T>
Table<T>::~Table() {
	for (auto e : *this->_rules)
		e.second->clear();
	this->_rules->clear();
}

template<typename T>
int Table<T>::size() const {
	return this->_rules->size();
}

template<typename T>
void Table<T>::addRule(Rule<T>* r) {
	auto l = this->_rules->find(r->leftChar());
	if (l != this->_rules->end()) {
		(*l).second->push_back(r);
	} else {
		this->_rules->emplace(r->leftChar(), new std::list<Rule<T>*> {r});
	}
}

template<typename T>
const std::list<Rule<T>*>* Table<T>::rulesFor(T c) {
	std::list<Rule<T>*>* ret = new std::list<Rule<T>*>();	
	auto it1 = this->_rules->find(c);
	if (it1 != this->_rules->end())
		ret->insert(ret->end(), (*it1).second->begin(), (*it1).second->end());
		// return it->second;
	// else
	// 	return nullptr;
	auto it2 = this->_rules->find(wildcard());
	if (it2 != this->_rules->end())
		ret->insert(ret->end(), (*it2).second->begin(), (*it2).second->end());
	return ret;
}

template<typename T>
std::string Table<T>::toString() {
	std::string ret = "table " + this->name + " {\n";
	for (auto const& e : *this->_rules) {
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
