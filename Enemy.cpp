#include "GameObjects.h"
#include <iostream>

GameObjects::Enemy::Enemy(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Enemy::Draw() {
	wmove(stdscr, y, x);
	printw("G");
}

void GameObjects::Enemy::gachi(Context &context, Statistic &statistic) {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Enemy::Dead(Context &context, Statistic &statistic) {
	statistic.Amount_of_alive_enemy--;
	statistic.Amount_of_injured_people--;
	context.GetCell(x, y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
}

void GameObjects::Enemy::ReactToBullet(Context &context, Statistic &statistic) {
	if (hp == 3)
		statistic.Amount_of_injured_people++;
	hp--;
	if (hp == 0)
		Dead(context, statistic);
}

void GameObjects::Enemy::Move(char key, Context &context, Statistic &statistic) {
	if (amount_of_steps != 0)
		return;
	switch (key) {

	case 'w':
	case 'W':
		if ((y > 0) && (context.GetCell(x,y-1)->IsAlive() == 0)) {
			context.GetCell(x,y-1) = std::make_unique<GameObjects::Enemy>(x, y - 1, hp, hitbox, 1, 0);
			context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 'd':
	case 'D':
		if ((x < (Field_width - 1)) && (context.GetCell(x+1,y)->IsAlive() == 0)) {
			context.GetCell(x+1,y) = std::make_unique<GameObjects::Enemy>(x + 1, y, hp, hitbox, 1, 0);
			context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 's':
	case 'S':
		if ((y < (Field_height - 1)) && (context.GetCell(x,y+1)->IsAlive() == 0)) {
			context.GetCell(x,y+1) = std::make_unique<GameObjects::Enemy>(x, y + 1, hp, hitbox, 1, 0);
			context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 'a':
	case 'A':
		if ((x > 0) && (context.GetCell(x-1,y)->IsAlive() == 0)) {
			context.GetCell(x-1,y) = std::make_unique<GameObjects::Enemy>(x - 1, y, hp, hitbox, 1, 0);
			context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	}
}


void GameObjects::Enemy::Shoot(Context &context, Statistic &statistic) {
	if (y == Field_height - 1)
		return;
	statistic.Amount_of_bullets++;
	if (context.GetCell(x,y+1)->IsAlive() == 0) {
		context.GetCell(x,y+1) = std::make_unique<GameObjects::Bullet>(x, y + 1, 3, hitbox, 1, 0);
	}
	else {
		context.GetCell(x,y+1)->ReactToBullet(context, statistic);
	}
}

void GameObjects::Enemy::act(char key, Context &context, Statistic &statistic) {
	

	int random_paramether;


	if ((y - statistic.Coordinats_of_man[1] > 0) && (context.GetCell(x,y-1)->IsAlive() == 0))
		random_paramether = 0;
	else
		if ((x - statistic.Coordinats_of_man[0] > 0) && (context.GetCell(x-1,y)->IsAlive() == 0))
			random_paramether = 3;
		else
			if (((statistic.Coordinats_of_man[0] - x) > 0) && (context.GetCell(x+1,y)->IsAlive() == 0))
				random_paramether = 1;
			else
				random_paramether = 4;
	

	switch (random_paramether) {
	case 0:
		Move('w', context, statistic);
		break;
	case 1:
		Move('d', context, statistic);
		break;
	case 2:
		Move('s', context, statistic);
		break;
	case 3:
		Move('a', context, statistic);
		break;
	case 4:
		Shoot(context, statistic);
		break;

	}

}


bool GameObjects::Enemy::IsAlive() {
	return hitbox;
}

void GameObjects::Enemy::SetAmountOfSteps() {
	amount_of_steps = 0;
}
