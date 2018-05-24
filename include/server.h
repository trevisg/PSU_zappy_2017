/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server header file
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE

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

/** Number of simultaneous connection on server listening socket => listen() */
#define BACKLOG 5
/** Number of RFC command handled by this (broken) server */
#define REF_NB 15
/** This good old C mem alloc dirty method */
#define BUF_SIZE 1057
/** The length of the struct epoll_events array pointed to by *events */
#define MAX_EVENTS 10
/** This good old ... u know */
#define MAXCHAN 1000
/** Idem, see join() function */
#define MAXCHANNAME 200
/** For windows compactbility, added carriage return here */
#define RESP_FMT "%d %s\r\n"
/** Dummy hack to remove newline char from cmd buffer see ```man strcspn()```*/
#define RM_NL(a) a[strcspn(a, "\r")] = 0;

/** See @file server_src/rfc_cmds0.c */
int join(const char **channame, int clifd);
int nick(const char **nickname, int clifd);
int ping(const char **nope, int clifd);
int user(const char **usercmd, int clifd);

/** See @file server_src/server_decls.c */
/** Main EPITECH MyFTP Protocol (RFC959 Extract)
* methods function pointer
*/
typedef int (*cmds)(const char **, int);
/** The object prototype mapping the methods name */
extern const char *G_PROTOS[REF_NB];
/** The global pointer */
extern const cmds G_CMDS[REF_NB];
/** Only here for code clarity and lisibility
* @TODO : still missing lot of rfc command see subject, rfc or
* this [gist](https://gist.github.com/xero/2d6e4b061b4ecbeb9f99) for help
*/
enum  CMDS {
	JOIN, NICK, LIST, SERVER, PART,
	USERS, NAMES, ACCEPTF, MSGAB, MSGABC,
	QUERY, ME, NOTICE, WHOIS, WHOWAS,
	DNS, PING, KICK
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

/** Yeah simplification */
typedef struct addrinfo adrinf;

/** @TODO : please split this **mess** !!
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

typedef struct			s_client {
	int			clifd;
	char			*nick;
	char			*channel;
}				t_client;

/** See server_src/inits.c */
int	set_sockfd(t_serv *all);
int	set_epoll(t_serv *all);
int	set_iface(adrinf *hints, adrinf **res, const char *port);
int	set_clifd(int clisock, int epollfd, struct epoll_event *ev);

/** See miserver/loghelpers.c */
int	logthisevent(const char etype, t_serv *all);
int	initlogs(const char **paths, t_log *ptr);

#endif /* !SERVER_H_ */

#endif /* _GNU_SOURCE */
