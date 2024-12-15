#include "GameObjects.h"
#include <iostream>


GameObjects::Ground::Ground(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Ground::Draw() {
	wmove(stdscr, y, x);
	wprintw(stdscr, "-");
}

void GameObjects::Ground::Dead(Context &context, Statistic& statistic) {}

void GameObjects::Ground::Move(char direction, Context &context, Statistic& statistic) {}

void GameObjects::Ground::Shoot(Context &context, Statistic& statistic) {}

void GameObjects::Ground::ReactToBullet(Context &context, Statistic& statistic) {}


void GameObjects::Ground::gachi(Context &context, Statistic& statistic) {
	std::cout << "x == " << x << "y == " << y << "hp == " << hp << std::endl;
}

void GameObjects::Ground::act(char key, Context &context, Statistic& statistic) {}

bool GameObjects::Ground::IsAlive() {
	return hitbox;
}

void GameObjects::Ground::SetAmountOfSteps() {
	amount_of_steps = 0;
}