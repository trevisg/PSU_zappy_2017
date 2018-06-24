/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Send informations to client
*/

#ifndef CMD_FCTS_H_
# define CMD_FCTS_H_

	#include "server.h"

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

	#ifdef CMD_GUI
		/** see send_fcts/game.c */
	void		*send_game_end(cmdargs args, int clifd, t_world *map);
	void		*send_map_size(cmdargs args, int clifd, t_world *map);
	void		*send_map_content(cmdargs args, int clifd, t_world *map);
	void		*send_tile_content(cmdargs args, int clifd, t_world *map);
		/** see send_fcts/player.c */
	void		*send_player_join(cmdargs args, int clifd, t_world *map);
	void		*send_player_pos(cmdargs args, int clifd, t_world *map);
	void		*send_player_lv(cmdargs args, int clifd, t_world *map);
	void		*send_player_inv(cmdargs args, int clifd, t_world *map);
	void		*send_player_death(cmdargs args, int clifd, t_world *map);
		/** send_fcts/team.c */
	void		*send_player_from_egg(cmdargs args, int clifd, t_world *map);
	void		*send_team_names(cmdargs args, int clifd, t_world *map);
	void		*send_expulsion(cmdargs args, int clifd, t_world *map);
	void		*send_broadcast(cmdargs args, int clifd, t_world *map);
		/** see send_fcts/time.c */
	void		*send_inc_start(cmdargs args, int clifd, t_world *map);
	void		*send_inc_end(cmdargs args, int clifd, t_world *map);
	void		*send_time_unit(cmdargs args, int clifd, t_world *map);
	void		*send_time_modif(cmdargs args, int clifd, t_world *map);
		/** see send_fcts/egg.c */
	void		*send_egg_lay(cmdargs args, int clifd, t_world *map);
	void		*send_egg_laid(cmdargs args, int clifd, t_world *map);
	void		*send_egg_hatch(cmdargs args, int clifd, t_world *map);
	void		*send_egg_death(cmdargs args, int clifd, t_world *map);
		/**  see send_fcts/cmd.c */
	void		*send_res_drop(cmdargs args, int clifd, t_world *map);
	void		*send_res_collect(cmdargs args, int clifd, t_world *map);
	void		*send_msg(cmdargs args, int clifd, t_world *map);
	void		*send_cmd_unknow(cmdargs args, int clifd, t_world *map);
	void		*send_cmd_params(cmdargs args, int clifd, t_world *map);
		/** see send_fcts/find_list.c */
	t_user		*find_user_in_teams(t_teams *teams, int clifd);
	t_user		*find_player_by_id(t_teams *teams, unsigned int id);
	int		get_nbr_by_level(int level);
	t_egg		*find_egg_on_tile(t_tile *tile, t_user *layer);
	t_egg		*find_egg_state(t_user *user, EGG_STATE state);

	#endif /* !CMD_GUI */

#endif /* !CMD_FCTS_H_ */
