#include "Enemy.h"
void Enemy::Start()
{
	shipSpeed.speedX = -1;
	shipSpeed.speedY = 0;
}
void Enemy::Tick()
{
	transform.x += shipSpeed.speedX;
	transform.y = transform.y;
}

void Enemy::CheckCollision(std::list <Actor*> listaDeActores)
{
	for (Actor *actor : listaDeActores)
	{
		if (this != actor)
		{
			if ((transform.x == actor->transform.x || transform.x - 1 == actor->transform.x) && transform.y == actor->transform.y)
			{
				if (actor->type == "PlayerBullet" || actor->type == "Player")
				{
					m_thisActorHasToBeDestroyed = true;
				}
			}
		}
	}
}