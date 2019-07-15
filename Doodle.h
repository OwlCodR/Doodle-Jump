/////////////////////
//                 //
// Code by OwlCodR //
//                 //
//    11.12.2017   //
/////////////////////

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Doodle	// Класс Дудла
{
public:
	Texture t_Texture, t_Texture2;
	Sprite s_SpriteLeft, s_SpriteRight;
	double x, y;
	string direction;

	Doodle(double x, double y)	// Конструктор
	{
		direction = "LEFT";
		this->x = x;
		this->y = y;
		t_Texture.loadFromFile("images/doodle_left.png");
		s_SpriteLeft.setTexture(t_Texture);

		t_Texture2.loadFromFile("images/doodle_right.png");
		s_SpriteRight.setTexture(t_Texture2);
	}

	void draw(RenderWindow &window)
	{
		if (direction == "RIGHT")
		{
			window.draw(s_SpriteRight);
		}
		if (direction == "LEFT")
		{
			window.draw(s_SpriteLeft);
		}
	}
};
