//
// EPITECH PROJECT, 2018
// PSU_zappy_2017 Client GUI
// File description:
// Nework client test
//

#include "../include/Network_Client.hpp"

int main(void)
{
	Network client;
	client._connect_to("127.0.0.1", "2222");
	std::vector<std::string> yolo = client._get("teamnames");
	for (uint i = 0; i < yolo.size(); ++i) {
		std::cout << yolo[i] << std::endl;
	}
	std::map<std::string, int> yala = client._get_mapsize();
	std::cout << "map.x = " << yala["x"] << std::endl;
	std::cout << "map.y = " << yala["y"] << std::endl;
	std::vector<std::map<std::string, std::string> > players;
	std::map<std::string, std::string> yulu;
 	players = client._get_team_members(yolo[2]);
	for (uint i = 0; i < players.size(); ++i) {
		std::cerr << " id: " << players[i]["id"] << std::endl;
		std::cerr << " x: " << players[i]["x"] << std::endl;
		std::cerr << " y: " << players[i]["y"] << std::endl;
		std::cerr << " ttl: " << players[i]["ttl"] << std::endl;
	}
	return (0);
}
