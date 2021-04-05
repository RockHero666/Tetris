#include "Variables.h"
#include <sstream>
#include <Windows.h>
#include <random>

//////���� /-�������-\   \\\\\\\\
 

void Reset()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			field[i][j] = 0;
		}


	dx = 0; // �������������� �����������
	rotate = 0; // ��������
	begin_color = rand() % 7; // ���� ���������
	colorNum = 1; // ������� ����
	beginGame = true; // ���������� ��� ����������� ������ ������
	n = rand() % 7; // ������� ������
	n_b; // �������� ������
	score = 0; // ���� ������
	pause = 0;
	music_is_on = 1;
	score_str = "0";

	// ���������� ��� ������� � ��������

	timer = 0;// ������� ��������� ������
	delay = 0.3; // �������� ����� ��������
	
	reset = 1;
}

bool check()
{
	for (int i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;  // �������� �������� �� ����� ����� ������ � ����
		else if (field[a[i].y][a[i].x]) return 0; // �������� �� ��� ���������� ����� �� ������ �����������

	return 1;
}


bool wingame()
{
	return score > 10000;
}

bool endGame()  // ��������  ������ � ������ ������� �������
{
	for (int i = 0; i < N; i++)
	{
		if (field[1][i])
		{
			return 1;
		}
	}
	return 0;
}


void Score(const int score, Text& text)
{
	std::ostringstream oss;
	oss << score;
	score_str = oss.str();
	text.setString(score_str);

}

void Aref_of_score(int& score, const double multip)
{
	double  result;

	result = 70 *  multip*5;
	
	score += result;
}

void Cheat()
{
	Reset();

	for (int i = 0; i < 7; i++)
	{
		
		figures[i][0] = 1;
		figures[i][1] = 3;
		figures[i][2] = 5;
		figures[i][3] = 7;
	}
}


void Event_f(RenderWindow& window)
{
	//////���� /-��������� �������-\   \\\\\\\\

	Event event;
	while (window.pollEvent(event))
	{

		if (event.type == Event::Closed)
		{
			window.close();
		}

		// ���� �� ������ ������� �� ����������?
		if (event.type == Event::KeyPressed)
		{

			if (event.key.code == Keyboard::C && Keyboard::LControl)
			{
				Cheat();
			}

			if (event.key.code == Keyboard::R)
			{
				Reset();
			}

			if (event.key.code == Keyboard::P) //  ���� ������ P �� ������ ����������� � �������� ���������
			{
				if (!pause)
					pause = 1;
				else
					pause = 0;

			}

			if (event.key.code == Keyboard::M) //  ������������� ������
			{
				if (music_is_on)
					music_is_on = 0;
				else
					music_is_on = 1;

			}

			if (!pause)
			{
				// ��� ������ � ������� �����?
				if (event.key.code == Keyboard::Up) rotate = true;
				// ��� ����� ������� �����?
				else if (event.key.code == Keyboard::Left) dx = -1;
				// ��� ������� ������?
				else if (event.key.code == Keyboard::Right) dx = 1;
			}

			
		}
		//if (event.type == Event::KeyPressed)
		//{
		//	if (!pause)
		//	{
		//		// ��� ������ � ������� �����?
		//		if (event.key.code == Keyboard::W) rotate = true;
		//		// ��� ����� ������� �����?
		//		else if (event.key.code == Keyboard::A) dx = -1;
		//		// ��� ������� ������?
		//		else if (event.key.code == Keyboard::D) dx = 1;
		//	}
		//	
		//}
	}
	// ������ �� ������ "����"? �������� ������� ���������
	if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
	if (Keyboard::isKeyPressed(Keyboard::S)) delay = 0.05;
	/*if (Keyboard::isKeyPressed(Keyboard::P)) Pause();
	if (Keyboard::) Pause();*/

	/////////////////////////////


}

void Moveing()
{
	//////���� /-��������� �����������-\   \\\\\\\\


		// �������������� �����������
	for (int i = 0; i < 4; i++) {
		b[i] = a[i];
		a[i].x += dx;
	}

	// ���� ����� �� ������� ���� ����� �����������, �� ���������� ������ ����������
	if (!check()) {
		for (int i = 0; i < 4; i++)
			a[i] = b[i];
	}




	// ��������
	if (rotate && n != 6)
	{
		Point p = a[1]; // ��������� ����� ��������
		for (int i = 0; i < 4; i++)
		{
			b[i] = a[i];
			int x = a[i].y - p.y; //y-y0
			int y = a[i].x - p.x; //x-x0
			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}

		// ���� ����� �� ������� ���� ����� ��������, �� ���������� ������ ���������� 
		if (!check()) {
			for (int i = 0; i < 4; i++)
				a[i] = b[i];
		}
	}

	/////////////////////////////
}


void Logick_of_draw()
{
	//////���� /-������ ����������� � ��������-\   \\\\\\\\

		// ������ ��������� ��������� �� ����?
	if (beginGame)
	{
		beginGame = false; // ���� ���������� �����
		n = rand() % 7; // ������ ������ 
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2 +4; // +4 �������� ��������� ��������� ��� ��������� ��� ������ ���������
			a[i].y = figures[n][i] / 2;
		}
		n_b = rand() % 7; // ������ ���������
		begin_color = 1 + rand() % 8; // ���� ���������
		for (int i = 0; i < 4; i++) // ������ ������������
		{
			z[i].x = figures[n_b][i] % 2 + 4;
			z[i].y = figures[n_b][i] / 2;
		}
	}


	// �������� ��������� ���� (��� �������)
	if (timer > delay)
	{

		for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; } // ���������� ������� ���� ��� �������� �������

		if (!check())
		{

			for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum; // ������ � ���� ������ 

			for (int i = 0; i < 4; i++) // ���������� ������������
			{
				a[i] = z[i];
			}

			n = n_b; // ������� ������ = �������� ������ 
			n_b = rand() % 7;  // ������� � ��������

			for (int i = 0; i < 4; i++)  // ������ ������������
			{

				z[i].x = figures[n_b][i] % 2 +4;
				z[i].y = figures[n_b][i] / 2;
			}

			colorNum = begin_color;  // ������� ���� = �������� ���� 
			begin_color = 1 + rand() % 8; // ������� � ��������

		}
		timer = 0;
	}




	dx = 0; // ����� �����������
	rotate = 0; // ����� ��������

	if (score < 1600)  // ����� 1
	{
		delay = 0.3; // ������� � ������ ����� ��������� �� ����
	}
	else if (score >= 1600 && score < 3000) // ����� 2
	{
		delay = 0.22;
	}
	else if (score >= 3000 && score < 5000) // ����� 3 
	{
		delay = 0.15;
	}
	else if (score >= 5000)				// ����� 4
	{
		delay = 0.1;
	}


	/////////////////////////////
}

