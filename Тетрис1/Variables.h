#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;


static const int M = 20; // ������ �������� ����
const int N = 10; // ������ �������� ����

int field[M][N] = { 0 }; // ������� ����




	
	

	// ������ �������-���������
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

	// a - ������� ������  b - ����� a ���  �������� � �������� ��������� � ������ ������ �� ���� 
	// z - ������ ���������



	


	int dx = 0; // �������������� �����������
	bool rotate = 0; // ��������
	int begin_color = rand() % 7; // ���� ���������
	int colorNum = 1; // ������� ����
	bool beginGame = true; // ���������� ��� ����������� ������ ������
	int n = rand() % 7; // ������� ������
	int n_b; // �������� ������
	int score; // ���� ������
	bool pause = 0;
	bool music_is_on = 1;
	bool music_first_on = 1; // ��� ��������� � ���������� ������� ���
	std::string score_str;// ��� �������� �����
	bool reset=0; // ���������� ����� ��� ����

	// ���������� ��� ������� � ��������
	

	Clock clock1;// ����� ������� ���� ������������ �����
	
	float timer = 0;// ������� ��������� ������
	float delay = 0.3; // �������� ����� ��������