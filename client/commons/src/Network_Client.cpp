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
	return (rt >= 0 ? true : false);
}

std::map<std::string, std::string>	Network::get_map_size()
{

	std::map<std::string, std::string> map_size;
	std::string req("GET /mapsize\n");

	if (!connect_to("127.0.0.1", "2222")) {
		map_size["error"] = "Connection error";
	} else {
		write(_client_socket, req.c_str(), req.size());
		listen_up();
		_queue.pop();
		while (!_queue.empty()) {
			if (_queue.front() != ",") {
				std::string index = _queue.front();
				_queue.pop();
				std::string value = _queue.front();
				map_size[index] = value;
			}
			_queue.pop();
		}
	}
	return (map_size);
}

std::vector<std::string>	Network::get_teamnames()
{

	std::vector<std::string> teams;
	std::string req("GET /teamnames\n");

	if (!connect_to("127.0.0.1", "2222")) {
		teams.emplace_back("Connection error");
	} else {
		write(_client_socket, req.c_str(), req.size());
		listen_up();
		while (!_queue.empty()) {
			if (_queue.front() != "teamnames" && _queue.front() != ",") {
				teams.emplace_back(_queue.front());
			}
			_queue.pop();
		}
	}
	return (teams);
}

std::vector<std::map<std::string, std::string> >	Network::get_team_details(
		std::string team
						)
{
	std::vector<std::map<std::string, std::string> > team_details;
	std::map<std::string, std::string>		player;
	std::string req("POST /team_detail&team=" + team + "\n");

	if (!connect_to("127.0.0.1", "2222")) {
		std::map<std::string, std::string> err;
		err["error"] = "Connection lost";
		team_details.emplace_back(err);
	} else {
		write(_client_socket, req.c_str(), req.size());
		listen_up();
		std::map<std::string, std::string> team_name;
		team_name["teamname"] = _queue.front();
		team_details.emplace_back(team_name);
		_queue.pop();
		while (!_queue.empty()) {
			if (_queue.front() != ",") {
				std::string index = _queue.front();
				_queue.pop();
				std::string value = _queue.front();
				player[index] = value;
			}
			if (player.size() == 4) {
				team_details.emplace_back(player);
				player.clear();
			}
			_queue.pop();
		}
	}
	return (team_details);
}

std::vector<std::string> Network::_look()
{
	std::vector<std::string> rt;
	std::string req("Look\n");

	write(_client_socket, req.c_str(), req.size());
	listen_up();
	while (!_queue.empty()) {
		rt.emplace_back(_queue.front());
		_queue.pop();
	}
	return (rt);
}

std::map<std::string, std::string> Network::_forward()
{
	std::map<std::string, std::string> rt;
	std::string req("Forward\n");

	write(_client_socket, req.c_str(), req.size());
	listen_up();
	while (!_queue.empty()) {
		_queue.pop();
	}
	return (rt);
}

std::vector<std::string>		Network::_fork()
{
	std::vector<std::string> res;
	std::string req("Fork\n");

	write(_client_socket, req.c_str(), req.size());
	listen_up();
	return (res);
}

std::map<std::string, std::string>	Network::_teams(
					std::string team_name)
{
	std::map<std::string, std::string> pos;
	std::string req("Team " + team_name + "\n");

	write(_client_socket, req.c_str(), req.size());
	listen_up();
	while (!_queue.empty()) {
		std::string value(_queue.front());
		if (value != "ko") {
			pos["PLAYER_CREDIT"] = value;
			_queue.pop();
			value = _queue.front();
			pos["x"] = value;
			_queue.pop();
			value = _queue.front();
			pos["y"] = value;
			break;
		} else {
			pos["ko"] = "NO CREDITS";
		}
		if (!_queue.empty())
			_queue.pop();
	}
	return (pos);
}

bool	Network::listen_up()
{
	int r_size = 0;
	std::string s;
	std::regex r("[a-z0-9,.]+");

	memset(_server_resp, 0, MAX_RESP);
	while ((r_size = read(_client_socket, _server_resp, MAX_RESP)) > 0) {
		if (r_size) {
			s = _server_resp;
			std::sregex_iterator i;
			for (i = std::sregex_iterator(s.begin(), s.end(), r);
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
