#include "Starfighter.h"


Starfighter::Starfighter(float posX, float posY, int line, int column) : Spaceship(posX,posY,line,column)
{
	red_ = 250.0f / 255.0f;
	green_ = 250.0f / 255.0f;
	blue_ = 0.0f / 255.0f;
	damageImpact_ = 100;
	price_ = LibConstants::PRICE_STARFIGHTER;
	cadence_ = 400;
	id_ = LibConstants::ID_STARFIGHTER;
	frequence_ = 0;
}


Starfighter::~Starfighter()
{
}

void Starfighter::draw()
{
	float width = 0.12;
	float height = 0.08;
	std::vector<float> vectorX;
	std::vector<float> vectorY;

	vectorX.emplace_back(posX_);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ - (3 * width / 4));
	vectorY.emplace_back(posY_ + (height / 2));

	vectorX.emplace_back(posX_ - (3 * width / 4));
	vectorY.emplace_back(posY_ + (height / 2));

	vectorX.emplace_back(posX_ - width);
	vectorY.emplace_back(posY_);

	vectorX.emplace_back(posX_ - (3 * width / 4));
	vectorY.emplace_back(posY_ - (height / 2));

	vectorX.emplace_back(posX_ - (3 * width / 4));
	vectorY.emplace_back(posY_ - (height / 2));

	GraphicPrimitives::drawFillRect2D(posX_ - 0.045, posY_ - 0.05f, 0.01f, 0.1f,red_,green_,blue_);
	GraphicPrimitives::drawFillRect2D(posX_ - 0.065, posY_ - 0.05f, 0.01f, 0.1f, red_,green_,blue_);
	GraphicPrimitives::drawFillPolygone2D(vectorX, vectorY, red_, green_, blue_);
}

void Starfighter::drawLegende()
{
	GraphicPrimitives::drawText2D("Degats / missile :  15", -0.40, -0.88, red_, green_, blue_);
	GraphicPrimitives::drawText2D("Cadence de tir  :  moyen", -0.40, -0.96, red_, green_, blue_);
	GraphicPrimitives::drawText2D("   |     Missile : 2 (ligne droite)", 0.10, -0.88, red_, green_, blue_);
}