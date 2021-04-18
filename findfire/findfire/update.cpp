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
	//movement and collision + coin/torch count + portal
	if (_kbhit())
	{
		int input = _getch();
		if (input == UP)
		{
			if (World[character_x - 1][character_y] != '@' && World[character_x - 1][character_y] != '$' && World[character_x - 1][character_y] != 'T' && World[character_x - 1][character_y] != 'O')
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
				sight--;
			}
			else if (World[character_x - 1][character_y] == coin_shape)
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
				coin_count++;
				sight--;
			}
			else if (World[character_x - 1][character_y] == torch_shape)
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
				sight--;
				sight += 24;
			}
			else if (World[character_x - 1][character_y] == portal_shape)
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
				sight--;
				if (current_level == level_2)
				{
					current_level--;
				}
				else if (current_level == level_1)
				{
					current_level++;
				}
				//portal activate
				switch(current_level)
				{
					case level_1:
						coin = 5;
						torch = 5;
						Init();
						while (isDone())
						{
							Update();
							Draw();
						}
					case level_2:
						coin = 8;
						torch = 8;
						Init();
						while (isDone())
						{
							Update();
							Draw();
						}
				}
			}
		}
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		else if (input == DOWN)
		{
			if (World[character_x + 1][character_y] != '@' && World[character_x + 1][character_y] != '$' && World[character_x + 1][character_y] != 'T' && World[character_x + 1][character_y] != 'O')
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
				sight--;
			}
			else if (World[character_x + 1][character_y] == coin_shape)
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
				coin_count++;
				sight--;
			}
			else if (World[character_x + 1][character_y] == torch_shape)
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
				sight--;
				sight += 24;
			}
			else if (World[character_x + 1][character_y] == portal_shape)
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
				sight--;
				if (current_level == level_2)
				{
					current_level--;
				}
				else if (current_level == level_1)
				{
					current_level++;
				}
				//portal activate
				switch (current_level)
				{
				case level_1:
					coin = 5;
					torch = 5;
					Init();
					while (isDone())
					{
						Update();
						Draw();
					}
				case level_2:
					coin = 8;
					torch = 8;
					Init();
					while (isDone())
					{
						Update();
						Draw();
					}
				}
			}
		}
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		else if (input == LEFT)
		{
			if (World[character_x][character_y - 1] != '@' && World[character_x][character_y - 1] != '$' && World[character_x][character_y - 1] != 'T' && World[character_x][character_y - 1] != 'O')
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
				sight--;
			}
			else if (World[character_x][character_y - 1] == coin_shape)
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
				coin_count++;
				sight--;
			}
			else if (World[character_x][character_y - 1] == torch_shape)
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
				sight--;
				sight += 24;
			}
			else if (World[character_x][character_y - 1] == portal_shape)
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
				sight--;
				if (current_level == level_2)
				{
					current_level--;
				}
				else if (current_level == level_1)
				{
					current_level++;
				}
				//portal activate
				switch (current_level)
				{
				case level_1:
					coin = 5;
					torch = 5;
					Init();
					while (isDone())
					{
						Update();
						Draw();
					}
				case level_2:
					coin = 8;
					torch = 8;
					Init();
					while (isDone())
					{
						Update();
						Draw();
					}
				}
			}
		}
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		else if (input == RIGHT)
		{
			if (World[character_x][character_y + 1] != '@' && World[character_x][character_y + 1] != '$' && World[character_x][character_y + 1] != 'T' && World[character_x][character_y + 1] != 'O')
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
				sight--;
			}
			else if (World[character_x][character_y + 1] == coin_shape)
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
				coin_count++;
				sight--;
			}
			else if (World[character_x][character_y + 1] == torch_shape)
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
				sight--;
				sight += 24;
			}
			else if (World[character_x][character_y + 1] == portal_shape)
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
				sight--;
				if (current_level == level_2)
				{
					current_level--;
				}
				else if (current_level == level_1)
				{
					current_level++;
				}
				//portal activate
				switch (current_level)
				{
				case level_1:
					coin = 5;
					torch = 5;
					Init();
					while (isDone())
					{
						Update();
						Draw();
					}
				case level_2:
					coin = 8;
					torch = 8;
					Init();
					while (isDone())
					{
						Update();
						Draw();
					}
				}
			}
		}
	}
}