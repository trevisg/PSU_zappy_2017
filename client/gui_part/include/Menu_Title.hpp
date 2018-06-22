//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Title header
//

#ifndef MENU_TITLE_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	MenuTitle
{
	public:
		MenuTitle(int xpos, int ypos);
		sf::Text get_menuTitleText();
	private:
		int 		x;
		int 		y;
		sf::Font	TitleFont;
		sf::Text	TitleText;
		sf::String	TitleString;
};

#endif /* !MENU_TITLE_HPP_ */
