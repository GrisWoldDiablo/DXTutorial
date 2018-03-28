#include "GameController.h"

GameLevel* GameController::currentLevel;
bool GameController::loading;

GameController::GameController()
{
}

GameController::~GameController()
{
}

void GameController::Init()
{
	loading = true;
	currentLevel = 0;
}

void GameController::LoadInitialLevel(GameLevel * lev)
{
	loading = true;
	currentLevel = lev;
	currentLevel->Load();
	loading = false;
}

void GameController::SwitchLevel(GameLevel * lev)
{
	loading = true;
	currentLevel->UnLoad();
	lev->Load();
	delete currentLevel;
	currentLevel = lev;
	loading = false;

}

void GameController::Render()
{
	if (loading) { return; }
	currentLevel->Render();
}

void GameController::Update()
{
	if (loading) { return; }
	currentLevel->Update();
}
