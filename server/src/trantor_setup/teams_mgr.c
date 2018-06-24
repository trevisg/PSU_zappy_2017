/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** teams mgr
*/

#include "../../include/server.h"

t_teams *get_new_team(char *name)
{
	t_teams *list = malloc(sizeof(*list));

	if (list) {
		memset(list, 0, sizeof(*list));
		list->users = NULL;
		list->team_name = strdup(name);
		list->next = NULL;
		list->prev = NULL;
	}
	return list;
}

t_teams *add_team_back(t_teams *list, char *name)
{
	t_teams *new_team = get_new_team(name);

	if (new_team && list) {
		new_team->prev = list;
		list->next = new_team;
	}
	return new_team;
}

t_teams *init_teams(char **teams_names)
{
	int i;
	t_teams *teamlist = get_new_team(teams_names[0]);

	for (i = 1; teams_names[i]; i++) {
		teamlist = add_team_back(teamlist, teams_names[i]);
	}
	while (teamlist->prev)
		teamlist = teamlist->prev;
	return teamlist;
}
