/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server rfc methods functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/server.h"

void	*join(cmdargs args, int clifd, t_channel *chan)
{
	t_user *user = find_user_by_fd(chan->users, clifd);
	t_channel *new = !get_channel_userlist(chan, args[1]) ?
		get_new_channel_list(chan->users, args[1]) :
		NULL;
	chan = insert_back_channel(chan, new);
	dprintf(clifd, "353 %s :%s %s %s\r\n",
		args[1], "foob", user->nick, "fi");
	return (chan);
}

void     *nick(cmdargs args, int clifd, t_channel *chan)
{
	if (clifd || chan)
	printf("NICK [%s] joining the BrokenIRC server\r\n", args[1]);
	return (chan);
}

void	*ping(cmdargs args, int clifd, t_channel *chan)
{
	if (args || !args || chan)
	dprintf(clifd, "PONG\r\n");
	return (chan);
}

void     *user(cmdargs args, int clifd, t_channel *chan)
{
	char *banneer = "|| Welcome to BrokenIRC Network || ";

	t_user *usr = get_new_user(clifd, args);
	t_userlist *list = get_new_userlist(usr);
	chan->users = insert_back_user(chan->users, list);
	dprintf(clifd, "001 :%s %s %s tamere\r\n", args[1], args[1], banneer);
	return (chan);
}

void	*quit(cmdargs args, int clifd, t_channel *chan)
{
	if (chan || !chan)
	printf("[%s] cmd received\n", args[0]);
	chan = remove_user(chan->users, clifd);
	dprintf(clifd, ":BrokenIRC!127.0.0.1 <user> QUIT :%s", args[1]);
	close(clifd);
	return (chan);
}
