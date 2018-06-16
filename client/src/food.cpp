//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// food
//

#include "../include/food.hpp"

Food::Food() {food = 0;}
int Food::getFood() {return food;}
void Food::setFood(int qte) {food = qte;}
void Food::addFood(int qte) {food += qte;}
void Food::clearFood() {food = 0;}
bool Food::subFood(int qte)
{
    if (food - qte < 0)
      return false;
    food = food - qte;
    return true;
}
