#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "village.h"
#include "wandering.h"
#include "fight.h"

using namespace std;

string newName, name;

void cat() {
    cout << R"(
    / \__/ \
   (  ^  ^  )
    \  ==  /
     /    \
    /|    |\
   (_()..()_)
)";
}

void bookOfTravel() {
    cout << R"(
        _________
       / BOOK   /,
      /  OF    //
     / TRAVEL //
    /________//
   (________(/

)";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Character myHero;
    bool userChose = false;
    char userAccept;

    do {
        cout << "\nChoose your Hero:" << endl;
        cout << "1. Mage\n2. Russian Agent\n3. Freddy FazBear\n4. Goy" << endl;

        int userChoice;
        cin >> userChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Choose 1, 2, 3 or 4" << endl;
            continue;
        }

        myHero = createCharacter(userChoice);

        if (myHero.name == "Invalid") {
            cout << "Choose 1, 2, 3 or 4" << endl;
            continue;
        }

        cout << "Here are the stats of the " << myHero.name << endl;
        cout << myHero.description << endl;
        cout << "HP: " << myHero.hp << endl;
        cout << "Damage: " << myHero.damage << endl;
        cout << "Weapon: " << myHero.weaponName << " (+ " << myHero.weaponDamage << ")" << endl;
        cout << "Armor: " << myHero.armorName << " (+ " << myHero.armorDefense << ")" << endl;

        cout << "\nDo you accept this role? {Y/N}" << endl;
        cin >> userAccept;

        if (userAccept == 'Y' || userAccept == 'y') userChose = true;

    } while (userChose == false);

    cout << "Now tell me, what is your name?" << endl;
    cin >> name;
    myHero.playerName = name + " the " + myHero.name;

    cout << "\nYou begin The Journey as a " << myHero.playerName << ".\n" << endl;

    cout << "You finally arrive at your hometown: " << myHero.spawnVillage << "!" << endl;
    cout << "Here is a Book of Travel that might help you in your journey." << endl;

    showBook(myHero);

    bool gameRunning = true;

    while (gameRunning && myHero.hp > 0) {

        villageMenuChoice(myHero);

        if (myHero.hp > 0) {
            Wandering theWilds;
            theWilds.name = "The Dangerous Wilds";
            theWilds.monsterSpawnRate = 100;

            enterRoom(myHero, theWilds);

            if (myHero.miniBossesDefeated == 4) {
                cout << "\n==================================================" << endl;
                cout << " CONGRATULATIONS, " << myHero.playerName << "!" << endl;
                cout << " YOU DESTROYED KEBABEX, YOU WON!" << endl;
                cout << "==================================================" << endl;
                gameRunning = false;
            }
        }
    }

    if (myHero.hp <= 0) {
        cout << "\nYour journey ends here. Rest in peace, " << myHero.playerName << "." << endl;
    }

    return 0;
}