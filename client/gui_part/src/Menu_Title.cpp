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
	if (!TitleFont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load font\n");
	}
	TitleText.setFont(TitleFont);
	TitleString = sf::String("Menu");
	TitleText.setString(TitleString);
	TitleText.setCharacterSize(50);
	TitleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	TitleText.setFillColor(sf::Color::Blue);
	TitleText.setPosition(x, y);
}

sf::Text	MenuTitle::get_menuTitleText()
{
	return TitleText;
}
