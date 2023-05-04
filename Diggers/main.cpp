#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "digger");
    // Создание спрайта фона и его текстуры
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.png");
    sf::Sprite background(backgroundTexture);
    // Создание спрайта игрока и его текстуры
    sf::Texture playerTexture;
    playerTexture.loadFromFile("player.png");
    sf::Sprite player(playerTexture);
    // Установка начальной позиции игрока
    player.setPosition(400, 300);
    // Создание объекта камеры
    sf::View view(sf::FloatRect(0, 0, 800, 600));
    // Закрепление камеры за игроком
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
        // Обработка управления игроком
        const float speed = 0.175f; // скорость передвижения игрока
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
        // Обновление позиции камеры
        view.setCenter(player.getPosition());
        window.setView(view);
        window.clear();
        // Отображение фона на экране
        window.draw(background);
        // Отображение игрока на экране
        window.draw(player);
        window.display();
    }
    return 0;
}