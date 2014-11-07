#include "Asteroide.h"

Asteroide::Asteroide(float posX, float posY, float red, float green, float blue) :
	posX_(posX),
	posY_(posY),
	red_(red),
	green_(green),
	blue_(blue){}


Asteroide::~Asteroide(){}

void Asteroide::drawVita()
{
	char * lifePoints = new char[100];

	Utility::itoa(life_, lifePoints);

	GraphicPrimitives::drawText2D(lifePoints, posX_+0.015, posY_-0.08f, 1.0f, 0.0f, 0.0f);

	delete[] lifePoints;
}

bool Asteroide::hitSpaceship(Spaceship *s)
{
	return getHitBoxLeft() <= s->getX() && getHitBoxTop() <= s->getHitBoxTop()
		&& getHitBoxBottom() >= s->getHitBoxBottom() && getHitBoxRight() >= (s->getX() - (4*LibConstants::SQUARE_POS/5));
}
