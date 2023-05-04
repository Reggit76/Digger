//#include "Character.h"
//Character::Character(sf::Texture& texture, Vector2<float> position, List<Wall>& walls)
//    : m_position(position), m_walls(walls)
//{
//    m_sprite.setTexture(texture);
//    m_sprite.setPosition(m_position.x, m_position.y);
//}
//void Character::move(Vector2<float> direction)
//{
//    m_velocity.x = direction.x * m_speed;
//}
//void Character::jump()
//{
//    if (m_onGround)
//    {
//        m_velocity.y = -m_jumpForce;
//        m_onGround = false;
//    }
//}
//void Character::shoot(Vector2<float> direction)
//{
//    m_weapon.shoot(m_position, direction);
//}
//void Character::takeItem(Vector2<float> position, List<Item>& items)
//{
//    Item* item = items.search(position);
//    if (item != nullptr)
//    {
//        m_inventory.addItem(item);
//        items.remove(item);
//    }
//}
//void Character::putItem(Vector2<float> position, List<Item>& items)
//{
//    Item* item = m_inventory.getSelectedItem();
//    if (item != nullptr)
//    {
//        item->setPosition(position);
//        items.add(item);
//        m_inventory.removeItem(item);
//    }
//}
//void Character::openInventory()
//{
//    m_inventory.open();
//}
//void Character::climbWall()
//{
//    if (m_onWall)
//    {
//        m_velocity.y = -m_climbForce;
//    }
//}
//void Character::upgradeWeapon()
//{
//    m_weapon.upgrade();
//}
//void Character::update(float deltaTime)
//{
//    // Обработка логики персонажа
//}
//void Character::draw(sf::RenderWindow& window)
//{
//    window.draw(m_sprite);
//}