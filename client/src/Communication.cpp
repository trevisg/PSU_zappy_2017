//
// EPITECH PROJECT, 2018
// Communication
// File description:
// Communication between server and client
//

#include "Communication.hpp"

Communication::Communication(int ac, char **av) : _ac(ac), _av(av)
{
}

Communication::~Communication()
{

}

/** This function will initialize the connection between
* client and server. It will set correct values to player too
* @param player it returns the player with correct values (pos, lvl, etc)
*/
Player Communication::initConnection(Player player)
{
	std::vector<int>  infos;

	_clifd = server_connect(_av[1], atoi(_av[2]));
	player = _parser.playerConnect(getSrvMsg());
	return (player);
}

/** This function read the server output
*/
std::string Communication::getSrvMsg(void)
{
	std::string msg
	char buffer[1024];

	if (read(_clifd, buffer, 1024) != -1)
		msg = buffer;
	return (msg);
}

/** This function send cli info to srv
*/
int Communication::sendSrvMsg(std::string msg)
{
	return (dprintf(_clifd, "%s\n", msg.c_str()));
}

/** This function read on client output
*/
std::string Communication::getCliMsg(void)
{
	std::string msg;
	char buffer[1024];

	if (read(0, buffer, 1024)) {
		msg = buffer;
	}
	return (msg);
}

/* This function write on client
*/
int Communication::sendCliMsg(std::string msg)
{
	return (dprintf(0, "%s\n", msg.c_str()));
}

void Communication::handleCmd(std::string srvMsg)
{
	switch (srvMsg)
	{
	case FORWARD:

		break;
	case RIGHT:

		break;
	case LEFT:

		break;
	case LOOK:

		break;
	case INVENTORY:

		break;
	case BROADCAST:

		break;
	case CONNECT:

		break;
	case FORK:

		break;
	case EJECT:

		break;
	case TAKE:

		break;
	case SET:

		break;
	case INCANTATION:

		break;
	case CHECKTILE:

		break;
	}
}

PlayerView Communication::getPlayerView() {
	return (_fov);
}

PlayerView Communication::Look()
{

}
