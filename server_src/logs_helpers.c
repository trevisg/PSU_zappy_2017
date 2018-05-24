/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server logger function source
*/

#include "../include/server.h"
#include <unistd.h>

/**
* @function
* @brief ### Switch type and print data in t_serv according to a fmt string
* @param etype the kind of event type in [C]onnect, [D]isconnect or default
* @param all the 'catch them all' structure with server infos
* @return 1
*/
int	logthisevent(const char etype, t_serv *all)
{
	char usr[BUF_SIZE];
	char *c_fmt = " => IN: [%zd bytes] FROM: [%s] DATA: [%s]\n";
	char *d_fmt = "USER: [%s] disconnect\n";
	char *def_fmt = "Type:%c Size:%zd DATA: [%s]\n";

	memset(usr, 0, BUF_SIZE);
	RM_NL(all->buf);
	sprintf(usr, "%s:%s", all->host, all->service);
	switch (etype) {
		case 'c':
		fprintf(stdout, c_fmt, all->nread, usr, all->buf);
		break;
		case 'd':
		fprintf(stdout, d_fmt, usr);
		break;
		default:
		fprintf(stdout, def_fmt, etype, all->nread, all->buf);
	}
	return (1);
}

/**
* @function
* @brief ### Check if log path is writtable and open logs *FILE pointers.
* @param paths a 2D array of char containing the conf file paths
* @param ptr the returned setupded struct
* @return 0 if ok with access and all other syscalls
* @return 84 if error
* @NOTE The default file mode is a=rwx (0777) with selected permissions
* removed in accordance with the file mode creation mask.
*/
int	initlogs(const char **paths, t_log *ptr)
{
	int rt = 0;
	int flgs = R_OK | W_OK;

	if (!access(paths[ACCESS], flgs) && !access(paths[ERRORS], flgs)) {
		ptr->mode = 0777 & ~umask(0);
		ptr->dir_mode = ptr->mode | S_IWUSR | S_IXUSR;
		ptr->timeval = time(NULL);
		ptr->timestmp = ctime(&ptr->timeval);
		ptr->accesslog = fopen(paths[ACCESS], "rw");
		ptr->errlog = fopen(paths[ERRORS], "rw");
	} else {
		perror("access");
		rt = 84;
	}
	return (rt);
}
