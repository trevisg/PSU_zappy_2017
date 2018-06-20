//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// player header
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "string"
#include "../include/inventory.hpp"
#include "../include/pos.hpp"
#include "../include/playerview.hpp"

enum {NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3};

class Player
{
public:
	Player();
	void setTeam(std::string teamName);
	std::string getTeam();
	std::vector<Pos> GetviewPos(int maxX, int maxY);
	void turnRight();
	void turnLeft();
	Pos nextCalcPos(Pos old);
private:

	int lifeLeft;
	int level;
	int direction;
	std::string team;
	Inventory	invent;
	Pos position;
	PlayerView view;
	bool readyToRitual;
};

#endif /*PLAYER_HPP*/
