/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server AI client to server commands
*/

#include "../../include/cmd_fcts.h"

static t_inhabitant	*get_user(int clifd, t_teams *temps)
{
	t_inhabitant *user = NULL;

	for (t_teams *tmpm = temps; tmpm; tmpm = tmpm->next) {
		for (t_userlist *tmp = tmpm->users; tmp; tmp = tmp->next) {
			if (tmp->user->clifd == clifd) {
				user = tmp->user;
				break;
			}
		}
	}
	printf("User level %d\n", user->level);
	printf("User orientation : ");
	user->o == N ? printf("N\n") : user->o == E ? printf("E\n") :
	user->o == S ? printf("S\n") : user->o == W ? printf("W\n") :
	printf("??\n");
	return (user);
}

void		print_cell(int y, int x, t_inhabitant *usr)
{
	printf("%d:%d[%s", y, x, (usr && y == usr->curr_pos[Y]
	&& x == usr->curr_pos[X]) ? "X]" : ".]");
}


int		**set_north(int **to_look, int playerx, int playery, int level)
{
	to_look[0][Y] = playery - level;
	to_look[0][X] = playerx;
	to_look[1][Y] = to_look[0][Y];
	to_look[1][X] = to_look[0][X] - level;
	to_look[2][Y] = to_look[0][Y];
	to_look[2][X] = to_look[0][X] + level;
	return (to_look);
}

int		**set_south(int **to_look, int playerx, int playery, int level)
{
	to_look[0][Y] = playery + level;
	to_look[0][X] = playerx;
	to_look[1][Y] = to_look[0][Y];
	to_look[1][X] = to_look[0][X] + level;
	to_look[2][Y] = to_look[0][Y];
	to_look[2][X] = to_look[0][X] - level;
	return (to_look);
}

int		**set_east(int **to_look, int playerx, int playery, int level)
{
	to_look[0][Y] = playery;
	to_look[0][X] = playerx + level;
	to_look[1][Y] = to_look[0][Y] - level;
	to_look[1][X] = to_look[0][X];
	to_look[2][Y] = to_look[0][Y] + level;
	to_look[2][X] = to_look[0][X];
	return (to_look);
}

int		**set_west(int **to_look, int playerx, int playery, int level)
{
	to_look[0][Y] = playery;
	to_look[0][X] = playerx - level;
	to_look[1][Y] = to_look[0][Y] + level;
	to_look[1][X] = to_look[0][X];
	to_look[2][Y] = to_look[0][Y] - level;
	to_look[2][X] = to_look[0][X];
	return (to_look);
}

int		**looking_pos(int level, int playerx, int playery,
		ORIENTATION o)
{
	int **to_look = malloc(3 * level);

	for (int i = 0; i != 3 * level; ++i) {
		to_look[i] = malloc(level + 3);
	}
	switch (o) {
		case N:
		set_north(to_look, playerx, playery, level);
		break;
		case E:
		set_east(to_look, playerx, playery, level);
		break;
		case S:
		set_south(to_look, playerx, playery, level);
		break;
		case W:
		set_west(to_look, playerx, playery, level);
		break;
	}
	return (to_look);
}

void		send_tilecontent(t_tile tile, int clifd)
{
	dprintf(clifd, "%s",
	tile.ressources.food.qtt ? "food " : "");
	dprintf(clifd, "%s",
	tile.ressources.sibur.qtt ? "sibur " : "");
	dprintf(clifd, "%s",
	tile.ressources.phiras.qtt ? "phiras " : "");
	dprintf(clifd, "%s",
	tile.ressources.mendiane.qtt ? "mendiane " : "");
	dprintf(clifd, "%s",
	tile.ressources.thystame.qtt ? "thystame " : "");
	dprintf(clifd, "%s",
	tile.ressources.linemate.qtt ? "lynemate" : "");
}

uint		is_tile_to_look(int **to_look, int i, int j)
{
	uint rt = ((to_look[0][X] == j && to_look[0][Y] == i)
	|| (to_look[1][X] == j && to_look[1][Y] == i)
	|| (to_look[2][X] == j && to_look[2][Y] == i))
	? true : false;

	return (rt);
}

void		target_zone(t_inhabitant *usr, t_tile **map, int dims[], int clifd)
{
	int	**to_look = looking_pos(usr->level, usr->curr_pos[X],
			usr->curr_pos[Y], usr->o);

	dprintf(clifd, "[");
	for (int i = 0; i != dims[Y]; ++i) {
		for (int j = 0; j != dims[X]; ++j) {
			print_cell(i, j, usr);
			if (i == usr->curr_pos[Y] && j == usr->curr_pos[X])
				dprintf(clifd, "player,");
			if (is_tile_to_look(to_look, i, j)){
				printf("%s", "* ");
				send_tilecontent(map[i][j], clifd);
				dprintf(clifd, ", ");
			} else
				printf("  ");
		}
		printf("\n\n");
	}
	dprintf(clifd, "]\n");
}

void		*ai_look(char **cmdargs, int clifd, t_world *map)
{
	t_inhabitant *usr = get_user(clifd, map->teams);
	int pos[] = { map->sizeX, map->sizeY };
	if (cmdargs[0]) {
		target_zone(usr, map->tiles, pos, clifd);
	}
	return (map);
}

void	*ai_right(char **cmdargs, int clifd, t_world *map)
{
	t_inhabitant *usr = get_user(clifd, map->teams);

	printf("%s : \n", cmdargs[0]);
	switch (usr->o) {
		case N:
		usr->o = E;
		break;
		case E:
		usr->o = S;
		break;
		case S:
		usr->o = W;
		break;
		case W:
		usr->o = N;
		break;
	}
	dprintf(clifd, "ok\n");
	return (map);
}

void	*ai_left(char **cmdargs, int clifd, t_world *map)
{
	t_inhabitant *usr = get_user(clifd, map->teams);

	printf("%s : \n", cmdargs[0]);
	switch (usr->o) {
		case N:
		usr->o = W;
		break;
		case E:
		usr->o = N;
		break;
		case S:
		usr->o = E;
		break;
		case W:
		usr->o = S;
		break;
	}
	dprintf(clifd, "ok\n");
	return (map);
}

void		*ai_forward(char **cmdargs, int clifd, t_world *map)
{
	t_inhabitant *usr = get_user(clifd, map->teams);
	int	**to_look = looking_pos(usr->level, usr->curr_pos[X],
			usr->curr_pos[Y], usr->o);

	printf("%s : \n", cmdargs[0]);
	if ((to_look[0][X] >= 0 &&to_look[0][X] <= map->sizeX) &&
	(to_look[0][Y] >= 0 && to_look[0][Y] <= map->sizeX)) {
		usr->curr_pos[X] = to_look[0][X];
		usr->curr_pos[Y] = to_look[0][Y];
		dprintf(clifd, "ok\n");
	} else {
		printf("Unreachable position %d,%d\n",
		to_look[0][X], to_look[0][Y]);
		dprintf(clifd, "ko\n");
	}
	return (map);
}
