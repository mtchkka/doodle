//
// Created by matve on 24-Apr-26.
//
#include "monster.h"
#include <iostream>
#include <string>

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
            break;

            case 2:
            m.name = "Gummy Gooner";
            m.hp;
            m.maxhp = 40;
            m.damage - 8;
            m.attackSpeed = 2;
            m.defense = 10;
            m.shield = 20;

            m.xpreward = 35;
            m.loot = "Gummies", "Gummy Bust";
            m.lootAmount = 10;
            break;


    }
}
