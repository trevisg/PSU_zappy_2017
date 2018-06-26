/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server time handlers functions
*/

#include <time.h>
#include "server.h"

/** Return time spent from begin to ttl
* @param begin the programm start count
* @param ttl the time to live
* @return time_spent the time spent
*/
double	get_time(clock_t begin, double ttl)
{
	double time_spent;

	for (EVER) {
		time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
		if (time_spent >= ttl)
			break;
	}
	return (time_spent);
}

#ifdef CLOCKTEST
int	main(void)
{
	clock_t begin = clock();

	printf("Done %0.2f seconds passed\n",
		get_time(begin, 5.0));
	return (0);
}
#endif
