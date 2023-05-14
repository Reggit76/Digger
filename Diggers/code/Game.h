#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <list>
#include <iterator>
#include "Rock.h"
#include "Player.h"
#include "Diamond.h"


using namespace sf;
using namespace std;


class Game
{
private:
    int width;
    int hight;
    int **arr;
    list <Rock> lRock;
    list <Diamond> lDiamond;
    Player player;
public:
    Game(sf::RenderWindow& window);
    virtual ~Game();
    void import(string filename);
    bool initial();
    void drawBackground(RenderWindow& window);
    void drawRock(RenderWindow& window);
    void drawDiamond(RenderWindow& window);
    bool removeRock(float x, float y);
    bool removeDiamond(float x, float y);
    void movePlayer(RenderWindow& window, float x, float y, std::string rotate);
    void playerDraw(RenderWindow& window);
};