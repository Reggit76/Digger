#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Enemy
{
private:
    Sprite sp;
    Texture txLeft;
    Texture txRight;
    Texture txDown;
    Texture txUp;
    float x;
    float y;
    float hp;
public:
    Enemy();
    Enemy(float x, float y);
    void SetHP(float hp);
    void SetCordX(float x);
    void SetCordY(float y);
    float GetHP();
    float GetCordX();
    float GetCordY();
    void move(RenderWindow& window, float x, float y, std::string rotate);
    void draw(RenderWindow& window);
};

