#include "glory.h"
#include <vector>
#include <ranges>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <regex>

class mainMenu {
public:
	std::vector <std::string> menuData;
	std::vector <glory> gloryData;
	std::vector <std::string> controlsData;
	sf::Font _font;
	std::string gloryString;

	//ustawia menu
	mainMenu();
	//ustawia czcionke
	void setFontInMenu(sf::Font&);
	//odpowiada za wyswieltanie opcji menu
	void showMenu(sf::RenderWindow&);
	//wyswietla najlepsze wyniki
	void showGlory(sf::RenderWindow&);
	//laduje najlepszych graczy z pliku
	void loadGlory();
	//laduje odpcje menu z pliku
	void loadMenuData();
	//zapisuje najlepszych graczy do pliku
	void saveGlory();
	//dodaje nowy wynik do vectora
	void updateGlory(std::string, int);
	//wyswietla sterowanie
	void showControls(sf::RenderWindow&);
	//wczytuje opis sterowania
	void loadControls();
};