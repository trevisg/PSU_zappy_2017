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
SERVER_SRCS	= logs_helpers.c \
		server_init.c \
		server_main.c \
		server_decls.c \
		sig_handler.c \
		user_list.c \
		teams_list.c \
		lists_helpers.c \
		commands_parsing.c \
		rfc_cmds0.c \
		rfc_cmds1.c

SERVERSRC	= $(addprefix server_src/, $(SERVER_SRCS))

SERVEROBJS	:= $(SERVERSRC:.c=.o)

#Binary name

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
		@echo "Debug server command line args handler"
		gcc server_src/cl_args.c $(CFLAGS) -D CLTEST -g3

.PHONY:		all clean fclean re doc server
