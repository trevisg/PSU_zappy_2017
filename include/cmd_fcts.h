/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Send informations to client
*/

#include "server.h"
#include "zappy_game.h"

/* send_fcts/game.c*/
void *send_game_end(cmdargs args, int clifd, t_teams *teams);
void *send_map_size(cmdargs args, int clifd, t_teams *teams);
void *send_map_content(cmdargs args, int clifd, t_teams *teams);
void *send_tile_content(cmdargs args, int clifd, t_teams *teams);

/* send_fcts/player.c */
void *send_player_join(cmdargs args, int clifd, t_teams *teams);
void *send_player_pos(cmdargs args, int clifd, t_teams *teams);
void *send_player_lv(cmdargs args, int clifd, t_teams *teams);
void *send_player_inv(cmdargs args, int clifd, t_teams *teams);
void *send_player_death(cmdargs args, int clifd, t_teams *teams);

/* send_fcts/team.c */
void *send_player_from_egg(cmdargs args, int clifd, t_teams *teams);
void *send_team_names(cmdargs args, int clifd, t_teams *teams);
void *send_expulsion(cmdargs args, int clifd, t_teams *teams);
void *send_broadcast(cmdargs args, int clifd, t_teams *teams);

/* send_fcts/time.c */
void *send_inc_start(cmdargs args, int clifd, t_teams *teams);
void *send_inc_end(cmdargs args, int clifd, t_teams *teams);
void *send_time_unit(cmdargs args, int clifd, t_teams *teams);
void *send_time_modif(cmdargs args, int clifd, t_teams *teams);

/* send_fcts/egg.c */
void *send_egg_lay(cmdargs args, int clifd, t_teams *teams);
void *send_egg_laid(cmdargs args, int clifd, t_teams *teams);
void *send_egg_hatch(cmdargs args, int clifd, t_teams *teams);
void *send_egg_death(cmdargs args, int clifd, t_teams *teams);

/* send_fcts/cmd.c */
void *send_res_drop(cmdargs args, int clifd, t_teams *teams);
void *send_res_collect(cmdargs args, int clifd, t_teams *teams);
void *send_msg(cmdargs args, int clifd, t_teams *teams);
void *send_cmd_unknow(cmdargs args, int clifd, t_teams *teams);
void *send_cmd_params(cmdargs args, int clifd, t_teams *teams);

/* send_fcts/find_list.c */
t_user *find_user_in_teams(t_teams *teams, int clifd);
t_user *find_player_by_id(t_teams *teams, int id)
int get_nbr_by_level(int level);
t_egg *find_egg_on_tile(t_tile *tile, t_user *layer);
t_egg *find_hatched_egg(t_user *user);
