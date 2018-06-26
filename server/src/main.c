/*
** EPITECH PROJECT, 2018
** PSU_ZAPPY_2017 - Server
** File description:
** Zappy server main() source file
*/

#include <signal.h>
#include "server.h"

/** Self explanatory (here is the main())
* @param ac the number of received args
* @param av the received args, set get_args() for details
*/
int		main(int ac, char **av)
{
	int rt = 0;
	t_clargs *params = NULL;

	if ((params = get_opts(ac, av))) {
		signal(SIGINT, sig_handler);
		rt = server(params);
		free_opts(params);
	} else {
		usage(av[0]);
		free_opts(params);
		rt = 84;
	}
	return (rt);
}
