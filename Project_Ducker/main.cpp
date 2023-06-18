#include <iostream>

#include "Game.h"
#include "MainMenu.h"

int main()
{
	

	
	MainMenu menu;

	while (menu.running())
	{
		menu.update();
		menu.render();
	}

	/*sf::VideoMode resolution = sf::VideoMode(800, 600);

	Game game(resolution);


	while (game.running())
	{
		game.update();
		game.render();
	}*/


	
	return 0;
}

