#include "player.h"

player::player()
{
	playername = "nowy gracz";
	playerScore = 0;
}

bool player::newPlayer(std::string &newName)
{
	std::regex reg("\\w*");
	//std::regex reg("\d");
	std::smatch result;
	if (std::regex_match(newName,result, reg));
	{
		std::cout << "xd" << std::endl;
		playername = newName;
		return true;

	}
	return false;
}

void player::showPlayer(sf::RenderWindow& W, sf::Font _font)
{
	sf::Text txt1;

	txt1.setFont(_font);
	txt1.setFillColor(sf::Color::White);
	txt1.setCharacterSize(24);

	txt1.setPosition(0, 0);
	txt1.setString(playername);
	W.draw(txt1);

	txt1.setPosition(0, 30);
	txt1.setString(std::to_string(playerScore));
	W.draw(txt1);
}
