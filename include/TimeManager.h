#pragma once
#include <time.h>
#include <iostream>
#include <chrono>


class TimeManager
{
	bool m_shouldExecuteNextFrame;
	clock_t m_lastFrameTime;
	float m_desiredDeltaTime;
	const clock_t m_ciclosPorFrame;

	float m_elapsedTime;
	float _maxTime;
	bool m_stopTimer = false;

public:
	TimeManager(float _desiredDeltaTime) : m_shouldExecuteNextFrame(false), m_lastFrameTime(clock()), m_desiredDeltaTime(_desiredDeltaTime), m_ciclosPorFrame(_desiredDeltaTime * float(CLOCKS_PER_SEC))
	{

	}

	float GetElapsedTime() const;



	bool shouldExecuteNextFrame();

	
};
