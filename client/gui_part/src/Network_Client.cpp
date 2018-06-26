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

std::vector<std::string>	Network::get_teamnames()
{
	std::vector<std::string> teams;
	std::string req("GET /teamnames\n");
	write(_client_socket, req.c_str(), req.size());
	listen_up();
	while (!_queue.empty()) {
		teams.emplace_back(_queue.front());
		_queue.pop();
	}
	return (teams);
}

bool	Network::listen_up()
{
	int r_size = 0;
	std::string s;
	std::regex r("[a-z]+");

	memset(_server_resp, 0, MAX_RESP);
	while ((r_size = read(_client_socket, _server_resp, MAX_RESP)) > 0) {
		if (r_size) {
			s = _server_resp;
			for (std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
			i != std::sregex_iterator(); ++i) {
				std::smatch m = *i;
				_queue.push(m.str());
			}
			break;
		} else
			break;
	}
	return (r_size > 0 ? true : false);
}

std::string	Network::get_lastbuffer()
{
	return _queue.front();
}
