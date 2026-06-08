//
// Created by matve on 24-Apr-26.
//
#include "village.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

void villageMenu(Village v) {
    cout << "\n--- " << v.name << " ---" << endl;
    cout << R"(
    ~_--~..=~--~~.,,==_--__-_
   !  1. Go Wander           1
   1                         !
   /       2. Book Of Travel }
   \                         [
   (   3. Upgrade            !
   ]                         1
   !            4. Wise Cat  )
   "__=~~..,==--_-=~=~.--__-"
)" << endl;
}

void villageMenuChoice(Character& player) {
    bool inVillage = true;

    Village v;
    v.name = player.spawnVillage;

    while (inVillage) {
        villageMenu(v);

        int choice;
        cout << "What would you like to do? ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "\nYou step out of the gates to wander the wilds..." << endl;
                inVillage = false;
                break;
            case 2:
                cout << "\nYou open your Book of Travel" << endl;
                showBook(player);
                break;
            case 3:
                cout << "\nYou walk into the Blacksmith" << endl;
                showWeaponUpgrade(player);
                break;
            case 4:
                cout << "\nYou approach the Wise Cat" << endl;
                cout << "Cat: \"Meow.\"" << endl;
                cout << "(It goes back to sleep. Very wise.)" << endl;
                break;
            default:
                cout << "Invalid choice. Please pick 1-4." << endl;
                break;
        }
    }
}