##
## EPITECH PROJECT, 2018
## PSU_zappy_2017client makefile
## File description:
## Makefile for zappy client
##

CC      	= g++

DOXYGEN		= doxygen

RM      	= rm -f

CFLAGS		+= -I./include -Wall -Werror -Wextra

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for client
CLIENT_SRCS	=	src/player.cpp 	\
			src/core.cpp 	\
			src/pos.cpp	\
			src/tile.cpp	\
			src/main.c

CLIENTSRC	= $(addprefix ./, $(CLIENT_SRCS))

CLIENTOBJS	:= $(CLIENTSRC:.c=.o)

#Binary name

CLIENT		= zappy_client


all:		$(CLIENT)

$(CLIENT):	$(CLIENTOBJS)
		$(CC) $(CFLAGS) $(CLIENTOBJS) -o $(CLIENT)

##clean:
##		$(RM) $(CLIENTOBJS)

##fclean: 	clean
##		$(RM) $(CLIENT)

##re:		fclean all

doc:
		$(DOXYGEN) bonus/Doxyfile

socktest:
		gcc $(CFLAGS) -D SOCKTEST src/sockets/sockets_methods.c -o cli
		@printf "Done run with ./cli [host] [port]\n"

.PHONY:		all clean fclean re doc server
