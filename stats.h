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

class Stats
{
	public:
		int strength;
		int dexterity;
		int constitution;
		int intelligence;

		void make_Stats(int str, int dex, int con, int intel)
		{
			strength = str;
			dexterity = dex;
			constitution = con;
			intelligence = intel;
		}

		void print_stats()
		{
			cout << "Attributes: " << endl << endl;			
			cout << "Strength: " << strength << endl;
			cout << "Dexterity: " << dexterity << endl;
			cout << "Constitution: " << constitution << endl;
			cout << "Intelligence: " << intelligence << endl;
			cout <<  endl;
		}
};