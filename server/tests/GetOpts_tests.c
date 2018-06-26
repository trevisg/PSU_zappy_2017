/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments parsing and storage [TESTFILE]
*/

#include <assert.h>
#include "../include/server.h"

static void	print_2d(char **buff)
{
	for(int i = 0; buff[i] != NULL; ++i) {
		printf("\tbuff[%d]: [%s]\n", i, buff[i]);
		assert(strlen(buff[i]) >= 1);
	}
	printf("\n");
}

static void	print_clargs(t_clargs *args)
{
	printf("%s\n", "t_clargs *args :");
	printf("Server port [%s]\n", args->port);
	assert(atoi(args->port) >= 1024);
	printf("Map width [%d]\n", args->width);
	assert(args->width >= 1);
	printf("Map height [%d]\n", args->height);
	assert(args->height >= 1);
	printf("Teams names :\n");
	print_2d(args->teams_names);
	printf("Max players per team [%d]\n", args->clientsNb);
	assert(args->clientsNb >= 1);
	printf("Frequency [%d]\n", args->freq);
	assert(args->freq > 0);
}

int	main(int ac, char **av)
{
	int rt = 0;
	t_clargs *args = NULL;

	if (!(args = get_opts(ac, av))) {
		fprintf(stderr, "%s\n", "Bogus args RTFM");
		free_opts(args);
		rt = 84;
	} else {
		print_clargs(args);
		free_opts(args);
	}
	return (rt);
}
