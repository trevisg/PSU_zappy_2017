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

	/** X Y position */
	typedef enum	POS
	{
		X = 0,
		Y = 1
	}		POS;
	/** Orientation state of a t_inhabitant */
	typedef enum	ORIENTATION
	{
		N = 1,
		E = 2,
		S = 3,
		W = 4
	}		ORIENTATION;
	/** Evolution state of an egg */
	typedef enum	EGG_STATE
	{
		IN_PROCESS = 0,
		HATCHED = 1,
		DEAD = 2
	} 		EGG_STATE;
	/** For ITEMS access (improve usage and readability)
	* @note glob var ITEM can be accessed by ITEMS[FOOD] or ITEMS[PHIRAS]
	* @deprecated In fact this is useless as ITEMS is not a pointer
	*/
	typedef enum	ITEMS_NAMES {
		EMPTY = -1,
		FOOD = 0,
		DERAUMERE = 1,
		LINEMATE = 2,
		SIBUR = 3,
		MENDIANE = 4,
		PHIRAS = 5,
		THYSTAME = 6
	}	ITEMS_NAMES;
	/** The stone ressources needed by the trantorians
	* to do an incantation
	* @var t_stone::name
	* @brief The stone name
	* @var t_stone::qtt
	* @brief The stone quantity present on a world tile
	*/
	typedef struct		s_stone {
		char		name[MAX_STONE_NAME];
		unsigned int	qtt;
	}			t_stone;
	/** The food ressource needed by the trantorians
	* to subsist
	* @var t_food::name
	* @brief The food name ('eatme')
	* @var t_food::value
	* @brief The food energetic value (see FOOD_VALUE)
	*/
	typedef struct		s_food {
		char		name[MAX_FOOD_NAME];
		unsigned int	qtt;
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
		t_stone		deraumere;
	}			t_ressources;
	/* Egg  */
	typedef struct		s_egg {
		unsigned int	id;
		EGG_STATE	ev;
		unsigned int	id_droper;
		struct s_egg	*next;
		struct s_egg	*prev;
	}			t_egg;
	/** A typical Trantor inhabitant (also a game player)
	* @var t_inhabitant::o
	* @brief the current orientation of a player
	* @var t_inhabitant::id
	* @brief The unique player id
	* @var t_inhabitant::ttl
	* @brief The player TimeToLive (his life counter)
	* @var t_inhabitant::isco
	* @brief a boolean check for temp disconnections
	* @var t_inhabitant::level
	* @brief The incantation level (1->MAX_LEVEL)
	* @var t_inhabitant::inventory
	* @brief The player ressources inventory
	* @var t_inhabitant::curr_pos
	* @brief The current player position (x,y format)
	* @var t_inhabitant::team_name
	* @brief The trantorian team name
	* @var t_inhabitant::refuser
	* @brief The reference to the t_user associated
	*/
	typedef struct		s_inhabitant {
		ORIENTATION	o;
		unsigned int	id;
		double		ttl;
		unsigned int	isco;
		unsigned int	level;
		int		clifd;
		t_egg		*eggs;
		t_ressources	inventory;
		ITEMS_NAMES	just_drop;
		int		curr_pos[2];
		ITEMS_NAMES	just_collect;
		char		team_name[MAX_TEAM_NAME];
	}			t_inhabitant;
	/** The doubly linked list of connected users
	* @var t_userlist::user
	* @brief the trantorian player/user
	* @var t_userlist::prev
	* @brief the previous node in list
	* @var t_userlist::next
	* @brief the next node in list
	*/
	typedef struct                  s_userlist {
		t_inhabitant		*user;
		struct s_userlist       *prev;
		struct s_userlist       *next;
	}                               t_userlist;

	/** A doubly linked list of current teams with their users
	* @var t_teams::team_name
	* @brief a t_inhabitant team name
	* @var t_teams::users
	* @brief the t_inhabitant list in this team
	* @var t_teams::prev
	* @brief the previous node in list
	* @var t_teams::next
	* @brief the next node in list
	*/
	typedef struct                  s_teams {
		char                    *team_name;
		t_userlist              *users;
		struct s_teams          *prev;
		struct s_teams          *next;
	}                               t_teams;
	/** A world tile
	* @var t_tile::ressources
	* @brief The randomly generated ressource on a tile
	* @var t_tile::pos
	* @brief The x,y style coord for a particular tile
	*/
	typedef struct		s_tile {
		t_ressources	ressources;
		t_egg		*eggs;
		int		pos[2];
	}			t_tile;
	/** The Trantor world
	* @var t_world::tile
	* @brief The world consist off a 2d array of t_tile (s)
	* @var t_world::dim
	* @brief Dimensions of the world dim[X] & dim[Y]
	*/
	typedef struct		s_world {
		int		sizeX;
		int		sizeY;
		int             graphical_fd;
		t_teams		*teams;
		t_tile		**tiles;
	}			t_world;

	/** The items description / setting
	* @note See src/trantor_setup/ressources_decl.c
	*/
	extern t_ressources ITEMS;

#endif /* !ZAPPY_GAME_H_ */
