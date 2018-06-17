//
// EPITECH PROJECT, 2018
// PSU_zappy_2017client
// File description:
// pos header
//

#ifndef POS_HPP
#define POS_HPP

class Pos
{
public:
    Pos();
    Pos(int valx, int valy);
    int getX();
    int getY();
    void setX(int nx);
    void setY(int ny);
private:
	int x;
  int y;
};

#endif /*PLAYER_HPP*/
