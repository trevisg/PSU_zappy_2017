/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_cmd player
*/

#include "cmd_fcts.h"

void *send_player_join(cmdargs args, int clifd, t_teams *teams)
{
	t_teams *tmpt;
	t_userlist *tmpu;
	
	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		for (tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pnw %d %d %d %d %d %d\n",
				tmpu->user->refplayer->id,
				tmpu->user->refplayer->curr_pos[0],
				tmpu->user->refplayer->curr_pos[1],
				tmpu->user->refplayer->o,
				tmpu->user->refplayer->level,
				tmpt->team_name);
		}
	}
	return teams;
}

void *send_player_pos(cmdargs args, int clifd, t_teams *teams)
{
	t_user *sender;

	if ((sender = find_user_in_teams(teams, clifd))) {
		dprintf(clifd, "ppo %d %d %d %d\n",
			sender->refplayer->id,
			sender->refplayer->curr_por[0],
			sender->refplayer->curr_por[1],
			sender->refplayer->o);
	}
	return teams;
}

void *send_player_lv(cmdargs args, int clifd, t_teams *teams)
{
	int n = atoi(args[0]);
	t_user *playern = find_player_by_id(teams, n);

	dprintf(clifd, "plv %d %d\n", n, playern->refplayer->level);
	return teams;
}

/*  */
void *send_player_inv(cmdargs args, int clifd, t_teams *teams)
{
	int n = atoi(args[0]);
	t_user *playern = find_player_by_id(teams, n);

	dprintf(clifd, "pin %d %d %d %d %d %d %d %d %d %d\n", n,
		playern->refplayer->curr_pos[0],
		playern->refplayer->curr_pos[1],
		playern->refplayer->inventory.food.qtt,
		playern->refplayer->inventory.linemate.qtt,
		playern->refplayer->inventory.deraumere.qtt,
		playern->refplayer->inventory.sibur.qtt,
		playern->refplayer->inventory.mendiane.qtt,
		playern->refplayer->inventory.phiras.qtt,
		playern->refplayer->inventory.thystame.qtt);
	return teams;
}

/* You must specify the dead player's clifd */
void *send_player_death(cmdargs args, int clifd, t_teams *teams)
{
	t_user *playern = find_user_in_team(teams, clifd);
	t_teams *tmpt;
	t_userlist *tmpu;
	
	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		for (tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pdi %d\n",
				playern->refplayer->id);
		}
	}
	return teams;
}
