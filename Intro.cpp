#include "Intro.h"

void Intro::Init_of_window() {
	initscr();

	cbreak(); //отключает буфуризацию строк и обратортку символов, делает вводимые пользователем символы сразу доступными для программы

	noecho(); //отключает отображение вводимых символов на экран

	curs_set(FALSE); //делает пользовательский курсор невидимым

	keypad(stdscr, TRUE); //для данного окна stdscr включается простой режим работы с функциональными клавишами (F1, F2, ...)

	timeout(25); //устанавливает время ожидания для getch(), wgetch() для ввода символа

	int h1;
	int w1;

	getmaxyx(stdscr, h1, w1);

}



int Intro::Play_Slide() {
	const char** strs = new (const char* [4]);
	strs[0] = "Choose your rank: ";
	strs[1] = "Private";
	strs[2] = "Sergant";
	strs[3] = "Officer";
	int start_x = Field_width / 2 - 3 - 1;
	int start_y = Field_height / 4 + 3 - 1;
	int current = 0;
	int offset = 0;
	int key;
	//you died on a field of honour
	timeout(100000);
	while (true) {
		wmove(stdscr, Field_height / 4, Field_width / 2 - 3);
		printw(strs[0]);
		//CreateRectangle(Field_width / 2 - 3 - 1, Field_height / 4 - 1, strlen(str) + 2, 3);
		wmove(stdscr, Field_height / 4 + 3, Field_width / 2 - 3);
		printw(strs[1]);
		//create empty rectangle
		wmove(stdscr, Field_height / 4 + 6, Field_width / 2 - 3);
		printw(strs[2]);
		wmove(stdscr, Field_height / 4 + 9, Field_width / 2 - 3);
		printw(strs[3]);
		CreateRectangle(start_x, start_y + offset * 3, strlen(strs[current]) + 2, 3, 1);
		//im old but im still remember how to keep gun in my arms
		//so you say
		refresh();
		key = getch();
		if (((key == 's') || (key == 'S')) && (offset < 2)) {
			CreateRectangle(start_x, start_y + offset * 3, strlen(strs[current]) + 2, 3, 0);
			offset++;
			current++;
		}
		else
			if (((key == 'w') || (key == 'W')) && (offset > 0)) {
				CreateRectangle(start_x, start_y + offset * 3, strlen(strs[current]) + 2, 3, 0);
				offset--;
				current--;
			}
			else
				if (key == ' ') {
					return offset+1;
				}

		Sleep(50);
		if (key == ' ')
			break;
	}
}

void Intro::Play_Obuchenie() {
	char* str;
	int key;
	clear();
	while (true) {
		wmove(stdscr, Field_height / 4, Field_width / 2);
		printw("So you are in battlefield");
		wmove(stdscr, Field_height / 4 + 1, Field_width / 2);
		printw("It depends on your decision speed that you will live another second.");
		wmove(stdscr, Field_height / 4 + 2, Field_width / 2);
		printw("So this is some keys that will prove it to you: ");
		wmove(stdscr, Field_height / 4 + 3, Field_width / 2);
		printw("Moving keys:");
		wmove(stdscr, Field_height / 4 + 5, Field_width / 2 + 8);
		printw("W");
		wmove(stdscr, Field_height / 4 + 7, Field_width / 2 + 4);
		printw("A");
		wmove(stdscr, Field_height / 4 + 7, Field_width / 2 + 8);
		printw("S");
		wmove(stdscr, Field_height / 4 + 7, Field_width / 2 + 12);
		printw("D");
		wmove(stdscr, Field_height / 4 + 9, Field_width / 2);
		printw("Shooting key:");
		wmove(stdscr, Field_height / 4 + 11, Field_width / 2 + 4);
		printw("SPACE");
		wmove(stdscr, Field_height / 4 + 14, Field_width / 2 + 24);
		str = "If you are ready to test yourself, press SPACE key";
		printw(str);
		CreateRectangle(Field_width / 2 + 24 - 1, Field_height / 4 + 14 - 1, strlen(str) + 2, 3, 1);
		refresh();
		key = getch();
		if (key == ' ')
			break;
		Sleep(50);
	}
}

void Intro::TalkToSergant() {
	const char** str = new (const char* [11]);
	int key;
	str[0] = "Instructor: I respect your experience but even best people may forget some basic things";
	str[1] = "Sergant: Man! I said you I know all things better than you";
	str[2] = "Instructor: Excellent! Let me to ask you a few questions and I will let you out";
	str[3] = "Sergant: Whatever";
	str[4] = "Instructor: Soo which key proves you to move up?";
	str[5] = "Sergant: I know it..Im playing computer games since CS 1.6 was born.";
	str[6] = "This is 'S' Key Actually!";
	str[7] = "Instructor: Unfortunately this is 'W' key";
	str[8] = "Instructor: I cant leave it, let me show basic things:";
	str[9] = "Sergant: NAAAH man say what you wanna say";
	str[10] = "If you're ready to learn basic things press SPACE: ";
	for (int index = 0; index < 10; index++) {
		wmove(stdscr, Field_height / 4 + index * 2, Field_width / 2 - 29);
		printw(str[index]);
		refresh();
		Sleep(50);
	}
	Sleep(50);
	wmove(stdscr, Field_height / 4 + 21, Field_width / 2 + 31);
	printw(str[10]);
	CreateRectangle(Field_width / 2 + 31 - 1, Field_height / 4 + 21 - 1, strlen(str[10]), 3, 1);
	refresh();
	timeout(100000);
	while (true) {
		key = getch();
		if (key == ' ') {
			Play_Obuchenie();
			break;
		}
	}
}

