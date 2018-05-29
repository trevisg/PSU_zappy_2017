/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server rfc methods functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/server.h"

void	*join(cmdargs args, int clifd, t_channel *chans)
{
	t_user *usr = find_user_by_fd(chans->users, clifd);
	t_userlist *list = get_new_userlist(usr);
	t_channel *rchan = get_chan_by_name(chans, args[1]);

	if (!rchan) {
		rchan = get_new_chan_list(list, args[1]);
		chans = insert_back_channel(chans, rchan);
	} else if (!find_user_by_fd(rchan->users, clifd)) {
		rchan->users = insert_back_user(rchan->users, list);
	}
	for (t_userlist *b = rchan->users; b; b = b->next) {
		dprintf(b->user->clifd, ":%s JOIN :%s\r\n", usr->nick, args[1]);
	}
	dprintf(clifd, ":server 331\r\n%s: no topic is set\r\n", args[1]);
	return (chans);
}

void     *nick(cmdargs args, int clifd, t_channel *chans)
{
	if (clifd || chans)
	printf("NICK [%s] joining the BrokenIRC server\r\n", args[1]);
	return (chans);
}

void	*ping(cmdargs args, int clifd, t_channel *chans)
{
	if (args || !args || chans)
	dprintf(clifd, "PONG\r\n");
	return (chans);
}

void     *user(cmdargs args, int clifd, t_channel *chans)
{
	char *banneer = "|| Welcome to BrokenIRC Network || ";

	t_user *usr = get_new_user(clifd, args);
	t_userlist *list = get_new_userlist(usr);
	chans->users = insert_back_user(chans->users, list);
	dprintf(clifd, "001 :%s %s %s\r\n", args[1], args[1], banneer);
	return (chans);
}

void	*quit(cmdargs args, int clifd, t_channel *chans)
{
	t_user *usr = find_user_by_fd(chans->users, clifd);
	for (t_userlist *b = chans->users; b; b = b->next) {
		dprintf(b->user->clifd, ":%s QUIT :%s", usr->nick, args[1]);
	}
	chans->users = remove_user(chans->users, clifd);
	close(clifd);
	return (chans);
}
