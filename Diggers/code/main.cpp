#include "Game.h"
#include <iostream>


int main() {
	RenderWindow window(sf::VideoMode(1200, 800), "DiggerV2");
	Game game(window); // создание класса game для дальнейшего использования механик игры
	Music music; // подключаем фоновую музыку
	music.openFromFile("sound/music.ogg"); 
	music.play();
	music.setVolume(5);
	bool MenuIsOpen = true; // переменная отвечающие за состояние, открыто меню сейчач или нет
	while (window.isOpen()) {
		window.clear();		
		Event event;
		while (window.pollEvent(event)) // цикл для проверки нажали ли на закрыть окно
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (MenuIsOpen) { // если меню открыто, то следим за положением курсора и нажатием на лкм
			game.Menu(window);
			Vector2i mp = Mouse::getPosition(window);
			if ((mp.x > 320 && mp.x < 880) && (mp.y > 320 && mp.y < 420) && (Mouse::isButtonPressed(Mouse::Left))){
				MenuIsOpen = false;
			}
			else if ((mp.x > 320 && mp.x < 880) && (mp.y > 500 && mp.y < 600) && (Mouse::isButtonPressed(Mouse::Left))) {
				window.close();
			}
		}
		else { // если в меню нажали play то запускается логика уже игры
			game.drawBackground(window); // отрисовка фона игры(карты)
			game.drawRock(window); // отрисовка камней на карте
			game.drawDiamond(window); // отрисовка алмазов на карте
			game.drawEnemy(window); // отрисовка врагов
			game.drawStatus(window); // отрисовка окна состояния персонажа
			if (Keyboard::isKeyPressed(Keyboard::A)) { // шаг влево за персонажа
				game.movePlayer(window, -1, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D)) { // шаг вправо за персонажа
				game.movePlayer(window, 1, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::S)) { // шаг вниз за персонажа
				game.movePlayer(window, 0, 1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W)) { // шаг вверх за персонажа
				game.movePlayer(window, 0, -1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape)) { // пауза игры и выход в меню
				MenuIsOpen = true;
			}
			else { // отрисовка персонажа если он ничего не делает
				game.playerDraw(window); 
			}
			game.Update(window); // обновление событий в игре
		}	
		window.display();
	}
	return 0;
}