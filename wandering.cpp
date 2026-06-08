//
// Created by matve on 03-May-26.
//
#include "wandering.h"
#include <iostream>
#include <string>

using namespace std;

Wandering randWandering(int wanderingType) {
    Wandering w;

    switch (wanderingType) {
        case 1:
            w.name = "Bubble Land";
            w.doorChoice = 3;
            w.roomAmount = 5;
            w.monsterSpawnRate = 20;
            w.MBamount = 10;
            break;
        case 2:
            w.name = "Dark Cave";
            w.doorChoice = 2;
            w.roomAmount = 10;
            w.monsterSpawnRate = 60;
            w.MBamount = 50;
            break;
        default:
            w.name = "Unknown Wilds";
            w.doorChoice = 1;
            w.roomAmount = 3;
            w.monsterSpawnRate = 10;
            w.MBamount = 0;
            break;
    }

    return w;
}