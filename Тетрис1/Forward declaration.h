#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;


void Reset();
bool check();
bool wingame();
bool endGame();
void Score(const int score, Text& text);
void Aref_of_score(int& score, const double multip);
void Event_f(RenderWindow& window);
void Moveing();
void Logick_of_draw();
void Line_logick(Text& text);
void Draw_static_obj(Sprite& sprite, Sprite& fon_s, RenderWindow& window);
void Draw_in_air_and_colorize(Sprite& sprite, Sprite& begin_sprite, RenderWindow& window);
void Time_logick();
int Random();
void Logick(RenderWindow& window, Text& text);
void Draw(Sprite& sprite, Sprite& fon_s, Sprite& begin_sprite, Text& pause_text, Text& game_text, Text& over_text, Text& gamew_text, Text& win_text, RenderWindow& window);
void Music_logic(Music& music);