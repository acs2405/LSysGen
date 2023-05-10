
#pragma once


namespace lsysgen {

template<template<typename> typename C, typename T>
class TreeNode;

}

#include "common.h"
#include "NodeContent.h"


namespace lsysgen {

template<template<typename> typename C, typename T>
class TreeNode {
public:
    static int const TYPE_LEAF;
    static int const TYPE_BRANCH;

    // class iterator {
    //  TreeNode<C,T> * n;

    //  iterator();
    //  iterator(TreeNode<C,T> * n);

    // public:
    //  iterator operator++();
    //  TreeNode<C,T> * operator *();
    // };

private:
    C<T> * _content;
    int const _type;
    TreeNode<C,T> * _parent;
    TreeNode<C,T> * _left;
    TreeNode<C,T> * _right;
    TreeNode<C,T> * _leftmostChild;
    TreeNode<C,T> * _rightmostChild;

public:
    TreeNode ();
    TreeNode (T const& element);
    TreeNode (T const& element, int type);
    /*
     * Branch constructor with one element.
     */
    TreeNode (TreeNode * node);
    /*
     * Copy constructor, except it doesn't copy children.
     */
    TreeNode (TreeNode<C,T> const& n);

    ~TreeNode ();

    void addChild(TreeNode<C,T> * child);

    void prune();

    bool isRoot() const;
    bool isLocalLeftmost() const;
    bool isLocalRightmost() const;
    bool isBranch() const;
    bool isLeaf() const;

    // Getters
    TreeNode<C,T> * left() const;
    TreeNode<C,T> * right() const;
    TreeNode<C,T> * parent() const;
    TreeNode<C,T> * leftmostChild() const;
    TreeNode<C,T> * rightmostChild() const;
    C<T>& content();
    C<T> const& content() const;
    T element() const;
    int type() const;

    bool isInstance() const;
    
    TreeNode<NodeContent,T> * asGeneric();
    TreeNode<NodeContent,T> const* asGeneric() const;

    // These functions go upwards when no left/right node is found
    TreeNode<C,T> * nextLeft() const;
    TreeNode<C,T> * nextRight() const;

    // Returns the root node
    TreeNode<C,T> * root();
    TreeNode<C,T> const* root() const;

    // Returns the number of left siblings this node has
    size_t siblingNo() const;
    size_t size() const;

    // TreeNode<C,T> * encapsulate();

    // virtual std::string elementToString();
    std::string toString(TreeNode<C,T> const* markNode=nullptr) const;
    std::string toStringWithContext() const;
};

template<template<typename> typename C, typename T>
std::ostream& operator<<(std::ostream& os, TreeNode<C, T> const& n);

}
