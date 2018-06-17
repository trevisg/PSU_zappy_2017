/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Map management on server
*/

#include "map.h"

/* Create a new map with dimX & dimY dimensions
** It return a pointer on the new allocated map
*/
p_tile *create_map(int dimX, int dimY)
{
	int i;
	p_tile *new_map = malloc(sizeof(t_tile) * dimY);

	if (new_map) {
		for (i = 0; i < dimY; i++) {
			new_map[i] = malloc(sizeof(t_tile) * dimX);
			if (!new_map[i]) {
				destroy_map(new_map);
				return NULL;
			}
		}
	}
	return new_map;
}

/* Destroy the map by free all elmts
 */
void destroy_map(p_tile *map)
{
	int i;

	for (i = 0; map[i]; i++) {
		free(map[i]);
	}
	free(map);
}

/* Fill the map with random items value
 */
void fill_map(p_tile *map, int dimX, int dimY)
{
	int i;
	int j;

	srand(time(NULL));
	for (i = 0; i < dimY; i++) {
		for (j = 0; j < dimX; j++) {
			map[i][j].items = get_random_item();
		}
	}
}

/* Get an item randomly generated
** See MAX_RAND in map.h
*/
t_items get_random_item(void)
{
	t_items item;

	item.nfood = rand()%(MAX_RAND-0)+0;
	item.nlinemate = rand()%(MAX_RAND-0)+0;
	item.nderaumere = rand()%(MAX_RAND-0)+0;
	item.nsibur = rand()%(MAX_RAND-0)+0;
	item.nmendiane = rand()%(MAX_RAND-0)+0;
	item.nphiras = rand()%(MAX_RAND-0)+0;
	item.nthystame = rand()%(MAX_RAND-0)+0;
	return item;
}
