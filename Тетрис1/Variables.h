#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;


static const int M = 20; // высота игрового поля
const int N = 10; // ширина игрового поля

int field[M][N] = { 0 }; // игровое поле




	
	

	// Массив фигурок-тетрамино
	int figures[7][4] =
	{
		1,3,5,7, // I
		2,4,5,7, // S
		3,5,4,6, // Z
		3,5,4,7, // T
		2,3,5,7, // L
		3,5,7,6, // J
		2,3,4,5, // O
	};

	struct Point
	{
		int x, y;
	}
	a[4], b[4], z[4];

	// a - текущая фигура  b - дубль a для  возврата в исходное положение в случае выхода за поле 
	// z - фигура будующего



	


	int dx = 0; // горизонтальное перемещение
	bool rotate = 0; // вращение
	int begin_color = rand() % 7; // цвет будующего
	int colorNum = 1; // текущий цвет
	bool beginGame = true; // переменная для отображения первой фигуры
	int n = rand() % 7; // текущая фигура
	int n_b; // будующая фигура
	int score; // очки игрока
	bool pause = 0;
	bool music_is_on = 1;
	bool music_first_on = 1; // для включения и выключения впервый раз
	std::string score_str;// для рестарта счета
	bool reset=0; // переменная ресет для нужд

	// Переменные для таймера и задержки
	

	Clock clock1;// класс вермени куда записывается время
	
	float timer = 0;// подсчет пройденых секунд
	float delay = 0.3; // задержка перед падением