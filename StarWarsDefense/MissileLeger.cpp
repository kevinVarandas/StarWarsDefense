#include "MissileLeger.h"

MissileLeger::MissileLeger(float posX, float posY, float r, float g, float b) : Missile(posX, posY, r, g, b)
{
	width_ = 0.02f;
	height_ = 0.01f;
	VposX_ = 0.04f;
	VposY_ = 0.0f;
	damage_ = 5;
	id_ = 1;
}
		

MissileLeger::~MissileLeger(){}

void MissileLeger::draw()
{
	GraphicPrimitives::drawFillRect2D(posX_ -width_, posY_ - (height_/2), width_, height_, red_, green_, blue_);
}

void MissileLeger::tick()
{
	posX_ += VposX_;
}