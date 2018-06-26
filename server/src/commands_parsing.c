/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Zappy server commands parsing functions source file
*/

#include "../include/server.h"
#include <stdlib.h>

/** Split the received buffer by the '\\r\\n' symbol to get multiple
* commands in one buffer (or only one it's all depends on the client)
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
static char 	**get_args(char *cmd, const char *sep)
{
	int i = 0;
	char *token = NULL;
	char **tkns = malloc(MAXARGS * sizeof(*tkns));

	if (tkns) {
		memset(tkns, 0, sizeof(*tkns) * MAXARGS);
		token = strtok(cmd, sep);
		while (token) {
			tkns[i] = strdup(token);
			token = strtok(NULL, sep);
			i = i <= MAXARGS ? i + 1 : i;
		}
	}
	return (tkns);
}

/** Run command for AI client type
* @param args the 2D char array containing the request splitted by spaces
*/
void	run_ia_cmd(char *cmd, int clifd, t_world *map)
{
	char **args = NULL;
	uint index = 0;

	for (index = 0; G_PROTOS[index]; ++index) {
		if ((strstr(cmd, G_PROTOS[index]))) {
			args = get_args(cmd, " :");
			G_CMDS[index](args, clifd, map);
			free_buffers(args);
			break;
		}
	}
}

/** Run command for Graphical client type
* @param cmd to check for
* @param clifd the client file descriptor to read on
* @param map the t_world trantor map
* @param index the
*/
void	run_graph_cmd(char *cmd, int clifd, t_world *map)
{
	char **args = NULL;
	int index = 0;

	for (index = 0; G_GRAPH_PROTO[index]; ++index) {
		if ((strstr(cmd, G_GRAPH_PROTO[index]))) {
			args = get_args(cmd, " /&=");
			G_GRAPH_CMDS[index](args, clifd, map);
			free_buffers(args);
			break;
		}
	}
}

/** Match all methods in G_CMDS for a given req command string
* @param req the readed commands buffer
* @param clifd the client socket fd
* @note could add compilation macro for debug print_2darray() calls
* but epitech norm insist on 20 line per function so ...
*/
int	get_methods(char *req, int clifd, t_world *map)
{
	int index = 0;
	char **cmds = get_commands(req);

	for (int j = 0; cmds[j]; ++j) {
		run_ia_cmd(cmds[j], clifd, map);
		run_graph_cmd(cmds[j], clifd, map);
	}
	free_buffers(cmds);
	return ((index == REF_NB) ? (0) : (index));
}
