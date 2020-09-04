
#include "NodeContent.h"

#include <utility>


namespace lsysgen {

std::string _elementToStr(char c) {return std::string(1, c);}
std::string _elementToStr(std::string s) {return s;}


template<typename T>
NodeContent<T>::NodeContent():
        _element(0) {}
template<typename T>
NodeContent<T>::NodeContent(T const& element):
        _element(element) {}
template<typename T>
NodeContent<T>::NodeContent(NodeContent<T>* content):
        _element(content->_element) {}
// template NodeContent<char>::NodeContent(NodeContent<char>* content);

template<typename T>
NodeContent<T>::~NodeContent() {}

template<typename T>
T NodeContent<T>::element() const {return this->_element;}

template<typename T>
bool NodeContent<T>::isInstance() const {
    return false;
}

// template<typename T>
// bool NodeContent<T>::isVoid() const {return _isVoid(this->_element);}

template<typename T>
std::string NodeContent<T>::toString() const {
    return _elementToStr(this->_element);
}

// virtual NodeContent<T>& NodeContent<T>::operator=(NodeContent<T> const& p2) {
//     this->_element = p2._element;
//     return *this;
// }



template<typename T>
LeftSideNodeContent<T>::LeftSideNodeContent(): NodeContent<T>() {}
template<typename T>
LeftSideNodeContent<T>::LeftSideNodeContent(T const& element):
        NodeContent<T>(element), params(nullptr), cond(nullptr) {}
template<typename T>
LeftSideNodeContent<T>::LeftSideNodeContent(LeftSideNodeContent<T>* content):
        NodeContent<T>(content->element()), params(content->params), cond(content->cond) {}

template<typename T>
LeftSideNodeContent<T>::~LeftSideNodeContent() {
    if (this->params != nullptr) {
        this->params->clear();
        delete this->params;
    }
}

template<typename T>
bool LeftSideNodeContent<T>::isInstance() const {
    return false;
}

// template<typename T>
// LeftSideNodeContent<T>* LeftSideNodeContent<T>::copy() {
//     LeftSideParseTreeNode<T>* node = new LeftSideParseTreeNode();
//     node->cond = this->cond;
//     node->params = this->params;
//     return node;
// }

template<typename T>
std::string LeftSideNodeContent<T>::toString() const {
    std::string ret;
    if (this->params) {
        ret += "(";
        for (auto param = this->params->begin(); param != this->params->end(); ++param) {
            if (param != this->params->begin())
                ret += ",";
            ret += (*param)->name;
        }
        if (this->cond)
            ret += "|" + this->cond->getText();
        ret += ")";
    }
    return this->element() + ret;
}

// LeftSideNodeContent<T>& LeftSideNodeContent<T>::operator=(LeftSideNodeContent<T> const& p2) {
//     LeftSideNodeContent<T>::operator=(p2);
//     this->params = p2.params;
//     this->cond = p2.cond;
//     return *this;
// }



template<typename T>
RightSideNodeContent<T>::RightSideNodeContent(): NodeContent<T>() {}
template<typename T>
RightSideNodeContent<T>::RightSideNodeContent(T const& element):
        NodeContent<T>(element), args(nullptr) {}
template<typename T>
RightSideNodeContent<T>::RightSideNodeContent(RightSideNodeContent<T>* content):
        NodeContent<T>(content->element()), args(content->args) {}

template<typename T>
RightSideNodeContent<T>::~RightSideNodeContent() {
    delete this->args;
}

template<typename T>
bool RightSideNodeContent<T>::isInstance() const {
    return false;
}

template<typename T>
std::string RightSideNodeContent<T>::toString() const {
    std::string ret;
    if (this->args) {
        ret += "(";
        for (auto arg = this->args->begin(); arg != this->args->end(); ++arg) {
            if (arg != this->args->begin())
                ret += ",";
            ret += (*arg)->getText();
        }
        ret += ")";
    }
    return this->element() + ret;
}

// RightSideNodeContent<T>& RightSideNodeContent<T>::operator=(RightSideNodeContent<T> const& p2) {
//     RightSideNodeContent<T>::operator=(p2);
//     this->args = p2.args;
//     return *this;
// }



template<typename T>
InstanceNodeContent<T>::InstanceNodeContent(): NodeContent<T>() {}
template<typename T>
InstanceNodeContent<T>::InstanceNodeContent(T const& element):
        NodeContent<T>(element), values(nullptr) {}
template<typename T>
InstanceNodeContent<T>::InstanceNodeContent(InstanceNodeContent<T>* content):
        NodeContent<T>(content->element()), values(content->values) {}

template<typename T>
InstanceNodeContent<T>::~InstanceNodeContent() {
    delete this->values;
}

template<typename T>
bool InstanceNodeContent<T>::isInstance() const {
    return true;
}

template<typename T>
std::string InstanceNodeContent<T>::toString() const {
    std::string ret;
    if (this->values) {
        ret += "(";
        for (auto value = this->values->begin(); value != this->values->end(); ++value) {
            if (value != this->values->begin())
                ret += ",";
            ret += (*value).toString();
        }
        ret += ")";
    }
    return this->element() + ret;
}

// InstanceNodeContent<T>& InstanceNodeContent<T>::operator=(InstanceNodeContent<T> const& p2) {
//     InstanceNodeContent<T>::operator=(p2);
//     this->values = p2.values;
//     return *this;
// }



template class NodeContent<char>;
template class LeftSideNodeContent<char>;
template class RightSideNodeContent<char>;
template class InstanceNodeContent<char>;
// template class LeftSideNodeContent<std::string>;
// template class RightSideNodeContent<std::string>;
// template class InstanceNodeContent<std::string>;

}
