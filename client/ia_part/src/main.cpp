//
// EPITECH PROJECT, 2018
// Communication
// File description:
// Communication between server and client
//

#include "../include/Trantorian.hpp"

/** Dummy print usage function
* @param progname the programm name
*/
void	usage(const char *progname)
{
	std::cerr << "USAGE: " << progname << " -p port -n name -h machine\n";
	std::cerr << "\tport\tis the port number\n";
	std::cerr << "\tname\tis the name of the team\n";
	std::cerr << "\tmachine\tis the name of the machine;";
	std::cerr << " localhost by default\n";
}

/** Turn the 2D argv array to a key , value pairs map
* @param av the argv array from main()
* @return map a string key and string value map
*/
std::map<std::string, std::string>	get_opts(char **av)
{
	std::map<std::string, std::string> map;
	for (uint i = 1; av[i]; ++i) {
		map[av[i]] = av[i + 1] ? av[i + 1] : "";
	}
	return (map);
}

/** Check if all required flags are provided
* @param opts the map of flags and their values
* @return rt true if correct args, false otherwise
*/
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

/** The zappy_ai main entry point, check the args and run
* @param ac the number of av args
* @param av the arguments like -[flag] [value]
*/
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
