/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments parsing and storage
*/

#include <stdlib.h>
#include "../../include/server.h"

#if defined(CLTEST) || defined(CLDBG)
static void	print_2d(char **buff)
{
	for(int i = 0; buff[i]; ++i) {
		printf("\tbuff[%d]: [%s]\n", i, buff[i]);
	}
	printf("\n");
}

static void	print_clargs(t_clargs *args)
{
	printf("%s\n", "t_clargs *args :");
	printf("Server port [%d]\n", args->port);
	printf("Map width [%d]\n", args->width);
	printf("Map height [%d]\n", args->height);
	printf("Teams names :\n");
	print_2d(args->teams_names);
	printf("Max players per team [%d]\n", args->clientsNb);
	printf("Frequency [%d]\n", args->freq);
}
#endif

/** Tokenize the flag buffer, splitting by spaces
* @param buff a command string like "-[x] [args]"
* @param saveptr the requested strtok_r context saving pointer
* @return cmd_args the flags arguments
*/
static char	**get_cmdargs(char *buff, char **saveptr)
{
	char *subtoken = NULL;
	char **cmd_args = malloc(2048);
	unsigned int size = 0;

	if (cmd_args) {
		memset(cmd_args, 0, 2048);
		for (; ; buff = NULL) {
			subtoken = strtok_r(buff, " ", saveptr);
			if (subtoken == NULL)
				break;
			cmd_args[size] = strdup(subtoken);
			size = size + 1 <= 2048 ? size + 1 : size;
		}
		cmd_args[size] = NULL;
	}
	return (cmd_args);
}

/** Construct a single string from av args for an easiest parsing
* @param ac the number of received args
* @param av the command line option from main()
* @return req the string with all args
*/
static char	*get_req(unsigned int ac, char **av)
{
	char	*req = malloc(2048);
	unsigned int size = 0;

	memset(req, 0, 2048);
	if (ac >= 10 && req) {
		for (size = 1; av[size]; ++size) {
			strncat(req, av[size], strlen(av[size]));
			size != ac - 1 ? strcat(req, " ") : req;
		}
	}
	return (strlen(req) ? req : NULL);
}

/** Set default params for frequency argument
* @return args a malloc'ed t_clargs struct with args-freq set to dflt value
*/
static t_clargs		*set_default_args()
{
	t_clargs	*args = malloc(sizeof(*args));

	if (args) {
		args->freq = 100;
	}
	return (args);
}

/** Parse command line args flags from av[] and store it in a t_clargs struct
* @param ac the number of received params
* @param av the 2d char array from main()
* @return args the storage struct
* @return NULL if errors
* @note consider refactoring / splitting this function as it's 2 lines above
* the 20's authorized by this silly/f**ing norm. Variables are also uncorrectly
* declared. We also could do a 'trash bin struct' for all args
*/
t_clargs		*get_opts(int ac, char **av)
{
	t_clargs	*args = set_default_args();
	clargs		*opts = set_opts();
	char 		*req = get_req(ac, av);
	char 		**cmd_args = NULL;
	char 		*token;
	char		*saveptr1, *saveptr2;
	int		index = 0;

	if (args && req) {
		for (; ; req = NULL) {
			token = strtok_r(req, "-", &saveptr1);
			if (token == NULL) {
				break;
			} else {
				index = token[0];
				cmd_args = get_cmdargs(token, &saveptr2);
				cmd_args ? opts[index](cmd_args, args) : opts;
				cmd_args ? free_buffers(cmd_args) : cmd_args;
			}
		}
	}
	return (args);
}

#ifdef CLTEST
int	main(int ac, char **av)
{
	int rt = 0;
	t_clargs *args = NULL;

	if (!(args = get_args(ac, av))) {
		fprintf(stderr, "%s\n", "Bogus args RTFM");
		rt = 84;
	} else {
		print_clargs(args);
	}
	return (rt);
}
#endif
