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
#include "class_skill.h"

using namespace std;

/*-----------------------------------------------------------------------------FIGHTER SECTION---------------------------------------------------------------*/
//Take a massive two handed blow - characters strength is added to the damage
class Two_Handed_Blow : public Fighter_Skill
{	
	public:

		void make_Two_Handed_Blow()
		{
			name = "Two Handed Blow";
			type = "fighter";
			description = "A powerful two handed attack, the fighter puts all his strength into the swing. Strength of the fighter is added to the damage.";
			level = 0;
		}

		void print_skill_details()
		{
			cout << "Skill Name: " << name << endl;
			cout << "Skill Type: " << type << endl;
			cout << "Description: " << description << endl;
			cout << "Level: " << level << endl;
		}

		//Add strength to damage
		double skill_action(int strength, double damage)
		{
			if(level == 0)
			{
				return 0;
			}

			double levelMod = level / 5;
			double damageResult = strength + damage + levelMod;

			return damageResult;
		}			
};

vector<Skill*> generate_fighter_skills()
{
	vector<Skill*> fighterSkills;

	Two_Handed_Blow* twoHandedBlow = new Two_Handed_Blow;
	twoHandedBlow->make_Two_Handed_Blow();

	fighterSkills.push_back(twoHandedBlow);

	return fighterSkills;
}

/*-----------------------------------------------------------------------------HUNTER SECTION---------------------------------------------------------------*/


class Precision_Shot : public Hunter_Skill
{
	public:
		void make_Precision_Shot()
		{
			name = "Precision Shot";
			type = "hunter";
			description = "A precise shot, the hunter uses all his dexterity into firing a powerful shot. Dexterity of the hunter is added to the damage.";
			level = 0;
		}

		void print_skill_details()
		{
			cout << "Skill Name: " << name << endl;
			cout << "Skill Type: " << type << endl;
			cout << "Description: " << description << endl;
			cout << "Level: " << level << endl;
		}

		//Add dexterity to damage
		double skill_action(int dexterity, double damage)
		{

			if(level == 0)
			{
				return 0;
			}

			double levelMod = level / 5;
			double damageResult = dexterity + damage + levelMod;

			return damageResult;
		}			
};

vector<Skill*> generate_hunter_skills()
{
	vector<Skill*> hunterSkills;

	Precision_Shot* precisionShot = new Precision_Shot;
	precisionShot->make_Precision_Shot();

	hunterSkills.push_back(precisionShot);

	return hunterSkills;
}

/*-----------------------------------------------------------------------------PALADIN SECTION---------------------------------------------------------------*/


class Smite : public Paladin_Skill
{
	public:
		void make_Smite()
		{
			name = "Smite";
			type = "paladin";
			description = "Unleash a righteous blow upon your enemy! 1d6 holy damage added to regular damage!";
			level = 0;
		}

		void print_skill_details()
		{
			cout << "Skill Name: " << name << endl;
			cout << "Skill Type: " << type << endl;
			cout << "Description: " << description << endl;
			cout << "Level: " << level << endl;
		}

		//Just hit em hard
		double skill_action(double constitution, double damage)
		{
			if(level == 0)
			{
				return 0;
			}

			double levelMod = level / 5;			
			int dice = rand() % 6 + 1;
			double damageResult = damage + dice + levelMod;

			return damageResult;
		}	
};

vector<Skill*> generate_paladin_skills()
{
	vector<Skill*> paladinSkills;

	Smite* smite = new Smite;
	smite->make_Smite();

	paladinSkills.push_back(smite);

	return paladinSkills;
}

/*-----------------------------------------------------------------------------MAGE SECTION---------------------------------------------------------------*/


class Fireball : public Mage_Skill
{
	public:
		void make_Fireball()
		{
			name = "Fireball";
			type = "mage";
			description = "Classic fireball. What could possible go wrong?";
			level = 0;
		}

		void print_skill_details()
		{
			cout << "Skill Name: " << name << endl;
			cout << "Skill Type: " << type << endl;
			cout << "Description: " << description << endl;
			cout << "Level: " << level << endl;
		}

		//Fireball burn
		double skill_action(int intelligence, double damage)
		{
			if(level == 0)
			{
				return 0;
			}
			
			double levelMod = level / 5;			
			int dice = rand() % 6 + 1;
			double damageResult = intelligence * dice + levelMod;

			return damageResult;
		}		
};

vector<Skill*> generate_mage_skills()
{
	vector<Skill*> mageSkills;

	Fireball* fireball = new Fireball;
	fireball->make_Fireball();

	mageSkills.push_back(fireball);

	return mageSkills;
}

/*-----------------------------------------------------------------------------MISC SECTION---------------------------------------------------------------*/

void print_skill_vector(vector<Skill*> skills)
{
	Skill* toPrint = new Skill;

	for(std::vector<Skill*>::iterator it = skills.begin(); it != skills.end(); it++)
	{
		(*it)->print_skill_details();
		cout << endl;
	}
}