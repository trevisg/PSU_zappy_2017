//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// inventory header
//

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include "../include/stone.hpp"
#include "../include/food.hpp"

class Inventory
{
public:
	Inventory();
	void  setItem(std::string stonename, int qte);
	Stone linemate;
	Stone deraumere;
	Stone sibur;
	Stone mendiane;
	Stone phiras;
	Stone thystame;
	Food foodItem;
private:

};

#endif /*INVENTORY_HPP*/
