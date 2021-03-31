#include <iostream>

class Game
{
public:
	void Init()//map generation, movement, sight, torch/coin count, portal
	{
		int i, j;

		for (i = 1; i < 22; i++)
		{
			for (j = 1; j < 22; j++)
			{
				World[i][j] = '0';
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
				std::cout << World[i][j];
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