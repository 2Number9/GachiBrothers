#include "GameObjects.h" //���� ���� ������ conio.h, � ������� ��� ���� getch(), �� �������� ������ getch()
#include <ctime>
#include <iostream>
//#include <Windows.h>



int main() {
	
	initscr();

	cbreak(); //��������� ����������� ����� � ���������� ��������, ������ �������� ������������� ������� ����� ���������� ��� ���������

	noecho(); //��������� ����������� �������� �������� �� �����

	curs_set(FALSE); //������ ���������������� ������ ���������

	keypad(stdscr, TRUE); //��� ������� ���� stdscr ���������� ������� ����� ������ � ��������������� ��������� (F1, F2, ...)

	timeout(50); //������������� ����� �������� ��� getch(), wgetch() ��� ����� �������

	int h1;
	int w1;

	getmaxyx(stdscr, h1, w1);

	int key;
	//wmove(stdscr, 0, 1);
	while (true) {
		key = getch();
		if (key != ERR)
			printw("aboba");
		else
			printw("Dicks");
		refresh();
		Sleep(50);
		clear();
		if (key == 'x')
			break;
	}

	CreateField();
	PutShelters();
	CreateMan();

	while (true) {
		clear();
		for (int i = 0; i < Field_width * Field_height; i++) {
			Cells[i]->SetAmountOfSteps();
		}
		printw("x");

		key = getch();
		for (int i = 0; i < Field_width * Field_height; i++) {
			Cells[i]->act(key);
		}
		printw("x");
		for(int i = 0; i < Field_width* Field_height; i++) {
			Cells[i]->Draw();
		}
		printw("x");
		refresh();
		Sleep(100);
	}

	endwin();
	
	return 0;
}