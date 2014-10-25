#include "Spaceship.h"


Spaceship::Spaceship(float posX, float posY, int line, int column) : 
	posX_(posX),posY_(posY),
	line_(line),column_(column){}


Spaceship::~Spaceship()
{
}

void Spaceship::drawPrice()
{
	char * price = new char[100];

	Utility::itoa(price_, price);

	GraphicPrimitives::drawText2D(price, posX_ - 0.1, posY_ - 0.12f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D("$", posX_ - 0.01, posY_ - 0.12f, 1.0f, 1.0f, 1.0f);

	delete[] price;
}

bool Spaceship::isReadyToFire()
{
	bool fire = frequence_%cadence_ == 0;
	frequence_ = (frequence_ + 1) % cadence_;

	return fire;
}