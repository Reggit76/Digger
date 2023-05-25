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
    int type;
    float x;
    float y;
public:
    int trend = 0;
    Enemy();
    Enemy(float x, float y, int type);
    void SetCordX(float x);
    void SetCordY(float y);
    void SetType(int type);
    float GetCordX();
    float GetCordY();
    int GetType();
    void move(RenderWindow& window, float x, float y);
    void draw(RenderWindow& window);
};

