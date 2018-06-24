##
## EPITECH PROJECT, 2018
## PSU_zappy_2017 makefile
## File description:
## Makefile for zappy server
##

CC      	= gcc

DOXYGEN		= doxygen

RM      	= rm -f

CFLAGS		+= -I./include -Wall -Werror -Wextra -std=gnu99

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for server
srcS	= varioushelpers_functions/time_handlers.c \
		varioushelpers_functions/logs_helpers.c \
		varioushelpers_functions/sig_handler.c \
		varioushelpers_functions/usage.c \
		commandline_args_handlers/cl_args_helpers.c \
		commandline_args_handlers/cl_args_parsing.c \
		commandline_args_handlers/cl_flags_bis.c \
		commandline_args_handlers/cl_flags.c \
		tcpserver_functions/server_decls.c \
		tcpserver_functions/server_init.c \
		tcpserver_functions/server_main.c \
		trantor_setup/ressources_decl.c \
		trantor_setup/users_mgr.c \
		trantor_setup/teams_mgr.c \
		trantor_setup/world_creation.c \
		commands_parsing.c \
		print_fcts.c \
		send_fcts/broadcast.c \
		send_fcts/find_list.c \
		send_fcts/motion.c \
		send_fcts/utils.c \
		send_fcts/utils2.c \
		main.c

SERVERSRC	= $(addprefix src/, $(srcS))

SERVEROBJS	:= $(SERVERSRC:.c=.o)

## Binary and rule name for zappy_server

SERVER		= zappy_server

all:		$(SERVER)

$(SERVER):	$(SERVEROBJS)
		$(CC) $(CFLAGS) $(SERVEROBJS) -o $(SERVER)

clean:
		$(RM) $(SERVEROBJS)

fclean: 	clean
		$(RM) $(SERVER)

re:		fclean all

cltest:
		@printf "Debug server command line args handler\n"
		gcc src/commandline_args_handlers/*.c $(CFLAGS) \
 		-D CLTEST -g3
		@printf "Done.\nNow run with ./a.out [see subject for args]\n"

clocktest:
		@printf "Debug clock processing methods\n"
		gcc src/various_helpers_functions/time_handlers.c  \
		$(CFLAGS) -D CLOCKTEST -g3
		@printf "Done.\nNow run with ./a.out [no args]\n"

maptest:
		@printf "Debug map gen methods\n"
		gcc src/trantor_setup/world_creation.c src/trantor_setup/ressources_decl.c \
		$(CFLAGS) -D MAPTEST -g3
		@printf "Done.\nNow run with ./a.out X Y\n"

.PHONY:		all clean fclean re cltest clocktest maptest server
