#include "game.h"

int main()
{
	Game g;

	g.Init();
	while (g.isDone())
	{
		g.Update();
		g.Draw();
	}
}