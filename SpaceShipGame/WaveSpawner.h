#pragma once
#include "ActorsManager.h"
#include "TimeManager.h"
#include "Enemy.h"
#include "Wave.h"
#include "tinyxml2.h"

class WaveSpawner
{
public:
	WaveSpawner()
	{
		Init();

	}
	void Init();

	std::list <Wave*> m_WavesList;
	
};

