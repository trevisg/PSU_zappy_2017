/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server source file
*/

#include "../include/server.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <regex.h>

/** Set the new accept() client socket in epoll event list
* for new client handling and write 220 + [server header] on client socket
* if connection succeed
* @param all the 'foure tout' server struct
* @param args the argv from main to update child process name
*/
static int	initco(t_serv *all, char **args, int *connected)
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
		fprintf(stdout, "\n%s: %s\n", args[0], okco);
		*(connected) += 1;
	}
	return (rt);
}

/**  Main get commands / parse and exec runner function
* @param all the infamous structure
* @param newfd the client socket fd
*/
static int 	evhandler(t_serv *all, int newfd)
{
	struct sockaddr_in addr;
	socklen_t addr_size = sizeof(struct sockaddr_in);
	int res = getpeername(newfd, (struct sockaddr *)&addr, &addr_size);

	if (res == -1) {
		perror("getpeername ! :");
	} else {
		sprintf(all->host, "%s", inet_ntoa(addr.sin_addr));
		sprintf(all->service, "%d", ntohs(addr.sin_port));
		if (all->nread && logthisevent('c', all)) {
			get_methods(all->buf, newfd);
		} else {
			logthisevent('d', all);
		}
	}
	return (0);
}

/** Get the active fd from event queue, if it's our server fd, initco()
* with the new connected client, else handle received cmd buffer
* through evhandler()
* @param all the 'catch them all' structure with server infos
* @param args the argv pointer form main containing initial process names
* @return 0 fo normal exit
* @exit(0) if a client / child process disconnect
*/
static int	getactiveclients(t_serv *all, char **args)
{
	int clifd = -1;
	static int connected;

	for (int n = 0; n < all->nfds; ++n) {
		clifd = all->events[n].data.fd;
		if (clifd == all->listen_sock) {
			initco(all, args, &connected);
		} else {
			memset(all->buf, 0, BUF_SIZE);
			all->nread = read(clifd, all->buf, BUF_SIZE);
			evhandler(all, clifd);
			memset(all->buf, 0, BUF_SIZE);
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
		for (EVER) {
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
		signal(SIGINT, sig_handler);
		rt = server(av);
	} else {
		fprintf(stderr, "%s: [port]\n", av[0]);
		rt = 84;
	}
	return (rt);
}
