#pragma once
#include "Utilidades.h"
#include "TimeManager.h"


	float TimeManager::GetElapsedTime() const
	{
		return m_elapsedTime;

	}

	bool TimeManager::shouldExecuteNextFrame()
	{
		//float dt = (clock() - m_lastFrameTime) / float(CLOCKS_PER_SEC);

		clock_t timeBetweenFrames = clock() - m_lastFrameTime;
		
		//m_ciclosPorFrame /= float(CLOCKS_PER_SEC);

		if (timeBetweenFrames >= (m_ciclosPorFrame / float(CLOCKS_PER_SEC)))
		{
			m_shouldExecuteNextFrame = true;
			m_lastFrameTime = clock() - (timeBetweenFrames - m_ciclosPorFrame);

		}

		 m_elapsedTime += (timeBetweenFrames / CLOCKS_PER_SEC);
		 
		return m_shouldExecuteNextFrame;
	}

	
