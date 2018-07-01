/*
** EPITECH PROJECT, 2018
** PSU_ZAPPY_2017 - Server
** File description:
** Zappy server source file
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include "server.h"

/** Set the new accept() client socket in epoll event list
* for new client handling if connection succeed
* @param all the 'foure tout' server struct
* @param args the argv from main to update child process name
* @note respond WELCOME
*/
static int	init_connection(t_serv *all, int *connected)
{
	int rt = 84;
	struct sockaddr_in addr;
	socklen_t addr_size = sizeof(struct sockaddr_in);
	struct sockaddr *cliaddr = (struct sockaddr *)&addr;
	char *okco = "Someone connect to me!\n";

	all->conn_sock = accept(all->listen_sock, cliaddr, &addr_size);
	if (all->conn_sock == -1) {
		perror("initco: accept");
	} else if (!(rt = set_clifd(all->conn_sock, all->epollfd, &all->ev))) {
		fprintf(stdout, "\n./zappy_server: %s\n", okco);
		*(connected) += 1;
	}
	return (rt);
}

/**  Main get commands / parse and exec runner function
* @param all the infamous structure
* @param newfd the client socket fd
*/
static int 	events_handler(t_serv *all, int newfd)
{
	struct sockaddr_in addr;
	socklen_t addr_size = sizeof(struct sockaddr_in);
	int res = getpeername(newfd, (struct sockaddr *)&addr, &addr_size);

	if (res == -1) {
		perror("evhandler: getpeername");
	} else {
		sprintf(all->host, "%s", inet_ntoa(addr.sin_addr));
		sprintf(all->service, "%d", ntohs(addr.sin_port));
		if (all->nread && logthisevent('c', all)) {
			get_methods(all->buf, newfd, all->refmap);
		} else {
			logthisevent('d', all);
		}
	}
	return (0);
}

/** Get the active fd from event queue, if it's our server fd, initco() with
* the new connected client, else handle received cmd buffer through evhandler()
* @param all the 'catch them all' structure with server infos
* @param args the argv pointer form main containing initial process names
* @return 0 fo normal exit
* @return exit() if a client / child process disconnect
* @todo must implement circular buffer instead of 2d char array
* see [this ref](https://bit.ly/2s86kKz) for explanations and code snippets
* (note of note : will do it (maybe) later)
*/
static int	getactiveclients(t_serv *all)
{
	int clifd = -1;
	static int connected;

	for (int n = 0; n < all->nfds; ++n) {
		clifd = all->events[n].data.fd;
		if (clifd == all->listen_sock) {
			init_connection(all, &connected);
		} else {
			memset(all->buf, 0, BUF_SIZE);
			all->nread = read(clifd, all->buf, BUF_SIZE);
			events_handler(all, clifd);
		}
	}
	return (0);
}

/** Contain the main server infinite loop
* @param options the server and game settings received from main()
* @todo read the various notes on documentation and do what requested
*/
int	server(t_clargs *options)
{
	int rt = 0;
	t_serv all;
	all.refmap = get_world(options);
	print_world(all.refmap);
	print_teams(all.refmap->teams);

	set_iface(&all.hints, &all.res, options->port);
	all.listen_sock = set_sockfd(&all);
	if (all.listen_sock < 0 || set_epoll(&all) == -1) {
		rt = 84;
	} else {
		for (EVER) {
			all.nfds = epoll_wait(all.epollfd, all.events,
				MAX_EVENTS, -1);
			if (all.nfds == -1) {
				perror("server: epoll_wait");
				break;
			}
			rt = getactiveclients(&all);
		}
		close(all.listen_sock);
		free_world(all.refmap, options);
	}
	return (rt);
}
