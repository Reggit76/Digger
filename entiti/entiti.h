#include <iostream>
#pragma onse///запускает программу один раз
using namespace std;

class Entiti {
protected:
    int hp;///поле здоровья
    int damage;///поле урона
public:
    Entiti(int hp, int damage);/// конструктор
    ///print
    virtual void print() const = 0;///хз зачем, пусть будет, в лабе так было)) PS: спасибо амиру
    ///gets
    int get_hp()const;///в
    int get_damage()const;
    ///sets
    void set_hp(int hp);
    void set_damage(int damege);
};

