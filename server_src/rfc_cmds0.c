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
	if (clifd)
	printf("NICK [%s] joining the BrokenIRC server\r\n", nickname[1]);
	// dprintf(clifd, "001 :Welcome %s\r\n", nickname[1]);
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
	static t_userlist *liste = NULL;
	char *banneer = ":BrokenIRC.foo || Welcome to BrokenIRC Network || ";

	if (usercmd[1][0]) {
		t_user *usr = get_new_user(clifd, usercmd);
		t_userlist *userlist = get_new_userlist(usr);
		liste = push_back(liste, userlist);
		dprintf(clifd, "001 %s :Welcome %s\r\n", usercmd[1], banneer);
	}
	print_users(liste);
	return (0);
}

int 	quit(cmdargs quitmsg, int clifd)
{
	printf("%scmd received\n", quitmsg[0]);
	dprintf(clifd, ":BrokenIRC!127.0.0.1 QUIT :%s", quitmsg[1]);
	return (0);
}
