/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy Game World (Trantor) initialisation
*/

#include <stdlib.h>
#include <time.h>
#include "server.h"

/** Free the t_world ptr with the 2D t_tile array inside
* @param trantor the world pointer to be freed
* @param args the command line args to have the map size
*/
void		free_world(t_world *trantor, t_clargs *args)
{
	t_tile **tmp = trantor->tiles;

	for (int i = 0; i < args->height; ++i) {
		free(tmp[i]);
	}
	free(tmp);
	free(trantor);
}

/** Assign random qtt of ITEMS in each world tile
* @param tileress a pointer to a tile ressource structure
*/
static void	get_ressources(t_ressources *tileress)
{
	memcpy(tileress, &ITEMS, sizeof(ITEMS));
	tileress->food.qtt = rand()%(MAX_RAND-0)+0;
	tileress->linemate.qtt = rand()%(MAX_RAND-0)+0;
	tileress->deraumere.qtt = rand()%(MAX_RAND-0)+0;
	tileress->sibur.qtt = rand()%(MAX_RAND-0)+0;
	tileress->mendiane.qtt = rand()%(MAX_RAND-0)+0;
	tileress->phiras.qtt = rand()%(MAX_RAND-0)+0;
	tileress->thystame.qtt = rand()%(MAX_RAND-0)+0;
}

/** Alloc memory and fill with ressource the t_world::tiles
* @param x the map width
* @param y the map height
* @return tiles the 2D tiles array
*/
static t_tile	**get_tiles(int x, int y)
{
	t_tile	**tiles = malloc(sizeof(*tiles) * y);
	int 	i = 0;
	int	j = 0;

	if (tiles) {
		srand(time(NULL));
		for (i = 0; i < y; ++i) {
			tiles[i] = malloc(sizeof(*tiles[i]) * x);
			for (j = 0; j < x; ++j) {
				get_ressources(&tiles[i][j].ressources);
			}
		}
	}
	return (tiles);
}

/** Setup the trantor world map
* @param args the args pointer containing the map size
* @return trantor the setup'ed map
*/
t_world		*get_world(t_clargs *args)
{
	t_world	*trantor = malloc(sizeof(*trantor));

	if (trantor) {
		trantor->sizeX = args->width;
		trantor->sizeY = args->height;
		trantor->teams = init_teams(args->teams_names);
		trantor->teams = init_userlist(trantor->teams, args);
		trantor->tiles = get_tiles(args->width, args->height);
	}
	return (trantor);
}

#ifdef MAPTEST
int main(int ac, char **av)
{
	if (ac >= 3) {
		t_clargs args;
		args.width = atoi(av[1]);
		args.height = atoi(av[2]);
		t_world *trantor = get_world(&args);
		for (int i = 0; i != atoi(av[1]); ++i) {
			for (int j = 0; j != atoi(av[2]); ++j) {
				t_ressources tmp = trantor->tiles[i][j].ressources;
				printf("%d ", tmp.food.qtt);
			}
			printf("\n");
		}
		free_world(trantor, &args);
	} else {
		printf("USAGE : %s x y\n", av[0]);
	}
	return (0);
}
#endif
