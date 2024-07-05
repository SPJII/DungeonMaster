#include <iostream>
#include <fstream>
#include <cstdlib> // for system("cls")


int mainMenu;
int timeMenu;
int partyMenu;
int factionMenu;
int questMenu;
int npcMenu;
int indexMenu;

//function declarations
int callMainMenu();
int callTimeMenu();


int hours;
int days = 1;
int day;
std::string seasons[4] = { "Spring", "Summer", "Fall", "Winter" };
std::string currentSeason;
int years = 1;

int time() {

	// if hours > 23 reset to 0 and add 1 to days
	if (hours > 23) {
		hours = 0;
		days++;
	}
	// if days <= 90 seasons = Spring, days <= 180 seasons = Summer, days <= 270 seasons = Fall, days <= 365 seasons = Winter
	if (days < 90) {
		currentSeason = seasons[0];
		day = days;
	}
	else if (days < 180) {
		currentSeason = seasons[1];
		day = abs(days - 90);
	}
	else if (days < 270) {
		currentSeason = seasons[2];
		day = abs(days - 180);
	}
	else if (days < 360) {
		currentSeason = seasons[3];
		day = abs(days - 360);
	}
	// once a year has passed add 1 to years and reset days
	else if (days >= 360) {
		days = days - 359;
		years++;
	}
	else if (days == 0) {
		day = 1;
	}
	std::cout << "Year: " << years << " /" << "Season: " << currentSeason << " /" << "Day of Season: " << day << "\n";
	return 0;
}

int callMainMenu() {

	std::cout << "Hello Dungeon Master!\n"
		<< "________________\n"
		<< "| Main Menu    |\n"
		<< "|______________|\n"
		<< "[1) Time       ]\n"
		<< "[2) Parties    ]\n"
		<< "[3) Factions   ]\n"
		<< "[4) Quests     ]\n"
		<< "[5) Npcs       ]\n"
		<< "[6) Index      ]\n"
		<< "[0) Save & Exit]\n"
		<< "|______________|\n"
		<< "|ENTER HERE    |: ";
	std::cin >> mainMenu;
	system("cls");
	if (mainMenu == 1) {
		callTimeMenu();
	}
	else if (mainMenu == 2) {
		//party
		std::cout << "<-Main Menu!\n"
			<< "_________________\n"
			<< "| Parties Menu  |\n"
			<< "|_______________|\n"
			<< "[1) Load Party  ]\n"
			<< "[2) Group Combat]\n"
			<< "[3) Warfare     ]\n"
			<< "[4) Party       ]\n"
			<< "[5) Main Menu   ]\n"
			<< "[0) Save & Exit ]\n"
			<< "|_______________|\n"
			<< "  ENTER HERE: ";
		std::cin >> partyMenu;
		system("cls");
		if (partyMenu == 0) {
			return 0;
		}
		else if (partyMenu == 5) {
			callMainMenu();
		}
		//int party(int partyMenu);
	}
	else if (mainMenu == 3) {
		//factions
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
		if (factionMenu == 0) {
			return 0;
		}
		else if (factionMenu == 4) {
			callMainMenu();
		}
		//int faction(int factionMenu);

	}
	else if (mainMenu == 4) {
		//quests
		std::cout << "<-Main Menu!\n"
			<< "_________________\n"
			<< "| Quest Menu    |\n"
			<< "|_______________|\n"
			<< "[1) Load Quest  ]\n"
			<< "[2) Create Quest]\n"
			<< "[3) Quest Reward]\n"
			<< "[4) Main Menu   ]\n"
			<< "[0) Save & Exit ]\n"
			<< "|_______________|\n"
			<< "  ENTER HERE: ";
		std::cin >> questMenu;
		system("cls");
		if (questMenu == 0) {
			return 0;
		}
		else if (questMenu == 4) {
			callMainMenu();
		}
		system("cls");
		//int quest(int questMenu);
	}
	else if (mainMenu == 5) {
		//npcs
		std::cout << "<-Main Menu!\n"
			<< "_________________\n"
			<< "|   NPC Menu    |\n"
			<< "|_______________|\n"
			<< "[1) Load NPC    ]\n"
			<< "[2) Create NPC  ]\n"
			<< "[3) NPC List    ]\n"
			<< "[4) Main Menu   ]\n"
			<< "[0) Save & Exit ]\n"
			<< "|_______________|\n"
			<< "  ENTER HERE: ";
		std::cin >> npcMenu;
		system("cls");
		if (npcMenu == 0) {
			return 0;
		}
		else if (npcMenu == 4) {
			callMainMenu();
		}
		system("cls");
	}
	else if (mainMenu == 6) {
		//index
		std::cout << "<-Main Menu!\n"
			<< "___________________\n"
			<< "|   Index Menu    |\n"
			<< "|_________________|\n"
			<< "[1) Monster Index ]\n"
			<< "[2) humanoid Index]\n"
			<< "[3) Item List     ]\n"
			<< "[4) Spell List    ]\n"
			<< "[5) Main Menu     ]\n"
			<< "[0) Save & Exit   ]\n"
			<< "|_________________|\n"
			<< "  ENTER HERE: ";
		std::cin >> indexMenu;
		system("cls");
		if (indexMenu == 0) {
			return 0;
		}
		else if (indexMenu == 5) {
			callMainMenu();
		}
		system("cls");
	}
	else if (mainMenu == 0) {
		//exit
		std::cout << "Saving...\n";
		//int save();
		std::cout << "Goodbye!\n";
		return 0;
	}
	return 0;
}

