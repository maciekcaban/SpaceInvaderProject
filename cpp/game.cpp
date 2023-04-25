#include "game.h"

game::game()
{
    gamestatus = 1;

    //ladowanie grafiki 
    std::future <void> f1 = std::async([&]() {Graf1.loadTexturesFromFiles(); });
    //ladowanie danych do menu
    std::future <void> f2 = std::async(&mainMenu::loadGlory, &Menu1);
    std::future <void> f3 = std::async([&]() {Menu1.loadControls(); });
    std::future <void> f4 = std::async([&]() {Menu1.loadMenuData(); });
   
    f1.wait();
    f2.wait();
    f3.wait();
    f4.wait();

    Menu1.setFontInMenu(Graf1._font);

    //tworzenie i konfiguracja okna
    Win.create(sf::VideoMode(1200, 800, 32), "SpaceInvaders");
    Win.setActive(true);
    Win.setFramerateLimit(60);
    Win.setVerticalSyncEnabled(false);
    Win.setPosition(sf::Vector2i(0, 0)); //lewy gorny rog okna
}

void game::checkHits(enemyMenager* enemies, PlayerShip* playerShip, ufoShip* ufo, missileMenager* missiles)
{
	for (auto v : missiles->missilesInSpace)
	{
		//pocisk gracza
		if (v->id == 1)
		{
            //kolizje z enemy
			for (auto e : enemies->enemyLines)
			{
				if (v->missileSprite.getGlobalBounds().intersects(e->shipModel.getGlobalBounds()))
				{
					//enemy zostal trafiony
					v->alive = false;
					e->alive = false;
					break;
				}
			}
            //kolizja z ufo
            if (v->missileSprite.getGlobalBounds().intersects(ufo->shipModel.getGlobalBounds()))
            {
                //ufo zostalo trafione
                ufo->dieEvent(missiles);
                v->alive = false;
                ufo->alive = false;
                break;
            }
		}
        else
        //paczka ufo
            if (v->id == 2)
            {
                if (v->missileSprite.getGlobalBounds().intersects(playerShip->shipModel.getGlobalBounds()))
                {
                    //paczka zlapana
                    v->alive = false;
                    Player1.playerScore += 130;
                }
            }
            else
                if (v->id == 3)
                {
                    if (v->missileSprite.getGlobalBounds().intersects(playerShip->shipModel.getGlobalBounds()))
                    {
                        //gracz zostal trafiony
                        v->alive = false;
                        playerShip->alive = 0;
                        Menu1.updateGlory(Player1.playername, Player1.playerScore);
                    }
                }
	}
}

