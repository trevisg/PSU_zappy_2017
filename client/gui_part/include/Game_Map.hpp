//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Gui Game Map Board Header
//

#ifndef GAME_MAP_HPP_

// #include "../../include/map.hpp"
#include "Game_MapTile.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// class GameMap : public Map
class GameMap
{
	public:
		GameMap();
		~GameMap();
	private:
		std::vector<std::vector<GameMapTile> > map;
};

#endif /* !GAME_MAP_HPP_ */
