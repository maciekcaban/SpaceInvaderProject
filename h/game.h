#include <SFML/Graphics.hpp>
#include "graphicMenager.h"
#include "player.h"
#include "mainMenu.h"

#include "playerShip.h"
#include "ufoShip.h"
#include "enemyMenager.h"

#include "playerMisille.h"
#include "missileMenager.h"

#include <future>


class game {
	//mode 1 - menu
	//mode 2 - controls
	//mode 3 - game
	//mode 4 - nowy gracz
	sf::RenderWindow Win;
	graphicMenager Graf1;
	mainMenu Menu1;
	player Player1;

public:
	int gamestatus;

	game();
	void runGame();
	void checkHits(enemyMenager* enemies, PlayerShip* playerShip,ufoShip* ufo, missileMenager* missiles);
	void resetGame(ufoShip&, PlayerShip&, enemyMenager&, missileMenager&, sf::Texture& tx1, sf::Texture& tx2, sf::Texture& tx3);
};