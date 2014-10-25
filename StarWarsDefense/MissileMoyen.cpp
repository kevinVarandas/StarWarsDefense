#include "MissileMoyen.h"


MissileMoyen::MissileMoyen(float posX, float posY, float VposY, float red, float green, float blue) : Missile(posX, posY, VposY,red,green,blue)
{
	width_ = 0.04;
	height_ = 0.04;
	VposX_ = 0.004f;
	damage_ = 15;
	id_ = 2;
}

MissileMoyen::~MissileMoyen(){}

void MissileMoyen::draw()
{
	GraphicPrimitives::drawFillTriangle2D(posX_, posY_, posX_ + 0.03f, posY_ + 0.02f, posX_ + 0.03f, posY_ - 0.02f, red_, green_, blue_);
	GraphicPrimitives::drawFillTriangle2D(posX_+0.04f, posY_,posX_+0.01f,posY_+0.02f,posX_+0.01f,posY_-0.02f, red_, green_, blue_);
}

void MissileMoyen::tick()
{
	posX_ += VposX_;
	posY_ += VposY_;
}