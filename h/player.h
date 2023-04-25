#pragma once
#include "graphicMenager.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <regex>

class player {
public:

	int playerScore;
	std::string playername;

	player();
	bool newPlayer(std::string&);
	void showPlayer(sf::RenderWindow&, sf::Font);
};