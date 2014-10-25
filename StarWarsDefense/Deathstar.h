#pragma once
#include "Spaceship.h"
#include "GraphicEngine.h"
#include "Utility.h"

class Deathstar :
	public Spaceship
{
public:
	Deathstar(float posX, float posY, int line = -1, int column = -1);
	~Deathstar();

	virtual void draw();
	virtual void drawLegende();
};

