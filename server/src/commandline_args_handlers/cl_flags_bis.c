/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments flags getter helpers (next)
*/

#include <stdlib.h>
#include "../../include/server.h"

/** Get -n flag, the teams name
* @param teams the received argument to flag
* @param args the t_clargs struct to fill with teams names values
*/
void	*get_teams(char **teams, t_clargs *args)
{
	unsigned int size = 0;

	args->teams_names = malloc(MAXTEAMS);
	memset(args->teams_names, 0, MAXTEAMS);
	for (size = 1; teams[size]; ++size) {
		args->teams_names[size - 1] = strdup(teams[size]);
	}
	args->teams_names[size] = NULL;
	return (size <= 1 ? NULL : args);
}

/** Get -c flag, the number of clients(aka players) per teams
* @param clientsNb the received arguments to flag
* @param args the t_clargs struct to fill with clientsNb value
*/
void	*get_clientsNb(char **clientsNb, t_clargs *args)
{
	args->clientsNb = atoi(clientsNb[1]);
	return (args->clientsNb >= 0 ? args : NULL);
}

/** Get -f flag, the frequency of blablabla
* @param freq the received argument to flag
* @param args the t_clargs struct to fill with frequency value
*/
void	*get_freq(char **freq, t_clargs *args)
{
	args->freq = atoi(freq[1]);
	return (args->freq > 0 ? args : NULL);
}
