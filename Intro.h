#pragma once
#include "GameObjects.h"

class Intro {
public:
	Intro() = default;
	~Intro() = default;
	void run();
	void Init_of_window();
	void Play_Intro();
	int Play_Slide();
	void Play_Second_Slide(int choosed_one);
	void Play_Obuchenie();
	void TalkToSergant();
	void TalkToOfficer();
	void Preface_Before_Fight(int choosed_one);
};