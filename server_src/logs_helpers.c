/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server logger function source
*/

#include "../include/server.h"
#include <unistd.h>
#include <stdlib.h>

/** Dummy print 2d Array for debug purpose
* @param args the args array to print
*/
void print_2darray(char **array)
{
	for (int i = 0; array[i]; i++) {
		printf("Print 2d says : arg[%d] : [%s]\n", i, array[i]);
	}
}

/** Construct the host:service string from struct infos
* @note this is to avoid sprintf usage
*/
static char *get_host_string(const char *host, const char *service)
{
	char *usr = malloc((NI_MAXHOST + 1 + NI_MAXSERV) * sizeof(*usr));

	memset(usr, 0, NI_MAXHOST + 1 + NI_MAXSERV);
	strncpy(usr, host, NI_MAXHOST);
	strcat(usr, ":");
	strncat(usr, service, NI_MAXSERV);
	return (usr);
}

/** Switch type and print data in t_serv according to a fmt string
* @param etype the kind of event type in [C]onnect, [D]isconnect or default
* @param all the 'catch them all' structure with server infos
* @return 1
*/
int	logthisevent(const char etype, t_serv *all)
{
	char *usr = get_host_string(all->host, all->service);
	char *c_fmt = " => IN: [%zd bytes] FROM: [%s] DATA: [%s]\n";
	char *d_fmt = "USER: [%s] disconnect\n";
	char *def_fmt = "Type:%c Size:%zd DATA: [%s]\n";

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
	free(usr);
	return (1);
}

/** Check if log path is writtable and open logs *FILE pointers.
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
