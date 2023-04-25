#pragma once
#include <SFML/Graphics.hpp>

class missile
{
public:
	int id;
	bool alive;
	int x, y;
	int speed;
	sf::Sprite missileSprite;

	//void update(sf::RenderWindow&);
	virtual void update(sf::RenderWindow&) = 0;
	virtual bool flyOutCheck() = 0;
};