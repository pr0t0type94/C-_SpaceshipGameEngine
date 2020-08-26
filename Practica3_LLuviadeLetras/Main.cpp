#pragma once
#include <iostream>
#include <time.h>
#include "Engine2.h"


int main()
{
	system("chcp 65001");

	bool runMainLoop = true;
	Engine2 * engine = new Engine2(0.5f,30,80);

	while (!(GetKeyState(VK_ESCAPE) & 0x8000))
	{
		if (engine->executeNextFrame())
		{
			engine->Update();
			engine->Draw();
		}

	}
	std::cin.get();
}

