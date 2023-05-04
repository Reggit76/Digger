#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Digger");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    int posX = 0, posY = 0;
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) posX--;
                if (event.key.code == sf::Keyboard::Right) posX++;
                if (event.key.code == sf::Keyboard::Down) posY++;
                if (event.key.code == sf::Keyboard::Up) posY--;
            }
        }
        shape.setPosition(posX * 25, posY * 25);
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}