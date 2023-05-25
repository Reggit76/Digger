#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Player{ 
private:
    float x;
    float y;
    int count_of_hits;
    ///hp
    float hp;
    Texture txLeft;
    Texture txRight;
    Texture txDown;
    Texture txUp;
    Sprite sp;
    int score;
public:

    Player();

    int get_score();
    void set_score(int score);
    void set_count_of_hits(int count_of_hits);
    int get_count_of_hits();
    void SetHP(float hp);
    void SetCordX(float x);
    void SetCordY(float y);
    float GetHP();
    float GetCordX();
    float GetCordY();
    void move(RenderWindow& window, float x, float y);
    void draw(RenderWindow& window);
};
