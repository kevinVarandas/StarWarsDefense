#pragma once
#include "Spaceship.h"
#include "GraphicPrimitives.h"
#include "Utility.h"
#include <chrono>

class Asteroide
{
protected:
	float posX_, posY_;
	float VposX_, VposY_;

	float width_, height_;
	
	float red_, green_, blue_;
	int life_, moneyWhenExplosed_, scoreWhenExplosed_;

	std::chrono::system_clock::time_point tStart_;
	
public:
	Asteroide(float posX, float posY, float red = 1.0f, float green = 1.0f, float blue = 1.0f);
	~Asteroide();

	virtual void draw() = 0;
	virtual void tick() = 0;
	
	void drawVita();
	bool hitSpaceship(Spaceship *s);

	int getLife(){ return life_; }
	void setLife(int life){ life_ = life; }

	int getScoreWhenExplosed(){ return scoreWhenExplosed_; }
	float getHitBoxBottom(){ return posY_ - (height_ / 2); }
	float getHitBoxTop(){ return posY_ + (height_ / 2); }
	float getHitBoxLeft(){ return posX_; }
	float getHitBoxRight(){ return posX_ + width_; }
	int getMoneyWhenExplosed(){ return moneyWhenExplosed_; }
};

