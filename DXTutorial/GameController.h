#pragma once

#include "GameLevel.h"

class GameController
{
private:
	GameController();
	static GameLevel* currentLevel;
public:
	~GameController();

	static bool loading;

	static void Init();

	static void LoadInitialLevel(GameLevel* lev);
	static void SwitchLevel(GameLevel* lev);

	static void Render();
	static void Update();
};

