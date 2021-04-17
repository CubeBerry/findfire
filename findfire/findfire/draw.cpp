#include "game.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>

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

void Game::Draw()
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

	//item count
	textcolor(WHITE, BLACK);
	std::cout << "Coin : " << coin_count << std::endl;
	std::cout << "Sight : " << sight << std::endl;
}