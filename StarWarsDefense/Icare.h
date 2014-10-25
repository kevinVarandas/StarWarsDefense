#pragma once
#include "Asteroide.h"
class Icare :
	public Asteroide
{
public:
	Icare(float posX, float posY);
	Icare(float posX, float posY, float VposX);
	~Icare();

	virtual void draw();
	virtual void tick();
};