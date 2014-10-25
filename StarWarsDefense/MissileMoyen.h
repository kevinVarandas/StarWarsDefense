#pragma once
#include "Missile.h"
class MissileMoyen :
	public Missile
{
public:
	MissileMoyen(float posX, float posY,float VposY = 0.00f, float red = 252.0/255.0f, float green = 210.0/255.0f, float blue = 9/255.0f);
	~MissileMoyen();

	virtual void draw();
	virtual void tick();
};

