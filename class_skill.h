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
#include "skill.h"

using namespace std;

class Fighter_Skill : public Skill
{
	public:

		void make_Hunter_Skill(string nm, string desc)
		{
			name = nm;
			description = desc;
			type = "fighter";
			level = 0;
		}

		virtual double skill_action()
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

class Hunter_Skill : public Skill
{
	public:

		void make_Hunter_Skill(string nm, string desc)
		{
			name = nm;
			description = desc;
			type = "hunter";
			level = 0;
		}

		virtual double skill_action()
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

class Paladin_Skill : public Skill
{
	public:

		void make_Paladin_Skill(string nm, string desc)
		{
			name = nm;
			description = desc;
			type = "paladin";
			level = 0;
		}

		virtual double skill_action()
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

class Mage_Skill : public Skill
{
	public:

		void make_Mage_Skill(string nm, string desc)
		{
			name = nm;
			description = desc;
			type = "mage";
			level = 0;
		}

		virtual double skill_action()
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