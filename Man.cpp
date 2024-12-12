#include "GameObjects.h"
#include <iostream>

GameObjects::Man::Man(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Man::Draw() {
	wmove(stdscr, y, x);
	wprintw(stdscr, "Z");
}

void GameObjects::Man::Move(char direction) {
	if (amount_of_steps != 0)
		return;
	switch (direction) {

	case 'w':
	case 'W': 
		if ((y > 0) && (Cells[(y - 1) * Field_width + x]->IsAlive() == 0)) {
			coordinats_of_man[1]--;
			Cells[(y-1) * Field_width + x] = std::make_unique<GameObjects::Man>(x, y-1, hp, hitbox, 1, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 'd':
	case 'D':
		if ((x < (Field_width - 1)) && (Cells[y * Field_width + (x + 1)]->IsAlive() == 0)) {
			coordinats_of_man[0]++;
			Cells[y * Field_width + (x + 1)] = std::make_unique<GameObjects::Man>(x + 1, y, hp, hitbox, 1, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;

	case 'a':
	case 'A':
		if ((x > 0) && (Cells[y * Field_width + (x - 1)]->IsAlive() == 0)) {
			coordinats_of_man[0]--;
			Cells[y * Field_width + (x - 1)] = std::make_unique<GameObjects::Man>(x - 1, y, hp, hitbox, 1, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;

	case 's':
	case 'S':
		if ((y < (Field_height - 1)) && (Cells[(y + 1) * Field_width + x]->IsAlive() == 0)) {
			coordinats_of_man[1]++;
			Cells[(y + 1) * Field_width + x] = std::make_unique<GameObjects::Man>(x, y + 1, hp, hitbox, 1, 1);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	

	case 'x':
		break;
	}

}

void GameObjects::Man::Dead() {
	Man_alive = 0;
	Amount_of_injured_people--;
	Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
}


void GameObjects::Man::ReactToBullet() {
	if (hp == 3)
		Amount_of_injured_people++;
	hp--;
	if (hp == 0)
		Dead();
}

void GameObjects::Man::Shoot() {
	if (y == 0)
		return;
	Amount_of_bullets++;
	if (Cells[(y - 1) * Field_width + x]->IsAlive() == 0) {
		Cells[(y - 1) * Field_width + x] = std::make_unique<GameObjects::Bullet>(x, y - 1, hp, 1, 1, 1);
	}
	else {
		Cells[(y - 1) * Field_width + x]->ReactToBullet();
	}
}



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
}

bool GameObjects::Man::IsAlive() {
	return hitbox;
}

void GameObjects::Man::SetAmountOfSteps() {
	amount_of_steps = 0;
}
