/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments parsing and storage
*/

#include <stdlib.h>
#include "../include/server.h"

void	*get_port(char **port, t_clargs *args)
{
	#ifdef CLTEST
		printf("\t%s\n", "get_port ouh yeah!");
	#endif
	args->port = atoi(port[0]);
	return (args->port >= 1024 ? args : NULL);
}

void	*get_width(char **width, t_clargs *args)
{
	#ifdef CLTEST
		printf("\t%s\n", "get_width ouh yeah!");
	#endif
	args->width = atoi(width[0]);
	return (args->width >= 0 ? args : NULL);
}

void	*get_height(char **height, t_clargs *args)
{
	#ifdef CLTEST
		printf("\t%s\n", "get_height ouh yeah!");
	#endif
	args->height = atoi(height[0]);
	return (args->height >= 0 ? args : NULL);
}

void	*get_teams(char **teams, t_clargs *args)
{
	unsigned int size = 0;
	#ifdef CLTEST
		printf("\t%s\n", "get_teams ouh yeah!");
	#endif
	args->teams_names = malloc(MAXTEAMS);
	for (; teams[size]; ++size) {
		args->teams_names[size] = strdup(teams[size]);
	}
	return (size > 0 ? args : NULL);
}

void	*get_clientsNb(char **clientsNb, t_clargs *args)
{
	#ifdef CLTEST
		printf("\t%s\n", "get_clientsNb ouh yeah!");
	#endif
	args->clientsNb = atoi(clientsNb[0]);
	return (args->clientsNb >= 0 ? args : NULL);
}

void	*get_freq(char **freq, t_clargs *args)
{
	#ifdef CLTEST
		printf("\t%s\n", "get_freq ouh yeah!");
	#endif
	args->freq = atoi(freq[0]);
	return (args->freq >= 0 ? args : NULL);
}

typedef void *(*clargs)(char **, t_clargs *);
clargs  *get_opts()
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

static char	*get_req(unsigned int ac, char **av)
{
	char	*req = NULL;
	unsigned int size = 0;

	if (ac >= 11) {
		req = malloc(2048);
		for (size = 1; av[size]; ++size) {
			strncat(req, av[size], strlen(av[size]));
			size != ac - 1 ? strcat(req, " ") : req;
		}
	}
	return (req);
}

/** Parse command line args from av[] and store it in a t_clargs struct
* @param ac the number of received params
* @param av the 2d char array from main()
* @return args the storage struct
* @return NULL if errors
*/
t_clargs		*get_args(int ac, char **av)
{
	t_clargs	*args = malloc(sizeof(*args));
	clargs		*opts = get_opts();
	char 		*req = get_req(ac, av);
	char		*cmd = NULL;
	int		index = 0;

	if (args && req) {
		cmd = strtok(req, "-");
		index = cmd[0];
		printf("Opts : [%d] [%s]\n", index, cmd);
		opts[index](av, args);
		while (cmd) {
			cmd = strtok(NULL, "-");
			index = cmd ? cmd[0] : 0;
			printf("Index : [%c] Opts : [%s]\n", index, cmd);
			index ? opts[index](av, args) : opts;
		}
	}
	return (args);
}

#ifdef CLTEST
int	main(int ac, char **av)
{
	int rt = 0;
	if (!get_args(ac, av)) {
		fprintf(stderr, "%s\n", "Bogus args RTFM");
		rt = 84;
	}
	return (rt);
}
#endif
