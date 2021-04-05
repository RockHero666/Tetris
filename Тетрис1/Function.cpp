#include "Variables.h"
#include <sstream>
#include <Windows.h>
#include <random>

//////Блок /-функции-\   \\\\\\\\
 

void Reset()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			field[i][j] = 0;
		}


	dx = 0; // горизонтальное перемещение
	rotate = 0; // вращение
	begin_color = rand() % 7; // цвет будующего
	colorNum = 1; // текущий цвет
	beginGame = true; // переменная для отображения первой фигуры
	n = rand() % 7; // текущая фигура
	n_b; // будующая фигура
	score = 0; // очки игрока
	pause = 0;
	music_is_on = 1;
	score_str = "0";

	// Переменные для таймера и задержки

	timer = 0;// подсчет пройденых секунд
	delay = 0.3; // задержка перед падением
	
	reset = 1;
}

bool check()
{
	for (int i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;  // проверка проверка на выход влево вправо и вниз
		else if (field[a[i].y][a[i].x]) return 0; // проверка на уже записанные блоки по данным координатам

	return 1;
}


bool wingame()
{
	return score > 10000;
}

bool endGame()  // проверка  записи в блоках верхних уровней
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
	//////Блок /-обработка событий-\   \\\\\\\\

	Event event;
	while (window.pollEvent(event))
	{

		if (event.type == Event::Closed)
		{
			window.close();
		}

		// Была ли нажата клавиша на клавиатуре?
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

			if (event.key.code == Keyboard::P) //  если нажата P то логика выключается и остается отрисовка
			{
				if (!pause)
					pause = 1;
				else
					pause = 0;

			}

			if (event.key.code == Keyboard::M) //  переключатель музыки
			{
				if (music_is_on)
					music_is_on = 0;
				else
					music_is_on = 1;

			}

			if (!pause)
			{
				// Эта кнопка – стрелка вверх?
				if (event.key.code == Keyboard::Up) rotate = true;
				// Или может стрелка влево?
				else if (event.key.code == Keyboard::Left) dx = -1;
				// Или стрелка вправо?
				else if (event.key.code == Keyboard::Right) dx = 1;
			}

			
		}
		//if (event.type == Event::KeyPressed)
		//{
		//	if (!pause)
		//	{
		//		// Эта кнопка – стрелка вверх?
		//		if (event.key.code == Keyboard::W) rotate = true;
		//		// Или может стрелка влево?
		//		else if (event.key.code == Keyboard::A) dx = -1;
		//		// Или стрелка вправо?
		//		else if (event.key.code == Keyboard::D) dx = 1;
		//	}
		//	
		//}
	}
	// Нажали на кнопку "Вниз"? Ускоряем падение тетрамино
	if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
	if (Keyboard::isKeyPressed(Keyboard::S)) delay = 0.05;
	/*if (Keyboard::isKeyPressed(Keyboard::P)) Pause();
	if (Keyboard::) Pause();*/

	/////////////////////////////


}

void Moveing()
{
	//////Блок /-обработка перемещений-\   \\\\\\\\


		// Горизонтальное перемещение
	for (int i = 0; i < 4; i++) {
		b[i] = a[i];
		a[i].x += dx;
	}

	// Если вышли за пределы поля после перемещения, то возвращаем старые координаты
	if (!check()) {
		for (int i = 0; i < 4; i++)
			a[i] = b[i];
	}




	// Вращение
	if (rotate && n != 6)
	{
		Point p = a[1]; // указываем центр вращения
		for (int i = 0; i < 4; i++)
		{
			b[i] = a[i];
			int x = a[i].y - p.y; //y-y0
			int y = a[i].x - p.x; //x-x0
			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}

		// Если вышли за пределы поля после поворота, то возвращаем старые координаты 
		if (!check()) {
			for (int i = 0; i < 4; i++)
				a[i] = b[i];
		}
	}

	/////////////////////////////
}


