#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Player
{
    // Все private переменные могут быть доступны только внутри объекта
private:
 
    // Позиция игрока
    Vector2f m_Position;
 
    // Объявляем объект Sprite
    Sprite m_Sprite;
 
    // Добавляем текстуру
    Texture m_Texture;
 
    // Логические переменные для отслеживания направления движения
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_UpPressed;
    bool m_DownPressed;
 
    // Скорость игрока в пикселях в секунду
    float m_Speed;
    ///hp
    float hp;
    // Открытые методы
public:
 
    // Настраиваем игрока в конструкторе
    Player();
    /// геты и сеты для хп
    float get_hp();
    void set_hp(float hp);
    // Для отправки спрайта в главную функцию
    Sprite getSprite();
 
    // Для движения игрока
    void moveLeft();
    void moveUp();
    void moveDown();
    void moveRight();
 
    // Прекращение движения
    void stopLeft();
    void stopUp();
    void stopDown();
    void stopRight();
 
    // Эта функция будет вызываться на каждый кадр
    void update(float elapsedTime);
 
};