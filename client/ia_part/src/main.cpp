//
// EPITECH PROJECT, 2018
// Communication
// File description:
// Communication between server and client
//

#include "../include/Trantorian.hpp"

void	usage(const char *progname)
{
	std::cerr << "USAGE: " << progname << " -p port -n name -h machine\n";
	std::cerr << "\tport\tis the port number\n";
	std::cerr << "\tname\tis the name of the team\n";
	std::cerr << "\tmachine\tis the name of the machine;";
	std::cerr << " localhost by default\n";
}

std::map<std::string, std::string>	get_opts(char **av)
{
	std::map<std::string, std::string> map;
	for (uint i = 1; av[i]; ++i) {
		map[av[i]] = av[i + 1] ? av[i + 1] : "";
	}
	return (map);
}

bool	check_opts(std::map<std::string, std::string> opts)
{
	bool rt = opts.find("-p") != opts.end()
	&& opts.find("-n") != opts.end()
	&& opts.find("-h") != opts.end() ? true : false;

	if (rt) {
		int port  = std::stoi(opts["-p"]);
		std::string team_name = opts["-n"];
		std::string server_host = opts["-h"];
		rt = port >= 1024 ? true : rt;
	}
	return (rt);
}

int	main(int ac, char **av)
{
	int rt = 84;

	if (ac >= 4) {
		std::map<std::string, std::string> opts = get_opts(av);
		bool check = check_opts(opts);
		if (check) {
			Trantorian ia_player(opts["-p"], opts["-h"]);
			check = ia_player.check_co();
			if (check) {
				ia_player.run(opts["-n"]);
			}
			rt = 0;
		} else {
			opts.clear();
			usage(av[0]);
		}

	} else
		usage(av[0]);
	return (rt);
}
