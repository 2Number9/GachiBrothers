#include "GameObjects.h"
#include <iostream>

GameObjects::Man::Man(int x, int y, int hp, bool hitbox, char amount_of_steps, bool is_a_good_guy) : x(x), y(y), hp(hp), hitbox(hitbox), amount_of_steps(amount_of_steps), is_a_good_guy(is_a_good_guy) {}

void GameObjects::Man::Draw() {
	wmove(stdscr, y, x);
	wprintw(stdscr, "Z");
}

void GameObjects::Man::Move(char direction, Context &context, Statistic &statistic) {
	if (amount_of_steps != 0)
		return;
	switch (direction) {

	case 'w':
	case 'W': 
		if ((y > 0) && (context.GetCell(x, y-1)->IsAlive() == 0)) {
			statistic.Coordinats_of_man[1]--;
			context.GetCell(x, y-1) = std::make_unique<GameObjects::Man>(x, y-1, hp, hitbox, 1, 1);
			context.GetCell(x, y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	case 'd':
	case 'D':
		if ((x < (Field_width - 1)) && (context.GetCell(x+1, y)->IsAlive() == 0)) {
			statistic.Coordinats_of_man[0]++;
			context.GetCell(x+1, y) = std::make_unique<GameObjects::Man>(x + 1, y, hp, hitbox, 1, 1);
			context.GetCell(x, y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;

	case 'a':
	case 'A':
		if ((x > 0) && (context.GetCell(x-1, y)->IsAlive() == 0)) {
			statistic.Coordinats_of_man[0]--;
			context.GetCell(x-1,y) = std::make_unique<GameObjects::Man>(x - 1, y, hp, hitbox, 1, 1);
			context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;

	case 's':
	case 'S':
		if ((y < (Field_height - 1)) && (context.GetCell(x,y+1)->IsAlive() == 0)) {
			statistic.Coordinats_of_man[1]++;
			context.GetCell(x,y+1) = std::make_unique<GameObjects::Man>(x, y + 1, hp, hitbox, 1, 1);
			context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
		}
		break;
	

	case 'x':
		break;
	}

}

void GameObjects::Man::Dead(Context &context, Statistic& statistic) {
	statistic.Man_alive = 0;
	statistic.Amount_of_injured_people--;
	context.GetCell(x,y) = std::make_unique<GameObjects::Ground>(x, y, 9, 0, 0, 0);
}


void GameObjects::Man::ReactToBullet(Context &context, Statistic& statistic) {
	if (hp == 3)
		statistic.Amount_of_injured_people++;
	hp--;
	if (hp == 0)
		Dead(context, statistic);
}

void GameObjects::Man::Shoot(Context &context, Statistic& statistic) {
	if (y == 0)
		return;
	statistic.Amount_of_bullets++;
	if (context.GetCell(x,y-1)->IsAlive() == 0) {
		context.GetCell(x,y-1) = std::make_unique<GameObjects::Bullet>(x, y - 1, hp, 1, 1, 1);
	}
	else {
		context.GetCell(x,y-1)->ReactToBullet(context, statistic);
	}
}



void GameObjects::Man::gachi(Context &context, Statistic& statistic) {
	std::cout << "x == " << x << "y == " << y << std::endl;
}

void GameObjects::Man::act(char key, Context &context, Statistic& statistic) {
	if (key == 'x')
		return;
	else
		if (key == ' ')
			Shoot(context, statistic);
		else
			if (key != ERR)
				Move(key, context, statistic);
}

bool GameObjects::Man::IsAlive() {
	return hitbox;
}

void GameObjects::Man::SetAmountOfSteps() {
	amount_of_steps = 0;
}
