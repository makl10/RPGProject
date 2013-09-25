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
#include "item.h"

using namespace std;


class Weapon : public Item
{
	public:
		double damage;

		void make_Weapon(string nm, string tp, double dmg)
		{
			name = nm;
			type = tp;
			damage = dmg;
		}

		void print_item_details()
		{
			cout << "Weapon Name: " << name << endl;
			cout << "Weapon Type: " << type << endl;
			cout << "Weapon Damage: " << damage << endl;
		}
};

class Armour : public Item
{
	public:
		double armourRating;

		void make_Armour(string nm, string tp, double armourValue)
		{
			name = nm;
			type = tp;
			armourRating = armourValue;
		}

		void print_item_details()
		{
			cout << "Armour Name: " << name << endl;
			cout << "Armour Type: " << type << endl;
			cout << "Armour Value: " << armourRating << endl;
		}
};

vector<Armour> armourGen()
{
	vector<Armour> armourPile;
	ifstream in_file;
	in_file.open("./lists/armourList.txt");
	std::string line;
	Armour toBeAdded;
	string i;


	while(!in_file.eof())
	{
		//Error check
		if(in_file.fail())
		{
			printf("Error opening file. \n");
			break;
		}

		//Read line from file and save to string
		std::getline(in_file, line);

		std::istringstream ss(line);
		std::string token;
		vector<string> stringSplit;


		while(std::getline(ss, token, ','))
		{
			stringSplit.push_back(token);
		}

		toBeAdded.make_Armour(stringSplit.at(0), stringSplit.at(1), atof(stringSplit.at(2).c_str()));

		//Add string to the end of the vector
		armourPile.push_back(toBeAdded);
	}

	return armourPile;

}

void printArmourVector(vector<Armour> armour)
{
	Armour* toPrint = new Armour;

	for(std::vector<Armour>::iterator it = armour.begin(); it != armour.end(); it++)
	{
		*toPrint = *it;
		toPrint->print_item_details();
		std::cout << std::endl;
	}
}