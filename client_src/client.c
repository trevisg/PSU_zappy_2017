/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc client main source file
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

void *set_iface(struct sockaddr_in *addr, int server_port,
	struct hostent *he, int sockfd)
{
	addr->sin_family = AF_UNSPEC;
	addr->sin_port = htons(server_port);
	addr->sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(addr->sin_zero), 8);
	if (server_port == -1 || connect(sockfd,
		(struct sockaddr *)&addr, sizeof(struct sockaddr)) == -1) {
		perror("connect");
		exit(1);
	} else {
		return addr;
	}

}

int cli_loop(int sockfd)
{
	int numbytes = 0;
	char buf[1024];

	while (1) {
		if (send(sockfd, "Hello, world!\n", 14, 0) == -1){
			perror("send");
			exit (84);
		}
		printf("After the send function \n");
		numbytes = recv(sockfd, buf, 1024, 0);
		if (numbytes == -1) {
			perror("recv");
		}
		buf[numbytes] = '\0';
		printf("Received in pid = %d, text = : %s \n", getpid(), buf);
		sleep(1);
	}
}

int main(int ac, char **av)
{
	int sockfd;
	int server_port;
	struct hostent *he;
	struct sockaddr_in their_addr;

	if (ac != 3) {
		fprintf(stderr, "Usage: %s [host] [port]\n", av[0]);
		exit(84);
	}
	he = gethostbyname(av[1]);
	if (he == NULL) {
		exit(84);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket");
		exit(84);
	}
	server_port = atoi(av[2]);
	set_iface(&their_addr, server_port, he, sockfd);
	cli_loop(sockfd);
	close(sockfd);
	return 0;
}
