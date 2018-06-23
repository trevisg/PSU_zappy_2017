/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_cmd game
*/

#include "cmd_fcts.h"

void *send_game_end(cmdargs args, int clifd, t_teams *teams)
{
	dprintf(clifd, "seg %s\n", teams->team_name);
	return teams;
}

void *send_map_size(cmdargs args, int clifd, t_teams *teams)
{
	dprintf(clifd, "msz %d %d\n", teams->refmap->sizeX, teams->refmap->sizeY);
	return teams;
}

void *send_map_content(cmdargs args, int clifd, t_teams *teams)
{
	int i;
	int j;
	
	for (i = 0; i < teams->refmap->sizeY; i++) {
		for (j = 0; j < teams->refmap->sizeX; j++) {
			dprintf(clifd, "btc %d %d %d %d %d %d %d %d %d", j, i,
				teams->refmap->tiles[i][j].ressources.food.qtt,
				teams->refmap->tiles[i][j].ressources.linemate.qtt,
				teams->refmap->tiles[i][j].ressources.deraumere.qtt,
				teams->refmap->tiles[i][j].ressources.sibur.qtt,
				teams->refmap->tiles[i][j].ressources.mendiane.qtt,
				teams->refmap->tiles[i][j].ressources.phiras.qtt,
				teams->refmap->tiles[i][j].ressources.thystame.qtt);
		}
	}
	return teams;
}

void *send_tile_content(cmdargs args, int clifd, t_teams *teams)
{
	int x = atoi(args[0]);
	int y = atoi(args[1]);
	
	dprintf(clifd, "btc %d %d %d %d %d %d %d %d %d\n", x, y,
		teams->refmap->tiles[x][y].ressources.food.qtt,
		teams->refmap->tiles[x][y].ressources.linemate.qtt,
		teams->refmap->tiles[x][y].ressources.deraumere.qtt,
		teams->refmap->tiles[x][y].ressources.sibur.qtt,
		teams->refmap->tiles[x][y].ressources.mendiane.qtt,
		teams->refmap->tiles[x][y].ressources.phiras.qtt,
		teams->refmap->tiles[x][y].ressources.thystame.qtt);
	return teams;
}