void Line_logick(Text& text)
{
	//////���� /-������� ������-\   \\\\\\\\

		//----�������� �����----//
	int k = M - 1;
	double score_multip = 0;
	bool is_deleted = false;
	for (int i = M - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}

		if (count < N)
		{
			k--;

		}

		if (count >= N)
		{
			score_multip += 1.1;
			is_deleted = true;
		}
	}



	if (is_deleted||reset)
	{
		Aref_of_score(score, score_multip);
		Score(score, text); // ����������� ��� � ������ � ��������� � text 
		reset = 0;
	}


	/////////////////////////////
}

void Draw_static_obj(Sprite& sprite, Sprite &fon_s, RenderWindow& window)
{
	//////���� /-������� ������������ �����-\   \\\\\\\\

	//RenderStates rend;
	//rend.blendMode.SrcAlpha;
	//window.clear(Color::Black); // ����� ���

	window.draw(fon_s); // ��� ������

	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (field[i][j] == 0) continue; // ���� ���� �� ������� �� ������
			sprite.setTextureRect(IntRect(field[i][j] * 20, 0, 20, 20)); // ���� ��������� �� 20 ��� ���� ���������� � ����� ��������
			sprite.setPosition(j * 20, i * 20); // �����������
			sprite.move(44, 35);// �������� ��� ���
			window.draw(sprite); // ���������
		}

	/////////////////////////////
}

void Draw_in_air_and_colorize(Sprite& sprite, Sprite& begin_sprite, RenderWindow& window)
{
	//////���� /-��������� ������� � ��������������-\   \\\\\\\\

	for (int i = 0; i < 4; i++)
	{
		// ������������� ���������
		sprite.setTextureRect(IntRect(colorNum * 20, 0, 20, 20));
		// ������������� ������� ������� ������� ���������
		sprite.setPosition(a[i].x * 20, a[i].y * 20);
		sprite.move(44, 35); // ��������
		// ��������� �������

		begin_sprite.setTextureRect(IntRect(begin_color * 20, 0, 20, 20));  // ����� ������������
		begin_sprite.setPosition(z[i].x * 20, z[i].y * 20);
		begin_sprite.move(245, 17);

		window.draw(begin_sprite);
		window.draw(sprite);
	}


	/////////////////////////////
}

void Time_logick()
{
	float time1 = clock1.getElapsedTime().asSeconds();
	clock1.restart();
	timer += time1;
}

int Random() // ����� ������� 
{
	std::random_device rd; // ��������� �����
	std::mt19937 random(rd()); // � ������ ��������
	std::uniform_int_distribution<> distrib(1, 100000); // � ������������ ��������� ��� �� ����� ���� �������� �����

	return distrib(random);// ������� ��������� � ���������� �����
}


void Logick(RenderWindow& window, Text& text)
{

	Event_f(window); // ���� �� ������� �� ������ ����� ��������� ��������� �������

	if(!wingame())
	if (!endGame())
	{
		if (!pause)
		{
			Time_logick();

			Moveing();

			Logick_of_draw();

			Line_logick(text);
		}
	}
	
}


void Draw(Sprite& sprite, Sprite& fon_s, Sprite& begin_sprite,Text &pause_text, Text& game_text, Text& over_text, Text& gamew_text, Text& win_text, RenderWindow& window)
{
	
		Draw_static_obj(sprite, fon_s, window);

		Draw_in_air_and_colorize(sprite, begin_sprite, window);
	
		if (pause)
			window.draw(pause_text); // ���� ���� �� ����� �������� �������
		

		if (endGame())
		{
			window.draw(game_text);
			window.draw(over_text);
		}

		if (wingame())
		{
			window.draw(gamew_text);
			window.draw(win_text);
		}
}

void Music_logic(Music & music)
{

	
	if (music_is_on)
	{
		if (music_first_on)
		{
			music.play();//������������� ������
			music_first_on = 0;
		}
	}
	else
	{
		music.pause();
		music_first_on = 1;
	}
}
