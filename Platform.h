/////////////////////
//                 //
// Code by OwlCodR //
//                 //
//    12.12.2017   //
/////////////////////
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Platform	// Класс платформы
{
public:
	Texture t_Texture;
	Sprite s_Sprite;
	int x, y;

	Platform(int x , int y)	// Конструктор
	{
		this->x = x;
		this->y = y;
		t_Texture.loadFromFile("images/platform.png");
		s_Sprite.setTexture(t_Texture);
	}
};
