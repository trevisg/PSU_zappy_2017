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

enum {
	X = 0,
	Y = 1
};

typedef enum  {
	DROPPING = 0,
	FORKING = 1,
	MOOVING = 2,
	SEARCHING = 3,
	PICKING_FOOD = 4,
	PICKING_STONE = 5
}	STATE;

class Trantorian
{
	public:
		Trantorian(std::string server_port, std::string server_host);
		~Trantorian();
		bool	check_co();
		void 	_do_fork();
		bool	run(std::string team_name);
		void	_do_search(std::vector<std::string>  res, uint cnt);
	private:
		Network				_client;
		uint					_level;
		std::string		_team_name;
		std::string		_server_port;
		std::string		_server_host;
};

#endif /* !TRANTORIAN_HPP_ */
