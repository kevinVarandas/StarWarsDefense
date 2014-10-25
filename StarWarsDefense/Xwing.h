#pragma once
#include "Spaceship.h"
#include "GraphicPrimitives.h"
#include "Utility.h"

class Xwing :
	public Spaceship
{
public:
	Xwing(float posX, float posY, int line = -1, int column = -1);
	~Xwing();

	virtual void draw();
	virtual void drawLegende();
};

