#include <iostream>
#include "2_D_arry.h"
using namespace std;

int main() {
    DoubleArray arr(3, 4);
    arr.set(0, 0, 1);
    arr.set(0, 1, 2);
    arr.set(0, 2, 3);
    arr.set(0, 3, 4);
    arr.set(1, 0, 5);
    arr.set(1, 1, 6);
    arr.set(1, 2, 7);
    arr.set(1, 3, 8);
    arr.set(2, 0, 9);
    arr.set(2, 1, 10);
    arr.set(2, 2, 11);
    arr.set(2, 3, 12);
    arr.print();
    return 0;
}
///вывод
///1 2 3 4
///5 6 7 8 
///9 10 11 12 
/// использование: в методах используется следущая конструкция (строка,столбец,значение)
/// принт выводит в консоль фором, если надо куда-то передовать, можно изменить

