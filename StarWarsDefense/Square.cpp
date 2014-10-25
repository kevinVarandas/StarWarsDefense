#include "Square.h"

Square::Square(float x = -1.0f, float y = 1.0f,float side = 0.1f, 
				float red = 1.0f,float green = 1.0f, float blue = 1.0f) :
	posX_(x), posY_(y),side_(side),
	red_(red),green_(green), blue_(blue),
	cptClick_(0){}

Square::~Square(){}

void Square::draw()
{
	GraphicPrimitives::drawFillRect2D( posX_, posY_, side_, side_, red_, green_, blue_);
}

int Square::getCptClick(){ return cptClick_; }
void Square::incCptClick(){ cptClick_++; }

float Square::getX(){ return posX_; }
float Square::getY(){ return posY_; }
float Square::getSide(){ return side_; }

void Square::setColor(float r, float g, float b)
{
	red_ = r;
	green_ = g;
	blue_ = b;
}