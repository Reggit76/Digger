#include "Game.h"
#include <iostream>
#include <SFML/Audio.hpp>

int main() {
	RenderWindow window(sf::VideoMode(1200, 800), "DiggerV2");
	View view(FloatRect(0, 0, 1200, 800));
	Game game(window);
	Music music;
	music.openFromFile("music.ogg");
	music.play();
	music.setVolume(10);
	while (window.isOpen()) {
		window.clear();		
		game.drawBackground(window);
		game.drawRock(window);
		game.drawDiamond(window);
		game.drawEnemy(window);
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
		else if (Keyboard::isKeyPressed(Keyboard::D)) {
			game.movePlayer(window, 1, 0, "Right");
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			game.movePlayer(window, 0, 1, "Down");
		}
		else if (Keyboard::isKeyPressed(Keyboard::W)) {
			game.movePlayer(window, 0, -1, "Up");
		}
		else
			game.playerDraw(window);
		game.enemyUpdate(window);
		window.display();
	}
	window.close();
	return 0;
}