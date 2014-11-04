#include <iostream>
#include <cstdlib>

#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Square.h"
#include "Spaceship.h"
#include "LibConstants.h"
#include "Player.h"
#include "Missile.h"
#include "Asteroide.h"
#include "Wave.h"

int main(int argc, char * argv[])
{
	Engine e(argc, argv, LibConstants::windowsWidth, LibConstants::windowsHeight , "Star Wars Defense Project");
    
	std::vector< std::vector<Square> > squares_;
	std::vector<Spaceship *> spaceships_;
	std::vector<Square> squareChoice_;
	std::vector<Spaceship *> spaceshipChoice_;
	std::vector<Missile *> missiles_;
	Player player;

	Wave wave_;

	srand(time(NULL));
	
	for (int ligne = 0; ligne < LibConstants::NB_SQUARE; ligne++)
	{
		//création des lignes vide
		squares_.emplace_back();
		//Remplissage des lignes
		for (int colonne = 0; colonne < LibConstants::NB_SQUARE; colonne++)
		{
			squares_[ligne].emplace_back(-(1.0f - LibConstants::SQUARE_SIZE) + (ligne)*LibConstants::SQUARE_POS,
										-(1.0f - LibConstants::SQUARE_SIZE) + (colonne)*LibConstants::SQUARE_POS,
										LibConstants::SQUARE_POS,
										0.0f,
										0.0f,
										0.0f	);
		}

	}
	float x = -0.99f;
	float y = 0;
	for (int shipChoice = 0; shipChoice < LibConstants::NB_SHIP_CHOICE; shipChoice++)
	{
		y = -0.3f + shipChoice*0.3;

		squareChoice_.emplace_back(x, y, LibConstants::SQUARE_POS, 0.0f, 0.0f, 0.0f);
		if (shipChoice == 0)
			spaceshipChoice_.push_back(new Xwing(x+(4*LibConstants::SQUARE_POS/5),y+(LibConstants::SQUARE_POS/2)));
		else if (shipChoice ==1)
			spaceshipChoice_.push_back(new Starfighter(x + (4 * LibConstants::SQUARE_POS / 5), y + (LibConstants::SQUARE_POS / 2)));
		else if (shipChoice == 2)
			spaceshipChoice_.push_back(new Arcadia(x + (4 * LibConstants::SQUARE_POS / 5), y + (LibConstants::SQUARE_POS / 2)));
		else if (shipChoice == 3)
			spaceshipChoice_.push_back(new Deathstar(x + (4 * LibConstants::SQUARE_POS / 5), y + (LibConstants::SQUARE_POS / 2)));
	}

	GraphicEngine * ge = new MyGraphicEngine(&squares_, &squareChoice_, &spaceshipChoice_, &spaceships_,&missiles_,&wave_,&player);
	GameEngine * gme = new MyGameEngine(&squares_, &squareChoice_, &spaceshipChoice_, &spaceships_, &missiles_, &wave_, &player);
	ControlEngine * ce = new MyControlEngine(&squares_, &squareChoice_, &spaceshipChoice_, &spaceships_, &missiles_, &wave_, &player);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}