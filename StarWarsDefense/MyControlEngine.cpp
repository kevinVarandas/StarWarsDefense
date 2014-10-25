#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	
	float posX = ((x - (LibConstants::windowsWidth / 2.0f)) / (float)(LibConstants::windowsWidth / 2.0f)) + 1 - LibConstants::SQUARE_SIZE;
	float posY = ((y - (LibConstants::windowsHeight / 2.0f)) / -(float)(LibConstants::windowsHeight / 2.0f)) + 1 - LibConstants::SQUARE_SIZE;
	if ((*player_).hasSeenHowToPlay())
	{

		int i = (int)(posX / LibConstants::SQUARE_POS);
		int j = (int)(posY / LibConstants::SQUARE_POS);
		std::cout << " i " << i << " et j " << j << std::endl;
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (x >= (LibConstants::windowsWidth / 2 * LibConstants::SQUARE_SIZE) &&
				y <= (LibConstants::windowsHeight - LibConstants::windowsHeight / 2 * LibConstants::SQUARE_SIZE))
			{
				if ((*squares_)[i][j].getCptClick() < 1 && i < 5 && (*player_).hasEnoughMoney())
				{
					(*squares_)[i][j].incCptClick();
					float posXSpaceship = (*squares_)[i][j].getX();
					float posYSpaceship = (*squares_)[i][j].getY();
					float sideSpaceship = (*squares_)[i][j].getSide();

					if ((*player_).getSelectedSpaceship() == 0)
					{
						spaceships_->push_back(new Xwing(posXSpaceship + (4 * sideSpaceship / 5),
							posYSpaceship + (sideSpaceship / 2), i, j));
					}

					if ((*player_).getSelectedSpaceship() == 1)
						spaceships_->push_back(new Starfighter(posXSpaceship + (4 * sideSpaceship / 5),
						posYSpaceship + (sideSpaceship / 2), i, j));

					if ((*player_).getSelectedSpaceship() == 2)
						spaceships_->push_back(new Arcadia(posXSpaceship + (4 * sideSpaceship / 5),
						posYSpaceship + (sideSpaceship / 2), i, j));

					if ((*player_).getSelectedSpaceship() == 3)
						spaceships_->push_back(new Deathstar(posXSpaceship + (4 * sideSpaceship / 5),
						posYSpaceship + (sideSpaceship / 2), i, j));
				}
			}
			else
			{
				posX = ((x - (LibConstants::windowsWidth / 2.0f)) / (float)(LibConstants::windowsWidth / 2.0f));
				posY = ((y - (LibConstants::windowsHeight / 2.0f)) / -(float)(LibConstants::windowsHeight / 2.0f));
				for (int i = 0; i < LibConstants::NB_SHIP_CHOICE; i++)
				{
					if (posX >= (*squareChoice_)[i].getX() && posX <= (*squareChoice_)[i].getX() + (*squareChoice_)[i].getSide()
						&& posY >= (*squareChoice_)[i].getY() && posY <= (*squareChoice_)[i].getY() + (*squareChoice_)[i].getSide())
					{
						(*player_).setSelectedSpaceship(i);
					}
				}
			}
		}
		else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			for (int k = 0; k < (int)spaceships_->size(); k++)
			{
				if ((*spaceships_)[k]->getLine() == i && (*spaceships_)[k]->getColumn() == j)
				{
					(*squares_)[(*spaceships_)[k]->getLine()][(*spaceships_)[k]->getColumn()].restoreCptClick();
					(*player_).updateMoney((*spaceships_)[k]->getPrice()/2);

					delete (*spaceships_)[k];
					spaceships_->erase(spaceships_->begin() + k);
				}
			}
		}
	}
	else
	{
		(*player_).setHasSeenHowToPlay();
	}
}