#include <iostream>
#include <fstream>
#include <string>
#include "Index.h"
#include "Database.h"

int indexMenu;

void handleIndexMenu() {
    indexMenu = -1;
    while (indexMenu != 5 && indexMenu != 0) {
        std::cout << "<-Main Menu!\n"
            << "___________________\n"
            << "|   Index Menu    |\n"
            << "|_________________|\n"
            << "[1) Monster Index ]\n"
            << "[2) Humanoid Index]\n"
            << "[3) Item List     ]\n"
            << "[4) Spell List    ]\n"
            << "[5) Main Menu     ]\n"
            << "[0) Save & Exit   ]\n"
            << "|_________________|\n"
            << "  ENTER HERE: ";
        std::cin >> indexMenu;
        system("cls");
        switch (indexMenu) {
        case 0: saveAndExit(); break;
        case 5: break;
        default:
            // Index menu actions
            break;
        }
    }
}
