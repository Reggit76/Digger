#include "Game.h"


Game::Game(sf::RenderWindow& window)
{
    initial();
    player.move(window, 1, 1, "Right");
    player.move(window, -1, -1, "Right");
}

Game::~Game()
{
    delete[] arr;
}

void Game::import(string filename)
{
    ifstream file(filename);
    file >> hight >> width;
    arr = new int* [hight];
    for (int i = 0; i < hight; i++) {
        arr[i] = new int[width];
    }
    int bf;
    int count_rock;
    file >> count_rock;
    lRock.resize(count_rock);
    lDiamond.resize(count_rock);
    for (int i = 0; i < hight; i++) {
        for (int j = 0; j < width; j++) {
            file >> bf;
            arr[i][j] = bf;
            if (bf == 3)
                lRock.push_front(Rock(100.f * j, 100.f * i));
            if (bf == 5)
                lDiamond.push_front(Diamond(100.f * j, 100.f * i));
        }
    }
    file.close();
}

bool Game::initial()
{
    import("map.txt");
    return true;
}

void Game::drawBackground(sf::RenderWindow& window)
{   
    Texture tx;
    for (int i = 0; i < hight; i++) {
        for (int j = 0; j < width; j++) {
            if (arr[i][j] == 9)
                tx.loadFromFile("img/wall.png");
            else
                tx.loadFromFile("img/back2.png");
            Sprite sp(tx);
            sp.setPosition(100.f * j, 100.f * i);
            window.draw(sp);
        }
    }
}

void Game::drawRock(sf::RenderWindow& window)
{   
    list <Rock>::iterator it;
    Texture tx;
    for (it = lRock.begin(); it != lRock.end(); it++) {
        tx.loadFromFile("img/rock.png");
        Sprite sp(tx);
        sp.setPosition((*it).GetCordX(), (*it).GetCordY());
        window.draw(sp);
    }
}

void Game::drawDiamond(RenderWindow& window)
{
    list <Diamond>::iterator it;
    Texture tx;
    for (it = lDiamond.begin(); it != lDiamond.end(); it++) {
        tx.loadFromFile("img/Diamond.png");
        Sprite sp(tx);
        sp.setPosition((*it).GetCordX(), (*it).GetCordY());
        window.draw(sp);
    }
}

bool Game::removeRock(float x, float y)
{
    list <Rock>::iterator it;
    for (it = lRock.begin(); it != lRock.end(); it++) {
        if (x == (*it).GetCordX() && y == (*it).GetCordY()) {
            it = lRock.erase(it);
            return true;
        }            
    }
    return false;
}

bool Game::removeDiamond(float x, float y)
{
    list <Diamond>::iterator it;
    for (it = lDiamond.begin(); it != lDiamond.end(); it++) {
        if (x == (*it).GetCordX() && y == (*it).GetCordY()) {
            it = lDiamond.erase(it);
            return true;
        }
    }
    return false;
}

void Game::movePlayer(RenderWindow& window, float x, float y, std::string rotate)
{
    int px = (player.GetCordX() + x * 100.f) / 100.f;
    int py = (player.GetCordY() + y * 100.f) / 100.f;
    if (arr[py][px] == 3 && player.get_count_of_hits() > 0)
    {   
        removeRock(px * 100.f, py * 100.f);
        player.set_count_of_hits((player.get_count_of_hits())-1);
    }
    if (arr[py][px] == 5 && player.get_count_of_hits() > 0)
    {
        removeDiamond(px * 100.f, py * 100.f);
        player.set_count_of_hits((player.get_count_of_hits())-1);
        player.set_score(25);
    }
    if (arr[py][px] != 9) {
        player.move(window, x, y, rotate);
        View view(FloatRect(0, 0, 1200, 800));
        view.setCenter(Vector2f(player.GetCordX(), player.GetCordY()));
        window.setView(view);
    }
    else
        player.draw(window);
}

void Game::playerDraw(RenderWindow& window) {
    player.draw(window);
}