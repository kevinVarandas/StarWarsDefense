#include "Hypnos.h"

Hypnos::Hypnos(float posX, float posY) : Asteroide(posX,posY)
{
	VposX_ = 0.0023f;
	VposY_ = 0.0f;
	life_ = 100;
	width_ = 0.08f;
	height_ = 0.12f;
	moneyWhenExplosed_ = 25;
	scoreWhenExplosed_ = life_ / 10;
}

Hypnos::~Hypnos(){}


void Hypnos::draw()
{
	std::vector<float> vectorX;
	std::vector<float> vectorY;

	vectorX.emplace_back(posX_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ + (width_ / 4));
	vectorY.emplace_back(posY_ + (height_ / 4));

	vectorX.emplace_back(posX_ + (width_));
	vectorY.emplace_back(posY_ + (height_ / 4));

	vectorX.emplace_back(posX_ + (width_));
	vectorY.emplace_back(posY_ - (height_ / 4));

	vectorX.emplace_back(posX_ + (width_ / 4));
	vectorY.emplace_back(posY_ - (height_ / 4));

	GraphicPrimitives::drawFillPolygone2D(vectorX,vectorY,red_,green_,blue_);
}

void Hypnos::tick()
{
	posX_ -= VposX_;
	posY_ -= VposY_;
}