//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// player header
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "string"
#include "../include/pos.hpp"
#include "../include/playerview.hpp"

enum {NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3};

class Player
{
public:
	Player();
	~Player();
	void setTeam(std::string teamName);
	void setLvl(int lvl);
	void setDir(int dir);
	void setInv(std::vector<int> inv);
	std::string getTeam();
	std::vector<Pos> GetviewPos(int maxX, int maxY);
	void turnRight();
	void turnLeft();
	Pos nextCalcPos(Pos old);

private:
	int _lifeLeft;
	int _level;
	int _direction;
	std::string _team;
	std::vector<int> _inventory;
	Pos _position;
	PlayerView _view;
	bool _readyToRitual;
};

#endif /*PLAYER_HPP*/
