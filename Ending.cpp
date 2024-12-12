#include "Ending.h"

void Ending::Run() {
	int key;
	if (Man_alive == 1)
		Win = 1;
	else
		Win = 0;
	clear();
	if (Win == 1) {
		clear();
		wmove(stdscr, Field_height / 4, Field_width / 2-20);
		printw("You are accomplished this mission");
		refresh();
		Sleep(50);
		wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
		printw("Based on the test results: ");
		refresh();
		Sleep(50);
		switch (Choosed_one) {
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
		switch (Choosed_one) {
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
	CreateRectangle(Field_width / 2 + 40 - 1, Field_height / 4 + 20 - 1, strlen("If you wanna escape press 'J'") + 2, 3, 1);
	while (true) {
		refresh();
		key = getch();
		if ((key == 'j') || (key == 'J'))
			break;
	}
	GameResults();
}