#include "Wave.h"


Wave::Wave() :level_(0), frequency_(1), freezeTime_(2000), waveActive_(false),
numberOfAsteroide_(0), cadencePop_(1), frequencePop_(0), asteroideDestroyed_(0){}

Wave::~Wave(){}

void Wave::drawNumWave()
{
	char * numWave = new char[100];

	Utility::itoa(level_, numWave);
	GraphicPrimitives::drawText2D("Vague :", -0.98f, 0.90f, 255.0/255.0f,216.0/255.0f, 0.0f);
	GraphicPrimitives::drawText2D(numWave, -0.92f, 0.82, 1.0f, 1.0f, 1.0f);

	delete[] numWave;
}

void Wave::addAsteroide(std::vector<std::vector<Square> > *squares)
{
	int random;
	int randomCase = rand() % 10;
	if (level_ < 5)
		random = 0;
	else if (level_ >= 5 && level_ < 10)
		random = rand() % 2;
	else if (level_ == 10)
		random = rand() % 3;
	else if (level_ > 10 && level_ <= 15)
		random = rand() % 2 + 1;
	else
		random = 3;
	switch (random)
	{
	case 0:
		asteroides_.push_back(new Hypnos((*squares)[9][randomCase].getX() + (*squares)[0][0].getSide(), (*squares)[0][randomCase].getY() + ((*squares)[0][0].getSide() / 2)));
		break;
	case 1:
		asteroides_.push_back(new Eros((*squares)[9][randomCase].getX() + (*squares)[0][0].getSide(), (*squares)[0][randomCase].getY() + ((*squares)[0][0].getSide() / 2)));
		break;
	case 2:
		asteroides_.push_back(new Icare((*squares)[9][randomCase].getX() + (*squares)[0][0].getSide(), (*squares)[0][randomCase].getY() + ((*squares)[0][0].getSide() / 2)));
		break;
	case 3:
		asteroides_.push_back(new Icare((*squares)[9][randomCase].getX() + (*squares)[0][0].getSide(), (*squares)[0][randomCase].getY() + ((*squares)[0][0].getSide() / 2), 0.0008));
		break;
	default:
		break;
	}
	numberOfAsteroide_++;
}

bool Wave::isReadyToGo()
{
	bool fire = frequency_%freezeTime_== 0;
	frequency_ = (frequency_ + 1) % freezeTime_;

	return fire;
}

bool Wave::isReadyToPopAsteroide()
{
	if (level_ < 5)
		frequencePop_ = 1500;
	else if (level_ >= 5 && level_ < 10)
		frequencePop_ = 1300;
	else if (level_ >= 10 && level_ < 15)
		frequencePop_ = 1100;
	else if (level_ >= 15)
		frequencePop_ = 600;

	bool ready = cadencePop_%frequencePop_ == 0;
	cadencePop_ = cadencePop_ + 1 % frequencePop_;

	return ready;
}

void Wave::drawNumberOfAsteroide()
{
	char * numberOfAsteroide = new char[100];
	char * maxAsteroide = new char[100];
	float x = -0.99f;
	Utility::itoa(asteroideDestroyed_, numberOfAsteroide);
	Utility::itoa(getMaxAsteroide(), maxAsteroide);
	GraphicPrimitives::drawText2D("Asteroides  :", x, -0.90f, 255 / 255.0, 216 / 255.0, 0.f);
	GraphicPrimitives::drawText2D(numberOfAsteroide, x+0.28, -0.90f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(" /  ", x+0.32, -0.90f, 255 / 255.0, 216 / 255.0, 0.f);
	GraphicPrimitives::drawText2D(maxAsteroide, x+0.35, -0.90f, 255 / 255.0, 216 / 255.0, 0.f);

	delete[] numberOfAsteroide;
	delete[] maxAsteroide;
}