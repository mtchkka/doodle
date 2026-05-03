//
// Created by matve on 24-Apr-26.
//

#ifndef HRA_PLAYER_H
#define HRA_PLAYER_H

#include <string>
#include <iostream>
using namespace std;

struct Character {

    string name;
    string playerName;

    int hp;
    int maxhp;
    int damage;
    int mana;
    int maxMana;

    int money;
    int level;
    int experience;

    string ability;
};

Character createCharacter(int choice);

void showBook(Character);

#endif //HRA_PLAYER_H
