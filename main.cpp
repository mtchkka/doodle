#include <iostream>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "village.h"

using namespace std;

string newName, name;

void cat() {
    cout << R"(
      ____
      |  |
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
        cout << "1. Mage\n2. Warrior\n3. Cat Warrior\n4. Boring Warrior" << endl;

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
        cout << "HP: " << myHero.hp << endl;
        cout << "Damage: " << myHero.damage << endl;
        cout << "Mana: " << myHero.mana << endl;
        cout << "Special Ability: " << myHero.ability << endl;

        cout << "Do you accept this role? {Y/N}" << endl;
        cin >> userAccept;

        if (userAccept == 'Y' || userAccept == 'y')
        userChose = true;

    } while (userChose == false);

    cout << "Now tell me, what is your name?" << endl;
    cin >> name;
    myHero.playerName = name + " The " + myHero.name;

    cout << "\nYou begin The Journey as a " << myHero.playerName << ".\n" << endl;

    Village currentVillage = generateRandVillage();

    cout << "You spawned in a " << currentVillage.name << "!" << endl;
    cout << "Here is a Book of Travel that might help you in your journey" << endl;
    showBook(myHero);

    cout << "To access the Book of Travel, you must be in a village.\n" << endl;
    cout << "As of now, you are in a village, what would you prefer to do?\n"<<endl;
    villageMenu(currentVillage);

}