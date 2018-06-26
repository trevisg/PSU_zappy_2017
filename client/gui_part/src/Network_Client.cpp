//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Game window methods
//

#include "../include/Network_Client.hpp"

Network::Network() :  _server_port(2222), _server_host("127.0.0.1"),
	_addr((const struct sockaddr *)&_client_address)
{
	memset(&_client_address, 0, sizeof(_client_address));
	memset(_server_resp, 0, MAX_RESP);
}

Network::~Network()
{
	close(_client_socket);
}

bool	Network::connect_to(std::string server_host, std::string server_port)
{
	int rt = 0;
	uint address_size = sizeof(_client_address);

	_server_port = std::stoi (server_port, nullptr, 10);
	strncpy(_server_host, server_host.c_str(), 45);
	_client_address.sin_family = AF_INET;
	_client_address.sin_addr.s_addr = inet_addr(_server_host);
	_client_address.sin_port = htons(_server_port);
	if ((_client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		std::cerr << "Nework(): socket() :" << strerror(errno) << "\n";
		exit(EXIT_FAILURE);
	} else if ((rt = connect(_client_socket, _addr, address_size)) == -1) {
		std::cerr << "connect: connect() :" << strerror(errno) << "\n";
	}
	return (rt > 0 ? true : false);
}

bool	Network::listen_up()
{
	int r_size = 0;
	static uint queue_size;

	memset(_server_resp, 0, MAX_RESP);
	while ((r_size = read(_client_socket, _server_resp, MAX_RESP)) > 0) {
		std::cout << r_size << '\n';
		if (r_size) {
			_map[queue_size] = std::string(_server_resp);
			queue_size += 1;
			break;
		} else {
			queue_size = 0;
			break;
		}
	}
	return (r_size > 0 ? true : false);
}

std::string	Network::get_lastbuffer()
{
	uint i = 0;
	std::string::size_type pos = 0;

	for (; i < _map.size(); ++i) {
		while ((pos = _map[i].find ("\n", pos)) != std::string::npos) {
			_map[i].erase (pos, 1);
		}
	}
	return _map[i - 1];
}
