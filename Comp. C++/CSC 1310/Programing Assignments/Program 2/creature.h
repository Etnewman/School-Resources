#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include <fstream>
#include "linkedlist.h"

using namespace std;

class Creature
{
	private:
		string cName;
		string cDescription;
		float cCost;
		bool cDanger;
		int numCreatures;
		
	public:
		Creature(string n, string d, float c, bool dan)
		{
			cName = n;
			cDescription = d;
			cCost = c;
			cDanger = dan;
		}
		
		Creature()
		{
		}
		
	//**********Accessor Functions**********
		
		string getName()
		{
			return cName;
		}
		
		string getDescription()
		{
			return cDescription;
		}
		
		float getCost()
		{
			return cCost;
		}
		
		bool getDanger()
		{
			return cDanger;
		}
		
	//**********Mutator Functions**********
		
		void setName(string n)
		{
			cName = n;
		}
		
		void setDescription(string d)
		{
			cDescription = d;
		}
		
		void setCost(float c)
		{
			cCost = c;
		}
		
		void setDanger(bool dan)
		{
			cDanger = dan;
		}
		
		//**********Class Functions**********
		
		void printCreature()
		{
			cout << "\n******************************************************************************************\n";
			
			cout << "\n\tCreature Name: \t" << cName;
			
			cout << "\n\n\tCreature Description: \n\n" << cDescription;
			
			cout << "\n\n\tCreature Cost Per Month: \t" << cCost;
			
			cout << "\n\n\tCreature Danger Status: \t";
			if (cDanger == true)
			{
				cout << "Dangerous.\n";
			}
			else if (cDanger == false)
			{
				cout << "Non-Dangerous.\n";
			}


		}
		
		
	void printCreatureToFile(char* temp)
		{
			ofstream outfile;
			outfile.open(temp, ios_base::app);
			
			outfile << cName << endl;
			outfile << cDescription << endl;
			outfile << cDanger << endl;
			outfile << cCost << endl;
			
			outfile.close();
			outfile.clear();
			
			cout << "\n\nThe Creature: " << cName << " was added to the file.";
		};
		
};
		#endif
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		