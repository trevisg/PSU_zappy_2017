//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// pos src
//

#include "../include/pos.hpp"

Pos::Pos()
{
  x = 0;
  y = 0;
}

Pos::Pos(int valx, int valy)
{
  x = valx;
  y = valy;
}

int Pos::getX() {return x;}
int Pos::getY() {return y;}
void Pos::setX(int nx) {x = nx;}
void Pos::setY(int ny) {y = ny;}
