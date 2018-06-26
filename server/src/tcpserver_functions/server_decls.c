/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server global variables
** for commands settings see methodsXX.c files
*/

#include "../../include/cmd_fcts.h"

/** The 2D array containing the handled commands strings for comparison  */
const char *G_PROTOS[REF_NB] = {
	"Forward",
	"Right",
	"Left",
	"Team",
	"Inventory",
	"Broadcast",
	"Connect_nbr",
	"Take",
	"Set",
	NULL
};

/** The functions pointers for the various RFC commands handlers */
const cmds G_CMDS[REF_NB] = {
	r_forward,
	r_right,
	r_left,
	r_team,
	r_inventory,
	r_broadcast,
	r_connect_nbr,
	r_take_obj,
	r_set_obj,
	NULL
};
