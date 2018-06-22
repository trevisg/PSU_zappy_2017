//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Gui Game Window Header
//

#ifndef GAME_WINDOW_HPP_

// #include "../../include/map.hpp"
#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	GameWindow
{
	public:
		GameWindow();
		void setgamesound();
		bool start_me(int x_mapsize, int y_mapsize);
	private:
		sf::Music	gamemusic;
		sf::SoundBuffer	soundbuff;
		std::map<std::string, sf::Sound> gamesounds;
};

extern sf::RenderWindow gamewindow;

#endif /* !GAME_WINDOW_HPP_ */
