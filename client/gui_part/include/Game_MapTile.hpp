//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Gui Game Map Tile Header
//

#ifndef GAME_MAPTILE_HPP_

// #include "../../include/tile.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// class GameMapTile : public Tile
class GameMapTile
{
	public:
		GameMapTile();
		~GameMapTile();
	private:
		sf::RectangleShape	tilerect;
		sf::Sprite		tilesprite;
		sf::Texture		tiletexture;
};

#endif /* !GAME_MAPTILE_HPP_ */
