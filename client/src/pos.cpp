//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// pos src
//

#include "../include/pos.hpp"

Pos::Pos()
{
	_x = 0;
	_y = 0;
}

Pos::Pos(int valx, int valy)
{
	_x = valx;
	_y = valy;
}

int Pos::getX() {return x;}
int Pos::getY() {return y;}
void Pos::setX(int nx) {x = nx;}
void Pos::setY(int ny) {y = ny;}
void Pos::setMaxX(int maxx) {maxX = maxx;}
void Pos::setMaxY(int maxy) {maxY = maxy;}

void Pos::move(int direction)
{
	if (direction == 0)
	{
		if (getY() + 1 < _maxY)
			setY(getY() + 1);
		else
			setY(0);
	}
	else if (direction == 1)
	{
		if (getX() + 1 < _maxX)
			setX(getX() + 1);
		else
			setX(0);
	}
	else if (direction == 2)
	{
		if (getY() - 1 >= 0)
			setY(getY() - 1);
		else
			setY(maxY);
	}
	else
	{
		if (getX() - 1 >= 0)
			setX(getX() - 1);
		else
			setX(_maxX);
	}
}
