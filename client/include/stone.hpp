//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// stone
//

#ifndef STONE_HPP
#define STONE_HPP

class Stone
{
public:

  Stone();
	int getStone();
  void setStone(int qte);
  void addStone(int qte);
  bool subStone(int qte);
  void clearStone();
private:
	int stone;
};

#endif /*STONE_HPP*/
