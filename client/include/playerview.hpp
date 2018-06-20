//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// playerview header
//

#ifndef PLAYERVIEW_HPP
#define PLAYERVIEW_HPP

#include <vector>
#include "Tile.hpp"

class PlayerView
{
public:
    PlayerView();
    void addTile();
    void tileSetPos(int nx, int ny);
    void addPlayer(Player ntretor);
    void tileSetItem(std::string itemname, int qte);
private:

    std::vector<Tile> view;
    Tile tmptile;
    
    void clearTile();
};

#endif /*CORE_HPP*/
