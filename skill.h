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

using namespace std;

class Skill
{
	public:
		string name;
		string type;
		string description;
		int level;

		void make_Skill(string nm, string tp, string desc)
		{
			name = nm;
			type = tp;
			description = desc;
			level = 0;
		}

		virtual double skill_action(int attr, double damage)
		{
			return 0;
		}

		void print_skill_details()
		{
			cout << "Skill Name: " << name << endl;
			cout << "Skill Type: " << type << endl;
			cout << "Description: " << description << endl;
			cout << "Level: " << level << endl;
		}
};
