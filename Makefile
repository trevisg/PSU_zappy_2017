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
SERVER_SRCS	= varioushelpers_functions/time_handlers.c \
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
		trantor_setup/world_creation.c \
		commands_parsing.c \
		lists_finders.c \
		teams_list.c \
		user_list.c \
		rfc_cmds0.c \
		rfc_cmds1.c \
		main.c

SERVERSRC	= $(addprefix server_src/, $(SERVER_SRCS))

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

doc:
		$(DOXYGEN) bonus/Doxyfile

cltest:
		@printf "Debug server command line args handler\n"
		gcc server_src/commandline_args_handlers/*.c $(CFLAGS) \
 		-D CLTEST -g3
		@printf "Done.\nNow run with ./a.out [see subject for args]\n"

clocktest:
		@printf "Debug clock processing methods\n"
		gcc server_src/various_helpers_functions/time_handlers.c  \
		$(CFLAGS) -D CLOCKTEST -g3
		@printf "Done.\nNow run with ./a.out [no args]\n"

maptest:
		@printf "Debug map gen methods\n"
		gcc server_src/world_creation.c server_src/ressources_decl.c \
		$(CFLAGS) -D MAPTEST -g3
		@printf "Done.\nNow run with ./a.out X Y\n"

.PHONY:		all clean fclean re doc server
