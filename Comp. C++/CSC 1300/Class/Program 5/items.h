#ifndef ITEMS_H
#define ITEMS_H

#include<iostream>
#include<fstream>
#include<string>
#include <cstring>
#include <cstdlib>

using namespace std;


struct Money
{
	float matCost;
	float saleCost;
	float profit;
};


struct Items
{
	string name;
	string descrp;
	int numStores;
	string* nameStores;
	string creationDate;
	
	struct Money Cost;
};

int menuFunc();
void itemAdd(Items facArray[], int facNum, int& currNum);
void printItems(Items facArray[], int& currNum);
void saveInventory(Items facArray[], int& currNum);

#endif