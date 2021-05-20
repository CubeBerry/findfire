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
				if (current_level == level_1)
				{
					l1.coin--;
				}
				else if (current_level == level_2)
				{
					l2.coin--;
				}
			}
			else if (World[character_x - 1][character_y] == torch_shape)
			{
				World[character_x -= 1][character_y] = character_pos;
				World[character_x + 1][character_y] = ' ';
				sight--;
				sight += 24;
				if (current_level == level_1)
				{
					l1.torch--;
				}
				else if (current_level == level_2)
				{
					l2.torch--;
				}
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
				switch (current_level)
				{
				case level_1:
					Init(l1.coin, l1.torch);
					while (isDone())
					{
						Update();
						Draw();
					}
				case level_2:
					Init(l2.coin, l2.torch);
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
				if (current_level == level_1)
				{
					l1.coin--;
				}
				else if (current_level == level_2)
				{
					l2.coin--;
				}
			}
			else if (World[character_x + 1][character_y] == torch_shape)
			{
				World[character_x += 1][character_y] = character_pos;
				World[character_x - 1][character_y] = ' ';
				sight--;
				sight += 24;
				if (current_level == level_1)
				{
					l1.torch--;
				}
				else if (current_level == level_2)
				{
					l2.torch--;
				}
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
					Init(l1.coin, l1.torch);
					while (isDone())
					{
						Update();
						Draw();
					}
				case level_2:
					Init(l2.coin, l2.torch);
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
				if (current_level == level_1)
				{
					l1.coin--;
				}
				else if (current_level == level_2)
				{
					l2.coin--;
				}
			}
			else if (World[character_x][character_y - 1] == torch_shape)
			{
				World[character_x][character_y -= 1] = character_pos;
				World[character_x][character_y + 1] = ' ';
				sight--;
				sight += 24;
				if (current_level == level_1)
				{
					l1.torch--;
				}
				else if (current_level == level_2)
				{
					l2.torch--;
				}
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
					Init(l1.coin, l1.torch);
					while (isDone())
					{
						Update();
						Draw();
					}
				case level_2:
					Init(l2.coin, l2.torch);
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
				if (current_level == level_1)
				{
					l1.coin--;
				}
				else if (current_level == level_2)
				{
					l2.coin--;
				}
			}
			else if (World[character_x][character_y + 1] == torch_shape)
			{
				World[character_x][character_y += 1] = character_pos;
				World[character_x][character_y - 1] = ' ';
				sight--;
				sight += 24;
				if (current_level == level_1)
				{
					l1.torch--;
				}
				else if (current_level == level_2)
				{
					l2.torch--;
				}
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
					Init(l1.coin, l1.torch);
					while (isDone())
					{
						Update();
						Draw();
					}
				case level_2:
					Init(l2.coin, l2.torch);
					while (isDone())
					{
						Update();
						Draw();
					}
				}
			}
		}
	}

	if (sight == 0 || coin_count == 13)//game over
	{
		id = false;
	}
}