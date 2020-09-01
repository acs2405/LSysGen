
#pragma once


#include "LSystem.h"

#include <GL/glut.h>
#include <string>
#include <iostream>

class Drawer2D {
	LSystem<char>* lsystem;
	
public:
	Drawer2D(LSystem<char>* lsystem);

	void prepare(int argc, char** argv);

	void draw();
};
