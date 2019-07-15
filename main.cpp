/////////////////////
//                 //
// Code by OwlCodR //
//                 //
//    11.12.2017   //
/////////////////////

#include <SFML/Graphics.hpp>
#include <time.h>
#include "Doodle.h"
#include "Platform.h"
#include "Counter.h"
#include "Game.h"

using namespace std;
using namespace sf;

void draw_platforms(RenderWindow &window, vector<Platform> &VectorPlatform)
{
	// Отрисовка платформ
	for (int i(0); i < VectorPlatform.size(); i++)
	{
		window.draw(VectorPlatform[i].s_Sprite);
	}
}

int main()
{
	srand(time(0));	// Обновляем рандом
	RenderWindow window(VideoMode(400, 533), "Doodle Game!");	// Создаем окно 400x533 с названием "Doodle Game!"
	window.setFramerateLimit(60);	// Устанавливаем лимит fps - 60

	Texture t1;	// Создаем текстуру
	t1.loadFromFile("images/background.png");	// Загружаем картинку в текстуру
	Sprite sBackground(t1);	// Создаем спрайт sBackground и загружаем туда текстуру


	Platform platform(100, 530);	// Создание 1 платформы 
	vector<Platform> VectorPlatform;	// Создание вектора платформ

	for (int i(0); i < 10; i++)	// Заполняем вектор платформами
	{
		VectorPlatform.push_back(platform);
		VectorPlatform[i].x = rand() % 340 + 30;
		VectorPlatform[i].y = rand() % 500 + 30;
	}

	int h = 200;	
	float dy = 0;

	Doodle Doodle(VectorPlatform[0].x, VectorPlatform[0].y - 100);
	Counter Counter(0, 0);
	Game Game;

	while (window.isOpen())	// Пока окно открыто
	{
		Event Event;	// Создание события
		while (window.pollEvent(Event))
		{
			if (Event.type == Event::Closed)	// Если событие - Закрыть окно, то
				window.close();	// Закрыть окно
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))	// Если была нажата стрелочка вправо
		{
			Doodle.x += 3;				// Координаты по x - увеличить
			Doodle.direction = "RIGHT"; // Напрваление дудла - вправо
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))		// Если была нажата стрелочка влево
		{
			Doodle.x -= 3;				// Координаты по x - уменьшить
			Doodle.direction = "LEFT";	// Напрваление дудла - влево
		}

		dy += 0.2;
		Doodle.y += dy;
		if (Doodle.y > 560)
		{
			// Если координаты дудла по y > 560 (Т.е. он упал)
			Game.Over(window);
		}
		if (Doodle.y < h)
		{
			Doodle.y = h;
			for (int i(0); i < 10; i++)
			{
				VectorPlatform[i].y -= dy;
				if (VectorPlatform[i].y > 533)
					// Если платформа ниже 533 по y
				{
					VectorPlatform[i].y = 0;
					VectorPlatform[i].x = rand() % 280 + 30;
					// Задаем рандомное положение платформы
					Counter.Count++;
				}
			}
		}

		for (int i(0); i < 10; i++)
		{
			if ((Doodle.x + 50 > VectorPlatform[i].x) && (Doodle.x + 20 < VectorPlatform[i].x + 68) && (Doodle.y + 70 > VectorPlatform[i].y) && (Doodle.y + 70 < VectorPlatform[i].y + 14) && (dy > 0))
				// Если дудл наступил на платформу
			{
				dy = -10;
			}
		}

		for (int i(0); i < 10; i++) VectorPlatform[i].s_Sprite.setPosition(VectorPlatform[i].x, VectorPlatform[i].y);
		// Устанавливаем координаты для спрайта платформ

		Doodle.s_SpriteLeft.setPosition(Doodle.x, Doodle.y);
		Doodle.s_SpriteRight.setPosition(Doodle.x, Doodle.y);
		// Устанавливаем координаты для спрайта дудла

		window.draw(sBackground);	// Отрисовка фона
		Doodle.draw(window);		// Отрисовка дудла
		draw_platforms(window, VectorPlatform);	// Отрисовка платформ
		Counter.draw(window);		// Отрисовка счетчика

		window.display();	// Отобразить всё на экран
	}

	return 0;
}
