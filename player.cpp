//
// Created by mat on 24-Apr-26.
//
#include "player.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

// Forward declarations for the book's pages
void showCharacterSheet(Character& player);
void showMonsterLog();
void showGameInfo();

// --- THE BOOK OF TRAVEL MENU ---
void showBook(Character& player) {
    bool reading = true;
    while (reading) {
        cout << R"(
    ========== Book of Travel ==|==|====
    |                           |  |   |
    |        1. Character Sheet  \/    |
    |        2. Monster Log            |
    |        3. Game Info              |
    |                                  |
    |        0. Close Book             |
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        )" << endl;

        cout << "What page do you turn to? ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice." << endl;
            continue;
        }

        switch (choice) {
            case 1: showCharacterSheet(player); break;
            case 2: showMonsterLog(); break;
            case 3: showGameInfo(); break;
            case 0:
                cout << "You close the Book of Travel." << endl;
                reading = false;
                break;
            default: cout << "That page doesn't exist. Pick 0-3." << endl; break;
        }
    }
}

void showCharacterSheet(Character& player) {
    cout << "\n=====================================" << endl;
    cout << "           CHARACTER SHEET           " << endl;
    cout << "=====================================" << endl;
    cout << "Name:     " << player.playerName << " the " << player.name << endl;
    cout << "Origin:   " << player.spawnVillage << endl;

    cout << "\n--- COMBAT STATS ---" << endl;
    cout << "HP:       " << player.hp << " / " << player.maxhp << endl;
    cout << "Weapon:   " << player.weaponName << " (+ " << player.weaponDamage << " Damage)" << endl;
    cout << "Armor:    " << player.armorName << " (+ " << player.armorDefense << " Def)" << endl;

    cout << "\n--- PROGRESSION ---" << endl;
    cout << "Normal Fights Won:  " << player.normalFightsWon << " / 2" << endl;
    cout << "Mini-Bosses Beaten: " << player.miniBossesDefeated << " / 3" << endl;
    cout << "Total Kills:        " << player.monstersKilled << endl;

    cout << "\n--- BACKPACK ---" << endl;
    if (player.inventory.empty()) {
        cout << "(Your bag is completely empty.)" << endl;
    } else {
        for (int i = 0; i < player.inventory.size(); i++) {
            cout << "- " << player.inventory[i] << endl;
        }
    }
    cout << "=====================================\n" << endl;
}

void showMonsterLog() {
    cout << R"(
    ============ Monster Log ===|==|====
    |                           |  |   |
    |             [MONSTERS]     \/    |
    |                                  |
    |   Pink Slime (drops Slimey Goo)  |
    |  Gummy Gooner (drops Gummy Bust) |
    | Gummy Fox Knox (drops Gummy Bust)|
    |  Rabbit Rabi (drops Slimey Goo)  |
    |    Slime (drops Slimey Goo)      |
    |  Gummy Bear (drops Slimey Goo)   |
    |                                  |
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    )" << endl;
}

void showGameInfo() {
    cout << R"(
    ========== Game Info ================

    You just need to win lol
    Win 2 normal fights -> Face a Mini Boss
    Beat 3 Mini Bosses -> Face the Main Boss

    =====================================
    )" << endl;
}

// --- HELPER FUNCTIONS FOR INVENTORY ---
int countLoot(Character& player, string targetLoot) {
    int count = 0;
    for (int i = 0; i < player.inventory.size(); i++) {
        if (player.inventory[i] == targetLoot) count++;
    }
    return count;
}

void removeLoot(Character& player, string targetLoot, int amountToRemove) {
    int removed = 0;
    for (int i = 0; i < player.inventory.size(); ) {
        if (player.inventory[i] == targetLoot && removed < amountToRemove) {
            player.inventory.erase(player.inventory.begin() + i);
            removed++;
        } else {
            i++;
        }
    }
}

