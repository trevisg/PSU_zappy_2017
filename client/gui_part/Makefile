##
## EPITECH PROJECT, 2018
## PSU_zappy_2017client makefile
## File description:
## Makefile for zappy client
##

CC      	= g++

RM      	= rm -f

CPPFLAGS	+= -I./include -Wall -Werror -Wextra

LDFLAGS		+= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for GUI client
GUICLIENT_SRCS	=  Zappy_gui.cpp \
		Menu_Title.cpp \
		Menu_Settings.cpp \
		Menu_NewGame.cpp \
		Game_Window.cpp \
		Menu.cpp

GUICLIENTSRC	= $(addprefix src/, $(GUICLIENT_SRCS))

#Binary name

GUICLIENT	= zappy_gui


all:		$(GUICLIENT)

$(GUICLIENT):
		$(CC) $(CFLAGS) $(LDFLAGS) $(GUICLIENTSRC) -o $(GUICLIENT)

testgame:
		@printf "Debug game window methods\n"
		g++ src/Game_Window.cpp $(CPPFLAGS) $(LDFLAGS) -D TESTGAME
		@printf "Done.\nNow run with ./a.out x y (map size)\n"

fclean: 	clean
		$(RM) $(GUICLIENT)

re:		fclean all

.PHONY:		all clean fclean re doc server
