//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// player src
//

#include "../include/player.hpp"

Player::Player()
{
	_lifeLeft = 1260;
	_readyToRitual = false;
	_level = 1;
	_direction = NORTH;
}

Player::~Player()
{
	
}

void Player::setTeam(std::string teamName) {_team = teamName;}
std::string Player::getTeam() {return _team;}

std::vector<Pos> Player::GetviewPos(int maxX, int maxY)
{
	Pos point;
	Pos tmp;
	std::vector<Pos> list;
	int i = 0;
	int nbc = 1;
	int j = 0;

	// !!!!! les deux prochaines lignes doivent etre set en amont pas ici
	_position.setMaxX(600);
	_position.setMaxY(200);
	// !!!                                                            !!!!

	point = _position;
	while (i <= _level)
	{
		tmp = point;
		while (j < nbc)
		{
			list.emplace_back(tmp);
			tmp.move(_direction);
			j++;
		}
		j = 0;
		point = nextCalcPos(point);
		i++;
		nbc = nbc + 2;
	}
	return list;
}

Pos Player::nextCalcPos(Pos old)
{
	Pos tmp = old;
	int tmpdir = _direction;

	tmp.move(_direction);
	tmpdir = tmpdir - 1;
	if (tmpdir < 0)
		tmpdir = 3;
	tmp.move(tmpdir);
	return tmp;
}

void Player::turnRight()
{
	_direction = _direction + 1;
	if (_direction >=4)
		_direction = 0;
	// send turn right request
}

void Player::turnLeft()
{
	_direction = _direction - 1;
	if (_direction < 0)
		_direction = 3;
	// send turn left request
}

void Player::setLvl(int lvl)
{
	_level = lvl;
}

void Player::setDir(int dir)
{
	_direction = dir;
}

void Player::setInv(std::vector<int> inv)
{
	_inventory = inv;
}
