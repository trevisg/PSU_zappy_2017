//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// tile header
//

#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include "../include/inventory.hpp"
#include "../include/player.hpp"
#include "../include/pos.hpp"
#include "Tile.hpp"

class Tile
{
public:
	Tile();
	void setPos(int nx, int ny);
	Pos  getPos();
	void addPlayer(Player nplayer);
	void setInv(std::vector<int> inv);
	std::vector<int> getInv(void);
private:

	std::vector<Player> _player_list;
	std::vector<int> _inventory;
	Pos _position;
};

#endif /*TILE_HPP*/
