#include <iostream>

#include "Game.h"
#include "MainMenu.h"
#include "General.h"

/// <summary>
/// po game end game
/// </summary>

int main()
{
	General gen;

	while (gen.running())
	{
		gen.update();
		gen.render();
	}
	
	return 0;
}

