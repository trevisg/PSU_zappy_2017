/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server channel list methods
*/

#include "../include/server.h"
#include <stdlib.h>

t_channel	*get_new_channel_list(t_userlist *userlist)
{
	t_channel *list = malloc(sizeof(*list));

	if (list) {
		memset(list, 0, sizeof(*list));
		list->users = userlist;
		list->prev = NULL;
		list->next = NULL;
	}
	return (list);
}

void	*insert_back(t_channel *head, t_channel *new)
{
	t_channel *tmp = head;

	if (!head) {
		head = new;
	} else {
		while (tmp->next) tmp = tmp->next;
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
			free(tmp);
			break;
		}
		tmp = tmp->next;
	}
}

void 	free_channel_list(t_channel *list)
{
	while (list) {
		free_userlist(list->users);
		t_channel *next = list->next;
		free(list);
		list = next;
	}
}
