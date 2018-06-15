/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server header file
*/

#ifndef ZAPPY_GAME_H_
# define ZAPPY_GAME_H_

	#define MAX_STONE_NAME	9
	#define MAX_TEAM_NAME	200
	#define FOOD_VALUE	126

	typedef struct 	s_stone {
		char	name[MAX_STONE_NAME];
		int	qtt;
	}		t_stone;

	typedef struct		s_ressources {
		t_stone		sibur;
		t_stone		phiras;
		t_stone		mendiane;
		t_stone		thystame;
		t_stone		linemate;
		t_stone 	deraumere;
	}			t_ressources;

	typedef struct 		s_inhabitant {
		unsigned int 	id;
		float		ttl;
		unsigned int 	level;
		int 		curr_pos[2];
	}			t_inhabitant;

	typedef struct		s_team {
		char		team_name[MAX_TEAM_NAME];
		t_inhabitant	*members;
	}			t_tem;

	typedef struct		s_tile {
		t_ressources	ressources;
		t_inhabitant	trantorian;
		int 		pos[2];
	}			t_tile;

	typedef struct 		s_world {
		t_tile		tile;
	}			t_world;

	/** See @file server_src/stones_decl.c */
	extern volatile t_ressources STONES;

#endif /* !ZAPPY_GAME_H_ */
