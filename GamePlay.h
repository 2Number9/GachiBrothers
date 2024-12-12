#pragma once
#include "GameObjects.h"

class GamePlay {
public:
	GamePlay() = default;
	~GamePlay() = default;
	void Run();
	void Create_Field_And_Objects();
};