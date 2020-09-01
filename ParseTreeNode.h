
#pragma once


namespace lsysgen {

template<template<typename> typename C, typename T>
class ParseTreeNode;

}

#include "NodeContent.h"

#include <string>
#include <iostream>


namespace lsysgen {

template<template<typename> typename C, typename T>
class ParseTreeNode {
public:
	static const int LEAF = 1;
	static const int BRANCH = 2;

	// class iterator {
	// 	ParseTreeNode<C,T>* n;

	// 	iterator();
	// 	iterator(ParseTreeNode<C,T>* n);

	// public:
	// 	iterator operator++();
	// 	ParseTreeNode<C,T>* operator*();
	// };

private:
	C<T>* _content;
	const int _type;
	ParseTreeNode<C,T>* _parent;
	ParseTreeNode<C,T>* _left;
	ParseTreeNode<C,T>* _right;
	ParseTreeNode<C,T>* _leftmostChild;
	ParseTreeNode<C,T>* _rightmostChild;

public:
	ParseTreeNode ();
	ParseTreeNode (T const& element);
	ParseTreeNode (T const& element, int type);
	ParseTreeNode (ParseTreeNode<C,T>* n);

	~ParseTreeNode ();

	void addChild(ParseTreeNode<C,T>* child);

	bool isRoot() const;
	bool isLocalLeftmost() const;
	bool isLocalRightmost() const;
	bool isBranch() const;
	bool isLeaf() const;

	// Getters
	ParseTreeNode<C,T>* left() const;
	ParseTreeNode<C,T>* right() const;
	ParseTreeNode<C,T>* parent() const;
	ParseTreeNode<C,T>* leftmostChild() const;
	ParseTreeNode<C,T>* rightmostChild() const;
	C<T>* content();
	const C<T>* content() const;
	T element() const;
	int type() const;

	bool isInstance() const;
	
	ParseTreeNode<NodeContent,T>* asGeneric();
	const ParseTreeNode<NodeContent,T>* asGeneric() const;

	// These functions go upwards when no left/right node is found
	ParseTreeNode<C,T>* nextLeft() const;
	ParseTreeNode<C,T>* nextRight() const;

	// Returns the root node
	ParseTreeNode<C,T>* root();
	const ParseTreeNode<C,T>* root() const;

	// Returns the number of left siblings this node has
	int siblingNo() const;
	int size() const;

	ParseTreeNode<C,T>* encapsulate();

	// virtual std::string elementToString();
	std::string toString(const ParseTreeNode<C,T>* markNode=nullptr) const;
	std::string toStringWithContext() const;

	// // Left to right direct children iterator
	// iterator begin();
	// iterator end();
	// // Right to left direct children iterator
	// reverse_iterator rbegin();
	// reverse_iterator rend();
	// // Left to right siblings iterator (including this or not)
	// sibling_iterator sbegin(bool including=true);
	// sibling_iterator send(bool including=true);
	// // Right to left siblings iterator (including this or not)
	// reverse_sibling_iterator rsbegin(bool including=true);
	// reverse_sibling_iterator rsend(bool including=true);
	// // Left to right global iterator (including this or not). This uses nextLeft()
	// global_iterator gbegin(bool including=true);
	// global_iterator gend(bool including=true);
	// // Right to left global iterator (including this or not). This uses nextRight()
	// reverse_global_iterator rgbegin(bool including=true);
	// reverse_global_iterator rgend(bool including=true);

	// Returns a copy of the node with just its content and its type
	// virtual ParseTreeNode<C,T>* copy();
};

}
