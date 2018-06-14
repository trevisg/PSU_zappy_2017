/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server teams list methods
*/

#include "../include/server.h"
#include <stdlib.h>

/** Self explanatory
* @param userlist the userlist to insert in the new teams element
* @param channame the new teams name
*/
t_teams	*get_new_chan_list(t_userlist *userlist, char *channame)
{
	t_teams *list = malloc(sizeof(*list));

	if (list) {
		memset(list, 0, sizeof(*list));
		list->users = userlist;
		list->channame = strdup(channame);
		list->prev = NULL;
		list->next = NULL;
	}
	return (list);
}

/** Push back a new teams element to the main list container
* @param head the head pointer
* @param new the new teams element to be inserted
*/
void	*insert_back_teams(t_teams *head, t_teams *new)
{
	t_teams *tmp = head;

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

/** Remove a teams element from the doubly linked list
* @param list the userlist to be updated
* @param channame the teams name to be deleted
*/
void	remove_teams(t_teams *list, char *channame)
{
	t_teams *tmp = list;

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
void	free_teams_list(t_teams *list)
{
	while (list) {
		free_userlist(list->users);
		t_teams *next = list->next;
		free(list);
		list = next;
	}
}

/** Self explanatory
* @return the default teams where all user resides
* @note the teams name, the default user and all could be parsed from
* a config file (#pullrequestIdea)
*/
t_teams	*init_default_teams(void)
{
	char *defuser[5] = {"NICK", "4Dm1n", "42", "*", ":John Doe"};
	t_teams *defchan = malloc(sizeof(*defchan));
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
