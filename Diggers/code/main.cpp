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
	// загрузка шрифта и настройка текста для кнопок
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text playText("Play", font, 50);
	playText.setPosition(300, 300);
	playText.setFillColor(sf::Color::White);

	sf::Text exitText("Exit", font, 50);
	exitText.setPosition(300, 400);
	exitText.setFillColor(sf::Color::White);

	// создание кнопок
	sf::RectangleShape playButton(sf::Vector2f(200, 70));
	playButton.setPosition(290, 285);
	playButton.setFillColor(sf::Color(51, 153, 255));
	playButton.setOutlineThickness(3);
	playButton.setOutlineColor(sf::Color::White);

	sf::RectangleShape exitButton(sf::Vector2f(200, 70));
	exitButton.setPosition(290, 385);
	exitButton.setFillColor(sf::Color(255, 51, 51));
	exitButton.setOutlineThickness(3);
	exitButton.setOutlineColor(sf::Color::White);
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