#pragma once
#include <list>
#include "GameObject.h"
#include "DrawEngine.h"
class Actor : public GameObject
{

public:
	std::wstring shape;

	Actor() {}
	Actor(int _x, int _y, std::wstring _shape): GameObject(_x,_y)
	{
		shape = _shape;
		Start();
	}
	~Actor()
	{

	} 
	

	void virtual Start() =0;
	void virtual Tick()=0;
	void virtual CheckCollision(std::list <Actor*> listaDeActores);

	bool m_thisActorHasToBeDestroyed = false;


	std::string type;
	int pointsWhenDie;
};

