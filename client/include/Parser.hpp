//
// EPITECH PROJECT, 2018
// Parser
// File description:
// Parser header
//

#ifndef PARSER_HPP
#define PARSER_HPP

#include "communication.hpp"
#include <vector>

/** This class is parsing the server output sent to the client                               * and set correct values int class like Player of Tile
*/

class Parser
{
public:
	Parser();
	~Parser();

	std::vector<int> getIntList(std::string srvMsg, int size)
	std::vector<int> playerConnect(std::string srvMsg);
	void setTile(Tile tile, std::string srvMsg);
	void setInv(Player player, std::string srvMsg);
	void setPlayerPos(Player player, std::string srvMsg);
	void setPlayerLvl(Player, std::string srvMsg);
	void setMapLimit(player player, std::string srvMsg);

private:

};

#endif
