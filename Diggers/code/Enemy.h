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
public:
    Enemy();
    Enemy(float x, float y);
    void SetHP(float hp);
    void SetCordX(float x);
    void SetCordY(float y);
    float GetHP();
    float GetCordX();
    float GetCordY();
    void move(RenderWindow& window, float x, float y);
    void draw(RenderWindow& window);
};

