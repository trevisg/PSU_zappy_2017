/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server global variables
** for commands settings see methodsXX.c files
*/

#include "../include/server.h"

const char *G_PROTOS[REF_NB] = {
	"join", "nick", "ping", "user", "quit", "privmsg",
	NULL
};

const cmds G_CMDS[REF_NB] = {
	join, nick, ping, user, quit, privmsg,
	NULL
};
