//
// Created by mat on 24-Apr-26.
//

#ifndef HRA_VILLAGE_H
#define HRA_VILLAGE_H

#include <string>
#include <iostream>
#include "player.h"
using namespace std;


struct Village {

    string name;

};

void villageMenu(Village v);
void villageMenuChoice(Character& player);

#endif //HRA_VILLAGE_H
