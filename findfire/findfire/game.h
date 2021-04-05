#include <iostream>
#include <Windows.h>
#include <conio.h>

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

void ClearScreen()
{
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
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
		World[character_x][character_y] = character_pos;

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
	//------------------------------------------------------------------------------
	void Update()//map loading, movement, sight, torch/coin count, portal
	{
		//movement
		if (_kbhit())
		{
			int input = _getch();
			if (input == 102)
			{
				World[character_x += 1][character_y += 1] = character_pos;
				//std::cout << character_pos;
			}
		}
	}

	void Draw()
	{
		//system("cls");
		ClearScreen();
		//map writing
		int i, j;

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
	//Close();
	bool isDone() const
	{
		return id;
	}
private:
	char World[23][23];

	int level_check;
	int current_level;

	int coin;
	int torch;

	//character position
	const char character_pos = 'P';
	int character_x = 5;
	int character_y = 5;

	bool id;
};