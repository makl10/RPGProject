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

//SimpleAttack = 1
//SkillAttack = 2
//Inventory = 3


struct Node
{
	bool playerOption;
	int optionResponseData;
	
	Node* leftChild;
	Node* rightChild;
};

