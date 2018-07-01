/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server AI client to server commands
*/

#include "../../include/cmd_fcts.h"

/** Chained list helper function to find a user in all t_teams by its clifd
* @param clifd the message sender unique identifier
* @param temps the t_world::teams containing all the teams and their users
* @return user the requested t_inhabitant pointer
*/
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

void		print_cell(int y, int x, t_inhabitant *usr, t_teams *teams)
{
	printf("%d:%d[%s", x, y, (usr && y == usr->curr_pos[Y]
	&& x == usr->curr_pos[X]) ? "X" : "");
	/** Starting iterate over teams */
	for (t_teams *tmp = teams; tmp; tmp = tmp->next) {
		/** Locate the usr teammates */
		if (!strcmp(tmp->team_name, usr->team_name)) {
			/** Is there a teammate on this tile ? */
			for (t_userlist *tpm = teams->users;
				tpm; tpm = tpm->next) {
				printf("%s", (tpm->user->curr_pos[Y] == y
				&& tpm->user->curr_pos[X] == x)
				&& (tpm->user->curr_pos[Y] != usr->curr_pos[Y]
				&& tpm->user->curr_pos[X] != usr->curr_pos[X]) ?
				"o," : "");
			}
			printf("%s", "]");
			break;
		}
	}
}

uint		is_tile_to_look(int **to_look, int i, int j)
{
	uint rt = ((to_look[0][X] == j && to_look[0][Y] == i)
	|| (to_look[1][X] == j && to_look[1][Y] == i)
	|| (to_look[2][X] == j && to_look[2][Y] == i))
	? true : false;

	return (rt);
}

/** Helper for ai_look and ai_forward functions, return an int array containing
* the 'viewable' tiles for a Level 1 player, ** handle ORIENTATION::N **
* positions.
* @param to_look the positions to be set
* @param playerx the player X position
* @param playery the player Y position
* @param level the player current level
* @return to_look the int array `look north side` tiles coordinates
*/
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

/** Helper for ai_look and ai_forward functions, return an int array containing
* the 'viewable' tiles for a Level 1 player, ** handle ORIENTATION::S **
* positions.
* @param to_look the positions to be set
* @param playerx the player X position
* @param playery the player Y position
* @param level the player current level
* @return to_look the int array `look south side` tiles coordinates
*/
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

/** Helper for ai_look and ai_forward functions, return an int array containing
* the 'viewable' tiles for a Level 1 player, ** handle ORIENTATION::E **
* positions.
* @param to_look the positions to be set
* @param playerx the player X position
* @param playery the player Y position
* @param level the player current level
* @return to_look the int array `look east side` tiles coordinates
*/
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

/** Helper for ai_look and ai_forward functions, return an int array containing
* the 'viewable' tiles for a Level 1 player, ** handle ORIENTATION::W **
* positions.
* @param to_look the positions to be set
* @param playerx the player X position
* @param playery the player Y position
* @param level the player current level
* @return to_look the int array `look west side` tiles coordinates
*/
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

