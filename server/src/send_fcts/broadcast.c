/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast team look eject
*/

#include "cmd_fcts.h"

void *r_team(cmdargs args, int clifd, t_world *map)
{
	if (args[1] && strcmp(args[1], "graphical") == 0) {
		map->graphical_fd = clifd;
		dprintf(clifd, "GRAPHICAL SOCKET\n");
	} else if (args[1] && assign_player(args[1], map->teams, clifd)) {
		dprintf(clifd, "%d\n%d %d\n",
			count_nb_empty(map->teams, args[1]),
			map->sizeX, map->sizeY);
	} else {
		dprintf(clifd, "ko\n");
	}
	return map;
}

void *r_broadcast(cmdargs args, int clifd, t_world *map)
{
	if (!args[1])
		return map;
	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			if (tmpu->user->clifd != clifd && tmpu->user->isco) {
				dprintf(tmpu->user->clifd, "%s\n", args[1]);
				dprintf(map->graphical_fd ,"pbc %d %s\n",
					tmpu->user->clifd, args[1]);
			}
		}
	}
	return map;
}
