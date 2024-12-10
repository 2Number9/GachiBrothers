#include "GameObjects.h"
#include <iostream>

GameObjects::Shelter::Shelter(int x, int y, int hp, bool hitbox, char amount_of_steps) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps) {}

void GameObjects::Shelter::Draw() {
	//GoToPos(x, y);
	wmove(stdscr, y, x);
	wprintw(stdscr, "#");
}

void GameObjects::Shelter::Dead() {
	//GoToPos(x, y);
	//printw(" ");
	//this = std::make_unique<GameObjects::Ground>(x, y, 9);
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
	//Draw();
}

bool GameObjects::Shelter::IsAlive() {
	return hitbox;
}

void GameObjects::Shelter::SetAmountOfSteps() {
	amount_of_steps = 0;
}