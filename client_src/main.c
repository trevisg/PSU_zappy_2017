/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <ncurses.h>

void	write_separator()
{
	int i = 0;

	while (i < COLS) {
		move(LINES - 2, i);
		printw("_");
		i++;
	}
}

int main(int ac, char **av)
{
	initscr();
	write_separator();
	move(LINES -1,0);
	printw("message:");
	refresh();
	getch();
	endwin();
	return 0;
}
