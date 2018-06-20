##
## EPITECH PROJECT, 2018
## PSU_zappy_2017client makefile
## File description:
## Makefile for zappy client
##

CC      	= g++

RM      	= rm -f

CFLAGS		+= -I./include -Wall -Werror -Wextra

LDFLAGS		+= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for GUI client
GUICLIENT_SRCS	=  Zappy_gui.cpp \
		Menu_Title.cpp \
		Menu_Settings.cpp \
		Menu_NewGame.cpp \
		Menu.cpp

GUICLIENTSRC	= $(addprefix src/, $(GUICLIENT_SRCS))

#Binary name

GUICLIENT	= zappy_gui


all:		$(GUICLIENT)

$(GUICLIENT):
		$(CC) $(CFLAGS) $(LDFLAGS) $(GUICLIENTSRC) -o $(GUICLIENT)

fclean: 	clean
		$(RM) $(GUICLIENT)

re:		fclean all

.PHONY:		all clean fclean re doc server
