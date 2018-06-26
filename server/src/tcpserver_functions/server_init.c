/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Server listening socket and interface init
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../../include/server.h"

/** Add the new client file descriptor in struct epoll_event structure
* for polling their events
* @todo read [this](https://bit.ly/2gOr7gr) medium blog post on 'epoll madness'
*/
int	set_clifd(int clisock, int epollfd, struct epoll_event *ev)
{
	int rt = 0;
	int op = EPOLL_CTL_ADD;

	ev->events = EPOLLIN | EPOLLET;
	ev->data.fd = clisock;
	if (epoll_ctl(epollfd, op, clisock, ev) == -1) {
		perror("set_clifd: epoll_ctl:");
		rt = 84;
	}
	fprintf(stderr, "Add client n°[%d] to epoll interest list\n", clisock);
	return (rt);
}

/** Listening interface setup */
int	set_iface(adrinf *hints, adrinf **res, const char *port)
{
	int rt = 0;

	memset(hints, 0, sizeof(struct addrinfo));
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = SOCK_STREAM;
	hints->ai_flags = AI_PASSIVE;
	hints->ai_protocol = IPPROTO_TCP;
	hints->ai_canonname = NULL;
	hints->ai_addr = NULL;
	hints->ai_next = NULL;
	if ((getaddrinfo(NULL, port, hints, res))) {
		perror("set_iface: getaddrinfo");
		rt = 84;
	}
	return (rt);
}


/** Epoll IO handler initialisation
* - declare an epoll fd with epoll_create()
* - set event handling to EPOLLIN (check ```man epoll```)
* - register server listening fd on ev structure
* @param all the foure tout structure
*/
int	set_epoll(t_serv *all)
{
	int rt = 0;

	all->epollfd = epoll_create(10);
	memset(&all->ev, 0, sizeof(all->ev));
	if (all->epollfd == -1) {
		perror("set_epoll: epoll_create1");
		rt = 84;
	} else {
		all->ev.events = EPOLLIN;
		all->ev.data.fd = all->listen_sock;
		rt = epoll_ctl(all->epollfd, EPOLL_CTL_ADD, all->listen_sock,
			&all->ev);
		if (rt == -1) {
			perror("set_epoll: epoll_ctl");
			rt = 84;
		}
	}
	return (rt);
}

/** Prevents those dreaded "Address already in use" errors */
static void 	prevent_reused(int sockfd)
{
	int yes = 1;

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&yes,
		sizeof(int)) == -1) {
		perror("prevent_reused: setsockopt");
		exit(84);
	}
}

/** Tcp Listening socket setup
* - declare a socket with socket()
* - bind() to an interface
* - listen() on this fd / socket
* @param all the 'foure tout' structure containing the struct to setup
* @return sfd the configured listening socket fd or -1 if failure
*/
int	set_sockfd(t_serv *all)
{
	int sfd = -1;

	for (all->rp = all->res; all->rp != NULL; all->rp = all->rp->ai_next) {
		sfd = socket(all->rp->ai_family, all->rp->ai_socktype,
			all->rp->ai_protocol);
		prevent_reused(sfd);
		if (sfd == -1) {
			continue;
		}
		if (bind(sfd, all->rp->ai_addr, all->rp->ai_addrlen) == 0) {
			break;
		}
		close(sfd);
	}
	if (all->rp == NULL) {
		fprintf(stderr, "Could not bind\n");
	} else if ((listen(sfd, BACKLOG) == -1)) {
		perror("listen: set_sockfd");
	}
	return (sfd);
}
