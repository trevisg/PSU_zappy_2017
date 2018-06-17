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
private:

std::vector<Player> player_list;
Inventory inv;
Pos position;
};

#endif /*TILE_HPP*/
