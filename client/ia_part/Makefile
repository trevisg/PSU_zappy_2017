##
## EPITECH PROJECT, 2018
## PSU_zappy_2017client makefile
## File description:
## Makefile for zappy client
##

CC      	= g++

DOXYGEN		= doxygen

RM      	= rm -f

CFLAGS		+= -I./include -I../commons/include -Wall -Werror -Wextra -g3

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for client
CLIENT_SRCS	=	src/Trantorian.cpp \
			src/main.cpp \
			../commons/src/Network_Client.cpp


CLIENTOBJS	:= $(CLIENT_SRCS:.c=.o)

#Binary name

CLIENT		= zappy_ai


all:		$(CLIENT)

$(CLIENT):	$(CLIENTOBJS)
		$(CC) $(CFLAGS) $(CLIENTOBJS) -o $(CLIENT)

fclean:
		$(RM) $(CLIENT)

re:		fclean all

.PHONY:		all
