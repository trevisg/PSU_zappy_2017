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

all:
		cd server && $(MAKE)
		mv server/zappy_server .

zappy_server:	all

clean:
		cd server && $(MAKE) clean

fclean: 	clean
		cd server && $(MAKE) fclean

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
