//
// Created by mat on 24-Apr-26.
//
#include "player.h"

#include <iostream>
using namespace std;

void showBook(Character) {
    cout << R"(
    ========== Book of Travel ==|==|====
    |                           |  |   |
    |        1. Inventory        \/    |
    |        2. Character info         |
    |        3. Character upgrade      |
    |        4. Enemies info           |
    |        5. Game info              |
    |                                  |
    |    (Press Enter to get back)     |
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
)" << endl;
    cin.ignore();
    cin.get();
}

int name;

Character createCharacter(int choice) {
    Character newPlayer;

    switch (choice) {
        case 1:
            newPlayer.name = "Mage";
            newPlayer.playerName = name;
            newPlayer.hp = 100;
            newPlayer.maxhp = 100;
            newPlayer.damage = 10;
            newPlayer.mana = 5;
            newPlayer.maxMana = 5;
            newPlayer.money = 0;
            newPlayer.level = 1;
            newPlayer.experience = 0;
            newPlayer.ability = "Fireball";
            break;
        case 2:
            newPlayer.name = "Warrior";
            newPlayer.hp = 150;
            newPlayer.maxhp = 150;
            newPlayer.damage = 7;
            newPlayer.mana = 4;
            newPlayer.maxMana = 4;
            newPlayer.money = 0;
            newPlayer.level = 1;
            newPlayer.experience = 0;
            newPlayer.ability = "Super Shield";
            break;
        case 3:
            newPlayer.name = "Cat Warrior";
            newPlayer.hp = 60;
            newPlayer.maxhp = 60;
            newPlayer.damage = 15;
            newPlayer.mana = 10;
            newPlayer.maxMana = 5;
            newPlayer.money = 0;
            newPlayer.level = 1;
            newPlayer.experience = 0;
            newPlayer.ability = "Super Speed";
            break;
        case 4:
            newPlayer.name = "Boring Warrior";
            newPlayer.hp = 150;
            newPlayer.maxhp = 150;
            newPlayer.damage = 7;
            newPlayer.mana = 4;
            newPlayer.maxMana = 4;
            newPlayer.money = 0;
            newPlayer.level = 1;
            newPlayer.experience = 0;
            newPlayer.ability = "Super Shield";
            break;
        default:
            newPlayer. name = "Invalid";
            break;
    }

            return newPlayer;
    }