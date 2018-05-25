/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server users list methods
*/

#include "../include/server.h"

t_user *get_new_user(int clifd, int mode, char *nick, char *rname)
{
	t_user usr = malloc(sizeof(*usr));

	if (usr) {
		usr->clifd = clifd;
		usr->mode = mode;
		usr->nick = nick;
		usr->rname = rname;
	}
}
