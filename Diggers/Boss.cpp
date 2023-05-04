//#include "Boss.h"
//Boss::Boss(sf::Texture& texture, Vector2<float> position, List<Wall>& walls)
//    : m_position(position), m_walls(walls), m_health(1000), m_isDead(false), m_speed(100.0f)
//{
//    m_sprite.setTexture(texture);
//    m_sprite.setPosition(m_position.x, m_position.y);
//}
//void Boss::update(float deltaTime, Character& player)
//{
//    // Обработка логики босса
//    if (!m_isDead)
//    {
//        // Поведение босса, когда он живой
//        // Например, движение к игроку и атака
//        Vector2<float> direction = player.getPosition() - m_position;
//        float distance = Vector2<float>::getMagnitude(direction);
//        if (distance < 1000.0f)
//        {
//            direction = Vector2<float>::normalize(direction);
//            m_position += direction * m_speed * deltaTime;
//        }
//        if (distance < 500.0f)
//        {
//            m_weapon.shoot(m_position, direction);
//        }
//        // Обновление спрайта босса
//        m_sprite.setPosition(m_position.x, m_position.y);
//    }
//    else
//    {
//        // Поведение босса, когда он мертв
//        // Например, анимация смерти и удаление из списка боссов
//    }
//}
//void Boss::draw(sf::RenderWindow& window)
//{
//    window.draw(m_sprite);
//}
//bool Boss::isDead()
//{
//    return m_isDead;
//}