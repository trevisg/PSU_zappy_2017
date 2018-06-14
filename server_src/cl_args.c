/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments parsing and storage
*/

#include <stdlib.h>
#include "../include/server.h"

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

/** Free the token list
* @param buffer the 2D array to be free'd
*/
static void free_buffers(char **buffer)
{
	int i;

	for (i = 0; buffer[i]; ++i) {
		free(buffer[i]);
	}
	free(buffer);
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

/** Get -p flag, the requested listening port for server
* @param port the received argument to flag
* @param args the t_clargs struct to fill with port value
*/
void	*get_port(char **port, t_clargs *args)
{
	#ifdef CLDBG
		printf("\t\t%s\n", "get_port()");
		print_2d(port);
	#endif
	args->port = atoi(port[1]);
	return (args->port >= 1024 ? args : NULL);
}

/** Get -x flag, the map width
* @param width the received argument to flag
* @param args the t_clargs struct to fill with width value
*/
void	*get_width(char **width, t_clargs *args)
{
	#ifdef CLDBG
		printf("\t\t%s\n", "get_width()");
		print_2d(width);
	#endif
	args->width = atoi(width[1]);
	return (args->width >= 0 ? args : NULL);
}

/** Get -y flag, the map height
* @param height the received argument to flag
* @param args the t_clargs struct to fill with height value
*/
void	*get_height(char **height, t_clargs *args)
{
	#ifdef CLDBG
		printf("\t%s\n", "get_height ouh yeah!");
		print_2d(height);
	#endif
	args->height = atoi(height[1]);
	return (args->height >= 0 ? args : NULL);
}

/** Get -n flag, the teams name
* @param teams the received argument to flag
* @param args the t_clargs struct to fill with teams names values
*/
void	*get_teams(char **teams, t_clargs *args)
{
	unsigned int size = 0;
	#ifdef CLDBG
		printf("\t%s\n", "get_teams ouh yeah!");
		print_2d(teams);
	#endif
	args->teams_names = malloc(MAXTEAMS);
	for (size = 1; teams[size]; ++size) {
		args->teams_names[size - 1] = strdup(teams[size]);
	}
	return (size > 0 ? args : NULL);
}

/** Get -c flag, the number of clients(aka players) per teams
* @param clientsNb the received arguments to flag
* @param args the t_clargs struct to fill with clientsNb value
*/
void	*get_clientsNb(char **clientsNb, t_clargs *args)
{
	#ifdef CLDBG
		printf("\t%s\n", "get_clientsNb ouh yeah!");
		print_2d(clientsNb);
	#endif
	args->clientsNb = atoi(clientsNb[1]);
	return (args->clientsNb >= 0 ? args : NULL);
}

/** Get -f flag, the frequency of blablabla
* @param freq the received argument to flag
* @param args the t_clargs struct to fill with frequency value
*/
void	*get_freq(char **freq, t_clargs *args)
{
	#ifdef CLDBG
		printf("\t%s\n", "get_freq ouh yeah!");
		print_2d(freq);
	#endif
	args->freq = atoi(freq[1]);
	return (args->freq >= 0 ? args : NULL);
}

/** The flags 'gatherer' function pointer */
typedef void *(*clargs)(char **, t_clargs *);
/** The flags 'gatherer' initialiser */
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
	if (ac >= 11 && req) {
		for (size = 1; av[size]; ++size) {
			strncat(req, av[size], strlen(av[size]));
			size != ac - 1 ? strcat(req, " ") : req;
		}
	}
	return (strlen(req) ? req : NULL);
}

/** Parse command line args flags from av[] and store it in a t_clargs struct
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
