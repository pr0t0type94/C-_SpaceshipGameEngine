#include "Actor.h"

void Actor::Start() {}
//void Actor::Tick() {}
void Actor::CheckCollision(std::list<Actor*> listaDeActores)
{

	for (Actor *actor : listaDeActores)
	{
		if (this != actor)
		{
			if (transform.x == actor->transform.x & transform.y == actor->transform.y)
			{			
				m_thisActorHasToBeDestroyed = true;
			}
		}
	}

}


