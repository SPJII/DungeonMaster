#include <iostream>
#include <fstream>
#include <string>
#include "Main.h"
#include "Database.h"
#include "Time.h"
#include "Parties.h"
#include "Factions.h"
#include "Characters.h"
#include "Index.h"

int mainMenu;

void exit();

int main() {
    std::cout << "Would you like to go to main menu? (y/n)\n";
    std::string start;
    std::cin >> start;
    if (start == "n") {
        system("cls");
        std::cout << "Goodbye!\n";
        return 0;
    }

    system("cls");

    while (true) {
        displayMainMenu();
        std::cin >> mainMenu;
        system("cls");
        handleMainMenu();
    }

    return 0;
}

void displayMainMenu() {
    std::cout << "Hello Dungeon Master!\n"
        << "________________\n"
        << "| Main Menu    |\n"
        << "|______________|\n"
		<< "[1) New game   ]\n"
		<< "[2) Save Game  ]\n"
		<< "[3) Load Game  ]\n"
        << "[4) Time       ]\n"
        << "[5) Parties    ]\n"
        << "[6) Factions   ]\n"
        << "[7) Characters ]\n"
        << "[8) Index      ]\n"
        << "[0) Exit       ]\n"
        << "|______________|\n"
        << "|ENTER HERE    |: ";
}

void handleMainMenu() {
    switch (mainMenu) {
	case 1: newGame(); break;
	case 2: saveGame(); break;
	case 3: loadGame(); break;
	case 4: handleTimeMenu(); break;
	case 5: handlePartyMenu(); break;
	case 6: handleFactionMenu(); break;
	case 7: handleCharactersMenu(); break;
	case 8: handleIndexMenu(); break;
    case 0: exit(); break;
    default: std::cout << "Invalid option. Try again.\n"; break;
    }
}

void exit() {
    std::cout << "Goodbye!\n";
    exit(0);
}

