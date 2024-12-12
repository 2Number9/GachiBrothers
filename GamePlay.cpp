#include "GamePlay.h"
#include "Intro.h"
#include "Ending.h"

void GamePlay::Create_Field_And_Objects() {

	CreateField();
	PutShelters();
	CreateMan();
	CreateEnemy();

}

void GamePlay::Run() {

	Intro intro;
	intro.run();

	Sleep(100);

	Create_Field_And_Objects();
	while (true) {
		clear();
	
		//initialisation
		for (int i = 0; i < Field_width * Field_height; i++) {
			Cells[i]->SetAmountOfSteps();
		}
		
		int key;
		timeout(50);
		key = getch();

		//acting
		for (int i = 0; i < Field_width * Field_height; i++) {
			Cells[i]->act(key);
		}

		//drawing
		for (int i = 0; i < Field_width * Field_height; i++) {
			Cells[i]->Draw();
		}
		DisplayScore();

		flushinp();
		refresh();

		if ((Man_alive == 0) || (Amount_of_alive_enemy == 0))
			break;

		if (key == 'x')
			break;
		Sleep(150);
	}
	Sleep(50);
	clear();
	flushinp();
	Ending ending;
	ending.Run();
}
