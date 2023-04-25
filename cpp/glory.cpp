#include "glory.h"


glory::glory()
{
	gPlayerName = "gg";
	gScore = 0;
}

bool glory::operator>(glory& _gSecondGlory)
{
	//if (this->gScore > _gSecondGlory.gScore)
	//	return *this;
	//else
	//	return _gSecondGlory;
	return this->gScore > _gSecondGlory.gScore;
}



