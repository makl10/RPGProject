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
#include "inventory.h"
#include "stats.h"
#include "skill_set.h"

using namespace std;

class Character
{
	public:
		string name;
		string race;
		string type;
		Inventory* inventory;
		Stats* attributes;

		double health;
		double mana;
		double damage;
		double armour;

		vector<Skill*> skillSet;


		void make_Character(string nm, string rc, string tp, double hlt, double mn, double dmg, double arm, Inventory* newInv, Stats* newStat, vector<Skill*> skills)
		{
			name = nm;
			race = rc;
			type = tp;
			health = hlt;
			mana = mn;
			damage = dmg;
			armour = arm;
			inventory = newInv;
			attributes = newStat;
			skillSet = skills;
		}

		void calcDamageTotal()
		{
			damage = damage + inventory->beingUsed->mainHand->damage + inventory->beingUsed->offHand->damage;
		}

		void calcArmourTotal()
		{
			armour = armour + inventory->beingUsed->chest->armourRating + inventory->beingUsed->head->armourRating + inventory->beingUsed->hands->armourRating + inventory->beingUsed->feet->armourRating;
		}

		void equip_mainHand(Item* toFind)
		{
			Item* toEquip = new Item;

			toEquip = inventory->access_item(toFind->name);

			if(toEquip->type != "weapon")
			{
				cout << "This is not a weapon!!" << endl;
			}

			else
			{
				cout << toEquip->name << " was equipped!" << endl;
				inventory->beingUsed->mainHand = (Weapon*)toEquip;
				inventory->erase_item(toEquip->name);
			}
		}

		void equip_offHand(Item* toFind)
		{
			Item* toEquip = new Item;

			toEquip = inventory->access_item(toFind->name);

			if(toEquip->type != "weapon" || toEquip->type != "shield")
			{
				cout << "This is not a weapon!!" << endl;
			}

			else
			{
				cout << toEquip->name << " was equipped!" << endl;
				inventory->beingUsed->offHand = (Weapon*)toEquip;
				inventory->erase_item(toEquip->name);
			}
		}

		void equip_chesst(Item* toFind)
		{
			Item* toEquip = new Item;

			toEquip = inventory->access_item(toFind->name);

			if(toEquip->type != "chest")
			{
				cout << "This is not a chest piece!!" << endl;
			}

			else
			{
				cout << toEquip->name << " was equipped!" << endl;
				inventory->beingUsed->chest = (Armour*)toEquip;
				inventory->erase_item(toEquip->name);
			}
		}

		void equip_head(Item* toFind)
		{
			Item* toEquip = new Item;

			toEquip = inventory->access_item(toFind->name);

			if(toEquip->type != "helm")
			{
				cout << "This is not a helmet, fool!!" << endl;
			}

			else
			{
				cout << toEquip->name << " was equipped!" << endl;
				inventory->beingUsed->head = (Armour*)toEquip;
				inventory->erase_item(toEquip->name);
			}
		}

		void equip_hands(Item* toFind)
		{
			Item* toEquip = new Item;

			toEquip = inventory->access_item(toFind->name);

			if(toEquip->type != "gloves")
			{
				cout << "These are not gloves, ye scallywag!!!" << endl;
			}

			else
			{
				cout << toEquip->name << " was equipped!" << endl;
				inventory->beingUsed->hands = (Armour*)toEquip;
				inventory->erase_item(toEquip->name);
			}
		}

		void equip_feet(Item* toFind)
		{
			Item* toEquip = new Item;

			toEquip = inventory->access_item(toFind->name);

			if(toEquip->type != "boots")
			{
				cout << "These are not boots!!!" << endl;
			}

			else
			{
				cout << toEquip->name << " was equipped!" << endl;
				inventory->beingUsed->feet = (Armour*)toEquip;
				inventory->erase_item(toEquip->name);
			}
		}													

		void print_character_info()
		{
			cout << "Character Information: " << endl << endl;
			cout << "Name: " << name << endl;
			cout << "Race: " << race << endl;
			cout << "Class: " << type << endl;
			cout << "Health: " << health << endl;
			cout << "Mana: " << mana << endl;
			cout << "Damage: " << damage << endl;
			cout << "Armour: " << armour << endl << endl;
			inventory->print_inventory();
			cout << endl;
			attributes->print_stats();
			cout << "Skills: " << endl;
			print_skill_vector(skillSet);
		}
};

class Basic_Goblin : public Character
{
	public:

		void make_Basic_Goblin()
		{
			Weapon* fist = new Weapon;
			fist->make_Weapon("Fists", "weapon", 10);

			Weapon* rustySword = new Weapon;
			rustySword->make_Weapon("Rusty Sword", "weapon", 20);

			Armour* rustyChainMail = new Armour;
			rustyChainMail->make_Armour("Rusty Chain Mail", "chest", 10);

			Armour* goblinHead = new Armour;
			goblinHead->make_Armour("Goblin Head", "helm", 0);

			Armour* goblinHands = new Armour;
			goblinHands->make_Armour("Goblin Hands", "gloves", 0);

			Armour* rustyBoots = new Armour;
			rustyBoots->make_Armour("Rusty Boots", "boots", 0);

			Equipped* beingUsed = new Equipped;
			beingUsed->make_Equipped(rustySword, fist, goblinHead, rustyChainMail, goblinHands, rustyBoots);

			Item* drink = new Item;
			drink->make_Item("Booze!", "booze");

			Inventory* inventory2 = new Inventory;
			vector<Item*> stuff;
			stuff.push_back(drink);
			stuff.push_back(drink);
			stuff.push_back(drink);

			inventory2->make_Inventory(stuff, beingUsed);

			Stats* attributes2 = new Stats;
			attributes2->make_Stats(5, 5, 5, 5);

			vector<Skill*> skillSet2;
			skillSet2 = generate_fighter_skills();				

			name = "Goblin Runt";
			race = "goblin";
			type = "fighter";
			health = 500;
			mana = 50;
			damage = 0;
			armour = 0;
			inventory = inventory2;
			attributes = attributes2;
			skillSet = skillSet2; 
		}
};