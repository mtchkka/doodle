//
// Created by mat on 24-Apr-26.
//

#ifndef HRA_VILLAGE_H
#define HRA_VILLAGE_H

#include <string>
using namespace std;

struct Village {

    string name;
    string description;
    string location;
    string type;

    int population;

};

Village generateRandVillage();

void villageMenu(Village);

#endif //HRA_VILLAGE_H
