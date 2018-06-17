//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// main file
//

#include <iostream>
#include "../include/core.hpp"

int noMoreSpace()
{
  std::cout << "sory, no more player avilable on this server int this team" << std::endl;
  return 84;
}

bool argChecker(int ac, char **av)
{
  if (ac != 4)
    return false;
  // rajouter des checks
  return true;
}

int usage()
{
  std::cout << "usages" << std::endl;
  return 84;
}

int main(int ac, char **av)
{
  Core master;

  if (argChecker(ac, av) == false)
    return usage();
  if (master.initConnexion(av[2]) == false)
    return(noMoreSpace());
  master.start();
}
