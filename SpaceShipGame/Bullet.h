#pragma once
#include <SpaceShip.h>
class Bullet : public SpaceShip
{
	//start cojer la pos del player +1
public:
	Bullet(int _x, int _y, std::wstring _shape) : SpaceShip(_x, _y, _shape)
	{
		Start();
	}
	~Bullet()
	{

	}

	void Start() override;
	void Tick() override;
	void CheckCollision(std::list<Actor*> list);
};

