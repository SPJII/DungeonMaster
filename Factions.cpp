#include <iostream>
#include <fstream>
#include <string>
#include "Factions.h"
#include "Database.h"
int factionMenu;

void handleFactionMenu() {
    factionMenu = -1;
    while (factionMenu != 4 && factionMenu != 0) {
        std::cout << "<-Main Menu!\n"
            << "_________________\n"
            << "| Faction Menu  |\n"
            << "|_______________|\n"
            << "[1) Load Faction]\n"
            << "[2) Diplomacy   ]\n"
            << "[3) Villages    ]\n"
            << "[4) Main Menu   ]\n"
            << "[0) Save & Exit ]\n"
            << "|_______________|\n"
            << "  ENTER HERE: ";
        std::cin >> factionMenu;
        system("cls");
        switch (factionMenu) {
        case 0: saveAndExit(); break;
        case 4: break;
        default:
            // Faction menu actions
            break;
        }
    }
}