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
	int level_, freezeTime_, numberOfAsteroide_;
	std::vector<Asteroide *> asteroides_;
	bool waveActive_;

	int frequencePop_, asteroideDestroyed_;

	std::chrono::system_clock::time_point tStart_, startAsteroidePop_;
	bool firstTick_, firstAsteroide_;

public:
	Wave();
	~Wave();

	int getLevel(){ return level_; }
	int getFreezeTime(){ return freezeTime_; }
	int getSize(){ return (int)asteroides_.size(); }
	void setActive(){ waveActive_ = true; }
	void setInactive(){ waveActive_ = false; }
	bool isActive(){ return waveActive_; }
	Asteroide* getAsteroide(int i){ return asteroides_[i]; }
	void deleteAsteroide(int i)
	{ 
		asteroides_[i] = nullptr;
		asteroides_.erase(asteroides_.begin() + i); 
	}
	int getNumberOfAsteroide(){ return numberOfAsteroide_; }
	int getMaxAsteroide();
	void resetNumberOfAsteroide(){ numberOfAsteroide_ = 0; }
	void levelUp(){ level_++; }
	bool isEmpty(){ return asteroides_.empty(); }
	int getNumberOfAsteroideDestroyed(){ return asteroideDestroyed_; }
	void incNumberOfAsteroideDestroyed(){ asteroideDestroyed_++; }
	void resetNumberOfAsteroideDesrtroyed(){ asteroideDestroyed_ = 0; }
	void resetChrono()
	{ 
		tStart_ = std::chrono::high_resolution_clock::now();
		firstAsteroide_ = true;
	}
	void resetChronoAsteroidePop(){ startAsteroidePop_ = std::chrono::high_resolution_clock::now(); }

	bool isReadyToGo();
	void drawNumWave();
	void drawNumberOfAsteroide();
	bool isReadyToPopAsteroide();
	void addAsteroide(std::vector<std::vector<Square> > *squares);
};

