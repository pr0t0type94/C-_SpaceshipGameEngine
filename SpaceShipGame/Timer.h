#pragma once
#include <chrono>
#include <iostream>
#include "TimeManager.h"
#include <Windows.h>

class Timer
{

public:
		std::chrono::duration<float> _maxTime;
		std::chrono::time_point<std::chrono::steady_clock> inicio;
		std::chrono::seconds elapsedSeconds;

		bool timeOut = false;
		Timer() 
		{
		}		
		~Timer()
		{
			//delete Timer;
		}

		int counter = 1;

		void startTimer(std::chrono::seconds _maxTime);
};

