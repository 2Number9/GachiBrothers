#pragma once
#include "GamePlay.h"

class Statistic {
public:
	
	Statistic() = default;
	
	~Statistic() = default;

	std::vector<int> Coordinats_of_man;
	
	bool Man_alive;

	int Amount_of_alive_enemy;

	int Amount_of_bullets;

	int Amount_of_injured_people;

	int Choosed_one;

	int Win;

	void Display_Score() {
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
	};
};