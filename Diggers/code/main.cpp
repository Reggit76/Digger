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
	
	sf::Texture menuTexture;
	if (!menuTexture.loadFromFile("img/MainMenu.png")) {
		
	}
	sf::Sprite menuSprite(menuTexture);

	
	sf::Texture playTexture;
	if (!playTexture.loadFromFile("img/play.png")) {
		
	}
	sf::Sprite playSprite(playTexture);
	playSprite.setPosition(315, 335);

	
	sf::Texture exitTexture;
	if (!exitTexture.loadFromFile("img/exit.png")) {
		
	}
	sf::Sprite exitSprite(exitTexture);
	exitSprite.setPosition(315, 500);
    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (playSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    
                    while (window.isOpen()) {
                        
                        window.clear();

                        
                        game.drawBackground(window);
                        game.drawRock(window);
                        game.drawDiamond(window);
                        game.drawEnemy(window);

                        
                        sf::Event event;
                        while (window.pollEvent(event)) {
                            if (event.type == sf::Event::Closed) {
                                window.close();
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
                            else {
                                game.playerDraw(window);
                            }
                        }

                        
                        game.enemyUpdate(window);
                        window.display();
                    }
                }

                
                if (exitSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    window.close();
                }
            }
        }

        
        window.clear();
        window.draw(menuSprite);
        window.draw(playSprite);
        window.draw(exitSprite);
        window.display();
    }

    return 0;
}