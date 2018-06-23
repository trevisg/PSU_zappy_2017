/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** utils
*/

#include "cmd_fcts.h"

void move(t_inhabitant *player, t_world *map)
{
	switch (player->o) {
	case N:
		if (player->curr_pos[1] == (map->sizeY - 1))
			player->curr_pos[1] -= (map->sizeY - 1);
		else
			player->curr_pos[1] += 1;
		break;
	case E:
		if (player->curr_pos[0] == (map->sizeX - 1))
			player->curr_pos[0] -= (map->sizeX - 1);
		else
			player->curr_pos[0] += 1;
		break;
	case S:
		if (player->curr_pos[1] == (map->sizeY - 1))
			player->curr_pos[1] += (map->sizeY - 1);
		else
			player->curr_pos[1] -= 1;
		break;
	case W:
		if (player->curr_pos[1] == (map->sizeY - 1))
			player->curr_pos[1] -= (map->sizeY - 1);
		else
			player->curr_pos[0] -= 1;
		break;
	}
}
