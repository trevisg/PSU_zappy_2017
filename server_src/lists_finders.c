/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server t_userlist and t_teams lists helpers functions
*/

#include "../include/server.h"
#include <stdlib.h>

/** Get the size of a 2d Array
* @return i the size of the cmdargs 2d char *array
*/
unsigned int get_size(cmdargs args)
{
	unsigned int i = 0;
	while (args[i]) {
		++i;
	}
	return (i);
}


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

/** Get the t_teams pointer by its name
* @param list the teams list
* @param channame the resquested teams
* @return a t_teams pointer if exists , NULL otherwise
*/
t_teams	*get_team_by_name(t_teams *list, char *channame)
{
	t_teams *rt = NULL;

	for (t_teams *tmp = list; tmp; tmp = tmp->next) {
		if (!strcmp(tmp->channame, channame)) {
			rt = tmp;
			break;
		}
	}
	return (rt);
}

unsigned int	is_user_in_chan(int clifd, t_teams *chans)
{
	for (t_userlist *usrs = chans->users; usrs; usrs = usrs->next) {
		if (clifd == usrs->user->clifd) {
			printf("Chan name [%s] Is in list ? [%s]\n",
			chans->channame, usrs->user->nick);
			usrs->user->isco = false;
		}
	}
	return (1);
}

/** Find a user by name literaly
* @param name the name to find
*/
t_user	*find_user_by_name(const char *name, t_userlist *usrs)
{
	t_user *needle = NULL;

	for (t_userlist *foo = usrs; foo; foo = foo->next) {
		if (!strcmp(name, foo->user->nick) ||
		!strcmp(name, foo->user->rname)) {
			needle = foo->user;
			break;
		}
	}
	return (needle);
}
