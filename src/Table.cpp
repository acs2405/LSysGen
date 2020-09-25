
#include "Table.h"


namespace lsysgen {

char wildcard() {return '_';}

template<typename T>
Table<T>::Table(std::string const& name): name(name), _rules() {
    // this->_rules = new std::map<T, std::list<Rule<T> *> *>();
}

template<typename T>
Table<T>::~Table() {
    for (auto e : _rules)
        e.second->clear();
    _rules.clear();
}

template<typename T>
int Table<T>::size() const {
    return _rules.size();
}

template<typename T>
void Table<T>::addRule(Rule<T> * r) {
    auto l = _rules.find(r->leftChar());
    if (l != _rules.end()) {
        ( *l).second->push_back(r);
    } else {
        _rules.emplace(r->leftChar(), new std::list<Rule<T> *> {r});
    }
}

template<typename T>
std::list<Rule<T> *> const* Table<T>::rulesFor(T c) const {
    std::list<Rule<T> *> * ret = new std::list<Rule<T> *>();   
    auto it1 = _rules.find(c);
    if (it1 != _rules.end())
        ret->insert(ret->end(), (*it1).second->begin(), (*it1).second->end());
        // return it->second;
    // else
    //  return nullptr;
    auto it2 = _rules.find(wildcard());
    if (it2 != _rules.end())
        ret->insert(ret->end(), (*it2).second->begin(), (*it2).second->end());
    return ret;
}

template<typename T>
std::string Table<T>::toString() const {
    std::string ret = "table " + this->name + " {\n";
    for (auto const& e : _rules) {
        for (Rule<T> * r : *e.second)
            ret += "    " + r->toString() + "\n";
    }
    ret += "}\n";
    return ret;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Table<T> const& t) {
    return os << t.toString() << std::endl;
}



template class Table<char>;

template std::ostream & operator<<(std::ostream & os, Table<char> const& r);

}
