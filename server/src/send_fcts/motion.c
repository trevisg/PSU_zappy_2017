/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** movements of player
*/

#include "cmd_fcts.h"

void *r_inventory(char **args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);

	dprintf(clifd,
		"[%s %d, %s %d, %s %d, %s %d, %s %d, %s %d, %s %d]\n",
		player->inventory.food.name, player->inventory.food.qtt,
		player->inventory.linemate.name, player->inventory.linemate.qtt,
		player->inventory.deraumere.name, player->inventory.deraumere.qtt,
		player->inventory.sibur.name, player->inventory.sibur.qtt,
		player->inventory.mendiane.name, player->inventory.mendiane.qtt,
		player->inventory.phiras.name, player->inventory.phiras.qtt,
		player->inventory.thystame.name, player->inventory.thystame.qtt);
	return map;
}
