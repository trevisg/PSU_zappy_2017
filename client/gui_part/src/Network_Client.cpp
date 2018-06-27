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

bool	Network::_connect_to(std::string server_host, std::string server_port)
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

std::vector<std::string>	Network::_get(std::string req)
{
	std::vector<std::string> teams;
	std::string request("GET /" + req + "\n");
	std::cerr << "Sending request : " << request;
	write(_client_socket, request.c_str(), request.size());
	_listen_up();
	if (_queue.front() == req) {
		_queue.pop();
		while (!_queue.empty()) {
			teams.emplace_back(_queue.front());
			_queue.pop();
		}
	} else {
		teams.emplace_back("\nERROR invalid format");
	}
	return (teams);
}

std::map<std::string, int>	Network::_get_mapsize()
{
	std::map<std::string, int> mapsize;
	std::string request("GET /mapsize\n");
	std::cerr << "Sending request : " << request;
	write(_client_socket, request.c_str(), request.size());
	_listen_up();
	if (_queue.front() == "mapsize") {
		_queue.pop();
		while (!_queue.empty()) {
			std::string index(_queue.front());
			mapsize[index] = 0;
			_queue.pop();
			uint val = std::stoi (_queue.front(), nullptr, 10);
			mapsize[index] = val;
			_queue.pop();
		}
	} else {
		mapsize["ERROR"] = -1;
	}
	return (mapsize);
}

std::vector<std::map<std::string, std::string> >
			Network::_get_team_members(std::string teamname)
{
	uint 	members = 0;
	std::map<std::string, std::string> teams_members;
	std::vector<std::map<std::string, std::string> > teams;
	std::string request("POST /team_detail&team=" + teamname + "\n");

	std::cerr << "Sending request : " << request;
	write(_client_socket, request.c_str(), request.size());
	_listen_up();
	_listen_up();
	_queue.pop();
	while (!_queue.empty()) {
		std::string index;
		std::string value;

		index = _queue.front();
		_queue.pop();
		value = _queue.front();
		teams_members[index] = value;
		if (teams_members.find("id") != teams_members.end()
		&& teams_members.find("x") != teams_members.end()
		&& teams_members.find("y") != teams_members.end()
		&& teams_members.find("ttl") != teams_members.end()) {
			teams_members["id"] = std::to_string(members);
			teams.emplace_back(teams_members);
			teams_members.clear();
			members += 1;
		}
		if (!_queue.empty())
			_queue.pop();
	}
	return (teams);
}

bool	Network::_listen_up()
{
	int r_size = 0;
	std::string s;
	std::regex r("[a-z0-9.]+");

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
		}
	}
	return (r_size > 0 ? true : false);
}
