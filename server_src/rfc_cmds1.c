/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server rfc methods functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/server.h"

void	*privmsg(cmdargs args, int clifd, t_channel *chans)
{
	t_user *from = find_user_by_fd(chans->users, clifd);
	t_channel *reqchan = get_chan_by_name(chans, args[1]);
	t_userlist *broadcast_list = reqchan->users;

	for (t_userlist *tmp = broadcast_list; tmp; tmp = tmp->next) {
		if (tmp->user->clifd != clifd) {
			dprintf(tmp->user->clifd, ":%s PRIVMSG %s %s\r\n",
			from->nick, args[1], args[2]);
		}
	}
	return (chans);
}
