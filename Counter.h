/////////////////////
//                 //
// Code by OwlCodR //
//                 //
//    11.12.2017   //
/////////////////////

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Counter	// ����� - �������
{
public:
	Font f_Font;
	Text t_Count;
	int Count;

	Counter(int x, int y)
	{
		Count = 0;
		f_Font.loadFromFile("arial.ttf");// ��������� �����
		t_Count.setString("Count: " + to_string(Count));	// ������������� ������
		t_Count.setFont(f_Font);		// ������������� ����� - f_Font
		t_Count.setCharacterSize(40);	// ������������� ������ - 40
		t_Count.setColor(Color::Black);	// ������������� ���� - ������
		t_Count.setPosition(x, y);		// ������������� �������������� - x, y
	}

	void draw(RenderWindow &window)
	{
		t_Count.setString("Count: " + to_string(Count));	// ������������� ������
		window.draw(t_Count);
	}
};
