#pragma once
#include <iostream>
#include "Utilidades.h"
	class DrawEngine
	{
	public:
		int alto;
		int ancho;
		std::wstring pantalla;

		DrawEngine(int _ancho, int _alto) : ancho(_ancho), alto(_alto)
		{
			pantalla.resize(alto*ancho);
		}
		~DrawEngine()
		{

		}
		void Start();
		void Draw();
		void Reset();
		void DrawAt(int x, int y, std::wstring caract);
		void StringToScreen(int x, int y, std::wstring content);

		int m_points = 0;
		int m_record = 0;
		int m_lives = 0;

		void drawExtraStuff();

		void drawPoints();
		void addPoints(int pointsToAdd);
		void drawRecord();
		void addRecord(int record);

		int leftWavesNumber;
		void restOneWave();
		void drawWaves(int numberOfWaves);

		void drawPlayerLifes();
		void loosePlayerLife();

		bool isGameOver= false;
		void drawGameOverScreen();
	};
