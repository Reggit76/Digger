#include "ores.h"
using namespace std;
Ores::Ores(int hp, int damage, int count_of_ores):Entiti(hp, damage)
{
    set_count_of_ores(count_of_ores);
}
int Ores::get_count_of_ores()const{
    return count_of_ores;
}
void Ores::set_count_of_ores(int count_of_ores){
    this -> count_of_ores = count_of_ores;
}
void Ores::print()const{
    std::cout<<"damage:"<<get_damage()<< " hp:" << get_hp() << " count:" << get_count_of_ores();
}
