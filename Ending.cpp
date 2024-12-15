#include "Ending.h"



void Ending::Game_Results(GameObjects::Statistic &statistic) {
	flushinp();
	clear();
	wmove(stdscr, Field_height / 4 + 1, Field_width / 2 - 4);
	refresh();

	wmove(stdscr, Field_height / 4 + 3, Field_width / 2 - 4);
	printw("Here is some stats: ");
	refresh();
	Sleep(50);
	wmove(stdscr, Field_height / 4 + 5, Field_width / 2 - 4);
	printw("Amount of alived people: ");
	refresh();
	Sleep(50);
	printw(" %d", statistic.Man_alive + statistic.Amount_of_alive_enemy);
	refresh();
	Sleep(50);
	wmove(stdscr, Field_height / 4 + 7, Field_width / 2 - 4);
	printw("Amount of killed people: ");
	printw(" %d", 2 - statistic.Amount_of_alive_enemy + 1 - statistic.Man_alive);
	refresh();
	Sleep(50);
	wmove(stdscr, Field_height / 4 + 9, Field_width / 2 - 4);
	printw("Amount of injured people: ");
	refresh();
	Sleep(50);
	printw(" %d", statistic.Amount_of_injured_people);
	refresh();
	Sleep(50);
	wmove(stdscr, Field_height / 4 + 11, Field_width / 2 - 4);
	printw("Amount of ammos fired: ");
	refresh();
	Sleep(50);
	printw(" %d", statistic.Amount_of_bullets);
	refresh();

	wmove(stdscr, Field_height / 4 + 20, Field_width / 4 + 35);
	printw("If you wanna escape press 'J'");
	Create_Rectangle(Field_width / 4 + 35 - 1, Field_height / 4 + 20 - 1, strlen("If you wanna escape press 'J'") + 2, 3, 1);
	timeout(50);
	int key;
	while (true) {
		refresh();
		key = getch();
		if ((key == 'j') || (key == 'J'))
			break;
	}
	endwin();
}

void Ending::Create_Rectangle(int x, int y, int width, int height, bool is_not_empty) {
	const char** str = new (const char* [2]);
	if (is_not_empty == 1) {
		str[0] = "-";
		str[1] = "|";
	}
	else {
		str[0] = " ";
		str[1] = " ";
	}
	for (int index_x = 0; index_x < width; index_x++) {
		wmove(stdscr, y, x + index_x);
		printw(str[0]);
		wmove(stdscr, y + height - 1, x + index_x);
		printw(str[0]);
	}
	for (int index_y = 0; index_y < height; index_y++) {
		wmove(stdscr, y + index_y, x);
		printw(str[1]);
		wmove(stdscr, y + index_y, x + width - 1);
		printw(str[1]);
	}
}

void Ending::Run(GameObjects::Statistic &statistic) {
	int key;
	if (statistic.Man_alive == 1)
		statistic.Win = 1;
	else
		statistic.Win = 0;
	clear();
	if (statistic.Win == 1) {
		clear();
		wmove(stdscr, Field_height / 4, Field_width / 2-20);
		printw("You are accomplished this mission");
		refresh();
		Sleep(50);
		wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
		printw("Based on the test results: ");
		refresh();
		Sleep(50);
		switch (statistic.Choosed_one) {
		case 1:
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("You assigned to Commander of the assault squad and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a platoon commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 8, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 10, Field_width / 2-20);
			printw("You got evacuated and underwent a course of treatment");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 12, Field_width / 2-20);
			printw("After all you retired with honor from the armed forces");
			refresh();
			Sleep(50);
			break;
		case 2:
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("You assigned to Commander of the assault platoon and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a soldiers company commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 8, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 10, Field_width / 2-20);
			printw("You got evacuated and underwent a course of treatment");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 12, Field_width / 2-20);
			printw("After all you retired with honor from the armed forces");
			refresh();
			Sleep(50);
			break;
		case 3:
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("You assigned to Commander of the assault soildiers company and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a batalion commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 8, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 10, Field_width / 2-20);
			printw("You got evacuated and underwent a course of treatment");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 12, Field_width / 2-20);
			printw("After all you retired with honor from the armed forces");
			refresh();
			Sleep(50);


		}
	}
	else {
		clear();
		wmove(stdscr, Field_height / 4, Field_width / 2-20);
		printw("You are failed your first mission");
		refresh();
		Sleep(50);
		wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
		printw("Based on test results");
		refresh();
		Sleep(50);
		switch (statistic.Choosed_one) {
		case 1:
			printw(":");
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("You assigned to member of the assault squad and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("You showed you as a good solder and over time become a squad commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 8, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 10, Field_width / 2-20);
			printw("You got evacuated but didnt manage to get to the hospital");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 12, Field_width / 2-20);
			printw("And was buried in field cemetery");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 14, Field_width / 2-20);
			printw("Now only cross remains that was a one soldier who fullfired his duty");
			refresh();
			break;
		case 2:
			printw(" and taking into attention your experience and previous reachments: ");
			refresh();
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("You assigned to Commander of the assault squad and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a soldiers platoon commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 8, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 10, Field_width / 2-20);
			printw("You got evacuated but didnt manage to get to the hospital");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 12, Field_width / 2-20);
			printw("And was buried in field cemetery");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 14, Field_width / 2-20);
			printw("Now only cross remains that was a one soldier who fullfired his duty");
			refresh();
			break;
		case 3:
			printw(" and taking into attention your experience and previous reachments: ");
			refresh();
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("You assigned to Commander of the assault platoon and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a soldiers company commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 8, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 10, Field_width / 2-20);
			printw("You got evacuated but didnt manage to get to the hospital");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 12, Field_width / 2-20);
			printw("And was buried in field cemetery");
			refresh();
			wmove(stdscr, Field_height / 4 + 14, Field_width / 2 - 20);
			printw("Now only cross remains that was a soldier who fullfired his duty");
			Sleep(50);
			break;

		}
	}
	timeout(50);
	refresh();
	wmove(stdscr, Field_height / 4 + 20, Field_width / 2 + 40);
	printw("If you wanna escape press 'J'");
	Create_Rectangle(Field_width / 2 + 40 - 1, Field_height / 4 + 20 - 1, strlen("If you wanna escape press 'J'") + 2, 3, 1);
	while (true) {
		refresh();
		key = getch();
		if ((key == 'j') || (key == 'J'))
			break;
	}
	Game_Results(statistic);
}