void Intro::TalkToOfficer() {
	const char** str = new (const char* [10]);
	int key;
	str[0] = "Instructor: I wish you good health, Mr Officer!";
	str[1] = "Officer: Good health, comrade instructor";
	str[2] = "Instructor: Mr Officer, Im sorry but i have to show you some useful keys of this game";
	str[3] = "Instructor: Of course we can forget about it. All will be as you wanna be";
	str[4] = "Officer: No need to forget of something important comrade";
	str[5] = "Officer: I respect rules. So show me your key-management tricks:";
	str[6] = "Officer: Maybe I forgot it for real...A-Ha-Ha-Ha";
	str[7] = "Instructor: Ha-Ha-Ha";
	str[8] = "Instructor: So Mr Officer Here is some basic keys that you need to know:";
	str[9] = "Click SPACE key to see Learning Menu";
	clear();
	for (int i = 0; i < 9; i++) {
		wmove(stdscr, Field_height / 4 + i*2, Field_width / 2 - 20);
		printw(str[i]);
		Sleep(50);
		refresh();
	}
	wmove(stdscr, Field_height / 4 + 20, Field_width / 2 + 29);
	printw(str[9]);
	CreateRectangle(Field_width / 2 + 29 - 1, Field_height / 4 + 20 - 1, strlen(str[9]) + 2, 3, 1);
	Sleep(50);
	refresh();
	while (true) {
		key = getch();
		if (key == ' ') {
			Play_Obuchenie();
			break;
		}
	}
}

void Intro::Play_Second_Slide(int choosed_one) {
	int key;
	
	clear();
	switch (choosed_one) {
	case 1:
		Play_Obuchenie();
		break;
	case 2:
		TalkToSergant();
		break;
	case 3:
		TalkToOfficer();
		break;

	}
}

void Intro::Preface_Before_Fight(int choosed_one) {
	clear();
	const char** str = new (const char* [4]);
	int key;
	timeout(100000);
	str[0] = "Instructor: Now after you finished lesson we're ready to check what will you do in real combat";
	str[1] = "Instructor: Be careful but dont be afraid!";
	str[2] = "Instructor: Just remember! That how you'll show yourself will determine your further path..";
	str[3] = "When you will ready to your mission press SPACE";
	for (int index = 0; index < 3; index++) {
		wmove(stdscr, Field_height / 4 + index*2, Field_width / 2-15);
		printw(str[index]);
		refresh();
		Sleep(50);
	}
	wmove(stdscr, Field_height / 4 + 16, Field_width / 2 + 26);
	printw(str[3]);
	CreateRectangle(Field_width / 2 + 26 - 1, Field_height / 4 + 16 - 1, strlen(str[3]) + 2, 3, 1);
	refresh();
	Sleep(50);

	switch (choosed_one) {
	case 1:
		wmove(stdscr, Field_height / 4 + 6, Field_width / 2-15);
		printw("Private: Lets go Man, Im always ready");
		refresh();
		Sleep(100);
		break;
	case 2:
		wmove(stdscr, Field_height / 4 + 6, Field_width / 2-15);
		printw("Sergant: Just give me gun man I will kill everyone, you will see");
		refresh();
		Sleep(100);
		break;
	case 3:
		wmove(stdscr, Field_height / 4 + 6, Field_width / 2-15);
		printw("Officer: Hope my player remembers how to keep mouse in his hand");
		refresh();
		Sleep(50);
		wmove(stdscr, Field_height / 4 + 8, Field_width / 2-15);
		printw("Officer: Just kidding, lets do it");
		refresh();
		Sleep(100);
		break;
	}
	while (true) {
		key = getch();
		if (key == ' ')
			break;
	}
}

void Intro::Play_Intro() {
	char* str;
	wmove(stdscr, Field_height / 4, Field_width / 2 - 3); //вывод статистики
	str = "This game is not just a simple game.";
	printw(str);
	//CreateRectangle(Field_width / 2 - 4, Field_height / 4 - 1, strlen(str)+2, 3);
	str = "This is the story you writing are";
	wmove(stdscr, Field_height / 4+3, Field_width / 2 - 3);
	printw(str);

	wmove(stdscr, Field_height / 4+16, Field_width / 2 + 35);
	printw("Tap any key to next page");
	CreateRectangle(Field_width / 2 + 35 - 1, Field_height / 4 + 16 - 1, strlen("Tap any key to next page")+2, 3, 1);
	refresh();
	timeout(10000);
	int key;
	key = getch();
	clear();
	//print_ramka
	//widelit' ramka
	refresh();
	Choosed_one = Play_Slide();
	Play_Second_Slide(Choosed_one);
	Preface_Before_Fight(Choosed_one);

}


void Intro::run() {
	Init_of_window(); //засунуть все, кроме act из GameObjects в private почти

	Play_Intro();
	
	if (Man_alive == 1)
		Win = 1;
	else
		Win = 0;



}
