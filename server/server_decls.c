/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server global variables
** for commands settings see methodsXX.c files
*/

#include "server.h"

const char *G_PROTOS[REF_NB] = {
	"/server", "/nick", "/list", "/join",
	"/part", "/users", "/names",
	"/msg a b", "/msg a b c", "/accept_file",
	NULL
};

const cmds G_CMDS[REF_NB] = {
	user, pass, cwd,
	NULL
};
