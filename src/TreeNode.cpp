
#include "TreeNode.h"


namespace lsysgen {

bool _isVoid(char const& c) {return !c;}
bool _isVoid(std::string const& s) {return !s.size();}


template<template<typename> typename C, typename T>
int const TreeNode<C,T>::NO_POS = -1;
// template<template<typename> typename C, typename T>
// int const TreeNode<C,T>::TYPE_LEAF = 1;
// template<template<typename> typename C, typename T>
// int const TreeNode<C,T>::TYPE_BRANCH = 2;


template<template<typename> typename C, typename T>
TreeNode<C,T>::TreeNode(): _parent(nullptr), _pos(TreeNode<C,T>::NO_POS) {}

template<template<typename> typename C, typename T>
TreeNode<C,T>::~TreeNode() {}

// template<template<typename> typename C, typename T>
// bool TreeNode<C,T>::isInstance() const {
//     return this->_content.isInstance();
//     // return dynamic_cast<TreeNode<InstanceNodeContent, T> const*>(this) != nullptr;
//     // return std::is_base_of<InstanceNodeContent<T>, C<T>>::value; //this->_content.isInstance();
// }

// template<>
// bool TreeNode<LeftSideNodeContent,char>::isInstance() const {return false;}

// template<>
// bool TreeNode<RightSideNodeContent,char>::isInstance() const {return false;}

// template<>
// bool TreeNode<InstanceNodeContent,char>::isInstance() const {return true;}

template<template<typename> typename C, typename T>
TreeNode<NodeContent,T> * TreeNode<C,T>::asGeneric() {
    return reinterpret_cast<TreeNode<NodeContent,T> *>(this);
}
template<template<typename> typename C, typename T>
TreeNode<NodeContent,T> const* TreeNode<C,T>::asGeneric() const {
    return reinterpret_cast<TreeNode<NodeContent,T> const*>(this);
}

// template<template<typename> typename C, typename T>
// void TreeBranch<C,T>::addLeaf(C<T> const& content) {
//     _children.emplace_back(content);
//     // TreeLeaf<C,T> newLeaf = _children.back().get();
//     _children.back()->_parent = this;
//     _children.back()->_pos = this->_children.size();
// }

// template<template<typename> typename C, typename T>
// void TreeBranch<C,T>::addBranch() {
//     _children.emplace_back();
//     // TreeBranch<C,T> newBranch = _children.back().get();
//     _children.back()->_parent = this;
//     _children.back()->_pos = this->_children.size();
// }

template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isRoot() const {return _parent == nullptr;}
template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isFirstSibling() const {return _parent == nullptr || _pos == 0;}
template<template<typename> typename C, typename T>
bool TreeNode<C,T>::isLastSibling() const {return _parent == nullptr || _pos == _parent->size() - 1;}

template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::prevSibling() const {
    if (_parent == nullptr)
        return nullptr;
    if (isFirstSibling())
        return nullptr;
    return _parent->children()->at(_pos - 1);
}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::nextSibling() const {
    if (_parent == nullptr)
        return nullptr;
    if (isLastSibling())
        return nullptr;
    return _parent->children()->at(_pos + 1);
}

template<template<typename> typename C, typename T>
TreeBranch<C,T> * TreeNode<C,T>::parent() {return this->_parent;}
template<template<typename> typename C, typename T>
TreeBranch<C,T> const* TreeNode<C,T>::parent() const {return this->_parent;}

template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::prev() const {
    if (!isFirstSibling())
        return prevSibling();
    if (_parent)
        return _parent->prev();
    return nullptr;
}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::next() const {
    if (!isLastSibling())
        return nextSibling();
    if (_parent)
        return _parent->next();
    return nullptr;
}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeNode<C,T>::root() {
    if (_parent == nullptr)
        return this;
    else
        return _parent->root();
}
template<template<typename> typename C, typename T>
TreeNode<C,T> const* TreeNode<C,T>::root() const {
    if (_parent == nullptr)
        return this;
    else
        return _parent->root();
}
template<template<typename> typename C, typename T>
size_t TreeNode<C,T>::siblingNo() const {
    return this->_pos;
}

// template<template<typename> typename C, typename T>
// TreeBranch<C,T> * TreeNode<C,T>::encapsulate() {
//     TreeBranch<C,T> * newParent = new TreeBranch<C,T>();
//     newParent->addChild(this);
//     return newParent;
// }

// Returns the string representing all the nodes from the root, marking the one 
// whose function was called.
template<template<typename> typename C, typename T>
std::string TreeNode<C, T>::toStringWithContext() const {
    return this->root()->toString(this);
    // std::string ret;
    // TreeNode<C,T> const* root = this->root();
    // if (root->isLeaf()) {
    //     // TreeLeaf<C,T> const* rootLeaf = reinterpret_cast<TreeLeaf<C,T> const*>(root);
    //     ret += root->content().toString();
    // } else {
    //     TreeBranch<C,T> const* rootBranch = reinterpret_cast<TreeBranch<C,T> const*>(root);
    //     for (auto const node : *rootBranch->children())
    //         ret += node->toString(this);
    // }
    // if (root == this)
    //     ret = "<" + ret + ">";
    // return ret;
}


template<template<typename> typename C, typename T>
TreeLeaf<C,T>::TreeLeaf(T const& element): TreeNode<C,T>(), _content(element) {}
template<template<typename> typename C, typename T>
TreeLeaf<C,T>::TreeLeaf(TreeLeaf<C,T> const& leaf): TreeNode<C,T>(), _content(leaf._content) {}

template<template<typename> typename C, typename T>
TreeLeaf<C,T>::~TreeLeaf() {}

template<template<typename> typename C, typename T>
bool TreeLeaf<C,T>::isLeaf() const {return true;}
template<template<typename> typename C, typename T>
bool TreeLeaf<C,T>::isBranch() const {return false;}

template<template<typename> typename C, typename T>
C<T> & TreeLeaf<C,T>::content() {return this->_content;}
template<template<typename> typename C, typename T>
C<T> const& TreeLeaf<C,T>::content() const {return this->_content;}
template<template<typename> typename C, typename T>
T TreeLeaf<C,T>::element() const {return this->isLeaf() ? this->_content.element() : 0;}

template<template<typename> typename C, typename T>
bool TreeLeaf<C,T>::isInstance() const {
    return this->_content.isInstance();
}

// Returns the string representing this node and, if it's a branch, its children.
// Marks itself with angle brackets (<>) when markNode is equal to this.
template<template<typename> typename C, typename T>
std::string TreeLeaf<C,T>::toString(TreeNode<C,T> const* markNode) const {
    std::string ret = this->_content.toString();
    // if (markNode)
    //     ret += "{" + std::to_string((int)this->_pos) + "}";
    if (markNode == this)
        return "<" + ret + ">";
    return ret;
}


template<template<typename> typename C, typename T>
TreeBranch<C,T>::TreeBranch(): TreeNode<C,T>(), _children(new std::vector<TreeNode<C,T> *>()), _content() {}
template<template<typename> typename C, typename T>
TreeBranch<C,T>::TreeBranch(TreeNode<C,T> * node): TreeNode<C,T>(), _children(new std::vector<TreeNode<C,T> *>(1, node)), _content() {}

// template<template<typename> typename C, typename T>
// TreeBranch<C,T>::TreeBranch(TreeBranch<C,T> const& branch): TreeBranch() {
//     addChild(branch);
// }

template<template<typename> typename C, typename T>
TreeBranch<C,T>::~TreeBranch() {
    for (auto child : *_children)
        delete child;
    delete _children;
}

template<template<typename> typename C, typename T>
bool TreeBranch<C,T>::isLeaf() const {return false;}
template<template<typename> typename C, typename T>
bool TreeBranch<C,T>::isBranch() const {return true;}

template<template<typename> typename C, typename T>
C<T> & TreeBranch<C,T>::content() {throw std::logic_error("A TreeBranch object has no content");}
template<template<typename> typename C, typename T>
C<T> const& TreeBranch<C,T>::content() const {throw std::logic_error("A TreeBranch object has no content");}
template<template<typename> typename C, typename T>
T TreeBranch<C,T>::element() const {throw std::logic_error("A TreeBranch object has no element");}

template<template<typename> typename C, typename T>
bool TreeBranch<C,T>::isInstance() const {
    return this->_content.isInstance();
}

template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeBranch<C,T>::firstChild() const {return _children->size() > 0 ? _children->front() : nullptr;}
template<template<typename> typename C, typename T>
TreeNode<C,T> * TreeBranch<C,T>::lastChild() const {return _children->size() > 0 ? _children->back() : nullptr;}

template<template<typename> typename C, typename T>
size_t TreeBranch<C,T>::size() const {
    // size_t size = 0;
    // for (TreeNode<C,T> * child = this->_leftmostChild; child != nullptr; child = child->_right)
    //     ++size;
    return this->_children->size();
}

template<template<typename> typename C, typename T>
std::vector<TreeNode<C,T> *> const* TreeBranch<C,T>::children() const {return this->_children;}

template<template<typename> typename C, typename T>
void TreeBranch<C,T>::addChild(TreeNode<C,T> * node) {
    assert(node->_parent == nullptr);
    // std::cerr << "Adding " << node->toString() << " to " << this->toString(node) << ": ";
    if (_children->capacity() == _children->size())
        _children->reserve(2*_children->capacity());
    node->_parent = this;
    node->_pos = _children->size();
    _children->push_back(node); // Use emplace_back(args...) when possible
    // std::cerr << this->toString(node) << std::endl;
}

template<template<typename> typename C, typename T>
void TreeBranch<C,T>::reserve(size_t n) {
    _children->reserve(n);
}

template<template<typename> typename C, typename T>
void TreeBranch<C,T>::transferChildrenTo(TreeBranch<C,T> * target) {
    target->_children->reserve(target->_children->capacity() + this->_children->capacity());
    for (auto const child : *_children) {
        child->_parent = target;
        child->_pos = target->_children->size();
        target->_children->push_back(child);
    }
    _children->clear();
}

template<template<typename> typename C, typename T>
void TreeBranch<C,T>::prune() {
    for (auto const child : *_children) {
        child->_parent = nullptr;
        child->_pos = TreeNode<C,T>::NO_POS;
    }
    _children->clear();
}

template<template<typename> typename C, typename T>
std::string TreeBranch<C,T>::toString(TreeNode<C,T> const* markNode) const {
    std::string ret;
    for (auto const node : *_children)
        ret += node->toString(markNode);
    if (!this->isRoot())
        ret = "[" + ret + "]";
    // if (markNode)
    //     ret += "{" + std::to_string((int)this->_pos) + ", " + std::to_string(this->size()) + "}";
    if (markNode == this)
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

template class TreeLeaf<NodeContent, char>;
template class TreeLeaf<LeftSideNodeContent, char>;
template class TreeLeaf<RightSideNodeContent, char>;
template class TreeLeaf<InstanceNodeContent, char>;

template class TreeBranch<NodeContent, char>;
template class TreeBranch<LeftSideNodeContent, char>;
template class TreeBranch<RightSideNodeContent, char>;
template class TreeBranch<InstanceNodeContent, char>;

template std::ostream& operator<<(std::ostream& os, const TreeNode<NodeContent, char>& n);
template std::ostream& operator<<(std::ostream& os, const TreeNode<LeftSideNodeContent, char>& n);
template std::ostream& operator<<(std::ostream& os, const TreeNode<RightSideNodeContent, char>& n);
template std::ostream& operator<<(std::ostream& os, const TreeNode<InstanceNodeContent, char>& n);

}
