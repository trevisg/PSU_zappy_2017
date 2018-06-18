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
}

void Player::setTeam(std::string teamName) {team = teamName;}
std::string Player::getTeam() {return team;}
