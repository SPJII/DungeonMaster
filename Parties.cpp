#include <iostream>
#include <fstream>
#include <string>
#include "Parties.h"
#include "Database.h"

int partyMenu, questMenu;

// conciliation of the two functions
void handlePartyMenu() {
    partyMenu = -1;
    while (partyMenu != 7 && partyMenu != 0) {
        std::cout << "<-Main Menu!\n"
            << "_________________\n"
            << "| Parties Menu  |\n"
            << "|_______________|\n"
            << "[1) Load Party  ]\n"
            << "[2) Create Party]\n"
            << "[3) Edit Party  ]\n"
            << "[4) Delete Party]\n"
            << "[5) View Parties]\n"
            << "[6) Group Combat]\n"
            << "[7) Main Menu   ]\n"
            << "[0) Save & Exit ]\n"
            << "|_______________|\n"
            << "  ENTER HERE: ";
        std::cin >> partyMenu;
        system("cls");
        switch (partyMenu) {
        case 1: loadParties(); break;
        case 2: createParty(); break;
        case 3: editParty(); break;
        case 4: deleteParty(); break;
        case 5: viewParties(); break;
        case 6: groupCombat(); break;
        case 7: return;
        case 0: saveAndExit(); break;
        default: std::cout << "Invalid option. Try again.\n"; break;
        }
    }
}

void createParty() {

}

void editParty() {
}

void deleteParty() {
}

void viewParties() {

}

void saveParties() {
}

void loadParties() {

}

void groupCombat() {
}

void handleQuestMenu() {
    questMenu = -1;
    while (questMenu != 3 && questMenu != 0) {
        std::cout << "<-Main Menu!\n"
            << "_________________\n"
            << "| Quest Menu    |\n"
            << "|_______________|\n"
            << "[1) View Quests ]\n"
            << "[2) Create Quest]\n"
            << "[3) Main Menu   ]\n"
            << "[0) Save & Exit ]\n"
            << "|_______________|\n"
            << "  ENTER HERE: ";
        std::cin >> questMenu;
        system("cls");
        switch (questMenu) {
        case 0: saveAndExit(); break;
        case 3: break;
        default:
            // Quest menu actions
            break;
        }
    }
}
