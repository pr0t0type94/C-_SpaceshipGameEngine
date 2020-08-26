#include "Wave.h"

void Wave::AddEnemiesToWaveList(int posX, int posY,std::string type)
{
	
	Enemy *enemyToList;
	if (type == "Simple")
	{
		enemyToList = new SimpleEnemy(posX, posY, L"|");
	}
	else if (type == "Double")
	{
		enemyToList = new DoubleEnemy(posX, posY, L"{");
	}
	else if (type == "Hard")
	{
		enemyToList = new HardEnemy(posX, posY, L"<");
	}
	

	m_enemiesList.push_back(enemyToList);

}
