/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server header file
*/

#ifndef SERVER_H_
# define SERVER_H_

	#include <stdio.h>
	#include <netdb.h>
	#include <string.h>
	#include <sys/epoll.h>
	#include <netinet/in.h>
	#include <sys/socket.h>
	#include "zappy_game.h"

	/** Number of simultaneous connection on server listening socket
	* see listen() call
	*/
	#define BACKLOG 10
	/** Number of Zappy command */
	#define REF_NB 13
	/** This good old C mem alloc dirty method */
	#define BUF_SIZE 1060
	/** The length of the struct epoll_events array
	* pointed to by *events
	*/
	#define MAX_EVENTS 10

	/** Max teams */
	#define MAXTEAMS 1000
	/** Maximum number of args in a single command */
	#define MAXARGS 15
	/** Maximum argument length see ref below
	* @note obtained by 500 / max args
	*/
	#define MAXARGSIZE 33
	/** Maximal size for a client IP address */
	#define NI_MAXHOST 1025
	/** Maximal size for a client host port */
	#define NI_MAXSERV 32
	/** Argument format typedef as per subject request
	* @note Useless typedef came from a deprecated method, but hey too lazy
	* to rename all
	*/
	typedef char ** cmdargs;
	/** Yess useless so mandatory */
	#define EVER ;;

	/** Only here for code clarity and lisibility
	* @todo : Have a look at ZAPPY_CMDS.md file for ref
	*/
	enum  CMDS {
		FORWARD, RIGHT, LEFT,
		LOOK, INVENTORY, BROADCAST_TEXT,
		CONNECT_NBR, FORK, EJECT,
		TAKE_OBJECT, SET_OBJECT, INCANTATION
	};

	/* Future login handler filepath (to be set in a .conf file) */
	enum  LPATHS {
		ACCESS,
		ERRORS,
		NOTICES
	};

	/** The logger methods structure with files pointer
	* and timestamp variables
	* @note not yet implemented
	*/
	typedef struct			s_log {
		FILE			*errlog;
		FILE			*accesslog;
		char			*timestmp;
		time_t			timeval;
		mode_t			*set;
		mode_t 			mode;
		mode_t			dir_mode;
	}				t_log;

	/** Used to store command line args */
	typedef struct			s_clargs {
		char			*port;
		int			width;
		int			height;
		char			**teams_names;
		int			clientsNb;
		int			freq;
	}				t_clargs;

	/** Yeah simplification */
	typedef struct addrinfo adrinf;

	/** Main server structure */
	typedef struct			s_serv {
		int			nfds;
		int			port;
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

	/** To avoid stdbool include (for s_user.isco)*/
	#define true	1
	#define false 	0
	/** A typical Zappy client
	* @todo update with the t_inhabitant struct
	*/
	typedef struct			s_user {
		int			clifd;
		int			mode;
		char			*nick;
		char 			*rname;
		unsigned int		isco;
	}				t_user;

	/** The doubly linked list of connected users */
	typedef struct			s_userlist {
		t_user 			*user;
		struct s_userlist	*prev;
		struct s_userlist	*next;
	}				t_userlist;

	/** A doubly linked list of current teams with their users */
	typedef struct 			s_teams {
		char 			*channame;
		t_userlist		*users;
		struct s_teams		*prev;
		struct s_teams		*next;
	}				t_teams;

	/** Main Zappy Protocol methods function pointer
	* @note see server_src/server_decls.c
	*/
	typedef void *(*cmds)(cmdargs args, int clifd, t_teams *chanlist);
	/** The flags 'gatherer' function pointer
	* @note see server_src/cl_args_helpers.c
	*/
	typedef void *(*clargs)(char **, t_clargs *);

	/** @note see server_src/inits.c */
	int		set_sockfd(t_serv *all);
	int		set_epoll(t_serv *all);
	int		set_iface(adrinf *hints, adrinf **res,
				const char *port);
	int		set_clifd(int clisock, int epollfd,
				struct epoll_event *ev);
	/** @note see server_src/server_main.c */
	int		server(t_clargs *options);
	/** @note see server_src/commands_parsing.c */
	int		get_methods(char *req, int clifd);
	/** @note see server_src/logs_helpers.c */
	int		logthisevent(const char etype, t_serv *all);
	void		print_users(t_userlist *list);
	void		print_users_in_chans(t_teams *chanlist, int index);
	/** @note see server_src/client_list.c */
	t_userlist	*get_new_userlist(t_user *usr);
	void		print_users(t_userlist *liste);
	void		free_userlist(t_userlist *list);
	void		*remove_user(t_userlist *list, int clifd);
	t_user		*get_new_user(int clifd, cmdargs usercmd);
	void		*insert_back_user(t_userlist *head, t_userlist *nuser);
	/** @note see server_src/teams_list.c */
	t_teams		*init_default_teams(void);
	void		free_teams_list(t_teams *list);
	t_teams		*get_new_chan_list(t_userlist *userlist, char *);
	void		remove_teams(t_teams *list, char *channame);
	void		*insert_back_teams(t_teams *head, t_teams *chan);
	/** @note see server_src/list_helpers.c */
	t_user		*find_user_by_fd(t_userlist *list, int clifd);
	t_user		*find_user_by_name(const char *name, t_userlist *usrs);
	t_teams		*get_team_by_name(t_teams *list, char *channame);
	unsigned int	is_user_in_chan(int clifd, t_teams *chans);
	unsigned int 	get_size(cmdargs args);
	/** @note see @file server_src/rfc_cmds0.c */
	void		*join(cmdargs args, int clifd, t_teams *chanlist);
	void		*nick(cmdargs args, int clifd, t_teams *chanlist);
	void		*ping(cmdargs args, int clifd, t_teams *chanlist);
	void		*user(cmdargs args, int clifd, t_teams *chanlist);
	void		*quit(cmdargs args, int clifd, t_teams *chanlist);
	/** @note see server_src/rfc_cmds1.c */
	void		*privmsg(cmdargs args, int clifd, t_teams *chans);
	/** @note See server_src/cl_flags.c */
	void		*get_port(char **port, t_clargs *args);
	void		*get_width(char **width, t_clargs *args);
	void		*get_height(char **height, t_clargs *args);
	/** @note see server_src/cl_flags_bis.c */
	void		*get_teams(char **teams, t_clargs *args);
	void		*get_clientsNb(char **clientsNb, t_clargs *args);
	void		*get_freq(char **freq, t_clargs *args);
	/** @note see server_src/cl_args.c */
	t_clargs	*get_opts(int ac, char **av);
	/** @note see server_src/cl_args_helpers.c */
	clargs		*set_opts();
	void		free_buffers(char **buffer);
	/** @note see server_src/signal_handler.c */
	void		sig_handler(int signo);
	/** @note see server_src/usage.c */
	void 		usage(char *progname);

	/** The object prototype mapping the methods name
	* @note see server_src/server_decls.c
	*/
	extern const char *G_PROTOS[REF_NB];
	/** The global pointer for subject commands methods */
	extern const cmds G_CMDS[REF_NB];

	/** See server_src/trantor_setup/world_creation */
	t_world		*get_world(t_clargs *args);
	void		free_world(t_world *trantor, t_clargs *args);

#endif /* !SERVER_H_ */
