#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "List.h"
class Character
{
public:
    Character(sf::Texture& texture, Vector2<float> position, List<Wall>& walls);
    void move(Vector2<float> direction);
    void jump();
    void shoot(Vector2<float> direction);
    void takeItem(Vector2<float> position, List<Item>& items);
    void putItem(Vector2<float> position, List<Item>& items);
    void openInventory();
    void climbWall();
    void upgradeWeapon();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
private:
    sf::Sprite m_sprite;
    Vector2<float> m_position;
    Vector2<float> m_velocity;
    List<Wall>& m_walls;
    Weapon m_weapon;
    Inventory m_inventory;
};