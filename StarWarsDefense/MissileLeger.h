#pragma once
#include "Missile.h"
class MissileLeger :
	public Missile
{
public:
	MissileLeger(float posX, float posY, float 	red_ = 0.0f / 255.0f, float green_ = 72.0f / 255.0f, float	blue_ = 255.0f / 255.0f);
	~MissileLeger();

	virtual void draw();
	virtual void tick();
};

