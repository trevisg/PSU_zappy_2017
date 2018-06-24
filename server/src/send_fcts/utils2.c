/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** utils for r_cmd
*/

#include "cmd_fcts.h"

void *del_obj_on_map(t_world *map, int x, int y, char *obj_name)
{
	t_stone *stones[6] = {&map->tiles[x][y].ressources.sibur,
			      &map->tiles[x][y].ressources.phiras,
			      &map->tiles[x][y].ressources.mendiane,
			      &map->tiles[x][y].ressources.thystame,
			      &map->tiles[x][y].ressources.linemate,
			      &map->tiles[x][y].ressources.deraumere};
	for (int i = 0; i < 6; i++) {
		if (strcmp(stones[i]->name, obj_name) == 0) {
			stones[i]->qtt -= 1;
			break;
		}
	}
	if (strcmp(map->tiles[x][y].ressources.food.name, obj_name) == 0) {
		map->tiles[x][y].ressources.food.qtt -= 1;
	}
	return map;
}

int check_obj_in_inv(t_inhabitant *player, char *obj_name)
{
	t_stone *stones[6] = {&player->inventory.sibur,
			      &player->inventory.phiras,
			      &player->inventory.mendiane,
			      &player->inventory.thystame,
			      &player->inventory.linemate,
			      &player->inventory.deraumere};

	if (strcmp(player->inventory.food.name, obj_name) == 0) {
		if (player->inventory.food.qtt > 0)
			return true;
	}
	for (int i = 0; i < 6; i++) {
		if (strcmp(stones[i]->name, obj_name) == 0) {
			if (stones[i]->qtt > 0)
				return true;
		}
	}
	return false;
}

void *del_obj_from_player(t_inhabitant *player, char *obj_name)
{
	t_stone *stones[6] = {&player->inventory.sibur,
			      &player->inventory.phiras,
			      &player->inventory.mendiane,
			      &player->inventory.thystame,
			      &player->inventory.linemate,
			      &player->inventory.deraumere};

	if (strcmp(player->inventory.food.name, obj_name) == 0) {
		player->inventory.food.qtt -= 1;
	}
	for (int i = 0; i < 6; i++) {
		if (strcmp(stones[i]->name, obj_name) == 0) {
			stones[i]->qtt -= 1;
			break;
		}
	}
	return player;
}

void *add_obj_to_map(t_world *map, int x, int y, char *obj_name)
{
	t_stone *stones[6] = {&map->tiles[x][y].ressources.sibur,
			      &map->tiles[x][y].ressources.phiras,
			      &map->tiles[x][y].ressources.mendiane,
			      &map->tiles[x][y].ressources.thystame,
			      &map->tiles[x][y].ressources.linemate,
			      &map->tiles[x][y].ressources.deraumere};
	for (int i = 0; i < 6; i++) {
		if (strcmp(stones[i]->name, obj_name) == 0) {
			stones[i]->qtt += 1;
			break;
		}
	}
	if (strcmp(map->tiles[x][y].ressources.food.name, obj_name) == 0) {
		map->tiles[x][y].ressources.food.qtt += 1;
	}
	return map;
}
