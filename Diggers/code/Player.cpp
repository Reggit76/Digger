#include "player.h"

Player::Player()
{
    /// hp
    hp = 100.f;

    // Устанавливаем начальную позицию игрока в пикселях
    this->x = 100.f;
    this->y = 100.f;
    txUp.loadFromFile("img/playerUp.png");
    txDown.loadFromFile("img/playerDown.png");
    txRight.loadFromFile("img/playerRight.png");
    txLeft.loadFromFile("img/playerLeft.png");
    sp.setTexture(txDown);
}

/// set and get
float Player::GetHP()
{
    return hp;
}
void Player::SetHP(float hp)
{
    this->hp = hp;
}

void Player::SetCordX(float x)
{
    this->x = x;
}

void Player::SetCordY(float y)
{
    this->y = y;
}

float Player::GetCordX()
{
    return x;
}

float Player::GetCordY()
{
    return y;
}

void Player::move(RenderWindow& window, float x, float y, std::string rotate)
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
    sleep(milliseconds(100));
}

void Player::draw(RenderWindow& window)
{
    window.draw(sp);
}

