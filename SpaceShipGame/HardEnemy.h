#pragma once
#include "Enemy.h"
class HardEnemy :
	public Enemy
{
public:
	HardEnemy(int posX, int posY, std::wstring _shape) : Enemy(posX, posY, _shape)
	{
		type = "Hard";
		pointsWhenDie = 20;
		shipSpeed.speedX = -2;
	}
};

