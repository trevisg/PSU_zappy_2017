//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu new game header
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	MenuNewGame
{
	public:
		MenuNewGame(int xsize, int ysize);
		sf::RectangleShape	getNewGameRect();
		sf::Text		getNewGameText();
		void 			setNewGamePos(int xpos, int ypos);
	private:
		sf::Texture		newgametextures;
		sf::Sprite		newgamesprite;
		sf::Vector2f		newgamesize;
		sf::RectangleShape 	newgamerect;
		sf::Font		newgamefont;
		sf::Text 		newgametext;
};
