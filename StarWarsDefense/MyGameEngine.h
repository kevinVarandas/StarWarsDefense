#pragma once

#include "Engine.h"
#include "Square.h"
#include "Spaceship.h"
#include "Player.h"
#include "Missile.h"
#include "Wave.h"

class MyGameEngine:public GameEngine {
	std::vector<std::vector<Square>	>*squares_;
	std::vector<Spaceship *> *spaceships_;
	std::vector<Square> *squareChoice_;
	std::vector<Spaceship *> *spaceshipChoice_;
	std::vector<Missile *> * missiles_;
	Wave * wave_;
	Player * player_;

public:
	MyGameEngine(std::vector<std::vector<Square> >*squares, std::vector<Square> *squareChoice,
		std::vector<Spaceship *> *spaceshipChoice, std::vector<Spaceship *> *spaceships, std::vector<Missile *> * missiles,
		Wave * wave, Player * player) :
		squares_(squares),
		squareChoice_(squareChoice),
		spaceshipChoice_(spaceshipChoice),
		spaceships_(spaceships),
		missiles_(missiles),
		wave_(wave),
		player_(player){}

    virtual void idle();
    
};
