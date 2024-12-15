#pragma once
#include "GameObjects.h"


class GamePlay {
public:
	GamePlay(GameObjects::Context &context, GameObjects::Statistic &statistic);
	~GamePlay() = default;
	void Run();
	void Create_Field_And_Objects();
private:
	void Create_Field();
	void Put_Shelters();
	void Create_Man();
	void Create_Enemy();
	void Display_Score();
	GameObjects::Context &context;
	GameObjects::Statistic &statistic;
};