//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// inventory header
//

#include "../include/inventory.hpp"

Inventory::Inventory()
{

}

void Inventory::setItem(std::string stonename, int qte)
{
  if (stonename == std::string("linemate"))
    linemate.setStone(qte);
  else if (stonename == std::string("deraumere"))
    deraumere.setStone(qte);
  else if (stonename == std::string("sibur"))
    sibur.setStone(qte);
  else if (stonename == std::string("mendiane"))
    mendiane.setStone(qte);
  else if (stonename == std::string("phiras"))
    phiras.setStone(qte);
  else if (stonename == std::string("thystame"))
    thystame.setStone(qte);
  else if (stonename == std::string("food"))
    foodItem.setFood(qte);
  else
    return;
}
