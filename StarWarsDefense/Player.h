#pragma once
#include "GraphicPrimitives.h"
#include "Utility.h"
#include "LibConstants.h"

class Player
{
private:
	int money_;
	int selectedSpaceship_;
	int score_;
	bool seenHowToPlay_;
	int nbImpact_;

public:
	Player();
	~Player();

	int getMoney(){ return money_; }
	void updateMoney(int money)
	{ 
		if (money_ < LibConstants::MAX_MONEY) 
			money_ += money; 
	}
	void updateScore(int score){ 
		if(score_ < LibConstants::MAX_SCORE)
			score_ += score; 
	}

	bool hasSeenHowToPlay(){ return seenHowToPlay_; }
	bool isGameOver() { return nbImpact_ >= LibConstants::MAX_IMPACT; }
	void setHasSeenHowToPlay(){ seenHowToPlay_ = true; }
	void addImpact(){ nbImpact_++; }

	void setSelectedSpaceship(int id){ selectedSpaceship_ = id; }
	int getSelectedSpaceship(){ return selectedSpaceship_; }

	void drawLife();
	bool hasEnoughMoney();
	void drawMoney();
	void drawScore();
	void drawGameOver();
	void drawReadMe();
	void addBonusEndOfWave(int level);
};

