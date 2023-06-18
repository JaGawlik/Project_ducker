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


	
	//sf::RenderWindow* window;

	//
	//sf::VideoMode resolution = sf::VideoMode(800, 600);



	//MainMenu menu;
	//Game game(resolution);


	//

	////window = new sf::RenderWindow(sf::VideoMode(800.f,600.f), "Menu", sf::Style::Close | sf::Style::Titlebar);

	//while (menu.running())
	//{
	//	menu.update();
	//	menu.render();


	//}



	


	//sf::RenderWindow



	/*Game game(resolution);

	while (game.running())
	{
		game.update();
		game.render();
	}*/


	
	return 0;
}

