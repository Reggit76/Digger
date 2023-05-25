#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <list>
#include <iterator>
#include <math.h>
#include "Rock.h"
#include "Player.h"
#include "Diamond.h"
#include "Enemy.h"


using namespace sf;
using namespace std;


class Game
{
private:
    int width;
    int hight;
    int **arr;
    bool Gameover;
    list <Rock> lRock;
    list <Diamond> lDiamond;
    list <Enemy> lEnemy;
    SoundBuffer SoundBf;
    Sound sound;
    Player player;
public:
    Game(RenderWindow& window);
    virtual ~Game();
    void import(string filename);
    void Menu(RenderWindow& window);
    bool GetGameover();
    void SetGameover();
    void drawBackground(RenderWindow& window);
    void drawRock(RenderWindow& window);
    void drawDiamond(RenderWindow& window);
    void drawEnemy(RenderWindow& window);
    bool removeRock(float x, float y);
    bool removeDiamond(float x, float y);
    void movePlayer(RenderWindow& window, float x, float y);
    void playerDraw(RenderWindow& window);
    void drawStatus(RenderWindow& window);
    void Update(RenderWindow& window);
};