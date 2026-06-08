//
// Created by matve on 07-Jun-26.
//

#ifndef HRA_FIGHT_H
#define HRA_FIGHT_H

#include "player.h"
#include "wandering.h"
#include "monster.h"
#include <vector>

void enterRoom(Character& player, Wandering currentZone);
void startCombat(Character& player, int monsterCount, int bossType = 0);

#endif //HRA_FIGHT_H