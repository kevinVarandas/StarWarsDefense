#include "Arcadia.h"

Arcadia::Arcadia(float posX, float posY, int line, int column) : Spaceship(posX, posY, line, column)
{
	red_ = 0.0f / 255.0f;
	green_ = 255.0f / 255.0f;
	blue_ = 30.0f / 255.0f;
	damageImpact_ = 120;
	price_ = LibConstants::PRICE_ARCADIA;
	cadence_ = 1800;
	id_ = LibConstants::ID_ARCADIA;
}


Arcadia::~Arcadia(){}

void Arcadia::draw()
{
	float width = 0.10;
	float height = 0.11;
	std::vector<float> vectorX;
	std::vector<float> vectorY;

	vectorX.emplace_back(posX_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ - ( width / 2));
	vectorY.emplace_back(posY_ + (height / 2));

	vectorX.emplace_back(posX_ - width);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ - ( width / 2));
	vectorY.emplace_back(posY_ - (height / 2));

	GraphicPrimitives::drawFillPolygone2D(vectorX, vectorY, red_, green_, blue_);
	GraphicPrimitives::drawFillRect2D(posX_-width+0.01,posY_-(height/8),width-0.02f,(height/4),0.35f,0.35f,0.35f);
}

void Arcadia::drawLegende()
{
	GraphicPrimitives::drawText2D("Degats / missile :  15", -0.40, -0.88, red_, green_, blue_);
	GraphicPrimitives::drawText2D("Cadence de tir  :  moyen", -0.40, -0.96, red_, green_, blue_);
	GraphicPrimitives::drawText2D("   |     Missile : 4 ( 2 ligne droite / 2 biais)", 0.10, -0.88, red_, green_, blue_);
}