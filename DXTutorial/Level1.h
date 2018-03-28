#pragma once
#include "GameLevel.h"
class Level1 : public GameLevel
{
private:
	float y;
	float ySpeed;
public:
	Level1();
	~Level1();

	// Inherited via GameLevel
	void Load() override;
	void UnLoad() override;
	void Render() override;
	void Update() override;
};

