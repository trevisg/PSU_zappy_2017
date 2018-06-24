/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** utils
*/

#include "cmd_fcts.h"

void	move(t_inhabitant *player, t_world *map)
{
	switch (player->o) {
	case N:
		if (player->curr_pos[1] == (map->sizeY - 1))
			player->curr_pos[1] -= (map->sizeY - 1);
		else
			player->curr_pos[1] += 1;
		break;
	case E:
		if (player->curr_pos[0] == (map->sizeX - 1))
			player->curr_pos[0] -= (map->sizeX - 1);
		else
			player->curr_pos[0] += 1;
		break;
	case S:
		if (player->curr_pos[1] == (map->sizeY - 1))
			player->curr_pos[1] += (map->sizeY - 1);
		else
			player->curr_pos[1] -= 1;
		break;
	case W:
		if (player->curr_pos[1] == (map->sizeY - 1))
			player->curr_pos[1] -= (map->sizeY - 1);
		else
			player->curr_pos[0] -= 1;
		break;
	}
}

int	assign_player(char *team_name, t_teams *teams, int clifd)
{
	int exist = false;

	for (t_teams *tmpt = teams; tmpt; tmpt = tmpt->next) {
		if (strcmp(team_name, tmpt->team_name) == 0) {
			for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
				if (!tmpu->user->isco) {
					exist = true;
					tmpu->user->clifd = clifd;
					tmpu->user->isco = true;
					break;
				}
			}
		}
	}
	return exist;
}

int	count_nb_empty(t_teams *teams, char *team_name)
{
	int nb_empty = 0;

	for (t_teams *tmpt = teams; tmpt; tmpt = tmpt->next) {
		if (strcmp(team_name, tmpt->team_name) == 0) {
			for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
				if (!tmpu->user->isco)
					nb_empty++;
			}
		}
	}
	return nb_empty;
}

void	*add_obj_to_player(t_inhabitant *player, char *obj_name)
{
	t_stone *stones[6] = {&player->inventory.sibur,
			      &player->inventory.phiras,
			      &player->inventory.mendiane,
			      &player->inventory.thystame,
			      &player->inventory.linemate,
			      &player->inventory.deraumere};
	
	if (strcmp(player->inventory.food.name, obj_name) == 0) {
		player->inventory.food.qtt += 1;
	}
	for (int i = 0; i < 6; i++) {
		if (strcmp(stones[i]->name, obj_name) == 0) {
			stones[i]->qtt += 1;
			break;
		}
	}
	return player;
}

int check_obj_on_map(t_world *map, int x, int y, char *obj_name)
{
	t_stone *stones[6] = {&map->tiles[x][y].ressources.sibur,
			      &map->tiles[x][y].ressources.phiras,
			      &map->tiles[x][y].ressources.mendiane,
			      &map->tiles[x][y].ressources.thystame,
			      &map->tiles[x][y].ressources.linemate,
			      &map->tiles[x][y].ressources.deraumere};
	for (int i = 0; i < 6; i++) {
		if (strcmp(stones[i]->name, obj_name) == 0) {
			if (stones[i]->qtt > 0)
				return true;
		}
	}
	if (strcmp(map->tiles[x][y].ressources.food.name, obj_name) == 0) {
		printf("There is food on this tile\n");
		if (map->tiles[x][y].ressources.food.qtt > 0)
			return true;
	}
	return false;
}
