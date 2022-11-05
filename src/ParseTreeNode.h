
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
    static int const TYPE_LEAF;
    static int const TYPE_BRANCH;

    // class iterator {
    //  ParseTreeNode<C,T> * n;

    //  iterator();
    //  iterator(ParseTreeNode<C,T> * n);

    // public:
    //  iterator operator++();
    //  ParseTreeNode<C,T> * operator *();
    // };

private:
    C<T> * _content;
    int const _type;
    ParseTreeNode<C,T> * _parent;
    ParseTreeNode<C,T> * _left;
    ParseTreeNode<C,T> * _right;
    ParseTreeNode<C,T> * _leftmostChild;
    ParseTreeNode<C,T> * _rightmostChild;

public:
    ParseTreeNode ();
    ParseTreeNode (T const& element);
    ParseTreeNode (T const& element, int type);
    ParseTreeNode (ParseTreeNode<C,T> const& n);

    ~ParseTreeNode ();

    void addChild(ParseTreeNode<C,T> * child);

    void prune();

    bool isRoot() const;
    bool isLocalLeftmost() const;
    bool isLocalRightmost() const;
    bool isBranch() const;
    bool isLeaf() const;

    // Getters
    ParseTreeNode<C,T> * left() const;
    ParseTreeNode<C,T> * right() const;
    ParseTreeNode<C,T> * parent() const;
    ParseTreeNode<C,T> * leftmostChild() const;
    ParseTreeNode<C,T> * rightmostChild() const;
    C<T>& content();
    C<T> const& content() const;
    T element() const;
    int type() const;

    bool isInstance() const;
    
    ParseTreeNode<NodeContent,T> * asGeneric();
    ParseTreeNode<NodeContent,T> const* asGeneric() const;

    // These functions go upwards when no left/right node is found
    ParseTreeNode<C,T> * nextLeft() const;
    ParseTreeNode<C,T> * nextRight() const;

    // Returns the root node
    ParseTreeNode<C,T> * root();
    ParseTreeNode<C,T> const* root() const;

    // Returns the number of left siblings this node has
    size_t siblingNo() const;
    size_t size() const;

    ParseTreeNode<C,T> * encapsulate();

    // virtual std::string elementToString();
    std::string toString(ParseTreeNode<C,T> const* markNode=nullptr) const;
    std::string toStringWithContext() const;
};

template<template<typename> typename C, typename T>
std::ostream& operator<<(std::ostream& os, ParseTreeNode<C, T> const& n);

}
