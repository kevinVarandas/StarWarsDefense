#include "Missile.h"


Missile::Missile(float posX, float posY, float r, float g, float b): posX_(posX),posY_(posY),red_(r),green_(g),blue_(b){}

Missile::Missile(float posX, float posY, float VposY, float r, float g, float b) 
	: posX_(posX), posY_(posY),  VposY_(VposY),
	red_(r), green_(g), blue_(b){}

Missile::~Missile(){}

bool Missile::hitAsteroid(Asteroide *a)
{
	return getHitBoxBottom() <= a->getHitBoxTop()
		&& getHitBoxTop() >= a->getHitBoxBottom()
		&& getHitBoxRight() >= a->getHitBoxLeft()
		&& getHitBoxRight() <= a->getHitBoxRight();
}