/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server t_userlist and t_channel lists helpers functions
*/

#include "../include/server.h"

/** Find a t_user structure pointer if clientfd exist inside
* @param list the full userlist
* @param clifd the 'to find' client fd
* @return user if clientfd exist in the list
* @return NULL pointer if nothing found
*/
t_user	*find_user_by_fd(t_userlist *list, int clifd)
{
	t_user *usr = NULL;

	for (t_userlist *tmp = list; tmp; tmp = tmp->next) {
		if (tmp->user->clifd == clifd) {
			usr = tmp->user;
			break;
		}
	}
	return (usr);
}

/** Get the t_channel pointer by its name
* @param list the channel list
* @param channame the resquested channel
* @return a t_channel pointer if exists , NULL otherwise
*/
t_channel	*get_chan_by_name(t_channel *list, char *channame)
{
	t_channel *rt = NULL;

	for (t_channel *tmp = list; tmp; tmp = tmp->next) {
		if (!strcmp(tmp->channame, channame)) {
			rt = tmp;
			break;
		}
	}
	return (rt);
}
