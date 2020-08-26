#pragma once
#include "Actor.h"
class SpaceShip : public Actor
{

	struct speed
	{
		float speedX;
		float speedY;

	};

public:
	speed shipSpeed;
	SpaceShip() {}

	SpaceShip(int _x, int _y, std::wstring _shape) : Actor(_x, _y, _shape)
	{

	}
	~SpaceShip()
	{
	}

	void virtual Start() override;

	void virtual Tick() override;
};


