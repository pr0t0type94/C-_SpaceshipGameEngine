#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
class ActorsManager 
{

public:
	ActorsManager() { }
	~ActorsManager() { }


	void addActor(int _posX, int _posY, const char* type);
	void removeActor(Actor * actor);

	std::list<Actor*> m_listaDeActoresADestruir;

	//static void addActorsToDestroyList(Enemy * enemy);

	void destroyAllActorsInList();
};

