#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//po tym bedzie dziedziczyc ufo, gracz i obcy
class ship {
public:
	bool alive;
	float speed;
	int x, y;

	sf::Sprite shipModel;
	void update();
	void dieEvent();
};