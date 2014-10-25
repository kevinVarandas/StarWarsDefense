#pragma once
#include "Missile.h"
class MissileLourd :
	public Missile
{
public:
	MissileLourd(float posX, float posY, float r = 1.0f, float g = 0.0f, float b = 0.0f);
	~MissileLourd();

	virtual void draw();
	virtual void tick();
};

