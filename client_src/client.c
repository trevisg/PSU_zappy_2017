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

int main(int ac, char **av)
{
        int sockfd, numbytes;
        char buf[1024];
        struct hostent *he;
        struct sockaddr_in their_addr;

        if (ac != 3) {
                fprintf(stderr,"Usage: %s [host] [port]\n", av[0]);
                exit(84);
        }

        if ((he=gethostbyname(av[1])) == NULL) {  /* get the host info */
                herror("gethostbyname");
                exit(84);
        }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(84);
        }

        int server_port = atoi(av[2]);
        their_addr.sin_family = AF_INET;
        their_addr.sin_port = htons(atoi(av[2]));
        their_addr.sin_addr = *((struct in_addr *)he->h_addr);
        bzero(&(their_addr.sin_zero), 8);
        if (server_port == -1 || connect(sockfd,
                (struct sockaddr *)&their_addr,sizeof(struct sockaddr)) == -1) {
                perror("connect");
                exit(1);
        }
        while (1) {
                if (send(sockfd, "Hello, world!\n", 14, 0) == -1){
                        perror("send");
                        exit (84);
                }
                printf("After the send function \n");
                if ((numbytes=recv(sockfd, buf, 1024, 0)) == -1) {
                        perror("recv");
                }
                buf[numbytes] = '\0';
                printf("Received in pid=%d, text=: %s \n",getpid(), buf);
                sleep(1);
        }
        close(sockfd);
        return 0;
}
