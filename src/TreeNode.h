
#pragma once

/*

Notas:
- Usar std::optional<T> para un objeto (no puntero) que puede tener valor o no (no usa punteros)
- Usar std::unique_ptr<T> solo para objetos cuya propiedad haya que transferir (se crean con std::make_unique y 
se pasan a funciones con std::move)
- Usar noexcept o noexcept(cond) al final de la signatura de las funciones
- Modules y generators

*/

namespace lsysgen {

template<template<typename> typename C, typename T>
class TreeNode;

template<template<typename> typename C, typename T>
class TreeLeaf;

template<template<typename> typename C, typename T>
class TreeBranch;

}

#include "common.h"
#include "NodeContent.h"


namespace lsysgen {

template<template<typename> typename C, typename T>
class TreeNode {
public:
    static int const NO_POS;
    // static int const TYPE_LEAF;
    // static int const TYPE_BRANCH;

    // class iterator {
    //  TreeNode<C,T> * n;

    //  iterator();
    //  iterator(TreeNode<C,T> * n);

    // public:
    //  iterator operator++();
    //  TreeNode<C,T> * operator *();
    // };

protected:
    // C<T> _content;
    // int const _type;
    TreeBranch<C,T> * _parent;
    size_t _pos;
    // TreeNode<C,T> * _left;
    // TreeNode<C,T> * _right;
    // TreeNode<C,T> * _leftmostChild;
    // TreeNode<C,T> * _rightmostChild;

protected:
    TreeNode ();
    TreeNode (T const& element);
    TreeNode (TreeNode<C,T> const& node);

public:
    // TreeNode () = nullptr;
    // TreeNode (T const& element);
    // TreeNode (T const& element, int type);
    // TreeNode (TreeNode<C,T> const& n);

    virtual ~TreeNode ();

    // virtual void addChild(std::unique_ptr<TreeNode<C,T>> child) = 0;

    // virtual void prune() = 0;

    bool isRoot() const;
    bool isFirstSibling() const;
    bool isLastSibling() const;
    virtual bool isLeaf() const = 0;
    virtual bool isBranch() const = 0;

    // Getters
    // virtual TreeNode<C,T> * first() const = 0;
    // virtual TreeNode<C,T> * last() const = 0;
    virtual C<T> & content() = 0;
    virtual C<T> const& content() const = 0;
    virtual T element() const = 0;

    virtual bool isInstance() const = 0;
    
    TreeNode<NodeContent,T> * asGeneric();
    TreeNode<NodeContent,T> const* asGeneric() const;

    TreeNode<C,T> * prevSibling() const;
    TreeNode<C,T> * nextSibling() const;

    // These functions go upwards when no left/right node is found
    TreeNode<C,T> * prev() const;
    TreeNode<C,T> * next() const; // Does not make sense

    // Returns the root node
    TreeBranch<C,T> * parent();
    TreeBranch<C,T> const* parent() const;
    TreeNode<C,T> * root();
    TreeNode<C,T> const* root() const;
    // TreeBranch<C,T> * encapsulate();

    // Returns the number of left siblings this node has
    size_t siblingNo() const;
    // virtual size_t size() const = 0;

    // virtual std::string elementToString();
    virtual std::string toString(TreeNode<C,T> const* markNode=nullptr) const = 0;
    std::string toStringWithContext() const;

    // friend void TreeBranch<C,T>::addChild(std::unique_ptr<TreeNode<C,T>> node);
    friend TreeBranch<C,T>;
};

template<template<typename> typename C, typename T>
class TreeLeaf: public TreeNode<C, T> {
private:
    C<T> _content;

public:
    TreeLeaf (T const& element);
    TreeLeaf (TreeLeaf<C,T> const& leaf);

    ~TreeLeaf();

    bool isBranch() const;
    bool isLeaf() const;

    C<T> & content();
    C<T> const& content() const;
    T element() const;

    bool isInstance() const;

    std::string toString(TreeNode<C,T> const* markNode=nullptr) const;
};

template<template<typename> typename C, typename T>
class TreeBranch: public TreeNode<C, T> {
private:
    std::vector<TreeNode<C,T> *> * _children;
    C<T> _content;

public:
    TreeBranch ();
    TreeBranch (TreeNode<C,T> * node);

    ~TreeBranch();

    bool isBranch() const;
    bool isLeaf() const;

    C<T> & content();
    C<T> const& content() const;
    T element() const;

    bool isInstance() const;

    TreeNode<C,T> * firstChild() const;
    TreeNode<C,T> * lastChild() const;
    size_t size() const;

    std::vector<TreeNode<C,T> *> const* children() const;

    void addChild(TreeNode<C,T> * child);
    void reserve(size_t n);

    void transferChildrenTo(TreeBranch<C,T> * target);
    void prune();

    std::string toString(TreeNode<C,T> const* markNode=nullptr) const;
};

template<template<typename> typename C, typename T>
std::ostream& operator<<(std::ostream& os, TreeNode<C, T> const& n);

}