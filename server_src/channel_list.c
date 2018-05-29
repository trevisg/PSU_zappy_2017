/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server channel list methods
*/

#include "../include/server.h"
#include <stdlib.h>

/** Self explanatory
* @param userlist the userlist to insert in the new channel element
* @param channame the new channel name
*/
t_channel	*get_new_chan_list(t_userlist *userlist, char *channame)
{
	t_channel *list = malloc(sizeof(*list));

	if (list) {
		memset(list, 0, sizeof(*list));
		list->users = userlist;
		list->channame = strdup(channame);
		list->prev = NULL;
		list->next = NULL;
	}
	return (list);
}

/** Push back a new channel element to the main list container
* @param head the head pointer
* @param new the new channel element to be inserted
*/
void	*insert_back_channel(t_channel *head, t_channel *new)
{
	t_channel *tmp = head;

	if (!head) {
		head = new;
	} else {
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
	}
	return (head);
}

/** Remove a channel element from the doubly linked list
* @param list the userlist to be updated
* @param channame the channel name to be deleted
*/
void	remove_channel(t_channel *list, char *channame)
{
	t_channel *tmp = list;

	while (tmp->next != NULL)
	{
		if (!strcmp(tmp->channame, channame)) {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free_userlist(tmp->users);
			free(tmp->channame);
			free(tmp);
			break;
		}
		tmp = tmp->next;
	}
}

/** Self explanatory
* @param list the list to be de-allocated
*/
void	free_channel_list(t_channel *list)
{
	while (list) {
		free_userlist(list->users);
		t_channel *next = list->next;
		free(list);
		list = next;
	}
}

/** Self explanatory
* @return the default channel where all user resides
* @note the channel name, the default user and all could be parsed from
* a config file (#pullrequestIdea)
*/
t_channel	*init_default_channel()
{
	char *defuser[5] = {"NICK", "4Dm1n", "42", "*", ":John Doe"};
	t_channel *defchan = malloc(sizeof(*defchan));
	t_user *admin = get_new_user(0, defuser);
	t_userlist *allusers = get_new_userlist(admin);

	if (defchan && admin && allusers) {
		defchan->channame = "#welcome";
		defchan->users = allusers;
		defchan->prev = NULL;
		defchan->next = NULL;
	}
	return (defchan);
}
