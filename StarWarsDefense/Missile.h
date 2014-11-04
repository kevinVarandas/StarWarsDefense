#pragma once
#include "GraphicPrimitives.h"
#include "Asteroide.h"
class Missile
{
protected:
	int damage_, id_;
	float posX_, posY_, VposX_, VposY_;
	float height_, width_;
	float red_, green_, blue_;
public:
	Missile(float posX, float posY, float r, float g, float b);
	Missile(float posX, float posY, float VposY, float r, float g, float b);
	~Missile();

	virtual void draw() = 0;
	virtual void tick() = 0;

	virtual float getPosX() { return posX_;}
	virtual float getPosY(){ return posY_; }

	float getHitBoxBottom(){ return posY_ - (height_ / 2); }
	float getHitBoxRight(){ return posX_; }
	float getHitBoxLeft(){ return posX_ - width_; }
	float getHitBoxTop(){ return posY_ + (height_ / 2); }

	int getDamage(){ return damage_; }
	int getId() { return id_; }

	bool hitAsteroid(Asteroide *a);
};

