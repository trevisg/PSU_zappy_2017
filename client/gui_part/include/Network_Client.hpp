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
		bool listen_up();
		std::vector<std::string> get_teamnames();
		bool connect_to(std::string server_host,
		std::string server_port);
		std::string get_lastbuffer();
	private:
		uint _server_port;
		int _client_socket;
		char _server_resp[MAX_RESP];
		char _server_host[MAX_HOSTNAME];
		std::queue<std::string> _queue;
		struct sockaddr_in _client_address;
		const struct sockaddr *_addr;

};
#endif /* !NETWORK_CLIENT_HPP_ */
