//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Main Gui Menu new game header
//

#ifndef MENU_NEWGAME_HPP_

#include "Game_Window.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	MenuNewGame
{
	public:
		MenuNewGame(int xsize, int ysize);
		sf::CircleShape		getnewgamebutton();
		sf::Text		getNewGameText();
		GameWindow		*getGameWindow();
		void 			setNewGamePos(int xpos, int ypos);
	private:
		sf::SoundBuffer		soundbuff;
		sf::Sound		selectsound;
		sf::Texture		newgametextures;
		sf::Sprite		newgamesprite;
		sf::Vector2f		newgamesize;
		sf::CircleShape		newgamebutton;
		sf::Font		newgamefont;
		sf::Text 		newgametext;
};

#endif /* !MENU_NEWGAME_HPP_ */
