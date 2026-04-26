//
// Created by matve on 24-Apr-26.
//
#include "monster.h"
#include <iostream>

using namespace std;

Monster spawnMonster(int monsterType) {
    Monster m;

    switch (monsterType) {
        case 1:
            m.name = "Pink Slime";
            m.hp;
            m.maxhp = 25;
            m.damage = 5;
            m.attackSpeed = 1;
            m.defense = 5;
            m.shield = 5;

            m.xpreward = 10;
            m.loot = "Pink Slimey Goo";
            m.lootAmount = 10;
    }
}
