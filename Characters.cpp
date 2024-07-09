#include <iostream>
#include <fstream>
#include <string>
#include "Characters.h"
#include "Database.h"
int CharacterMenu;

void handleCharactersMenu() {
    CharacterMenu = -1;
    while (CharacterMenu != 4 && CharacterMenu != 0) {
        std::cout << "<-Main Menu!\n"
            << "____________________\n"
            << "|   Character Menu  |\n"
            << "|___________________|\n"
            << "[1) Load Character  ]\n"
            << "[2) Create Character]\n"
            << "[3) Character List  ]\n"
            << "[4) Main Menu       ]\n"
            << "[0) Save & Exit     ]\n"
            << "|___________________|\n"
            << "  ENTER HERE: ";
        std::cin >> CharacterMenu;
        system("cls");
        switch (CharacterMenu) {
        case 0: saveAndExit(); break;
        case 4: break;
        default:
            // NPC menu actions
            break;
        }
    }
}

class Character {
public:
	int Id;
	std::string name;
	std::string faction;
	std::string party;
    std::string bio;
	int level = 1;
	int maxHealth = 100;
	int health = 100;
	int maxMana = 100;
	int mana = 100;
	int prowess = 10;
	int agility = 10;
	int constitution = 10;
	int intelligence = 10;
	int wisdom = 10;

	void levelUp() {
		level++;
		// players can choose 2 attributes to increase; Max health, Max mana, prowess, agility, constitution or intelligence by 2. Wisdom always increase by 1.
		std::cout << "Choose the first attribute to increase: ";
		std::cout
			<< "1) Health"
			<< "2) Mana pool"
			<< "3) Agility"
			<< "4) Constitution"
			<< "5) Intelligence\n";
		int choice1;
		std::cin >> choice1;
		if (choice1 < 1 || choice1 > 5) {
			std::cout << "Invalid choice. Choose another one: ";
			std::cin >> choice1;
		}
		switch (choice1) {
		case 1:
			maxHealth += 2;
			break;
		case 2:
			maxMana += 2;
			break;
		case 3:
			agility += 2;
			break;
		case 4:
			constitution += 2;
			break;
		case 5:
			intelligence += 2;
			break;
		}
		std::cout << "Choose the second attribute to increase: ";
		std::cout
			<< "1) Health"
			<< "2) Mana pool"
			<< "3) Agility"
			<< "4) Constitution"
			<< "5) Intelligence\n";
		int choice2;
		std::cin >> choice2;
		if (choice2 == choice1) {
			std::cout << "You have already chosen this attribute. Choose another one: ";
			std::cin >> choice2;
		}
		else if (choice2 < 1 || choice2 > 5) {
			std::cout << "Invalid choice. Choose another one: ";
			std::cin >> choice2;
		}
		switch (choice2) {
		case 1:
			maxHealth += 2;
			break;
		case 2:
			maxMana += 2;
			break;
		case 3:
			agility += 2;
			break;
		case 4:
			constitution += 2;
			break;
		case 5:
			intelligence += 2;
			break;
		}
		wisdom++;
		// save character changes to database
	}

	void takeDamage(int damage) {
		health -= damage;
		if (health < 0) {
			health = 0;
		}
	}

	void heal(int amount) {
		health += amount;
		if (health > maxHealth) {
			health = maxHealth;
		}
	}

	void restoreMana(int amount) {
		mana += amount;
		if (mana > maxMana) {
			mana = maxMana;
		}
	}

	void castSpell(int cost) {
		mana -= cost;
		if (mana < 0) {
			mana = 0;
		}
	}

	void displayStats() {
		std::cout << "Name: " << name << "\n";
		std::cout << "Faction: " << faction << "\n";
		std::cout << "Party: " << party << "\n";
		std::cout << "Bio: " << bio << "\n";
		std::cout << "Level: " << level << "\n";
		std::cout << "Health: " << health << "/" << maxHealth << "\n";
		std::cout << "Mana: " << mana << "/" << maxMana << "\n";
		std::cout << "Prowess: " << prowess << "\n";
		std::cout << "Agility: " << agility << "\n";
		std::cout << "Constitution: " << constitution << "\n";
		std::cout << "Intelligence: " << intelligence << "\n";
		std::cout << "Wisdom: " << wisdom << "\n";
	}	

