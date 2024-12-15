#include "Statistic.h"



void Statistic::Display_Score() {
	wmove(stdscr, Field_height / 4, Field_width + 12);
	printw("SQUAD LIST:");
	wmove(stdscr, Field_height / 4 + 1, Field_width + 7);
	printw("ALLY REMAIN: ");
	if (Man_alive)
		printw("%d ", 1);
	else
		printw("%d ", 0);
	printw("ENEMY TEAM REMAIN : ");
	printw("%d", Amount_of_alive_enemy);
}