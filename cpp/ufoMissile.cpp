#include "ufomissile.h"

ufoMissile::ufoMissile(sf::Texture& model, sf::Vector2f vec)
{
	id = 2;
	vec.x += 4;
	x = vec.x;
	y = vec.y;
	alive = true;
	speed = 4.f;

	missileSprite.setTexture(model);
	missileSprite.setPosition(vec);
	missileSprite.setScale(3, 3);
}

bool ufoMissile::flyOutCheck()
{
	sf::Vector2f currPoz = this->missileSprite.getPosition();

	if (currPoz.y > 820)
		return true;

	return false;
}


void ufoMissile::update(sf::RenderWindow& Win)
{
	sf::Vector2f Second = sf::Vector2f(missileSprite.getPosition().x, missileSprite.getPosition().y + speed);
	sf::Transform T;
	T.rotate(0, missileSprite.getPosition());
	missileSprite.setPosition(T.transformPoint(Second));

	Win.draw(missileSprite);
}