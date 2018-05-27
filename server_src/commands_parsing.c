/*
** EPITECH PROJECT, 2018
** MY_IRC
** File description:
** my_irc server source file
*/

#include "../include/server.h"
#include <stdlib.h>

/** Free the token list */
static void free_buffers(char **buffer)
{
	int i;

	for (i = 0; buffer[i]; ++i) {
		free(buffer[i]);
	}
	free(buffer);
}

/** Split the received buffer by the \\r\\n symbol to get multiple
* commands in one buffer (or only one it's all depends)
* @param req the read() buffer from clifd
*/
static char	**get_commands(char *req)
{
	int i = 0;
	char *cmd = NULL;
	char **cmds = malloc(MAXARGS * sizeof(*cmds));

	if (cmds) {
		memset(cmds, 0, sizeof(*cmds) * MAXARGS);
		cmd = strtok(req, "\r\n");
		while (cmd) {
			cmds[i] = strdup(cmd);
			cmd = strtok(NULL, "\r\n");
			i = i <= MAXARGS ? i + 1 : i;
		}
	}
	return (cmds);
}

/** Tokenize the command buffer by splitting by spaces
* @param cmd a command string received after get_commands() tokenization
*/
static char 	**get_args(char *cmd)
{
	int i = 0;
	char *token = NULL;
	char **tkns = malloc(MAXARGS * sizeof(*tkns));

	if (tkns) {
		memset(tkns, 0, sizeof(*tkns) * MAXARGS);
		token = strtok(cmd, " ");
		while (token) {
			tkns[i] = strdup(token);
			token = strtok(NULL, " ");
			i = i <= MAXARGS ? i + 1 : i;
		}
	}
	return (tkns);
}

/** Match all methods in G_CMDS for a given req command string
* @param req the requested command on format 'CMD <space> [ARGS]'
* @param clifd the client socket fd
*/
int	get_methods(char *req, int clifd)
{
	int j = 0;
	int index = 0;
	char **cmds = get_commands(req);
	char **args = NULL;

	print_2darray(cmds, "Commands");
	while (cmds[j]) {
		for (index = 0; G_PROTOS[index]; ++index) {
			if ((strcasestr(cmds[j], G_PROTOS[index]))) {
				args = get_args(cmds[j]);
				print_2darray(args, "Args");
				index = G_CMDS[index](args, clifd);
				free_buffers(args);
				break;
			}
		}
		++j;
	}
	free_buffers(cmds);
	return ((index == REF_NB) ? (0) : (index));
}
