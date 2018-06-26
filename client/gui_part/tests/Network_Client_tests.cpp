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
	while (client.listen_up()) {
		std::cout << "[" << client.get_lastbuffer() << "]\n";
	}
	return (0);
}
