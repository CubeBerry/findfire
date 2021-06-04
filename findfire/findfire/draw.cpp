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

//text and background color
void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//clear screen
void ClearScreen()
{
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

//move to x,y position
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Game::Draw()
{
	//system("cls");
	ClearScreen();
	//map darwing
	int i, j;

	for (i = 0; i < 23; i++)
	{
		for (j = 0; j < 23; j++)
		{
			if (World[i][j] == ' ')
			{
				textcolor(BLACK, GREEN);//text color, background color
			}
			else if (World[i][j] == character_pos)
			{
				textcolor(BLACK, GREEN);
			}
			else if (World[i][j] == coin_shape)
			{
				textcolor(YELLOW, GREEN);
			}
			else if (World[i][j] == torch_shape)
			{
				textcolor(RED, GREEN);
			}
			else if (World[i][j] == portal_shape)
			{
				textcolor(YELLOW, BLUE);
			}
			else
			{
				textcolor(BLACK, LIGHTGRAY);
			}
			std::cout << World[i][j];
		}
		std::cout << std::endl;
	}

	//item count
	textcolor(WHITE, BLACK);
	std::cout << "Coin : " << coin_count << std::endl;
	std::cout << "Sight : " << sight << std::endl;
	std::cout << "Level : " << current_level + 1;
}