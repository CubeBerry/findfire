#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>
#include "game.h"
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

void Game::Init()//map generation, player position initialize
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

	//random--------------------------------------------
	std::random_device rd;
	std::mt19937_64 rng(rd());
	//variables between 1 and 21
	std::uniform_int_distribution<_int64> dist1(1, 21);
	//--------------------------------------------------
	int count;

	for (count = 0; count < coin; count++)//coin
	{
		if (World[dist1(rng)][dist1(rng)] == 32)
		{
			World[dist1(rng)][dist1(rng)] = coin_shape;
		}
	}

	for (count = 0; count < torch; count++)//torch
	{
		if (World[dist1(rng)][dist1(rng)] == 32)
		{
			World[dist1(rng)][dist1(rng)] = torch_shape;
		}
	}
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
}