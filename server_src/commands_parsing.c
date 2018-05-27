/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server source file
*/

#include "../include/server.h"

/** Match all methods in G_CMDS for a given req command string
* @param req the requested command on format 'CMD <space> [ARGS]'
* @param clifd the client socket fd
*/
int	get_methods(char *req, int clifd)
{
	int index = 0;
	int i = 0;
	int j = 0;
	char *str, *arg = NULL;
	char args[MAXARGS][MAXARGSIZE] = {{0},{0}};

	str = strdup(req);
	arg = strtok(str, " \r\n");
	while (arg) {
		strncpy(args[i++], arg, MAXARGSIZE);
		arg = strtok(NULL, " \r\n");
	}
	print_arg(args);
	for (j = 0; args[j]; ++j) {
		for (index = 0; G_PROTOS[index]; ++index) {
			if ((strcasestr(args[j], G_PROTOS[index]))) {
				index = G_CMDS[index](args, clifd);
				break;
			}
		}
	}

	memset(req, 0, BUF_SIZE);
	return ((index == REF_NB) ? (0) : (index));
}
