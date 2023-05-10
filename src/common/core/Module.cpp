
#include "Module.h"

// #include <regex>
#include <misc.h>


namespace lsysgen {

template<typename T>
Module<T>::Module(std::string_view name): _name(name), //_settings(settings), 
        _scope(nullptr), _mainLSystem(nullptr), _lsystems(), eh(nullptr) {}

// template<typename T>
// Module<T>::Module(): _scope() {}

template<typename T>
Module<T>::~Module() {
    _lsystems.clear();
    delete _scope;
    delete _evaluator;
    delete eh;
}

template<typename T>
ErrorHandler * Module<T>::messages() {return this->eh;}

template<typename T>
LSysDExpressionEvaluator * Module<T>::evaluator() {return this->_evaluator;}

// template<typename T>
// Settings const* Module<T>::settings() const {return this->_settings;}

template<typename T>
Scope * Module<T>::scope() {return this->_scope;}

template<typename T>
std::string const& Module<T>::name() const {return this->_name;}

template<typename T>
LSystem<T> * Module<T>::mainLSystem() {return this->_mainLSystem;}



template class Module<char>;

}
