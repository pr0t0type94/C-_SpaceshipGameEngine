#include "Timer.h"

void Timer::startTimer(std::chrono::seconds _maxTime)
{
	
		inicio = std::chrono::high_resolution_clock::now();




		if (elapsedSeconds >= _maxTime)
		{
			timeOut = true;
		}
	
		std::chrono::duration<float> elapsed = std::chrono::high_resolution_clock::now() - inicio;
	
		elapsedSeconds.operator+=(std::chrono::duration_cast<std::chrono::seconds>(elapsed));



}

