#ifndef JELLYBELLY_H
#define JELLYBELLY_H

#include <iostream>
#include <fstream>
#include <cstring> //for strcpy function
#include <cstdlib> //for atof function
#include <string>
using namespace std;

struct Jellybean
{
	string flavor;
	string color;
	double pricePerLb;
	double starRating;
	int quantityLbs;
};

const int NUM_FLAVORS = 50;

float stringToFloat(string);
int deleteBeans(Jellybean[], int);
int displayMenuGetChoice();
void printAllInventory(Jellybean[], int);
void printColor(Jellybean[], int);
int addBeans(Jellybean[], int);
//FIXME - add other function prototypes

#endif
