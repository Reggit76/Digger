#include "player.h"
 
Player::Player()
{
    // скорость персонажа 
    m_Speed = 400;
 
    // Связываем текстуру и спрайт
    m_Texture.loadFromFile("bob.png");
    m_Sprite.setTexture(m_Texture);     
 
    // Устанавливаем начальную позицию игрока в пикселях
    m_Position.x = 300;
    m_Position.y = 300;
 
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
 
void Player::stopLeft()
{
    m_LeftPressed = false;
}
void Player::stopUp()
{
    m_UpPressed = false;
}
void Player::stopDown()
{
    m_DownPressed = false;
}
void Player::stopRight()
{
    m_RightPressed = false;
}
 
// Двигаем Боба на основании пользовательского ввода в этом кадре,
// прошедшего времени и скорости
void Player::update(float elapsedTime)
{
    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
 
    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }
    if (m_UpPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    if (m_DownPressed)
    {
        m_Position.y -=  m_Speed * elapsedTime;
    }
    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_Position);   
 
}