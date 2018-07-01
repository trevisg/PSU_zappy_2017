##
## EPITECH PROJECT, 2018
## PSU_zappy_2017 makefile
## File description:
## Makefile for PSU_zappy_2017 project
##

CC      	= gcc

DOXYGEN		= doxygen

DPKGDEB		= dpkg-deb


## Binary and rule name for zappy_server

SERVER		= zappy_server

CLIENT		= zappy_ai

all:
		cd server && $(MAKE)
		mv server/zappy_server .
		cd client/ia_part/ && $(MAKE)
		mv client/ia_part/zappy_ai .
server:
		cd server && $(MAKE)
		mv server/zappy_server .

client:
		cd client/ia_part && $(MAKE)
		mv client/ia_part/zappy_ai .

gui:
		cd client/gui_part && $(MAKE)
		mv client/gui_part/zappy_gui .

zappy_server:	server

zappy_ai:	client

zappy_gui:	gui

clean:
		cd server && $(MAKE) clean

fclean: 	clean
		cd server && $(MAKE) fclean
		cd client/ia_part/ && $(MAKE) fclean

re:		fclean all

doc:
		$(DOXYGEN) bonus/Doxyfile

package-deb:
		make re && make clean && \
 		cp zappy_server bonus/pkgs/deb/zappy-server/usr/local/bin
		$(DPKGDEB) --build bonus/pkgs/deb/zappy-server

install-deb:
		@printf "Installing zappy-server binary in /usr/local/bin\n"
		sudo dpkg -i bonus/pkgs/deb/zappy-server.deb

.PHONY:		all clean fclean re doc server package-deb install-deb
