#pragma once
#include "missile.h"

class enemyMissile : public missile
{
public:
	enemyMissile(sf::Texture&, sf::Vector2f);
	bool flyOutCheck();
	void update(sf::RenderWindow&);
};