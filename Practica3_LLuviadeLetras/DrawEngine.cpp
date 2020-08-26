#include "DrawEngine.h"
#include <vector>
#include <string>
#include <codecvt>

	void DrawEngine::Reset()
	{

		// ║ ╣ ╗ ╝ ╚ ╔ ╩ ╦ ╠ ═ ╬
		
		pantalla.clear();

		pantalla.append(L"╔");
		for (int i = 1; i < ancho - 1; i++) { pantalla.append(L"═"); }
		pantalla.append(L"╗\n");

		pantalla.append(L"║");
		for (int i = 1; i < ancho - 1; i++) { pantalla.append(L" "); }
		pantalla.append(L"║\n");

		pantalla.append(L"╠");
		for (int i = 1; i < ancho - 1; i++) { pantalla.append(L"═"); }
		pantalla.append(L"╣\n");

		for (int j = 3; j < alto - 1; j++)
		{
			pantalla.append(L"║");
			for (int i = 1; i < ancho - 1; i++) { pantalla.append(L" "); }
			pantalla.append(L"║\n");
		}

		pantalla.append(L"╚");
		for (int i = 1; i < ancho - 1; i++) { pantalla.append(L"═"); }
		pantalla.append(L"╝\n");

	

		drawExtraStuff();

	}
	
	void DrawEngine::Draw()
	{
		std::cout << std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(pantalla);

	}
	
	//Método para cambiar un sector del área de juego, según coordenadas  X y Y
	//Cambia el valor del area de juego por un nuevo caracter.
	void DrawEngine::DrawAt(int x, int y, std::wstring contenido)
	{
		pantalla.replace(y*(ancho+1) + x, 1, contenido);
		//pantalla.append(contenido);
	}

	void DrawEngine::StringToScreen(int x, int y, std::wstring content)
	{
		//std::wstring s = content;
		int count = 0;
		for (wchar_t currChar : content)
		{
			std::wstring newChar(1, currChar);
			pantalla.replace((y*ancho + x) + (count + 1), 1, newChar);
			count++;
		}
	}

	void DrawEngine::drawExtraStuff()
	{
		drawPoints();
		drawPlayerLifes();
		drawRecord();
		drawWaves(leftWavesNumber);

		if (isGameOver)
		{
			drawGameOverScreen();
		}
	}
	void DrawEngine::drawPoints()
	{

		StringToScreen(2, 1, L"PUNTUACIÓN: " + std::to_wstring(m_points));
	}
	void DrawEngine::addPoints(int pointsToAdd)
	{
		m_points += pointsToAdd;

	}
	void DrawEngine::drawPlayerLifes()
	{

		StringToScreen(ancho / 6.0f, 1, L"Player Lives: " +std::to_wstring(m_lives));
	}
	void DrawEngine::drawRecord()
	{
		StringToScreen(ancho / 1.15f, 1, L"RÉCORD: " + std::to_wstring(m_record));
	}

	void DrawEngine::addRecord(int record)
	{
		m_record = record;

	}
	void DrawEngine::restOneWave()
	{
		leftWavesNumber--;
	}
	void DrawEngine::drawWaves(int numberOfWaves)
	{
		StringToScreen(ancho / 2.2f, 1, L"Waves Left: " + std::to_wstring(numberOfWaves));

	}
	void DrawEngine::loosePlayerLife()
	{
		m_lives --;
	}

	void DrawEngine::drawGameOverScreen()
	{
		if (m_lives > 0)
		{
			StringToScreen(ancho / 2-1, alto /2, L"Congratulations you win!");

		}
		else
		{
			StringToScreen(ancho / 2 + 2, alto / 2, L"Game Over");

		}

		StringToScreen(ancho / 2-1, alto / 2+1, L"You scored: " + std::to_wstring(m_points) + L" points!");
		StringToScreen(ancho / 2, (alto / 2)+2, L"Press Esc to exit");


	}

