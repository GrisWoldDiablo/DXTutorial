#pragma once
#include "Graphics.h"
class GameLevel
{
protected:
	static Graphics* gfx;
public:
	static void Init(Graphics* graphics);

	virtual void Load()   = 0;
	virtual void UnLoad() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
	GameLevel();
	~GameLevel();
};

