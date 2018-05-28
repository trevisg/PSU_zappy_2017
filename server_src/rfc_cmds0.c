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
	t_user *user = find_user_by_fd(chans->users, clifd);
	t_channel *reqchan = get_chan_by_name(chans, args[1]);
	t_userlist *userlist = reqchan ? reqchan->users :
		get_new_userlist(user);
	t_channel *nchan = reqchan ? NULL :
		get_new_chan_list(userlist, args[1]);
	chans = nchan ? insert_back_channel(chans, nchan) :
		chans;
	dprintf(clifd, ":%s JOIN %s\r\n", user->nick, args[1]);
	dprintf(clifd, ":127.0.0.1 331\r\n%s: no topic is set\r\n", args[1]);
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
	if (chans || !chans)
	printf("[%s] cmd received\n", args[0]);
	chans = remove_user(chans->users, clifd);
	dprintf(clifd, ":BrokenIRC!127.0.0.1 <user> QUIT :%s", args[1]);
	close(clifd);
	return (chans);
}
