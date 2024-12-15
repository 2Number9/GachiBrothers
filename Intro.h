#pragma once
#include "GamePlay.h"

class Intro {
public:
	Intro() = default;
	~Intro() = default;
	void run(GameObjects::Statistic &statistic);
	void Init_of_window();
	void Play_Intro(GameObjects::Statistic &statistic);
	int Play_Slide();
	void Play_Second_Slide(int choosed_one);
	void Play_Obuchenie();
	void TalkToSergant();
	void TalkToOfficer();
	void Preface_Before_Fight(int choosed_one);
private:
	void Create_Rectangle(int x, int y, int width, int height, bool is_not_empty);
};