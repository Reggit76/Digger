#include <iostream>
#include "entiti.h"
using namespace std;


Entiti::Entiti(int hp, int damage){
    set_hp(hp);
    set_damage(damage);
}
int Entiti::get_hp()const{
    return hp;
    }
int Entiti::get_damage()const{
    return damage;
}
void Entiti::set_hp(int hp){
    this -> hp = hp;
    }
void Entiti::set_damage(int damage){
    this -> damage = damage;
    }

