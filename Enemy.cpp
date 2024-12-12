#include "GameObjects.h"
#include <iostream>

GameObjects::Enemy::Enemy(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Enemy::Draw() {
	wmove(stdscr, y, x);
	printw("G");
}

void GameObjects::Enemy::gachi() {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Enemy::Dead() {
	Amount_of_alive_enemy--;
	Amount_of_injured_people--;
	Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
}

void GameObjects::Enemy::ReactToBullet() {
	if (hp == 3)
		Amount_of_injured_people++;
	hp--;
	if (hp == 0)
		Dead();
}

void GameObjects::Enemy::Move(char key) {
	if (amount_of_steps != 0)
		return;
	switch (key) {

	case 'w':
	case 'W':
		if ((y > 0) && (Cells[(y - 1) * Field_width + x]->IsAlive() == 0)) {
			Cells[(y - 1) * Field_width + x] = std::make_unique<GameObjects::Enemy>(x, y - 1, hp, hitbox, 1, 0);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 'd':
	case 'D':
		if ((x < (Field_width - 1)) && (Cells[y * Field_width + (x + 1)]->IsAlive() == 0)) {
			Cells[y * Field_width + (x + 1)] = std::make_unique<GameObjects::Enemy>(x + 1, y, hp, hitbox, 1, 0);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 's':
	case 'S':
		if ((y < (Field_height - 1)) && (Cells[(y + 1) * Field_width + x]->IsAlive() == 0)) {
			Cells[(y + 1) * Field_width + x] = std::make_unique<GameObjects::Enemy>(x, y + 1, hp, hitbox, 1, 0);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 'a':
	case 'A':
		if ((x > 0) && (Cells[y * Field_width + (x - 1)]->IsAlive() == 0)) {
			Cells[y * Field_width + (x - 1)] = std::make_unique<GameObjects::Enemy>(x - 1, y, hp, hitbox, 1, 0);
			Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	}
}


void GameObjects::Enemy::Shoot() {
	if (y == Field_height - 1)
		return;
	Amount_of_bullets++;
	if (Cells[(y + 1) * Field_width + x]->IsAlive() == 0) {
		Cells[(y + 1) * Field_width + x] = std::make_unique<GameObjects::Bullet>(x, y + 1, 3, hitbox, 1, 0);
	}
	else {
		Cells[(y + 1) * Field_width + x]->ReactToBullet();
	}
}

void GameObjects::Enemy::act(char key) {
	

	int random_paramether;


	if ((y - coordinats_of_man[1] > 0) && (Cells[(y - 1) * Field_width + x]->IsAlive() == 0))
		random_paramether = 0;
	else
		if ((x - coordinats_of_man[0] > 0) && (Cells[y * Field_width + (x - 1)]->IsAlive() == 0))
			random_paramether = 3;
		else
			if (((coordinats_of_man[0] - x) > 0) && (Cells[y * Field_width + (x + 1)]->IsAlive() == 0))
				random_paramether = 1;
			else
				random_paramether = 4;
	

	switch (random_paramether) {
	case 0:
		Move('w');
		break;
	case 1:
		Move('d');
		break;
	case 2:
		Move('s');
		break;
	case 3:
		Move('a');
		break;
	case 4:
		Shoot();
		break;

	}

}


bool GameObjects::Enemy::IsAlive() {
	return hitbox;
}

void GameObjects::Enemy::SetAmountOfSteps() {
	amount_of_steps = 0;
}
