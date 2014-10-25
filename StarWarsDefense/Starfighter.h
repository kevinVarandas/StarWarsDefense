#pragma once
#include "Spaceship.h"
#include "GraphicPrimitives.h"
#include "Utility.h"

class Starfighter :
	public Spaceship
{
public:
	Starfighter(float posX, float posY, int line = -1, int column = -1);
	~Starfighter();

	virtual void draw();
	virtual void drawLegende();
};