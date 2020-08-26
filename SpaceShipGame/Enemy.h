#pragma once
#include "SpaceShip.h"
#include "ActorsManager.h"
#include "DrawEngine.h"
#include <stdio.h>

class Enemy : public SpaceShip
{

public:
	Enemy(int _x, int _y, std::wstring _shape) : SpaceShip(_x, _y,_shape)
	{
		Start();
		
	}
	~Enemy()
	{
		
		//delete actor from listaDeActores
		//add points to draw manager
	}
	
	//void destroyObject();
	void Start() override;
	void Tick() override;
	void CheckCollision(std::list <Actor*> listaDeActores) override;
};

