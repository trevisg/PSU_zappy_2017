/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy client c socket handler methods
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/** Simple TCP socket non blocking client
* @param srvhost the server address (127.0.0.1 if localhost)
* @param port the server listening port
* @return client_sockfd the setup client socket / file descriptor to write()
* and read() on
* @return exit() if something failed
*/
int	connect_to_server(const char *srvhost, int port)
{
	int rt = 0;
	int client_sockfd = 0;
	struct sockaddr_in client;
	const struct sockaddr *addr;

	addr = (const struct sockaddr *)&client;
	if ((client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket: ");
		exit(EXIT_FAILURE);
	}
	client.sin_addr.s_addr = inet_addr(srvhost);
	client.sin_family = AF_INET;
	client.sin_port = htons(port);
	if ((rt = connect(client_sockfd, addr, sizeof(client))) == -1) {
		perror("Connect: ");
		exit(EXIT_FAILURE);
	}
	fcntl(client_sockfd, F_SETFL, O_NONBLOCK);
	return (client_sockfd);
}

#ifdef SOCKTEST
#define EVER ;;

int main(int ac, char **av)
{
	char c;
	int port = 0;
	int clifd = 0;
	const char *host;

	if (ac == 3) {
		port = atoi(av[2]);
		host = av[1];
		clifd = connect_to_server(host, port);
		for (EVER) {
			dprintf(clifd, "HELLO WORLD\n");
			read(0, &c, 1);
			if (c == 'q') {
				break;
			}
		}
	} else {
		fprintf(stderr, "USAGE : %s host port\n", av[0]);
	}
	return (0);
}
#endif
