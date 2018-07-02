/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server global variables
** for commands settings see methodsXX.c files
*/

#include "cmd_fcts.h"

/** The 2D array containing the handled commands strings for comparison  */
const char *G_PROTOS[REF_NB] = {
	"Forward",
	"Right",
	"Left",
	"Team",
	"Look",
	"Fork",
	NULL
};

/** The functions pointers for the various RFC commands handlers */
const cmds G_CMDS[REF_NB] = {
	ai_forward,
	ai_right,
	ai_left,
	r_team,
	ai_look,
	ai_fork,
	NULL
};

/** The 2D array containing the graphical client to server methods name
* for comparison
*/
const char *G_GRAPH_PROTO[REF_NB] = {
	"GET /mapsize",
	"GET /teamnames",
	"POST /team_detail&team=",
	NULL
};

/** The functions pointers for the various RFC commands handlers */
const cmds G_GRAPH_CMDS[REF_NB] = {
	g_mapsize,
	g_teams_names,
	g_team_detail,
	NULL
};
