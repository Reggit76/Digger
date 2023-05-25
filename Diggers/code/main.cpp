#include "Game.h"
#include <iostream>


int main() {
	RenderWindow window(VideoMode(1200, 800), "Digger");
	Game game(window); // �������� ������ game ��� ����������� ������������� ������� ����
	Music music; // ���������� ������� ������
	music.openFromFile("sound/music.ogg"); 
	music.play();
	music.setVolume(5);
	bool MenuIsOpen = true; // ���������� ���������� �� ���������, ������� ���� ������ ��� ���
	while (window.isOpen()) {
		window.clear();		
		Event event;
		while (window.pollEvent(event)) // ���� ��� �������� ������ �� �� ������� ����
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		if (MenuIsOpen) { // ���� ���� �������, �� ������ �� ���������� ������� � �������� �� ���
			game.Menu(window);
			Vector2i mp = Mouse::getPosition(window);
			if ((mp.x > 320 && mp.x < 880) && (mp.y > 320 && mp.y < 420) && (Mouse::isButtonPressed(Mouse::Left))){
				MenuIsOpen = false;
			}
			else if ((mp.x > 320 && mp.x < 880) && (mp.y > 500 && mp.y < 600) && (Mouse::isButtonPressed(Mouse::Left))) {
				window.close();
			}
		}
		else if (!MenuIsOpen && game.GetGameover()) {
			Texture tx;
			tx.loadFromFile("img/Gameover.png");
			Sprite GameOver(tx);
			window.draw(GameOver);
			if (Mouse::isButtonPressed(Mouse::Left)){
				MenuIsOpen = true;
			}
		}
		else { // ���� � ���� ������ play �� ����������� ������ ��� ����
			game.drawBackground(window); // ��������� ���� ����(�����)
			game.drawRock(window); // ��������� ������ �� �����
			game.drawDiamond(window); // ��������� ������� �� �����
			game.drawEnemy(window); // ��������� ������
			game.drawStatus(window); // ��������� ���� ��������� ���������
			if (Keyboard::isKeyPressed(Keyboard::A)) { // ��� ����� �� ���������
				game.movePlayer(window, -1, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D)) { // ��� ������ �� ���������
				game.movePlayer(window, 1, 0);
			}
			else if (Keyboard::isKeyPressed(Keyboard::S)) { // ��� ���� �� ���������
				game.movePlayer(window, 0, 1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W)) { // ��� ����� �� ���������
				game.movePlayer(window, 0, -1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape)) { // ����� ���� � ����� � ����
				MenuIsOpen = true;
			}
			else { // ��������� ��������� ���� �� ������ �� ������
				game.playerDraw(window); 
			}
			game.Update(window); // ���������� ������� � ����
		}	
		window.display();
	}
	return 0;
}