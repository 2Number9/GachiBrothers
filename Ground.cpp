#include "GameObjects.h"
#include <iostream>


GameObjects::Ground::Ground(int x, int y, int hp, bool hitbox, char amount_of_steps) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps) {}

void GameObjects::Ground::Draw() {
	//GoToPos(x, y);
	wmove(stdscr, y, x);
	wprintw(stdscr, "-");
}

void GameObjects::Ground::Dead() {}

void GameObjects::Ground::Move(char direction) {}

void GameObjects::Ground::Shoot() {}

void GameObjects::Ground::ReactToBullet() {}


void GameObjects::Ground::gachi() {
	std::cout << "x == " << x << "y == " << y << "hp == " << hp << std::endl;
}

void GameObjects::Ground::act(char key) {
	//Draw();
}

bool GameObjects::Ground::IsAlive() {
	return hitbox;
}

void GameObjects::Ground::SetAmountOfSteps() {
	amount_of_steps = 0;
}