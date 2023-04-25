#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "missile.h"
#include "playerMisille.h"
#include "ufomissile.h"
#include "enemyMissile.h"

//#include "enemyMenager.h"
////#include "enemyShip.h"
//#include "playerShip.h"
//#include "ufoShip.h"


class missileMenager {
public:
	std::vector <missile*> missilesInSpace;
	sf::Texture playerMissileTexture;
	sf::Texture enemyMissileTexture;
	sf::Texture ufoMissileTexture;

	missileMenager(sf::Texture&, sf::Texture&, sf::Texture&);
	void update(sf::RenderWindow&);
	void flyOutCheck();
	void clearDeathMissiles();
	void addPlayerMissile(sf::Vector2f);
	void addEnemyMissile(sf::Vector2f);
	void addUfoMissile(sf::Vector2f);
	//void checkHits(enemyMenager* enemies, PlayerShip* playerShip,ufoShip* ufo);
};