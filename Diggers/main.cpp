#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Digger");
    // Создание спрайта фона и его текстуры
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("img/background.png");
    sf::Sprite background(backgroundTexture);
    // Создание спрайта игрока и его текстуры
    sf::Texture playerTexture_l;
    playerTexture_l.loadFromFile("img/player_l.png");
    sf::Texture playerTexture_r;
    playerTexture_r.loadFromFile("img/player_r.png");
    sf::Sprite player(playerTexture_l);
    float playerX = 400.0f;
    float playerY = 300.0f;
    player.setPosition(playerX, playerY);
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
        const float gridSize = 0.075f; // размер сетки
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerX -= gridSize;
            sf::Sprite player(playerTexture_l);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerX += gridSize;
            sf::Sprite player(playerTexture_r);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerY -= gridSize;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerY += gridSize;
        }
        // Обновление позиции игрока
        player.setPosition(playerX, playerY);
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