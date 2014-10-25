#pragma once
#include "GraphicPrimitives.h"
#include "Utility.h"

class Square
{

private:
	float posX_, posY_;
	float side_;
	float red_, green_, blue_;

	int cptClick_;

public:
	Square(	float x, float y, float side,
			float red, float green, float blue);
	~Square();
	
	void draw();

	int getCptClick();
	void incCptClick();
	float getX();
	float getY();
	float getSide();
	void restoreCptClick(){ cptClick_ = 0; }
	void setColor(float, float, float);
};