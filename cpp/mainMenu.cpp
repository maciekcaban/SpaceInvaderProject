#include "mainMenu.h"

//zamienia _ na spacje
char UnderLineToSpace(const char x)
{
	if (x == '_')
		return ' ';
	return x;
}

bool sortGlory( glory g1, glory g2)
{
	return (g1 > g2);
}

mainMenu::mainMenu()
{
	//_font = f;
}

void mainMenu::setFontInMenu(sf::Font& f)
{
	_font = f;
}

void mainMenu::showMenu(sf::RenderWindow& W)
{
	std::string nap1 = "";
	sf::Text txt1;

	txt1.setFont(_font);
	txt1.setFillColor(sf::Color::White);
	txt1.setCharacterSize(24);

	for (int i = 0; i < menuData.size(); i++)
	{
		nap1 = menuData[i];
		txt1.setString(nap1);
		txt1.setPosition(300, 100 + 100 * i);
		W.draw(txt1);
	}
}

void mainMenu::loadMenuData()
{
	std::filesystem::path path1;
//	path1 = "C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\napisy\\menu.txt";
	path1 = "C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\napisy\\menu.txt";

	std::ifstream odczyt(path1);
	std::string nap1;
	std::string nap2;


	while (odczyt >> nap1)
	{
		std::ranges::copy(std::views::transform(nap1, UnderLineToSpace), std::back_inserter(nap2));
		menuData.push_back(nap2);
		nap2 = "";
	}
	odczyt.close();
}

void mainMenu::loadControls()
{
	std::filesystem::path path1;
	//path1 = "C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\napisy\\sterowanie.txt";
	path1 = "C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\napisy\\sterowanie.txt";
	std::ifstream odczyt(path1);
	std::string nap1;


	while (std::getline(odczyt,nap1))
	{
		controlsData.push_back(nap1);
	}
	odczyt.close();
}

void mainMenu::showControls(sf::RenderWindow &W)
{
	std::string nap1 = "";
	sf::Text txt1;

	txt1.setFont(_font);
	txt1.setFillColor(sf::Color::White);
	txt1.setCharacterSize(24);

	for (int i = 0; i < controlsData.size(); i++)
	{
		nap1 = controlsData[i];
		txt1.setString(nap1);
		txt1.setPosition(300, 100 + 50 * i);
		W.draw(txt1);
	}
}

void mainMenu::loadGlory()
{
	std::filesystem::path path1;
	//path1 = "C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\glory hole\\chwala.txt";
	path1 = "C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\glory hole\\chwala.txt";

	std::ifstream odczyt(path1);
	std::string input;
	std::string name = "";
	std::string scr = "";
	int scr_int;
	glory glory1;
	std::regex reg ("\\w+;\\d+");
	
	
	std::smatch result;
	std::getline(odczyt, gloryString);

	while (std::getline(odczyt, input))
	{
		//std::cout << input << std::endl;
		if (std::regex_match(input, result, reg))
		{
			name = "";
			scr = "";

			for (char x : std::ranges::take_while_view(input, [](char c) { return c != ';'; })) {
				name = name + x;
				//std::cout << x;
			}

			for (char n : std::ranges::drop_while_view(input, [](char i) { return i != ';'; })) {
				//std::cout << n << ' ';
				scr = scr + n;
			}

			scr.erase(0, 1);
			scr_int = stoi(scr);

			glory1.gPlayerName = name;
			glory1.gScore = scr_int;
			gloryData.push_back(glory1);
		}
	}
	odczyt.close();

	std::ranges::sort(gloryData.begin(), gloryData.end(), sortGlory);

}

void mainMenu::showGlory(sf::RenderWindow& W)
{
	std::string nap1 = gloryString;
	sf::Text txt1;
	int sec;

	txt1.setFont(_font);
	txt1.setFillColor(sf::Color::White);
	txt1.setCharacterSize(24);

	txt1.setPosition(800, 100);
	txt1.setString(nap1);
	W.draw(txt1);

	txt1.setCharacterSize(24);
	for (int i = 0; i < gloryData.size(); i++)
	{
		nap1 = gloryData[i].gPlayerName;
		sec = gloryData[i].gScore;
		nap1 = nap1 + " - " + std::to_string(sec);
		txt1.setString(nap1);
		txt1.setPosition(800, 150 + 50 * i);
		W.draw(txt1);
	}
}

void mainMenu::saveGlory()
{
	std::filesystem::path path2;
	//path2 = "C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\glory hole\\chwala1.txt";
	path2 = "C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\glory hole\\chwala.txt";
	
	std::ofstream zapis(path2);

	zapis << gloryString << std::endl;

	std::ranges::for_each(gloryData.begin(), gloryData.end(), [&zapis](glory it) { zapis << it.gPlayerName << ";";
	zapis << it.gScore << std::endl; });
}

void mainMenu::updateGlory(std::string gamer1, int scr)
{
	glory g1;
	g1.gPlayerName = gamer1;
	g1.gScore = scr;

	gloryData.push_back(g1);
	std::ranges::sort(gloryData, [](glory a, glory b) { return a > b; });
}