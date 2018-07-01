//
// EPITECH PROJECT, 2018
// Communication
// File description:
// Main AI methods container methods
//

#include "../include/Trantorian.hpp"

#define TTL 126
#define EXIT_MAX_PLAYER 84
#define EVER ;;
#define Frequency(f) sleep(f);

Trantorian::Trantorian(std::string server_port, std::string server_host) :
_server_port(server_port), _server_host(server_host)
{
	_level = 1;
}

Trantorian::~Trantorian()
{

}

bool	Trantorian::check_co()
{
	bool rt = false;
	rt = _client.connect_to(_server_host, _server_port);
	return (rt);
}

void 	log_drop( std::map<std::string, std::string> resp,
		std::vector<int> map_size, std::string team_name)
{
	std::cout << "Finished drop on this " << map_size[X]
	<< "*" << map_size[Y] << " map\n";
	std::cout << "Note : Still have ["
	<< resp["PLAYER_CREDIT"] << "] trantorians to drop "
	<< "for team [\"" << team_name << "\"]\n";
}

void	Trantorian::_do_search(std::vector<std::string>  res, uint  cnt)
{
	std::cerr << "state : " << "SEARCHING\n";
	std::cerr << "send -->look \n";
	std::cerr << "Receive :\n";
	for (uint i = 0; i != res.size(); ++i) {
		std::cerr << "[" << res[i] << "]\n";
	}
	if (cnt >= TTL) {
		std::cerr << "No more life exiting..\n";
		kill(getpid(), SIGINT);
	}
}

void	Trantorian::_do_fork()
{
	static uint childs;

	childs += 1;
	if (fork() == 0) {
		std::cerr << " Where in child n°" << childs << '\n';
		Trantorian ia_player(_server_port, _server_host);
		bool check = ia_player.check_co();
		if (check) {
			ia_player.run(_team_name);
		}
	}
}

void	do_moove(int _level)
{
	std::cerr << "state : " << "MOOVING\n";
	std::cerr << "Send Forward on trantor map \n";
	std::cerr << "Note : we're still on level [";
	std::cerr << _level << "]\n";
	std::cerr << "send -->Forward \n";
}

void 	print_state(uint cnt, STATE value)
{

	std::cerr << "State : ";
	switch (value) {
		case DROPPING:
		std::cerr << "DROPPING\n";
		break;
		case FORKING:
		std::cerr << "FORKING\n";
		break;
		case MOOVING:
		std::cerr << "MOOVING\n";
		break;
		case SEARCHING:
		std::cerr << "SEARCHING\n";
		break;
		case PICKING_FOOD:
		std::cerr << "PICKING_FOOD\n";
		break;
		case PICKING_STONE:
		std::cerr << "PICKING_STONE\n";
		break;
	}
	std::cerr << "TimeTolive: " << TTL - cnt << "s\n";
}

bool	Trantorian::run(std::string team_name)
{
	bool rt = false;
	STATE curr_state = DROPPING;
	static uint cnt = 0;
	std::vector<int> map_size;
	std::map<std::string, std::string> resp;

	_team_name = team_name;
	for (EVER) {
		Frequency(1);
		++cnt;
		resp = curr_state == DROPPING ?
			_client.get_map_dimension(_team_name) : resp;
		if (resp.find("x") != resp.end()
		&& resp.find("y") != resp.end()
		&& resp.find("PLAYER_CREDIT") != resp.end()
		&& curr_state == DROPPING) {
			map_size.push_back(std::stoi (resp["x"], nullptr, 10));
			map_size.push_back(std::stoi (resp["y"], nullptr, 10));
			log_drop(resp, map_size, team_name);
			curr_state = SEARCHING;
			rt = true;
		} else if (resp.find("ko") != resp.end()) {
			std::cerr << "Error : reaching MAX PLAYER for team "
			<< team_name << "\n";
			exit(EXIT_MAX_PLAYER);
		}
		if (curr_state == SEARCHING) {
			std::vector<std::string> res = _client.look();
			_do_search(res, cnt);
			curr_state = MOOVING;
		}
		if (curr_state == MOOVING) {
			std::map<std::string, std::string> resp;
			resp = _client.forward();
			do_moove(_level);
			curr_state = cnt == 30 ? FORKING : SEARCHING;
		}
		if (curr_state == FORKING) {
			std::vector<std::string> resp;
			resp = _client.fork();
			_do_fork();
			curr_state = SEARCHING;
		}
		print_state(cnt, curr_state);
	}
	return (rt);
}
