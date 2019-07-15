/////////////////////
//                 //
// Code by OwlCodR //
//                 //
//    11.12.2017   //
/////////////////////

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game	// Класс - Игра
{
public:
	Font f_Font;
	Text t_GameOver;
	Text t_Exit;

	void Over(RenderWindow &window)
	{
		f_Font.loadFromFile("arial.ttf");

		t_GameOver.setString("Game Over!");		// Устанавливаем строку
		t_GameOver.setFont(f_Font);				// Устанавливаем шрифт - f_Font
		t_GameOver.setCharacterSize(50);		// Устанавливаем размер - 60
		t_GameOver.setColor(Color::Red);		// Устанавливаем цвет - Красный
		t_GameOver.setPosition(80, 200);		// Устанавливаем местоположение

		t_Exit.setString("Press SPACE to exit game!");// Устанавливаем строку
		t_Exit.setFont(f_Font);				// Устанавливаем шрифт - f_Font
		t_Exit.setCharacterSize(30);		// Устанавливаем размер - 30
		t_Exit.setColor(Color::Red);		// Устанавливаем цвет - Красный
		t_Exit.setPosition(30, 250);		// Устанавливаем местоположение

		window.draw(t_GameOver);
		window.draw(t_Exit);
		window.display();
		while (!Keyboard::isKeyPressed(Keyboard::Space))
		{
		}
		window.close();
	}
};
