#include "Wall.h"
Wall::Wall(sf::Texture& texture, Vector2<float> position, float width, float height)
    : m_position(position), m_width(width), m_height(height)
{
    m_sprite.setTexture(texture);
    m_sprite.setPosition(m_position.x, m_position.y);
    m_sprite.setScale(m_width / m_sprite.getGlobalBounds().width, m_height / m_sprite.getGlobalBounds().height);
}
void Wall::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}
Vector2<float> Wall::getPosition()
{
    return m_position;
}
float Wall::getWidth()
{
    return m_width;
}
float Wall::getHeight()
{
    return m_height;
}