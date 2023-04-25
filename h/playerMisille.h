#pragma once
#include "missile.h"

class playerMissile : public missile
{
public:
	playerMissile(sf::Texture&, sf::Vector2f);
	bool flyOutCheck();
	void update(sf::RenderWindow&);
};