/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** movements of player
*/

#include "cmd_fcts.h"

/* Move a player forward and responds to the client */
void *forward(cmdargs args, int clifd, t_world *map)
{
//	t_user *player = find_user_in_teams(teams, clifd);
	args[0][0] = 'c';
	printf("forward\n");
	
//	move(player->refplayer, teams->refmap);
	dprintf(clifd, "ok\n");
	return map;
}

void *right(cmdargs args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	printf("turn right\n");
/*	t_user *player = find_user_in_teams(teams, clifd);

	switch (player->refplayer->o) {
	case N:
		player->refplayer->o = E;
		break;
	case E:
		player->refplayer->o = S;
		break;
	case S:
		player->refplayer->o = W;
		break;
	case W:
		player->refplayer->o = N;
		break;
		}*/
	dprintf(clifd, "ok\n");
	return map;
}

void *left(cmdargs args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	printf("turn left\n");
/*	t_user *player = find_user_in_teams(teams, clifd);

	switch (player->refplayer->o) {
	case N:
		player->refplayer->o = W;
		break;
	case E:
		player->refplayer->o = N;
		break;
	case S:
		player->refplayer->o = E;
		break;
	case W:
		player->refplayer->o = S;
		break;
		}*/
	dprintf(clifd, "ok\n");
	return map;
}
