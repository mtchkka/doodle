//
// Created by matve on 03-May-26.
//

#ifndef HRA_WANDERING_H
#define HRA_WANDERING_H
#include <iostream>
#include <string>
using namespace std;

struct Wandering{

    string name;

    int doorChoice;
    int roomAmount;

    int monsterSpawnRate;
    int MBamount;

};

Wandering randWandering(int wanderingType);
#endif //HRA_WANDERING_H
