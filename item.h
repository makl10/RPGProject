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

class Item
{
	public:
		string name;
		string type;

		void make_Item(string nm, string tp)
		{
			name = nm;
			type = tp;
		}

		void print_item_details()
		{
			cout << "Item Name: " << name << endl;
			cout << "Item Type: " << type << endl;
		}
};
