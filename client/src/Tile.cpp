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
    position.setX(nx);
    position.setY(ny);
}

Pos Tile::getPos() {return position;}
void Tile::addPlayer(Player nplayer) {player_list.emplace_back(nplayer);}
