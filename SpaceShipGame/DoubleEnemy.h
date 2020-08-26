#pragma once
#include "Enemy.h"
class DoubleEnemy :
	public Enemy
{
public:
	DoubleEnemy(int posX, int posY, std::wstring _shape) : Enemy(posX, posY, _shape)
	{
		type = "Double";
		pointsWhenDie = 10;
	}
};

