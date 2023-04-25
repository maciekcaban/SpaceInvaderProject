#include "graphicMenager.h"


graphicMenager::graphicMenager() {

}

void graphicMenager::loadTexturesFromFiles()
{
	//enemyOneShipModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\obcy1.png");
	//enemyTwoShipModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\obcy2.png");
	//enemyThreeShipModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\obcy3.png");
	//playerShipModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\stateczek.png");
	//ufoShipmodel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\ufo.png");
	//ufoBonusModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\paczka.png");
	//playerMissileModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\pocisk_1.png");
	//enemyMissileModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\pocisk_2.png");
	//backgroundModel.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\background.jpg");
	//_font.loadFromFile("C:\\Users\\Pawel\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\czcionka\\arial.ttf");

	enemyOneShipModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\obcy1.png");
	enemyTwoShipModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\obcy2.png");
	enemyThreeShipModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\obcy3.png");
	playerShipModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\stateczek.png");
	ufoShipmodel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\ufo.png");
	ufoBonusModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\paczka.png");
	playerMissileModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\pocisk_1.png");
	enemyMissileModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\pocisk_2.png");
	backgroundModel.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\zasoby\\background.jpg");
	_font.loadFromFile("C:\\Users\\nobodyL\\Documents\\GitHub\\74ba6498-gr52-repo\\Projekt\\SpaneInvaderProj\\czcionka\\arial.ttf");

	backgroundSprite.setPosition(0, 0);
	backgroundSprite.setTexture(backgroundModel);
}