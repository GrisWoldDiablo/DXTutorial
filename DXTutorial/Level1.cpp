#include "Level1.h"
#include "GameController.h"

Level1::Level1()
{
}


Level1::~Level1()
{
}

void Level1::Load()
{
	y = ySpeed = 0.0f;
}

void Level1::UnLoad()
{
}

void Level1::Render()
{
	gfx->ClearScreen(0.0f, 0.0f, 0.5f);

	gfx->DrawCircle(375.0f, y, 50.0f, 1.0f, 1.0f, 1.0f, 1.0f, 5);
}

void Level1::Update()
{
	ySpeed += 1.0f;
	y += ySpeed;
	if (y > 600 - 50.0f)
	{
		y = 600 - 50.0f;
		ySpeed = -30.0f;
	}
}
