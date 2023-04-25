#pragma once
#include "ship.h"
#include "enemyShip.h"
#include "missileMenager.h"

#include <vector>
#include <stdlib.h>
#include <time.h> 

class enemyMenager
{
public:
	int enemyCount;
	bool intoRight;
	long int intoDown;
	long int moveCounter;
	sf::Clock shotTimer;
	sf::Time reloadCooldown;
	//std::list <enemy*>enemyLines;
	std::vector <enemyShip*> enemyLines;

	enemyMenager(sf::Texture& tx1, sf::Texture& tx2, sf::Texture& tx3);
	void update(sf::RenderWindow& Win);
	void shot(missileMenager*);
	void checkEnemyDie(int&);
	bool checkEnemyAtTheGate();
};