#include "Enemy.h"

Enemy::Enemy(){
    this->x = -500.f;
    this->y = -500.f;
    this->type = 0;
    txUp.loadFromFile("img/antUp.png");
    txDown.loadFromFile("img/antDown.png");
    txRight.loadFromFile("img/antRight.png");
    txLeft.loadFromFile("img/antLeft.png");
    sp.setTexture(txDown);
}

Enemy::Enemy(float x, float y, int type)
{
    this->x = x;
    this->y = y;
    this->type = type;
    txUp.loadFromFile("img/antUp.png");
    txDown.loadFromFile("img/antDown.png");
    txRight.loadFromFile("img/antRight.png");
    txLeft.loadFromFile("img/antLeft.png");
    sp.setTexture(txDown);
}
// set and get

void Enemy::SetCordX(float x)
{
    this->x = x;
}

void Enemy::SetCordY(float y)
{
    this->y = y;
}

void Enemy::SetType(int type)
{
    this->type = type;
}

float Enemy::GetCordX()
{
    return x;
}

float Enemy::GetCordY()
{
    return y;
}

int Enemy::GetType()
{
    return type;
}

void Enemy::move(RenderWindow& window, float x, float y)
{
    SetCordX(GetCordX() + x * 100.f);
    SetCordY(GetCordY() + y * 100.f);
    sp.setPosition(GetCordX(), GetCordY());
    if (y == 1)
        sp.setTexture(txUp);
    if (y == -1)
        sp.setTexture(txDown);
    if (x == -1)
        sp.setTexture(txLeft);
    if (x == 1)
        sp.setTexture(txRight);
    window.draw(sp);
}

void Enemy::draw(RenderWindow& window)
{
    window.draw(sp);
}
