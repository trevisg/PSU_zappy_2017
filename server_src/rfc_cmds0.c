/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server rfc methods functions
*/

#include <unistd.h>
#include "../include/server.h"

int	join(const char *channame, int clifd)
{
	static char chans[MAXCHAN][MAXCHANNAME];
	int chanselect = 0;
	int cnt = 0;

	for (chanselect = 0; chanselect <= MAXCHAN; ++chanselect) {
		if (!strcmp(channame, chans[chanselect])) {
			printf("chans ? %s ", chans[chanselect]);
			break;
		} else if (strlen(chans[chanselect]) > 2) {
			sprintf(chans[chanselect], "%s", channame);
			cnt += 1;
		}
	}
	chanselect = cnt ? cnt : chanselect;
	sprintf(chans[chanselect], "%s", channame);
	dprintf(clifd, "Welcome to %s channel\r\n", chans[chanselect]);
	return (0);
}

int	part(const char *channame, int clifd)
{
	static char chans[MAXCHAN][MAXCHANNAME];
	static int chanselect;

	chanselect += 1;
	if (printf("is valid channel name\n") || chanselect) {
		sprintf(chans[chanselect], "Welcome to %s\n", channame);
		printf("\n%s", chans[chanselect]);
		dprintf(clifd, "%s\r\n", chans[chanselect]);
	}
	return (0);
}
