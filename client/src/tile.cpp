//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// tile header
//

#include "../include/Tile.hpp"

Tile::Tile() {}

void Tile::setPos(int nx, int ny)
{
	_position.setX(nx);
	_position.setY(ny);
}

Pos Tile::getPos() {return position;}

void Tile::addPlayer(Player nplayer) {_player_list.emplace_back(nplayer);}

void setInv(std::vector<int> inv) : _inventory(inv)
{
}

std::vector<int> getInv(void)
{
	return (_inventory);
}
