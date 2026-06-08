//
// Created by matve on 24-Apr-26.
//

#ifndef HRA_PLAYER_H
#define HRA_PLAYER_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Character {
    string name;
    string playerName;

    int hp;
    int maxhp;
    int damage;

    string description;

    int weaponDamage;
    string weaponName;
    int weaponLevel;

    string armorName;
    int armorDefense;

    int monstersKilled;
    int deaths;
    string spawnVillage;

    int normalFightsWon;
    int miniBossesDefeated;

    vector<string> inventory;
};

Character createCharacter(int choice);

void showBook(Character& player);
void showWeaponUpgrade(Character& player);

#endif //HRA_PLAYER_H
