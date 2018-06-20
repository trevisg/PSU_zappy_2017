//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// Core header
//

#ifndef CORE_HPP
#define CORE_HPP

#include "string"
#include "player.hpp"
#include "map.hpp"

class Core
{
public:
	Core();
	void start();
	bool initConnexion(std::string teamName);
private:
	Player _trantor;
	Map _map;
};

#endif /*CORE_HPP*/