int callTimeMenu() {
	std::string changeTime;
	int addTime;
	std::cout << "<-Main Menu!\n";
	std::cout << "Date: ";
	time();
	std::cout
		<< "____________________\n"
		<< "|   Time Menu      |\n"
		<< "|__________________|\n"
		<< "[1) Long Rest      ]\n"
		<< "[2) Short Rest     ]\n"
		<< "[3) Change Time    ]\n"
		<< "[4) Important Dates]\n"
		<< "[5) Main Menu      ]\n"
		<< "[0) Save & Exit    ]\n"
		<< "|__________________|\n"
		<< "  ENTER HERE: ";

	std::cin >> timeMenu;
	system("cls");
	if (timeMenu == 1) {
		// long rest is 1 to 7 days
		std::cout << "[How long would you like this long rest to be?]\n";
		std::cin >> addTime;
		// if cin addTime is invalid 

		days += addTime;
	}
	else if (timeMenu == 2) {
		// short rest is 1 to 24 hours
		std::cout << "[How long would you like this short rest to be?]\n";
		std::cin >> addTime;
		hours += addTime;
	}
	else if (timeMenu == 3) {
		// change time
		std::cout << "____________________________________________\n"
			<< "|What would you like to change the time to?|\n"
			<< "|__________________________________________|\n"
			<< "[1) Hours                                  ]\n"
			<< "[2) Days                                   ]\n"
			<< "[3) Seasons                                ]\n"
			<< "[4) Years                                  ]\n"
			<< "|__________________________________________|\n";

		std::cin >> changeTime;
		if (changeTime == "1") {
			std::cout << "How many hours would you like to add?\n";
			std::cin >> addTime;
			hours += addTime;
		}
		else if (changeTime == "2") {
			std::cout << "How many days would you like to add?\n";
			std::cin >> addTime;
			days += addTime;
		}
		else if (changeTime == "3") {
			std::cout << "Would you like to skip to next season?\n"
				<< "[1) Yes ]\n"
				<< "[2) No  ]\n";
			std::cin >> addTime;
			if (addTime == 1) {
				days = +90;
			}
			else if (addTime == 2) {
				days = +0;
			}
		}
		else if (changeTime == "4") {
			std::cout << "How many years would you like to pass?\n";
			std::cin >> addTime;
			years += addTime;
		}
	}
	else if (timeMenu == 4) {
		// important dates
		std::cout << "___________________________________________________\n"
			<< "|1) What would you save a date to important dates?|\n"
			<< "|2) Or print list of Important dates?             |\n"
			<< "|_________________________________________________|\n";
		std::cin >> changeTime;
		if (changeTime == "1") {
			std::cout << "What date would you like to save?\n";
			std::cin >> addTime;

			// wip
		}
		else if (changeTime == "2") {
			std::cout << "Here is a list of important dates:\n";
			// wip
		}
	}
	else if (timeMenu == 0) {
		return 0;
	}
	else if (timeMenu == 5) {
		callMainMenu();
	}
	system("cls");
	callTimeMenu();
}


int main() {
	std::cout << "Would you like to go to main menu? (y/n)\n";
	std::string start;
	std::cin >> start;
	if (start == "n") {
		system("cls");
		//close program
		std::cout << "Goodbye!\n";
		return 0;
	}

	//clear console
	system("cls");

	//main menu
	callMainMenu();
}