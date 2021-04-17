#include "game.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

void Game::Update()//map loading, movement, sight, torch/coin count, portal
{
	//movement and collision + coin/torch count
	if (_kbhit())
	{
		int input = _getch();
		if (input == UP)
		{
			if (World[character_x - 1][character_y] != '@' && World[character_x - 1][character_y] != '$' && World[character_x - 1][character_y] != 'T')
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
			}
			else if (World[character_x - 1][character_y] == coin_shape)
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
				coin_count++;
			}
			else if (World[character_x - 1][character_y] == torch_shape)
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
				sight += 24;
			}
		}
		else if (input == DOWN)
		{
			if (World[character_x + 1][character_y] != '@' && World[character_x + 1][character_y] != '$' && World[character_x + 1][character_y] != 'T')
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
			}
			else if (World[character_x + 1][character_y] == coin_shape)
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
				coin_count++;
			}
			else if (World[character_x + 1][character_y] == torch_shape)
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
				sight += 24;
			}
		}
		else if (input == LEFT)
		{
			if (World[character_x][character_y - 1] != '@' && World[character_x][character_y - 1] != '$' && World[character_x][character_y - 1] != 'T')
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
			}
			else if (World[character_x][character_y - 1] == coin_shape)
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
				coin_count++;
			}
			else if (World[character_x][character_y - 1] == torch_shape)
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
				sight += 24;
			}
		}
		else if (input == RIGHT)
		{
			if (World[character_x][character_y + 1] != '@' && World[character_x][character_y + 1] != '$' && World[character_x][character_y + 1] != 'T')
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
			}
			else if (World[character_x][character_y + 1] == coin_shape)
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
				coin_count++;
			}
			else if (World[character_x][character_y + 1] == torch_shape)
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
				sight += 24;
			}
		}
	}
}