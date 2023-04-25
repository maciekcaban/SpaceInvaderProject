#include "enemyMissile.h"

enemyMissile::enemyMissile(sf::Texture& model, sf::Vector2f vec)
{
	id = 3;
	vec.x += 4;
	x = vec.x;
	y = vec.y;
	alive = true;
	speed = 3.f;

	missileSprite.setTexture(model);
	missileSprite.setPosition(vec);
	missileSprite.rotate(180);
	missileSprite.setScale(2, 2);
}

bool enemyMissile::flyOutCheck()
{
	sf::Vector2f currPoz = this->missileSprite.getPosition();

	if (currPoz.y >820)
		return true;

	return false;
}

void enemyMissile::update(sf::RenderWindow& Win)
{
	sf::Vector2f Second = sf::Vector2f(missileSprite.getPosition().x, missileSprite.getPosition().y + speed);
	sf::Transform T;
	T.rotate(0, missileSprite.getPosition());
	missileSprite.setPosition(T.transformPoint(Second));

	Win.draw(missileSprite);
}

