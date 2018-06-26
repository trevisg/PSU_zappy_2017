/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server command line arguments flags getter helpers
*/

#include <stdlib.h>
#include "server.h"

/** Get -p flag, the requested listening port for server
* @param port the received argument to flag
* @param args the t_clargs struct to fill with port value
*/
void	*get_port(char **port, t_clargs *args)
{
	int rt = 0;

	args->port = strdup(port[1]);
	rt = atoi(port[1]);
	return (rt >= 1024 ? args : NULL);
}

/** Get -x flag, the map width
* @param width the received argument to flag
* @param args the t_clargs struct to fill with width value
*/
void	*get_width(char **width, t_clargs *args)
{
	args->width = atoi(width[1]);
	return (args->width >= 0 ? args : NULL);
}

/** Get -y flag, the map height
* @param height the received argument to flag
* @param args the t_clargs struct to fill with height value
*/
void	*get_height(char **height, t_clargs *args)
{
	args->height = atoi(height[1]);
	return (args->height >= 0 ? args : NULL);
}
