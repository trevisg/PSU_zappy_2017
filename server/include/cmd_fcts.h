/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Send informations to client
*/

#ifndef CMD_FCTS_H_
# define CMD_FCTS_H_

	#include "server.h"

	/** IA <--> Server part */
	/** see send_fcts/motion.c */
	void		*r_forward(cmdargs args, int clifd, t_world *map);
	void		*r_right(cmdargs args, int clifd, t_world *map);
	void		*r_left(cmdargs args, int clifd, t_world *map);
	void		*r_inventory(cmdargs args, int clifd, t_world *map);
	/** see send_fcts/broadcast.c */
	void		*r_team(cmdargs args, int clifd, t_world *map);
	void		*r_broadcast(cmdargs args, int clifd, t_world *map);
	void		*r_connect_nbr(cmdargs args, int clifd, t_world *map);
	void		*r_take_obj(cmdargs args, int clifd, t_world *map);
	void		*r_set_obj(cmdargs args, int clifd, t_world *map);

	/** see send_fcts/utils.c */
	void		move(t_inhabitant *player, t_world *map);
	int		assign_player(char *team_name, t_teams *teams, int clifd);
	int		count_nb_empty(t_teams *teams, char *team_name);
	void		*add_obj_to_player(t_inhabitant *player, char *obj_name);
	int		check_obj_on_map(t_world *map, int x, int y, char *obj_name);
	/** see send_fcts/utils2.c */
	void		*del_obj_on_map(t_world *map, int x, int y, char *obj_name);
	int		check_obj_in_inv(t_inhabitant *player, char *obj_name);
	void		*del_obj_from_player(t_inhabitant *player, char *obj_name);
	void		*add_obj_to_map(t_world *map, int x, int y, char *obj_name);

	/* send_fcts/find_list.c */
	t_inhabitant	*find_player_by_fd(t_teams *teams, int clifd);

	/** Graphical client <--> Server part */
	void		*g_mapsize(char **args, int clifd, t_world *map);
	void		*g_teams_names(char **args, int clifd, t_world *map);
	void		*g_team_detail(char **args, int clifd, t_world *map);

#endif /* !CMD_FCTS_H_ */
