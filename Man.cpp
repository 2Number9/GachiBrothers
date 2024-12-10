#include "GameObjects.h"
#include <iostream>

GameObjects::Man::Man(int x, int y, int hp, bool hitbox, char amount_of_steps) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps) {}

void GameObjects::Man::Draw() {
	//GoToPos(x, y);
	wmove(stdscr, y, x);
	wprintw(stdscr, "Z");
}

void GameObjects::Man::Move(char direction) {
	if (amount_of_steps != 0)
		return;
	switch (direction) {

	case 'w':
	case 'W': //пока забьем на проверки, если там что-то есть
		if ((y > 0) && (Cells[(y - 1) * Field_width + x]->IsAlive() == 0)) {
			Cells[(y-1) * Field_width + x] = std::make_unique<GameObjects::Man>(x, y-1, hp, hitbox, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
			y--;
		}
		break;
	case 'd':
	case 'D':
		if ((x < (Field_width - 1)) && (Cells[y * Field_width + (x + 1)]->IsAlive() == 0)) {
			Cells[y * Field_width + (x + 1)] = std::make_unique<GameObjects::Man>(x + 1, y, hp, hitbox, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
			x++;
		}
		break;

	case 'a':
	case 'A':
		if ((x > 0) && (Cells[y * Field_width + (x - 1)]->IsAlive() == 0)) {
			Cells[y * Field_width + (x - 1)] = std::make_unique<GameObjects::Man>(x - 1, y, hp, hitbox, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
			x--;
		}
		break;

	case 's':
	case 'S':
		if ((y < (Field_height - 1)) && (Cells[(y + 1) * Field_width + x]->IsAlive() == 0)) {
			Cells[(y + 1) * Field_width + x] = std::make_unique<GameObjects::Man>(x, y + 1, hp, hitbox, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
			y++;
		}
		break;
	

	case 'x':
		break;
	}
	//GoToPos(0, Field_height + 1);
	//std::cout << "Cells[y * Field_width + x]->IsAlive() == " << Cells[y * Field_width + x]->IsAlive() << std::endl;

}


void GameObjects::Man::ReactToBullet() {
	hp--;
	if (hp == 0)
		Dead();
}

void GameObjects::Man::Shoot() {
	if (y == 0)
		return;
	if (Cells[(y - 1) * Field_width + x]->IsAlive() == 0) {
		Cells[(y - 1) * Field_width + x] = std::make_unique<GameObjects::Bullet>(x, y - 1, hp, hitbox, 1);
	}
	else {
		Cells[(y - 1) * Field_width + x]->ReactToBullet();
		Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
	}
}


void GameObjects::Man::Dead() {}

void GameObjects::Man::gachi() {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Man::act(char key) {
	if (key == 'x')
		return;
	else
		if (key == ' ')
			Shoot();
		else
			if (key != ERR)
				Move(key);
	//Cells[y * Field_width + x]->Draw();
}

bool GameObjects::Man::IsAlive() {
	return hitbox;
}

void GameObjects::Man::SetAmountOfSteps() {
	amount_of_steps = 0;
}
