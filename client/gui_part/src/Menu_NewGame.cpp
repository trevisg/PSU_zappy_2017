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
	newgamebutton = sf::CircleShape(45.0);
	newgamebutton.setFillColor(sf::Color::Black);
	newgamebutton.setOutlineThickness(5);
	newgamebutton.setOutlineColor(sf::Color::White);
	newgamebutton.setPosition(920, 300);
	if (!newgamefont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load Settings font\n");
	}
	newgametext.setFont(newgamefont);
	newgametext.setString("START");
	newgametext.setCharacterSize(15);
	newgametext.setFillColor(sf::Color::White);
	newgametext.setPosition(920, 330);
	if (!soundbuff.loadFromFile("assets/sounds/menu/start-select.wav")) {
		fprintf(stderr, "Failed to load select sound\n");
	}
	selectsound.setBuffer(soundbuff);
}

sf::CircleShape	MenuNewGame::getnewgamebutton()
{
	return (newgamebutton);
}

sf::Text 		MenuNewGame::getNewGameText()
{
	return (newgametext);
}

void			MenuNewGame::setNewGamePos(int xpos, int ypos)
{
	newgamebutton.setPosition(xpos, ypos);
}

GameWindow		*MenuNewGame::getGameWindow()
{
	GameWindow 	game_wind;
	GameWindow *game = &game_wind;
	selectsound.play();
	return (game);
}
