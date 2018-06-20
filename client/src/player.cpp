//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// player src
//

#include "../include/player.hpp"

Player::Player()
{
  lifeLeft = 1260;
  readyToRitual = false;
  level = 1;
  direction = NORTH;
}

void Player::setTeam(std::string teamName) {team = teamName;}
std::string Player::getTeam() {return team;}

std::vector<Pos> Player::GetviewPos(int maxX, int maxY)
{
    Pos point;
    Pos tmp;
    std::vector<Pos> list;
    int i = 0;
    int nbc = 1;
    int j = 0;

    // !!!!! les deux prochaines lignes doivent etre set en amont pas ici
    position.setMaxX(600);
    position.setMaxY(200);
    // !!!                                                            !!!!

    point = position;
    while (i <= level)
    {
      tmp = point;
      while (j < nbc)
      {
        list.emplace_back(tmp);
        tmp.move(direction);
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
    int tmpdir = direction;

    tmp.move(direction);
    tmpdir = tmpdir - 1;
    if (tmpdir < 0)
      tmpdir = 3;
    tmp.move(tmpdir);
    return tmp;
}

void Player::turnRight()
{
  direction = direction + 1;
  if (direction >=4)
    direction = 0;
  // send turn right request
}

void Player::turnLeft()
{
  direction = direction - 1;
  if (direction < 0)
    direction = 3;
  // send turn left request
}
