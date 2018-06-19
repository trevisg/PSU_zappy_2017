//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu Options header
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class MenuOptions {
	public:
		MenuOptions(int xsize, int ysize);
		sf::RectangleShape	getOptsRect();
		sf::Text		getOptsText();
	private:
		sf::Texture		optionstextures;
		sf::Sprite		optionssprite;
		sf::Vector2f		optionspos;
		sf::RectangleShape 	optionsrect;
		sf::Font		optionsfont;
		sf::Text 		optiontext;
};
