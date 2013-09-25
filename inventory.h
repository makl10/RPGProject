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
#include "equipment.h"

using namespace std;

class Equipped
{
	public:
		Weapon* mainHand;
		Weapon* offHand;
		Armour* chest;
		Armour* head;
		Armour* hands;
		Armour* feet;

		void make_Equipped(Weapon* main, Weapon* off, Armour* chst, Armour* hd, Armour* gloves, Armour* boots)
		{
			mainHand = main;
			offHand = off;
			head = hd;			
			chest = chst;
			hands = gloves;
			feet = boots;
		}

		void print_equipped()
		{
			cout << "Main Hand: " << endl;
			mainHand->print_item_details();
			cout << "Off Hand: " << endl;
			offHand->print_item_details();
			cout << "Chest: " << endl;
			chest->print_item_details();
			cout << "Head: " << endl;
			head->print_item_details();
			cout << "Hands: " << endl;
			hands->print_item_details();
			cout << "Feet: " << endl;
			feet->print_item_details();
		}

};

class Inventory
{
	public:
		vector<Item*> items;
		Equipped* beingUsed;

		void make_Inventory(vector<Item*> stuff, Equipped* toUse)
		{
			items = stuff;
			beingUsed = toUse;
		}

		void add_to_inventory(Item* toAdd)
		{
			items.push_back(toAdd);
		}

		//Drop message for user purpose
		void drop_item(string name)
		{
			bool exists = false;
			int i;
			for(i = 0; i < items.size(); i++)
			{
				if(name == items.at(i)->name)
				{
					cout << items.at(i)->name << " was dropped." << endl;
					exists = true;					
					break;
				}
			}

			if(exists)
			{
				items.erase(items.begin() + i);
			}

			else if(!exists)
			{
				cout << "Item not contained in inventory!" << endl;
			}	
		}

		//No drop message - for equipping purpose - no need for inventory check - done in access_item
		void erase_item(string name)
		{
			bool exists = false;
			int i;
			for(i = 0; i < items.size(); i++)
			{
				if(name == items.at(i)->name)
				{
					exists = true;					
					break;
				}
			}

			if(exists)
			{
				items.erase(items.begin() + i);
			}			
		}	

		//For using an item or used to equip an item
		Item* access_item(string name)
		{
			int i;
			for(i = 0; i < items.size(); i++)
			{
				if(name == items.at(i)->name)
				{
					return items.at(i);
				}
			}

			cout << "Item not found!" << endl;
		}
		
		void print_inventory()
		{
			Item* toPrint = new Item;
			int i = 1;

			cout << "Inventory:" << endl << endl;
			for(std::vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
			{
				//toPrint = *it;
				cout << i << ")" << endl;
				(*it)->print_item_details();
				cout << endl;
				i++;
			}

			cout << "Items Equipped:" << endl << endl;
			beingUsed->print_equipped();
		}
};