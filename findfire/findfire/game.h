#include <iostream>
#include <Windows.h>

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE
};

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Game
{
public:
	void Init()//map generation, player position initialize
	{
		int i, j;

		for (i = 1; i < 22; i++)
		{
			for (j = 1; j < 22; j++)
			{
				World[i][j] = ' ';
			}
		}

		//wall = @
		//-----------------------
		for (i = 0; i < 23; i++)
		{
			World[i][0] = '@';
		}
		for (i = 0; i < 23; i++)
		{
			World[i][22] = '@';
		}
		for (i = 1; i < 22; i++)
		{
			World[0][i] = '@';
		}
		for (i = 1; i < 22; i++)
		{
			World[22][i] = '@';
		}
		//------------------------

		//character
		Player_position cp;
		cp.x = 5;
		cp.y = 5;
		World[cp.x][cp.y] = character;

		//map generate 23x23
		for (i = 0; i < 23; i++)
		{
			for (j = 0; j < 23; j++)
			{
				if (World[i][j] == ' ')
				{
					textcolor(BLACK, GREEN);//text color, background color
					std::cout << World[i][j];
				}
				else
				{
					textcolor(BLACK, LIGHTGRAY);
					std::cout << World[i][j];
				}
			}
			std::cout << std::endl;
		}
	}
	//Update();
	//Draw();
	//Close();
	/*bool isDone() const
	{
		return isDone;
	}*/
private:
	char World[23][23];
	struct Player_position
	{
		int x;
		int y;//initial position
	};

	int level_check;
	int current_level;

	int coin;
	int torch;

	const char character = 'P';
};