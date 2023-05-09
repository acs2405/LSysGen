
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

#include "common.h"
#include "LSysDParser.h"
#include "TreeNode.h"
#include "values.h"


namespace lsysgen {

template<typename T>
class NodeContent {
private:
    const T _element;

protected:
    std::vector<void *> * _v;

protected:
    NodeContent();
    NodeContent(T const& element);
    NodeContent(NodeContent<T> const& content);

protected:
    void createV();
    std::vector<void *> * v();
    std::vector<void *> const* v() const;

public:
    virtual ~NodeContent();

    T element() const;
    virtual bool isInstance() const;
    // bool isVoid() const;

    virtual std::string toString() const;

    // virtual NodeContent<T>& operator=(NodeContent<T> const& p2);

    friend TreeNode<NodeContent, T>;
    friend TreeLeaf<NodeContent, T>;
    friend TreeBranch<NodeContent, T>;
};

template<typename T>
class LeftSideNodeContent : public NodeContent<T> {
public:
    // std::vector<Parameter *> * params;

    LeftSideNodeContent();
    LeftSideNodeContent(T const& element);
    LeftSideNodeContent(LeftSideNodeContent<T> const& content);

    ~LeftSideNodeContent();

    bool isInstance() const;

    void createParams();
    std::vector<Parameter *> * params();
    std::vector<Parameter *> const* params() const;

    // void setParams(std::vector<Parameter *> * params);
    // void setCond(LSysDParser::ExpressionContext * cond);

    // LeftSideNodeContent<T> copy() override;

    std::string toString() const override;

    // LeftSideNodeContent<T>& operator=(LeftSideNodeContent<T> const& p2);
};

template<typename T>
class RightSideNodeContent : public NodeContent<T> {
public:
    // std::vector<LSysDParser::ExpressionContext *> * args;

    RightSideNodeContent();
    RightSideNodeContent(T const& element);
    RightSideNodeContent(RightSideNodeContent<T> const& content);

    ~RightSideNodeContent();

    bool isInstance () const;

    void createArgs();
    std::vector<LSysDParser::ExpressionContext *> * args();
    std::vector<LSysDParser::ExpressionContext *> const* args() const;

    // RightSideNodeContent<T> * copy() override;

    std::string toString() const override;

    // RightSideNodeContent<T> * eval(std::map<Parameter *, antlrcpp::Any *> * paramMapping);

    // RightSideNodeContent<T>& operator=(RightSideNodeContent<T> const& p2);
};

template<typename T>
class InstanceNodeContent : public NodeContent<T> {
public:
    // std::vector<Value> * values;

    InstanceNodeContent();
    InstanceNodeContent(T const& element);
    InstanceNodeContent(InstanceNodeContent<T> const& content);

    ~InstanceNodeContent();

    bool isInstance() const;

    void createValues();
    std::vector<Value> * values();
    std::vector<Value> const* values() const;

    // InstanceNodeContent<T> * copy() override;

    std::string toString() const override;

    // InstanceNodeContent<T> * derive(Table<T> * table, std::vector<T> * ignore=nullptr, Environment * env=nullptr);

    // InstanceNodeContent<T> & operator=(InstanceNodeContent<T> const& p2);
};

}
