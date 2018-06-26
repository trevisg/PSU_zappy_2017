/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server graphical client <-> server commands g_mapsize
*/

#include "../../include/cmd_fcts.h"

void	*g_mapsize(char **args, int clifd, t_world *map)
{
	if (args || !args)
		dprintf(clifd, "{x: %d, y: %d}\n", map->sizeX, map->sizeY);
	return (map);
}

void	*g_teams_names(char **args, int clifd, t_world *map)
{
	dprintf(clifd, "{teams:[");
	if (args || !args) {
		for (t_teams *tmp = map->teams; tmp; tmp = tmp->next) {
			dprintf(clifd, "%s%c", tmp->team_name,
				tmp->next ? ',' : ']');
		}
		dprintf(clifd, "}\n");
	}
	return (map);
}

void	send_details(int clifd, t_userlist *teams_members)
{
	uint id = 0;
	for (t_userlist *tmp = teams_members; tmp; tmp = tmp->next) {
		dprintf(clifd, "[{id:%d,x:%d,", id, tmp->user->curr_pos[X]);
		dprintf(clifd, "y:%d,ttl:%0.3f}]%s", tmp->user->curr_pos[Y],
		tmp->user->ttl, tmp->next ? ",\n" : "\n");

	}
}

void	*g_team_detail(char **args, int clifd, t_world *map)
{
	uint i = 0;

	for (; args[i]; ++i) {
	}
	if (i == 4 && !strcmp("team", args[2]) &&
		strlen(args[3]) <= MAX_TEAM_NAME) {
		for (t_teams *tmp = map->teams; tmp; tmp = tmp->next) {
			if (strstr(args[3], tmp->team_name)) {
				dprintf(clifd, "{%s:{\n", args[3]);
				send_details(clifd, tmp->users);
				dprintf(clifd, "}}\n");
				break;
			}
		}
	}
	return (map);
}
