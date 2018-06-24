/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_cmd egg
*/

/* Provide the clifd of the player's user */
void *send_egg_lay(cmdargs args, int clifd, t_world *map);
{
	t_user *layer = find_user_in_teams(map->teams, clifd);

	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pfk %d\n", layer->refplayer->id);
		}
	}
	return map;
}

/* Provide the layer's clifd
** The layer must be on the same tile as the egg he just laid
*/
void *send_egg_laid(cmdargs args, int clifd, t_world *map);
{
	t_user *layer = find_user_in_teams(map->teams, clifd);
	int x = layer->refplayer->curr_pos[0];
	int y = layer->refplayer->curr_pos[1];
	t_tile *tile = map->tiles[x][y];
	t_egg *egg = find_egg_on_tile(tile, layer);

	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "enw %d %d %d %d\n",
				egg->id, layer->refplayer->id, x, y);
		}
	}
	return map;
}

void *send_egg_hatch(cmdargs args, int clifd, t_world *map)
{
	t_user *layer = find_user_in_teams(map->teams, clifd);
	t_egg *egg = find_egg_state(user, HATCHED);

	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "eht %d\n", egg->id);
		}
	}
	return map;
}

void *send_egg_death(cmdargs args, int clifd, t_world *map)
{
	t_user *layer = find_user_in_teams(map->teams, clifd);
	t_egg *egg = find_egg_state(user, DEAD);

	for (t_teams *tmpt = map->teams; tmpt; tmpt = tmpt->next) {
		for (t_userlist *tmpu = tmpt->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "eht %d\n", egg->id);
		}
	}
	return map;
}
