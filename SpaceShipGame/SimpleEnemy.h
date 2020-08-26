#pragma once
#include "Enemy.h"
class SimpleEnemy : public Enemy
{
public:
	SimpleEnemy(int posX, int posY, std::wstring _shape) : Enemy(posX,posY,_shape)
	{
		type = "Simple";
		pointsWhenDie = 5;
	}
};

