/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server global variables
** for commands settings see methodsXX.c files
*/

#include "../../include/server.h"
#include "../../include/cmd_fcts.h"

/** The 2D array containing the handled commands strings for comparison  */
const char *G_PROTOS[REF_NB] = {
	"FORWARD", "Right", "Left",
	NULL
};

/** The functions pointers for the various RFC commands handlers */
const cmds G_CMDS[REF_NB] = {
	forward, right, left,
	NULL
};
