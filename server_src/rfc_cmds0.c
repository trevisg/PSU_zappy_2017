/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server rfc methods functions
*/

#include <unistd.h>
#include "../include/server.h"

static int isnewchannel(const char *req, char chans[1000][110])
{
	int i = 0;

	if (strlen(req)) {
		for (i = 0; chans[i]; i++) {
			if (strlen(chans[i]) && !strncmp(chans[i], req, 110)) {
				printf("channel exist ? : %s\n", chans[i]);
				break;
			}
		}
	}
	return (i);
}

int	join(const char *channame, int clifd)
{
	static char chans[MAXCHAN][MAXCHANNAME];
	static int chanselect;

	fprintf(stderr, "%s\n", "sa plante aprés");
	// chanselect = isnewchannel(channame, chans);
	chanselect = 0;
	if (chanselect || !chanselect) {
		sprintf(chans[chanselect], "Welcome to %s\n", channame);
		printf("\n%s", chans[chanselect]);
		dprintf(clifd, "%s\r\n", chans[chanselect]);
	}
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
