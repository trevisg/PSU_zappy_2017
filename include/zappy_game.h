/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** zappy_server header file
*/

#ifndef ZAPPY_GAME_H_
# define ZAPPY_GAME_H_

	/** For t_stone::name size */
	#define MAX_STONE_NAME	9
	/** For t_food::name size */
	#define MAX_FOOD_NAME	9
	/** To define to maximal elevation level after an incantation */
	#define MAX_LEVEL	8
	/** For t_team::team_name and t_clargs::teams_names sizes */
	#define MAX_TEAM_NAME	200
	/** "One unit of food allows them to live for 126 units of time." */
	#define FOOD_VALUE	126
	/** For ramdom generation of world ressources */
	#define MAX_RAND 5

	/** The stone ressources needed by the trantorians
	* to do an incantation
	* @var t_stone::name
	* @brief The stone name
	* @var t_stone::qtt
	* @brief The stone quantity present on a world tile
	*/
	typedef struct 	s_stone {
		char	name[MAX_STONE_NAME];
		int	qtt;
	}		t_stone;
	/** The food ressource needed by the trantorians
	* to subsist
	* @var t_food::name
	* @brief The food name ('eatme')
	* @var t_food::value
	* @brief The food energetic value (see FOOD_VALUE)
	*/
	typedef struct		s_food {
		char		name[MAX_FOOD_NAME];
		unsigned int 	qtt;
	}			t_food;
	/** All the differents ressources possible for a t_world::tiles
	* @var t_ressources::food
	* @brief A food unit
	* @var t_ressources::sibur
	* @brief The sibur kind of stone
	* @var t_ressources::phiras
	* @brief The phiras kind of stone
	* @var t_ressources::mendiane
	* @brief The mendiane kind of stone
	* @var t_ressources::thystame
	* @brief The thystame kind of stone
	* @var t_ressources::linemate
	* @brief The linemate kind of stone
	* @var t_ressources::deraumere
	* @brief The deraumere kind of stone
	*/
	typedef struct		s_ressources {
		t_food		food;
		t_stone		sibur;
		t_stone		phiras;
		t_stone		mendiane;
		t_stone		thystame;
		t_stone		linemate;
		t_stone 	deraumere;
	}			t_ressources;
	/** A typical Trantor inhabitant (also a game player)
	* @var t_inhabitant::id
	* @brief The unique player id
	* @var t_inhabitant::ttl
	* @brief The player TimeToLive (his life counter)
	* @var t_inhabitant::level
	* @brief The incantation level (1->MAX_LEVEL)
	* @var t_inhabitant::inventory
	* @brief The player ressources inventory
	* @var t_inhabitant::curr_pos
	* @brief The current player position (x,y format)
	* @var t_inhabitant::team_name
	* @brief The trantorian team name
	*/
	typedef struct 		s_inhabitant {
		unsigned int 	id;
		double		ttl;
		unsigned int 	level;
		t_ressources	inventory;
		int 		curr_pos[2];
		char		team_name[MAX_TEAM_NAME];
	}			t_inhabitant;
	/** A trantorian team
	* @var t_team::team_name
	* @brief The team name as defined in t_clargs struct
	* @var t_team::members
	* @brief The team members pointer
	*/
	typedef struct		s_team {
		char		team_name[MAX_TEAM_NAME];
		t_inhabitant	*members;
	}			t_team;
	/** A world tile
	* @var t_tile::ressources
	* @brief The randomly generated ressource on a tile
	* @var t_tile::trantorian
	* @brief Is there any trantorian(s) on a tile ?
	* @var t_tile::pos
	* @brief The x,y style coord for a particular tile
	*/
	typedef struct		s_tile {
		t_ressources	ressources;
		t_inhabitant	*trantorian;
		int 		pos[2];
	}			t_tile;
	/** The Trantor world
	* @var t_world::tile
	* @brief The world consist off a 2d array of t_tile (s)
	*/
	typedef struct 		s_world {
		t_tile		**tiles;
	}			t_world;

	/** For ITEMS access (improve usage and readability)
	* @note glob var ITEM can be accessed by ITEMS[FOOD] or ITEMS[PHIRAS]
	* @deprecated In fact this is useless as ITEMS is not a pointer
	*/
	enum	ITEMS_NAMES {
		FOOD = 0,
		SIBUR = 1,
		PHIRAS = 2,
		MENDIANE = 3,
		THYSTAME = 4,
		LINEMATE = 5,
		DERAUMERE = 6
	};
	/** The items description / setting
	* @note See server_src/trantor_setup/ressources_decl.c
	*/
	extern t_ressources ITEMS;

#endif /* !ZAPPY_GAME_H_ */
