//
// EPITECH PROJECT, 2018
// Communication
// File description:
// Communication between server and client
//

#ifndef TRANTORIAN_HPP_
# define TRANTORIAN_HPP_

#include <iostream>
#include <signal.h>
#include <string>
#include <map>
#include "../../commons/include/Network_Client.hpp"

/** The life a player */
#define TTL 126
/** If max player is reachedn, this is the exit code */
#define EXIT_MAX_PLAYER 84
/** No comment */
#define EVER ;;
/** Simple debugging trick to have one action per f second */
#define Frequency(f) sleep(f);

/** To get positions in int array or vector */
enum {
	X = 0,
	Y = 1
};

/** The AI states */
typedef enum  {
	DROPPING = 0,
	FORKING = 1,
	MOOVING = 2,
	SEARCHING = 3,
	PICKING_FOOD = 4,
	PICKING_STONE = 5
}	STATE;

/** The main AI class */
class Trantorian
{
	public:
		Trantorian(std::string server_port, std::string server_host);
		~Trantorian();
		bool	check_co();
		void 	_do_fork();
		void 	_do_moove();
		bool	_do_drop();
		bool	run(std::string team_name);
		void	_do_search(uint cnt);
	private:
		Network				_client;
		uint				_level;
		std::vector<int>		_map_size;
		std::string			_team_name;
		STATE 				_curr_state;
		std::string			_server_port;
		std::string			_server_host;
};

#endif /* !TRANTORIAN_HPP_ */
