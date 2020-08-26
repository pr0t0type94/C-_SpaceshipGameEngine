#pragma once
#include "Engine2.h"
#include "Player.h"
#include "Bullet.h"
#include "ActorsManager.h"
#include "WaveSpawner.h"
#include <algorithm>
#include "Timer.h"
#include <thread>
class SpaceShip_GameEngine : public Engine2
{
public:
	int m_currentPoints;
	int m_maxRecord;
	int m_playerLives = 3;

	Player * m_player; 
	WaveSpawner *m_WaveSpawner = new WaveSpawner();

	SpaceShip_GameEngine(float deltaTime,int ancho, int alto) : Engine2(deltaTime,ancho,alto)
	{

	}
	~SpaceShip_GameEngine()	
	{
		delete m_player;
		delete m_WaveSpawner;
	}
	
	void Start() override;
	void Update() override;
	void Draw() override;

	void AddActorToScene(Actor * actor);
	void checkPlayerInput();

	Wave *m_currentSpawnedWave;
	void spawnEnemiesAndWavesFunction();
	void spawnNextEnemy();
	void spawnNextWave();
	bool checkEnemiesLeft();
	int m_waveTimeCounter;

	void gameOver();
	bool m_isGameOver;
	void checkIfGameOver();
	void startNewGame();

	/*struct newGame
	{
		Player *_player;
		int _newGamePoints = 0;
		int _newGameLives = 3;

		newGame(Player *player, int newGamePoints, int newGameLives) : _player(player), _newGamePoints(newGamePoints) , _newGameLives(newGameLives)
		{
			
		}
	}*/
	
	//void MyHandler1();

	/*void hookEvent(Player* pSource);
	void unhookEvent(Player* pSource);*/


	//void fillspawnactors()
};