void game::runGame()
{
    //tworzenie obiektow do gry
    PlayerShip playerShip1(Graf1.playerShipModel);
    ufoShip ufo1(Graf1.ufoShipmodel);
    enemyMenager enemyMenager1(Graf1.enemyOneShipModel, Graf1.enemyTwoShipModel, Graf1.enemyThreeShipModel);
    missileMenager missileMenager1(Graf1.playerMissileModel, Graf1.enemyMissileModel, Graf1.ufoBonusModel);

    //tworzenie wskaznikow
    missileMenager* missileMenagerPointer = &missileMenager1;
    enemyMenager* enemyMenagerPoiter = &enemyMenager1;
    PlayerShip* PlayerShipPoiter = &playerShip1;
    ufoShip* ufoShipPoiter = &ufo1;
    std::string newPlayerName = "";
    //rungame
    /// -------------------pêtla g³ówna okna------------------------ ///
    while (Win.isOpen())
    {
        /// ---------------- wydarzenia ---------------- ///
        sf::Event Ev;
        while (Win.pollEvent(Ev))
        {
            if (Ev.type == sf::Event::Closed)
                Win.close();

            //sprawddzanie czy escape wcisnieto
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                Win.close();
            }

            //sterowanie w menu
            if (gamestatus == 1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                {
                    //start gry
                    gamestatus = 3;
                    ufo1.ufoClock.restart();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                {
                    //nowy gracz
                    gamestatus = 4;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                {
                    //wyswietl sterowanie
                    gamestatus = 2;
                }
            }
            //sterowanie w menu sterowania
            if (gamestatus == 2 and sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                //powrot do menu 
                gamestatus = 1;
            }

            //sterowanie w grza
            if (gamestatus == 3)
            {
                //std::cout << "gra dziala" << std::endl;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))    //lewo
                {
                    playerShip1.moveFactor = 1;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))    //prawo
                {
                    playerShip1.moveFactor = 2;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)==false and sf::Keyboard::isKeyPressed(sf::Keyboard::D)==false)
                {
                    playerShip1.moveFactor = 0;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    playerShip1.shot(missileMenagerPointer);
                }
            }

            //podawanie nicku nowego gracza
            if (gamestatus == 4)
            {
                //po wcisnieciu enter spradza czy nick jest poprawny
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    if (Player1.newPlayer(newPlayerName))
                    {
                        gamestatus = 1;
                        newPlayerName.clear();
                    }
                    else
                        newPlayerName.clear();
                }

                //wczytuje nowy nick

                if (Ev.type == sf::Event::TextEntered)
                {
                    char newMark = Ev.text.unicode;
                    std::cout << (char)newMark << std::endl;
                    newPlayerName += (char)newMark;

                    std::cout << "new name:" << std::endl;
                    for (int i=0; i<newPlayerName.size();i++)
                    {
                        std::cout << (char)newPlayerName[i];
                    }
                    std::cout<<std::endl;
                }
            }
        }
        /// --------------- tworzymy klatkê obrazu ------------------ ///
        Win.clear(sf::Color::Black);
        Win.draw(Graf1.backgroundSprite);
        Player1.showPlayer(Win, Graf1._font);

        if (gamestatus == 1)
        {
            Menu1.showMenu(Win);
            Menu1.showGlory(Win);
        }
        if (gamestatus == 2)
        {
            Menu1.showControls(Win);
        }
        //gra
        if (gamestatus == 3)
        {
            //playerShip move
            if (playerShip1.moveFactor !=0)
            {
                playerShip1.move();
            }
            playerShip1.update(Win);

            //ufo
            ufo1.update(Win);

            //enemy
            enemyMenager1.update(Win);
            enemyMenager1.checkEnemyDie(Player1.playerScore);
            enemyMenager1.shot(missileMenagerPointer);

            //pociski
            missileMenager1.update(Win);
            missileMenager1.flyOutCheck();
            missileMenager1.clearDeathMissiles();

            checkHits(enemyMenagerPoiter, PlayerShipPoiter, ufoShipPoiter, missileMenagerPointer);

            if (playerShip1.alive == false or enemyMenager1.enemyCount==0 or enemyMenager1.checkEnemyAtTheGate()==true)
            {
               resetGame(ufo1, playerShip1, enemyMenager1, missileMenager1, Graf1.enemyOneShipModel, Graf1.enemyTwoShipModel, Graf1.enemyThreeShipModel);
               //gamestatus = 1;
            }
        }
        Win.display();
    }

    Menu1.updateGlory(Player1.playername,Player1.playerScore);
    Menu1.saveGlory();
}

void game::resetGame(ufoShip & ufo, PlayerShip& playerShip1, enemyMenager& enemies, missileMenager & missiles, sf::Texture& tx1, sf::Texture& tx2, sf::Texture& tx3)
{
    std::cout << "restarting" << std::endl;
    gamestatus = 1;
    Player1.playerScore = 0;

    //ufo
    ufo.alive = true;
    ufo.x = 0;
    ufo.y = 50;
    ufo.deathFactor = 0;
    ufo.shipModel.setPosition(ufo.x, ufo.y);

    //playerShip
    playerShip1.x = 550;
    playerShip1.y = 740;
    playerShip1.alive = true;
    playerShip1.shipModel.setPosition(playerShip1.x, playerShip1.y);

    //enemyMenager
    enemies.enemyCount = 21;
    enemies.intoRight = true;
    enemies.intoDown = 500;
    enemies.moveCounter = 0;
    for (int i = 0; i < enemies.enemyLines.size(); i++)
    {
        delete enemies.enemyLines[i];
    }
    enemies.enemyLines.clear();
    for (int i = 0; i < enemies.enemyCount / 3; i++)
    {
        enemies.enemyLines.push_back(new enemyShip(30, 100 * i, 50, tx1));
    }
    for (int i = 0; i < enemies.enemyCount / 3; i++)
    {
        enemies.enemyLines.push_back(new enemyShip(20, 100 * i, 100, tx2));
    }
    for (int i = 0; i < enemies.enemyCount / 3; i++)
    {
        enemies.enemyLines.push_back(new enemyShip(10, 100 * i, 150, tx3));
    }

    //missilemenager
    for (int i = 0; i < missiles.missilesInSpace.size(); i++)
    {
        delete missiles.missilesInSpace[i];
    }
    missiles.missilesInSpace.clear();

    std::cout << "restart finished" << std::endl;
}
