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

class Player
{
public:
	Player();
	void setTeam(std::string teamName);
	std::string getTeam();
private:
	int lifeLeft;
	std::string team;
	Inventory	invent;
	Pos position;
	bool readyToRitual;
};

#endif /*PLAYER_HPP*/
