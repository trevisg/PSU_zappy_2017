//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Gui Game Window Header
//

#ifndef GAME_WINDOW_HPP_

#include "../../commons/include/Network_Client.hpp"
#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	GameWindow
{
	public:
		GameWindow();
		void _set_bg();
		void _setgame_sound();
		void _set_team_names();
		void _set_team_details();
		void _DrawBoard(int x_size, int y_size);
		sf::Text _init_text(std::string team_name);
		void _event_handler(sf::Event ev);
		bool _is_there_a_player_here(int y, int x);
		bool _start_me(int x_mapsize, int y_mapsize);
	private:
		Network						_client;
		sf::Font					_font;
		sf::Text 					_titletext;
		sf::Texture					_bg_texture;
		sf::Sprite					_bg_sprite;
		sf::Music					_gamemusic;
		sf::SoundBuffer					_soundbuff;
		std::vector<std::string>			_teams_names;
		std::vector<std::map<std::string, std::string>>	_team_details;
		std::vector<sf::Text>				_teams_text;
		std::map<std::string, sf::Sound>		_gamesounds;
};

extern sf::RenderWindow gamewindow;

#endif /* !GAME_WINDOW_HPP_ */
