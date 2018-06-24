/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** find list utils
*/

#include "cmd_fcts.h"


t_inhabitant *find_player_by_fd(t_teams *teams, int clifd)
{
	t_teams *tmpt;
	t_userlist *tmpu;

	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		for (tmpu = teams->users; tmpu; tmpu = tmpu->next) {
			if (tmpu->user->clifd == clifd)
				return tmpu->user;
		}
	}
	return NULL;
}
