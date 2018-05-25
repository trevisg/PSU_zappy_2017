/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server users list methods
*/

#include "../include/server.h"
#include <stdlib.h>

t_user *get_new_user(int clifd, cmdargs usercmd)
{
	t_user *usr = malloc(sizeof(*usr));

	if (usr) {
		memset(usr, 0, sizeof(*usr));
		usr->clifd = clifd;
		usr->mode = atoi(usercmd[2]);
		usr->nick = strdup(usercmd[1]);
		usr->rname = strdup(usercmd[4]);
	}
	return (usr);
}

t_userlist *get_new_userlist(t_user *usr)
{
	t_userlist *list = malloc(sizeof(*list));

	if (list) {
		memset(list, 0, sizeof(*list));
		list->user = usr;
		list->prev = NULL;
		list->next = NULL;
	}
	return (list);
}

void *push_back(t_userlist *head, t_userlist *new)
{
	t_userlist *tmp = head;

	if (!head) {
		head = new;
	} else {
		while (tmp->next) tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (head);
}

void	print_users(t_userlist *liste)
{
	printf("\t\tUSERS LIST :\n");
	for (t_userlist *tmp = liste; tmp; tmp = tmp->next) {
		printf("User : [%s], Real Name : [%s]\n",
		tmp->user->nick, tmp->user->rname);
	}
}
