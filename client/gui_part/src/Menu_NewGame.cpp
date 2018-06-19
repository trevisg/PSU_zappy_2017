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
	newgamerect.setPosition(200, 100);
	if (!newgamefont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load options font\n");
	}
	newgametext.setFont(newgamefont);
	newgametext.setString("Options");
	newgametext.setCharacterSize(20);
	newgametext.setStyle(sf::Text::Underlined);
	newgametext.setFillColor(sf::Color::Red);
	newgametext.setPosition(100, 40);
}

sf::RectangleShape	MenuNewGame::getNewGameRect()
{
	return newgamerect;
}

sf::Text 		MenuNewGame::getNewGameText()
{
	return newgametext;
}

void			MenuNewGame::setNewGamePos(int xpos, int ypos)
{
	newgamerect.setPosition(xpos, ypos);
}