	void death() {
		// if health reaches 0, character dies
		// remove character from party
		// save character to database
	}
};

void createCharacter() {
	Character character;
	std::cout << "Enter character name: ";
	std::cin >> character.name;
	std::cout << "Enter character faction: ";
	std::cin >> character.faction;
	std::cout << "Enter character party: ";
	std::cin >> character.party;
	std::cout << "Enter character bio: ";
	std::cin >> character.bio;
	std::cout << "Enter character level: ";
	std::cin >> character.level;
	std::cout << "Enter character health: ";
	std::cin >> character.health;
	std::cout << "Enter character mana: ";
	std::cin >> character.mana;
	std::cout << "Enter character prowess: ";
	std::cin >> character.prowess;
	std::cout << "Enter character agility: ";
	std::cin >> character.agility;
	std::cout << "Enter character constitution: ";
	std::cin >> character.constitution;
	std::cout << "Enter character intelligence: ";
	std::cin >> character.intelligence;
	std::cout << "Enter character wisdom: ";
	std::cin >> character.wisdom;
	// save character to database
	
}	

void editCharacter() {
	// choose which attribute to edit
	Character character;
	std::cout << "Enter character name: ";
	std::cin >> character.name;
	// load character from database
	std::cout << "Edit character: " << character.name << "\n";
	std::cout << "1) Name: " << character.name << "\n";
	std::cout << "2) Faction: " << character.faction << "\n";
	std::cout << "3) Party: " << character.party << "\n";
	std::cout << "4) Bio: " << character.bio << "\n";
	std::cout << "5) Level: " << character.level << "\n";
	std::cout << "6) Health: " << character.health << "\n";
	std::cout << "7) Mana: " << character.mana << "\n";
	std::cout << "8) Prowess: " << character.prowess << "\n";
	std::cout << "9) Agility: " << character.agility << "\n";
	std::cout << "10) Constitution: " << character.constitution << "\n";
	std::cout << "11) Intelligence: " << character.intelligence << "\n";
	std::cout << "12) Wisdom: " << character.wisdom << "\n";
	std::cout << "0) Exit\n";
	std::cout << "Choose attribute to edit: ";
	int choice;
	std::cin >> choice;
	switch (choice) {
	case 1:
		std::cout << "Enter new name: ";
		std::cin >> character.name;
		break;
	case 2:
		std::cout << "Enter new faction: ";
		std::cin >> character.faction;
		break;
	case 3:
		std::cout << "Enter new party: ";
		std::cin >> character.party;
		break;
	case 4:
		std::cout << "Enter new bio: ";
		std::cin >> character.bio;
		break;
	case 5:
		std::cout << "Enter new level: ";
		std::cin >> character.level;
		break;
	case 6:
		std::cout << "Enter new health: ";
		std::cin >> character.health;
		break;
	case 7:
		std::cout << "Enter new mana: ";
		std::cin >> character.mana;
		break;
	case 8:
		std::cout << "Enter new prowess: ";
		std::cin >> character.prowess;
		break;
	case 9:
		std::cout << "Enter new agility: ";
		std::cin >> character.agility;
		break;
	case 10:
		std::cout << "Enter new constitution: ";
		std::cin >> character.constitution;
		break;
	case 11:
		std::cout << "Enter new intelligence: ";
		std::cin >> character.intelligence;
		break;
	case 12:
		std::cout << "Enter new wisdom: ";
		std::cin >> character.wisdom;
		break;
	case 0:
		break;
	default:
		std::cout << "Invalid option. Try again.\n";
		break;

	}
	// save character to database

}	

void deleteCharacter() {
	Character character;
	std::cout << "Enter character name: ";
	std::cin >> character.name;
	// load character from database
	std::cout << "Delete character: " << character.name << "\n";
	std::cout << "1) Yes\n";
	std::cout << "2) No\n";
	std::cout << "Choose option: ";
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		// delete character from database
	}
}

void viewCharacters() {
	// load all characters from database
	// display all characters
}

void saveCharacters() {
	// save all characters to database
}

void loadCharacters() {
	// load all characters from database
}