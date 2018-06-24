/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** utils
*/

#include "cmd_fcts.h"

void move(t_inhabitant *player, t_world *map)
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

int assign_player(char *team_name, t_teams *teams, int clifd)
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

int count_nb_empty(t_teams *teams, char *team_name)
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
