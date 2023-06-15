#include <iostream>

#include "Game.h"
#include "MainMenu.h"


/// <summary>
/// animacja dodawania punktow przy trafieniu celu 
/// nowa klasa
/// </summary>


int main()
{
	//std::srand(static_cast <unsigned>(time(0)));
	//srand(time(NULL));

	
	/*MainMenu menu;

	while (menu.running())
	{
		menu.update();
		menu.render();
	}*/
	sf::VideoMode resolution = sf::VideoMode(800, 600);

	Game game(resolution);


	////std::thread t1(timer, 30);

	while (game.running())
	{
		game.update();
		game.render();
	}

	//t1.join();
	
	return 0;
}

