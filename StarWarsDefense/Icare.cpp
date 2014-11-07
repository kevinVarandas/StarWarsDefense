#include "Icare.h"


Icare::Icare(float posX, float posY) :Asteroide(posX, posY)
{
	VposX_ = 0.0018f;
	VposY_ = 0.0f;
	life_ = 800;
	width_ = 0.1f;
	height_ = 0.08f;
	moneyWhenExplosed_ = 100;
	scoreWhenExplosed_ = life_ / 10;
}

Icare::Icare(float posX, float posY, float VposX) :Asteroide(posX, posY)
{
	VposX_ = VposX;
	VposY_ = 0.0f;
	life_ = 800;
	width_ = 0.1f;
	height_ = 0.08f;
	moneyWhenExplosed_ = 100;
	scoreWhenExplosed_ = life_ / 10;
}

Icare::~Icare(){}

void Icare::draw()
{
	std::vector<float> vectorX;
	std::vector<float> vectorY;

	vectorX.emplace_back(posX_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ + width_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ + (width_ / 2));
	vectorY.emplace_back(posY_ - (height_ / 2));

	vectorX.emplace_back(posX_ + 0.05f);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ + (width_ / 2)+0.05f);
	vectorY.emplace_back(posY_ + (height_ / 2));

	vectorX.emplace_back(posX_ + width_ + 0.05f);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ + (width_ / 2) +0.05f);
	vectorY.emplace_back(posY_ - (height_ / 2));

	vectorX.emplace_back(posX_ + (width_ / 2));
	vectorY.emplace_back(posY_ + (height_ / 2));

	GraphicPrimitives::drawFillPolygone2D(vectorX, vectorY, red_, green_, blue_);
}

void Icare::tick()
{
	posX_ -= VposX_;
	posY_ -= VposY_;
}