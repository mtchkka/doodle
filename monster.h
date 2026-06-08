//
// Created by matve on 24-Apr-26.
//

#ifndef HRA_MONSTER_H
#define HRA_MONSTER_H

#include <string>

using namespace std;

struct Monster {
    string name;
    int hp;
    int damage;
    bool isAlive;
    
    string loot;
    int lootAmount;
};

Monster spawnMonster(int monsterType);

#endif //HRA_MONSTER_H