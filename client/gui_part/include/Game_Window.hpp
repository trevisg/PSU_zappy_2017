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
		void _setgame_sound();
		void _set_bg();
		void _event_handler(sf::Event ev);
		bool _start_me(int x_mapsize, int y_mapsize);
	private:
		sf::Texture	_bg_texture;
		sf::Sprite	_bg_sprite;
		sf::Music	_gamemusic;
		sf::SoundBuffer	_soundbuff;
		std::map<std::string, sf::Sound> _gamesounds;
};

extern sf::RenderWindow gamewindow;

#endif /* !GAME_WINDOW_HPP_ */
