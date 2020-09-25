
#pragma once


namespace lsysgen {

template<typename T>
class NodeContent;

template<typename T>
class LeftSideNodeContent;

template<typename T>
class RightSideNodeContent;

template<typename T>
class InstanceNodeContent;

}

#include "ParseTreeNode.h"

#include "LSysDParser.h"
#include "values.h"

#include <string>
#include <iostream>
#include <list>
#include <vector>


namespace lsysgen {

template<typename T>
class NodeContent {
    const T _element;

public:
    NodeContent();
    NodeContent(T const& element);
    NodeContent(NodeContent<T> const& content);

public:
    virtual ~NodeContent();

    T element() const;
    virtual bool isInstance() const;
    // bool isVoid() const;

    virtual std::string toString() const;

    // virtual NodeContent<T>& operator=(NodeContent<T> const& p2);
};

template<typename T>
class LeftSideNodeContent : public NodeContent<T> {
public:
    std::list<Parameter *> * params;

    LeftSideNodeContent();
    LeftSideNodeContent(T const& element);
    LeftSideNodeContent(LeftSideNodeContent<T> const& content);

    ~LeftSideNodeContent();

    bool isInstance() const;

    // void setParams(std::list<Parameter *> * params);
    // void setCond(LSysDParser::ExpressionContext * cond);

    // LeftSideNodeContent<T> copy() override;

    std::string toString() const override;

    // LeftSideNodeContent<T>& operator=(LeftSideNodeContent<T> const& p2);
};

template<typename T>
class RightSideNodeContent : public NodeContent<T> {
public:
    std::list<LSysDParser::ExpressionContext *> * args;

    RightSideNodeContent();
    RightSideNodeContent(T const& element);
    RightSideNodeContent(RightSideNodeContent<T> const& content);

    ~RightSideNodeContent();

    bool isInstance () const;

    // RightSideNodeContent<T> * copy() override;

    std::string toString() const override;

    // RightSideNodeContent<T> * eval(std::map<Parameter *, antlrcpp::Any *> * paramMapping);

    // RightSideNodeContent<T>& operator=(RightSideNodeContent<T> const& p2);
};

template<typename T>
class InstanceNodeContent : public NodeContent<T> {
public:
    std::vector<Value> * values;

    InstanceNodeContent();
    InstanceNodeContent(T const& element);
    InstanceNodeContent(InstanceNodeContent<T> const& content);

    ~InstanceNodeContent();

    bool isInstance() const;

    // InstanceNodeContent<T> * copy() override;

    std::string toString() const override;

    // InstanceNodeContent<T> * derive(Table<T> * table, std::list<T> * ignore=nullptr, Environment * env=nullptr);

    // InstanceNodeContent<T> & operator=(InstanceNodeContent<T> const& p2);
};

}
