#pragma once
#include "Asteroide.h"

class Eros:
	public Asteroide
{
public:
	Eros(float posX, float posY);
	~Eros();

	virtual void draw();
	virtual void tick();
};

