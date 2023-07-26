#ifndef BATTLESHIP1_AI_H
#define BATTLESHIP1_AI_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

class Ai {

public:

public:

    Ai() = default;

    void ch_ai();

    void ran_ai(int seed);

    bool check_for_ran(int row, int col);

    void destory_ai(int turn, int row, int col);


};


#endif //BATTLESHIP1_AI_H
