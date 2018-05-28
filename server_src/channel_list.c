/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server channel list methods
*/

#include "../include/server.h"
#include <stdlib.h>

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

void	free_channel_list(t_channel *list)
{
	while (list) {
		free_userlist(list->users);
		t_channel *next = list->next;
		free(list);
		list = next;
	}
}

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
