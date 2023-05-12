
#include "Table.h"


namespace lsysgen {

char wildcard() {return '_';}

template<typename T>
Table<T>::Table(std::string const& name): name(name), _rules(), _cachedRules() {
    // this->_rules = new std::map<T, std::list<Rule<T> *> *>();
}

template<typename T>
Table<T>::~Table() {
    for (auto el : _rules)
        for (auto r : el.second)
            delete r;
    // for (auto e : _rules)
    //     e.second->clear();
    // _rules.clear();
}

template<typename T>
size_t Table<T>::size() const {
    return _rules.size();
}

template<typename T>
void Table<T>::addRule(Rule<T> * r) {
    auto params = r->lside->content().params;
    int arity = params != nullptr ? params->size() : -1;
    T c = r->leftChar();
    this->addRule(r, c, arity);
}

template<typename T>
void Table<T>::addRule(Rule<T> * r, T c, int arity) {
    auto p = std::make_pair(c, arity);
    auto l = _rules.find(p);
    if (l != _rules.end()) {
        (*l).second.push_back(r);
    } else {
        _rules.emplace(p, std::list<Rule<T> *> {r});
    }
}

template<typename T>
std::list<Rule<T> *> const* Table<T>::rulesFor(T c, int arity) const {
    arity = std::max(arity, 0);
    auto p = std::make_pair(c, arity);
    if (_cachedRules.find(p) != _cachedRules.end()) {
        return &_cachedRules.at(p); // Is cached
    }
    // Is not cached
    auto & rs = _cachedRules[p];
    auto it = _rules.find(p);
    if (it != _rules.end())
        rs.insert(rs.end(), (*it).second.begin(), (*it).second.end());
    it = _rules.find(std::make_pair(c, -1));
    if (it != _rules.end())
        rs.insert(rs.end(), (*it).second.begin(), (*it).second.end());
    it = _rules.find(std::make_pair(wildcard(), arity));
    if (it != _rules.end())
        rs.insert(rs.end(), (*it).second.begin(), (*it).second.end());
    it = _rules.find(std::make_pair(wildcard(), -1));
    if (it != _rules.end())
        rs.insert(rs.end(), (*it).second.begin(), (*it).second.end());
    return &rs;
}

template<typename T>
std::string Table<T>::toString() const {
    std::string ret = "table " + this->name + " {\n";
    for (auto const& e : _rules) {
        for (Rule<T> * r : e.second)
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
