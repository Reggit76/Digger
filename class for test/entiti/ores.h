#pragma once
#include "entiti.h"
#include <iostream>


class Ores: public Entiti
{
protected:
    int count_of_ores;
public:
    Ores(int hp, int damage,int count_of_ores);
    int get_count_of_ores()const;
    void set_count_of_ores(int count_of_ores);
    void print()const;
};



