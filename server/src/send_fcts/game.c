/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_cmd game
*/

#include "cmd_fcts.h"

void *send_game_end(cmdargs args, int clifd, t_world *map)
{
	dprintf(clifd, "seg %s\n", map->teams->team_name);
	return map;
}

void *send_map_size(cmdargs args, int clifd, t_world *map)
{
	dprintf(clifd, "msz %d %d\n", map.sizeX, map.sizeY);
	return map;
}

void *send_map_content(cmdargs args, int clifd, t_world *map)
{
	int i;
	int j;
	
	for (i = 0; i < map.sizeY; i++) {
		for (j = 0; j < map.sizeX; j++) {
			dprintf(clifd, "btc %d %d %d %d %d %d %d %d %d", j, i,
				map->tiles[i][j].ressources.food.qtt,
				map->tiles[i][j].ressources.linemate.qtt,
				map->tiles[i][j].ressources.deraumere.qtt,
				map->tiles[i][j].ressources.sibur.qtt,
				map->tiles[i][j].ressources.mendiane.qtt,
				map->tiles[i][j].ressources.phiras.qtt,
				map->tiles[i][j].ressources.thystame.qtt);
		}
	}
	return map;
}

void *send_tile_content(cmdargs args, int clifd, t_world *map))
{
	int x = atoi(args[0]);
	int y = atoi(args[1]);
	
	dprintf(clifd, "btc %d %d %d %d %d %d %d %d %d\n", x, y,
		map->tiles[x][y].ressources.food.qtt,
		map->tiles[x][y].ressources.linemate.qtt,
		map->tiles[x][y].ressources.deraumere.qtt,
		map->tiles[x][y].ressources.sibur.qtt,
		map->tiles[x][y].ressources.mendiane.qtt,
		map->tiles[x][y].ressources.phiras.qtt,
		map->tiles[x][y].ressources.thystame.qtt);
	return map;
}
