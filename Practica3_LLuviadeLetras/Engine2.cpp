#pragma once
#include <iostream>
#include "Engine2.h"

	void Engine2::Start()
	{
		drawManager->m_record = readRecordFile();
	}

#pragma region Update

	bool Engine2::executeNextFrame()
	{
		return timeManager->shouldExecuteNextFrame();
	}
	void Engine2::Update()
	{
			//createActorsExplosions(m_listaDeExplosiones);
			MoveActors();
			CheckActorsCollision();
			DestroyCollidedActors();
		
	}
	void Engine2::CheckActorsCollision()
	{
		if (m_listaDeActores.size() >0) {

			for (Actor * actor : m_listaDeActores)
			{
				actor->CheckCollision(m_listaDeActores);
			}
		}
	}

	void Engine2::DestroyCollidedActors()
	{
		if (m_listaDeActores.size() >0) {
			{
				for (std::list<Actor*>::iterator iter = m_listaDeActores.begin(); iter != m_listaDeActores.end();)
				{
					if (iter._Ptr->_Myval->m_thisActorHasToBeDestroyed)
					{					
						drawManager->addPoints(iter._Ptr->_Myval->pointsWhenDie);
						ExplosionClass * expl = new ExplosionClass(iter._Ptr->_Myval->transform.x, iter._Ptr->_Myval->transform.y);
						m_listaDeExplosiones.push_back(expl);
						iter = m_listaDeActores.erase(iter);
					}
					else if (iter._Ptr->_Myval->transform.x >= drawManager->ancho - 2)
					{
						iter = m_listaDeActores.erase(iter);
					}
					else if (iter._Ptr->_Myval->transform.x <= 0)
					{
						iter = m_listaDeActores.erase(iter);
					}
					else
					{
						iter++;
					}
				}
			}
		}
	}
	void Engine2::createActorsExplosions(std::list<ExplosionClass*> listaDeExplosiones)
	{
		for (ExplosionClass * expl : listaDeExplosiones)
		{
			if (expl->_x == 3)
			{
				drawManager->StringToScreen(expl->_x, expl->_y, L"");
				drawManager->StringToScreen(expl->_x, expl->_y - 1, L"-");
				drawManager->StringToScreen(expl->_x, expl->_y + 1, L"-");
				drawManager->StringToScreen(expl->_x + 1, expl->_y, L"|");
			}
			else
			{
				drawManager->StringToScreen(expl->_x, expl->_y, L"*");
				drawManager->StringToScreen(expl->_x, expl->_y - 1, L"-");
				drawManager->StringToScreen(expl->_x, expl->_y + 1, L"-");
				drawManager->StringToScreen(expl->_x + 1, expl->_y, L"|");
				drawManager->StringToScreen(expl->_x - 1, expl->_y, L"|");
			}
		}
	}

	void Engine2::MoveActors()
	{
		if(m_listaDeActores.size()>0)
		for (Actor *actor : m_listaDeActores)
		{
			actor->Tick();
		}
	}

#pragma endregion

#pragma region Draw

	void Engine2::Draw() 
	{ 
		drawManager->Reset();
		DrawActors();

		drawManager->Draw();
	}
	void Engine2::DrawActors()
	{
		if (m_listaDeActores.size() >0)
		for (Actor *actor : m_listaDeActores)
		{
			drawManager->DrawAt(actor->transform.x, actor->transform.y, actor->shape);
			
		}
	}

#pragma endregion

#pragma region ReadRecordFromFile

	int Engine2::readRecordFile()
	{
		std::ifstream _readFile("./Data/recordFile.txt");
		int i;
		if (_readFile.is_open())
		{			
			while (_readFile >> i)
			{
				m_recordFromFile = i;
			}
		}
		return m_recordFromFile;
	}
	int Engine2::compareRecords()
	{	
		if (drawManager->m_points > m_recordFromFile)
		{
			m_recordToWrite = drawManager->m_points;
		}
		else
		{
			m_recordToWrite = m_recordFromFile;
		}

		return m_recordToWrite;
	}
	void Engine2::writeRecordFile()
	{
		std::ofstream _recordFile("./Data/recordFile.txt");
		compareRecords();
		
		int i;
		if (_recordFile.is_open())
		{
			
			_recordFile << compareRecords();

		}
		_recordFile.close();
	}
	void Engine2::OnApplicationQuit()
	{
		writeRecordFile();
	}

#pragma endregion



