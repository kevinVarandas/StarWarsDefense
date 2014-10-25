#pragma once
#include "Square.h"
#include "Asteroide.h"
#include "Hypnos.h"
#include "Icare.h"
#include "Eros.h"
#include "Utility.h"
#include <cstdlib>

class Wave
{
private:
	int level_, freezeTime_, frequency_, numberOfAsteroide_;
	std::vector<Asteroide *> asteroides_;
	bool waveActive_;

	int cadencePop_, frequencePop_, asteroideDestroyed_;

public:
	Wave();
	~Wave();

	int getLevel(){ return level_; }
	int getFreezeTime(){ return freezeTime_; }
	int getFrequency(){ return frequency_; }
	int getSize(){ return (int)asteroides_.size(); }
	void setActive(){ waveActive_ = true; }
	void setInactive(){ waveActive_ = false; }
	bool isActive(){ return waveActive_; }
	Asteroide* getAsteroide(int i){ return asteroides_[i]; }
	void deleteAsteroide(int i){ asteroides_.erase(asteroides_.begin() + i); }
	int getNumberOfAsteroide(){ return numberOfAsteroide_; }
	int getMaxAsteroide(){ return level_ * 4; }
	void resetNumberOfAsteroide(){ numberOfAsteroide_ = 0; }
	void levelUp(){ level_++; }
	bool isEmpty(){ return asteroides_.empty(); }
	int getNumberOfAsteroideDestroyed(){ return asteroideDestroyed_; }
	void incNumberOfAsteroideDestroyed(){ asteroideDestroyed_++; }
	void resetNumberOfAsteroideDesrtroyed(){ asteroideDestroyed_ = 0; }

	bool isReadyToGo();
	void drawNumWave();
	void drawNumberOfAsteroide();
	bool isReadyToPopAsteroide();
	void addAsteroide(std::vector<std::vector<Square> > *squares);
};

