#include <iostream>
#include <fstream>
#include <string>
#include <sqlite3.h>
#include "Database.h"
//Sqlite3 database functions
void newGame() {
	std::cout << "New game!\n";
}

void saveGame() {
	std::cout << "Game saved!\n";
}

void loadGame() {
	std::cout << "Game loaded!\n";
}

void saveAndExit() {
	saveGame();
	std::cout << "Goodbye!\n";
	exit(0);
}