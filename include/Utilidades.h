#pragma once
#include <conio.h>
#include <iostream>
#include <Windows.h>

#define UP 72;
#define DOWN 75;
#define LEFT 78;
#define RIGHT 80;

#define piel 176        //Textura de piel del Snake
#define comida 64       //Car�cter a mostrar como comida
#define espacio 0       //Car�cter de espacio vac�o.
#define paredLateral 186       //Textura de la pared del �rea de juego.
#define paredSuperior 205       //Textura de la pared del �rea de juego.

#define limY 60         //Tama�o o limite en Y del �rea de juego
#define limX 20         //Tama�o o limite en X del �rea de juego
#define maxPoints 500   //Puntaci�n m�xima para ganar el juego.

#define LIN_HOR_SALIR      205//Lineas Horizontales
#define LIN_VER_SALIR      186//Lineas Vericales
#define ESQ_SUP_DER_SALIR  201//Esquina superior Derecha
#define ESQ_SUP_IZQ_SALIR  200//Esquina superior Izquierda
#define ESQ_INF_DER_SALIR  187//Esquina inferior Derecha
#define ESQ_INF_IZQ_SALIR  188//Esquina inferior Izquierda

#define DEBUGLOG(log){std::cout << "log" << std::endl}

class Utilidades
{
public:
	//Funcion para capturar la tacla digitada omitiendo el el Enter.
	static int GetKey() {

		int Tecla = _getch();
		if (Tecla == 0xE0 || Tecla == 0)
			Tecla = _getch();
		return Tecla;

	}


};

