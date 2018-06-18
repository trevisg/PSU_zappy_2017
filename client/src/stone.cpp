//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// rocks
//

#include "../include/stone.hpp"

Stone::Stone() {stone = 0;}
int Stone::getStone() {return stone;}
void Stone::setStone(int qte) {stone = qte;}
void Stone::addStone(int qte) {stone += qte;}
void Stone::clearStone() {stone = 0;}
bool Stone::subStone(int qte)
{
    if (stone - qte < 0)
      return false;
    stone = stone - qte;
    return true;
}
