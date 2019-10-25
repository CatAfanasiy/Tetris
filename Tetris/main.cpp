#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Game.h"
int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(360, 480), "Tetris");
	Game game;
	sf::Clock clock;
	float counter = 0;
	while (window.isOpen()&& game.getIsRunning())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		counter += time;
		sf::Event event;
		while (window.pollEvent(event))
		{
			game.handleEvent(event);
		}
		if (counter > 0.4)
		{
			game.update();
			counter = 0;
		}
		window.clear();
		game.render(window);
		window.display();
	}
	return 0;
}