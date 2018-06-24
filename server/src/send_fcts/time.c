/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** time mgr && incantations mgr
*/

#include "cmd_fcts.h"

/* Provide the clifd of the incantator */
void *send_inc_start(cmdargs args, int clifd, t_world *map)
{
	t_user *incantor = find_user_in_teams(map->teams, clifd);
	int x = incantor->refplayer->curr_pos[0];
	int y = incantor->refplayer->curr_pos[1];
	t_tile *tile = map->tiles[x][y];
	t_inhabitant *player;
	int req_lvl = incantator->refplayer->level;
	char *nums = malloc(2 * get_nbr_by_level(req_lvl));

	for (player = tile->trantorians; player; player = player->next) {
		if (player->level == incantor->refplayer->level) {
			nums = strcat(nums, " ");
			nums = strcat(nums, tmpu->user->refplayer->id);
		}
	}
	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pic %d %d %d%s\n",
				pos[0], pos[1], req_lvl, nums);
		}
	}
	free(nums);
	return map;
}

/* Provide args[0] = "Current level: k" || "ko"
** Provide the clifd of the incantor
*/
void *send_inc_end(cmdargs args, int clifd, t_world *map)
{
	int pos[2];
	t_user *incantor = find_user_in_teams(map->teams, clifd);

	pos[0] = incantor->refplayer->curr_pos[0];
	pos[1] = incantor->refplayer->curr_pos[1];
	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pie %d %d %s",
				pos[0], pos[1], args[0]);
		}
	}
	return map;
}

/* Provide clifd of the requester */
void *send_time_unit(cmdargs args, int clifd, t_world *map)
{
	dprintf(clifd, "sgt %d\n", map->freq);
}

/* Provide clifd of the requester
** The frequency must have be changed upstream
*/
void *send_time_modif(cmdargs args, int clifd, t_world *map)
{
	dprintf(clifd, "sst %d\n", map->freq);
}
