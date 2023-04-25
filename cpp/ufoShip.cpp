#include "ufoShip.h"

ufoShip::ufoShip(sf::Texture &shipPng)
{
	alive = 1;
	speed = 0.8f;
	x = 0;
	y = 50;
	spawnCooldown = sf::seconds(5);
	deathFactor = 0;

	shipModel.setTexture(shipPng);
	shipModel.setPosition(x, y);
	shipModel.setScale(3, 3);
}

void ufoShip::move()
{
	sf::Vector2f currP = shipModel.getPosition();
	if (currP.x < 1200)
		shipModel.move(speed, 0);
	else
		flyOutEvent();
	return;
}

void ufoShip::update(sf::RenderWindow& Win)
{
	
	if (alive == true and ufoClock.getElapsedTime() > spawnCooldown)
	{
		move();
		Win.draw(shipModel);
	}
	
}

void ufoShip::dieEvent(missileMenager* v)
{
	//zrzucic paczke z bonusem
	v->addUfoMissile(shipModel.getPosition());
	alive = false;
	deathFactor = 0;
	shipModel.setPosition(1300, 0);
}

void ufoShip::flyOutEvent()
{
	alive = 0;
	shipModel.setPosition(1300, 0);
}