
#pragma once


#include "common.h"
#include "LSystem.h"
#include "TreeNode.h"
// #include "NodeContent.h"


class Point2D {
public:
    float x;
    float y;

    Point2D();
    Point2D(float x, float y);

    std::string toString() const;
};

struct Color {
    float r;
    float g;
    float b;
    float a;

    Color(float r, float g, float b, float a=1.0);
    Color(std::string const& color);
    Color();

    void parse(std::string const& s);
    Color rgb() const;
    std::string toString() const;
    std::string alpha() const;
};

class State2D {
public:
    // float x;
    // float y;
    Point2D pos;
    float dir;
    Color penColor;
    Color fillColor;
    float lineWidth;
    // bool filling;

    State2D();
};

class Bounds2D {
public:
    Point2D p0;
    Point2D p1;

    Bounds2D();
};

// class Command2D {
// protected:
//  Command2D(int type);

// public:
//  static int TYPE_MOVETO = 1;
//  static int TYPE_LINETO = 2;
//  static int TYPE_CLOSE = 3;

//  list<Point2D> points;
//  int type;
// };

// class Line2D: public Command2D {
// public:
//  Line2D(Point2D from, Point2D to);
// };
// class Move2D: public Command2D {
// public:
//  Move2D(Point2D from, Point2D to);
// };
// class Close2D: public Command2D {
// public:
//  Close2D();
// };

// class Shape2D {
// public:
//  static const MODE_STROKE = 1;
//  static const MODE_FILL = 2;

//  list<Point2D> points;
//  int mode;

//  Shape2D();
//  Shape2D(int mode);
// };

std::string node2svg(
        lsysgen::TreeNode<lsysgen::InstanceNodeContent, char>* parent, 
        lsysgen::LSystem<char>* lsystem=nullptr);

std::string node2svg(
        lsysgen::TreeNode<lsysgen::InstanceNodeContent, char>* parent, 
        State2D& state, 
        Bounds2D &bounds, 
        lsysgen::LSystem<char>* lsystem);

