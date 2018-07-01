/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server graphical client <-> server commands
*/

#include <unistd.h>
#include "../../include/cmd_fcts.h"

void	*g_mapsize(char **args, int clifd, t_world *map)
{
	if (args || !args) {
		dprintf(clifd, "{\"mapsize\": {\"x\": %d, \"y\": %d} }\n",
		map->sizeX, map->sizeY);
	}
	close(clifd);
	return (map);
}

void	*g_teams_names(char **args, int clifd, t_world *map)
{
	dprintf(clifd, "{\"teamnames\": [");
	if (args || !args) {
		for (t_teams *tmp = map->teams; tmp; tmp = tmp->next) {
			dprintf(clifd, "\"%s\"%s", tmp->team_name,
				tmp->next ? ", " : "]");
		}
		dprintf(clifd, "}\n");
	}
	close(clifd);
	return (map);
}

void	send_details(int clifd, t_userlist *teams_members)
{
	uint id = 0;
	for (t_userlist *tmp = teams_members; tmp; tmp = tmp->next) {
		dprintf(clifd, "{\"id\": %d , \"x\": %d , ",
		id, tmp->user->curr_pos[X]);
		dprintf(clifd, "\"y\":%d , \"ttl\": %0.3f}%s",
		tmp->user->curr_pos[Y], tmp->user->ttl,
		tmp->next ? ", " : "\n");

	}
}

void	*g_team_detail(char **args, int clifd, t_world *map)
{
	uint i = get_size(args);

	if (i >= 4 && !strcmp("team", args[2]) &&
		strlen(args[3]) <= MAX_TEAM_NAME) {
		for (t_teams *tmp = map->teams; tmp; tmp = tmp->next) {
			if (strstr(args[3], tmp->team_name)) {
				dprintf(clifd, "{\"%s\":[", args[3]);
				send_details(clifd, tmp->users);
				dprintf(clifd, "]}\n");
				break;
			}
		}
	}
	close(clifd);
	return (map);
}
