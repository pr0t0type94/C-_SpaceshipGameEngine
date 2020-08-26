#include "Bullet.h"

void Bullet::Start()
{
	shipSpeed.speedX = 1;
	pointsWhenDie = 0;
	type = "PlayerBullet";
}
void Bullet::Tick()
{
	transform.x += shipSpeed.speedX;
	transform.y = transform.y;


}

void Bullet::CheckCollision(std::list<Actor*> listaDeActores)
{
	for (Actor *actor : listaDeActores)
	{
		if (this != actor)
		{
			if ((transform.x == actor->transform.x || transform.x + 1 == actor->transform.x) && transform.y == actor->transform.y)
			{
				if(actor->type!="PlayerBullet")
				m_thisActorHasToBeDestroyed = true;
			}
		}
	}
}

