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
	std::chrono::system_clock::time_point tPopNow = std::chrono::high_resolution_clock::now();

	if (std::chrono::duration_cast<std::chrono::milliseconds>(tPopNow - tStart_).count() >= cadence_)
	{
		tStart_ = std::chrono::high_resolution_clock::now();
		return true;
	}
	return false;
}