#include "GameObjects.h"
#include <iostream>

GameObjects::Shelter::Shelter(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Shelter::Draw() {
	wmove(stdscr, y, x);
	wprintw(stdscr, "#");
}

void GameObjects::Shelter::Dead(Context &context, Statistic &statistic) {
	context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
}

void GameObjects::Shelter::Move(char direction, Context &context, Statistic& statistic) {}

void GameObjects::Shelter::Shoot(Context &context, Statistic& statistic) {}

void GameObjects::Shelter::ReactToBullet(Context &context, Statistic& statistic) {
	hp--;
	if (hp == 0)
		Dead(context, statistic);
}

void GameObjects::Shelter::gachi(Context &context, Statistic& statistic) {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Shelter::act(char key, Context &context, Statistic& statistic) {
}

bool GameObjects::Shelter::IsAlive() {
	return hitbox;
}

void GameObjects::Shelter::SetAmountOfSteps() {
	amount_of_steps = 0;
}