#pragma once
#include "entiti.h"
#include <iostream>


class Enemy: public Entiti
{
public:
    Enemy(int hp, int damage);
    void print()const;
};



