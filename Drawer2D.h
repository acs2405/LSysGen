
#pragma once


namespace lsysgen {

class Drawer2D;

}

#include "LSystem.h"

#include <GL/glut.h>
#include <string>
#include <iostream>


namespace lsysgen {

class Drawer2D {
	LSystem<char>* lsystem;
	
public:
	Drawer2D(LSystem<char>* lsystem);

	void prepare(int argc, char** argv);

	void draw();
};

}