// --- WEAPON UPGRADES (THE FORGE) ---
void showWeaponUpgrade(Character& player) {
    cout << "\n========== THE FORGE ==========" << endl;
    cout << "Current Weapon: " << player.weaponName << " (+ " << player.weaponDamage << " Damage)" << endl;
    cout << "Current Level:  " << player.weaponLevel << endl;
    cout << "-------------------------------" << endl;

    if (player.weaponLevel == 1) {
        int gooCount = countLoot(player, "Pink Slimey Goo");
        cout << "\n[ LEVEL 2 UPGRADE ]" << endl;
        cout << "Requires: 2 Pink Slimey Goo." << endl;
        cout << "You have: " << gooCount << " Goo." << endl;

        cout << "\nWould you like to craft this upgrade? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (gooCount >= 2) {
                cout << "\n*CLANG! CLANG! CLANG!*" << endl;
                cout << "You forge your weapon with the Slimey Goo!" << endl;

                removeLoot(player, "Pink Slimey Goo", 2);

                player.weaponLevel = 2;
                player.weaponDamage += 10;

                // Fun weapon names for your new classes!
                if (player.name == "Shroom Mt") player.weaponName = "Toxic Shroom";
                else if (player.name == "Russian Agent") player.weaponName = "Upgraded Kalashnikov";
                else if (player.name == "Freddy FazBear") player.weaponName = "Golden Microphone";
                else player.weaponName = "Racism";

                cout << "Your weapon is now a Level 2 " << player.weaponName << "!" << endl;
            } else {
                cout << "\nYou don't have enough materials!" << endl;
            }
        }
    }
    else if (player.weaponLevel == 2) {
        int gummyCount = countLoot(player, "Gummy Bust");
        cout << "\n[ LEVEL 3 UPGRADE ]" << endl;
        cout << "Requires: 2 Gummy Busts." << endl;
        cout << "You have: " << gummyCount << " Gummy Busts." << endl;

        cout << "\nWould you like to craft this upgrade? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (gummyCount >= 2) {
                cout << "\nDING DONG BING BONG PSHHHHHHHHHHHH" << endl;
                cout << "You forge your weapon with the tough Gummies!" << endl;

                removeLoot(player, "Gummy Bust", 2);

                player.weaponLevel = 3;
                player.weaponDamage += 20;

                if (player.name == "Shroom Mt") player.weaponName = "Nuclear Shroom";
                else if (player.name == "Russian Agent") player.weaponName = "Heavy Machine Gun";
                else if (player.name == "Freddy FazBear") player.weaponName = "The Bite of '87";
                else player.weaponName = "Censorship";

                cout << "Your weapon is now a MAX LEVEL " << player.weaponName << "!" << endl;
            } else {
                cout << "\nYou don't have enough materials!" << endl;
            }
        }
    }
    else if (player.weaponLevel == 3) {
        cout << "\nYour weapon has reached its maximum potential. It glows with immense power." << endl;
    }

    cout << "===============================\n" << endl;
}

Character createCharacter(int choice) {
    Character newPlayer;

    // Initialize standard trackers for ALL characters
    newPlayer.monstersKilled = 0;
    newPlayer.deaths = 0;
    newPlayer.normalFightsWon = 0;
    newPlayer.miniBossesDefeated = 0;

    switch (choice) {
        case 1:
            newPlayer.name = "Shroom Mt";
            newPlayer.spawnVillage = "Mushroom Village";
            newPlayer.hp = 50;
            newPlayer.maxhp = 50;
            newPlayer.damage = 10;
            newPlayer.weaponName = "Shroom";
            newPlayer.weaponDamage = 10;
            newPlayer.weaponLevel = 1;

            newPlayer.description = R"("
This Shroomy dude... his whole world rolls around mushrooms.
His weapon? Shroom. His armor? Hallucination.
Choose him if you.. like shrooms.
)";

            newPlayer.armorName = "Hallucination";
            newPlayer.armorDefense = 20;
            break;

        case 2:
            newPlayer.name = "Russian Agent";
            newPlayer.spawnVillage = "Siberia";
            newPlayer.hp = 250;
            newPlayer.maxhp = 250;
            newPlayer.damage = 55;
            newPlayer.weaponName = "Kalashnikov";
            newPlayer.weaponDamage = 35;
            newPlayer.weaponLevel = 1;

            newPlayer.description = R"("
[HEAVY RUSSIAN ACCENT] Volodya, volodya... Born in Siberia, cold hearted but hot body gives you a one-way
ticket into any woman bedroom. kalashnikov is your only real friend, cause others might be american agents.
You don't need a shield, you have it in your cold heart - warm love for Russia Matushka, Patriotic SHield will I say.
)";

            newPlayer.armorName = "Patriotic Shield";
            newPlayer.armorDefense = 100;
            break;

        case 3:
            newPlayer.name = "Freddy FazBear";
            newPlayer.spawnVillage = "Freddy Fazbear's Pizza Place";
            newPlayer.hp = 70;
            newPlayer.maxhp = 70;
            newPlayer.damage = 10;
            newPlayer.weaponName = "The Microphone";
            newPlayer.weaponDamage = 5;
            newPlayer.weaponLevel = 1;

            newPlayer.description = R"("
Arh Arh Arh Arh Arh Arh Arh. He will bite your head off if you're over the age of 18, but you can choose him
and scare kids, ain't that wonderful? Microphone is your main weapon, do whatever you want, even show it up
someones.. throat. Your FazSuit Plates created by the Purple Guy gives you extra defense.
)";

            newPlayer.armorName = "FazSuit Plates";
            newPlayer.armorDefense = 20;
            break;

        case 4:
            newPlayer.name = "Goy";
            newPlayer.spawnVillage = "Synagogue";
            newPlayer.hp = 50;
            newPlayer.maxhp = 50;
            newPlayer.damage = 10;
            newPlayer.weaponName = "Racism";
            newPlayer.weaponDamage = 15;
            newPlayer.weaponLevel = 1;

            newPlayer.description = R"("
Your main enemy is a JEW. They don't exist in this world, though. Your weapon is RACISM, cause
why not. The only thing defending you is your GOY hairuct, which helps quiet a lot.
)";

            newPlayer.armorName = "Haircut";
            newPlayer.armorDefense = 30;
            break;

        default:
            newPlayer.name = "Invalid";
            break;
    }

    return newPlayer;
}