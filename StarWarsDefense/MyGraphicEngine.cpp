#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){

	if ((*player_).hasSeenHowToPlay() && !(*player_).isGameOver())
	{
		//Affichage Budget user
		(*player_).drawMoney();
		//Affichage Score
		(*player_).drawScore();
		//Affichage vie
		(*player_).drawLife();
		//Affichage CASES
		for (int i = 0; i < LibConstants::NB_SQUARE; i++)
		{
			float x = (*squares_)[i][0].getX();
			float y = (*squares_)[i][0].getY();

			if (i != 5)
				GraphicPrimitives::drawLine2D(x, y, x, y + 10 * LibConstants::SQUARE_POS, 1.0f, 1.0f, 1.0f);
			else
				GraphicPrimitives::drawLine2D(x, y, x, y + 10 * LibConstants::SQUARE_POS, 1.0f, 0.0f, 0.0f);
		}

		for (int i = 0; i < LibConstants::NB_SQUARE; i++)
		{
			float x = (*squares_)[0][i].getX();
			float y = (*squares_)[0][i].getY();
			GraphicPrimitives::drawLine2D(x, y, x + 10*LibConstants::SQUARE_POS, y, 1.0f, 1.0f, 1.0f);
		}
		//Affichage des types de vaisseaux, prix et légende
		for (int i = 0; i < LibConstants::NB_SHIP_CHOICE; i++)
		{
			(*spaceshipChoice_)[i]->draw();
			(*spaceshipChoice_)[i]->drawPrice();

			if (i == (*player_).getSelectedSpaceship())
			{
				float x = (*squareChoice_)[i].getX();
				float y = (*squareChoice_)[i].getY();
				float size = (*squareChoice_)[i].getSide();
				float r = (*spaceshipChoice_)[i]->getRed();
				float g = (*spaceshipChoice_)[i]->getGreen();
				float b = (*spaceshipChoice_)[i]->getBlue();

				GraphicPrimitives::drawLine2D(x, y, x, y + size,r,g,b);
				GraphicPrimitives::drawLine2D(x + size, y, x +size , y + size, r, g, b);
				(*spaceshipChoice_)[i]->drawLegende();
			}
		}
		//Affichage des vaisseaux et Creation des missiles
		for (int i = 0; i < (int)spaceships_->size(); i++)
		{
			(*spaceships_)[i]->draw();
			if ((*spaceships_)[i]->getId() == LibConstants::ID_XWING && (*spaceships_)[i]->isReadyToFire())
			{
				(*missiles_).push_back(new MissileLeger((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY()));
			}
			else if ((*spaceships_)[i]->getId() == LibConstants::ID_STARFIGHTER && (*spaceships_)[i]->isReadyToFire())
			{
				(*missiles_).push_back(new MissileMoyen((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY() + 0.02f));
				(*missiles_).push_back(new MissileMoyen((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY() - 0.02f));
			}
			else if ((*spaceships_)[i]->getId() == LibConstants::ID_ARCADIA && (*spaceships_)[i]->isReadyToFire())
			{
				(*missiles_).push_back(new MissileMoyen((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY() + 0.02f, 0.004f, (*spaceships_)[i]->getRed(), (*spaceships_)[i]->getGreen(), (*spaceships_)[i]->getBlue()));
				(*missiles_).push_back(new MissileMoyen((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY() + 0.02f, 0.0f, (*spaceships_)[i]->getRed(), (*spaceships_)[i]->getGreen(), (*spaceships_)[i]->getBlue()));
				(*missiles_).push_back(new MissileMoyen((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY() - 0.02f, 0.0f, (*spaceships_)[i]->getRed(), (*spaceships_)[i]->getGreen(), (*spaceships_)[i]->getBlue()));
				(*missiles_).push_back(new MissileMoyen((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY() - 0.02f, -0.004f, (*spaceships_)[i]->getRed(), (*spaceships_)[i]->getGreen(), (*spaceships_)[i]->getBlue()));
			}
			else if ((*spaceships_)[i]->getId() == LibConstants::ID_DEATHSTAR && (*spaceships_)[i]->isReadyToFire())
			{
				(*missiles_).push_back(new MissileLourd((*spaceships_)[i]->getX(), (*spaceships_)[i]->getY()));
			}
		}
		//Affichage et suppression des missiles
		for (int i = 0; i < (int)missiles_->size(); i++)
		{
			// Missile sort du cadre
			if ((*missiles_)[i]->getHitBoxTop() >= 1.0f ||
				(*missiles_)[i]->getHitBoxLeft() >= 1.0f ||
				(*missiles_)[i]->getHitBoxBottom() <= (*squares_)[0][0].getY())
			{
				delete (*missiles_)[i];
				missiles_->erase(missiles_->begin() + i);
			}
			else
			{
				//dessine le missile
				(*missiles_)[i]->draw();
				for (int j = 0; j < (*wave_).getSize(); j++)
				{
					//Vérif si ça touche un astéroide
					if ((*missiles_)[i] != nullptr && (*wave_).getAsteroide(j) != nullptr && (*missiles_)[i]->hitAsteroid((*wave_).getAsteroide(j)))
					{
						int lifeAfterImpact = (*wave_).getAsteroide(j)->getLife() - (*missiles_)[i]->getDamage();
						//Si astéroide plus de vie
						if ( lifeAfterImpact <= 0)
						{
							(*player_).updateMoney((*wave_).getAsteroide(j)->getMoneyWhenExplosed());
							(*player_).updateScore((*wave_).getAsteroide(j)->getScoreWhenExplosed());
							(*wave_).incNumberOfAsteroideDestroyed();
							delete (*wave_).getAsteroide(j);
							(*wave_).deleteAsteroide(j);

							if ((*wave_).isEmpty())
								(*wave_).resetChrono();
						}
						else
						{
							(*wave_).getAsteroide(j)->setLife(lifeAfterImpact);
						}
						//Dans tous les cas delete des missiles
						delete (*missiles_)[i];
						(*missiles_)[i] = nullptr;
						missiles_->erase(missiles_->begin() + i);
					}
				}
			}
		}
		// FreezeTime avant le début de la vague
		if ((*wave_).isReadyToGo() && (*wave_).isEmpty() && !(*wave_).isActive())
		{
			(*wave_).setActive();
			(*wave_).levelUp();
			(*wave_).resetNumberOfAsteroideDesrtroyed();
			(*player_).addBonusEndOfWave((*wave_).getLevel());
		}
		//Affichage numero de vague
		(*wave_).drawNumWave();
		(*wave_).drawNumberOfAsteroide();

		if ((*wave_).isActive())
		{
			if ((*wave_).getNumberOfAsteroide() < (*wave_).getMaxAsteroide())
			{
				if ((*wave_).isReadyToPopAsteroide())
				{
					(*wave_).addAsteroide(squares_);
					(*wave_).resetChronoAsteroidePop();
				}
			}
			else
			{
				(*wave_).setInactive();
				(*wave_).resetNumberOfAsteroide();
			}
		}
		// Affichage et destructions des asteroides
		if (!(*wave_).isEmpty())
		{
			for (int i = 0; i < (*wave_).getSize(); i++)
			{
				// si Asteroide arrive tout à gauche du quadrillage
				if ((*wave_).getAsteroide(i)->getHitBoxLeft() <= (*squares_)[0][0].getX())
				{
					(*wave_).incNumberOfAsteroideDestroyed();
					(*player_).addImpact();
					delete (*wave_).getAsteroide(i);
					(*wave_).deleteAsteroide(i);

					if ((*wave_).isEmpty())
						(*wave_).resetChrono();
				}
				else
				{
					(*wave_).getAsteroide(i)->draw();
					(*wave_).getAsteroide(i)->drawVita();

					for (int j = 0; j < (int)spaceships_->size(); j++)
					{
						if ((*wave_).getAsteroide(i) != nullptr && (*spaceships_)[j] != nullptr && (*wave_).getAsteroide(i)->hitSpaceship((*spaceships_)[j]))
						{
							int lifeAsteroideAfterImpact = (*wave_).getAsteroide(i)->getLife() - (*spaceships_)[j]->getDamageImpact();
							if (lifeAsteroideAfterImpact <= 0)
							{
								(*wave_).incNumberOfAsteroideDestroyed();
								delete (*wave_).getAsteroide(i);
								(*wave_).deleteAsteroide(i);
								if ((*wave_).isEmpty())
									(*wave_).resetChrono();
							}
							else
							{
								(*wave_).getAsteroide(i)->setLife(lifeAsteroideAfterImpact);
							}
							(*squares_)[(*spaceships_)[j]->getLine()][(*spaceships_)[j]->getColumn()].restoreCptClick();
							delete (*spaceships_)[j];
							(*spaceships_)[j] = nullptr;
							spaceships_->erase(spaceships_->begin() + j);
						}
					}
				}
			}
		}
	}
	//Si Joueur Game Over
	else if ((*player_).isGameOver())
	{
		(*player_).drawGameOver();
	}
	//Si le Joueur n'a pas vu l'écran mode emploi
	else if (!(*player_).hasSeenHowToPlay())
	{
		(*player_).drawReadMe();
	}
}
