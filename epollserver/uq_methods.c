/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server methods from u- user to q- quit functions sources
*/

#include <unistd.h>
#include "server.h"

int	user(const char *username, int clifd)
{
	int rt = 0;
	char *askpass = "User name okay, need password.";
	char *errmsg = "Permission denied.";

	if (!username || strlen(username) <= 1) {
		fprintf(stderr, "%s\n", "Invalid USER");
		dprintf(clifd, RESP_FMT, 530, errmsg);
		rt = 1;
	} else {
		fprintf(stdout, "OK [%s] [%s]\n", G_PROTOS[USER], username);
		dprintf(clifd, RESP_FMT, 331, askpass);
	}
	return (rt);
}

int	pass(const char *pass, int clifd)
{
	int rt = 0;
	char *err = "Invalid PASS\n";
	char *oklog = "Login successful";

	if (!pass) {
		fprintf(stderr, "%s\n", err);
		dprintf(clifd, RESP_FMT, 430, err);
		rt = 1;
	} else {
		fprintf(stdout, "OK [%s] [%s]\n", G_PROTOS[PASS], pass);
		dprintf(clifd, RESP_FMT, 230, oklog);
	}
	return (rt);
}

int	cwd(const char *none, int clifd)
{
	int rt = 0;
	char cwd[255];
	char *err = "Trouble to get dir infos";

	memset(cwd, 0, 255);
	if ((!none || none) && (getcwd(cwd, 255) != NULL)) {
		fprintf(stdout, "OK [%s] [%s]\n", G_PROTOS[CWD], cwd);
		dprintf(clifd, RESP_FMT, 250, cwd);
	} else {
		perror("cwd: getcwd");
		dprintf(clifd, RESP_FMT, 336, err);
		rt = 1;
	}
	return (rt);
}
