#include "Eros.h"


Eros::Eros(float posX, float posY) : Asteroide(posX,posY)
{
	VposX_ = 0.0018f;
	VposY_ = 0.0f;
	life_ = 350;
	width_ = 0.1f;
	height_ = 0.08f;
	moneyWhenExplosed_ = 50;
	scoreWhenExplosed_ = life_ / 10;
}


Eros::~Eros(){}

void Eros::draw()
{
	std::vector<float> vectorX;
	std::vector<float> vectorY;

	vectorX.emplace_back(posX_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ + (width_ / 2));
	vectorY.emplace_back(posY_ + (height_ / 2));

	vectorX.emplace_back(posX_ + width_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ + (width_ / 2));
	vectorY.emplace_back(posY_ - (height_ / 2));

	GraphicPrimitives::drawFillPolygone2D(vectorX, vectorY, red_, green_, blue_);
}

void Eros::tick()
{
	posX_ -= VposX_;
	posY_ -= VposY_;
}