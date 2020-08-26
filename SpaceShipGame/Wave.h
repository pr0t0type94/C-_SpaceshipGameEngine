#pragma once
#include <vector>
#include "SimpleEnemy.h"
#include "DoubleEnemy.h"
#include "HardEnemy.h"

class Wave
{
public:
	std::list <Enemy*> m_enemiesList;

	void AddEnemiesToWaveList(int posX, int posY, std::string type);

	std::list<int> listOfTimes;

};

