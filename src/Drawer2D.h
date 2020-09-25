
#pragma once


namespace lsysgen {

class Drawer2D;

}

#include "lsysgen.h"
#include "interpreter2D.h"

#if defined(__linux) || defined(__linux__) || defined(linux)
#define LINUX
#include <GL/glut.h>
#elif defined(__APPLE__)
#define MACOS
#include <GLUT/glut.h>
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#define WINDOWS
#include <GL/glut.h>
#endif

#include <string>
#include <iostream>


namespace lsysgen {

// struct Color {
//  float r;
//  float g;
//  float b;
//  float a;

//  Color(float r, float g, float b, float a=1.0);
//  Color();
// };

// class Point2D {
// public:
//  float x;
//  float y;
// };

// class State2D {
// public:
//  float x;
//  float y;
//  double dir;
//  Color penColor;
//  Color fillColor;
//  // bool filling;

//  State2D();
// };

class Drawer2D {
    LSystem<char>* lsystem;

    void drawBranch(ParseTreeNode<InstanceNodeContent, char>* parent, State2D& state);
    
public:
    Drawer2D(LSystem<char>* lsystem);

    void prepare(int argc, char** argv);
    void display();
    void draw();

    void reshape(GLsizei width, GLsizei height);
    void click(int button, int state, int x, int y);
    void specialKeyPressed(int key, int x, int y);
    void keyPressed(unsigned char key, int x, int y);
};

}
