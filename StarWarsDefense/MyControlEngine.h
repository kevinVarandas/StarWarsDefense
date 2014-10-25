#pragma once
#include "Engine.h"
#include "Square.h"
#include "Spaceship.h"
#include "Xwing.h"
#include "Deathstar.h"
#include "Starfighter.h"
#include "Arcadia.h"
#include "LibConstants.h"
#include "Player.h"
#include "Missile.h"
#include "Wave.h"

class MyControlEngine:public ControlEngine {

	std::vector<std::vector<Square> >* squares_;
	std::vector<Spaceship *> * spaceships_;
	std::vector<Square> *squareChoice_;
	std::vector<Spaceship *> *spaceshipChoice_;
	std::vector<Missile *> * missiles_;
	Player * player_;
	Wave * wave_;

public:

	MyControlEngine(std::vector<std::vector<Square> >* squares, std::vector<Square> *squareChoice,
		std::vector<Spaceship *> *spaceshipChoice, std::vector<Spaceship *> * spaceships, std::vector<Missile *> * missiles,
		Wave * wave, Player *player) :
		squares_(squares),
		squareChoice_(squareChoice),
		spaceshipChoice_(spaceshipChoice),
		spaceships_(spaceships),
		missiles_(missiles),
		wave_(wave),
		player_(player){}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
};
