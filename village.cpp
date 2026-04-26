//
// Created by matve on 24-Apr-26.
//
#include "Village.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void villageMenu(Village) {
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
)";
}


Village generateRandVillage() {

    Village v;

    int roll = rand() % 3;

    switch (roll) {
        case 0:
            v.name = "Fortress";
            v.description = "Fortress";
            v.location = "Fortress";
            v.type = "Mountain Fortress";
            v.population = 30;
            break;
        case 1:
            v.name = "Village by The Lake";
            v.description = "Fortress";
            v.location = "Fortress";
            v.type = "Mountain Fortress";
            v.population = 30;
            break;
        case 2:
            v.name = "Muriom";
            v.description = "Fortress";
            v.location = "Fortress";
            v.type = "Mountain Fortress";
            v.population = 30;
            break;
    }
    return v;
}