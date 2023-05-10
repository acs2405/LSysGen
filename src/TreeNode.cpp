
#include "TreeNode.h"


namespace lsysgen {

bool _isVoid(char const& c) {return !c;}
bool _isVoid(std::string const& s) {return !s.size();}


template<template<typename> typename C, typename T>
int const TreeNode<C,T>::TYPE_LEAF = 1;
template<template<typename> typename C, typename T>
int const TreeNode<C,T>::TYPE_BRANCH = 2;


template<template<typename> typename C, typename T>
TreeNode<C,T>::TreeNode(): 
        _content(new C<T>()), _type(TreeNode::TYPE_BRANCH),
        _parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}
template<template<typename> typename C, typename T>
TreeNode<C,T>::TreeNode(T const& element): 
        _content(new C<T>(element)), _type(_isVoid(element) ? TreeNode::TYPE_BRANCH : TreeNode::TYPE_LEAF),
        _parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}
template<template<typename> typename C, typename T>
TreeNode<C,T>::TreeNode(T const& element, int type): 
        _content(new C<T>(element)), _type(type),
        _parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}
template<template<typename> typename C, typename T>
TreeNode<C,T>::TreeNode(TreeNode<C,T> const& n): 
        _content(new C<T>(*n._content)), _type(n._type),
        _parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}

template<template<typename> typename C, typename T>
TreeNode<C,T>::~TreeNode() {
    TreeNode<C,T> * nodeNext;
    for (auto node = _leftmostChild; node != nullptr; node = nodeNext) {
        nodeNext = node->_right;
        delete node;
    }
    delete _content;
}

template<template<typename> typename C, typename T>
void TreeNode<C,T>::addChild(TreeNode<C,T> * child) {
    child->_parent = this;
    if (this->_leftmostChild == nullptr)
        this->_leftmostChild = child;
    else {
        this->_rightmostChild->_right = child;
        child->_left = this->_rightmostChild;
    }
    this->_rightmostChild = child;
}

template<template<typename> typename C, typename T>
void TreeNode<C,T>::prune() {
    this->_leftmostChild = nullptr;
    this->_rightmostChild = nullptr;
}

template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isRoot() const {return _parent == nullptr;}
template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isLocalLeftmost() const {return _left == nullptr;}
template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isLocalRightmost() const {return _right == nullptr;}
template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isBranch() const {return _type == TreeNode::TYPE_BRANCH;}
template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isLeaf() const {return _type == TreeNode::TYPE_LEAF;}

template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::left() const {return this->_left;}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::right() const {return this->_right;}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::parent() const {return this->_parent;}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::leftmostChild() const {return this->_leftmostChild;}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::rightmostChild() const {return this->_rightmostChild;}

template<template<typename> typename C, typename T>
C<T> & TreeNode<C,T>::content() {return *this->_content;}
template<template<typename> typename C, typename T>
C<T> const& TreeNode<C,T>::content() const {return *this->_content;}
template<template<typename> typename C, typename T>
T TreeNode<C,T>::element() const {return this->isLeaf() ? this->_content->element() : 0;}
template<template<typename> typename C, typename T>
int TreeNode<C,T>::type() const {return this->_type;}

template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isInstance() const {
    return this->_content->isInstance();
}

template<template<typename> typename C, typename T>
TreeNode<NodeContent,T> const* TreeNode<C,T>::asGeneric() const {
    return reinterpret_cast<TreeNode<NodeContent,T> const*>(this);
}
template<template<typename> typename C, typename T>
TreeNode<NodeContent,T> * TreeNode<C,T>::asGeneric() {
    return reinterpret_cast<TreeNode<NodeContent,T> *>(this);
}

template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::nextLeft() const {
    if (this->_left)
        return this->_left;
    if (this->_parent)
        return this->_parent->nextLeft();
    return nullptr;
}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::nextRight() const {
    if (this->_right)
        return this->_right;
    if (this->_parent)
        return this->_parent->nextRight();
    return nullptr;
}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::root() {
    if (this->_parent == nullptr)
        return this;
    else
        return this->_parent->root();
}
template<template<typename> typename C, typename T>
TreeNode<C,T> const* TreeNode<C,T>::root() const {
    if (this->_parent == nullptr)
        return this;
    else
        return this->_parent->root();
}
template<template<typename> typename C, typename T>
size_t TreeNode<C,T>::siblingNo() const {
    if (this->_left == nullptr)
        return 0;
    else
        return this->_left->siblingNo() + 1;
}
template<template<typename> typename C, typename T>
size_t TreeNode<C,T>::size() const {
    size_t size = 0;
    for (TreeNode<C,T> * child = this->_leftmostChild; child != nullptr; child = child->_right)
        ++size;
    return size;
}

template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::encapsulate() {
    TreeNode<C,T> * node = new TreeNode<C,T>();
    node->addChild(this);
    return node;
}

// Returns the string representing this node and, if it's a branch, its children.
// Marks itself with angle brackets (<>) when markNode is equal to this.
template<template<typename> typename C, typename T>
std::string TreeNode<C,T>::toString(TreeNode<C,T> const* markNode) const {
    std::string ret;
    if (this->isLeaf()) {
        ret += _content->toString();
    } else {
        std::string children;
        for (auto node = _leftmostChild; node != nullptr; node = node->_right)
            children += node->toString(markNode);
        ret = this->isRoot() ? children : "[" + children + "]";
    }
    if (markNode == this)
        ret = "<" + ret + ">";
    return ret;
}
// Returns the string representing all the nodes from the root, marking the one 
// whose function was called.
template<template<typename> typename C, typename T>
std::string TreeNode<C, T>::toStringWithContext() const {
    std::string ret;
    TreeNode<C,T> const* root = this->root();
    for (auto node = root->_leftmostChild; node != nullptr; node = node->_right)
        ret += node->toString(this);
    if (root == this)
        ret = "<" + ret + ">";
    return ret;
}

template<template<typename> typename C, typename T>
std::ostream& operator<<(std::ostream& os, const TreeNode<C, T>& n) {
    return os << n.toString();
}



template class TreeNode<NodeContent, char>;
template class TreeNode<LeftSideNodeContent, char>;
template class TreeNode<RightSideNodeContent, char>;
template class TreeNode<InstanceNodeContent, char>;

template std::ostream& operator<<(std::ostream& os, const TreeNode<NodeContent, char>& n);
template std::ostream& operator<<(std::ostream& os, const TreeNode<LeftSideNodeContent, char>& n);
template std::ostream& operator<<(std::ostream& os, const TreeNode<RightSideNodeContent, char>& n);
template std::ostream& operator<<(std::ostream& os, const TreeNode<InstanceNodeContent, char>& n);

}
