#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include "combat.h"

Character* startupLevel()
{
	string name;
	string race;
	vector<Skill*> skillSet;
	Stats* attributes = new Stats;
	cout << "Awake!" << endl;
	cout << "You wake, who are you?" << endl;
	cout << "Please choose a name: ";
	cin >> name;
	cout << endl;
	cout << "Of what race are you?" << endl;

	bool quit = false;
	while(quit == false)
	{
		cout << "There are four different races:" << endl;
		cout << "1) Humans - Humans are very versatile and can adapt to any class, but gain no racial bonuses" << endl;
		cout << "2) Elves - Elves are secretive and wise, highly specalised to magice, they are also stupendous rangers, Elves have higher dexterity and more mana but have a penalty to strength and constitution" << endl;
		cout << "3) Dwarves - Dwarves are tough and sturdy, dwarves are resistant to magic and make great fighters and paladins but are not know for their intelligence, dwarves have a bonus to constitution but a penalty to intelligence and dexterity" << endl;
		cout << "Please choose one of these options by pressing 1 - Human, 2 - Elf, 3 - Dwarf or 4 - See descriptions again" << endl;

		int choice;
		cin >> choice;

		if(choice == 1)
		{
			cout << "You have chosen Human! Wisely Chosen!" << endl;
			race = "human";
			attributes->make_Stats(10, 10, 10, 10);
			quit = true;
		}

		else if(choice == 2)
		{
			cout << "You have chosen an Elf! Wisely Chosen!" << endl;
			race = "elf";
			attributes->make_Stats(5, 15, 5, 15);
			quit = true;
		}

		else if(choice == 3)
		{
			cout << "You have chosen dwarf! Wisely Chosen!" << endl;
			race = "dwarf";
			attributes->make_Stats(15, 5, 15, 5);
			quit = true;
		}

		else
		{
			//Loop again baby
		}
	}

	cout << endl;

	string type;

	quit = false;
	while(quit == false)
	{
		int choice;
		cout << "What kind of hero are you?" << endl;
		cout << "Press 1) - Warrior" << endl;
		cout << "Press 2) - Hunter" << endl;
		cout << "Press 3) - Paladin" << endl;
		cout << "Press 4) - Mage" << endl;
		cout << "Press 5) - See all options" << endl;
		cin >> choice;

		if(choice == 1)
		{
			cout << "You chose Warrior! Go Bash some heads in!" << endl;
			type = "fighter";
			skillSet = generate_fighter_skills();
			quit = true;
		}

		else if(choice == 2)
		{
			cout << "You chose Hunter! Go....ummm....hunt some things!" << endl;
			type = "hunter";
			skillSet = generate_hunter_skills();
			quit = true;
		}	


		else if(choice == 3)
		{
			cout << "You chose Paladin! Go banish some evil!" << endl;
			type = "paladin";
			skillSet = generate_paladin_skills();
			quit = true;
		}

		else if(choice == 4)
		{
			cout << "You chose Mage! Go blow shit up!" << endl;
			type = "mage";
			skillSet = generate_mage_skills();
			quit = true;
		}
	

		else
		{
			//Loop baby loop
		}
	}

	cout << endl;

	int attributePoints = 10;
	while(attributePoints != 0)
	{
		cout << "You have " << attributePoints << " points remaining to spend on your attributes." << endl;
		cout << "Press 1) - Strength. Current Value = " << attributes->strength << endl;
		cout << "Press 2) - Dexterity. Current Value = " << attributes->dexterity << endl;
		cout << "Press 3) - Constitution. Current Value = " << attributes->constitution << endl;
		cout << "Press 4) - Intelligence. Current Value = " << attributes->intelligence << endl;
		cout << "Press 5) - See options again." << endl;

		int choice;
		cin >> choice;

		if(choice == 1)
		{
			attributes->strength++;
			attributePoints--;
		}

		else if(choice == 2)
		{
			attributes->dexterity++;
			attributePoints--;
		}

		else if(choice == 3)
		{
			attributes->constitution++;
			attributePoints--;
		}

		else if(choice == 4)
		{
			attributes->intelligence++;
			attributePoints--;
		}

		else
		{
			//Loop again
		}

	}

	int skillPoints = 5;
	//Choose skills - can only choose 5 right now
	while(skillPoints != 0)
	{
		cout << "You have: " << skillPoints << " remaining to spend on skills." << endl;
		cout << "These are your options: " << endl << endl;
		for(int i = 0; i < skillSet.size(); i++)
		{
			cout << i << ") " << endl;
			skillSet.at(i)->print_skill_details();
			cout << endl << endl;
		}

		cout << "Please choose the number of the skill whose level you wish to increase. Note: the higher the skill level, the more powerful the skill" << endl;
		int choice;
		cin >> choice;
		cout << endl;

		if(choice >= skillSet.size() || choice < 0)
		{
			cout << "That is not a valid choice, please try again" << endl << endl;
		}

		else
		{
			(skillSet.at(choice))->level++;
			skillPoints--;
		}
	}

	Weapon* fist = new Weapon;
	fist->make_Weapon("Fists", "weapon", 10);

	Armour* head = new Armour;
	head->make_Armour("Head", "helm", 0);

	Armour* chest = new Armour;
	chest->make_Armour("Chest", "chest", 0);

	Armour* hands = new Armour;
	hands->make_Armour("Hands", "gloves", 0);

	Armour* feet = new Armour;
	feet->make_Armour("Feet", "boots", 0);

	Equipped* beingUsed = new Equipped;
	beingUsed->make_Equipped(fist, fist, head, chest, hands, feet);

	Item* drink = new Item;
	drink->make_Item("Booze!", "booze");

	Inventory* inventory = new Inventory;
	vector<Item*> stuff;

	Weapon* startup_short_sword = new Weapon;
	startup_short_sword->make_Weapon("Rusty Short Sword", "weapon", 20);

	stuff.push_back(drink);
	stuff.push_back(drink);
	stuff.push_back(drink);
	stuff.push_back(startup_short_sword);

	inventory->make_Inventory(stuff, beingUsed);

	Character* main = new Character;
	main->make_Character(name, race, type, 100, 100, 0, 0, inventory, attributes, skillSet);
	main->calcDamageTotal();
	main->calcArmourTotal();

	return main;
}