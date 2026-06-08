//
// Created by matve on 24-Apr-26.
//
#include "monster.h"
#include <iostream>
#include <string>

using namespace std;

Monster spawnMonster(int monsterType) {
    Monster m;
    m.isAlive = true;

    switch (monsterType) {
        case 1:
            m.name = "Pink Slime";
            m.hp = 160;
            m.damage = 105;
            m.loot = "Pink Slimey Goo";
            break;

        case 2:
            m.name = "Gummy Gooner";
            m.hp = 85;
            m.damage = 75;
            m.loot = "Gummy Bust";
            break;

        case 3:
            m.name = "Gummy Fox Knox";
            m.hp = 55;
            m.damage = 80;
            m.loot = "Gummy Bust";
            break;

        case 4:
            m.name = "Rabbit Rabi";
            m.hp = 100;
            m.damage = 45;
            m.loot = "Pink Slimey Goo";
            break;

        case 5:
            m.name = "Slime";
            m.hp = 50;
            m.damage = 25;
            m.loot = "Pink Slimey Goo";
            break;

        case 6:
            m.name = "Gummy Bear";
            m.hp = 250;
            m.damage = 95;
            m.loot = "Pink Slimey Goo";
            break;

            // THE BOSSESSS
        case 7:
            m.name = "The Gummy Guardian (Mini Boss)";
            m.hp = 500;
            m.damage = 45;
            m.loot = "Gummy Bust";
            break;

        case 8:
            m.name = "KEBABEX (Mutated Kebab)";
            m.hp = 1500;
            m.damage = 0;
            m.loot = "The Legendary Skewer";
            break;
    }
    return m;
}