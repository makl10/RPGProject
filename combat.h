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
#include "character.h"

#define SIMPLE_ATTACK 1
#define SKILL_ATTACK 2
#define INVENTORY_ACCESS 3

using namespace std;

//Helper struct
struct CombatResponse
{
	//Simple attack = 1
	//Skill = 2
	//Inventory = 3

	int playerOption;
	double damage;
};

CombatResponse* simpleAttack(Character* attacker, Character* defender)
{
	cout << attacker->name << " attacks " << defender->name << endl;

	int dexMod;
	double damage;
	if(attacker->attributes->dexterity * (dexMod = rand() % 7) > defender->attributes->dexterity * (dexMod = rand() % 7))
	{
		cout << attacker->name << " scores a hit on " << defender->name << endl;
		int strMod;
		damage = attacker->damage * (strMod = rand() % 7);
		if(damage > defender->armour)
		{
			cout << attacker->name << "'s blow pierces " << defender->name << "'s armour!" << endl;
			cout << attacker->name << " does " << damage << " to " << defender->name << endl;
			defender->health = defender->health - damage;
		}
		else
		{
			cout << defender->name << "'s armour turns the blow away!" << endl;
			damage = 0;
		}	
	}

	CombatResponse* result = new CombatResponse;
	result->playerOption = 1;
	result->damage = damage;
	
	return result;
}

CombatResponse* skillAttack(Character* main, Character* npc)
{
	double damageReturn;
	cout << "These are your skills: " << endl;
	for(int i = 0; i < main->skillSet.size(); i++)
	{
			cout << i << ") " << endl;
			main->skillSet.at(i)->print_skill_details();
			cout << endl << endl;		
	}

	cout << "Please choose the number of the skill that you wish to use." << endl;
	int choice;
	cin >> choice;

	if(choice >= main->skillSet.size() || choice < 0)
	{
		cout << "That is not a valid choice! Please choose a different value" << endl;
	}

	if(main->type == "fighter")
	{
		cout << main->name << " performs " << main->skillSet.at(choice)->name << " on " << npc->name << endl;
		damageReturn = main->skillSet.at(choice)->skill_action(main->attributes->strength, main->damage);
		cout << main->name << " does " << damageReturn << " worth of damage to " << npc->name << endl;
		npc->health = npc->health - damageReturn;
		
		CombatResponse* result = new CombatResponse;
		result->playerOption = 2;
		result->damage = damageReturn;
	
		return result;
	}

	if(main->type == "hunter")
	{
		cout << main->name << " performs " << main->skillSet.at(choice)->name << " on " << npc->name << endl;
		damageReturn = main->skillSet.at(choice)->skill_action(main->attributes->dexterity, main->damage);
		cout << main->name << " does " << damageReturn << " worth of damage to " << npc->name << endl;
		npc->health = npc->health - damageReturn;
		
		CombatResponse* result = new CombatResponse;
		result->playerOption = 2;
		result->damage = damageReturn;
	
		return result;		
	}

	if(main->type == "paladin")
	{
		cout << main->name << " performs " << main->skillSet.at(choice)->name << " on " << npc->name << endl;
		damageReturn = main->skillSet.at(choice)->skill_action(main->attributes->constitution, main->damage);
		cout << main->name << " does " << damageReturn << " worth of damage to " << npc->name << endl;
		npc->health = npc->health - damageReturn;
		
		CombatResponse* result = new CombatResponse;
		result->playerOption = 2;
		result->damage = damageReturn;
	
		return result;	
	}

	if(main->type == "mage")
	{
		cout << main->name << " performs " << main->skillSet.at(choice)->name << " on " << npc->name << endl;
		damageReturn = main->skillSet.at(choice)->skill_action(main->attributes->intelligence, main->damage);
		cout << main->name << " does " << damageReturn << " worth of damage to " << npc->name << endl;
		npc->health = npc->health - damageReturn;
		
		CombatResponse* result = new CombatResponse;
		result->playerOption = 2;
		result->damage = damageReturn;
	
		return result;	
	}
}

void combatMenu(Character* main, Character* npc)
{
	while(main->health > 0 && npc->health > 0)
	{
		cout << "You and " << npc->name << " do battle!" << endl;
		cout << "What would you like to do? Here are your options: " << endl;
		cout << "1) Basic attack - attack with your primary weapon." << endl;
		cout << "2) Skill attack - access one of your skills." << endl;
		cout << "3) Use item - access your inventory to use an item." << endl;
		cout << "4) See options again." << endl;
		cout << endl;

		int choice;
		CombatResponse* response = new CombatResponse;
		cin >> choice;

		if(choice == 1)
		{
			response = simpleAttack(main, npc);

			if(npc->health <= 0)
			{
				cout << "You have won!  " << npc->name << " is dead!" << endl;
				break;
			}

			//npc response
		}

		if(choice == 2)
		{
			response = skillAttack(main, npc);

			if(npc->health <= 0)
			{
				cout << "You have won!  " << npc->name << " is dead!" << endl;				
				break;
			}

			//npc response
		}

		if(choice == 3)
		{
			//response == inventoryAccess(main, npc);

			if(npc->health <= 0)
			{
				cout << "You have won!  " << npc->name << " is dead!" << endl;				
				break;
			}

			//npc response
		}

		if(main->health < 0)
		{
			cout << endl;
			cout << "You have died! Please reload or something." << endl;
			cout << endl;
		}

		else
		{
			cout << endl;
			cout << "You have " << main->health << " points of health left!" << endl;
			cout << npc->name << " has " << npc->health << " points of health left!" << endl;
			cout << endl;
		}
	}
}
