#pragma once
#include "ship.h"

class enemyShip : public ship
{
public:
	int scoreValue;
	int speedDown;

	enemyShip(int idType, int _x, int _y,sf::Texture&);
	void move(bool);
	void moveDown();
	//void enemyShot();
	void enemyUpdate(sf::RenderWindow&);
};	