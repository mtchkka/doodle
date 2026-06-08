//
// Created by matve on 07-Jun-26.
//
#include "fight.h"
#include "monster.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

bool areAllMonstersDead(const vector<Monster>& group) {
    for (int i = 0; i < group.size(); i++) {
        if (group[i].isAlive) return false;
    }
    return true;
}

void enterRoom(Character& player, Wandering currentZone) {
    cout << "\nYou open the heavy gates and step into " << currentZone.name << "..." << endl;

    int bossType = 0;
    int monsterAmount = 0;

    // progress
    if (player.miniBossesDefeated == 3) {
        cout << "Oh no no no no... It's... Kebabex..." << endl;
        bossType = 8;
        monsterAmount = 1;
    }
    else if (player.normalFightsWon >= 2) {
        cout << "A massive shadow blocks your path. A MINI BOSS appears!" << endl;
        bossType = 7;
        monsterAmount = 1;
    }
    else {
        monsterAmount = (rand() % 3) + 1;
        if (monsterAmount == 1) cout << "A monster jumps out of the bushes" << endl;
        else cout << "Jaj! " << monsterAmount << " monsters attack you!" << endl;
    }

    startCombat(player, monsterAmount, bossType);
}

void startCombat(Character& player, int monsterCount, int bossType) {
    cout << "\n=== COMBAT STARTED ===" << endl;

    vector<Monster> monsterGroup;

    // kebabex
    int kebabexPhase = 1;
    int kebabexFatDamage = 2;

    for (int i = 0; i < monsterCount; i++) {
        Monster m;

        if (bossType != 0) {
            m = spawnMonster(bossType);
        } else {
            int randomType = (rand() % 6) + 1;
            m = spawnMonster(randomType);

            if (monsterCount == 2) {
                m.hp = (m.hp * 60) / 100;
                m.damage = (m.damage * 60) / 100;
            } else if (monsterCount == 3) {
                m.hp = (m.hp * 43) / 100;
                m.damage = (m.damage * 43) / 100;
            }
            m.name = m.name + " " + to_string(i + 1);
        }

        monsterGroup.push_back(m);
    }

    while (player.hp > 0 && !areAllMonstersDead(monsterGroup)) {

        // PLAYER TURND
        cout << "\n=== YOUR TURN ===" << endl;
        int targetIndex = -1;

        while (true) {
            cout << "Which monster do you attack?" << endl;
            for (int i = 0; i < monsterGroup.size(); i++) {
                if (monsterGroup[i].isAlive) {
                    cout << "[" << i + 1 << "] " << monsterGroup[i].name << " (HP: " << monsterGroup[i].hp << ")" << endl;
                }
            }
            cout << "Choice: ";

            int targetChoice;
            cin >> targetChoice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Try again.\n" << endl;
            } else {
                targetIndex = targetChoice - 1;
                if (targetIndex >= 0 && targetIndex < monsterGroup.size() && monsterGroup[targetIndex].isAlive) {
                    break;
                } else {
                    cout << "Invalid target! Try again.\n" << endl;
                }
            }
        }

        int d20 = (rand() % 20) + 1;
        cout << "\nYou rolled a " << d20 << "!" << endl;

        int totalBaseDamage = player.damage + player.weaponDamage;
        int finalDamage = 0;

        if (d20 >= 1 && d20 <= 5) {
            int penaltyPercent = 15 - ((d20 - 1) * 3);
            finalDamage = totalBaseDamage - ((totalBaseDamage * penaltyPercent) / 100);
            cout << "Too bad... You deal " << finalDamage << " damage to " << monsterGroup[targetIndex].name << "." << endl;
            monsterGroup[targetIndex].hp -= finalDamage;
        }
        else if (d20 >= 6 && d20 <= 15) {
            int bonusPercent = 12 + ((d20 - 6) * 2);
            finalDamage = totalBaseDamage + ((totalBaseDamage * bonusPercent) / 100);
            cout << "Hell yeah! You deal " << finalDamage << " damage to " << monsterGroup[targetIndex].name << "." << endl;
            monsterGroup[targetIndex].hp -= finalDamage;
        }
        else if (d20 >= 16 && d20 <= 18) {
            finalDamage = player.damage + (player.weaponDamage * 2);
            cout << "LUCKY! Your weapon glows, dealing " << finalDamage << " damage to " << monsterGroup[targetIndex].name << "!" << endl;
            monsterGroup[targetIndex].hp -= finalDamage;
        }
        else if (d20 == 19) {
            cout << "WATAFAAAk! All monsters lose half their HP!" << endl;
            for (int i = 0; i < monsterGroup.size(); i++) {
                if (monsterGroup[i].isAlive) {
                    monsterGroup[i].hp /= 2;
                    if (monsterGroup[i].hp <= 0) {
                        monsterGroup[i].isAlive = false;
                        player.monstersKilled++;
                        cout << monsterGroup[i].name << " drops dead!" << endl;
                    }
                }
            }
            int healAmount = (player.maxhp * 20) / 100;
            player.hp += healAmount;
            if (player.hp > player.maxhp) player.hp = player.maxhp;
            cout << "You heal for " << healAmount << " HP. (Current HP: " << player.hp << ")" << endl;
        }
        else if (d20 == 20) {
            cout << "YOU ROLLED 20!!" << endl;
            if (bossType == 0) {
                cout << "RASTRELYAU, " << player.playerName << "! GODLY 20!!" << endl;
                for (int i = 0; i < monsterGroup.size(); i++) {
                    if (monsterGroup[i].isAlive) {
                        monsterGroup[i].hp = 0;
                        monsterGroup[i].isAlive = false;
                        player.monstersKilled++;
                    }
                }
            } else {
                finalDamage = totalBaseDamage * 3;
                cout << "You strike the Boss for a massive " << finalDamage << " damage!" << endl;
                monsterGroup[targetIndex].hp -= finalDamage;
            }
        }

        if (d20 < 20 && monsterGroup[targetIndex].hp <= 0 && monsterGroup[targetIndex].isAlive) {
            monsterGroup[targetIndex].isAlive = false;
            player.monstersKilled++;
            cout << monsterGroup[targetIndex].name << " drops dead!" << endl;
        }

        if (areAllMonstersDead(monsterGroup)) break;

        // ENEMY ATTAc
        cout << "\n=== ENEMIES ATTACK ===" << endl;
        for (int i = 0; i < monsterGroup.size(); i++) {
            if (monsterGroup[i].isAlive) {

                // KEBABEX LOGICC
                if (bossType == 8) {
                    cout << "\n[FAZE " << kebabexPhase << "]" << endl;

                    if (kebabexPhase == 1) {
                        cout << "Kebabex is rolling on fire! Prepare!" << endl;
                    }
                    else if (kebabexPhase == 2) {
                        cout << "Kebabex is overflowing with fatness." << endl;
                        player.hp -= kebabexFatDamage; // Ignores armor
                        cout << "I'm dealing you " << kebabexFatDamage << " of pure agony! (Your HP: " << player.hp << ")" << endl;
                        kebabexFatDamage += 2; // Scales for the next round
                    }
                    else if (kebabexPhase == 3) {
                        cout << "Kebabex made babies! SON! Now all his kids are attacking you!" << endl;
                        int pieceDamage = (player.hp / 10) * 1;
                        if (pieceDamage < 1) pieceDamage = 1; // Minimum 1 damage
                        player.hp -= pieceDamage; // Ignores armor
                        cout << "Those babies deals you " << pieceDamage << " of not-so-pure agony! (Your HP: " << player.hp << ")" << endl;
                    }
                    else if (kebabexPhase == 4) {
                        cout << "Kebabex rolled around in garlic-herbal sauce." << endl;
                        int sauceRoll = rand() % 2;

                        if (sauceRoll == 0) {
                            cout << "[Garlic] Kebabex is healing 10HP!" << endl;
                            monsterGroup[i].hp += 10;
                        } else {
                            cout << "[Herbal] Kebabex is healing 20HP to himself and 10HP to you!" << endl;
                            monsterGroup[i].hp += 20;
                            player.hp += 10;
                            if (player.hp > player.maxhp) player.hp = player.maxhp;
                        }
                    }

                    // next
                    kebabexPhase++;
                    if (kebabexPhase > 4) kebabexPhase = 1;

                    if (player.hp <= 0) {
                        cout << "You have been slain, tortured and fianlly eaten by Kebabex..." << endl;
                        break;
                    }
                }
                // mini boss normal boss
                else {
                    int missChance = rand() % 15;

                    if (missChance == 0) {
                        cout << monsterGroup[i].name << " swings at you and misses entirely!" << endl;
                    } else {
                        int dmgPercent = 30 + (rand() % 71);
                        int actualDamage = (monsterGroup[i].damage * dmgPercent) / 100;

                        actualDamage -= player.armorDefense;
                        if (actualDamage < 0) actualDamage = 0;

                        player.hp -= actualDamage;
                        cout << monsterGroup[i].name << " hits you for " << actualDamage << " damage! (Your HP: " << player.hp << ")" << endl;

                        if (player.hp <= 0) {
                            cout << "You have been slain..." << endl;
                            break;
                        }
                    }
                }
            }
        }
        cout << "====================" << endl;
    }

    if (player.hp > 0) {
        cout << "\n=== VICTORY! ===" << endl;

        cout << "\n[ LOOT RECOVERED ]" << endl;
        for (int i = 0; i < monsterGroup.size(); i++) {
            player.inventory.push_back(monsterGroup[i].loot);
            cout << "+ " << monsterGroup[i].loot << endl;
        }

        if (bossType == 8) {
            player.miniBossesDefeated = 4;
        }
        else if (bossType == 7) {
            player.miniBossesDefeated++;
            player.normalFightsWon = 0;
            cout << "\nMini-Boss defeated! (Total Mini-Bosses Defeated: " << player.miniBossesDefeated << " / 3)" << endl;
        }
        else {
            player.normalFightsWon++;
            cout << "\nNormal encounter cleared! (Normal Fights Won: " << player.normalFightsWon << " / 2)" << endl;
        }

    } else {
        cout << "\n=== GAME OVER ===" << endl;
        player.deaths++;
    }
}