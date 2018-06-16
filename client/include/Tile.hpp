//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// tile header
//


#ifndef TILE_HPP
#define TILE_HPP

#include "../include/inventory.hpp"
#include "../include/player.hpp"
#include "Tile.hpp"

class Tile
{
public:

private:
std::pair <int, int> pos; // a remplacer par l'objet pos
std::vector<Player> player_list;
Inventory inv;
};

#endif /*TILE_HPP*/
