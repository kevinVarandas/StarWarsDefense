#include "Deathstar.h"

Deathstar::Deathstar(float posX, float posY, int line, int column) : Spaceship(posX, posY,line,column)
{
	red_ = 1.0f;
	green_ = 0.0f;
	blue_ = 0.0f;
	damageImpact_ = 100;
	price_ = LibConstants::PRICE_DEATHSTAR;
	cadence_ = 3000;
	id_ = LibConstants::ID_DEATHSTAR;
}


Deathstar::~Deathstar()
{
}

void Deathstar::draw()
{
	std::vector<float> vectorX;
	std::vector<float> vectorY;

	vectorX.emplace_back(posX_);
	vectorY.emplace_back(posY_);
	vectorX.emplace_back(posX_ - 0.04f);
	vectorY.emplace_back(posY_ + 0.05f);
	vectorX.emplace_back(posX_ - 0.08f);
	vectorY.emplace_back(posY_ + 0.05f);
	vectorX.emplace_back(posX_ - 0.12f);
	vectorY.emplace_back(posY_);
	vectorX.emplace_back(posX_ - 0.08f);
	vectorY.emplace_back(posY_ - 0.05f);
	vectorX.emplace_back(posX_ - 0.04f);
	vectorY.emplace_back(posY_ - 0.05f);


	GraphicPrimitives::drawFillPolygone2D(vectorX, vectorY, red_, green_, blue_);
}
void Deathstar::drawLegende()
{
	GraphicPrimitives::drawText2D("Degats / missile :  150", -0.40, -0.88, red_, green_, blue_);
	GraphicPrimitives::drawText2D("Cadence de tir  :  lent", -0.40, -0.96, red_, green_, blue_);
	GraphicPrimitives::drawText2D("   |     Missile : 1", 0.10, -0.88, red_, green_, blue_);
}