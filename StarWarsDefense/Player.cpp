#include "Player.h"


Player::Player() : money_(300), selectedSpaceship_(0), score_(0), nbImpact_(0), seenHowToPlay_(false) {}

Player::~Player(){}

void Player::drawMoney()
{
	char * money = new char[100];
	float x = -0.99;
	Utility::itoa(money_, money);
	GraphicPrimitives::drawText2D("Budget", x, -0.50f, 255/255.0, 216/255.0, 0.f);
	GraphicPrimitives::drawText2D(money, x, -0.58f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(" $", x +0.11f, -0.58f, 255 / 255.0, 216 / 255.0, 0.f);
	delete[] money;
}

void Player::drawScore()
{
	char * score = new char[100];
	float x = -0.99;
	Utility::itoa(score_,score);
	GraphicPrimitives::drawText2D("Score", x, -0.70f, 255 / 255.0, 216 / 255.0, 0.f);
	GraphicPrimitives::drawText2D(score, x, -0.78f, 1.0f, 1.0f, 1.0f);
	delete[] score;
}

void Player::drawLife()
{
	char * impact = new char[100];
	float x = -0.99;
	Utility::itoa(nbImpact_, impact);
	GraphicPrimitives::drawText2D("Game Over :", x, -0.98f, 255 / 255.0, 216 / 255.0, 0.f);
	GraphicPrimitives::drawText2D(impact, x + 0.28f, -0.98f, 1.0f, 1.0f, 1.0f);
	
	GraphicPrimitives::drawText2D(" / ", x + 0.30f, -0.98f, 255 / 255.0, 216 / 255.0, 0.f);
	
	char * impactMax = new char[100];
	Utility::itoa(LibConstants::MAX_IMPACT, impactMax);
	GraphicPrimitives::drawText2D(impactMax, x + 0.33f, -0.98f, 255 / 255.0, 216 / 255.0, 0.f);
	
	delete[] impact;
	delete[] impactMax;
}

bool Player::hasEnoughMoney()
{
	bool enough;
	switch (selectedSpaceship_)
	{
	case LibConstants::ID_XWING:
		 enough = money_ - LibConstants::PRICE_XWING >= 0;
		if (enough)
			money_ -= LibConstants::PRICE_XWING;
		return enough;
	case LibConstants::ID_STARFIGHTER:
		enough = money_ - LibConstants::PRICE_STARFIGHTER>= 0;
		if (enough)
			money_ -= LibConstants::PRICE_STARFIGHTER;
		return enough;
	case LibConstants::ID_ARCADIA:
		enough = money_ - LibConstants::PRICE_ARCADIA >= 0;
		if (enough)
			money_ -= LibConstants::PRICE_ARCADIA;
		return enough;
	case LibConstants::ID_DEATHSTAR:
		enough = money_ - LibConstants::PRICE_DEATHSTAR>= 0;
		if (enough)
			money_ -= LibConstants::PRICE_DEATHSTAR;
		return enough;
	default:
		return false;
	}
}

void Player::drawGameOver()
{
	char * score = new char[100];

	Utility::itoa(score_, score);
	GraphicPrimitives::drawText2D("GAME OVER !!", -0.2f, 0.2f, 1.0f, 0.0f, 0.0f);
	GraphicPrimitives::drawText2D("Score :", -0.2f, 0.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(score, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
}
void Player::drawReadMe()
{
	GraphicPrimitives::drawText2D("BIENVENU SUR STAR WAR DEFENSE",-0.40f,0.85f,1.0f,0.0f,0.0f);
	
	char * text = "Les forces du bien et du mal se sont alliees pour survivre a ces vagues de meteorites.";
	GraphicPrimitives::drawText2D(text, -0.90f, 0.70f, 1.0f, 1.0f, 1.0f);

	text = "Plusieurs types de vaisseaux sont a disposition dans ce Tower Defense.";
	GraphicPrimitives::drawText2D(text, -0.90f, 0.60f, 1.0f, 1.0f, 1.0f);

	text = "Vous disposerez d'un court repis ainsi que d'un bonus d'argent entre chaque vague.";
	GraphicPrimitives::drawText2D(text, -0.90f, 0.45f, 1.0f, 1.0f, 1.0f);

	text = "Un asteroide heurtant un vaisseau detruit ce dernier, mais perd de la vie !";
	GraphicPrimitives::drawText2D(text, -0.90f, 0.35f, 1.0f, 1.0f, 1.0f);

	text = "Selectionnez le vaisseau sur la gauche de la fenetre puis posez-le sur la grille.";
	GraphicPrimitives::drawText2D(text, -0.90f, 0.25f, 1.0f, 1.0f, 1.0f);

	text = "Pour revendre un vaisseau : clic droit dessus (recuperation de la moitie de son prix).";
	GraphicPrimitives::drawText2D(text, -0.90f, 0.15f, 1.0f, 1.0f, 1.0f);

	text = "Si 4 asteroides heurtent le bord gauche de la grille, vous perdez la partie.";
	GraphicPrimitives::drawText2D(text, -0.90f, 0.00f, 1.0f, 1.0f, 1.0f);

	text = "A chaque vague, le nombre d ' asteroides augmentera !";
	GraphicPrimitives::drawText2D(text, -0.90f, -0.10f, 1.0f, 1.0f, 1.0f);

	text = "Le numero de vague est affiche en haut a gauche de la fenetre !";
	GraphicPrimitives::drawText2D(text, -0.90f, -0.20f, 1.0f, 1.0f, 1.0f);

	text = "Le nombre d'impact subis, le score et le budget sont affiches en bas a gauche !";
	GraphicPrimitives::drawText2D(text, -0.90f, -0.30f, 1.0f, 1.0f, 1.0f);

	text = "CONSEIL :";
	GraphicPrimitives::drawText2D(text, -0.90f, -0.55f, 0.0f, 122/255.0f, 255/255.0f);

	text = "Ne faites que de petits vaisseaux au depart ET surtout soyez vif !";
	GraphicPrimitives::drawText2D(text, -0.60f, -0.55f, 1.0f,1.0f,1.0f);

	text = "ASTUCE :";
	GraphicPrimitives::drawText2D(text, -0.90f, -0.65f, 0.0f, 122 / 255.0f, 255 / 255.0f);

	text = "Utilisez les petits vaisseaux pour proteger les autres ou votre vie !";
	GraphicPrimitives::drawText2D(text, -0.60f, -0.65f, 1.0f, 1.0f, 1.0f);

	text = "Cliquez pour commencer !";
	GraphicPrimitives::drawText2D(text, -0.30f, -0.90f, 1.0f, 0.0f, 0.0f);
}

void Player::addBonusEndOfWave(int level)
{
	if (level > 1 && level < 5)
		money_ += 25;
	else if (level >= 5 && level < 10)
		money_ += 50;
	else if (level >= 10)
		money_ += 75;
}