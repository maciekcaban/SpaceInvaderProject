#include "enemyShip.h"

enemyShip::enemyShip(int scr, int _x, int _y, sf::Texture& tx1)
{
	speed = 1.f;
	speedDown = 10.f;
	x = _x;
	y = _y;
	alive = true;

	scoreValue = scr;
	shipModel.setTexture(tx1);
	shipModel.setPosition(x, y);
	shipModel.setScale(3, 3);
}

void enemyShip::move(bool intoRight)
{
	if (intoRight == 1)
	{
		shipModel.move(speed, 0);
	}
	else
	{
		shipModel.move(-speed, 0);
	}
	return;
}

void enemyShip::moveDown()
{
	shipModel.move(0, speedDown);
	return;
}

void enemyShip::enemyUpdate(sf::RenderWindow& Win)
{

}