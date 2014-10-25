#pragma once
#include "Spaceship.h"
class Arcadia :
	public Spaceship
{
public:
	Arcadia(float posX, float posY, int line = -1, int column = -1);
	~Arcadia();

	virtual void draw();
	virtual void drawLegende();
};

