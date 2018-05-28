##
## EPITECH PROJECT, 2018
## my_irc makefile
## File description:
## Makefile for my_irc client & server
##

CC      	= gcc

DOXYGEN		= doxygen

RM      	= rm -f

CFLAGS		+= -I./include -Wall -Werror -Wextra

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for irc client
CLIENT_SRCS	= client.c

CLIENTSRC	= $(addprefix client_src/, $(CLIENT_SRCS))

CLIENTOBJS	:= $(CLIENTSRC:.c=.o)

## Sources and rules for server
SERVER_SRCS	= logs_helpers.c \
		server_init.c \
		server_main.c \
		server_decls.c \
		sig_handler.c \
		user_list.c \
		channel_list.c \
		lists_helpers.c \
		commands_parsing.c \
		rfc_cmds0.c \
		rfc_cmds1.c

SERVERSRC	= $(addprefix server_src/, $(SERVER_SRCS))

SERVEROBJS	:= $(SERVERSRC:.c=.o)

#Binaries names
CLIENT    	= client

SERVER		= server


all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(CLIENTOBJS)
		$(CC) $(CFLAGS) $(CLIENTOBJS) -o $(CLIENT)

$(SERVER):	$(SERVEROBJS)
		$(CC) $(CFLAGS) $(SERVEROBJS) -o $(SERVER)

clean:
		$(RM) $(CLIENTOBJS)
		$(RM) $(SERVEROBJS)

fclean: 	clean
		$(RM) $(CLIENT)
		$(RM) $(SERVER)

re:		fclean all

doc:
		$(DOXYGEN) bonus/Doxyfile

.PHONY: all clean fclean re doc server client
