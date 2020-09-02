
#pragma once


namespace lsysgen {

class color;

class Point2D;

class State2D;

class Drawer2D;

}

#include "LSystem.h"

#include <GL/glut.h>
#include <string>
#include <iostream>


namespace lsysgen {

struct color_t {
	char r;
	char g;
	char b;
	char a;
};

class Point2D {
public:
	float x;
	float y;
};

class State2D {
public:
	float x;
	float y;
	double dir;
	color_t color;
	color_t bgcolor;
	bool filling;
};

class Drawer2D {
	LSystem<char>* lsystem;

	void drawBranch(ParseTreeNode<InstanceNodeContent, char>* parent, State2D& state);
	
public:
	Drawer2D(LSystem<char>* lsystem);

	void prepare(int argc, char** argv);
	void display();
	void draw();
};

}
