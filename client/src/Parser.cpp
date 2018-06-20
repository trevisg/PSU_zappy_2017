//
// EPITECH PROJECT, 2018
// Parser
// File description:
// Command Parser
//

#include "Parser.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}


/** Get the number (set in param) of integers of the string srvMsg
* @param size the number of int to put in the vector
*/
std::vector<int> Parser::getIntList(std::string srvMsg, int size)
{
	std::vector<int> infos;
	std::string tmp;
	int i = 4;
	int j;

	while (infos.size() <= size) {
		j = 0;
		while (srvMsg[i] != ' ') {
			tmp[j++] = srvMsg[i++];
		}
		infos.push_back(atoi(tmp.c_str()));
		i++;
		tmp.clear();
	}
	return (infos);
}

/** Connecting a client to the server, that create a player
* @param srvMsg the message of server that content player pos, nb etc
* @return player modified with good values
*/
Player Parser::playerConnect(std::string srvMsg)
{
	Player player;
	std::vector<int> infos;
	std::string tmp;
	int i = srvMsg.size();
	int j;

	infos = getIntList(srvMsg, 5);
	while (srvMsg[i] != ' ') {
		i--;
	}
	while (srvMsg[i] != '\0') {
		tmp[j++] = srvMsg[i++];
	}
	player.setNumber(infos[0]);
	player.pos.setX(infos[1]);
	player.pos.setY(infos[2]);
	player.setOrientation(infos[3]);
	player.setLvl(infos[4]);
	player.setTeam(tmp);
	return (player);
}

/** Set position of tile
* @param tile the Tile that we want to set position
* @param srvMsg server message with tile pos
*/
void Parser::setTile(Tile tile, std::string srvMsg)
{
	std::vector<int> infos = getIntList(srvMsg, 9);

	tile.pos.setX(infos[0]);
	tile.pos.setY(infos[1]);
}

/** Set the inventory of player passed as parameters
* @param player the player we want to manipulate (inventory)
* @param srvMsg server message with inventory informations
*/
void Parser::setInv(Player player, std::string srvMsg)
{
	std::vector<int> infos = getIntList(srvMsg, 10);
	std::vector<int> inv;
	int i = 3;

	if (infos[0] == player.getNumber()) {
		while (i <= infos.size()) {
			inv.push_back(infos[i++]);
		}
		player.setInv(inv);
	}
}

/** Set the player's position passed as parameters
* @param player the player we want to manipulate (postion)
* @param srvMsg server message with position informations
*/
void Parser::setPlayerPos(Player player, std::string srvMsg)
{
	std::vector<int> infos = getIntList(srvMsg, 4);

	if (player.getNumber() == infos[0]) {
		player.pos.setX(infos[1]);
		player.pos.setY(infos[2]);
		player.pos.setOrientation(infos[3]);
	}
}

/** Set the player's level passed as parameters
* @param player the player we want to manipulate (level)
* @param srvMsg server message with level informations
*/
void Parser::setPlayerLvl(Player player, std::string srvMsg)
{
	std::vector<int> infos = getIntList(srvMsg, 2);

	if (player.getNumber() == infos[0])
		player.setLvl(infos[1]);
}

/** Get the map's limit
* @param player the player we want to manipulate (x max, y max)
* @param srvMsg server message with limits informations
*/
void Parser::setMapLimit(Player player, std::string srvMsg)
{
	std::vector<int> infos = getIntList(srvMsg, 2);

	player.setMaxX(infos[0]);
	player.setMaxY(infos[1]);
}

/** Transform the string returned by server as vector of Tile
* @param srvMsg server message with tiles informations
*/
std::vector<Tile> Parser::getLookInfo(std::string srvMsg)
{
	std::vector<Tile> tileList;
	int nbTile = 0;
	int i = 0;
	int j = 0;

	while (srvMsg[i] != '\0') {
		if (srvMsg[i] == ',') {
			nbTile++;
		}
	}
}
