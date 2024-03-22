/*
	Title: Program2.cpp
	Author: Ethan Newman
	Date: 2/14/2019
	Purpose: Let's play MASH!
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std; 

int main()
{
	int checkNum1, checkNum2, rngNum, switchNum, i;
	string namePeople[3];
	int num100 [3];
	string locationCityState[3];
	string jobTitle[3];
	string companyRest[3];
	int num500000[3];
	string typeCar[3];
	string houseMash[4] = { "Mansion" , "Apartment" , "Shack" , "House" };
	
	i = 0;
	checkNum1 = 0;
	checkNum2 = 0;
	
	while ( checkNum1 == 0) {
		cout << "Pick from the following menu: " << endl;
			cout << "1. Let's play MASH!" << endl;
			cout << "2. End program." << endl;
			cin >> switchNum;
	
		while (checkNum2 == 0) {
		
			switch(switchNum) {
				case 1:
					cout << "You chose to play MASH!\n\n";
					checkNum2 = checkNum2 + 1;
					break;
				case 2:
					cout << "You chose to end the program.\n";
					cout << "Bye!\n";
					return 0;
					break;
				default :
					cout << "Invalid input. Please try again.";
					break;
			}
		}
	
	checkNum2 = 0;
		
	cout << "Enter in on person you like: ";
	cin.ignore();
	getline(cin, namePeople[0]);
	cout << "\n\nEnter in another person you like: ";
	getline(cin, namePeople[1]);
	cout << "\n\nEnter in a person you hate: ";
	getline(cin, namePeople[2]);
	
	while (checkNum2 == 0) {
	
	cout << "\nEnter three numbers between 1 and 100, seperated by a space.\n";
	cin >> num100[0];
	cin >> num100[1];
	cin >> num100[2];
	cin.ignore();
	
	if (num100[i] > 100 || num100[i] < 1) { 
		cout << "\nYou have entered an invalid number. Try Again.\n";
	}
	else {
		checkNum2 = 1;
	}
	i++;
	}
	
	checkNum2 = 0;
	
	cout << "\nEnter in one city, state you like: ";
	cin.get();
	getline(cin, locationCityState[0]);
	cout << "\n\nEnter in another city, state you like: ";
	getline(cin, locationCityState[1]);
	cout << "\n\nEnter in one city, state you hate: ";
	getline(cin, locationCityState[2]);
	
	cout << "\n\nEnter in an awesome job title: ";
	getline(cin, jobTitle[0]);
	cout << "\n\nEnter in another awesome job title: ";
	getline(cin, jobTitle[1]);
	cout << "\n\nEnter in the worst job title: ";
	getline(cin, jobTitle[2]);
	
	cout << "\n\nEnter a company or restaurant you like: ";
	getline(cin, companyRest[0]);
	cout << "\n\nEnter another company or restaurant you like: ";
	getline(cin, companyRest[1]);
	cout << "\n\nEnter a company or restaurant you hate: ";
	getline(cin, companyRest[2]);
	
		while (checkNum2 == 0) {
	
	cout << "\nEnter three numbers between 10000 and 500000, seperated by a space.\n";
	cin >> num500000[0];
	cin >> num500000[1];
	cin >> num500000[2];
	cin.ignore();
	
	i = 0;
	
	if (num500000[i] > 500000 || num500000[i] < 10000) { 
		cout << "\nYou have entered an invalid number. Try Again.\n";
	}
	else {
		checkNum2 = 1;
	}
	i++;
	}
	
	checkNum2 = 0;
	cin.ignore();
	
	cout << "\nEnter in a car that you like: ";
	cin.get();
	getline(cin, typeCar[0]);
	cout << "\n\nEnter in another car that you like: ";
	getline(cin, typeCar[1]);
	cout << "\n\nEnter in a car that you hate: ";
	getline(cin, typeCar[2]);
	
	srand(time(0));
	rngNum = rand() % 4;
	
	// I reassigned rngNum to make the results truly random.
	
	cout << "******  MASH RESULTS  ******" << endl;
	cout << "You will live in a " << houseMash[rngNum] << endl;
	rngNum = rand() % 3;
	cout << "You will be happily married to " << namePeople[rngNum] << endl;
	rngNum = rand() % 3;
	cout << "You will live in " << locationCityState[rngNum] << endl;
	rngNum = rand() % 3;
	cout << "You will work at " << companyRest[rngNum];
	rngNum = rand() % 3;
	cout << " as a " << jobTitle[rngNum];
	rngNum = rand() % 3;
	cout << " making " << num500000[rngNum] << " a year.\n";
	rngNum = rand() % 3;
	cout << "You will drive a " << typeCar[rngNum] << endl << endl << endl;
	
	
	}
		return 0;
}
					
		
		
	