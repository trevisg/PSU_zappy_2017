//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Title methods
//

#include "../include/Menu_Title.hpp"

/**
*  @todo must write the below text instead of the present one:
* ## Keys : ##
*
* - [esc] : Close this windows and the newgame one\
* - [f1] : Pause background music\
* - See the top left white text inputs ? **please enter the server address (127.0.0.1 by default)**\
* - Now enter the port number\
* - Click on start button\
* - Enjoy!\
*
*/
 #define CMDS "[esc] to quit, [f1] to stop music & click [start] to run!"

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
	TitleText.setFillColor(sf::Color::White);
	TitleText.setPosition(x, y);
	menuhelptext.setFont(TitleFont);
	menuhelpstring = sf::String(CMDS);
	menuhelptext.setString(menuhelpstring);
	menuhelptext.setFillColor(sf::Color::White);
	menuhelptext.setPosition(220, 800);
}

sf::Text	MenuTitle::get_menuTitleText()
{
	return TitleText;
}

sf::Text	MenuTitle::get_menuHelpText()
{
	return menuhelptext;
}
