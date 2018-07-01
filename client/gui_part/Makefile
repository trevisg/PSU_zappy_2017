##
## EPITECH PROJECT, 2018
## PSU_zappy_2017client makefile
## File description:
## Makefile for zappy client
##

CC      	= g++

RM      	= rm -f

CPPFLAGS	+= -I./include -I../commons/include -Wall -Werror -Wextra

LDFLAGS		+= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

CRITFLAGS	= -Wall -Werror -Wextra -lcriterion -coverage

## Sources and rules for GUI client
GUICLIENT_SRCS	= ../commons/src/Network_Client.cpp \
		src/Zappy_gui.cpp \
		src/Menu_Title.cpp \
		src/Menu_Settings.cpp \
		src/Menu_NewGame.cpp \
		src/Game_Window.cpp \
		src/Menu.cpp

#Binary name

GUICLIENT	= zappy_gui


all:		$(GUICLIENT)

$(GUICLIENT):
		$(CC) $(CFLAGS) $(LDFLAGS) $(GUICLIENT_SRCS) -o $(GUICLIENT)

testgame:
		@printf "Debug game window methods\n"
		g++ src/Game_Window.cpp ../commons/src/Network_Client.cpp \
		$(CPPFLAGS) $(LDFLAGS) -D TESTGAME
		@printf "Done.\nNow run with ./a.out x y (map size)\n"

testnetwork:
		@printf "Debug network client methods\n"
		g++ $(CPPFLAGS) $(LDFLAGS) src/Network_Client.cpp \
 		tests/Network_Client_tests.cpp
		@printf "Done.\nNow run with ./a.out\n"

fclean: 	clean
		$(RM) $(GUICLIENT)

re:		fclean all

.PHONY:		all clean fclean re doc server
