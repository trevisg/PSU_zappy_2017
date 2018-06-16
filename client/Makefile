##
## EPITECH PROJECT, 2018
## PSU_zappy_2017client makefile
## File description:
## Makefile for zappy client
##

CC      	= gcc

DOXYGEN		= doxygen

RM      	= rm -f

CFLAGS		+= -I./include -Wall -Werror -Wextra -std=gnu99

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for server
SERVER_SRCS	=  src/main.c

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

.PHONY:		all clean fclean re doc server
