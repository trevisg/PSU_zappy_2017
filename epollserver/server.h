/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server header file
*/

#ifndef SERVER_H_
#define	SERVER_H_

#include <stdio.h>
#include <time.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/stat.h>

#define BACKLOG 5
#define REF_NB 15
#define BUF_SIZE 1057
#define MAX_EVENTS 10
#define BFTPD "(BrokenFtPd 0.0.42) - Service ready for new user."
#define RESP_FMT "%d %s\r\n"
#define RM_NL(a) a[strcspn(a, "\n")] = 0;

/** See @file miserver/methods_uq.c */
int user(const char *username, int clifd);
int pass(const char *pass, int clifd);
int cwd(const char *none, int clifd);

/** See @file miserver/decls.c */
/** Main EPITECH MyFTP Protocol (RFC959 Extract)
* methods function pointer
*/
typedef int (*cmds)(const char *, int);
/** The object mapping the methods name */
extern const char *G_PROTOS[REF_NB];
/** The global pointer */
extern const cmds G_CMDS[REF_NB];
/** Only here for code clarity and lisibility */
enum  CMDS {
	USER, PASS, CWD, CDUP, QUIT,
	DELE, PWD, PASV, PORT, HELP,
	NOOP, RETR, STOR, LIST
};

/* Future login handler filepath (to be set in a .conf file) */
enum  LPATHS {
	ACCESS,
	ERRORS,
	NOTICES
};

/** The logger mehtods structure with files pointer and timestmp vraiables */
typedef struct			s_log {
	FILE		*errlog;
	FILE		*accesslog;
	char		*timestmp;
	time_t		timeval;
	mode_t		*set;
	mode_t 		mode;
	mode_t		dir_mode;
}				t_log;

/** @NOTE : When doing network code, 80 chars column length
* is a pain in di a** to respect. So here is this dirty typedef ;)
*/
typedef struct addrinfo adrinf;

/** Yeah I know , sounds like we got a trashbin struct here ;)
* will improve promise!
*/
typedef struct				s_serv {
	int			nfds;
	int			epollfd;
	int			conn_sock;
	int			listen_sock;
	ssize_t 		nread;
	socklen_t 		addrlen;
	char 			buf[BUF_SIZE];
	char 			host[NI_MAXHOST];
	char 			service[NI_MAXSERV];
	adrinf			*rp;
	adrinf			*res;
	adrinf			hints;
	struct epoll_event 	ev;
	struct epoll_event 	events[MAX_EVENTS];
	struct sockaddr_storage addr;
}					t_serv;

/** See miserver/inits.c */
int	set_sockfd(t_serv *all);
int	set_epoll(t_serv *all);
int	set_iface(adrinf *hints, adrinf **res, const char *port);
int	set_clifd(int clisock, int epollfd, struct epoll_event *ev);

/** See miserver/loghelpers.c */
int	logthisevent(const char etype, t_serv *all);
int	initlogs(const char **paths, t_log *ptr);

#endif /* !SERVER_H_ */
