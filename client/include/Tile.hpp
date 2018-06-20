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
    
    Inventory inv;
private:

std::vector<Player> player_list;
Pos position;
};

#endif /*TILE_HPP*/
