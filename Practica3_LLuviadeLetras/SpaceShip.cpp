#include "SpaceShip.h"

void SpaceShip::Start()
{

}

void SpaceShip::Tick()
{
	transform.x += shipSpeed.speedX;
	transform.y += shipSpeed.speedY;

}

//void SpaceShip::CheckCollision(std::list<Actor*> listaDeActores)
//{
//	for (Actor *actor : listaDeActores)
//	{
//		if (this != actor)
//		{
//			if ((transform.x+shipSpeed.speedX) == actor->transform.x  & transform.y == actor->transform.y)
//			{
//				m_thisActorHasToBeDestroyed = true;
//			}
//		}
//	}
//}
