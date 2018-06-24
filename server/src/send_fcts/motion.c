/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** movements of player
*/

#include "cmd_fcts.h"

/* Move a player forward and responds to the client */
void *r_forward(cmdargs args, int clifd, t_world *map)
{
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);

	args[0][0] = 'c';
	move(player, map);
	dprintf(clifd, "ok\n");
	return map;
}

void *r_right(cmdargs args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	printf("turn right\n");
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);

	switch (player->o) {
	case N:
		player->o = E;
		break;
	case E:
		player->o = S;
		break;
	case S:
		player->o = W;
		break;
	case W:
		player->o = N;
		break;
	}
	dprintf(clifd, "ok\n");
	return map;
}

void *r_left(cmdargs args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	printf("turn left\n");
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);

	switch (player->o) {
	case N:
		player->o = W;
		break;
	case E:
		player->o = N;
		break;
	case S:
		player->o = E;
		break;
	case W:
		player->o = S;
		break;
	}
	dprintf(clifd, "ok\n");
	return map;
}

void *r_inventory(cmdargs args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);

	dprintf(clifd,
		"[%s %d, %s %d, %s %d, %s %d, %s %d, %s %d, %s %d]\n",
		player->inventory.food.name,
		player->inventory.food.qtt,
		player->inventory.linemate.name,
		player->inventory.linemate.qtt,
		player->inventory.deraumere.name,
		player->inventory.deraumere.qtt,
		player->inventory.sibur.name,
		player->inventory.sibur.qtt,
		player->inventory.mendiane.name,
		player->inventory.mendiane.qtt,
		player->inventory.phiras.name,
		player->inventory.phiras.qtt,
		player->inventory.thystame.name,
		player->inventory.thystame.qtt);
	return map;
}
