#pragma once
#include "ship.h"
#include "missileMenager.h"

class PlayerShip : public ship
{
public:
	int moveFactor;
	sf::Clock realoadTime;
	sf::Time reloadCooldown;
	PlayerShip(sf::Texture&);
	void update(sf::RenderWindow&);
	void move();
	void moveLeft();
	void moveRight();
	void shot(missileMenager* v);
	void dieEvent();
};