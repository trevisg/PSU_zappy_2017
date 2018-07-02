//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Game window methods
//

#ifndef NETWORK_CLIENT_HPP_
# define NETWORK_CLIENT_HPP_

#include <map>
#include <queue>
#include <vector>
#include <string>
#include <regex>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_HOSTNAME	45
#define MAX_RECO	30
#define MAX_RESP	4096

class	Network {
	public:
		Network();
		~Network();
		std::vector<std::string>		_look();
		std::vector<std::string>		_fork();
		std::map<std::string, std::string>	_teams(
							std::string team_name);
		std::map<std::string, std::string>	_forward();
		bool 					listen_up();
		std::map<std::string, std::string>	get_map_size();
		std::vector<std::string>		get_teamnames();
		std::vector<std::map<std::string, std::string> >
							get_team_details(
							std::string team);
		std::string				get_lastbuffer();
		bool					connect_to(
							std::string server_host,
							std::string server_port
							);
	private:
		uint					_server_port;
		int					_client_socket;
		char					_server_resp[MAX_RESP];
		char					_server_host[MAX_HOSTNAME];
		std::queue<std::string>			_queue;
		struct sockaddr_in			_client_address;
		const struct sockaddr			*_addr;

};
#endif /* !NETWORK_CLIENT_HPP_ */
