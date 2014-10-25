//#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "LibConstants.h"
#include "Square.h"
#include "Spaceship.h"
#include "Player.h"
#include "Missile.h"
#include "MissileLeger.h"
#include "MissileMoyen.h"
#include "MissileLourd.h"
#include "Asteroide.h"
#include "Hypnos.h"
#include "Eros.h"
#include "Icare.h"
#include "Wave.h"

class MyGraphicEngine:public GraphicEngine {
    
	std::vector<std::vector<Square> > *squares_;
	std::vector<Spaceship *> *spaceships_;
	std::vector<Square> * squareChoice_;
	std::vector<Spaceship *> *spaceshipChoice_;
	std::vector<Missile *> *missiles_;
	Player * player_;
	Wave * wave_;
public:

	MyGraphicEngine(std::vector<std::vector<Square> > *squares, std::vector<Square> *squareChoice,
		std::vector<Spaceship *> *spaceshipChoice, std::vector<Spaceship *> *spaceships, std::vector<Missile *> *missiles,
		Wave * wave, Player * player) :
		squares_(squares),
		squareChoice_(squareChoice),
		spaceshipChoice_(spaceshipChoice),
		missiles_(missiles),
		spaceships_(spaceships),
		wave_(wave),
		player_(player){}
    
    virtual void Draw();
};
