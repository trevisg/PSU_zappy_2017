/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** map management on server
*/

#pragma once

#include "server.h"
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 5

/* Used to store items present on a tile 
*  It can be considered like an inventory for a player
*/
typedef struct s_items
{
	int nfood;
	int nlinemate;
	int nderaumere;
	int nsibur;
	int nmendiane;
	int nphiras;
	int nthystame;
} t_items, *p_items, s_inventory;

/* Definition of a tile */
typedef struct s_tile
{
	t_userlist *players;
	t_items items;
} t_tile, *p_tile;

/* See server_src/map.c */
t_items get_random_item(void);
void destroy_map(p_tile *map);
p_tile *create_map(int dimX, int dimY);
void fill_map(p_tile *map, int dimX, int dimY);
