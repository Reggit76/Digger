#include "player.h"
 
Player::Player()
{
    // скорость персонажа 
    m_Speed = 100.f;
    /// hp
    hp = 100.f;
    // Связываем текстуру и спрайт
    m_Texture.loadFromFile("bob.png");
    m_Sprite.setTexture(m_Texture);     
 
    // Устанавливаем начальную позицию игрока в пикселях
    set_position_x(100.f);
    set_position_x(100.f);

 
}
 
// Делаем приватный спрайт доступным для функции draw()
Sprite Player::getSprite()
{
    return m_Sprite;
}
 
void Player::moveLeft()
{
    m_LeftPressed = true;
}
void Player::moveUp()
{
    m_UpPressed = true;
}
void Player::moveDown()
{
    m_DownPressed = true;
}
void Player::moveRight()
{
    m_RightPressed = true;
}
/// set and get
float Player::get_hp()
{
    return hp;
}
void Player::set_hp(float hp)
{
    this -> hp = hp;
}

float Player::get_damage()
{
    return damage;
}

void Player::set_damage(float damage)
{
    this -> damage = damage;
}
float Player::get_position_x()
{
    return position_x;
}

void Player::set_position_x(float position_x)
{
    this -> position_x = position_x;
}
float Player::get_position_y()
{
    return position_x;
}

void Player::set_position_y(float position_y)
{
    this -> position_y = position_y;
}



// void Player::stopLeft()
// {
//     m_LeftPressed = false;
// }
// void Player::stopUp()
// {
//     m_UpPressed = false;
// }
// void Player::stopDown()
// {
//     m_DownPressed = false;
// }
// void Player::stopRight()
// {
//     m_RightPressed = false;
// }
 
// 
void Player::update()
{
    if (m_RightPressed)
    {
        set_position_x((get_position_x())+1);
    }
 
    if (m_LeftPressed)
    {
        set_position_x((get_position_x())-1);
    }
    if (m_UpPressed)
    {
        set_position_y((get_position_y())+1);
    }
    if (m_DownPressed)
    {
        set_position_y((get_position_y())-1);
    }
    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(get_position_x(),get_position_y());   
 
}