#include "Player.h"

void Player::Start()
{
	pointsWhenDie = 0;
	type = "Player";
}

void Player::Tick()
{
	//read input
	checkPlayerInput();
}

void Player::CheckCollision(std::list <Actor*> listaDeActores)
{
	playerHasBeenDamage = false;

	for (Actor *actor : listaDeActores)
	{
		if (this !=actor)
		{
			if ((transform.x + 1 == actor->transform.x ||transform.x+1 == actor->transform.x) && transform.y == actor->transform.y)
			{
				if(actor->type!="PlayerBullet")
				playerHasBeenDamage = true;
			}
		}
	}
}


void Player::checkPlayerInput()
{
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		transform.x += 1;
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		transform.x -= 1;
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		transform.y -= 1;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		transform.y += 1;
	}


}
