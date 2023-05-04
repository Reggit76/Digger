#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "List.h"
#include "Wall.h"
class SecretRoom
{
public:
    SecretRoom(sf::Texture& texture, Vector2<float> position, List<Wall>& walls);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isOpen();
private:
    sf::Sprite m_sprite;
    Vector2<float> m_position;
    List<Wall>& m_walls;
    bool m_isOpen;
    float m_timer;
};
