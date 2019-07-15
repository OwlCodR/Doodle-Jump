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
	// ��������� ��������
	for (int i(0); i < VectorPlatform.size(); i++)
	{
		window.draw(VectorPlatform[i].s_Sprite);
	}
}

int main()
{
	srand(time(0));	// ��������� ������
	RenderWindow window(VideoMode(400, 533), "Doodle Game!");	// ������� ���� 400x533 � ��������� "Doodle Game!"
	window.setFramerateLimit(60);	// ������������� ����� fps - 60

	Texture t1;	// ������� ��������
	t1.loadFromFile("images/background.png");	// ��������� �������� � ��������
	Sprite sBackground(t1);	// ������� ������ sBackground � ��������� ���� ��������


	Platform platform(100, 530);	// �������� 1 ��������� 
	vector<Platform> VectorPlatform;	// �������� ������� ��������

	for (int i(0); i < 10; i++)	// ��������� ������ �����������
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

	while (window.isOpen())	// ���� ���� �������
	{
		Event Event;	// �������� �������
		while (window.pollEvent(Event))
		{
			if (Event.type == Event::Closed)	// ���� ������� - ������� ����, ��
				window.close();	// ������� ����
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))	// ���� ���� ������ ��������� ������
		{
			Doodle.x += 3;				// ���������� �� x - ���������
			Doodle.direction = "RIGHT"; // ����������� ����� - ������
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))		// ���� ���� ������ ��������� �����
		{
			Doodle.x -= 3;				// ���������� �� x - ���������
			Doodle.direction = "LEFT";	// ����������� ����� - �����
		}

		dy += 0.2;
		Doodle.y += dy;
		if (Doodle.y > 560)
		{
			// ���� ���������� ����� �� y > 560 (�.�. �� ����)
			Game.Over(window);
		}
		if (Doodle.y < h)
		{
			Doodle.y = h;
			for (int i(0); i < 10; i++)
			{
				VectorPlatform[i].y -= dy;
				if (VectorPlatform[i].y > 533)
					// ���� ��������� ���� 533 �� y
				{
					VectorPlatform[i].y = 0;
					VectorPlatform[i].x = rand() % 280 + 30;
					// ������ ��������� ��������� ���������
					Counter.Count++;
				}
			}
		}

		for (int i(0); i < 10; i++)
		{
			if ((Doodle.x + 50 > VectorPlatform[i].x) && (Doodle.x + 20 < VectorPlatform[i].x + 68) && (Doodle.y + 70 > VectorPlatform[i].y) && (Doodle.y + 70 < VectorPlatform[i].y + 14) && (dy > 0))
				// ���� ���� �������� �� ���������
			{
				dy = -10;
			}
		}

		for (int i(0); i < 10; i++) VectorPlatform[i].s_Sprite.setPosition(VectorPlatform[i].x, VectorPlatform[i].y);
		// ������������� ���������� ��� ������� ��������

		Doodle.s_SpriteLeft.setPosition(Doodle.x, Doodle.y);
		Doodle.s_SpriteRight.setPosition(Doodle.x, Doodle.y);
		// ������������� ���������� ��� ������� �����

		window.draw(sBackground);	// ��������� ����
		Doodle.draw(window);		// ��������� �����
		draw_platforms(window, VectorPlatform);	// ��������� ��������
		Counter.draw(window);		// ��������� ��������

		window.display();	// ���������� �� �� �����
	}

	return 0;
}
