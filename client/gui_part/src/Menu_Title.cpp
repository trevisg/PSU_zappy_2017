//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Title methods
//

#include "../include/Menu_Title.hpp"

MenuTitle::MenuTitle(int xpos, int ypos)
{
	x = xpos;
	y = ypos;
	if (!titlefont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load font\n");
	}
	titletext.setFont(titlefont);
	titlestring = sf::String("Menu");
	titletext.setString(titlestring);
	titletext.setCharacterSize(50);
	titletext.setStyle(sf::Text::Bold | sf::Text::Underlined);
	titletext.setFillColor(sf::Color::Blue);
	titletext.setPosition(x, y);
}

sf::Text	MenuTitle::get_menutitletext()
{
	return titletext;
}
