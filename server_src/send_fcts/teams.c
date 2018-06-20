/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** send_cmd team
*/

/* Provide the new player's clifd */
void *send_player_from_egg(cmdargs args, int clifd, t_teams *teams)
{
	t_teams *tmpt;
	t_userlist *tmpu;

	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		for (tmpu = teams->users; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "ebo %d\n",
				tmpu->user->refplayer->origin->id);
		}
	}
	return teams;
}

/* Provide clifd of the requester */
void *send_team_names(cmdargs args, int clifd, t_teams *teams)
{
	t_teams *tmp;
	char *msg = strdup("tna ");
	char *ret = strdup("\n");
	char *answer = malloc(teams->refmap->nbr_teams * MAX_TEAM_NAME);

	for (tmp = teams; tmp; tmp = tmp->next) {
		answer = strcat(answer, msg);
		answer = strcat(answer, tmp->team_name);
		answer = strcat(answer, ret);
	}
	dprintf(clifd, answer);
	free(msg);
	free(ret);
	free(answer);
	return teams;
}

/* Provide the clifd of the expelled player */
void *send_expulsion(cmdargs args, int clifd, t_teams *teams)
{
	t_teams *tmpt;
	t_userlist *tmpu;
	t_user *user = find_user_in_teams(teams, clifd);

	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		for (tmpu = teams->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pex %d\n",
				tmpu->user->refplayer->id);
		}
	}
}

/* Provide fd of sender & message of sender in (cmdargs)args */
void *send_broadcast(cmdargs args, int clifd, t_teams *teams)
{
	t_teams *tmpt;
	t_userlist *tmpu;
	t_user *sender = find_user_in_teams(teams, clifd);

	for (tmpt = teams; tmpt; tmpt = tmpt->next) {
		for (tmpu = teams->users; tmpu; tmpu = tmpu->next) {
			dprintf(tmpu->user->clifd, "pbc %d %s\n",
				tmpu->user->refplayer->id, args[0]);
		}
	}
}
