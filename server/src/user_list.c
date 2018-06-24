/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server users list methods
*/

#include "../include/server.h"
#include <stdlib.h>

/** Malloc and memset a new t_user element
* @param clifd the user client file descriptor
* @param usercmd the USER <space> args 2d array
* @return list the new element
*/
t_user	*get_new_user(int clifd, cmdargs usercmd)
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

/** Malloc and memset a new userlist element
* @param usr the t_user on the userlist
* @return list the new element
*/
t_userlist	*get_new_userlist(t_user *usr)
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

/** Push back a n(ew)user in the userlist head
* @param head the userlist to be modified
* @param nuser the n(ew)user to be inserted
* @return head the head pointer
*/
void	*insert_back_user(t_userlist *head, t_userlist *nuser)
{
	t_userlist *tmp = head;

	if (!head) {
		head = nuser;
	} else {
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = nuser;
		nuser->prev = tmp;
	}
	return (head);
}

/** Remove a user from a userlist
* @param list the userlist to be updated
* @param clifd the clientfd as index for element to be removed
* @return list the updated userlist
*/
void	*remove_user(t_userlist *list, int clifd)
{
	t_userlist *tmp = list;

	while (tmp) {
		if (tmp->user->clifd == clifd) {
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			else
				tmp->next = NULL;
			free(tmp->user->rname);
			free(tmp->user->nick);
			free(tmp->user);
			free(tmp);
			break;
		}
		tmp = tmp->next;
	}
	return (list);
}

/** Self explanatory
* @param list the list to be freed
*/
void	free_userlist(t_userlist *list)
{
	while (list) {
		free(list->user->rname);
		free(list->user->nick);
		free(list->user);
		t_userlist *next = list->next;
		free(list);
		list = next;
	}
}
