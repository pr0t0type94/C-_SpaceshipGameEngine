#pragma once
#include <Windows.h>
#include "SpaceShip.h"
#include "Bullet.h"


class Player : public SpaceShip
{
public:
	Player(int _x, int _y, std::wstring _shape) : SpaceShip(_x, _y, _shape)
	{
		Start();
	}

	void Start() override;
	void Tick() override;
	void CheckCollision(std::list <Actor*> listaDeActores) override;

	void checkPlayerInput();
	bool playerHasBeenDamage = false;

	//__event void playerHasBeenDamage();
};

