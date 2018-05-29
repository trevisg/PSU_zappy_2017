/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server logger function source
*/

#include "../include/server.h"
#include <unistd.h>
#include <stdlib.h>

/** Print each channel in list with its users
* @param chanlist the channels doubly linked list
* @param index the received command index to avoid printing each
* time a PING cmd is received (too much log ;))
*/
void	print_users_in_chans(t_channel *chanlist, int index)
{
	if (index != PING) {
		for (t_channel *tmp = chanlist; tmp; tmp = tmp->next) {
			printf("\tChannel : [%s]\n", tmp->channame);
			print_users(tmp->users);
		}
	}
}

/** Print users nick and real name stored in a t_userlist doubly linked list
* @param liste the t_userlist to print
*/
void	print_users(t_userlist *list)
{
	printf("\t\tUSERS LIST :\n");
	for (t_userlist *tmp = list; tmp; tmp = tmp->next) {
		printf("User : [%s], Real Name : [%s]\n",
		tmp->user->nick, tmp->user->rname);
	}
	printf("\n");
}

/** Construct the host:service string from struct infos
* @note this is to avoid sprintf usage
*/
static char *get_host_string(const char *host, const char *service)
{
	char *usr = malloc((NI_MAXHOST + 1 + NI_MAXSERV) * sizeof(*usr));

	memset(usr, 0, NI_MAXHOST + 1 + NI_MAXSERV);
	strncpy(usr, host, NI_MAXHOST);
	strcat(usr, ":");
	strncat(usr, service, NI_MAXSERV);
	return (usr);
}

/** Switch type and print data in t_serv according to a fmt string
* @param etype the kind of event type in [C]onnect, [D]isconnect or default
* @param all the 'catch them all' structure with server infos
* @return 1
*/
int	logthisevent(const char etype, t_serv *all)
{
	char *usr = get_host_string(all->host, all->service);
	char *c_fmt = " => IN: [%zd bytes] FROM: [%s] DATA: [%s]\n";
	char *d_fmt = "USER: [%s] disconnect\n";
	char *def_fmt = "Type:%c Size:%zd DATA: [%s]\n";

	switch (etype) {
		case 'c':
			fprintf(stdout, c_fmt, all->nread, usr, all->buf);
			break;
		case 'd':
			fprintf(stdout, d_fmt, usr);
			break;
		default:
			fprintf(stdout, def_fmt, etype, all->nread, all->buf);
			break;
	}
	free(usr);
	return (1);
}
