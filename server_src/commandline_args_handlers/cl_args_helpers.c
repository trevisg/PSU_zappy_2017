/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments parsing and storage (helpers)
*/

#include <stdlib.h>
#include "../../include/server.h"

/** Free the token list
* @param buffer the 2D array to be free'd
*/
void	free_buffers(char **buffer)
{
	int i;

	for (i = 0; buffer[i]; ++i) {
		free(buffer[i]);
	}
	free(buffer);
}

/** The flags 'gatherer' initialiser
* @return opts the flags function pointer malloc'ed and assigned
*/
clargs  *set_opts()
{
	clargs *opts = malloc(sizeof(clargs) * 'z');

	opts['p'] = get_port;
	opts['x'] = get_width;
	opts['y'] = get_height;
	opts['n'] = get_teams;
	opts['c'] = get_clientsNb;
	opts['f'] = get_freq;
	return (opts);
}
