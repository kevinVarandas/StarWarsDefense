#pragma once
namespace LibConstants
{
	// ABOUT WINDOW
	const int windowsWidth = 800;
	const int windowsHeight = 600;

	//ABOUT SQUARES
	const int NB_SQUARE = 10;
	const float SQUARE_SIZE = (float)(2.0 / NB_SQUARE);
	const float SQUARE_POS = (float)((2.0f - (2.0/NB_SQUARE)) / NB_SQUARE);

	//ABOUT SPACESHIP CHOICE
	const int NB_SHIP_CHOICE = 4;
	const int PRICE_XWING = 50;
	const int PRICE_STARFIGHTER = 120;
	const int PRICE_ARCADIA = 180;
	const int PRICE_DEATHSTAR = 250;

	const int ID_XWING = 0;
	const int ID_STARFIGHTER = 1;
	const int ID_ARCADIA = 2;
	const int ID_DEATHSTAR = 3;

	//PLAYER
	const int MAX_MONEY = 10000;
	const int MAX_SCORE = 999999;
	const int MAX_IMPACT = 4;
}