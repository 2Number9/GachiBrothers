#include "GameObjects.h"
#include <iostream>

GameObjects::Bullet::Bullet(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Bullet::Draw() {
	wmove(stdscr, y, x);
	wprintw(stdscr, ".");
}

void GameObjects::Bullet::Dead(Context &context, Statistic &statistic) {
	
}

void GameObjects::Bullet::ReactToBullet(Context &context, Statistic &statistic) {
	hp--;
	if (hp == 0)
		Dead(context, statistic);
}

void GameObjects::Bullet::gachi(Context &context, Statistic &statistic) {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Bullet::Move(char key, Context &context, Statistic &statistic) {

	if (amount_of_steps >3)
		return;

	int offset;
	if (is_a_good_guy == 0)
		offset = 1;
	else
		offset = -1;

	if (((y == 0) && (is_a_good_guy == 1)) || ((y == Field_height - 1 ) && (is_a_good_guy == 0))) {
		context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		return;
	}


	if (context.GetCell(x,y+offset)->IsAlive()) {
		context.GetCell(x,y+offset)->ReactToBullet(context, statistic);
		context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
	}
	else {
		
		context.GetCell(x,y+offset) = std::make_unique<GameObjects::Bullet>(x, y + offset, hp, hitbox, amount_of_steps + 1, is_a_good_guy);
		context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
	}
}

void GameObjects::Bullet::Shoot(Context &context, Statistic &statistic) {}


void GameObjects::Bullet::act(char key, Context &context, Statistic &statistic) {
	Move(key, context, statistic);
}

bool GameObjects::Bullet::IsAlive() {
	return hitbox;
}

void GameObjects::Bullet::SetAmountOfSteps() {
	amount_of_steps = 0;
}