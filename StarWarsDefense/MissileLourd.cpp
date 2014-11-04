#include "MissileLourd.h"


MissileLourd::MissileLourd(float posX, float posY, float r, float g, float b) : Missile(posX,posY,r,g,b)
{
	width_ = 0.08f;
	height_ = 0.06f;
	VposX_ = 0.006f,
	VposY_ = 0.0f,
	damage_ = 150;
	id_ = 4;
}

MissileLourd::~MissileLourd(){}

void MissileLourd::draw()
{
	std::vector<float> vectorX;
	std::vector<float> vectorY;

	vectorX.emplace_back(posX_- width_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ - (width_/2));
	vectorY.emplace_back(posY_ + (height_/2));

	vectorX.emplace_back(posX_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ - (width_/2));
	vectorY.emplace_back(posY_ - (height_/2));

	GraphicPrimitives::drawFillPolygone2D(vectorX, vectorY, red_, green_, blue_);
	GraphicPrimitives::drawFillRect2D(posX_ - width_+ 0.012f, posY_ - (height_ / 2), 0.010f, height_, red_, green_, blue_);
}

void MissileLourd::tick()
{
	posX_ += VposX_;
}