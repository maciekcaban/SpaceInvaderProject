#include "enemyMenager.h"

enemyMenager::enemyMenager(sf::Texture& tx1, sf::Texture& tx2, sf::Texture& tx3 )
{
	enemyCount = 21;
	intoRight = true;
	intoDown = 500;
	moveCounter = 0;	

	for (int i = 0; i < enemyCount/3; i++)
	{
		enemyLines.push_back(new enemyShip(30, 100 * i, 50, tx1) );
	}
	for (int i = 0; i < enemyCount/3; i++)
	{
		enemyLines.push_back(new enemyShip(20, 100 * i, 100, tx2));
	}
	for (int i = 0; i < enemyCount/3; i++)
	{
		enemyLines.push_back(new enemyShip(10, 100 * i, 150, tx3));
	}
}

void enemyMenager::update(sf::RenderWindow& Win)
{
	if (moveCounter < intoDown) //czy idzie na boki
	{
		for (int i = 0; i < enemyLines.size(); i++)
		{
			enemyLines[i]->move(intoRight);
			Win.draw(enemyLines[i]->shipModel);
			//std::cout << "statek przemieszczony:   " << i << std::endl;
		}
		moveCounter++;
	}
	else 
	{
		for (int i = 0; i < enemyLines.size(); i++)
		{
			enemyLines[i]->moveDown();
			Win.draw(enemyLines[i]->shipModel);
		}
		moveCounter = 0;
		if (intoRight == true)
		{
			intoRight = false;
		}
		else
		{
			intoRight = true;
		}
	}
	//std::cout << moveCounter << std::endl;
}

//sprawdza czy jakis przeciwnik ma alive=fasle (nie zyje) i go usuwa
void enemyMenager::checkEnemyDie(int & scr)
{
	for (int i = 0; i < enemyLines.size(); i++)
	{
		if (enemyLines[i]->alive == false)
		{
			scr = scr + enemyLines[i]->scoreValue;
			delete enemyLines[i];
			enemyLines.erase(enemyLines.begin()+i, enemyLines.begin()+i+1);
			enemyCount--;
			//i--;
		}
	}
}

bool enemyMenager::checkEnemyAtTheGate()
{
	if (enemyCount > 0)
	{
		sf::Vector2f vec = enemyLines[0]->shipModel.getPosition();
		if (vec.y + 30 > 740)
			return true;
	}
	return false;
}

void enemyMenager::shot(missileMenager* v)
{
	if (enemyCount > 0) 
	{
		reloadCooldown = sf::seconds(0.5 * enemyLines.size());
		if (shotTimer.getElapsedTime() > reloadCooldown)
		{
			shotTimer.restart();
			srand(time(NULL));
			int random;
			random = rand() % enemyLines.size();
			sf::Vector2f vec = enemyLines[random]->shipModel.getPosition();
			v->addEnemyMissile(vec);
		}
	}
}