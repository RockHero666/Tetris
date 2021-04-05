#include "Forward declaration.h"
#include<Windows.h>

INT  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
	srand(Random());


	//////Блок /-загрузки и переменные-\   \\\\\\\\

	Texture texture, fon;
	texture.loadFromFile("Tetris_blocks1.png");		
	fon.loadFromFile("Tetris_fon.png") ;
	

	Sprite sprite(texture), begin_sprite(texture), fon_s(fon);

	//"Q:\\C++ project\\SFML_Textures\\

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text text("0", font, 24);
	text.setFillColor(Color::Red);
	text.setPosition(303, 128);
	text.setStyle(Text::Bold);
	text.setOutlineColor(Color::Blue);
	text.setOutlineThickness(1);


	Text pause_text("PAUSE", font, 48);
	pause_text.setFillColor(Color::Red);
	pause_text.setStyle(Text::Bold);
	pause_text.setOutlineColor(Color::Black);
	pause_text.setOutlineThickness(2);
	pause_text.setPosition(61, 150);

	Text GAME_text("GAME", font, 48);
	GAME_text.setFillColor(Color::Red);
	GAME_text.setStyle(Text::Bold);
	GAME_text.setOutlineColor(Color::Black);
	GAME_text.setOutlineThickness(2);
	GAME_text.setPosition(71, 150);

	Text OVER_text("OVER", font, 48);
	OVER_text.setFillColor(Color::Red);
	OVER_text.setStyle(Text::Bold);
	OVER_text.setOutlineColor(Color::Black);
	OVER_text.setOutlineThickness(2);
	OVER_text.setPosition(74, 200);

	Text GAMEw_text("GAME", font, 48);
	GAMEw_text.setFillColor(Color::Green);
	GAMEw_text.setStyle(Text::Bold);
	GAMEw_text.setOutlineColor(Color::Black);
	GAMEw_text.setOutlineThickness(2);
	GAMEw_text.setPosition(71, 150);

	Text WIN_text("WIN", font, 48);
	WIN_text.setFillColor(Color::Green);
	WIN_text.setStyle(Text::Bold);
	WIN_text.setOutlineColor(Color::Black);
	WIN_text.setOutlineThickness(2);
	WIN_text.setPosition(97, 200);




	Music music;//создаем объект музыки
	music.openFromFile("voxel.ogg");//загружаем файл
	music.setVolume(10);
	music.setLoop(1);
	
	/////////////////////////////

	
	RenderWindow window(VideoMode(420, 580), "Tetris");
	

	while (window.isOpen())
	{

		Music_logic(music);
		Logick(window,text);
		Draw(sprite,fon_s,begin_sprite, pause_text, GAME_text, OVER_text, GAMEw_text, WIN_text,window);
		
		


		window.draw(text);		
		window.display();

	}
}








