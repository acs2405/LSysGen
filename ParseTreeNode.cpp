
#include "ParseTreeNode.h"


namespace lsys {

bool _isVoid(char const& c) {return !c;}
bool _isVoid(std::string const& s) {return !s.size();}



template<template<typename> typename C, typename T>
ParseTreeNode<C,T>::ParseTreeNode(): 
		_content(new C<T>()), _type(ParseTreeNode::BRANCH),
		_parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>::ParseTreeNode(T const& element): 
		_content(new C<T>(element)), _type(_isVoid(element) ? ParseTreeNode::BRANCH : ParseTreeNode::LEAF),
		_parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>::ParseTreeNode(T const& element, int type): 
		_content(new C<T>(element)), _type(type),
		_parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>::ParseTreeNode(ParseTreeNode<C,T>* n): 
		_content(new C<T>(n->_content)), _type(n->_type),
		_parent(nullptr), _left(nullptr), _right(nullptr), _leftmostChild(nullptr), _rightmostChild(nullptr) {}

template<template<typename> typename C, typename T>
ParseTreeNode<C,T>::~ParseTreeNode() {
	// Do not go upwards or back
	// delete this->_right;
	delete this->_leftmostChild;
	delete this->_content;
}

template<template<typename> typename C, typename T>
void ParseTreeNode<C,T>::addChild(ParseTreeNode<C,T>* child) {
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
bool ParseTreeNode<C,T>::isRoot() const {return _parent == nullptr;}
template<template<typename> typename C, typename T>
bool ParseTreeNode<C,T>::isLocalLeftmost() const {return _left == nullptr;}
template<template<typename> typename C, typename T>
bool ParseTreeNode<C,T>::isLocalRightmost() const {return _right == nullptr;}
template<template<typename> typename C, typename T>
bool ParseTreeNode<C,T>::isBranch() const {return _type == ParseTreeNode::BRANCH;}
template<template<typename> typename C, typename T>
bool ParseTreeNode<C,T>::isLeaf() const {return _type == ParseTreeNode::LEAF;}

template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::left() const {return this->_left;}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::right() const {return this->_right;}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::parent() const {return this->_parent;}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::leftmostChild() const {return this->_leftmostChild;}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::rightmostChild() const {return this->_rightmostChild;}
template<template<typename> typename C, typename T>
C<T>* ParseTreeNode<C,T>::content() {return this->_content;}
template<template<typename> typename C, typename T>
const C<T>* ParseTreeNode<C,T>::content() const {return this->_content;}
template<template<typename> typename C, typename T>
T ParseTreeNode<C,T>::element() const {return this->_content != nullptr ? this->_content->element() : '\0';}
template<template<typename> typename C, typename T>
int ParseTreeNode<C,T>::type() const {return this->_type;}

template<template<typename> typename C, typename T>
bool ParseTreeNode<C,T>::isInstance() const {
	return this->_content->isInstance();
}

template<template<typename> typename C, typename T>
const ParseTreeNode<NodeContent,T>* ParseTreeNode<C,T>::asGeneric() const {
	return reinterpret_cast<const ParseTreeNode<NodeContent,T>*>(this);
}
template<template<typename> typename C, typename T>
ParseTreeNode<NodeContent,T>* ParseTreeNode<C,T>::asGeneric() {
	return reinterpret_cast<ParseTreeNode<NodeContent,T>*>(this);
}

template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::nextLeft() const {
	if (this->_left)
		return this->_left;
	if (this->_parent)
		return this->_parent->nextLeft();
	return nullptr;
}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::nextRight() const {
	if (this->_right)
		return this->_right;
	if (this->_parent)
		return this->_parent->nextRight();
	return nullptr;
}
template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::root() {
	if (this->_parent == nullptr)
		return this;
	else
		return this->_parent->root();
}
template<template<typename> typename C, typename T>
const ParseTreeNode<C,T>* ParseTreeNode<C,T>::root() const {
	if (this->_parent == nullptr)
		return this;
	else
		return this->_parent->root();
}
template<template<typename> typename C, typename T>
int ParseTreeNode<C,T>::siblingNo() const {
	if (this->_left == nullptr)
		return 0;
	else
		return this->_left->siblingNo() + 1;
}
template<template<typename> typename C, typename T>
int ParseTreeNode<C,T>::size() const {
	int size = 0;
	for (ParseTreeNode<C,T>* child = this->_leftmostChild; child != nullptr; child = child->_right)
		++size;
	return size;
}

template<template<typename> typename C, typename T>
ParseTreeNode<C,T>* ParseTreeNode<C,T>::encapsulate() {
	ParseTreeNode<C,T>* node = new ParseTreeNode<C,T>();
	node->addChild(this);
	return node;
}

// template<template<typename> typename C, typename T>
// std::string ParseTreeNode<C,T>::contentToString() {
// 	return std::to_string(this->_content);
// }
// Returns the string representing this node and, if it's a branch, its children.
// Marks itself with angle brackets (<>) when markNode is equal to this.
template<template<typename> typename C, typename T>
std::string ParseTreeNode<C,T>::toString(const ParseTreeNode<C,T>* markNode) const {
	std::string ret;
	if (this->isLeaf()) {
		ret += this->_content->toString();
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
std::string ParseTreeNode<C, T>::toStringWithContext() const {
	std::string ret;
	const ParseTreeNode<C,T>* root = this->root();
	for (auto node = root->_leftmostChild; node != nullptr; node = node->_right)
		ret += node->toString(this);
	if (root == this)
		ret = "<" + ret + ">";
	return ret;
}



template class ParseTreeNode<NodeContent, char>;
template class ParseTreeNode<LeftSideNodeContent, char>;
template class ParseTreeNode<RightSideNodeContent, char>;
template class ParseTreeNode<InstanceNodeContent, char>;

}