#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>

using namespace sf;

class Player{ 
private:    // ��� private ���������� ����� ���� �������� ������ ������ �������
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
public:    // �������� ������

    // ����������� ������ � ������������
    Player();
    // ���� � ���� ��� ��

    int get_score();
    void set_score(int score);
    float GetHP();
    void SetHP(float hp);
    void set_count_of_hits(int count_of_hits);
    int get_count_of_hits();
    void SetCordX(float x);
    void SetCordY(float y);
    float GetCordX();
    float GetCordY();
    void move(RenderWindow& window, float x, float y, std::string rotate);
    void draw(RenderWindow& window);
};
