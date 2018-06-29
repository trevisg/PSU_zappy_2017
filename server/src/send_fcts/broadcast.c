/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast team look eject
*/

#include "cmd_fcts.h"

void	*r_team(char ** args, int clifd, t_world *map)
{
	if (args[1] && strcmp(args[1], "graphical") == 0) {
		map->graphical_fd = clifd;
	} else if (args[1] && assign_player(args[1], map->teams, clifd)) {
		dprintf(clifd, "%d\n%d %d\n",
			count_nb_empty(map->teams, args[1]),
			map->sizeX, map->sizeY);
	} else {
		dprintf(clifd, "ko\n");
	}
	return map;
}

void	*r_broadcast(char ** args, int clifd, t_world *map)
{
	if (!args[1])
		return map;
	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			if (tmpu->user->clifd != clifd && tmpu->user->isco) {
				dprintf(tmpu->user->clifd, "%s\n", args[1]);
				dprintf(map->graphical_fd ,"pbc %d %s\n",
					tmpu->user->clifd, args[1]);
			}
		}
	}
	return map;
}

void	*r_connect_nbr(char ** args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);

	dprintf(clifd, "%d\n", count_nb_empty(map->teams, player->team_name));
	return map;
}

void	*r_take_obj(char ** args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);
	int x = player->curr_pos[0];
	int y = player->curr_pos[1];

	printf("Player's food before:\t%d\n", player->inventory.food.qtt);
	printf("Food on tile before:\t%d\n", map->tiles[x][y].ressources.food.qtt);
	if (check_obj_on_map(map, x, y, args[1])) {
		player = add_obj_to_player(player, args[1]);
		del_obj_on_map(map, x, y, args[1]);
		dprintf(clifd, "ok\n");
	}
	else
		dprintf(clifd, "ko\n");
	printf("Player's food after:\t%d\n", player->inventory.food.qtt);
	printf("Food on tile after:\t%d\n", map->tiles[x][y].ressources.food.qtt);
	return map;
}

void	*r_set_obj(char ** args, int clifd, t_world *map)
{
	args[0][0] = 'c';
	t_inhabitant *player = find_player_by_fd(map->teams, clifd);
	int x = player->curr_pos[0];
	int y = player->curr_pos[1];

	printf("Player's food before:\t%d\n", player->inventory.food.qtt);
	printf("Food on tile before:\t%d\n", map->tiles[x][y].ressources.food.qtt);
	if (check_obj_in_inv(player, args[1])) {
		player = del_obj_from_player(player, args[1]);
		add_obj_to_map(map, x, y, args[1]);
		dprintf(clifd, "ok\n");
	}
	else
		dprintf(clifd, "ko\n");
	printf("Player's food after:\t%d\n", player->inventory.food.qtt);
	printf("Food on tile after:\t%d\n", map->tiles[x][y].ressources.food.qtt);
	return map;
}
