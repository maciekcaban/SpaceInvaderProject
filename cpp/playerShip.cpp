#include "playerShip.h"

PlayerShip::PlayerShip(sf::Texture& shipPng)
{
	alive = true;
	speed = 5.f;
	x = 550;
	y = 740;
	reloadCooldown = sf::seconds(3);
	moveFactor = 0;

	shipModel.setTexture(shipPng);
	shipModel.setPosition(x, y);
	shipModel.setScale(2, 2);
}

void PlayerShip::update(sf::RenderWindow& Win)
{
	Win.draw(shipModel);
}

void PlayerShip::moveLeft()
{
	sf::Vector2f currP = shipModel.getPosition();
	if (currP.x > 0)
		shipModel.move(-3.f, 0);
	return;
}

void PlayerShip::moveRight()
{
	sf::Vector2f currP = shipModel.getPosition();
	if (currP.x < 1150)
		shipModel.move(3.f, 0);
	return;
}

void PlayerShip::dieEvent()
{
	//zmienic status menu
	//dopisac wynik do GloryDate
}

void PlayerShip::move()
{
	if (moveFactor == 1)
		moveLeft();
	else
		moveRight();
}

void PlayerShip::shot(missileMenager *v)
{
	if (realoadTime.getElapsedTime() > reloadCooldown)
	{
		v->addPlayerMissile(shipModel.getPosition());
		realoadTime.restart();
	}
}