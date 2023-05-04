#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "digger");
    // �������� ������� ���� � ��� ��������
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.png");
    sf::Sprite background(backgroundTexture);
    // �������� ������� ������ � ��� ��������
    sf::Texture playerTexture;
    playerTexture.loadFromFile("player.png");
    sf::Sprite player(playerTexture);
    // ��������� ��������� ������� ������
    player.setPosition(400, 300);
    // �������� ������� ������
    sf::View view(sf::FloatRect(0, 0, 800, 600));
    // ����������� ������ �� �������
    view.setCenter(player.getPosition());
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        // ��������� ���������� �������
        const float speed = 0.175f; // �������� ������������ ������
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move(-speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.move(speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player.move(0, speed);
        }
        // ���������� ������� ������
        view.setCenter(player.getPosition());
        window.setView(view);
        window.clear();
        // ����������� ���� �� ������
        window.draw(background);
        // ����������� ������ �� ������
        window.draw(player);
        window.display();
    }
    return 0;
}