//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// food
//

#ifndef FOOD_HPP
#define FOOD_HPP

class Food
{
public:

  Food();
	int getFood();
  void setFood(int qte);
  void addFood(int qte);
  bool subFood(int qte);
  void clearFood();
private:
	int food;
};

#endif /*FOOD_HPP*/
