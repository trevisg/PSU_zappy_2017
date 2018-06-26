/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** print map && teams
*/

#include "../../include/server.h"

void            print_world(t_world *map)
{
	for (int i = 0; i < map->sizeX; i++) {
		for (int j = 0; j < map->sizeY; j++) {
			printf("%d ", map->tiles[i][j].ressources.food.qtt);
		}
		printf("\n");
	}
}


void		print_teams(t_teams *teams)
{
	for (t_teams *tmpt = teams; tmpt; tmpt = tmpt->next) {
		printf("%s\n", tmpt->team_name);
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			printf("%d[%s]: X=%d Y=%d %d %d %d %d %d %d %d ttl:%f\n",
			       tmpu->user->id, tmpu->user->team_name,
			       tmpu->user->curr_pos[0], tmpu->user->curr_pos[1],
			       tmpu->user->inventory.food.qtt,
			       tmpu->user->inventory.linemate.qtt,
			       tmpu->user->inventory.deraumere.qtt,
			       tmpu->user->inventory.sibur.qtt,
			       tmpu->user->inventory.mendiane.qtt,
			       tmpu->user->inventory.phiras.qtt,
			       tmpu->user->inventory.thystame.qtt,
			       tmpu->user->ttl);
		}
		printf("\n");
	}
}
