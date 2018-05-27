/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc signal handler source file
*/

#include "../include/server.h"
#include <sys/wait.h>
#include <stdlib.h>

/** Dummy signal hander to exit server properly on console with CTRL-C
* @param signo the catched signal type (hit ```man 2 signal```)
*/
void sig_handler(int signo)
{
	if (signo == SIGINT) {
		printf("\nReceived SIGINT\n\tSee u !..\n");
		exit(0);
	}
}
