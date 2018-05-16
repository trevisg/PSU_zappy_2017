##
## EPITECH PROJECT, 2018
## my_ftp makefile
## File description:
## Makefile for my_ftp
##

CC      	= gcc

DOXYGEN		= doxygen

RM      	= rm -f

CFLAGS		+= -Wall -Werror -Wextra

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for my_ftp => client
FTP_SRCS	= client.c

FTPSRC		= $(addprefix miftp/, $(FTP_SRCS))

FTPOBJS		:= $(FTPSRC:.c=.o)

## Sources and rules for server
SERVER_SRCS	= helpers_log.c \
		server_init.c \
		server_main.c \
		server_decls.c \
		server_commands0.c \
		server_methodsparser.c

SERVERSRC	= $(addprefix forkserver/, $(SERVER_SRCS))

SERVEROBJS	:= $(SERVERSRC:.c=.o)

#Binaries names
MYFTP    	= myftp

SERVER		= server


all:		$(MYFTP) $(SERVER)

$(MYFTP):	$(FTPOBJS)
		$(CC) $(CFLAGS) $(FTPOBJS) -o $(MYFTP)

$(SERVER):	$(SERVEROBJS)
		$(CC) $(CFLAGS) $(SERVEROBJS) -o $(SERVER)

clean:
		$(RM) $(FTPOBJS)
		$(RM) $(SERVEROBJS)

fclean: 	clean
		$(RM) $(MYFTP)
		$(RM) $(SERVER)

re:		fclean all

doc:
		$(DOXYGEN) bonus/Doxyfile

.PHONY: all clean fclean re doc server my_ftp
