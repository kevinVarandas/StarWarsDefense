#pragma once
#include "GraphicPrimitives.h"
#include "Utility.h"
#include "LibConstants.h"
class Spaceship
{
protected:
	float posX_, posY_;
	float red_, green_, blue_;
	int damageImpact_, price_, cadence_, frequence_, id_;

	int line_, column_;

public:
	Spaceship(float posX, float posY, int line, int column);
	~Spaceship();

	virtual void drawLegende() = 0;
	virtual void draw() = 0;
	virtual void drawPrice();

	bool isReadyToFire();

	float getRed(){ return red_; }
	float getGreen(){ return green_; }
	float getBlue(){ return blue_; }
	float getX(){ return posX_; }
	float getY(){ return posY_; }
	float getHitBoxBottom(){ return posY_ - (LibConstants::SQUARE_POS / 2); }
	float getHitBoxTop(){ return posY_ + (LibConstants::SQUARE_POS / 2); }
	int getId(){ return id_; }
	int getLine(){ return line_; }
	int getColumn(){ return column_; }
	int getPrice(){ return price_; }

	int getDamageImpact(){ return damageImpact_; }
};

