#include "GameObjects.h"
#include <iostream>

GameObjects::Bullet::Bullet(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Bullet::Draw() {
	wmove(stdscr, y, x);
	wprintw(stdscr, ".");
}

void GameObjects::Bullet::Dead() {
	
}

void GameObjects::Bullet::ReactToBullet() {
	hp--;
	if (hp == 0)
		Dead();
}

void GameObjects::Bullet::gachi() {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Bullet::Move(char key) {

	if (amount_of_steps >3)
		return;

	int offset;
	if (is_a_good_guy == 0)
		offset = 1;
	else
		offset = -1;

	if (((y == 0) && (is_a_good_guy == 1)) || ((y == Field_height - 1 ) && (is_a_good_guy == 0))) {
		Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		return;
	}


	if (Cells[(y + offset) * Field_width + x]->IsAlive()) {
		Cells[(y + offset) * Field_width + x]->ReactToBullet();
		Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
	}
	else {
		
		Cells[(y + offset) * Field_width + x] = std::make_unique<GameObjects::Bullet>(x, y + offset, hp, hitbox, amount_of_steps + 1, is_a_good_guy);
		Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
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