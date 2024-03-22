/*
	Name: Ethan Newman
	Date: 10/10/2019
	Assignment: Program 2 - CSC 1310
	Instructor: April Crockett
*/


#include "creature.h"
#include "linkedlist.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void enterCreature(LinkedList<Creature>*);
void enterCreatureFromFile(LinkedList<Creature>*);
void deleteCreature(LinkedList<Creature>*);
void printCreatures(LinkedList<Creature>*);
void saveCreaturesToFile(LinkedList<Creature>*);


int main()
{
	
LinkedList<Creature> list;

int choice;
int case1;

do
{
	cout << "\nWhat would you like to do?";
	cout << "\n\t1. Enter Magical Creature.";
	cout << "\n\t2. Delete a Magical Creature.";
	cout << "\n\t3. List/Print Creatures.";
	cout << "\n\t4. End Program.";
	cout << "\n\n\tEnter 1, 2, 3, or 4.";
	cout << "\nCHOICE: ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
				cout << "\n\nWould you like to enter the creature manually or from a file?\n";
				cout << "Type 1 for manual and 2 for file.\n";
				cout << "CHOICE: ";
				cin.ignore();
				cin >> case1;
				
				while (case1 > 3 && case1 < 0)
				{
					cout << "\n\nOOPS! You entered an invalid character. Please try again.\n";
					cout << "CHOICE: ";
					cin >> case1;
				}
				
				if (case1 == 1)
				{
					enterCreature(&list);

				}
				else if (case1 == 2)
				{
					enterCreatureFromFile(&list);
				}
				
				
				
				break;
		case 2:
				deleteCreature(&list);
				break;
		case 3:
				printCreatures(&list);
				break;
		case 4:
				saveCreaturesToFile(&list);
				cout << "\n\n\tGOODBYE!";
				return 0;
	}
	
	}while(choice > 0 && choice < 5);
	
	return 0;
}

void enterCreature(LinkedList<Creature>* list)
{
			
	string n, d;
	float c;
	bool dan;
	char choice;
			
	cout << "\nWhat is the name of your creature?\n";
	cin.ignore();
	getline(cin, n);
			
	cout << "\nGive a brief description of your creature.\n";
	getline(cin, d);
			
	cout << "\nHow much does it cost to maintain your creature?\n";
	cin >> c;
			
	cout << "\nIs your creature dangerous?(Y/N)\n";
	cout << "CHOICE: ";
	cin.ignore();
	cin >> choice;
			
			
	while (choice != 'y' && choice != 'Y'&& choice != 'n'&& choice != 'N')
	{
		cout << "\nOOPS! You entered an invalid character! Please try again.\n";
		cout << "CHOICE: ";
		cin >> choice;
	}
			
	if (choice == 'y' || choice == 'Y')
	{
		dan = true;
	}
	else if (choice == 'n' || choice == 'N')
	{
	
		dan = false;
	}
		
	Creature creature(n, d, c, dan);

	list->appendNode(creature);
		}

void enterCreatureFromFile(LinkedList<Creature>* list)
{
	char filename[100];
	
	
	
		cout << "\nWhat is the name of your file?\n";
		cin.ignore();
		cin.getline(filename, 100);
		
		ifstream inFile;
		inFile.open(filename);
		if(inFile.good())
		{
			string n, d;
			double c;
			bool dan;
			
			while (!inFile.eof())
			{
				getline(inFile, n);
				getline(inFile, d);
				
				inFile >> dan;
				
				inFile >> c;
				inFile.ignore();
				
				Creature creature(n, d, c, dan);
				
				
				list->appendNode(creature);
			}
		cout << "\n\nAll Creatures from" << filename << " have been added.\n";
		}
		else
		{
			cout << "\n\nI'm sorry, that file doesn\'t exist.\n\n";
		}
	
}
	
void deleteCreature(LinkedList<Creature>* list)
{
	int pos;

	if (list->getLength() == 0)
	{
		cout << "\nThere are no Creatures to Delete!\n\n\n";
	}
	else
	{
		
		for (int i = 0; i < list->getLength(); i++)
		{
			cout << i+1 << ".\n";
			list->getNodeValue(i).printCreature();
		}
		
		cout << "\nFrom top to Bottom, which creature would you like to delete?";
		cout << " Please enter an integer.\n";
		cout << "CHOICE: ";
		cin >> pos;
		cin.ignore();
		
		while (pos > list->getLength() || pos < 0)
		{
			cout << "\nOOPS! You entered an invalid number!\n";
			cin >> pos;
		}
		
		list->deleteNode(pos);
}

}
	
void printCreatures(LinkedList<Creature>* list)
{
	if (list->getLength() == 0)
	{
		cout << "\nOOPS! You don\'t have any creatures in your zoo!\n";
	}
	else
	{
		for (int i = 0; i < list->getLength(); i++)
		{
			list->getNodeValue(i).printCreature();
		}
		cout << "\n******************************************************************************************\n\n\n";
	
	}
}

void saveCreaturesToFile(LinkedList<Creature>* list)
{
	char filename[100];
	char cstring[1000];
	
	if (list->getLength() == 0)
	{
		cout << "\nOOPS! You don\'t have any creatures in your zoo!\n\n\n";
	}
	else
	{
		cout << "\nWhat would you like to name this file?\t";
		cin >> filename;
		cin.ignore();
		
		for (int i = 0; i < list->getLength(); i++)
		{
			list->getNodeValue(i).printCreatureToFile(filename);
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	


