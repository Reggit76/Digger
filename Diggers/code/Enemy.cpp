#include "Enemy.h"

Enemy::Enemy(){
    this->hp = 20.f;
    this->x = -500.f;
    this->y = -500.f;
    txUp.loadFromFile("img/antUp.png");
    txDown.loadFromFile("img/antDown.png");
    txRight.loadFromFile("img/antRight.png");
    txLeft.loadFromFile("img/antLeft.png");
    sp.setTexture(txDown);
}

Enemy::Enemy(float x, float y)
{
    // hp
    this->hp = 20.f;
    this->x = x;
    this->y = y;
    txUp.loadFromFile("img/antUp.png");
    txDown.loadFromFile("img/antDown.png");
    txRight.loadFromFile("img/antRight.png");
    txLeft.loadFromFile("img/antLeft.png");
    sp.setTexture(txDown);
}
// set and get
void Enemy::SetHP(float hp)
{
    this->hp = hp;
}

void Enemy::SetCordX(float x)
{
    this->x = x;
}

void Enemy::SetCordY(float y)
{
    this->y = y;
}

float Enemy::GetHP()
{
    return hp;
}

float Enemy::GetCordX()
{
    return x;
}

float Enemy::GetCordY()
{
    return y;
}

void Enemy::move(RenderWindow& window, float x, float y, std::string rotate)
{
    SetCordX(GetCordX() + x * 100.f);
    SetCordY(GetCordY() + y * 100.f);
    sp.setPosition(GetCordX(), GetCordY());
    if (rotate == "Up")
        sp.setTexture(txUp);
    if (rotate == "Down")
        sp.setTexture(txDown);
    if (rotate == "Left")
        sp.setTexture(txLeft);
    if (rotate == "Right")
        sp.setTexture(txRight);
    window.draw(sp);
}

void Enemy::draw(RenderWindow& window)
{
    window.draw(sp);
}
