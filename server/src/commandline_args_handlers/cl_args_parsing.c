/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments parsing and storage
*/

#include <stdlib.h>
#include <stdbool.h>
#include "../../include/server.h"

/** Check if all flags are present in command line arguments from main()
* @param av the 2D char array from main()
* @return true if all flags are presents
* @return false if there is any problem
*/
static bool		check_opts(char **av)
{
	int		i = 1;
	int		j = 0;
	int		k = 0;
	char		flags_cnt[6] = "\0";
	const char	*flags[5] = {"-p", "-x", "-y", "-n", "-c"};

	for (; av[i]; ++i) {
		for (j = 0; j <= 4; ++j) {
			if (!strcmp(av[i], flags[j])) {
				flags_cnt[k] = av[i][1];
				++k;
				break;
			}
		}
	}
	return (strstr(flags_cnt, "pxync") ? true : false);
}

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
	uint 	req_size = 0;

	memset(req, 0, 2048);
	if (ac >= 10 && req) {
		for (size = 1; av[size]; ++size) {
			strncat(req, av[size], strlen(av[size]));
			size != ac - 1 ? strcat(req, " ") : req;
		}
	}
	req_size = strlen(req);
	req_size <= 0 ? free(req) : req;
	return (req_size <= 0 ? NULL : req);
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
* @todo  1. Consider refactoring / splitting this function as it's 4 lines above
* the 20's authorized. Variables are also uncorrectly declared.
* solution ? do a 'trash bin struct' for all args and catch them all !
* 2. Add free() for all the malloc'ed buffers
*/
t_clargs		*get_opts(int ac, char **av)
{
	t_clargs	*args = set_default_args();
	char 		*req = get_req(ac, av);
	clargs		*opts = set_opts();
	char		*saveptr1, *saveptr2;
	char 		**cmd_args = NULL;
	char		*req_save = req;
	int		index = 0;
	char 		*token;

	if (args && req && check_opts(av)) {
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
	return (check_opts(av) ? clean_exit(args, opts, req_save) :
		error_exit(args, opts, req_save));
}
