/*
** EPITECH PROJECT, 2018
** MY_FTP
** File description:
** my_ftp server header file
*/

#ifndef _GNU_SOURCE
# define _GNU_SOURCE

#ifndef SERVER_H_
# define SERVER_H_

	#include <stdio.h>
	#include <time.h>
	#include <netdb.h>
	#include <string.h>
	#include <sys/socket.h>
	#include <sys/epoll.h>
	#include <sys/time.h>
	#include <sys/stat.h>

	/** Number of simultaneous connection on server listening socket
	* see listen() call
	*/
	#define BACKLOG 5
	/** Number of RFC command handled by this (broken) server */
	#define REF_NB 15
	/** This good old C mem alloc dirty method */
	#define BUF_SIZE 1060
	/** The length of the struct epoll_events array pointed to by *events
	*/
	#define MAX_EVENTS 10
	/** This good old ... u know */
	#define MAXCHAN 1000
	/** Idem, see join() function and RFC 1459 and RFC 2812 */
	#define MAXCHANNAME 50
	/** Maximum number of args in command as per rfc request
	* see section 2.3 of RFC 2812
	*/
	#define MAXARGS 15
	/** Maximum argument length see ref below
	* @note obtained by 500 / max args
	*/
	#define MAXARGSIZE 33
	/** Argument format typedef as per RFC request
	* @note Useless typedef came from a deprecated method, but hey too lazy
	* to rename all
	*/
	typedef char ** cmdargs;
	/** Yess useless so mandatory */
	#define EVER ;;

	/** See @file server_src/rfc_cmds0.c */
	int join(cmdargs channame, int clifd);
	int nick(cmdargs nickname, int clifd);
	int ping(cmdargs nope, int clifd);
	int user(cmdargs usercmd, int clifd);
	int quit(cmdargs quitmsg, int clifd);

	/** See @file server_src/server_decls.c */
	/** Main EPITECH MyIRC Protocol (RFC 1459 Extract)
	* methods function pointer
	*/
	typedef int (*cmds)(cmdargs, int);
	/** The object prototype mapping the methods name */
	extern const char *G_PROTOS[REF_NB];
	/** The global pointer */
	extern const cmds G_CMDS[REF_NB];
	/** Only here for code clarity and lisibility
	* @TODO : still missing lot of rfc command see subject, rfc or
	* this [gist](https://gist.github.com/xero/2d6e4b061b4ecbeb9f99)
	* for help
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

	/** The logger methods structure with files pointer
	* and timestamp variables */
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

	/** Main server structure */
	typedef struct			s_serv {
		int			nfds;
		int			epollfd;
		int			conn_sock;
		int			listen_sock;
		ssize_t 		nread;
		char 			buf[BUF_SIZE];
		char 			host[NI_MAXHOST];
		char 			service[NI_MAXSERV];
		adrinf			*rp;
		adrinf			*res;
		adrinf			hints;
		struct epoll_event 	ev;
		struct epoll_event 	events[MAX_EVENTS];
	}				t_serv;

	/** A typical IRC user */
	typedef struct			s_user {
		int			clifd;
		int			mode;
		char			*nick;
		char 			*rname;
	}				t_user;

	/** The doubly linked list of connected users */
	typedef struct			s_userlist {
		t_user 			*user;
		struct s_userlist	*prev;
		struct s_userlist	*next;
	}				t_userlist;

	/** A doubly linked list of current channels with their users */
	typedef struct 			s_channel {
		char 			*channame;
		t_userlist		*users;
		struct s_channel 	*prev;
		struct s_channel 	*next;
	}				t_channel;

	/** See server_src/inits.c */
	int	set_sockfd(t_serv *all);
	int	set_epoll(t_serv *all);
	int	set_iface(adrinf *hints, adrinf **res, const char *port);
	int	set_clifd(int clisock, int epollfd, struct epoll_event *ev);

	/** See server_src/commands_parsing.c */
	int	get_methods(char *req, int clifd);

	/** See server_src/logs_helpers.c */
	int	logthisevent(const char etype, t_serv *all);
	int	initlogs(const char **paths, t_log *ptr);
	void	print_2darray(char **array, char *ident);
	void	print_users(t_userlist *liste);

	/** See server_src/client_list.c */
	t_user		*get_new_user(int clifd, cmdargs usercmd);
	t_userlist	*get_new_userlist(t_user *usr);
	void		*push_back(t_userlist *head, t_userlist *users);
	void		print_users(t_userlist *liste);
	void		free_userlist(t_userlist *list);

	/** See server_src/signal_handler.c */
	void		sig_handler(int signo);

	#endif /* !SERVER_H_ */

#endif /* !_GNU_SOURCE */
