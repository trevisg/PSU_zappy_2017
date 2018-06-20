//
// EPITECH PROJECT, 2018
// communication
// File description:
// Communication header
//

#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "get_next_line.h"

/* Enum of all requests the client can do
*/
enum Commands {
	FORWARD		"Forward",
	RIGHT		"Right",
	LEFT		"Left",
	LOOK		"Look",
	INVENTORY	"Inventory",
	BROADCAST	"Broadcast text",
	CONNECT		"Connect_nbr",
	FORK		"Fork",
	EJECT		"Eject",
	TAKE		"Take object",
	SET		"Set object",
	INCANTATION	"Incantation",
	CHECKTILE	"bct"
};

/** Communication class. This class will handle the communication between
* The server and the client. It will first connect the cli to serv
*/
class Communication
{
public:
	Communication(int ac, char **av);
	~Communication();

	std::string getSrvMsg(void);
	int sendMsg(std::string msg);
	std::string getCliMsg(void);
	int sendCliMsg(std::string msg);
	void handleCmd(std::string srvMsg);
	PlayerView look(void);
	PlayerView getPlayerView(void);

private:
	int _clifd;
	int _srvfd;
	int _ac;
	char **_av;

	PlayerView _fov;
	Parser _parser;
};

#endif
