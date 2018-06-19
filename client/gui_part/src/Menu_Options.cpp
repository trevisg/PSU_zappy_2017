//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Options methods
//

#include "../include/Menu_Options.hpp"

MenuOptions::MenuOptions(int xsize, int ysize)
{
	optionspos = sf::Vector2f(xsize, ysize);
	optionsrect = sf::RectangleShape(optionspos);
	optionsrect.setFillColor(sf::Color::Black);
	optionsrect.setOutlineThickness(10);
	optionsrect.setOutlineColor(sf::Color::Red);
	if (!optionsfont.loadFromFile("assets/fonts/elasis.ttf")) {
		fprintf(stderr, "Failed to load options font\n");
	}
	optiontext.setFont(optionsfont);
	optiontext.setString("Options");
	optiontext.setCharacterSize(20);
	optiontext.setStyle(sf::Text::Underlined);
	optiontext.setFillColor(sf::Color::Red);
	optiontext.setPosition(10, 40);
}

sf::RectangleShape	MenuOptions::getOptsRect()
{
	return optionsrect;
}

sf::Text 		MenuOptions::getOptsText()
{
	return optiontext;
}
