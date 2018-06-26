/*
** EPITECH PROJECT, 2018
** PSU_ZAPPY_2017 - Server
** File description:
** Zappy server source file
*/

#include "server.h"

void 	usage(char *progname)
{
	printf("USAGE: %s", progname);
	printf(" -p port -x width -y height -n name1 name2 ... ");
	printf("-c clientsNb -f freq\n");
	printf("\tport\t\tis the port number\n");
	printf("\twidth\t\tis the width of the world\n");
	printf("\theight\t\tis the height of the world\n");
	printf("\tnameX\t\tis the name of the team X\n");
	printf("\tclientNb\tis the number of authorized client per team\n");
	printf("\tfreq\t\tis the reciprocal of time unit for execution ");
	printf("of actions\n");
}
