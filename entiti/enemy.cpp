#include <iostream>
#include "enemy.h"


Enemy::Enemy(int hp,int damage):Entiti(hp, damage){
    
}
void Enemy::print()const{
    std::cout<<"damage:"<<get_damage()<< " hp:" << get_hp();
}

