#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Player{ 
private:    // Все private переменные могут быть доступны только внутри объекта
    float x;
    float y;
    ///hp
    float hp;
    Texture txLeft;
    Texture txRight;
    Texture txDown;
    Texture txUp;
    Sprite sp;
public:    // Открытые методы

    // Настраиваем игрока в конструкторе
    Player();
    // геты и сеты для хп
    float GetHP();
    void SetHP(float hp);
    void SetCordX(float x);
    void SetCordY(float y);
    float GetCordX();
    float GetCordY();
    void move(RenderWindow& window, float x, float y, std::string rotate);
    void draw(RenderWindow& window);
};
