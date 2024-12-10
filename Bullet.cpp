#include "GameObjects.h"
#include <iostream>

GameObjects::Bullet::Bullet(int x, int y, int hp, bool hitbox, char amount_of_steps) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps) {}

void GameObjects::Bullet::Draw() {
	//GoToPos(x, y);
	wmove(stdscr, y, x);
	wprintw(stdscr, ".");
}

void GameObjects::Bullet::Dead() {}

void GameObjects::Bullet::ReactToBullet() {
	hp--;
	if (hp == 0)
		Dead();
}

void GameObjects::Bullet::gachi() {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Bullet::Move(char key) {
	if ((amount_of_steps != 0) || (y == 0))
		return;

	if (Cells[(y - 1) * Field_width + x]->IsAlive()) {
		Cells[(y - 1) * Field_width + x]->ReactToBullet();
		Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
	}
	else {
		
		Cells[(y - 1) * Field_width + x] = std::make_unique<GameObjects::Bullet>(x, y - 1, hp, hitbox, 1);
		Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0);
	}
}

void GameObjects::Bullet::Shoot() {}


void GameObjects::Bullet::act(char key) {
	Move(key);
}

bool GameObjects::Bullet::IsAlive() {
	return hitbox;
}

void GameObjects::Bullet::SetAmountOfSteps() {
	amount_of_steps = 0;
}