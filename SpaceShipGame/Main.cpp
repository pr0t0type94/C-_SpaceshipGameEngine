#include "SpaceShip_GameEngine.h"

int main()
{
	system("chcp 65001");
	SpaceShip_GameEngine * m_gameEngine = new SpaceShip_GameEngine(0.5f, 120, 30);
	m_gameEngine->Start();

		while (!(GetKeyState(VK_ESCAPE) & 0x8000))
		{

			if (!m_gameEngine->m_isGameOver)
			{
				if (m_gameEngine->executeNextFrame())
				{
					system("cls");
					m_gameEngine->Update();
					m_gameEngine->Draw();

				}
			}
			else
			{
				system("cls");
				m_gameEngine->gameOver();
				m_gameEngine->Draw();

			}

		}

			m_gameEngine->OnApplicationQuit();
			exit(1);
	
	std::cin.get();


}