//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// Core src
//

#include "../include/core.hpp"


#include <iostream>

Core::Core()
{
}

void Core::start()
{
    // main loop element
    // init
    std::cout << "corect exec\n";
}

bool Core::initConnexion(std::string teamName)
{
  // recive "welcome"
  trantor.setTeam(teamName);
  // recive team teamName
  // interpreter client num
  int clientNum = 3;
  if (clientNum < 1)
    return false;
  //set interpreter la talle de la map
  map.setSize(150, 300); // remplacer ces valeurs par la reponse du serveur
  return true;
}

void Core::
