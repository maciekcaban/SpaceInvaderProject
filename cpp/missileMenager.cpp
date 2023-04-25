#include "missileMenager.h"



missileMenager::missileMenager(sf::Texture& tx1, sf::Texture& tx2, sf::Texture& tx3) {
	playerMissileTexture = tx1;
	enemyMissileTexture = tx2;
	ufoMissileTexture = tx3;
}


void missileMenager::update(sf::RenderWindow& Win) 
{
	for (auto& i : missilesInSpace) 
	{
		i->update(Win);
	}
}

void missileMenager::flyOutCheck() 
{
	for (int i = 0; i < missilesInSpace.size(); i++)
	{
		if (missilesInSpace[i]->flyOutCheck())
		{
			missilesInSpace[i]->alive = false;
		}
	}
}

void missileMenager::clearDeathMissiles() 
{
	for (int i = 0; i < missilesInSpace.size(); i++)
	{
		if (missilesInSpace[i]->alive == false)
		{
			delete missilesInSpace[i];
			missilesInSpace.erase(missilesInSpace.begin() + i, missilesInSpace.begin() + i + 1);
		}
	}
}

void missileMenager::addPlayerMissile(sf::Vector2f vec) 
{

	missilesInSpace.push_back(new playerMissile(playerMissileTexture, vec));
}

void missileMenager::addEnemyMissile(sf::Vector2f vec)
{
	missilesInSpace.push_back(new enemyMissile(enemyMissileTexture, vec));
}

void missileMenager::addUfoMissile(sf::Vector2f vec)
{
	missilesInSpace.push_back(new ufoMissile(ufoMissileTexture, vec));
}

