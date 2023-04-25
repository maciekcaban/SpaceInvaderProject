#pragma once
#include "missile.h"


class ufoMissile : public missile
{
public:
	ufoMissile(sf::Texture&, sf::Vector2f);
	bool flyOutCheck();
	void update(sf::RenderWindow&);
};