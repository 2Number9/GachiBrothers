#pragma once
#include "GamePlay.h"

class Ending {
public:
	Ending() = default;
	~Ending() = default;
	void Run(GameObjects::Statistic &statistic);
private:
	void Create_Rectangle(int x, int y, int width, int height, bool is_not_empty);
	void Game_Results(GameObjects::Statistic &statistic);
};