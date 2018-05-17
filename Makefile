##
## EPITECH PROJECT, 2018
## my_irc makefile
## File description:
## Makefile for my_irc client & server
##

CC      	= gcc

DOXYGEN		= doxygen

RM      	= rm -f

CFLAGS		+= -Wall -Werror -Wextra -coverage

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for my_ftp => client
CLIENT_SRCS	= client.c

CLIENTSRC	= $(addprefix client/, $(FTP_SRCS))

CLIENTOBJS	:= $(FTPSRC:.c=.o)

## Sources and rules for server
SERVER_SRCS	= logs_helpers.c \
		server_init.c \
		server_main.c \
		server_decls.c \
		rfc_cmds0.c

SERVERSRC	= $(addprefix server/, $(SERVER_SRCS))

SERVEROBJS	:= $(SERVERSRC:.c=.o)

#Binaries names
CLIENT    	= client

SERVER		= server


all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(CLIENTTOBJS)
		$(CC) $(CFLAGS) $(FTPOBJS) -o $(CLIENT)

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
