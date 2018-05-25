/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server rfc methods functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/server.h"

int	join(cmdargs channame, int clifd)
{
	char *resp2 = ":127.0.0.1 <[RPL_TOPIC][1]> <username>! #foobar :foobi";
	dprintf(clifd, ":<username> %s %s %s\r\n", "JOIN", channame[1], resp2);
	return (0);
}

int     nick(cmdargs nickname, int clifd)
{
	char *banneer = ":BrokenIRC.foo || Welcome to BrokenIRC Network || ";
	if (clifd)
	printf("NICK [%s] joining the BrokenIRC server\r\n", nickname[1]);
	dprintf(clifd, "001 :Welcome %s %s\r\n", nickname[1], banneer);
	return (0);
}

int     ping(cmdargs nope, int clifd)
{
	if (nope || !nope)
	dprintf(clifd, "PONG\r\n");
	printf("PONG\r\n");
	return (0);
}

int     user(cmdargs usercmd, int clifd)
{
	if (clifd)
	printf("USER [%s] cmd received\n", usercmd[1]);
	return (0);
}
