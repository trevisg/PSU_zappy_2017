/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server rfc methods functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/server.h"

/** The JOIN #<teams> command handler
* @param args the JOIN arguments, composed of the teams name started by '#'
* @param clifd the client file descriptor
* @param chans the main teams doubly linked list (updated if new teams)
* @return chans the head pointer of the teams list passed in params
* @note see RFC 2812 part 3.2.1
*/
void	*join(cmdargs args, int clifd, t_teams *chans)
{
	t_user *usr = find_user_by_fd(chans->users, clifd);
	t_userlist *list = get_new_userlist(usr);
	t_teams *rchan = get_team_by_name(chans, args[1]);

	if (usr) {
		if (!rchan) {
		rchan = get_new_chan_list(list, args[1]);
		chans = insert_back_teams(chans, rchan);
		} else if (!find_user_by_fd(rchan->users, clifd)) {
			rchan->users = insert_back_user(rchan->users, list);
		}
		for (t_userlist *b = rchan->users; b; b = b->next) {
			dprintf(b->user->clifd, ":%s JOIN :%s\r\n", usr->nick, args[1]);
		}
		dprintf(clifd, ":server 331\r\n%s: no topic is set\r\n", args[1]);
	}
	return (chans);
}

/** The NICK <nickname> command handler handler
* @param args the NICK arguments, composed of the requested username
* @param clifd the client file descriptor (unusued)
* @param chans the main teams doubly linked list (unusued)
* @return chans the head pointer of the teams list passed in params
* @note stil missing the update username and the error messages if
* nickname already in use, invalid nickname etc .. (see RFC 2812 part 3.1.2)
*/
void     *nick(cmdargs args, int clifd, t_teams *chans)
{
	char *fmt = ":BrokenIRC NICK %s\r\n";


	if (clifd)
	for (t_userlist *tmp = chans->users; tmp; tmp = tmp->next) {
			dprintf(tmp->user->clifd, fmt, args[1]);
	}
	return (chans);
}

/** The PING <server address> command handler
* @param args the PING arguments, composed of the above arguments
* @param clifd the client file descriptor (unusued)
* @param chans the main teams doubly linked list (unusued)
* @return chans the head pointer of the teams list passed in params
* @note simply answer PONG followed by the conventionnal EOL symbol
*/
void	*ping(cmdargs args, int clifd, t_teams *chans)
{
	if (args || !args || chans)
	dprintf(clifd, "PONG\r\n");
	return (chans);
}

/** The USER <username> <mode> <unusued> <realname> command handler
* @param args the JOIN arguments, composed of the above args
* @param clifd the client file descriptor
* @param chans the main teams doubly linked list,
* updated by pushback'ing the new user in chan->users list
* @return chans the head pointer of the teams list passed in params
* @note Still missing a lot of check for size, dublons etc etc and
* also the <mode> handling (invisible etc) see RFC 2812 part 3.1.3
*/
void     *user(cmdargs args, int clifd, t_teams *chans)
{
	char *banneer = "|| Welcome to BrokenIRC Network || ";

	if (get_size(args) == 5) {
		t_user *usr = get_new_user(clifd, args);
		t_userlist *list = get_new_userlist(usr);
		chans->users = insert_back_user(chans->users, list);
		dprintf(clifd, "001 :%s %s %s\r\n", args[1], args[1], banneer);
	}
	return (chans);
}

/** The QUIT <quit message> command handler
* @param args the QUIT arguments, composed of the above args
* @param clifd the client file descriptor
* @param chans the main teams doubly linked list (updated if new teams)
* @return chans the head pointer of the teams list passed in params
* @note still a bit buggy on the remove_user() part (run and see by urself)
*/
void	*quit(cmdargs args, int clifd, t_teams *chans)
{
	t_user *usr = find_user_by_fd(chans->users, clifd);

	if (usr) {
		for (t_userlist *b = chans->users; b; b = b->next) {
			dprintf(b->user->clifd, ":%s QUIT :%s\r\n", usr->nick, args[1]);
		}
		for (t_teams *chan = chans; chan; chan = chan->next) {
			is_user_in_chan(clifd, chan);
		}
	}
	close(clifd);
	return (chans);
}
