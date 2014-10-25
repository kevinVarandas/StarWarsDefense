#include "MyGameEngine.h"

void MyGameEngine::idle(){
	//Si le joueur pas Game Over => avancer missiles et asteroides
	if ((*player_).hasSeenHowToPlay() && !(*player_).isGameOver())
	{
		for (int i = 0; i <(int)missiles_->size(); i++)
		{
			(*missiles_)[i]->tick();
		}
	
		for (int i = 0; i < (*wave_).getSize(); i++)
		{
			(*wave_).getAsteroide(i)->tick();
		}
	}
}