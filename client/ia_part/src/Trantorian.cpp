//
// EPITECH PROJECT, 2018
// Communication
// File description:
// Main AI methods container methods
//

#include "../include/Trantorian.hpp"

/** The AI constructor
* @param server_port the zappy_server port
* @param server_host the zappy_server address
*/
Trantorian::Trantorian(std::string server_port, std::string server_host) :
_server_port(server_port), _server_host(server_host)
{
	_level = 1;
}

Trantorian::~Trantorian()
{

}

/** Utility function around the Trantorian::_client connect_to method
* @return true if connection succedded
* @return false if not
*/
bool	Trantorian::check_co()
{
	bool rt = false;
	rt = _client.connect_to(_server_host, _server_port);
	return (rt);
}

/** Utility function to print the current AI STATE and the TimeTolive value
* @param cnt the time(aka life) counter
* @param value the current ai STATE value
*/
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

/** Utility function to log a new ai player loading and connection
* @param resp the response from server containing the map size and the
* number of players from the team leaving to be connected
* @param map_size 0 x pos, 1 y pos
* @param team_name the current ai player team name
*/
void 	log_drop( std::map<std::string, std::string> resp,
		std::vector<int> map_size, std::string team_name)
{
	std::cout << "Finished drop on this " << map_size[X]
	<< "*" << map_size[Y] << " map\n";
	std::cout << "Note : Still have ["
	<< resp["PLAYER_CREDIT"] << "] trantorians to drop "
	<< "for team [\"" << team_name << "\"]\n";
}

/** The DROPPING state method , send `Teams [teamname]` command to server
* and parse response. Exit if MAX_PLAYER per team value is reached
*/
bool	Trantorian::_do_drop()
{
	bool rt = false;
	std::map<std::string, std::string> resp;

	resp = _client._teams(_team_name);
	if (resp.find("x") != resp.end()
	&& resp.find("y") != resp.end()
	&& resp.find("PLAYER_CREDIT") != resp.end()) {
		_map_size.push_back(std::stoi (resp["x"], nullptr, 10));
		_map_size.push_back(std::stoi (resp["y"], nullptr, 10));
		log_drop(resp, _map_size, _team_name);
		rt = true;
	} else if (resp.find("ko") != resp.end()) {
		std::cerr << "Error : reaching MAX PLAYER for team "
		<< _team_name << "\n";
		exit(EXIT_MAX_PLAYER);
	}
	return (rt);
}

/** The SEARCHING state method, send `Look` command to server and (not yet)
* parse the response
*/
void	Trantorian::_do_search(uint cnt)
{
	std::vector<std::string> res = _client._look();
	std::cerr << "state : " << "SEARCHING\n";
	std::cerr << "send -->_look \n";
	std::cerr << "Receive :\n";
	for (uint i = 0; i != res.size(); ++i) {
		std::cerr << "[" << res[i] << "]\n";
	}
	if (cnt >= TTL) {
		std::cerr << "No more life exiting..\n";
		kill(getpid(), SIGINT);
	}
}

/** The SEARCHING state method, send `Fork` command to server and if server
* respond `ok`, call _fork() and launch a new Trantorian teammate in the child
* process
*/
void	Trantorian::_do_fork()
{
	static uint childs;
	std::vector<std::string> resp;

	childs += 1;
	resp = _client._fork();
	if (fork() == 0) {
		std::cerr << " Where in child n°" << childs << '\n';
		Trantorian ia_player(_server_port, _server_host);
		bool check = ia_player.check_co();
		if (check) {
			ia_player.run(_team_name);
		}
	}
}

void	Trantorian::_do_moove()
{
	std::map<std::string, std::string> resp;

	std::cerr << "state : " << "MOOVING\n";
	std::cerr << "Send _forward on trantor map \n";
	std::cerr << "Note : we're still on level [";
	std::cerr << _level << "]\n";
	resp = _client._forward();
	std::cerr << "send -->_forward \n";
}

/** The main AI event loop
* @param team_name the new Trantorian team name
* @note this stupid AI do only one thing, _forward,
* _forward and _forward again until death
*/
bool	Trantorian::run(std::string team_name)
{
	bool rt = false;
	static uint cnt = 0;

	_curr_state = DROPPING;
	_team_name = team_name;
	for (EVER) {
		Frequency(1);
		switch (_curr_state) {
			case DROPPING:
				rt = _do_drop();
				_curr_state = SEARCHING;
			break;
			case SEARCHING:
				_do_search(cnt);
				_curr_state = MOOVING;
			break;
			case MOOVING:
				_do_moove();
				_curr_state = cnt == 30 ? FORKING : SEARCHING;
			break;
			case FORKING:
				_do_fork();
				_curr_state = SEARCHING;
			break;
			case PICKING_FOOD:
			break;
			case PICKING_STONE:
			break;
		}
		++cnt;
		print_state(cnt, _curr_state);
	}
	return (rt);
}
