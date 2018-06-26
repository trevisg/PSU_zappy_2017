/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments parsing and storage (helpers)
*/

#include <stdlib.h>
#include "../../include/server.h"

void		*error_exit(t_clargs *args, clargs *opts, char *req_save)
{
	free(args);
	free(opts);
	free(req_save);
	return NULL;
}

void		*clean_exit(t_clargs *args, clargs *opts, char *req_save)
{
	free(opts);
	free(req_save);
	return args;
}


/** Free the t_clargs structure
* @param opts the structure
*/
void	free_opts(t_clargs *opts)
{
	if (opts) {
		free(opts->port);
		free_buffers(opts->teams_names);
		free(opts);
	}
}

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
