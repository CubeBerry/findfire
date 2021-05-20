#include "game.h"

int main()
{
	int coin, torch;
	coin = 5;
	torch = 5;

	Game g;

	g.Init(coin, torch);
	while (g.isDone())
	{
		g.Update();
		g.Draw();
	}
}