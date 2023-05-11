#include "Game.h"
#include <iostream>
#include <time.h>

int main() {
	RenderWindow window(sf::VideoMode(1200, 800), "DiggerV2");
	View view(FloatRect(0, 0, 1200, 800));
	Game game;
	while (window.isOpen()) {
		window.clear();		
		game.drawBackground(window);
		game.drawRock(window);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			game.movePlayer(window, -1, 0, "Left");
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			game.movePlayer(window, 1, 0, "Right");
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			game.movePlayer(window, 0, 1, "Down");
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			game.movePlayer(window, 0, -1, "Up");
		}
		//game.playerDraw(window);
		window.display();
	}
	window.close();
	return 0;
}