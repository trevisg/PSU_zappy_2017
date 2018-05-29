/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server rfc methods functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/server.h"

/** Self explanatory
* @param args the splitted message
* @return the constructed string
* @note missing check for buffer size, escape sequence, malicious message etc
* see RFC 2812 part 3.3.1 and how to check for bogus or malicious chars
*/
static char	*get_full_msg(char **args)
{
	char *msg = malloc(BUF_SIZE);

	memset(msg, 0, BUF_SIZE);
	for (int i = 2; args[i]; ++i) {
		strcat(msg, args[i]);
		strcat(msg, " ");
	}
	return (msg);
}

/** The PRIVMSG <msgtarget> <message> command
* @param args the PRIVMSG arguments, see above
* @param clifd the client file descriptor
* @param chans the main channel doubly linked list (updated if new channel)
* @return chans the head pointer of the channel list passed in params
* @note as get_args() split by space we need to reconstruct the original
* message with the get_full_msg() method
* @todo for now, message can only be sent to a channel , missing the message a
* user function
*/
void	*privmsg(cmdargs args, int clifd, t_channel *chans)
{
	t_user *from = find_user_by_fd(chans->users, clifd);
	t_channel *reqchan = get_chan_by_name(chans, args[1]);
	t_userlist *broadcast_list = reqchan->users;
	char *fullmsg = get_full_msg(args);

	for (t_userlist *tmp = broadcast_list; tmp; tmp = tmp->next) {
		if (tmp->user->clifd != clifd) {
			dprintf(tmp->user->clifd, ":%s PRIVMSG %s %s\r\n",
			from->nick, args[1], fullmsg);
		}
	}
	free(fullmsg);
	return (chans);
}