/** Helper function to ai_look() and ai_forward() methods,
* compute the tiles positions according to player level and orientation
* @param level the player current level
* @param playerx the player x position
* @param playery the player y position
*/
int		**looking_pos(int level, int playerx, int playery,
		ORIENTATION o)
{
	int **to_look = malloc(sizeof(int *) * 3 * level);

	memset(to_look, 0, 3 * level);
	for (int i = 0; i != 3 * level; ++i) {
		to_look[i] = malloc(sizeof(int) * (level + 3));
		memset(to_look[i], 0, level + 3);
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

/** Simple utils function to tp the player if he reach a map side when
* ai_forward()
* @param to_look the computed player new position stored in to_look[0] X,Y
* @param usr the t_inhabitant::curr_pos to update
* @param map the map and its size
*/
void		get_teleport(int **to_look, t_inhabitant *usr, int *msize)
{
	switch (usr->o) {
		case N:
		if ((to_look[0][Y] < 0))
			usr->curr_pos[Y] = msize[X];
		break;
		case E:
		if ((to_look[0][X] >= msize[X]))
			usr->curr_pos[X] = 0;
		break;
		case S:
		if ((to_look[0][Y] > msize[Y]))
			usr->curr_pos[Y] = 0;
		break;
		case W:
		if ((to_look[0][X]) < 0)
			usr->curr_pos[X] = msize[X];
		break;
	}
}

/** Helper function to send a s_tile content to a user when ai_look()
* @param tile the requested tile
* @param clifd the client socket to send content on
*/
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

/** Additional function for ai_look() method, iterate on map and send
* 'user viewable' tiles content
* @note this function also print a meaningfull 2D representation of the running
* AI client moove
* @param usr the t_inhabitant client
* @param map the t_world::map
* @params dims dirty hack to have map size x and y in one variable
*/
void		target_zone(t_inhabitant *usr, t_world *map, int dims[])
{
	int	**to_look = looking_pos(usr->level, usr->curr_pos[X],
			usr->curr_pos[Y], usr->o);

	dprintf(usr->clifd, "[");
	for (int i = 0; i != dims[Y]; ++i) {
		for (int j = 0; j != dims[X]; ++j) {
			print_cell(i, j, usr, map->teams);
			if (i == usr->curr_pos[Y] && j == usr->curr_pos[X])
				dprintf(usr->clifd, "player,");
			if (is_tile_to_look(to_look, i, j)){
				printf("%s", "* ");
				send_tilecontent(map->tiles[i][j], usr->clifd);
				dprintf(usr->clifd, ", ");
			} else
				printf("  ");
		}
		printf("\n\n");
	}
	dprintf(usr->clifd, "]\n");
}

/** The `Look` method implementation
* @param cmdargs the unusued Look command arguments
* @param clifd the unique client socket file descriptor
* @param map the t_world::map for Trantor world
*/
void		*ai_look(char **args, int clifd, t_world *map)
{
	t_inhabitant *usr = get_user(clifd, map->teams);
	int pos[] = { map->sizeX, map->sizeY };
	if (args[0]) {
		target_zone(usr, map, pos);
	}
	return (map);
}

/** The `Right` method implementation
* @param cmdargs the unusued Right command arguments
* @param clifd the unique client socket file descriptor
* @param map the t_world::map for Trantor world
*/
void	*ai_right(char **args, int clifd, t_world *map)
{
	t_inhabitant *usr = get_user(clifd, map->teams);

	printf("%s : \n", args[0]);
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

/** The `Left` method implementation
* @param cmdargs the unusued Left command arguments
* @param clifd the unique client socket file descriptor
* @param map the t_world::map for Trantor world
*/
void	*ai_left(char **args, int clifd, t_world *map)
{
	t_inhabitant *usr = get_user(clifd, map->teams);

	printf("%s : \n", args[0]);
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

/** The `Forward` method implementation
* @param cmdargs the unusued Forward command arguments
* @param clifd the unique client socket file descriptor
* @param map the t_world::map for Trantor world
*/
void			*ai_forward(char **args, int clifd, t_world *map)
{
	int		msize[] = { map->sizeX, map->sizeY };
	t_inhabitant 	*usr = get_user(clifd, map->teams);
	int		**to_look = looking_pos(usr->level, usr->curr_pos[X],
					usr->curr_pos[Y], usr->o);

	printf("%s : \n", args[0]);
	if ((to_look[0][X] >= 0 &&to_look[0][X] <= map->sizeX) &&
	(to_look[0][Y] >= 0 && to_look[0][Y] <= map->sizeX)) {
		usr->curr_pos[X] = to_look[0][X];
		usr->curr_pos[Y] = to_look[0][Y];
	} else {
		get_teleport(to_look, usr, msize);
	}
	dprintf(clifd, "ok\n");
	return (map);
}

/** The `Fork` method implementation
* @param cmdargs the unusued Fork command arguments
* @param clifd the unique client socket file descriptor
* @param map the t_world::map for Trantor world
*/
void	*ai_fork(char **args, int clifd, t_world *map)
{
	printf("%s : \n", args[0]);
	dprintf(clifd, "ok\n");
	return (map);
}
