#include "WaveSpawner.h"

void WaveSpawner::Init()
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError eResult = doc.LoadFile("WaveSpawnerDocument.xml");

	doc.LoadFile("./Data/WaveSpawnerDocument.xml");

	std::cout << doc.ErrorID() << std::endl;;

	tinyxml2::XMLElement *play = doc.FirstChildElement("PLAY");
	if (play)
	{

		tinyxml2::XMLElement *waves_To_Spawn = play->FirstChildElement("WAVES_TO_SPAWN");
		if (waves_To_Spawn)
		{
			tinyxml2::XMLElement *waves = waves_To_Spawn->FirstChildElement("WAVE");

			while (waves)	//para iterar en más de un elemento de cualquier tipo
			{
				Wave * newWave = new Wave();
				m_WavesList.push_back(newWave);

				tinyxml2::XMLElement *enemies = waves->FirstChildElement("Enemy");

				while (enemies)
				{

					newWave->AddEnemiesToWaveList(enemies->IntAttribute("posX"), enemies->IntAttribute("posY"),enemies->Attribute("type"));
					newWave->listOfTimes.push_back(enemies->IntAttribute("spawnTime"));
					enemies = enemies->NextSiblingElement("Enemy");	//para ir al siguiente elemento
				}

				waves = waves->NextSiblingElement("WAVE");	//para ir al siguiente elemento

			}

		}

	}

}
