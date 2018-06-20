//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// playerview src
//

#include "../include/playerview.hpp"

PlayerView::PlayerView()
{
}

void PlayerView::addTile()
{
  view.emplace_back(tmptile);
  clearTile();
}

void PlayerView::tileSetPos(int nx, int ny) {tmptile.setPos(nx, ny);}
void PlayerView::tileSetItem(std::string itemname, int qte) {tmptile.inv.setItem(itemname, qte);}
//void PlayerView::addPlayer(Player ntretor) {tmptile.addPlayer(ntretor);}

void PlayerView::clearTile()
{
  Tile ntmp;

  tmptile = ntmp;
}
