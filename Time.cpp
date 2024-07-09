#include <iostream>
#include <fstream>
#include <string>
#include "Main.h"
#include "Time.h"
#include "Database.h"

int hours, days = 1, day, years = 1, timeMenu;
std::string seasons[4] = { "Spring", "Summer", "Fall", "Winter" };
std::string currentSeason;

void updateTime() {
    if (hours > 23) {
        hours = 0;
        days++;
    }

    if (days < 90) {
        currentSeason = seasons[0];
        day = days;
    }
    else if (days < 180) {
        currentSeason = seasons[1];
        day = days - 90;
    }
    else if (days < 270) {
        currentSeason = seasons[2];
        day = days - 180;
    }
    else if (days < 360) {
        currentSeason = seasons[3];
        day = days - 270;
    }
    else if (days >= 360) {
        days = days - 359;
        years++;
    }

    if (days == 0) {
        day = 1;
    }

    std::cout << "Year: " << years << " / Season: " << currentSeason << " / Day of Season: " << day << "\n";
}


void handleTimeMenu() {
    timeMenu = -1;
    while (timeMenu != 5 && timeMenu != 0) {
        std::string changeTime;
        int addTime;
        std::cout << "<-Main Menu!\n";
        std::cout << "Date: ";
        updateTime();
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
        switch (timeMenu) {
        case 1:
            std::cout << "[How long would you like this long rest to be?]\n";
            std::cin >> addTime;
            days += addTime;
            break;
        case 2:
            std::cout << "[How long would you like this short rest to be?]\n";
            std::cin >> addTime;
            hours += addTime;
            break;
        case 3:
            std::cout
                << "____________________________________________\n"
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
                    days += 90;
                }
            }
            else if (changeTime == "4") {
                std::cout << "How many years would you like to pass?\n";
                std::cin >> addTime;
                years += addTime;
            }
            break;
        case 4:
            std::cout
                << "___________________________________________________\n"
                << "|1) What would you save a date to important dates?|\n"
                << "|2) Or print list of Important dates?             |\n"
                << "|_________________________________________________|\n";
            std::cin >> changeTime;
            if (changeTime == "1") {
                std::cout << "What date would you like to save?\n";
                std::cin >> addTime;
                // WIP
            }
            else if (changeTime == "2") {
                std::cout << "Here is a list of important dates:\n";
                // WIP
            }
            break;
        case 0: saveAndExit(); break;
        case 5: break;
        default: std::cout << "Invalid option. Try again.\n"; break;
        }
        system("cls");
    }
}

