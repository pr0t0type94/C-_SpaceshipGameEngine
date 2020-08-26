#pragma once
#include <Windows.h>
#include <time.h>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include "DrawEngine.h"
#include "TimeManager.h"
#include "Utilidades.h"
#include "Actor.h"
#include "SpaceShip.h"
#include "ExplosionClass.h"
class Engine2
{
public:
	TimeManager * timeManager;
	DrawEngine * drawManager;
	
	Engine2(float _deltaTime, int _ancho, int _alto) : timeManager(new TimeManager(_deltaTime)), drawManager(new DrawEngine(_ancho, _alto))
	{
	}
	~Engine2() {

		for (Actor *a : m_listaDeActores)
			delete a;

		m_listaDeActores.clear();
		drawManager->pantalla.clear();
		OnApplicationQuit();

		delete timeManager;
		delete drawManager;
	}

    std::list<Actor*> m_listaDeActores;
	std::list<ExplosionClass*> m_listaDeExplosiones;

	virtual void Start();
	
	bool executeNextFrame();

	virtual void Update();
	virtual void Draw();

	void CheckActorsCollision();
	void DestroyCollidedActors();
	void createActorsExplosions(std::list<ExplosionClass*> listaDeExplosiones);

	void MoveActors();
	void DrawActors();

	int m_recordToWrite;
	int m_recordFromFile;

	int readRecordFile();
	void writeRecordFile();
	int compareRecords();

	void OnApplicationQuit();
};

