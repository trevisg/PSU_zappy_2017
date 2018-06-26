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
	#include <stdlib.h>
	#include <time.h>
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
	* @note Useless typedef came from a deprecated method
	*/
	typedef char ** cmdargs;

	#define EVER ;;

	/** Only here for code clarity and lisibility
	* @todo : Have a look at ZAPPY_CMDS.md file for ref
	*/
	enum  CMDS {
		FORWARD, RIGHT, LEFT,
		LOOK, INVENTORY, BROADCAST_TEXT,
		CONNECT_NBR, FORK, EJECT,
		TAKE_OBJECT, SET_OBJECT, INCANTATION, TEAM
	};

	/** Future login handler filepath (to be set in a .conf file)
	* @note : not yet implemented
	*/
	enum  LPATHS {
		ACCESS,
		ERRORS,
		NOTICES
	};

	/** The logger methods structure with files pointer
	* and timestamp variables
	* @note not yet implemented
	* @todo create all methods to write to log file instead
	* stdout or stderr
	*/
	typedef struct			s_log {
		FILE			*errlog;
		FILE			*accesslog;
		char			*timestmp;
		time_t			timeval;
		mode_t			*set;
		mode_t			mode;
		mode_t			dir_mode;
	}				t_log;

	/** Used to store command line args
	* @var t_clargs::port
	* @brief the server listening port
	* @var t_clargs::width
	* @brief the map width (X)
	* @var t_clargs::height
	* @brief the map height (Y)
	* @var t_clargs::team_names
	* @brief the command lines team names
	* @var t_clargs::clientsNb
	* @brief the max number of client per team
	* @var t_clargs::freq
	* @brief the time frequency unit 1/f
	*/
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

	/** Main server structure
	* @var t_serv::ev
	* @brief `grep -r 'all->ev' .` ;)
	* @var t_serv::rp
	* @brief the main free addresses structs to bind()
	* @note this makes our server to listen on all interfaces
	* @var t_serv::res
	* @brief see set_sockfd()
	* @var t_serv::nfds
	* @brief all the registered client fd's entries
	* @var t_serv::port
	* @brief this server port int format
	* @var t_serv::hints
	* @brief see set_iface()
	* @var t_serv::nread
	* @brief the return read(clifd, x, x) value see getactiveclients()
	* @var t_serv::refmap
	* @brief the reference zappy_game object in this network programm
	* @var t_serv::epollfd
	* @brief see `man epoll`
	* @var t_serv::conn_sock
	* @brief see init_connection()
	* @var t_serv::listen_sock
	* @brief the server listen sock for new accept() ed client co
	* see init_connection()
	* @var t_serv::buf
	* @brief this so C memory for all the received data's
	* @todo u know this could be better with a circular buffer instead
	* @var t_serv::host
	* @brief the client address to print in logs ?
	* @todo make the bellow function work
	* @var t_serv::events
	* @brief read man epoll
	* @var t_serv::service
	* @brief the client address port
	*/
	typedef struct			s_serv {
		struct epoll_event	ev;
		adrinf			*rp;
		adrinf			*res;
		int			nfds;
		int			port;
		adrinf			hints;
		ssize_t			nread;
		t_world			*refmap;
		int			epollfd;
		int			conn_sock;
		int			listen_sock;
		char			buf[BUF_SIZE];
		char			host[NI_MAXHOST];
		struct epoll_event	events[MAX_EVENTS];
		char			service[NI_MAXSERV];
	}				t_serv;

	/** To avoid stdbool include (for s_user.isco)*/
	#define true	1
	#define false	0

	/** Main Zappy Protocol methods function pointer
	* @note see src/server_decls.c
	*/
	typedef void *(*cmds)(cmdargs args, int clifd, t_world *map);
	/** The flags 'gatherer' function pointer
	* @note see src/cl_args_helpers.c
	*/
	typedef void *(*clargs)(char **, t_clargs *);

	/** The object prototype mapping the methods name
	* @note see src/server_decls.c
	*/
	extern const char *G_PROTOS[REF_NB];
	/** The global pointer for subject commands methods */
	extern const cmds G_CMDS[REF_NB];

	/** @note see src/inits.c */
	int		set_sockfd(t_serv *all);
	int		set_epoll(t_serv *all);
	int		set_iface(adrinf *hints, adrinf **res,
				const char *port);
	int		set_clifd(int clisock, int epollfd,
				struct epoll_event *ev);
	/** @note see src/server_main.c */
	int		server(t_clargs *options);
	/** @note see src/commands_parsing.c */
	int		get_methods(char *req, int clifd, t_world *map);
	/** @note see src/logs_helpers.c */
	int		logthisevent(const char etype, t_serv *all);
	/** @note all trantor setup command and fctions */
	/** trantor_setup/teams_mgr.c */
	t_teams		*get_new_team(char *name);
	t_teams		*add_team_back(t_teams *list, char *name);
	t_teams		*init_teams(char **teams_names);
	/** trantor_setup/users_mgr.c */
	void		get_first_inventory(t_ressources *inv);
	t_inhabitant	*new_user(int id, int sizeX, int sizeY, char *teamname);
	t_userlist	*add_userlist(int id, t_clargs *args, char *team_name,
				t_userlist *head);
	t_userlist	*new_userlist(int nb_players, t_clargs *args, char *team_name);
	t_teams		*init_userlist(t_teams *teams, t_clargs *args);
	/** @note see server_src/list_helpers.c */
	t_teams		*get_team_by_name(t_teams *list, char *channame);
	unsigned int	is_user_in_chan(int clifd, t_teams *chans);
	unsigned int	get_size(cmdargs args);

	/** See src/trantor_setup/world_creation */
	t_world		*get_world(t_clargs *args);
	void		free_world(t_world *trantor, t_clargs *args);
	/* Print objects see src/print_fcts.c*/
	void            print_world(t_world *map);
	void            print_teams(t_teams *teams);

	#ifdef WITH_IRC

		void		print_users(t_userlist *list);
		void		print_users_in_chans(t_teams *chanlist,
				int index);
		/** @note see src/client_list.c */
		t_userlist	*get_new_userlist(t_user *usr);
		void		print_users(t_userlist *liste);
		void		free_userlist(t_userlist *list);
		void		*remove_user(t_userlist *list, int clifd);
		t_user		*get_new_user(int clifd, cmdargs usercmd);
		void		*insert_back_user(t_userlist *head,
				t_userlist *nuser);
		/** @note see src/teams_list.c */
		t_teams		*init_default_teams(void);
		void		free_teams_list(t_teams *list);
		t_teams		*get_new_chan_list(t_userlist *userlist,
				char *);
		void		remove_teams(t_teams *list, char *channame);
		void		*insert_back_teams(t_teams *head,
				t_teams *chan);
		/** @note see src/list_helpers.c */
		t_user		*find_user_by_fd(t_userlist *list, int clifd);
		t_user		*find_user_by_name(const char *name,
				t_userlist *usrs);
		/** @note see @file src/rfc_cmds0.c */
		void		*join(cmdargs args, int clifd,
				t_teams *chanlist);
		void		*nick(cmdargs args, int clifd,
				t_teams *chanlist);
		void		*ping(cmdargs args, int clifd,
				t_teams *chanlist);
		void		*user(cmdargs args, int clifd,
				t_teams *chanlist);
		void		*quit(cmdargs args, int clifd,
				t_teams *chanlist);
		/** @note see src/rfc_cmds1.c */
		void		*privmsg(cmdargs args, int clifd,
				t_teams *chans);
	#endif /* !WITH_IRC */

	/** @note See src/cl_flags.c */
	void		*get_port(char **port, t_clargs *args);
	void		*get_width(char **width, t_clargs *args);
	void		*get_height(char **height, t_clargs *args);
	/** @note see src/cl_flags_bis.c */
	void		*get_teams(char **teams, t_clargs *args);
	void		*get_clientsNb(char **clientsNb, t_clargs *args);
	void		*get_freq(char **freq, t_clargs *args);
	/** @note see src/cl_args.c */
	t_clargs	*get_opts(int ac, char **av);
	/** @note see src/cl_args_helpers.c */
	clargs		*set_opts();
	void		free_opts(t_clargs *opts);
	void		free_buffers(char **buffer);
	void		*clean_exit(t_clargs *args, clargs *opts, char *req_save);
	void		*error_exit(t_clargs *args, clargs *opts, char *req_save);
	/** @note see src/signal_handler.c */
	void		sig_handler(int signo);
	/** @note see src/usage.c */
	void		usage(char *progname);

#endif /* !SERVER_H_ */
