/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server source file
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/prctl.h>

/** Match all methods in G_CMDS for a given req command string
* @param req the requested command on format 'CMD <space> [ARGS]'
* @param clifd the client socket fd
*/
static int	get_methods(char *req, int clifd)
{
	int index = 0;
	char *arg = NULL;

	RM_NL(req);
	arg = strdup(req);
	for (index = 0; G_PROTOS[index] != NULL; ++index) {
		if ((strstr(req, G_PROTOS[index]))) {
			arg = strtok(arg, " ");
			arg = strtok(NULL, " ");
			if (G_CMDS[index] != NULL) {
				index = G_CMDS[index](arg, clifd);
			}
			break;
		}
	}
	memset(req, 0, BUF_SIZE);
	return ((index == REF_NB) ? (0) : (index));
}

/** Set the new accept() client socket in epoll event list
* for new client handling and write 220 + [server header] on client socket
* if connection succeed
* @param all the 'foure tout' server struct
* @param args the argv from main to update child process name
*/
static int	initco(t_serv *all, char **args, int *connected)
{
	int rt = 84;
	struct sockaddr *cliaddr = (struct sockaddr *) &all->addr;
	char *okco = "Someone connect to me!\n";

	all->conn_sock = accept(all->listen_sock, cliaddr, &all->addrlen);
	if (all->conn_sock == -1) {
		perror("initco: accept");
	} else if (!(rt = set_clifd(all->conn_sock, all->epollfd, &all->ev))) {
		fprintf(stdout, "%s: %s", args[0], okco);
		dprintf(all->conn_sock, "%d %s\n", 220, BFTPD);
		*(connected) += 1;
	}
	return (rt);
}

/** Select a cli from queue and get a new process if new client with initco()
* @param all the 'catch them all' structure with server infos
* @param args the argv pointer form main containing initial process names
* @return 0 fo normal exit
* @exit(0) if a client / child process disconnect
*/
static int	getactiveclients(t_serv *all, char **args)
{
	int clifd = -1;
	static int connected;
	struct sockaddr *ptr = (struct sockaddr *)&all->addr;

	for (int n = 0; n < all->nfds; ++n) {
		clifd = all->events[n].data.fd;
		if (clifd == all->listen_sock) {
			initco(all, args, &connected);
		} else {
			all->nread = read(clifd, all->buf, BUF_SIZE);
			if (!getnameinfo(ptr, all->addrlen, all->host,
				NI_MAXHOST, all->service, NI_MAXSERV,
				NI_NUMERICSERV)) {
				RM_NL(all->buf);
				if (all->nread && logthisevent('c', all)) {
					return (get_methods(all->buf, clifd));
				} else {
					logthisevent('d', all);
					connected -= 1;
				}
			} else {
				perror("findclients: getnameinfo");
			}
		}
	}
	return (0);
}

/** Contain the main 'listening for event' loop
* @TODO remove dirty struct
*/
int	server(char **args)
{
	int rt = 0;
	t_serv all;

	set_iface(&all.hints, &all.res, args[1]);
	if ((all.listen_sock = set_sockfd(&all)) < 0 || set_epoll(&all) == -1) {
		rt = 84;
	} else {
		for (;;) {
			all.nfds = epoll_wait(all.epollfd, all.events,
				MAX_EVENTS, -1);
				if (all.nfds == -1) {
					perror("server: epoll_wait");
					break;
				}
				rt = getactiveclients(&all, args);
			}
			close(all.listen_sock);
		}
		return (rt);
	}

	int	main(int ac, char **av)
	{
		int rt = 0;

		if (ac == 2) {
			prctl(PR_SET_PDEATHSIG, SIGHUP);
			rt = server(av);
		} else {
			fprintf(stderr, "%s: [port]\n", av[0]);
			rt = 84;
		}
		return (rt);
	}
