#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "game.h"

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

void Game::Update()//map loading, movement, sight, torch/coin count, portal
{
	//movement and collision
	if (_kbhit())
	{
		int input = _getch();
		if (input == UP)
		{
			if (World[character_x - 1][character_y] != '@')
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
			}
		}
		else if (input == DOWN)
		{
			if (World[character_x + 1][character_y] != '@')
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
			}
		}
		else if (input == LEFT)
		{
			if (World[character_x][character_y - 1] != '@')
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
			}
		}
		else if (input == RIGHT)
		{
			if (World[character_x][character_y + 1] != '@')
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
			}
		}
	}

	//map loading
	if (current_level == level_1)
	{
		Draw();
	}
}