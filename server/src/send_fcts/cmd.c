/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_cmd cmd && resources
*/

#include "cmd_fcts.h"

void *send_res_drop(cmdargs args, int clifd, t_world *map)
{
	t_user *user = find_user_in_teams(map->teams, clifd);

	for (t_teams tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist tmpu = tmpu->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pdr %d %d\n",
				tmpu->user->refplayer->id,
				tmpu->user->refplayer->just_drop);
		}
	}
	return map;
}

void *send_res_collect(cmdargs args, int clifd, t_world *map)
{
	t_user *user = find_user_in_teams(map->teams, clifd);

	for (t_teams tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist tmpu = tmpu->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pgt %d %d\n",
				tmpu->user->refplayer->id,
				tmpu->user->refplayer->just_collect);
		}
	}
	return map;
}

void *send_msg(cmdargs args, int clifd, t_world *map)
{
	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "smg %s\n", args[0]);
		}
	}
	return map;
}

/* Provide the clifd of the requester */
void *send_cmd_unknow(cmdargs args, int clifd, t_world *map)
{
	dprintf(clifd, "suc\n");
}

void *send_cmd_params(cmdargs args, int clifd, t_world *map)
{
	dprintf(clifd, "sbp\n");
}
