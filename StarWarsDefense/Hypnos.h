#pragma once
#include "Asteroide.h"

class Hypnos :
	public Asteroide
{
public:
	Hypnos(float posX, float posY);
	~Hypnos();

	virtual void draw();
	virtual void tick();
};

