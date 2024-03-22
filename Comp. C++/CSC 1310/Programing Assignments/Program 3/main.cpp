/*
	Name: Ethan Newman
	Project: Program 3 - Hash Tables
	Date: 11/5/2019
	Instructor: April Crockett
*/
#include "HashEntry.h"
#include "hashtable.h"
#include "weapon.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readFromFile(HashTable<Weapon*>*);
void enterManually(HashTable<Weapon*>*);
void searchHash(HashTable<Weapon*>*);
void deleteHash(HashTable<Weapon*>*);

int main()
{
	int choice;
	
	HashTable<Weapon*> *myTable = new HashTable<Weapon*>(10);
	
	do
	{
		
	
		cout << "\t\tWeapon Management Menu\n\n";
		cout << "1.\t Add Weapons from File\n";
		cout << "2.\t Add Weapons Manually\n";
		cout << "3.\t Search for a Weapon\n";
		cout << "4.\t Delete a Weapon\n";
		cout << "5.\t Print Hash Table\n";
		cout << "6.\t End Program\n";
		cout << "CHOOSE 1-6: ";
	
		cin >> choice;
	
		while (choice > 6 || choice < 1)
		{
			cout << "\n\nOOPS! Choose between 1 - 6!\n";
			cout << "CHOOSE 1-6: "; 
			cin >> choice;
		}
		
		switch(choice)
		{
			case 1:
					readFromFile(myTable);
					break;
			case 2: 
					enterManually(myTable);
					break;
			case 3:
					searchHash(myTable);
					break;
			case 4:
					deleteHash(myTable);
					break;
			case 5: 
					myTable->printHashTable();
					break;
			case 6:
					cout << "\n\n\nGoodbye!";
					return 0;
		}
	}while (choice > 0 && choice < 7);
	return 0;
}

void readFromFile(HashTable<Weapon*> *myTable)
{
	char filename[100];
	cout << "\nWhat is the name of your .txt file?\n";
	cin.ignore();
	cin.getline(filename, 100);
	
	ifstream inFile;
	inFile.open(filename);
	cout << "\n\n";
	if (inFile.good())
	{
		int key;
		string tempType, tempName, tempMat, tempDes;
		float tempEff;
		
		while (!inFile.eof())
		{
			inFile >> key;
			inFile.ignore();
			
			getline(inFile, tempType);
			getline(inFile, tempName);
			getline(inFile, tempMat);
			getline(inFile, tempDes);
			inFile >> tempEff;
			
			Weapon* oneWeapon = new Weapon(key, tempType, tempName, tempMat, tempDes, tempEff);
			myTable->putValue(key, oneWeapon);
			
			cout << "\t" << tempName << " was added to the Hash Function with key: " << key << endl;
		}
		
	}
	cout << "\n\n";
}
void enterManually(HashTable<Weapon*> *myTable)
{
	int key;
	string tempType, tempName, tempMat, tempDes;
	float tempEff;

	cout << "\nWhat is the ID of this weapon?\n";
	cout << "\nChoose an integer between 1 - 1000: ";
	cin >> key;
	
	while (key < 1 || key > 1000)
	{
		cout << "\nOOPS! Choose an integer between 1 - 1000: ";
		cin >> key;
	}
	
	cout << "\nWhat type of weapon is this?\n";
	cin.ignore();
	getline(cin, tempType);
	
	cout << "\nWhat is the name of this weapon?\n";
	getline(cin, tempName);
	
	cout << "\nWhat is this weapon made out of?\n";
	getline(cin, tempMat);
	
	cout << "\nBriefly describe this weapon.\n";
	getline(cin, tempDes);
	
	cout << "\nOn a scale of 1.0 - 10.0, how efficient is this weapon?\n";
	cout << "Choose 1.0 - 10.0: ";
	cin  >> tempEff;
	
	while ( tempEff < 1.0 || tempEff > 10.0)
	{
		cout << "\nOOPS! That was outside of the bounds of Rating!\n";
		cout << "Choose 1.0 - 10.0: ";
		cin >> tempEff;
	}
	
	Weapon* oneWeapon = new Weapon(key, tempType, tempName, tempMat, tempDes, tempEff);
	myTable->putValue(key, oneWeapon);
}

void searchHash(HashTable<Weapon*> *myTable)
{
	int key;
	cout << "\nWhat is the weapon ID?\n";
	cin >> key;
	
	while (key > 1000 || key < 0)
	{
		cout << "\nOOPS! Choose an integer between 1 - 1000: ";
		cin >> key;
	}
	
	Weapon* check = myTable->getValue(key);
	
	if (check != NULL)
	{
		check->printWeapon();
	}
	else
	{
		cout << "\nOOPS! That is an invalid key!\n";
	}
}

void deleteHash(HashTable<Weapon*> *myTable)
{
	int key;
	
	myTable->printHashTable();
	
	cout << "\n\nWhat is the ID of the weapon you would like to delete?\n";
	cout << "ID: ";
	cin >> key;
	
	Weapon* check = myTable->getValue(key);
	
	if (check != NULL)
	{
		myTable->removeValue(key);
		cout << "\nWeapon removed.";
	}
	else
	{
		cout << "\nOOPS! That is an invalid key!\n";
	}
}
