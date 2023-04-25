#pragma once
#include "ship.h"
#include "missileMenager.h"
#include "missile.h"

class ufoShip :public ship
{
public:
	sf::Time spawnCooldown;
	sf::Clock ufoClock;
	int deathFactor;
	ufoShip(sf::Texture&);
	void move();
	void update(sf::RenderWindow& W);
	void dieEvent(missileMenager*);
	void flyOutEvent();
};