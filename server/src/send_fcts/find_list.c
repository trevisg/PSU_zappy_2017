/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** find list utils
*/

#include "cmd_fcts.h"

t_user *find_user_in_teams(t_teams *teams, int clifd)
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

t_user *find_player_by_id(t_teams *teams, unsigned int id)
{
	t_teams *tmpt;
	t_userlist *tmpu;
	
	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		for (tmpu = teams->users; tmpu; tmpu = tmpu->next) {
			if (tmpu->user->refplayer->id == id)
				return tmpu->user;
		}
	}
	return NULL;
}

int get_nbr_by_level(int level)
{
	int nbr;

	if (level == 1)
		nbr = 1;
	else if (level == 2 || level == 3)
		nbr = 2;
	else if (level == 4 || level == 5)
		nbr = 4;
	else if (level == 6 || level == 7)
		nbr = 6;
	else
		nbr = 0;
	return nbr;
}

/*
**
*/
t_egg *find_egg_on_tile(t_tile *tile, t_user *layer)
{
	t_egg *tmpe;
	
	for (tmpe = tile->eggs; tmpe; tmpe = tmpe->next) {
		if (tmpe->id_droper == layer->refplayer->id)
			break;
	}
	return tmpe;
}

/* Find the egg from a player whose state is provided as a parameter */
t_egg *find_egg_state(t_user *user, EGG_STATE state)
{
	t_egg *tmpe;
	
	for (tmpe = user->refplayer->eggs; tmpe; tmpe = tmpe->next) {
		if (tmpe->ev == HATCHED && state == HATCHED)
			break;
		if (tmpe->ev == DEAD && state == DEAD)
			break;
	}
	return tmpe;
}
