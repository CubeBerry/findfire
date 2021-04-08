#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "game.h"

int main()
{
	Game g;
	g.Init();
	while (g.isDone())
	{
		g.Update();
	}
}