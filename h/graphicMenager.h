#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
//#include <fstream>

class graphicMenager
{
public:
	sf::Texture enemyOneShipModel;
	sf::Texture enemyTwoShipModel;
	sf::Texture enemyThreeShipModel;
	sf::Texture playerShipModel;
	sf::Texture ufoShipmodel;

	sf::Texture ufoBonusModel;
	sf::Texture playerMissileModel;
	sf::Texture enemyMissileModel;
	sf::Texture backgroundModel;
	sf::Font _font;

	sf::Sprite backgroundSprite;
	graphicMenager();
	void loadTexturesFromFiles();
};