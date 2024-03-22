/*
	File Name: lab2b.cpp
	Author: Ethan Newman & Austin Bohannon
	Date: January 24, 2019
	Purpose: To calculate and Display:
	The number of customers that purchased more than 1 energy drink per week
	The number that prefer citrus-flavored of that group
*/

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	float survey = 16500;
	float per_drink = .15;
	float per_citrus = .58;
	float drink_week;
	float citrus_week;
	
	drink_week = survey * per_drink;
	citrus_week = drink_week * per_citrus;
	
	cout << "Num of people who drink more than one a week : " << drink_week << endl;
	cout << "Num of people who drink more than one a week and prefer Citrus flavored : " << round(citrus_week) << endl;

	return 0;
}	