#include "GameObjects.h"
#include <iostream>

GameObjects::Shelter::Shelter(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Shelter::Draw() {
	wmove(stdscr, y, x);
	wprintw(stdscr, "#");
}

void GameObjects::Shelter::Dead() {
	Cells[y * Field_width + x] = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
}

void GameObjects::Shelter::Move(char direction) {}

void GameObjects::Shelter::Shoot() {}

void GameObjects::Shelter::ReactToBullet() {
	hp--;
	if (hp == 0)
		Dead();
}

void GameObjects::Shelter::gachi() {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Shelter::act(char key) {
}

bool GameObjects::Shelter::IsAlive() {
	return hitbox;
}

void GameObjects::Shelter::SetAmountOfSteps() {
	amount_of_steps = 0;
}