#include "Intro.h"
#include "Ending.h"

GamePlay::GamePlay(GameObjects::Context& context, GameObjects::Statistic& statistic) : context(context), statistic(statistic) {}

void GamePlay::Create_Field() {
	for (int y = 0; y < Field_height; y++) {
		for (int x = 0; x < Field_width; x++) {
			context.GetCell(x, y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
	}
	statistic.Amount_of_bullets = 0;
	statistic.Amount_of_injured_people = 0;
}

void GamePlay::Display_Score() {
	wmove(stdscr, Field_height / 4, Field_width + 20);
	printw("Ally alive: %d ", statistic.Man_alive);
	printw("Enemy alive: %d", statistic.Amount_of_alive_enemy);
}


void GamePlay::Put_Shelters() {
	for (int y = 2; y <= 4; y++) {
		for (int x = 6; x <= 17; x++) {
			context.GetCell(x, y) = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0, 0);
		}
	}

	for (int y = 3; y <= 5; y++) {
		for (int x = 29; x <= 40; x++) {
			context.GetCell(x, y) = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0, 0);
		}
	}

	for (int y = 2; y <= 4; y++) {
		for (int x = 54; x <= 65; x++) {
			context.GetCell(x, y) = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0, 0);
		}
	}

	for (int y = 20; y <= 22; y++) {
		for (int x = 8; x <= 19; x++) {
			context.GetCell(x, y) = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0, 0);
		}
	}


	for (int y = 21; y <= 23; y++) {
		for (int x = 27; x <= 38; x++) {
			context.GetCell(x, y) = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0, 0);
		}
	}

	for (int y = 20; y <= 22; y++) {
		for (int x = 56; x <= 67; x++) {
			context.GetCell(x, y) = std::make_unique<GameObjects::Shelter>(x, y, 3, 1, 0, 0);
		}
	}


}


void GamePlay::Create_Man() {
	context.GetCell(5, 23) = std::make_unique<GameObjects::Man>(5, 23, 3, 1, 0, 1);
	statistic.Coordinats_of_man.resize(2);
	statistic.Coordinats_of_man[0] = 5;
	statistic.Coordinats_of_man[1] = 23;
	statistic.Man_alive = true;
}

void GamePlay::Create_Enemy() {
	context.GetCell(8, 1) = std::make_unique<GameObjects::Enemy>(8, 1, 3, 1, 0, 0);
	context.GetCell(58, 1) = std::make_unique<GameObjects::Enemy>(58, 1, 3, 1, 0, 0);
	statistic.Amount_of_alive_enemy = 2;
}

void GamePlay::Create_Field_And_Objects() {

	Create_Field();
	Put_Shelters();
	Create_Man();
	Create_Enemy();

}



void GamePlay::Run() {

	Intro intro;
	intro.run(statistic);

	Sleep(100);

	

	Create_Field_And_Objects();
	while (true) {
		clear();
		refresh();
	
		//initialisation
		for (int y = 0; y < Field_height; y++)
			for (int x = 0; x < Field_width; x++) {
			context.GetCell(x,y)->SetAmountOfSteps();
		}
		

		int key;
		timeout(50);
		key = getch();

		//acting
		for (int y = 0; y < Field_height; y++)
			for (int x = 0; x < Field_width; x++) {
				context.GetCell(x, y)->act(key, context, statistic);
			}

		//drawing
		for (int y = 0; y < Field_height; y++)
			for (int x = 0; x < Field_width; x++) {
				context.GetCell(x, y)->Draw();
			}
		Display_Score();

		flushinp();
		refresh();

		if ((statistic.Man_alive == 0) || (statistic.Amount_of_alive_enemy == 0))
			break;

		if (key == 'x')
			break;
		Sleep(150);
	}
	Sleep(50);
	clear();
	flushinp();
	Ending ending;
	ending.Run(statistic);
}
