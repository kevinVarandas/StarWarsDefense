#include "Xwing.h"


Xwing::Xwing(float posX, float posY, int line, int column) : Spaceship(posX, posY, line, column)
{
	red_ = 0.0f / 255.0f;
	green_ = 72.0f / 255.0f;
	blue_ = 255.0f / 255.0f;
	damageImpact_ = 50;
	price_ = LibConstants::PRICE_XWING;
	cadence_ = 150;
	id_ = LibConstants::ID_XWING;
	frequence_ = 0;
}


Xwing::~Xwing()
{
}

void Xwing::draw()
{
	GraphicPrimitives::drawFillTriangle2D(posX_,posY_,posX_-0.1f,posY_+0.05f, posX_-0.1f,posY_-0.05f,red_,green_,blue_);
}

void Xwing::drawLegende()
{
	GraphicPrimitives::drawText2D("Degats / missile :  5",-0.40, -0.88, red_, green_, blue_);
	GraphicPrimitives::drawText2D("Cadence de tir  :  rapide", -0.40, -0.96, red_, green_, blue_);
	GraphicPrimitives::drawText2D("   |     Missile : 1", 0.10, -0.88, red_, green_, blue_);
}