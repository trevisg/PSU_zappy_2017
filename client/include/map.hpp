//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// map header
//

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include "Tile.hpp"

class Map
{
public:
  Map();
  void setSize(int xMax, int yMax);
private:
std::vector<std::vector<Tile>> tileList;
int maxX;
int maxY;
bool is_set;
};

#endif /*MAP_HPP*/
