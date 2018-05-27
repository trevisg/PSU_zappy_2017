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
	t_userlist *tmp;

	for (tmp = list; tmp; tmp = tmp->next) {
		if (tmp->user->clifd == clifd) {
			printf("%s Find \n", tmp->user->nick);
			break;
		}
	}
	return (tmp->user->clifd == clifd ? tmp->user : NULL);
}

/** Get the t_userlist from a t_channel channel list
* @param list the list to find in
* @param channame the key to find the channel
* @return res the needed userlist if found , NULL otherwise
*/
t_userlist *get_channel_userlist(t_channel *list, char *channame)
{
	t_channel *tmp;
	t_userlist *res = NULL;

	for (tmp = list; tmp; tmp = tmp->next) {
		if (!strcmp(tmp->channame, channame)) {
			res = tmp->users;
			break;
		}
	}
	return (res);
}
