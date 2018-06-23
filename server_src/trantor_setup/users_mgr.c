/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** users manager
*/

#include "server.h"

void get_first_inventory(t_ressources *inv)
{
	if (inv) {
		memcpy(inv, &ITEMS, sizeof(ITEMS));
		inv->food.qtt = 9;
	}
}

t_inhabitant *new_user(int id, int sizeX, int sizeY, char *teamname)
{
	t_inhabitant *new_usr = malloc(sizeof(*new_usr));

	if (new_usr) {
		memset(new_usr, 0, sizeof(*new_usr));
		new_usr->clifd = 0;
		new_usr->isco = 0;
		new_usr->id = id;
		new_usr->ttl = 126.0f;
		new_usr->level = 1;
		get_first_inventory(&new_usr->inventory);
		new_usr->curr_pos[0] = rand()%(sizeX-0)+0;
		new_usr->curr_pos[1] = rand()%(sizeY-0)+0;
		strcpy(new_usr->team_name, teamname);
		new_usr->o = rand()%(4-1)+1;
		new_usr->just_drop = EMPTY;
		new_usr->just_collect = EMPTY;
		new_usr->eggs = NULL;
	}
	return new_usr;
}

t_userlist *add_userlist(int id, t_clargs *args, char *team_name, t_userlist *head)
{
	t_userlist *new_node = malloc(sizeof(*new_node));
	
	new_node->user = new_user(id, args->width, args->height, team_name);
	if (!head) {
		new_node->next = NULL;
		new_node->prev = NULL;
	} else {
		new_node->prev = head;
		new_node->next = NULL;
		head->next = new_node;
	}
	return new_node;
}

t_userlist *new_userlist(int nb_players, t_clargs *args, char *team_name)
{
	t_userlist *new_list = NULL;
	new_list = add_userlist(0, args, team_name, new_list);
	
	for (int i = 1; i < nb_players; i++) {
		new_list = add_userlist(i, args, team_name, new_list);
	}
	while (new_list->prev)
		new_list = new_list->prev;
	return new_list;
}

t_teams *init_userlist(t_teams *teams, t_clargs *args)
{
	t_teams *tmpt;

	srand(time(NULL));
	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		tmpt->users = new_userlist(args->clientsNb, args, tmpt->team_name);
	}
	return teams;
}
