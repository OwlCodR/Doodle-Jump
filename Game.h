/////////////////////
//                 //
// Code by OwlCodR //
//                 //
//    11.12.2017   //
/////////////////////

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game	// ����� - ����
{
public:
	Font f_Font;
	Text t_GameOver;
	Text t_Exit;

	void Over(RenderWindow &window)
	{
		f_Font.loadFromFile("arial.ttf");

		t_GameOver.setString("Game Over!");		// ������������� ������
		t_GameOver.setFont(f_Font);				// ������������� ����� - f_Font
		t_GameOver.setCharacterSize(50);		// ������������� ������ - 60
		t_GameOver.setColor(Color::Red);		// ������������� ���� - �������
		t_GameOver.setPosition(80, 200);		// ������������� ��������������

		t_Exit.setString("Press SPACE to exit game!");// ������������� ������
		t_Exit.setFont(f_Font);				// ������������� ����� - f_Font
		t_Exit.setCharacterSize(30);		// ������������� ������ - 30
		t_Exit.setColor(Color::Red);		// ������������� ���� - �������
		t_Exit.setPosition(30, 250);		// ������������� ��������������

		window.draw(t_GameOver);
		window.draw(t_Exit);
		window.display();
		while (!Keyboard::isKeyPressed(Keyboard::Space))
		{
		}
		window.close();
	}
};
