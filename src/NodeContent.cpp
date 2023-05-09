
#include "NodeContent.h"

#include <utility>


namespace lsysgen {

std::string _elementToStr(char c) {return std::string(1, c);}
std::string _elementToStr(std::string s) {return s;}


template<typename T>
NodeContent<T>::NodeContent():
        _element(0), _v(nullptr) {}
template<typename T>
NodeContent<T>::NodeContent(T const& element):
        _element(element), _v(nullptr) {}
template<typename T>
NodeContent<T>::NodeContent(NodeContent<T> const& content):
        _element(content._element) {
    if (content._v)
        this->_v = new std::vector<void *>(*content._v);
    else
        this->_v = nullptr;
}
// template NodeContent<char>::NodeContent(NodeContent<char> * content);

template<typename T>
NodeContent<T>::~NodeContent() {}

template<typename T>
T NodeContent<T>::element() const {return this->_element;}

template<typename T>
bool NodeContent<T>::isInstance() const {
    return false;
}

template<typename T>
void NodeContent<T>::createV() {
    assert(this->_v == nullptr);
    this->_v = new std::vector<void *>();
}

template<typename T>
std::vector<void *> * NodeContent<T>::v() {
    return this->_v;
}
template<typename T>
std::vector<void *> const* NodeContent<T>::v() const {
    return this->_v;
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
LeftSideNodeContent<T>::LeftSideNodeContent(): 
        NodeContent<T>() {}
template<typename T>
LeftSideNodeContent<T>::LeftSideNodeContent(T const& element):
        NodeContent<T>(element) {}
template<typename T>
LeftSideNodeContent<T>::LeftSideNodeContent(LeftSideNodeContent<T> const& content):
        NodeContent<T>(content) {
    // if (content.params)
    //     this->params = new std::vector<Parameter *>(*content.params);
    // else
    //     this->params = nullptr;
}

template<typename T>
LeftSideNodeContent<T>::~LeftSideNodeContent() {
    // if (this->params != nullptr) {
    //     this->params->clear();
    delete this->params();
    // }
}

template<typename T>
bool LeftSideNodeContent<T>::isInstance() const {
    return false;
}

template<typename T>
void LeftSideNodeContent<T>::createParams() {
    this->createV();
}

template<typename T>
std::vector<Parameter *> * LeftSideNodeContent<T>::params() {
    return reinterpret_cast<std::vector<Parameter *> *>(this->_v);
}
template<typename T>
std::vector<Parameter *> const* LeftSideNodeContent<T>::params() const {
    return reinterpret_cast<std::vector<Parameter *> *>(this->_v);
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
    if (this->params()) {
        ret += "(";
        // ret += *this->params() | std::views::transform([](auto& param) {return param->name;}) | std::views::join_with(", ");
        for (auto param = this->params()->begin(); param != this->params()->end(); ++param) {
            if (param != this->params()->begin())
                ret += ",";
            ret += (*param)->name;
        }
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
RightSideNodeContent<T>::RightSideNodeContent(): 
        NodeContent<T>() {}
template<typename T>
RightSideNodeContent<T>::RightSideNodeContent(T const& element):
        NodeContent<T>(element) {}
template<typename T>
RightSideNodeContent<T>::RightSideNodeContent(RightSideNodeContent<T> const& content):
        NodeContent<T>(content) {
    // if (content.args)
    //     this->args = new std::vector<LSysDParser::ExpressionContext *>(*content.args);
    // else
    //     this->args = nullptr;
}

template<typename T>
RightSideNodeContent<T>::~RightSideNodeContent() {
    delete this->args();
}

template<typename T>
bool RightSideNodeContent<T>::isInstance() const {
    return false;
}

template<typename T>
void RightSideNodeContent<T>::createArgs() {
    this->createV();
}

template<typename T>
std::vector<LSysDParser::ExpressionContext *> * RightSideNodeContent<T>::args() {
    return reinterpret_cast<std::vector<LSysDParser::ExpressionContext *> *>(this->_v);
}
template<typename T>
std::vector<LSysDParser::ExpressionContext *> const* RightSideNodeContent<T>::args() const {
    return reinterpret_cast<std::vector<LSysDParser::ExpressionContext *> *>(this->_v);
}

template<typename T>
std::string RightSideNodeContent<T>::toString() const {
    std::string ret;
    if (this->args()) {
        ret += "(";
        // ret += *this->args() | std::views::transform([](auto& arg) {return arg->getText();}) | std::views::join_with(", ");
        for (auto arg = this->args()->begin(); arg != this->args()->end(); ++arg) {
            if (arg != this->args()->begin())
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
InstanceNodeContent<T>::InstanceNodeContent(): 
        NodeContent<T>() {}
template<typename T>
InstanceNodeContent<T>::InstanceNodeContent(T const& element):
        NodeContent<T>(element) {}
template<typename T>
InstanceNodeContent<T>::InstanceNodeContent(InstanceNodeContent<T> const& content):
        NodeContent<T>(content) {
    // if (content.values) {
    //     this->values = new std::vector<Value>(*content.values);
    // } else
    //     this->values = nullptr;
}

template<typename T>
InstanceNodeContent<T>::~InstanceNodeContent() {
        // std::cerr << "HERE deleting node content of " << this->element() << std::endl;
        // std::cerr << values << std::endl;if(values!=nullptr)
        // std::cerr << values->size() << std::endl;
    delete this->values();
}

template<typename T>
bool InstanceNodeContent<T>::isInstance() const {
    return true;
}

template<typename T>
void InstanceNodeContent<T>::createValues() {
    this->createV();
}

template<typename T>
std::vector<Value> * InstanceNodeContent<T>::values() {
    return reinterpret_cast<std::vector<Value> *>(this->_v);
}
template<typename T>
std::vector<Value> const* InstanceNodeContent<T>::values() const {
    return reinterpret_cast<std::vector<Value> *>(this->_v);
}

template<typename T>
std::string InstanceNodeContent<T>::toString() const {
    std::string ret;
    if (this->values()) {
        ret += "(";
        // ret += *this->values() | std::views::transform([](auto& v) {return v.toString();}) | std::views::join_with(", ");
        for (auto value = this->values()->begin(); value != this->values()->end(); ++value) {
            if (value != this->values()->begin())
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
