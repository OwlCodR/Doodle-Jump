/////////////////////
//                 //
// Code by OwlCodR //
//                 //
//    11.12.2017   //
/////////////////////

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Counter	// Класс - Счетчик
{
public:
	Font f_Font;
	Text t_Count;
	int Count;

	Counter(int x, int y)
	{
		Count = 0;
		f_Font.loadFromFile("arial.ttf");// Загружаем шрифт
		t_Count.setString("Count: " + to_string(Count));	// Устанавливаем строку
		t_Count.setFont(f_Font);		// Устанавливаем шрифт - f_Font
		t_Count.setCharacterSize(40);	// Устанавливаем размер - 40
		t_Count.setColor(Color::Black);	// Устанавливаем цвет - Черный
		t_Count.setPosition(x, y);		// Устанавливаем местоположение - x, y
	}

	void draw(RenderWindow &window)
	{
		t_Count.setString("Count: " + to_string(Count));	// Устанавливаем строку
		window.draw(t_Count);
	}
};
