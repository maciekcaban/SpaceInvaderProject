#include "playerMisille.h"

playerMissile::playerMissile(sf::Texture& model, sf::Vector2f vec)
{
	id = 1;
	vec.x += 4;
	x = vec.x;
	y = vec.y;
	alive = true;
	speed = 3.f;

	missileSprite.setTexture(model);
	missileSprite.setPosition(vec);	
	missileSprite.setScale(1.5, 1.5);
}

bool playerMissile::flyOutCheck()
{
	sf::Vector2f currPoz = this->missileSprite.getPosition();

	if (currPoz.y < -20)
		return true;

	return false;
}

void playerMissile::update(sf::RenderWindow& Win)
{
	sf::Vector2f Second = sf::Vector2f(missileSprite.getPosition().x, missileSprite.getPosition().y - speed);
	sf::Transform T;
	T.rotate(0, missileSprite.getPosition());
	missileSprite.setPosition(T.transformPoint(Second));

	Win.draw(missileSprite);
}

