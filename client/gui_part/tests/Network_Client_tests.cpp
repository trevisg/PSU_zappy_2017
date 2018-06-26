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
	client.connect_to("127.0.0.1", "2222");
	std::vector<std::string> yolo = client.get_teamnames();
	for (uint i = 0; i <= yolo.size(); ++i) {
		std::cout << yolo[i] << std::endl;
	}
	return (0);
}
