#include "SpaceShip_GameEngine.h"

void SpaceShip_GameEngine::Start()
{
	Engine2::Start();
	//generate player
	m_player = new Player(3, drawManager->alto / 2, L"C");
	AddActorToScene(m_player);
	//hookEvent(player);
	startNewGame();

}
void SpaceShip_GameEngine::checkIfGameOver()
{
	if (drawManager->m_lives <= 0)
	{
		m_isGameOver = true;
	}
	if (m_WaveSpawner->m_WavesList.size() <= 0 && checkEnemiesLeft() == false) m_isGameOver = true;
}
void SpaceShip_GameEngine::startNewGame()
{
	drawManager->m_lives = m_playerLives;
	m_isGameOver = false;
	spawnNextWave();
}

//template < typename T>
//std::pair<bool, int > findInVector(const std::list<T*>  & vecOfElements, const type_info(&element))
//{
//	std::pair<bool, int > result;
//
//	// Find given element in vector
//	auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
//
//	if (it != vecOfElements.end())
//	{
//		result.second = distance(vecOfElements.begin(), it);
//		result.first = true;
//	}
//	else
//	{
//		result.first = false;
//		result.second = -1;
//	}
//
//	return result;
//}

void SpaceShip_GameEngine::Update()
{
	//std::pair<bool, int> result = findInVector<Actor>(m_listaDeActores, typeid(Enemy));
	Engine2::Update();
	checkPlayerInput();
	if (m_player->playerHasBeenDamage) { drawManager->loosePlayerLife(); }

	checkIfGameOver();

	//SPAWN ENEMIES
	m_waveTimeCounter++;	

	spawnEnemiesAndWavesFunction();
}
void SpaceShip_GameEngine::spawnEnemiesAndWavesFunction()
{
	if (m_currentSpawnedWave->m_enemiesList.size() <= 0 && checkEnemiesLeft() == false)
	{
		spawnNextWave();
	}
	if (m_currentSpawnedWave->m_enemiesList.size() > 0) //&& TIMER.timeOut = true
	{
		if (m_waveTimeCounter >= m_currentSpawnedWave->listOfTimes.front() * 10)
		{
			m_waveTimeCounter = 0;
			spawnNextEnemy();
		}
	}
}
void SpaceShip_GameEngine::spawnNextEnemy()
{
		AddActorToScene(m_currentSpawnedWave->m_enemiesList.front());
		m_currentSpawnedWave->m_enemiesList.pop_front();
		m_currentSpawnedWave->listOfTimes.pop_front();
}
void SpaceShip_GameEngine::spawnNextWave()
{
	if (m_WaveSpawner->m_WavesList.size() > 0 )
	{
		m_currentSpawnedWave = m_WaveSpawner->m_WavesList.front();	
		m_WaveSpawner->m_WavesList.pop_front();
	}
}
bool SpaceShip_GameEngine::checkEnemiesLeft()
{
	for (Actor *a : m_listaDeActores)
	{
		if (a->type != "Player" && a->type != "PlayerBullet")
		{
			return true;
		}
	}
	return false;
}

void SpaceShip_GameEngine::Draw()
{
	drawManager->leftWavesNumber = m_WaveSpawner->m_WavesList.size();
	Engine2::Draw();

}
void SpaceShip_GameEngine::AddActorToScene(Actor * actor) 
{
		m_listaDeActores.push_back(actor);
}

template <typename T>
T clampValue(const T& n, const T& lower, const T& upper) {
	return std::fmax(lower, std::fmin(n, upper));
}
void SpaceShip_GameEngine::checkPlayerInput()
{
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		Bullet *bullet = new Bullet(m_player->transform.x + 1, m_player->transform.y, L">");
		AddActorToScene(bullet);
 	}
	
	m_player->transform.x= clampValue(m_player->transform.x, 2, drawManager->ancho-4);
	m_player->transform.y = clampValue(m_player->transform.y, 3, drawManager->alto-2);
}

void SpaceShip_GameEngine::gameOver()
{
	drawManager -> isGameOver = true;

	if (GetKeyState(VK_RETURN) & 0x8000)
	{
		//play another game

	}
}

//
//void SpaceShip_GameEngine::MyHandler1()
//{
//	drawManager->loosePlayerLife();
//}
//void SpaceShip_GameEngine::hookEvent(Player * pSource)
//{
//	
//	__hook(&Player::playerHasBeenDamage, pSource, &SpaceShip_GameEngine::MyHandler1);
//	
//}
//void SpaceShip_GameEngine::unhookEvent(Player * pSource)
//{
//	__unhook(&Player::playerHasBeenDamage, pSource, &SpaceShip_GameEngine::MyHandler1);
//
//}



