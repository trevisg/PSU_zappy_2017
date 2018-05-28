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
t_userlist	*get_channel_userlist(t_channel *list, char *channame)
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

/** Add user to channel
* @param chanlist the channel list
* @param userlist the userlist
* @param user the t_user pointer to insert
* @param user the user to put in channel
* @return 0 if operation succeed
* @return 1 if failure
*/
int	add_user_to_chan(t_channel *chanlist, t_user *usr)
{
	t_userlist *newuser = get_new_userlist(usr);
	insert_back_user(chanlist->users, newuser);
	return (newuser ? 0 : 1);
}
