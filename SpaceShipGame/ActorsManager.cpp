#include "ActorsManager.h"

void ActorsManager::addActor(int _posX, int _posY, const char* type)
{
	/*if (type == "Player")
	{
		Player *player = new Player(_posX, _posY, L"@");
		m_listaDeActores.push_back(player);
		std::cout << "x:" << player->transform.x << "y: " << player->transform.y
			<< "numero de actores: " << m_listaDeActores.size() << std::endl;
	}

	else if (type == "SimpleEnemy") { Enemy *SimpleEnemy = new Enemy(_posX, _posY, L"|"); m_listaDeActores.push_back(SimpleEnemy); }
	else if (type == "DoubleEnemy") { Enemy *DoubleEnemy = new Enemy(_posX, _posY, L"||"); m_listaDeActores.push_back(DoubleEnemy); }
	else if (type == "HardEnemy") { Enemy *HardEnemy = new Enemy(_posX, _posY, L"<"); m_listaDeActores.push_back(HardEnemy); }*/
}

void ActorsManager::removeActor(Actor * actor)
{
	//m_listaDeActores.remove(actor);
	//delete actor;
}

//void ActorsManager::addActorsToDestroyList(Enemy * enemy)
//{
//	m_listaDeActoresADestruir.push_back(enemy);
//}
//
//void ActorsManager::destroyAllActorsInList()
//{
//
//	for (Actor *actor : m_listaDeActoresADestruir)
//	{
//		delete actor;
//	}
//}

//std::list<Actor*> ActorsManager::ReturnFullActorsList()
//{
//
//	return m_listaDeActores;
//}
