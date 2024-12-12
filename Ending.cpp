#include "Ending.h"

void Ending::Run() {
	
	int key;
	nodelay(stdscr, FALSE);
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
		wmove(stdscr, Field_height / 4 + 1, Field_width / 2-20);
		printw("Based on the test results: ");
		refresh();
		Sleep(50);
		switch (Choosed_one) {
		case 1:
			wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
			printw("You assigned to Commander of the assault squad and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 3, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a platoon commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 5, Field_width / 2-20);
			printw("You got evacuated and underwent a course of treatment");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("After all you retired with honor from the armed forces");
			refresh();
			Sleep(50);
			break;
		case 2:
			wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
			printw("You assigned to Commander of the assault platoon and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 3, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a soldiers company commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 5, Field_width / 2-20);
			printw("You got evacuated and underwent a course of treatment");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("After all you retired with honor from the armed forces");
			refresh();
			Sleep(50);
			break;
		case 3:
			wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
			printw("You assigned to Commander of the assault soildiers company and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 3, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a batalion commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 5, Field_width / 2-20);
			printw("You got evacuated and underwent a course of treatment");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
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
		wmove(stdscr, Field_height / 4 + 1, Field_width / 2-20);
		printw("Based on test results");
		refresh();
		Sleep(50);
		switch (Choosed_one) {
		case 1:
			printw(":");
			wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
			printw("You assigned to member of the assault squad and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 3, Field_width / 2-20);
			printw("You showed you as a good solder and over time become a squad commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 5, Field_width / 2-20);
			printw("You got evacuated but didnt manage to get to the hospital");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("And was buried in field cemetery");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 7, Field_width / 2-20);
			printw("Now only cross remains that was a one soldier who fullfired his duty");
			refresh();
			break;
		case 2:
			printw(" and taking into attention your experience and previous reachments: ");
			refresh();
			wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
			printw("You assigned to Commander of the assault squad and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 3, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a soldiers platoon commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 5, Field_width / 2-20);
			printw("You got evacuated but didnt manage to get to the hospital");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("And was buried in field cemetery");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 7, Field_width / 2-20);
			printw("Now only cross remains that was a one soldier who fullfired his duty");
			refresh();
			break;
		case 3:
			printw(" and taking into attention your experience and previous reachments: ");
			refresh();
			wmove(stdscr, Field_height / 4 + 2, Field_width / 2-20);
			printw("You assigned to Commander of the assault platoon and sent on a trip into one neighbour country");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 3, Field_width / 2-20);
			printw("You showed you as a good commander and over time become a soldiers company commander");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 4, Field_width / 2-20);
			printw("But one day you got wounded at night mission saving a subordinate during shelling");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 5, Field_width / 2-20);
			printw("You got evacuated but didnt manage to get to the hospital");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 6, Field_width / 2-20);
			printw("And was buried in field cemetery");
			refresh();
			Sleep(50);
			wmove(stdscr, Field_height / 4 + 7, Field_width / 2-20);
			printw("Now only cross remains that was a one soldier who fullfired his duty");
			refresh();
			break;

		}
	}
	wmove(stdscr, Field_height / 4 + 16, Field_width + 3);
	printw("If you wanna see some stats press SPACE");
	wmove(stdscr, Field_height / 4 + 17, Field_width + 3);
	printw("Otherwise press any other Key");
	refresh();
	Sleep(1000);
	nodelay(stdscr, TRUE);
	timeout(100000);
	key = getch();
	if (key == ' ')
		GameResults();
}