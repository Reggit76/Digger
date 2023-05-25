#include "Game.h"


Game::Game(RenderWindow& window)
{
    import("map.txt");
    player.move(window, 1, 0);
    player.move(window, -1, 0);
    this->Gameover = false;
    SoundBf.loadFromFile("DiamondSound.ogg");

}

Game::~Game()
{
    for (int i = 0; i < hight; i++) {
        delete arr[i];
    }
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
    lRock.resize(10);
    lDiamond.resize(10);
    lEnemy.resize(6);
    for (int i = 0; i < hight; i++) {
        for (int j = 0; j < width; j++) {
            file >> bf;
            arr[i][j] = bf;
            if (bf == 3)
                lRock.push_front(Rock(100.f * j, 100.f * i));
            if (bf == 5)
                lDiamond.push_front(Diamond(100.f * j, 100.f * i));
            if (bf == 6)
                lEnemy.push_front(Enemy(100.f * j, 100.f * i));
        }
    }
    file.close();
}

void Game::Menu(RenderWindow& window)
{
    Texture tx;
    tx.loadFromFile("img/MainMenu.png");
    Sprite sp(tx);
    window.draw(sp);
    View view(FloatRect(0, 0, 1200, 800));
    view.setCenter(Vector2f(600, 400));
    window.setView(view);
}

bool Game::GetGameover()
{
    return Gameover;
}

void Game::SetGameover()
{
    this->Gameover = false;
}

void Game::drawBackground(RenderWindow& window)
{   
    Texture tx;
    for (int i = 0; i < hight; i++) {
        for (int j = 0; j < width; j++) {
            if (arr[i][j] == 9)
                tx.loadFromFile("img/wall.png");
            else
                tx.loadFromFile("img/back.png");
            Sprite sp(tx);
            sp.setPosition(100.f * j, 100.f * i);
            window.draw(sp);
        }
    }
}

void Game::drawRock(RenderWindow& window)
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

void Game::drawEnemy(RenderWindow& window)
{
    list <Enemy>::iterator it;
    for (it = lEnemy.begin(); it != lEnemy.end(); it++) {
        (*it).draw(window);
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
            SoundBf.loadFromFile("DiamondSound.mp3");
            sound.setBuffer(SoundBf);
            sound.play();
            it = lDiamond.erase(it);
            player.set_score((player.get_score()) + 25);
            return true;
        }
    }
    return false;
}

void Game::movePlayer(RenderWindow& window, float x, float y)
{
    int px = player.GetCordX() / 100.f + x;
    int py = player.GetCordY() / 100.f + y;
    if (arr[py][px] == 3 && player.get_count_of_hits() > 0)
    {   
        removeRock(px * 100.f, py * 100.f);
        arr[py][px] = 0;
        player.set_count_of_hits((player.get_count_of_hits())-1);
    }
    if (arr[py][px] == 5 && player.get_count_of_hits() > 0)
    {
        removeDiamond(px * 100.f, py * 100.f);
        arr[py][px] = 0;
        player.set_count_of_hits((player.get_count_of_hits())-1);
    }
    if ((arr[py][px] != 9) || (arr[py][px] == 3 && player.get_count_of_hits() > 0)) {
        player.move(window, x, y);
        View view(FloatRect(0, 0, 1200, 800));
        view.setCenter(Vector2f(player.GetCordX(), player.GetCordY()));
        window.setView(view);
    }
    else {
        player.draw(window);
    }       
}

void Game::playerDraw(RenderWindow& window) {
    player.draw(window);
}

void Game::drawStatus(RenderWindow& window)
{
    Font font;

    font.loadFromFile("arial.ttf");

    string info;
    info += "\nHp: " + to_string((int)player.GetHP());
    info += "\nScore: " + to_string(player.get_score());
    info += "\nHits: " + to_string(player.get_count_of_hits());

    Text text(info, font, 25);

    text.setFillColor(Color::White);

    text.setPosition(player.GetCordX() - 600, player.GetCordY() - 400);

    window.draw(text);
}

void Game::Update(RenderWindow& window)
{
    list <Enemy>::iterator it;
    for (it = lEnemy.begin(); it != lEnemy.end(); it++) {
        if ((player.GetCordX() == (*it).GetCordX() && player.GetCordY() == (*it).GetCordY()) && 
            (player.get_count_of_hits() > 0 && player.GetHP() > 0)) {
            it = lEnemy.erase(it);
            player.SetHP(player.GetHP() - 20);
            player.set_count_of_hits((player.get_count_of_hits()) - 1);
            continue;
        }
        else if ((player.get_count_of_hits() == 0 && player.GetHP() > 0)){
            player.SetHP(player.GetHP() - 20);
        }
    }
}
