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
#include "levels.h"

vector<Armour> armourPile;

int main()
{
	armourPile = armourGen();

	Character* main = new Character;
	main = startupLevel();
	main->print_character_info();
	cout << "Hmmm thats an awful lot of booze......where did all that booze come from?" << endl;

	Basic_Goblin* easyGoblin = new Basic_Goblin;
	easyGoblin->make_Basic_Goblin();

	combatMenu(main, easyGoblin);

	main->skillSet.at(0)->print_skill_details();

	double damage = main->skillSet.at(0)->skill_action(main->attributes->strength, main->damage);

	cout << damage << endl;


	return 0;
}