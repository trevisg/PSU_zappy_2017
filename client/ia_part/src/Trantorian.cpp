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

static void	do_search(std::vector<std::string>  res,uint  cnt)
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

static void	do_fork()
{
	if (fork() == 0) {
		/// where in child
	} else {
		/// where back in parent
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

bool	Trantorian::run(std::string team_name)
{
	bool rt = false;
	static STATE curr_state;
	static uint cnt;
	std::vector<int> map_size;
	std::map<std::string, std::string> resp;

	for (EVER) {
		Frequency(1);
		cnt += 1;
		_team_name = team_name;
		resp = cnt == 1 ?  _client.get_map_dimension(_team_name) : resp;
		curr_state = cnt == 1 ? DROPPING : curr_state;
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
			do_search(res, cnt);
			curr_state = MOOVING;
		}
		if (curr_state == MOOVING) {
			std::map<std::string, std::string> resp;
			resp = _client.forward();
			do_moove(_level);
			curr_state = SEARCHING;
		}
		if (curr_state == FORKING) {
			std::vector<std::string> resp;
			resp = _client.fork();
			do_fork();
			curr_state = SEARCHING;
		}
		std::cerr << "TimeTolive: " << TTL - cnt << "s\n";
	}
	return (rt);
}
