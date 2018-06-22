//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu NewGame methods
//

#include "../include/Menu_NewGame.hpp"

MenuNewGame::MenuNewGame(int xsize, int ysize)
{
	newgamesize = sf::Vector2f(xsize, ysize);
	newgamerect = sf::RectangleShape(newgamesize);
	newgamerect.setFillColor(sf::Color::Blue);
	newgamerect.setOutlineThickness(5);
	newgamerect.setOutlineColor(sf::Color::Black);
	newgamerect.setPosition(400, 140);
	if (!newgamefont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load Settings font\n");
	}
	newgametext.setFont(newgamefont);
	newgametext.setString("START");
	newgametext.setCharacterSize(20);
	newgametext.setFillColor(sf::Color::Red);
	newgametext.setPosition(410, 140);
	if (!soundbuff.loadFromFile("assets/sounds/menu/start-select.wav")) {
		fprintf(stderr, "Failed to load select sound\n");
	}
	selectsound.setBuffer(soundbuff);
	GameWindow 	game_wind;
	game = &game_wind;
}

sf::RectangleShape	MenuNewGame::getNewGameRect()
{
	return (newgamerect);
}

sf::Text 		MenuNewGame::getNewGameText()
{
	return (newgametext);
}

void			MenuNewGame::setNewGamePos(int xpos, int ypos)
{
	newgamerect.setPosition(xpos, ypos);
}

GameWindow		*MenuNewGame::getGameWindow()
{
	selectsound.play();
	return (game);
}
