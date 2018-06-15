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
SERVER_SRCS	= various_helpers_functions/time_handlers.c \
		various_helpers_functions/logs_helpers.c \
		various_helpers_functions/sig_handler.c \
		command_line_args/cl_args_helpers.c \
		command_line_args/cl_args_parsing.c \
		tcp_server_functions/server_decls.c \
		tcp_server_functions/server_init.c \
		tcp_server_functions/server_main.c \
		various_helpers_functions/usage.c \
		command_line_args/cl_flags_bis.c \
		command_line_args/cl_flags.c \
		commands_parsing.c \
		lists_helpers.c \
		stones_decl.c \
		teams_list.c \
		user_list.c \
		rfc_cmds0.c \
		rfc_cmds1.c \

SERVERSRC	= $(addprefix server_src/, $(SERVER_SRCS))

SERVEROBJS	:= $(SERVERSRC:.c=.o)

#Binary name

SERVER		= zappy_server


all:		$(SERVER)

$(SERVER):	$(SERVEROBJS)
		$(CC) $(CFLAGS) $(SERVEROBJS) -o $(SERVER)

zappy_server:	all

clean:
		$(RM) $(SERVEROBJS)

fclean: 	clean
		$(RM) $(SERVER)

re:		fclean all

doc:
		$(DOXYGEN) bonus/Doxyfile

argstest:
		@printf "Debug server command line args handler\n"
		gcc server_src/command_line_args/cl_args.c $(CFLAGS) \
 		-D CLTEST -g3
		@printf "Done.\nNow run with ./a.out [see subject for args]\n"

clocktest:
		@printf "Debug clock processing methods\n"
		gcc server_src/various_helpers_functions/time_handlers.c  \
		$(CFLAGS) -D CLOCKTEST -g3
		@printf "Done.\nNow run with ./a.out [no args]\n"

.PHONY:		all clean fclean re doc server
