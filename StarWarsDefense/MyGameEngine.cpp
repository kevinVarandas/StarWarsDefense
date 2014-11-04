#include "MyGameEngine.h"

void MyGameEngine::idle(){
	//Si le joueur pas Game Over => avancer missiles et asteroides
	if ((*player_).hasSeenHowToPlay() && !(*player_).isGameOver())
	{
		std::chrono::system_clock::time_point tNow = std::chrono::high_resolution_clock::now();
		int time = std::chrono::duration_cast<std::chrono::milliseconds>(tNow - tStart_).count();

		if (time >= 30)
		{
			for (int i = 0; i <(int)missiles_->size(); i++)
			{
				(*missiles_)[i]->tick();
			}
	
			for (int i = 0; i < (*wave_).getSize(); i++)
			{
				(*wave_).getAsteroide(i)->tick();
			}
			tStart_ = std::chrono::high_resolution_clock::now();
		}
	}
}