void Logick_of_draw()
{
	//////Блок /-логика отображения и движения-\   \\\\\\\\

		// Первое появление тетрамино на поле?
	if (beginGame)
	{
		beginGame = false; // блок повторного входа
		n = rand() % 7; // первая фигура 
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2 +4; // +4 начально положение тетрамино при появлении без сдвига координат
			a[i].y = figures[n][i] / 2;
		}
		n_b = rand() % 7; // фигура будующего
		begin_color = 1 + rand() % 8; // цвет будующего
		for (int i = 0; i < 4; i++) // массив предсказания
		{
			z[i].x = figures[n_b][i] % 2 + 4;
			z[i].y = figures[n_b][i] / 2;
		}
	}


	// Движение тетрамино вниз (тик таймера)
	if (timer > delay)
	{

		for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; } // постоянное движени вниз при проверке таймера

		if (!check())
		{

			for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum; // запись в поля цветом 

			for (int i = 0; i < 4; i++) // присвоение предсказания
			{
				a[i] = z[i];
			}

			n = n_b; // текущая фигура = будующая фигура 
			n_b = rand() % 7;  // смотрим в будующие

			for (int i = 0; i < 4; i++)  // массив предсказания
			{

				z[i].x = figures[n_b][i] % 2 +4;
				z[i].y = figures[n_b][i] / 2;
			}

			colorNum = begin_color;  // текущий цвет = будующий цвет 
			begin_color = 1 + rand() % 8; // смотрим в будующие

		}
		timer = 0;
	}




	dx = 0; // сброс перемещения
	rotate = 0; // сброс вращения

	if (score < 1600)  // левел 1
	{
		delay = 0.3; // возврат в дефолт после ускорения от вниз
	}
	else if (score >= 1600 && score < 3000) // левел 2
	{
		delay = 0.22;
	}
	else if (score >= 3000 && score < 5000) // левел 3 
	{
		delay = 0.15;
	}
	else if (score >= 5000)				// левел 4
	{
		delay = 0.1;
	}


	/////////////////////////////
}

void Line_logick(Text& text)
{
	//////Блок /-игровая логика-\   \\\\\\\\

		//----ПРОВЕРКА ЛИНИИ----//
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
		Score(score, text); // конвертация инт в стринг и помещение в text 
		reset = 0;
	}


	/////////////////////////////
}

void Draw_static_obj(Sprite& sprite, Sprite &fon_s, RenderWindow& window)
{
	//////Блок /-рисовка опустившихся фигур-\   \\\\\\\\

	//RenderStates rend;
	//rend.blendMode.SrcAlpha;
	//window.clear(Color::Black); // белый фон

	window.draw(fon_s); // фон спрайт

	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (field[i][j] == 0) continue; // если цвет не записан то дальше
			sprite.setTextureRect(IntRect(field[i][j] * 20, 0, 20, 20)); // цвет множенный на 20 что дает координаты в файле текстуры
			sprite.setPosition(j * 20, i * 20); // координация
			sprite.move(44, 35);// смещение под фон
			window.draw(sprite); // отрисовка
		}

	/////////////////////////////
}

void Draw_in_air_and_colorize(Sprite& sprite, Sprite& begin_sprite, RenderWindow& window)
{
	//////Блок /-отрисовка падения и разукрашивание-\   \\\\\\\\

	for (int i = 0; i < 4; i++)
	{
		// Разукрашиваем тетрамино
		sprite.setTextureRect(IntRect(colorNum * 20, 0, 20, 20));
		// Устанавливаем позицию каждого кусочка тетрамино
		sprite.setPosition(a[i].x * 20, a[i].y * 20);
		sprite.move(44, 35); // смещение
		// Отрисовка спрайта

		begin_sprite.setTextureRect(IntRect(begin_color * 20, 0, 20, 20));  // вывод предсказания
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

int Random() // вихрь марсена 
{
	std::random_device rd; // случайное число
	std::mt19937 random(rd()); // с вихрем марслена
	std::uniform_int_distribution<> distrib(1, 100000); // в определенном диапазоне что бы можно было передать вихрь

	return distrib(random);// возврат диапазона с параметром вихря
}


void Logick(RenderWindow& window, Text& text)
{

	Event_f(window); // если не вынести то нечему будет проверять повторное нажатие

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
			window.draw(pause_text); // если игра на паузе включить надпись
		

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
			music.play();//воспроизводим музыку
			music_first_on = 0;
		}
	}
	else
	{
		music.pause();
		music_first_on = 1;
	}
}
