#include "SecretRoom.h"
SecretRoom::SecretRoom(sf::Texture& texture, Vector2<float> position, List<Wall>& walls)
    : m_position(position), m_walls(walls), m_isOpen(false), m_timer(0.0f)
{
    m_sprite.setTexture(texture);
    m_sprite.setPosition(m_position.x, m_position.y);
}
void SecretRoom::update(float deltaTime)
{
    if (m_isOpen)
    {
        // Ћогика секретной комнаты, когда она открыта
        // Ќапример, по€вление монстров или сокровищ
        m_timer += deltaTime;
        if (m_timer > 10.0f)
        {
            m_isOpen = false;
            m_timer = 0.0f;
        }
    }
    else
    {
        // Ћогика секретной комнаты, когда она закрыта
        // Ќапример, проверка, прошел ли игрок р€дом
        for (int i = 0; i < m_walls.count(); i++)
        {
            if (Vector2<float>::getMagnitude(m_walls[i].getPosition() - m_position) < 50.0f)
            {
                m_isOpen = true;
                break;
            }
        }
    }
}
void SecretRoom::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}
bool SecretRoom::isOpen()
{
    return m_isOpen;
}